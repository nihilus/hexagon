/* tc-hexagon.c -- Assembler for Hexagon
   Copyright 1994, 1995, 1997, 1999, 2000, 2001, 2002, 2006-2008
   Free Software Foundation, Inc.

   This file is part of GAS, the GNU Assembler.

   GAS is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   GAS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GAS; see the file COPYING.  If not, write to the Free
   Software Foundation, 59 Temple Place - Suite 330, Boston, MA
   02111-1307, USA.

   Hexagon machine-specific port contributed by Qualcomm, Inc.
*/

#include <assert.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/param.h>
#include "as.h"
#include "dwarf2dbg.h"
#include "dw2gencfi.h"
#include "elf/hexagon.h"
#include "libiberty.h"
#include "libbfd.h"
#include "hexagon-isa.h"
#include "opcode/hexagon.h"
#include "struc-symbol.h"
#include "safe-ctype.h"
#include "subsegs.h"
#include <xregex.h>

#if defined (__MINGW32__)
#  ifndef MAX
#    define MAX(a,b) ((a) > (b) ? (a) : (b))
#  endif
#  ifndef MIN
#    define MIN(a,b) ((a) < (b) ? (a) : (b))
#  endif

#endif

#define DEFAULT_CODE_ALIGNMENT 2	/* log2 (4) */
#define DEFAULT_CODE_FALIGN    4	/* log2 (16) */
#define DEFAULT_DATA_ALIGNMENT 3	/* log2 (8) */

/* General limits.  */
#define MAX_MESSAGE           66	/* Message limit.  */
#define MAX_DATA_ALIGNMENT    16
#define MAX_INSNS             6		/* Insns in a packet.  */
#define MAX_FIXUPS            1		/* Per insn.  */
#define MAX_FRAG_INSNS        (2 * MAX_PACKET_INSNS - 1)	/* Per frag.  */

/* Hexagon CR aliases.  */
#define HEXAGON_SA0 0
#define HEXAGON_LC0 1
#define HEXAGON_SA1 2
#define HEXAGON_LC1 3
#define HEXAGON_P30 4
#define HEXAGON_M0  6
#define HEXAGON_M1  7
#define HEXAGON_SR  8
#define HEXAGON_PC  9
#define HEXAGON_GP 10

/* Hexagon GPR aliases.  */
#define HEXAGON_SP 29
#define HEXAGON_FP 30
#define HEXAGON_LR 31

/* Registers.  */
#define HEXAGON_NUM_GENERAL_PURPOSE_REGS 32
#define HEXAGON_NUM_CONTROL_REGS         32
#define HEXAGON_NUM_SYS_CTRL_REGS        64
#define HEXAGON_NUM_PREDICATE_REGS       4
#define HEXAGON_NUM_GUEST_REGS           32

/* Insn type opcode ranges.  */
#define HEXAGON_INSN_TYPE_A7   0x70000000 /* A-type.  */
#define HEXAGON_INSN_TYPE_X8   0x80000000 /* X-type.  */
#define HEXAGON_INSN_TYPE_A11  0xb0000000 /* A-type.  */
#define HEXAGON_INSN_TYPE_X12  0xc0000000 /* X-type.  */
#define HEXAGON_INSN_TYPE_X13  0xd0000000 /* X-type.  */
#define HEXAGON_INSN_TYPE_X14  0xe0000000 /* X-type.  */
#define HEXAGON_INSN_TYPE_A15  0xf0000000 /* A-type.  */
#define HEXAGON_INSN_TYPE_MASK(I) ((I) & 0xf0000000) /* Insn type mask.  */
#define HEXAGON_INSN_TYPE_A(I)						\
  (HEXAGON_INSN_TYPE_MASK (I) == HEXAGON_INSN_TYPE_A7			\
   || HEXAGON_INSN_TYPE_MASK (I) == HEXAGON_INSN_TYPE_A11		\
   || HEXAGON_INSN_TYPE_MASK (I) == HEXAGON_INSN_TYPE_A15)
#define HEXAGON_INSN_TYPE_X(I)						\
  (HEXAGON_INSN_TYPE_MASK (I) == HEXAGON_INSN_TYPE_X8			\
   || HEXAGON_INSN_TYPE_MASK (I) == HEXAGON_INSN_TYPE_X12		\
   || HEXAGON_INSN_TYPE_MASK (I) == HEXAGON_INSN_TYPE_X13		\
   || HEXAGON_INSN_TYPE_MASK (I) == HEXAGON_INSN_TYPE_X14)

/* Literals limits.  */
/* prefix + "_" + hex + NUL */
#define MAX_LITERAL_NAME      (LITERAL_PREFIX_LEN + 1 + 16 + 1)
/* Total numer of literals.  */
#define MAX_LITERAL_POOL      65536
/* Equal to MAX_PRECISION in atof-ieee.c.  */
#define MAX_LITTLENUMS        6		
/* Safe limit.  */
#define MAX_OPERANDS          10
#define MAX_SMALL_SECTION     \
  (1 + 1 + 1 + \
   MAX (MAX (sizeof (SMALL_COM_SECTION), sizeof (SMALL_BSS_SECTION)), \
        sizeof (SMALL_DATA_SECTION)))

#define LITERAL_SECTION_A        ".lita"
#define LITERAL_A_LEN            (sizeof (LITERAL_SECTION_A))
#define LITERAL_SECTION_ONCE_4   ".gnu.linkonce.l4"
#define LITERAL_ONCE_4_LEN       (sizeof (LITERAL_SECTION_ONCE_4))
#define LITERAL_SECTION_ONCE_8   ".gnu.linkonce.l8"
#define LITERAL_ONCE_8_LEN       (sizeof (LITERAL_SECTION_ONCE_8))
/* Must start with "." to be concatenated nicely with the literal
   "once" section.  */
#define LITERAL_PREFIX           ".CONST"
#define LITERAL_PREFIX_LEN       (sizeof (LITERAL_PREFIX))
#define LITERAL_SUBSECTION       (8191 - 8)

#define SMALL_DATA_SECTION ".sdata"
#define SMALL_DATA_LEN     (sizeof (SMALL_DATA_SECTION))

#define SMALL_BSS_SECTION ".sbss"
#define SMALL_BSS_LEN     (sizeof (SMALL_BSS_SECTION))

#define SMALL_COM_SECTION ".scommon"
#define SMALL_COM_LEN     (sizeof (SMALL_COM_SECTION))

/* Literal data structure.  */
typedef struct _hexagon_literal
{
  expressionS e, e1;
  segT sec;
  int sub;
  symbolS *sym;
  size_t size;
  const char *group_name;
  char name[MAX_LITERAL_NAME];
  const char *secname;
  struct _hexagon_literal *next;
} hexagon_literal;

/* Encode a conditional-execution predicate in a form that can be compared
   easily.  We keep 3 bits of state for each predicate register packed into
   a bitmask.  */
typedef long hexagon_pred_mask;
#define HEXAGON_PRED_LEN 3
#define HEXAGON_PRED_MSK (~(-1 << HEXAGON_PRED_LEN))
#define HEXAGON_PRED_YES 0x01	/* This predicate register is tested.  */
#define HEXAGON_PRED_NOT 0x02	/* Test is inverted.  */
#define HEXAGON_PRED_NEW 0x04	/* Test is dot-new qualified.  */
#define HEXAGON_PRED_GET(P, I)					\
  (((P) >> ((I) * HEXAGON_PRED_LEN)) & HEXAGON_PRED_MSK)
#define HEXAGON_PRED_SET(P, I, N)					\
  ((HEXAGON_PRED_GET (P, I) | ((N) & HEXAGON_PRED_MSK))			\
   << ((I) * HEXAGON_PRED_LEN))
#define HEXAGON_PRED_BITS(INVERTED, DOTNEW)			\
  (HEXAGON_PRED_YES						\
   | ((INVERTED) ? HEXAGON_PRED_NOT : 0)			\
   | ((DOTNEW) ? HEXAGON_PRED_NEW : 0))
#define HEXAGON_PRED_INIT(I, OPCODE)					   \
  (HEXAGON_PRED_BITS (HEXAGON_OPCODE_IS_CONDITION_INVERTED (OPCODE), \
		      HEXAGON_OPCODE_IS_CONDITION_DOTNEW (OPCODE))	\
   << ((I) * HEXAGON_PRED_LEN))

/* Packet instruction.  */
typedef struct _hexagon_packet_insn
{
  hexagon_insn insn;
  unsigned ndx;
  const hexagon_opcode *opcode;
  const hexagon_operand *ioperand;
  hexagon_pred_mask pred_mask;
  unsigned ireg, oreg;
  int opair;
  unsigned lineno;
  unsigned flags;
  unsigned pad:1, used:1;
  unsigned is_inner:1, is_outer:1;
  unsigned relax;
  hexagon_operand *operand;
  expressionS exp;
  unsigned fc;
  fixS *fix;
  /* Extender and original pair components.  */
  struct _hexagon_packet_insn *prefix, *left, *right;
  char *source;
} hexagon_packet_insn;

/* Flags for packet instruction.  */
enum _hexagon_insn_flag
{
  HEXAGON_INSN_IS_KXED = 0x01,	/* K-extension prefixed insn.  */
  HEXAGON_INSN_IS_R64 = 0x02,	/* Insn operates on register pairs.  */
  HEXAGON_INSN_IS_RELAX = 0x04,	/* Insn will be relaxed.  */
  HEXAGON_INSN_IN_RNEW = 0x08,	/* Insn has an operand of type R.NEW.  */
  HEXAGON_INSN_OUT_RNEW = 0x10,	/* Insn produces a result GPR.  */
  HEXAGON_INSN_IS_PAIR = 0x20,	/* Insn is paired.  */
};

/* Packet housekeeping.  */
typedef struct
{
  unsigned size;		/* Number of items in insn arrays.  */
  unsigned count;		/* Number of insns.  */
  unsigned prefix;		/* Number of k-extenders.  */
  unsigned duplex;		/* Number of duplex insns.  */
  unsigned relax;		/* Number of reserved slots.  */
  int drlx, ddrlx;		/* Deltas in extensions.  */
  int dpad, ddpad;		/* Deltas in padding NOP insns.  */
  int dpkt, ddpkt;		/* Deltas in padding NOP packets.  */
  unsigned lineno;		/* Line number at closing.  */
  unsigned stats;		/* Packet statistics.  */
  unsigned faligned:1;		/* Packet should be fetch-aligned.  */
  unsigned is_inner:1;		/* Packet has :endloop0.  */
  unsigned is_outer:1;		/* Packet has :endloop1.  */
  hexagon_packet_insn insns[MAX_PACKET_INSNS];	/* Insns.  */
} hexagon_packet;

#define hexagon_packet_slots(apacket) \
  ((apacket)->count + (apacket)->duplex)
#define hexagon_packet_length(apacket) \
  ((apacket)->count + (apacket)->prefix)
#define hexagon_packet_insns(apacket) \
  ((apacket)->count)

/* Instruction queue for packet formation.  */
typedef struct _hexagon_queue
{
  unsigned size;
  unsigned lineno;		/* Line number at closing.  */
  unsigned faligned:1;		/* Fetch-align request.  */
  unsigned is_inner:1;		/* :endloop0 request.  */
  unsigned is_outer:1;		/* :endloop1 request.  */
  hexagon_packet_insn insns[MAX_INSNS];	/* Insns.  */
} hexagon_queue;

typedef struct hexagon_frag_data
{
  hexagon_packet packet;
  fragS *previous;
} hexagon_frag_data;

/* Packet events tracked for statistics.  */
enum _hexagon_packet_stats
{
  HEXAGON_STATS_FALIGN = 0x01,	/* Adjustments due to .falign.  */
  HEXAGON_STATS_PAD = 0x02,	/* NOP padding inserted due to .falign.  */
  HEXAGON_STATS_PACK = 0x04,	/* NOP packet inserted due to .falign.  */
};

/* .falign counter types.  */
enum _hexagon_falign_counters
{
  HEXAGON_FALIGN_TOTAL,		/* # of .falign directives.  */
  HEXAGON_FALIGN_NEED,		/* ... which needed adjustments.  */
  HEXAGON_FALIGN_PAD,		/* ... which padded previous packets.  */
  HEXAGON_FALIGN_PACK,		/* ... which inserted new NOP packets.  */
  HEXAGON_FALIGN_FALIGN,	/* # of times that the history stopped due
				   to a fetch-alignment.  */
  HEXAGON_FALIGN_FALIGN1,	/* ... due to a single-insn fetch-alignment.  */
  HEXAGON_FALIGN_SECTION,	/* ... due to a section change.  */
  HEXAGON_FALIGN_END,		/* ... due to reaching end of the history.  */
  HEXAGON_FALIGN_TOP,		/* ... due to reaching top of the history.  */
  HEXAGON_FALIGN_LABEL,		/* ... due to a label.  */
  HEXAGON_FALIGN_ALIGN,		/* ... due to an alignment performed.  */
  HEXAGON_FALIGN_NOP,		/* ... due to a NOP packet inserted.  */
  HEXAGON_FALIGN_SHUF,		/* ... due to failure inserting a NOP.  */
  HEXAGON_FALIGN_COUNTERS
};

/* Pairing counter types.  */
enum _hexagon_pairs_counters
{
  HEXAGON_PAIRS_TOTAL,		/* # of total pairings.  */
  HEXAGON_PAIRS_UNDONE,		/* # of pairings undone.  */
  HEXAGON_PAIRS_COUNTERS
};

typedef enum _hexagon_suffix_type
{
  SUF_NONE, SUF_1ST,
  PIC_PCREL = 1,
  PIC_GOTREL,
  PIC_GOT,
  PIC_PLT,
  TLS_GD_GOT,
  TLS_LD_GOT,
  TLS_GD_PLT,
  TLS_LD_PLT,
  TLS_IE_GOT,
  TLS_IE,
  TLS_DTPREL,
  TLS_TPREL,
  SUF_MAX
} hexagon_suffix_type;

struct _hexagon_suffix
{
  const char *pri, *sec;
} hexagon_suffix[] = {
  {"", NULL},
  {"pcrel", NULL},
  {"gotrel", "gotoff"},
  {"got", NULL},
  {"plt", NULL},
  {"gdgot", NULL},
  {"ldgot", NULL},
  {"gdplt", NULL},
  {"ldplt", NULL},
  {"iegot", NULL},
  {"ie", NULL},
  {"dtprel", NULL},
  {"tprel", NULL},
};

/* Defined in bfd/cpu-hexagon.c, which doesn't have a corresponding .h.  */
extern int hexagon_get_mach (char *);

/* Forward declarations.  */
static int hexagon_assemble (hexagon_packet_insn *, char *, int);
static void hexagon_common (int);
static void hexagon_option (int);
static void hexagon_falign (int);

static segT hexagon_sdata_section, hexagon_sbss_section;
static asection hexagon_scom_section;
static asymbol hexagon_scom_symbol;

static hexagon_literal *hexagon_pool;
static unsigned hexagon_pool_counter;

/* Special insns created by GAS.  */
static hexagon_packet_insn hexagon_nop_insn, hexagon_kext_insn;

static symbolS *hexagon_got_symbol;

const pseudo_typeS md_pseudo_table[] = {
  {"align", s_align_bytes, 0},	/* Defaulting is invalid (0).  */
  {"comm", hexagon_common, 0},
  {"common", hexagon_common, 0},
  {"lcomm", hexagon_common, 1},
  {"lcommon", hexagon_common, 1},
  {"2byte", cons, 2},
  {"half", cons, 2},
  {"short", cons, 2},
  {"3byte", cons, 3},
  {"4byte", cons, 4},
  {"word", cons, 4},
  {"option", hexagon_option, 0},
  {"cpu", hexagon_option, 0},
  {"block", s_space, 0},
  {"file", (void (*) (int)) dwarf2_directive_file, 0},
  {"loc", dwarf2_directive_loc, 0},
  {"falign", hexagon_falign, 0},
  {NULL, 0, 0},
};

/* Valid characters that make up a symbol.  */
const char hexagon_symbol_chars[] = "";

/* This array holds the chars that always start a comment.  If the
   pre-processor is disabled, these aren't very useful.  */
const char comment_chars[] = "";

/* This array holds the chars that only start a comment at the beginning of
   a line.  If the line seems to have the form '# 123 filename'
   .line and .file directives will appear in the pre-processed output */
/* Note that input_file.c hand checks for '#' at the beginning of the
   first line of the input file.  This is because the compiler outputs
   #NO_APP at the beginning of its output.  */
/* Also note that comments started like this one will always
   work if '/' isn't otherwise defined.  */
const char line_comment_chars[] = "#";

const char line_separator_chars[] = ";";

const char hexagon_parallel_separator_chars[] = "{}";

/* Chars that can be used to separate mant from exp in floating point nums.  */
const char EXP_CHARS[] = "eE";

/* Chars that mean this number is a floating point constant
   As in 0f12.456 or 0d1.2345e12.  */
const char FLT_CHARS[] = "rRsSfFdD";

#ifdef TARGET_IS_LINUX
static int hexagon_mach_type = bfd_mach_hexagon_v5;
#else
static int hexagon_mach_type = bfd_mach_hexagon_v4;
#endif
static int cmdline_set_hexagon_mach_type = 0;

/* Non-zero if the cpu type has been explicitly specified.  */
static int mach_type_specified_p = 0;

/* Non-zero if opcode tables have been initialized.
   A .option command must appear before any instructions.  */
static int cpu_tables_init_p = 0;

const char *md_shortopts = "G:";
struct option md_longopts[] = {
#define OPTION_HEX_PAIR_INFO (OPTION_MD_BASE + 0)
  {"mpairing-info", no_argument, NULL, OPTION_HEX_PAIR_INFO},
#define OPTION_HEX_FALIGN_INFO_NEW (OPTION_MD_BASE + 1)
  {"mfalign-info", no_argument, NULL, OPTION_HEX_FALIGN_INFO_NEW},
#define OPTION_HEX_FALIGN_MORE_INFO (OPTION_MD_BASE + 2)
  {"mfalign-more-info", no_argument, NULL, OPTION_HEX_FALIGN_MORE_INFO},
#define OPTION_HEX_FALIGN_WARN (OPTION_MD_BASE + 3)
  {"mfalign-warn", no_argument, NULL, OPTION_HEX_FALIGN_WARN},
#define OPTION_HEX_NO_2MEMORY (OPTION_MD_BASE + 4)
  {"mno-dual-memory", no_argument, NULL, OPTION_HEX_NO_2MEMORY},
/* Code in md_parse_option () assumes that the -mv* options are sequential.  */
#define OPTION_HEX_MV2 (OPTION_MD_BASE + 5)
  {"mv2", no_argument, NULL, OPTION_HEX_MV2},
#define OPTION_HEX_MV3 (OPTION_MD_BASE + 6)
  {"mv3", no_argument, NULL, OPTION_HEX_MV3},
#define OPTION_HEX_MV4 (OPTION_MD_BASE + 7)
  {"mv4", no_argument, NULL, OPTION_HEX_MV4},
#define OPTION_HEX_MV5 (OPTION_MD_BASE + 8)
  {"mv5", no_argument, NULL, OPTION_HEX_MV5},
#define OPTION_HEX_MV55 (OPTION_MD_BASE + 9)
  {"mv55", no_argument, NULL, OPTION_HEX_MV55},
#define OPTION_HEX_MARCH (OPTION_MD_BASE + 10)
  {"march", required_argument, NULL, OPTION_HEX_MARCH},
#define OPTION_HEX_MCPU (OPTION_MD_BASE + 11)
  {"mcpu", required_argument, NULL, OPTION_HEX_MCPU},
#define OPTION_HEX_MSORT_SDA (OPTION_MD_BASE + 12)
  {"msort-sda", no_argument, NULL, OPTION_HEX_MSORT_SDA},
#define OPTION_HEX_MNO_SORT_SDA (OPTION_MD_BASE + 13)
  {"mno-sort-sda", no_argument, NULL, OPTION_HEX_MNO_SORT_SDA},
#define OPTION_HEX_MNO_EXTENDER (OPTION_MD_BASE + 14)
  {"mno-extender", no_argument, NULL, OPTION_HEX_MNO_EXTENDER},
#define OPTION_HEX_MNO_PAIRING (OPTION_MD_BASE + 15)
  {"mno-pairing", no_argument, NULL, OPTION_HEX_MNO_PAIRING},
#define OPTION_HEX_MNO_PAIRING_B (OPTION_MD_BASE + 16)
  {"mno-pairing-branch", no_argument, NULL, OPTION_HEX_MNO_PAIRING_B},
#define OPTION_HEX_MNO_PAIRING_2 (OPTION_MD_BASE + 17)
  {"mno-pairing-duplex", no_argument, NULL, OPTION_HEX_MNO_PAIRING_2},
#define OPTION_HEX_MNO_JUMPS (OPTION_MD_BASE + 18)
  {"mno-jumps", no_argument, NULL, OPTION_HEX_MNO_JUMPS},
#define OPTION_HEX_MNO_JUMPS_LONG (OPTION_MD_BASE + 19)
  {"mno-jumps-long", no_argument, NULL, OPTION_HEX_MNO_JUMPS_LONG},
#define OPTION_HEX_MNO_FALIGN (OPTION_MD_BASE + 20)
  {"mno-falign", no_argument, NULL, OPTION_HEX_MNO_FALIGN},
#define OPTION_HEX_MNO_DEALLOC_RETURN (OPTION_MD_BASE + 21)
  {"mno-dealloc_return", no_argument, NULL, OPTION_HEX_MNO_DEALLOC_RETURN},
};

size_t md_longopts_size = sizeof (md_longopts);

#define IS_SYMBOL_OPERAND(o) \
 ((o) == 'b' || (o) == 'c' || (o) == 's' || (o) == 'o' || (o) == 'O')

/* Relax states.  */
typedef enum _hexagon_relax_state
{
  /* Matching the respective entries in hexagon_relax_table.  */
  HEXAGON_RELAX_NONE = 0,
  /* Relax state for R_HEX_B7_PCREL.  */
  HEXAGON_RELAX_B7, HEXAGON_RELAX_B7_A,
  /* Relax state for R_HEX_B9_PCREL.  */
  HEXAGON_RELAX_B9, HEXAGON_RELAX_B9_A,
  /* Relax state for R_HEX_B13_PCREL.  */
  HEXAGON_RELAX_B13, HEXAGON_RELAX_B13_A,
  /* Relax state for R_HEX_B15_PCREL.  */
  HEXAGON_RELAX_B15, HEXAGON_RELAX_B15_A,
  /* Other relax state pairs go here.  */
  /* Done relaxing.  */
  HEXAGON_RELAX_DONE
} hexagon_relax_state;

#define HEXAGON_RANGE(B) (~(~0L << ((B) - 1)) \
			  & -(2 * MAX_PACKET_INSNS * HEXAGON_INSN_LEN))

/* State table for relaxing branches.
   Note that since an extender is used, the insn is moved up,
   so the limits are offset by that.  */
const struct relax_type hexagon_relax_table[] = {
  /* Dummy entry.  */
  {0L, 0L,
   0, HEXAGON_RELAX_NONE},
  /* Entries for R_HEX_B7_PCREL.  */
  {HEXAGON_RANGE (9), -HEXAGON_RANGE (9),
   0, HEXAGON_RELAX_B7_A},
  {0L, 0L,
   HEXAGON_INSN_LEN, HEXAGON_RELAX_DONE},
  /* Entries for R_HEX_B9_PCREL.  */
  {HEXAGON_RANGE (11), -HEXAGON_RANGE (11),
   0, HEXAGON_RELAX_B9_A},
  {0L, 0L,
   HEXAGON_INSN_LEN, HEXAGON_RELAX_DONE},
  /* Entries for R_HEX_B13_PCREL.  */
  {HEXAGON_RANGE (15), -HEXAGON_RANGE (15),
   0, HEXAGON_RELAX_B13_A},
  {0L, 0L,
   HEXAGON_INSN_LEN, HEXAGON_RELAX_DONE},
  /* Entries for R_HEX_B15_PCREL.  */
  {HEXAGON_RANGE (17), -HEXAGON_RANGE (17),
   0, HEXAGON_RELAX_B15_A},
  {0L, 0L,
   HEXAGON_INSN_LEN, HEXAGON_RELAX_DONE},
  /* Pair of entries for other relocations go here.  */
  /* Final entry.  */
  {0L, 0L,
   0, HEXAGON_RELAX_NONE},
};

static int hexagon_autoand = TRUE;
static int hexagon_extender = TRUE;
static int hexagon_pairing = TRUE;
static int hexagon_pairing_branch = TRUE;
static int hexagon_pairing_duplex = TRUE;
static int hexagon_relax = TRUE;
static int hexagon_relax_long = TRUE;
static int hexagon_sort_sda = TRUE;
static int hexagon_fetch_align = TRUE;
static int hexagon_dealloc_return = TRUE;

static int hexagon_faligning;	/* Indicate .falign for the next packet.  */
static int hexagon_falign_info;	/* Report statistics about .falign usage.  */
static int hexagon_falign_more;	/* Report more statistics about .falign.  */
static int hexagon_falign_warn;	/* Warn when .falign paddings occur.  */

static int hexagon_pairs_info;	/* Report statistics about pairings.  */

static unsigned hexagon_gp_size = HEXAGON_SMALL_GPSIZE;
static int hexagon_no_dual_memory = FALSE;

static int hexagon_in_packet;

static hexagon_packet hexagon_apacket;	/* Includes current packet.  */
static hexagon_queue hexagon_aqueue;

/* .falign statistics.  */
static unsigned n_falign[HEXAGON_FALIGN_COUNTERS];
/* Pairing statistics.  */
static unsigned n_pairs[HEXAGON_PAIRS_COUNTERS];


/* Structure to keep track of possible multiple writes to the same register
   within a packet.  */
typedef struct hexagon_reg_score
{
  char used;	/* Nonzero if register is modified in packet.  */
  char letter;  /* Encoding letter.  */
  int index;	/* Index within packet of instruction using register.  */
  hexagon_pred_mask pred[MAX_INSNS]; /* Bitmask to encode condition on access.  */

} hexagon_reg_score;

typedef struct hexagon_packet_score
{
  /* Score-boards to check register dependency conflicts.  */
  hexagon_reg_score gp_regs[HEXAGON_NUM_GENERAL_PURPOSE_REGS];
  hexagon_reg_score control_regs[HEXAGON_NUM_CONTROL_REGS];
  hexagon_reg_score system_regs[HEXAGON_NUM_SYS_CTRL_REGS];
  hexagon_reg_score pred_regs[HEXAGON_NUM_PREDICATE_REGS];
  hexagon_reg_score guest_regs[HEXAGON_NUM_GUEST_REGS];
  hexagon_reg_score pred_new_regs[HEXAGON_NUM_PREDICATE_REGS];
  hexagon_reg_score pred_late_regs[HEXAGON_NUM_PREDICATE_REGS];

  /* Counters for different instruction types and restrictions.  */
  int sr_ovf;			/* SR:OVF bit set.  */
  int jump;			/* Jumps, including loops.  */
  int dualjump;			/* Total jumps valid as dual jumps.  */
  int dualjump1;		/* Dual jump in first slot.  */
  int dualjump2;		/* Dual jump in second slot.  */
} hexagon_packet_score;

typedef struct _hexagon_march
{
  char *march_name_fe, *march_alt_fe, *march_short_fe;
  unsigned int march_name_be;
} hexagon_march;

static hexagon_march hexagon_marchs[] = {
  {"hexagonv2", "qdsp6v2", "v2", bfd_mach_hexagon_v2},
  {"hexagonv3", "qdsp6v3", "v3", bfd_mach_hexagon_v3},
  {"hexagonv4", "qdsp6v4", "v4", bfd_mach_hexagon_v4},
  {"hexagonv5", "qdsp6v5", "v5", bfd_mach_hexagon_v5},
  {"hexagonv55", "qdsp6v55", "v55", bfd_mach_hexagon_v55},
};


/* Instruction utilities.  */

/* Initialize the global NOP insn object.  */
static hexagon_insn
hexagon_find_nop (void)
{
  hexagon_nop_insn.insn = hexagon_nop_opcode->insn;
  hexagon_nop_insn.opcode = hexagon_nop_opcode;

  return hexagon_nop_opcode->insn;
}

/* Initialize the global KEXT insn object.  */
static hexagon_insn
hexagon_find_kext (void)
{
  if (hexagon_if_arch_kext ())
    {
      hexagon_kext_insn.insn = hexagon_kext_opcode->insn;
      hexagon_kext_insn.opcode = hexagon_kext_opcode;
      return hexagon_kext_opcode->insn;
    }
  else
    {
      memset (&hexagon_kext_insn, 0, sizeof (hexagon_kext_insn));
      return FALSE;
    }
}

/* Initialize the insn AINSN.  */
static void
hexagon_insn_init (hexagon_packet_insn *ainsn)
{
  memset (ainsn, 0, sizeof (*ainsn));
  *ainsn = hexagon_nop_insn;
  ainsn->pad = TRUE;
}

/* Adjust fixup information for AINSN.  The WHERE and OFFSET
   parameters are given in instruction counts within a packet.  */
static void
hexagon_adjust_fix (hexagon_packet_insn *ainsn, size_t where, size_t offset)
{
  if (ainsn->fc && ainsn->fix)
    {
      ainsn->fix->fx_where = where * HEXAGON_INSN_LEN;
      if (ainsn->fix->fx_pcrel)
	ainsn->fix->fx_offset += offset * HEXAGON_INSN_LEN;
    }
}

/* Set the parse bits of the insn at offset I in APACKET.
   Returns the updated insn encoding; APACKET is not modified.  */
static hexagon_insn
hexagon_set_parse_bits (hexagon_packet *apacket, size_t i)
{
  hexagon_insn insn;

  insn = HEXAGON_END_PACKET_RESET (apacket->insns[i].insn);

  if (i == 0 && apacket->is_inner)
    /* Mark the 1st insn for the inner loop.  */
    insn = HEXAGON_END_PACKET_SET (insn, HEXAGON_END_LOOP);
  else if (i == 1 && apacket->is_outer)
    /* Mart the 2nd insn for the outer loop.  */
    insn = HEXAGON_END_PACKET_SET (insn, HEXAGON_END_LOOP);
  else if (i >= apacket->size - 1
	   && HEXAGON_END_PACKET_GET (insn) != HEXAGON_END_PAIR)
    /* Mark the last insn for the end of the packet, unless a duplex.  */
    insn = HEXAGON_END_PACKET_SET (insn, HEXAGON_END_PACKET);

  return insn;
}

/* Emit INSN to STREAM at OFFSET.  If FC is nonzero, create a fixup for
   operand OP with EXP and store it in FIXSP.  */
static void
hexagon_insn_write (hexagon_insn insn, size_t fc, const hexagon_operand *op,
		    expressionS *exp, char *stream, size_t offset,
		    fixS **fixSP)
{
  fixS *fixP = NULL;
  addressT pc;

  /* Create any fixups */
  if (fc)
    {
      bfd_reloc_code_real_type reloc_type;
      hexagon_operand *operand;

      operand = xmalloc (sizeof (*operand));
      *operand = *op;

      reloc_type = (operand->flags & HEXAGON_OPERAND_IS_KXED
		    ? operand->reloc_kxed
		    : operand->reloc_type);

      pc = frag_now->fr_address + frag_now_fix ();

      fixP = fix_new_exp (frag_now, stream + offset - frag_now->fr_literal,
			  HEXAGON_INSN_LEN, exp,
			  (operand->flags & HEXAGON_OPERAND_PC_RELATIVE ? 1: 0),
			  reloc_type);
      fixP->tc_fix_data = operand;

      if (operand->flags & (HEXAGON_OPERAND_IS_LO16 | HEXAGON_OPERAND_IS_HI16))
	fixP->fx_no_overflow = TRUE;

      if (operand->flags & HEXAGON_OPERAND_PC_RELATIVE)
	/* Any PC relative operands within a packet must be relative
	   to the address of the packet, so the offset is adjusted to
	   account for that.  */
	fixP->fx_offset += offset;
    }
  else
    /* Allocate space for an insn.  */
    pc = frag_now->fr_address + frag_now_fix ();

  /* Write out the instruction.  */
  md_number_to_chars (stream + offset, insn, HEXAGON_INSN_LEN);

  if (pc % HEXAGON_INSN_LEN)
    as_warn (_("current location is not %d-byte aligned."), HEXAGON_INSN_LEN);

  /* Hexagon insns will never have more than 1 fixup? */
  if (fixSP)
    *fixSP = fixP;
}


/* Packet utilities.  */

/* Initialize the packet APACKET.  */
static void
hexagon_packet_init (hexagon_packet *apacket)
{
  size_t i;

  memset (apacket, 0, sizeof (*apacket));

  for (i = 0; i < MAX_PACKET_INSNS; i++)
    hexagon_insn_init (&apacket->insns[i]);
}


/* Return number of extender prefixes in APACKET.  */
static int
hexagon_packet_has_prefix (const hexagon_packet *apacket)
{
  size_t i;
  int count;

  /* Count number of extender prefixes in this packet.  */
  for (i = count = 0; i < apacket->size; i++)
    if (HEXAGON_OPCODE_IS_EXTENDER (apacket->insns[i].opcode))
      count++;

  return count;
}

/* Return number of paired insns in APACKET.  */
static int
hexagon_packet_has_pair (const hexagon_packet *apacket)
{
  size_t i;
  int count;

  /* Count number of compound insns in this packet.  */
  for (i = count = 0; i < apacket->size; i++)
    if (HEXAGON_OPCODE_IS_COMPOUND (apacket->insns[i].opcode))
      count++;

  return count;
}

/* Return number of duplex insns in PACKET.  If WHICH is non-null, store
   the index of the last duplex found there.  */
static int
hexagon_packet_has_duplex (const hexagon_packet *apacket, size_t *which)
{
  size_t i;
  int count;

  /* Count number of duplex insns in this packet.  */
  for (i = count = 0; i < apacket->size; i++)
    if (HEXAGON_OPCODE_IS_DUPLEX (apacket->insns[i].opcode))
      {
	count++;
	if (which)
	  *which = i;
      }

  return count;
}


/* Check if APACKET has a r.new insn, and return it if so.  */
static hexagon_packet_insn * 
hexagon_packet_has_rnew (const hexagon_packet *apacket)
{
  size_t i;

  for (i = 0; i < apacket->size; i++)
    if (apacket->insns[i].flags & HEXAGON_INSN_IN_RNEW)
      return ((hexagon_packet *) apacket)->insns + i;
  return NULL;
}

/* Return number of memory operation insns in APACKET.  */
static int
hexagon_packet_has_mem (const hexagon_packet *apacket)
{
  size_t i;
  int count;

  /* Count number of memory ops in this packet.  */
  for (i = count = 0; i < apacket->size; i++)
    if (apacket->insns[i].opcode
	&& HEXAGON_OPCODE_IS_MEMORY (apacket->insns[i].opcode))
      count++;

  return count;
}

/* Return number of store insns in APACKET.  */
static int
hexagon_packet_has_store (const hexagon_packet *apacket)
{
  size_t i;
  int count;

  /* Count number of stores in this packet.  */
  for (count = i = 0; i < apacket->size; i++)
    if (HEXAGON_OPCODE_IS_STORE (apacket->insns[i].opcode))
      count++;

  return count;
}

/* Return number of store restrictions in APACKET.  */
static int
hexagon_packet_has_store_not (const hexagon_packet *apacket)
{
  size_t i;
  int count;

  /* Count number of store restrictions in this packet.  */
  for (count = i = 0; i < apacket->size; i++)
    if (HEXAGON_OPCODE_IS_RESTRICT_SLOT1_NOSTORE (apacket->insns[i].opcode))
      count++;

  return count;
}

/* Return number of A-type restrictions in APACKET.  */
static int
hexagon_packet_has_a_only (const hexagon_packet *apacket)
{
  size_t i;
  int count;

  /* Count number of A-type restrictions in this packet.  */
  for (count = i = 0; i < apacket->size; i++)
    if (HEXAGON_OPCODE_IS_RESTRICT_SLOT1_AONLY (apacket->insns[i].opcode))
      count++;

  return count;
}

/* Return true if APACKET has an insn that precludes insns other than A-type
   and non-float X-type insns from the same packet.  */
static int
hexagon_packet_has_but_ax (const hexagon_packet *apacket)
{
  size_t i;
  size_t axok, count;

  /* Count number of RESTRICT_AX insns and AX insns in this packet.  */
  for (axok = count = i = 0; i < apacket->size; i++)
    {
      const hexagon_packet_insn *ainsn = apacket->insns + i;
      if (HEXAGON_OPCODE_IS_RESTRICT_AX (ainsn->opcode)
	  /* Check for special cases.  */
	  && (!HEXAGON_OPCODE_IS_RESTRICT_AX_SOMEREGS (ainsn->opcode)
	      || ((hexagon_if_arch_v3 ()
		   && ainsn->oreg != 2	/* SSR */
		   && ainsn->oreg != 21	/* TLBHI */
		   && ainsn->oreg != 22	/* TLBLO */
		   && ainsn->oreg != 23)    /* TLBIDX */
		  || ((hexagon_if_arch_v4 () || hexagon_if_arch_v5 ()
		       || hexagon_if_arch_v55 ())
		      && ainsn->oreg != 6 /* SSR */ ))))
	  axok++;

      if (!HEXAGON_OPCODE_IS_COMPOUND (ainsn->opcode)
	  && !HEXAGON_OPCODE_IS_XFLOAT (ainsn->opcode)
	  && (HEXAGON_INSN_TYPE_A (ainsn->insn)
	      || HEXAGON_INSN_TYPE_X (ainsn->insn)))
	count++;
    }

  return !axok || ((axok + count) == apacket->size);
}

/* Return true if APACKET contains a solo insn (one that cannot exist
   with other insns in a packet).  */
static int
hexagon_packet_has_solo (const hexagon_packet *apacket)
{
  size_t i;

  /* Solo insns cannot exist in a packet.  */
  for (i = 0; i < apacket->size; i++)
    if (HEXAGON_OPCODE_IS_SOLO (apacket->insns[i].opcode))
      return TRUE;

  return FALSE;
}

/* Return true if PACKET has an insn with a SLOT1_EMPTY restriction,
   ignoring the one with index CURRENT.  */
static int
hexagon_packet_has_slot1_empty (const hexagon_packet *packet, size_t current)
{
  size_t i;

  for (i = 0; i < packet->size; i++)
    if (i != current && !packet->insns[i].used)
      if (HEXAGON_OPCODE_IS_RESTRICT_SLOT1_EMPTY (packet->insns[i].opcode))
	return TRUE;

  return FALSE;
}

/* Move prefixes in APACKET to the side-lines.  */
static void
hexagon_packet_unfold (hexagon_packet *apacket)
{
  hexagon_packet packet;
  hexagon_packet_insn prefix;
  size_t i;

  /* Ignore an empty packet.  */
  if (!apacket->size)
    return;

  hexagon_insn_init (&prefix);

  packet = *apacket;
  /* Initialize new insn array.  */
  memset (&apacket->insns, 0, sizeof (apacket->insns));
  apacket->size = apacket->count = apacket->prefix = 0;

  for (i = 0; i < packet.size; i++)
    {
      hexagon_packet_insn *ainsn;

      if (packet.insns[i].pad)
	/* Skip padding insns.  */
	continue;

      /* Sanity check.  */
      assert (apacket->size < MAX_PACKET_INSNS);

      if (HEXAGON_OPCODE_IS_EXTENDER (packet.insns[i].opcode))
	{
	  /* Save the prefix.  */
	  prefix = packet.insns[i];
	  continue;
	}

      /* Insert the insn.  */
      ainsn = apacket->insns + apacket->size;
      *ainsn = packet.insns[i];
      hexagon_adjust_fix (ainsn, apacket->size, apacket->size - i);

      if ((packet.insns[i].flags & HEXAGON_INSN_IS_KXED))
	{
	  /* Insert the prefix.  */
	  ainsn->prefix = xmalloc (sizeof (*ainsn->prefix));
	  *ainsn->prefix = prefix;
	  hexagon_adjust_fix (ainsn->prefix, apacket->size,
			      apacket->size - (i - 1));
	  apacket->prefix++;
	}

      apacket->size++;
      if (!packet.insns[i].pad)
	apacket->count++;
    }
}

/* Move prefixes in APACKET inline with the insns.
   Assumes that the packet has already been shuffled and padded.  */
static void
hexagon_packet_fold (hexagon_packet *apacket)
{
  hexagon_packet packet;
  size_t i;

  /* Ignore an empty packet or one devoid of prefixes.  */
  if (!apacket->size || !apacket->prefix)
    return;

  packet = *apacket;
  /* Initialize new insn array.  */
  memset (&apacket->insns, 0, sizeof (apacket->insns));
  apacket->size = apacket->count = apacket->prefix = 0;

  /* Merge the insn and the prefix arrays.  */
  for (i = 0; i < packet.size; i++)
    {
      hexagon_packet_insn *ainsn;

      if (packet.insns[i].pad && packet.prefix)
	{
	  /* Skip padding insns to make room for a prefix.  */
	  packet.prefix--;
	  continue;
	}

      /* Sanity check.  */
      assert (apacket->size < MAX_PACKET_INSNS);

      if (packet.insns[i].flags & HEXAGON_INSN_IS_KXED)
	{
	  /* Insert the prefix.  */
	  ainsn = apacket->insns + apacket->size;
	  *ainsn = *packet.insns[i].prefix;
	  hexagon_adjust_fix (ainsn, apacket->size, apacket->size - i);

	  apacket->size++;
	  apacket->prefix++;

	  /* Sanity check.  */
	  assert (apacket->size < MAX_PACKET_INSNS);
	}

      /* Insert the insn.  */
      ainsn = apacket->insns + apacket->size;
      *ainsn = packet.insns[i];
      hexagon_adjust_fix (ainsn, apacket->size, apacket->size - i);

      apacket->size++;
      if (!packet.insns[i].pad)
	apacket->count++;
    }
}

/* Remove padded insns from APACKET.
   Assumes that the packet is in its final form (no prefixes or pairs).  */
static void
hexagon_packet_unpad (hexagon_packet *apacket)
{
  hexagon_packet packet;
  size_t size;
  size_t i;

  size = apacket->size;
  if (!size)
    return;

  hexagon_packet_init (&packet);

  /* Merge the insn and the prefix arrays.  */
  for (i = 0; i < size; i++)
    {
      hexagon_packet_insn *ainsn = apacket->insns + i;
      if (ainsn->pad)
	continue;
      hexagon_adjust_fix (ainsn, packet.size, packet.size - i);

      /* Insert the insn.  */
      packet.insns[packet.size++] = *ainsn;
      /* Sanity check.  */
      assert (packet.size <= MAX_PACKET_INSNS);
    }

  /* Copy new insn array.  */
  memcpy (apacket->insns, packet.insns, sizeof (apacket->insns));

  /* Update housekeeping.  */
  apacket->size = packet.size;
}

/* Add insn AINSN to packet APACKET.  PAD should be true if this insn is
   merely padding.  Returns true if successful.  */
static int
hexagon_packet_insert (hexagon_packet *apacket,
		       const hexagon_packet_insn *ainsn, int pad)
{
  int prefixed = ((!pad
		   && ainsn->flags & HEXAGON_INSN_IS_KXED
		   && ainsn->prefix
		   && HEXAGON_OPCODE_IS_EXTENDER (ainsn->prefix->opcode))
		  ? 1 : 0);
  int duplex = HEXAGON_OPCODE_IS_DUPLEX (ainsn->opcode) ? 1 : 0;
  int relax = (ainsn->flags & HEXAGON_INSN_IS_RELAX) ? 1 : 0;
  int slots = pad ? apacket->size : hexagon_packet_slots (apacket);
  int length = pad ? apacket->size : hexagon_packet_length (apacket);

  if (duplex && apacket->duplex)
    /* Limit duplex insns to one per packet.  */
    return FALSE;

  if (slots + duplex < MAX_PACKET_INSNS
      && length + prefixed + relax < MAX_PACKET_INSNS)
    {
      apacket->insns[apacket->size] = *ainsn;
      apacket->insns[apacket->size].pad = pad;
      if (prefixed)
	{
	  apacket->insns[apacket->size].prefix->pad = pad;
	  apacket->insns[apacket->size].prefix->lineno = ainsn->lineno;
	  apacket->prefix++;
	}
      apacket->lineno = MAX (ainsn->lineno, apacket->lineno);
      apacket->is_inner |= ainsn->is_inner;
      apacket->is_outer |= ainsn->is_outer;
      apacket->size++;
      if (!pad)
	{
	  apacket->count += 1;
	  apacket->duplex += duplex;
	  apacket->relax += relax;
	}
      return TRUE;
    }

  return FALSE;
}

/* Add insn AINSN to packet APACKET foregoing branch relaxation.  PAD
   should be true if the insn is merely padding.  Returns true if
   successful.  */
static int
hexagon_packet_cram (hexagon_packet *apacket,
		     hexagon_packet_insn *ainsn, int pad)
{
  hexagon_packet packet;
  hexagon_packet_insn insn;
  size_t i;

  /* Try to insert insn.  */
  if (hexagon_packet_insert (apacket, ainsn, pad))
    return TRUE;
  else
    {
      insn = *ainsn;

      if (!(insn.flags & HEXAGON_INSN_IS_PAIR)
	  && insn.flags & HEXAGON_INSN_IS_RELAX)
	{
	  /* Remove branch relaxation if range has not been reduced
	     by pairing.  */
	  insn.relax = HEXAGON_RELAX_NONE;
	  insn.flags &= ~HEXAGON_INSN_IS_RELAX;

	  /* Try again.  */
	  if (hexagon_packet_insert (apacket, &insn, pad))
	    return TRUE;
	}

      if (apacket->relax)
	{
	  packet = *apacket;
	  /* Remove any branch relaxation if range has not been reduced
	     by pairing.  */
	  for (i = packet.size; i > 0; i--)
	    if (!(packet.insns[i - 1].flags & HEXAGON_INSN_IS_PAIR)
		&& packet.insns[i - 1].flags & HEXAGON_INSN_IS_RELAX)
	      {
		packet.insns[i - 1].relax = HEXAGON_RELAX_NONE;
		packet.insns[i - 1].flags &= ~HEXAGON_INSN_IS_RELAX;
		packet.relax--;

		/* Try again.  */
		if (hexagon_packet_insert (&packet, &insn, pad))
		  {
		    *apacket = packet;
		    return TRUE;
		  }
	      }
	}

      /* Remove branch relaxation.  */
      insn.relax = HEXAGON_RELAX_NONE;
      insn.flags &= ~HEXAGON_INSN_IS_RELAX;

      /* Try again.  */
      if (hexagon_packet_insert (apacket, &insn, pad))
	return TRUE;

      if (apacket->relax)
	{
	  packet = *apacket;
	  /* Remove any branch relaxation.  */
	  for (i = packet.size - 1; i < packet.size; i--)
	    if (packet.insns[i].flags & HEXAGON_INSN_IS_RELAX)
	      {
		packet.insns[i].relax = HEXAGON_RELAX_NONE;
		packet.insns[i].flags &= ~HEXAGON_INSN_IS_RELAX;
		packet.relax--;

		/* Try again.  */
		if (hexagon_packet_insert (&packet, &insn, pad))
		  {
		    *apacket = packet;
		    return TRUE;
		  }
	      }
	}
    }

  return FALSE;
}



/* Packet queue management and packet formation.  */

/* Initialize insn queue AINSN.  */
static void
hexagon_queue_init (hexagon_queue *aqueue)
{
  memset (aqueue, 0, sizeof (*aqueue));
}

/* Insert AINSN into AQUEUE.  */
static int
hexagon_queue_insert (hexagon_queue *aqueue, hexagon_packet_insn *ainsn)
{
  if (aqueue->size < MAX_INSNS && !ainsn->pad)
    {
      aqueue->insns[aqueue->size] = *ainsn;
      aqueue->lineno = ainsn->lineno;
      aqueue->faligned = hexagon_faligning;
      aqueue->is_inner |= ainsn->is_inner;
      aqueue->is_outer |= ainsn->is_outer;
      aqueue->size++;
      return TRUE;
    }

  return FALSE;
}

/* Return true if AINSN would conflict with other insns in AQUEUE, 
   if it happens to be a duplex or vice-versa.  */
static int
hexagon_has_duplex_clash (const hexagon_queue *aqueue,
			  const hexagon_packet_insn *ainsn)
{
  size_t i;

  /* Count number of memory ops in this packet.  */
  for (i = 0; i < aqueue->size; i++)
    if (!aqueue->insns[i].pad && !ainsn->pad)
      if ((HEXAGON_OPCODE_IS_DUPLEX (aqueue->insns[i].opcode)
	   && ainsn->opcode->slots & HEXAGON_SLOTS_DUPLEX
	   && !(ainsn->opcode->slots & ~HEXAGON_SLOTS_DUPLEX))
	  || (HEXAGON_OPCODE_IS_DUPLEX (ainsn->opcode)
	      && aqueue->insns[i].opcode->slots & HEXAGON_SLOTS_DUPLEX
	      && !(aqueue->insns[i].opcode->slots & ~HEXAGON_SLOTS_DUPLEX))
	  /* FIXME: ideally, duplex insns that have only A and X types
	     should be so marked.  */
	  || (HEXAGON_OPCODE_IS_DUPLEX (aqueue->insns[i].opcode)
	      && HEXAGON_OPCODE_IS_RESTRICT_AX (ainsn->opcode))
	  || (HEXAGON_OPCODE_IS_DUPLEX (ainsn->opcode)
	      && HEXAGON_OPCODE_IS_RESTRICT_AX (aqueue->insns[i].opcode)))
	return TRUE;

  return FALSE;
}

/* Attempt to pair the left/right subparts of AINSN.  Return TRUE if
   the pairing is successful.  */
static int
hexagon_assemble_pair (hexagon_packet_insn *ainsn)
{
  hexagon_packet_insn insn;
  char *ltor, *rtol;
  int are_stores;
  size_t l;

  /* Do nothing if pairing is disabled.  */
  if (!hexagon_pairing)
    return FALSE;

  /* Skip certain insns.  */
  if (
      /* Packed or duplex insns.  */
      HEXAGON_OPCODE_IS_COMPOUND (ainsn->left->opcode)
      || HEXAGON_OPCODE_IS_DUPLEX (ainsn->left->opcode)
      || HEXAGON_OPCODE_IS_COMPOUND (ainsn->right->opcode)
      || HEXAGON_OPCODE_IS_DUPLEX (ainsn->right->opcode)
      /* Prefix insns.  */
      || HEXAGON_OPCODE_IS_EXTENDER (ainsn->left->opcode)
      || HEXAGON_OPCODE_IS_EXTENDER (ainsn->right->opcode)
      /* Both extended insns.  */
      || (ainsn->left->flags & HEXAGON_INSN_IS_KXED
	  && ainsn->right->flags & HEXAGON_INSN_IS_KXED)
      /* Both insns have symbolic references.  */
      || (ainsn->left->fc && ainsn->right->fc)
      /* Selectively, direct branch insns.  */
      || (!hexagon_pairing_branch
	  && (HEXAGON_OPCODE_IS_PCREL_BRANCH (ainsn->left->opcode)
	      || HEXAGON_OPCODE_IS_PCREL_BRANCH (ainsn->right->opcode)))
      /* Selectively, multiple memory operations.  */
      || (hexagon_no_dual_memory
	  && HEXAGON_OPCODE_IS_MEMORY (ainsn->left->opcode)
	  && HEXAGON_OPCODE_IS_MEMORY (ainsn->right->opcode)))
    return FALSE;

  /* Memory operations must be paired in source order.  */
  are_stores = (HEXAGON_OPCODE_IS_STORE (ainsn->left->opcode)
		&& HEXAGON_OPCODE_IS_STORE (ainsn->right->opcode));

  /* Create a pair and its mirror.  */
  l = (strlen (ainsn->left->source) + strlen (ainsn->right->source)
       + sizeof (PACKET_PAIR) + 1);
  ltor = alloca (l);
  rtol = alloca (l);

  snprintf (ltor, l, "%s%c%s",
	    ainsn->left->source, PACKET_PAIR, ainsn->right->source);
  snprintf (rtol, l, "%s%c%s",
	    ainsn->right->source, PACKET_PAIR, ainsn->left->source);

  hexagon_insn_init (&insn);
  if (hexagon_assemble (&insn, ltor, TRUE)
      || (!are_stores && hexagon_assemble (&insn, rtol, TRUE)))
    {
      /* Abandon if the result is an unwanted duplex.  */
      if (!hexagon_pairing_duplex && HEXAGON_OPCODE_IS_DUPLEX (insn.opcode))
	return FALSE;

      insn.used = FALSE;
      insn.pad = FALSE;
      insn.lineno = MAX (ainsn->left->lineno, ainsn->right->lineno);
      insn.flags |= HEXAGON_INSN_IS_PAIR;

      if (!strcmp (insn.source, ltor))
	{
	  insn.left = ainsn->left;
	  insn.right = ainsn->right;
	}
      else
	{
	  insn.left = ainsn->right;
	  insn.right = ainsn->left;
	}

      *ainsn = insn;
      return TRUE;
    }

  return FALSE;
}

/* Return true if APACKET0 is "better" than APACKET1.  */
static int
hexagon_packet_is_better (hexagon_packet *apacket0, hexagon_packet *apacket1)
{
  /* If either packet is invalid, choose the other.  */
  if (apacket0->size == 0)
    return FALSE;
  else if (apacket1->size == 0)
    return TRUE;

  /* Choose the shorter packet.  */
  else if (apacket0->size < apacket1->size)
    return TRUE;
  else if (apacket0->size > apacket1->size)
    return FALSE;

  /* Given two packets of the same size, prefer one with a duplex or
     reserved relax slot.  */
  else if (apacket0->duplex)
    return TRUE;
  else if (apacket0->relax)
    return TRUE;
  else
    return FALSE;
}

/* Attempt to form a packet by searching for a pairing starting with
   instruction J in AQUEUE.  If multiple choices of pairings exist,
   choose the best one.
   Note that paired instructions in the resulting packet contain
   left and right pointers that point into the unmodified ORIGQUEUE.
   Keeping track of malloc'ed storage is messy while we are trying and
   discarding pairings, so it's the caller's responsibility to track these
   pointers.  */
static int
hexagon_packet_form_recursive (hexagon_packet *apacket,
			       hexagon_queue *aqueue,
			       hexagon_queue *origqueue,
			       size_t j)
{
  size_t i;
  hexagon_queue queue;
  int ok;

  /* If we've run out of pairings to attempt, just form a packet from
     the instructions in the queue.  */
  if (!hexagon_pairing || j + 1 >= aqueue->size)
    {
      queue = *aqueue;
      hexagon_packet_init (apacket);
      apacket->is_inner = queue.is_inner;
      apacket->is_outer = queue.is_outer;

      for (i = 0; i < queue.size; i++)
	{
	  if (queue.insns[i].pad)
	    /* Skip an insn already inserted into the packet.  */
	    continue;

	  if (!hexagon_packet_cram (apacket, queue.insns + i, FALSE))
	    {
	      hexagon_packet_init (apacket);
	      break;
	    }
	}

      return (!aqueue->size || apacket->size
	      || apacket->is_inner || apacket->is_outer);
    }

  /* If the current insn is already used in a pairing, skip it.  */
  if (aqueue->insns[j].used)
    return hexagon_packet_form_recursive (apacket, aqueue, origqueue, j + 1);

  /* Otherwise, try pairing with each of the remaining insns in turn,
     choosing the best resulting packet.  Start by trying to form a
     packet without pairing insn j at all.  */
  queue = *aqueue;
  ok = hexagon_packet_form_recursive (apacket, &queue, origqueue, j + 1);

  for (i = j + 1; i < queue.size; i++)
    {
      hexagon_packet_insn insn;
      hexagon_packet packet;
      size_t m, n;

      /* Skip an already-used insn.  */
      if (aqueue->insns[i].used)
	continue;

      queue = *aqueue;
      hexagon_insn_init (&insn);
      insn.left = &origqueue->insns[j];
      insn.right = &origqueue->insns[i];
      if (hexagon_assemble_pair (&insn))
	{
	  /* Keep source order of certain insns.  */
	  if (HEXAGON_OPCODE_IS_PCREL_BRANCH (queue.insns[i].opcode)
	      || HEXAGON_OPCODE_IS_STORE (queue.insns[i].opcode))
	    m = i, n = j;
	  else
	    m = j, n = i;
	  
	  queue.insns[m].used = queue.insns[n].used = TRUE;
	  queue.insns[m].pad = queue.insns[n].pad = TRUE;
	  
	  if (!hexagon_has_duplex_clash (&queue, &insn))
	    {
	      /* Try pair if no clashes.  */
	      insn.used = TRUE;
	      insn.pad = FALSE;
	      queue.insns[m] = insn;

	      /* If we can successfully form a packet with this pairing,
		 see if it is better than anything we've seen so far.  */
	      if (hexagon_packet_form_recursive (&packet, &queue, origqueue,
						 j + 1)
		  && hexagon_packet_is_better (&packet, apacket))
		{
		  *apacket = packet;
		  ok = TRUE;
		}
	    }
	}
    }
  return ok;
}

/* Form a packet into APACKET from the insns in AQUEUE, clearing AQUEUE when
   we are done.  Returns true on success.  */
static int
hexagon_packet_form (hexagon_packet *apacket, hexagon_queue *aqueue)
{
  hexagon_queue origqueue = *aqueue;
  int ok = hexagon_packet_form_recursive (apacket, aqueue, &origqueue, 0);
  size_t i;

  if (!ok)
    as_bad_where (NULL, aqueue->lineno,
		  _("too many instructions in packet (maximum is %d)."),
		  MAX_PACKET_INSNS);

  /* The formed packet contains left and right pointers that point into
     the origqueue object.  We need to copy these objects to malloc'ed
     storage so that they can escape from this function.  */
  for (i = 0; i < apacket->size; i++)
    if (apacket->insns[i].flags & HEXAGON_INSN_IS_PAIR)
      {
	hexagon_packet_insn *left = xmalloc (sizeof (hexagon_packet_insn));
	hexagon_packet_insn *right = xmalloc (sizeof (hexagon_packet_insn));
	*left = *apacket->insns[i].left;
	*right = *apacket->insns[i].right;
	apacket->insns[i].left = left;
	apacket->insns[i].right = right;
      }

  n_pairs[HEXAGON_PAIRS_TOTAL] += apacket->duplex;
  hexagon_queue_init (aqueue);
  return ok;
}


/* Packet validity checking.  */

/* Return true if a predicate register with the .new suffix is updated in the
   packet scoreboard SCORE.  */
static int
hexagon_check_new_predicate (hexagon_packet_score *score)
{
  size_t i;

  for (i = 0; i < HEXAGON_NUM_PREDICATE_REGS; i++)
    if (score->pred_new_regs[i].used &&
	(!score->pred_regs[i].used || score->pred_late_regs[i].used))
      {
	if (score->control_regs[HEXAGON_P30].used)
	  as_warn (_("modifying `C4/P3:0' does not apply to `p%lu.new'."),
		   (unsigned long) i);

	if (score->pred_regs[i].used && score->pred_late_regs[i].used)
	  as_bad (_("cannot use register `p%lu' with `.new' in the packet."),
		  (unsigned long) i);
	else
	  as_bad (_("register `p%lu' used with `.new' but not modified "
		    "in the same packet."),
		  (unsigned long) i);

	return FALSE;
      }

  return TRUE;
}

/* Update scoreboard SCORE to reflect uses of predicate register REG_NUM
   by OPCODE.  Note that on Hexagon versions that support predicate autoand,
   multiple writes are only an error if one of them is a "late" predicate
   use.  */
static void
hexagon_check_predicate (int reg_num, const hexagon_opcode *opcode,
			 hexagon_packet_score *score)
{
  if (HEXAGON_OPCODE_IS_LATEPRED (opcode))
    score->pred_late_regs[reg_num].used++;
  if (score->pred_regs[reg_num].used
      && (!hexagon_autoand || score->pred_late_regs[reg_num].used))
    as_bad (_("register `p%d' modified more than once."), reg_num);
  else
    score->pred_regs[reg_num].used++;
}

/* Update scoreboard SCORE to reflect implicit uses of predicate register
   REG in OPCODE.  */
static void
hexagon_check_implicit_predicate (const hexagon_opcode *opcode,
				  unsigned int implicit, int reg,
				  hexagon_packet_score *score)
{
  if (opcode->implicit & implicit)
    hexagon_check_predicate (reg, opcode, score);
}

/* Update ARRAY to reflect implicit uses of REG by OPCODE.  If the register
   is already marked used, give an error.  */
static void
hexagon_check_implicit (const hexagon_opcode *opcode,
			unsigned int implicit, int reg,
			hexagon_reg_score *array, const char *name)
{
  if (opcode->implicit & implicit)
    {
      if (array[reg].used)
	as_bad (_("register `%s' modified more than once."), name);
      else
	array[reg].used++;
    }
}

/* Perform multiple-write checks on a use in INSN of REG_NUM using state
   in ARRAY.   For an explicit register operand, OPERAND is non-null and
   NAME is null (the name is looked up in the operand instead).  For
   implicit register  operands, NAME is the name and OPERAND is null.
   PRED_MASK encodes any predicate condition on this use, and PINDEX
   is the index of INSN in the packet.  */
static void
hexagon_check_register (hexagon_reg_score *array, int reg_num,
			const char *name, hexagon_pred_mask pred_mask,
			const hexagon_operand *operand,
			hexagon_packet_insn *insn, int pindex)
{
  int error = FALSE;
  int prev_i;

  /* Have we already seen a write to this register?  */
  for (prev_i = 0; prev_i < array[reg_num].used; ++prev_i)
    {
      hexagon_pred_mask prev_pred_mask = array[reg_num].pred[prev_i];

      /* Either this write is unconditional, or a previous one was.  */
      if (!pred_mask || !prev_pred_mask)
	{
	  if ((operand
	       && (array[reg_num].letter != operand->enc_letter
		   || !(operand->flags & HEXAGON_OPERAND_IS_READ)
		   || !(operand->flags & HEXAGON_OPERAND_IS_WRITE)))
	      || array[reg_num].index != pindex)
	    error = TRUE;
	}
      /* Check for two writes using the same condition on the same
	 predicate register.  */
      else
	{
	  size_t i;
	  hexagon_pred_mask a_pred_mask, prev_a_pred_mask;

	  for (i = 0; i < HEXAGON_NUM_PREDICATE_REGS; i++)
	    {
	      a_pred_mask = HEXAGON_PRED_GET (pred_mask, i);
	      prev_a_pred_mask = HEXAGON_PRED_GET (prev_pred_mask, i);
	      if (a_pred_mask && a_pred_mask == prev_a_pred_mask)
		{
		  error = TRUE;
		  break;
		}
	    }
	}

      if (error)
	{
	  char *errmsg = NULL;
	  char *buff;
	  char *reg_name;
	  if (operand)
	    {
	      buff = alloca (HEXAGON_MAPPED_LEN);
	      reg_name = hexagon_dis_operand (operand, insn->insn, 0, 0,
					      insn->opcode->enc, buff, &errmsg);
	    }
	  else
	    reg_name = buff = (char *) name;

	  if (reg_name)
	    as_bad (_("register `%s' modified more than once."), buff);
	  else if (errmsg)
	    as_bad ("%s\n", errmsg);
	  return;
	}
    }

  array[reg_num].used++;
  array[reg_num].letter = operand ? operand->enc_letter : 0;
  array[reg_num].pred[array[reg_num].used - 1] = pred_mask;
  array[reg_num].index = pindex;
}


/* Check for conflicts in register uses in BINSN, which might be part of a
   pair in AINSN, with index PINDEX in the packet.  SCORE holds the packet
   statistics state.  */
static void
hexagon_insn_check (hexagon_packet_insn *ainsn, hexagon_packet_insn *binsn,
		    int pindex, hexagon_packet_score *score)
{
  const char *cp;
  hexagon_pred_mask pred_mask = 0;
  hexagon_reg_score *array;
  char *errmsg = NULL;
  int reg_num;

  for (cp = binsn->opcode->syntax; *cp; cp++)
    /* Walk the syntax string for the opcode.  */
    if (ISUPPER (*cp))
      {
	/* Check for register operand.  */
	const hexagon_operand *operand = hexagon_lookup_operand (cp);
	if (!operand)
	  break;
	
	cp += strlen (operand->fmt);	/* Move cp to end of operand.  */
	
	if (operand->flags & HEXAGON_OPERAND_IS_READ
	    && operand->flags & HEXAGON_OPERAND_IS_PREDICATE)
	  {
	    if (!hexagon_extract_operand (operand, binsn->insn, 0,
					  binsn->opcode->enc,
					  &reg_num, &errmsg))
	      {
		if (errmsg)
		  as_bad ("%s\n", errmsg);
		break;
	      }

	    pred_mask = HEXAGON_PRED_INIT (reg_num, binsn->opcode);	    
	    if (HEXAGON_OPCODE_IS_CONDITION_DOTNEW (binsn->opcode))
	      score->pred_new_regs[reg_num].used++;
	  }
	
	if (operand->flags
	    & (HEXAGON_OPERAND_IS_WRITE | HEXAGON_OPERAND_IS_MODIFIED))
	  {
	    if (operand->flags & HEXAGON_OPERAND_IS_PREDICATE)
	      {
		if (!hexagon_extract_operand (operand, binsn->insn, 0,
					      binsn->opcode->enc,
					      &reg_num, &errmsg))
		  {
		    if (errmsg)
		      as_bad ("%s\n", errmsg);
		    break;
		  }

		/* P30 holds all 4 predicate registers; check for overlap.  */
		if (score->control_regs[HEXAGON_P30].used)
		  {
		    as_bad (_("register `P%d' modified more than once."),
			    reg_num);
		    break;
		  }
		
		hexagon_check_predicate (reg_num, ainsn->opcode, score);
		if (operand->flags & HEXAGON_OPERAND_IS_PAIR)
		  hexagon_check_predicate (reg_num + 1, ainsn->opcode, score);
		
		continue;
	      }
	    else if (operand->flags & HEXAGON_OPERAND_IS_MODIFIER)
	      {
		array = score->control_regs;
		
		if (!hexagon_extract_operand (operand, binsn->insn, 0,
					      binsn->opcode->enc,
					      &reg_num, &errmsg))
		  {
		    if (errmsg)
		      as_bad ("%s\n", errmsg);
		    break;
		  }
	      }
	    else
	      {
		if (!hexagon_extract_operand (operand, binsn->insn, 0,
					      binsn->opcode->enc,
					      &reg_num, &errmsg))
		  {
		    if (errmsg)
		      as_bad ("%s\n", errmsg);
		    break;
		  }
		
		if (operand->flags & HEXAGON_OPERAND_IS_CONTROL)
		  {
		    /* P30 is the 32-bit register that holds the value
		       of all 4 predicate regs together, so detect whether
		       we've already got a write to any of them.  */
		    if (reg_num == HEXAGON_P30)
		      {
			size_t j;
			
			for (j = 0; j < HEXAGON_NUM_PREDICATE_REGS; j++)
			  if (score->pred_regs[j].used)
			    {
			      score->control_regs[reg_num].used++;
			      break;
			    }
		      }
		    array = score->control_regs;
		  }
		else if (operand->flags & HEXAGON_OPERAND_IS_SYSTEM)
		  {
		    array = score->system_regs;
		    /* Record which register is changed.  */
		    ainsn->oreg = reg_num;
		    ainsn->opair = operand->flags & HEXAGON_OPERAND_IS_PAIR;
		  }
		else if (operand->flags & HEXAGON_OPERAND_IS_GUEST)
		  array = score->guest_regs;
		else
		  {
		    array = score->gp_regs;
		    
		    if (!(ainsn->flags & HEXAGON_INSN_OUT_RNEW)
			&& !(operand->flags & HEXAGON_OPERAND_IS_MODIFIED))
		      {
			/* Record which register is changed.  */
			ainsn->flags |= HEXAGON_INSN_OUT_RNEW;
			ainsn->oreg = reg_num;
			ainsn->opair = operand->flags & HEXAGON_OPERAND_IS_PAIR;
		      }
		  }
	      }
	    
	    hexagon_check_register (array, reg_num, NULL,
				    pred_mask, operand, binsn, pindex);
	    if (operand->flags & HEXAGON_OPERAND_IS_PAIR)
	      hexagon_check_register (array, reg_num + 1, NULL,
				      pred_mask, operand, binsn, pindex);
	  }

	if (!*cp)
	  break;
      }
  
  /* Check for implicit operand conflicts.  */
  if (binsn->opcode->implicit)
    {
      if (binsn->opcode->implicit & IMPLICIT_PC)
	{
	  /* Look into multiple implicit references to the PC in order
	     to allow slots with two branches.  */
	  score->control_regs[HEXAGON_PC].used++;
	  if (score->control_regs[HEXAGON_PC].used > 1
	      && score->control_regs[HEXAGON_PC].used > score->dualjump)
	    hexagon_check_implicit (binsn->opcode, IMPLICIT_PC, HEXAGON_PC,
				    score->control_regs, "c9/pc");
	}
      
      hexagon_check_implicit (binsn->opcode, IMPLICIT_LC0, HEXAGON_LC0,
			      score->control_regs, "c1/lc0");
      hexagon_check_implicit (binsn->opcode, IMPLICIT_SA0, HEXAGON_SA0,
			      score->control_regs, "c0/sa0");
      hexagon_check_implicit (binsn->opcode, IMPLICIT_LC1, HEXAGON_LC1,
			      score->control_regs, "c3/lc1");
      hexagon_check_implicit (binsn->opcode, IMPLICIT_SA1, HEXAGON_SA1,
			      score->control_regs, "c2/sa1");
      
      hexagon_check_implicit_predicate (binsn->opcode, IMPLICIT_P3, 3, score);
      /* V3 */
      hexagon_check_implicit_predicate (binsn->opcode, IMPLICIT_P0, 0, score);
      /* V4 */
      hexagon_check_implicit_predicate (binsn->opcode, IMPLICIT_P1, 1, score);
      
      if (binsn->opcode->implicit & IMPLICIT_SP)
	hexagon_check_register (score->gp_regs, HEXAGON_SP, "r29/sp",
				pred_mask, NULL, binsn, pindex);
      if (binsn->opcode->implicit & IMPLICIT_FP)
	hexagon_check_register (score->gp_regs, HEXAGON_FP, "r30/fp",
				pred_mask, NULL, binsn, pindex);
      if (binsn->opcode->implicit & IMPLICIT_LR)
	hexagon_check_register (score->gp_regs, HEXAGON_LR, "r31/lr",
				pred_mask, NULL, binsn, pindex);
    }
}

/* Main entry point for checking packet restrictions on APACKET.  */
static void
hexagon_packet_check (hexagon_packet *apacket)
{
  size_t i;
  hexagon_packet_insn *ainsn;
  hexagon_packet_score score;
  int n;

  /* Initialize score-boards.  */
  memset (&score, 0, sizeof (score));

  for (i = 0; i < apacket->size; i++)
    {
      ainsn = apacket->insns + i;

      /* Check whether the instruction is legal inside the packet,
         but allow single instruction in packet.  */
      if (HEXAGON_OPCODE_IS_SOLO (ainsn->opcode)
	  && hexagon_packet_insns (apacket) > 1)
	{
	  as_bad (_("instruction cannot appear in packet with other instructions."));
	  hexagon_in_packet = FALSE;
	  continue;
	}

      /* Only one jump or loop insn is permitted per packet except
	 for insns that are marked with a dual jump property that
	 says which slot they can go in.  Hardware loop setup instructions do
	 not count as jumps on Hexagon V4 and above (FIXME: Undocumented
	 behaviour).  */
      if (HEXAGON_OPCODE_IS_BRANCH (ainsn->opcode)
	  || (!hexagon_if_arch_v4 () && !hexagon_if_arch_v5 ()
	      && !hexagon_if_arch_v55 ()
	      && HEXAGON_OPCODE_IS_HWLOOP (ainsn->opcode)))
	{
	  score.jump++;
	  if (HEXAGON_OPCODE_IS_DUALJUMP_1 (ainsn->opcode)
	      || HEXAGON_OPCODE_IS_DUALJUMP_2 (ainsn->opcode))
	    score.dualjump++;
	  if (score.dualjump1 && HEXAGON_OPCODE_IS_DUALJUMP_2 (ainsn->opcode))
	    score.dualjump2++;
	  else if (HEXAGON_OPCODE_IS_DUALJUMP_1 (ainsn->opcode))
	    score.dualjump1++;
	}

      /* Record instructions that set the OVF bit in SR.  */
      if (ainsn->opcode->implicit & IMPLICIT_SR_OVF)
	score.sr_ovf = TRUE;

      if (ainsn->flags & HEXAGON_INSN_IS_PAIR)
	{
	  hexagon_insn_check (ainsn, ainsn->left, i, &score);
	  hexagon_insn_check (ainsn, ainsn->right, i, &score);
	}
      else
	hexagon_insn_check (ainsn, ainsn, i, &score);
    }
  hexagon_check_new_predicate (&score);

  /* Check for multiple writes to SR
     (implicit not allowed if explicit writes are present).  */
  if (score.sr_ovf && score.control_regs[HEXAGON_SR].used)
    as_bad_where (NULL, apacket->lineno,
		  _("`OVF' bit in `SR' register cannot be set "
		    "(implicitly or explicitly) more than once in packet."));

  if (apacket->is_inner)
    {
      /* Check whether registers updated by :endloop0 are updated in packet.  */
      if (score.control_regs[HEXAGON_P30].used
	  || score.control_regs[HEXAGON_SR].used
	  || score.control_regs[HEXAGON_SA0].used
	  || score.control_regs[HEXAGON_LC0].used
	  || score.control_regs[HEXAGON_PC].used)
	as_bad_where (NULL, apacket->lineno,
		      _("packet marked with `:endloop0' cannot contain "
			"instructions that modify registers "
			"`C4/P3:0', `C8/USR', `SA0', `LC0' or `PC'."));

      /* Although it may be dangerous to modify P3 then, legacy code is full of this.  */
#if 0
      if (score.pred_regs[3])
	as_warn (_("packet marked with `:endloop0' containing instructions "
		   "that modify register `p3' may have undefined results if "
		   "ending a pipelined loop."));
#endif

      /* Check for a solo instruction in a packet with :endloop0.  */
      if (hexagon_packet_has_solo (apacket))
	as_bad_where (NULL, apacket->lineno,
		      _("packet marked with `:endloop0' cannot contain a "
			"solo instruction."));
    }

  if (apacket->is_outer)
    {
      /* Check whether registers updated by :endloop1 are updated in packet.  */
      if (score.control_regs[HEXAGON_SA1].used
	  || score.control_regs[HEXAGON_LC1].used
	  || score.control_regs[HEXAGON_PC].used)
	as_bad_where (NULL, apacket->lineno,
		      _("packet marked with `:endloop1' cannot contain "
			"instructions that modify registers "
			"`SA1', `LC1' or `PC'."));

      /* Check for a solo instruction in a packet with :endloop1.  */
      if (hexagon_packet_has_solo (apacket))
	as_bad_where (NULL, apacket->lineno,
		      _("packet marked with `:endloop1' cannot contain a "
			"solo instruction."));
    }

  if (score.jump > 1
      && !(score.jump == 2 && score.dualjump == 2
	   && score.dualjump1 == 1 && score.dualjump2 == 1))
    {
      if (score.jump > 2 || hexagon_if_arch_v2 ())
	/* V2 only allows one jump per packet, other arch versions 2.  */
	as_bad_where (NULL, apacket->lineno,
		      _("too many branches in packet."));
      else
	/* Number of jumps is OK, but their type or ordering does not
	   meet the constraints for dual jumps.  */
	as_bad_where (NULL, apacket->lineno,
		      _("invalid dual-jump combination in packet."));
    }

  if (!hexagon_packet_has_but_ax (apacket))
    as_bad_where (NULL, apacket->lineno,
		  _("instruction cannot appear in packet with other than "
		    "A-type or non-float X-type instructions."));

  n = hexagon_packet_has_mem (apacket);
  if ((hexagon_no_dual_memory && n > 1) || n > 2)
    as_bad_where (NULL, apacket->lineno,
		  _("too many memory operations in packet."));

  if (hexagon_pairs_info && hexagon_packet_has_pair (apacket))
    as_warn_where (NULL, apacket->lineno, _("instructions paired."));
}


/* Packet shuffling.  */

/* Finish up contents of PACKET after shuffling.
   This adjusts the encoding of any insn in the packet that may
   depend on its final ordering.  */
static void
hexagon_packet_finish (hexagon_packet *packet)
{
  hexagon_packet_insn *inew = hexagon_packet_has_rnew (packet);

  /* Finish R.NEW instructions.  */
  if (inew)
    {
      int new_val_cmp_jmp = FALSE;
      size_t i;

      /* Check if the reference is a new-value compare jump.  */
      new_val_cmp_jmp =
	(HEXAGON_OPCODE_IS_CONDEXEC (inew->opcode)
	 && HEXAGON_OPCODE_IS_PCREL_BRANCH (inew->opcode)
	 && HEXAGON_OPCODE_IS_RESTRICT_SLOT1_NOSTORE (inew->opcode));

      for (i = 0; i < MAX_PACKET_INSNS; i++)
	{
	  if (packet->insns[i].flags & HEXAGON_INSN_OUT_RNEW
	      && !packet->insns[i].opair
	      && packet->insns[i].oreg == inew->ireg
	      && (!packet->insns[i].pred_mask
		  || packet->insns[i].pred_mask == inew->pred_mask)
	      && !(new_val_cmp_jmp
		   && HEXAGON_OPCODE_IS_XFLOAT (packet->insns[i].opcode)))
	    {
	      ssize_t off = inew->ndx - packet->insns[i].ndx;
	      hexagon_encode_operand (inew->ioperand, &inew->insn, inew->opcode,
				      off * 2 + inew->ireg % 2, FALSE, NULL);
	      return;
	    }
	}
      as_bad_where (NULL, inew->lineno,
		    _("register `r%u' used with `.new' "
		      "but not validly modified in the same packet."),
		    inew->ireg);
    }
}

/* Shuffle PACKET according to FROMTO mapping.  */
static void
hexagon_shuffle_packet (hexagon_packet *packet, size_t *fromto)
{
  hexagon_packet_insn insns[MAX_PACKET_INSNS];
  size_t from, ndx;
  size_t i;

  for (i = 0, ndx = 0; i < MAX_PACKET_INSNS; i++)
    {
      from = fromto[i];
      if (from >= MAX_PACKET_INSNS)
	from = i;

      /* Shuffle insns, prefixes, fix-ups...  */
      insns[i] = packet->insns[from];

      /* Fix up fix ups.  */
      hexagon_adjust_fix (insns + i, i, i - from);
      if (insns[i].prefix)
	hexagon_adjust_fix (insns[i].prefix, i, i - from);

      insns[i].ndx = ndx;
      if (!packet->insns[from].pad)
	ndx++;
    }

  memcpy (packet->insns, insns, sizeof (packet->insns));
}

/* Shuffle PACKET according to architectural restrictions, starting with
   SLOT_NUM.  MEM, STORE, NOSTORE, and AONLY are the number of memory ops,
   stores, store restrictions, and a restrictions (respectively) in
   the packet.  Returns true if packet was shuffled successfully.  */
static int
hexagon_shuffle_helper (hexagon_packet *packet, size_t slot_num,
			size_t *fromto, int mem, int store, int nostore,
			int aonly)
{
  size_t ndx, slots, temp_mask, store_mask;
  size_t i;
  int ok = FALSE;

  if (slot_num >= packet->size)
    return TRUE;

  ndx = MAX_PACKET_INSNS - slot_num - 1;
  slots = 1 << ndx;

  store_mask = HEXAGON_SLOTS_STORES;
  for (i = 0; i < packet->size && !ok; i++)
    {
      temp_mask = packet->insns[i].opcode->slots;

      /* If there is only one memory insn, it requires ndx #0.  */
      if (mem == 1 && HEXAGON_OPCODE_IS_MEMORY (packet->insns[i].opcode))
	temp_mask &= HEXAGON_SLOTS_MEM1;

      /* If there is a store restriction, make sure that none makes into
	 slot #1.  */
      if (nostore
	  && !HEXAGON_OPCODE_IS_RESTRICT_SLOT1_NOSTORE (packet->insns[i].opcode)
	  && HEXAGON_OPCODE_IS_STORE (packet->insns[i].opcode))
	temp_mask &= ~HEXAGON_SLOTS_STORES;

      /* If there is an A-type restriction, make sure that non-A instructions
	 are not placed into slot #1.  */
      if (aonly && !HEXAGON_INSN_TYPE_A (packet->insns[i].insn))
	temp_mask &= ~HEXAGON_SLOTS_1;

      /* Make sure that several stores follow source order.  */
      if (HEXAGON_OPCODE_IS_STORE (packet->insns[i].opcode))
	{
	  if (store > 1)
	    {
	      temp_mask &= store_mask;
	      store_mask >>= 1;
	    }
	  else
	    temp_mask &= HEXAGON_SLOTS_MEM1;
	}

      if (!packet->insns[i].used && temp_mask & slots)
	{
	  /* Check for SLOT1_EMPTY restriction.  */
	  if (ndx == 1
	      && !HEXAGON_OPCODE_IS_NOP (packet->insns[i].opcode)
	      && hexagon_packet_has_slot1_empty (packet, i))
	    /* If so, then skip this ndx.  */
	    continue;

	  /* Allocate this slot.  */
	  fromto[slot_num] = i;
	  packet->insns[i].used = TRUE;

	  /* Try to shuffle remaining slots.  */
	  ok = hexagon_shuffle_helper (packet, slot_num + 1, fromto,
				       mem, store, nostore, aonly);
	  if (!ok)
	    /* Deallocate ndx if unsuccessful.  */
	    packet->insns[i].used = FALSE;
	}
    }
  return ok;
}

/* Prepare APACKET for shuffling.  */
static void
hexagon_shuffle_prepare (hexagon_packet *apacket)
{
  size_t fromto[MAX_PACKET_INSNS];
  unsigned i, j, k;
  int found;

  /* Initialize shuffle map.  */
  for (i = 0; i < MAX_PACKET_INSNS; i++)
    fromto[i] = MAX_PACKET_INSNS;

  /* Pad packet with NOPs.  */
  for (i = apacket->size, j = hexagon_packet_length (apacket);
       i < MAX_PACKET_INSNS; i++)
    {
      int pad;

      /* Insert NOPs needed to satisfy :endloop requirements.  */
      pad = (i < j
	     || !((apacket->is_inner && i < 2)
		  || (apacket->is_outer && i < 3)));
      hexagon_packet_insert (apacket, &hexagon_nop_insn, pad);
    }

  /* Reorder the instructions in the packet so that they start with
     slot #3 (index #0) instead of slot #0.

     1 - Go through all non-padded instructions, find the highest slot each
     insn can go to and put it in the corresponding position.  If an
     position is already assigned, then try the next one.  If all
     positions after the wanted one are taken, then try again from the
     beginning of the array.

     2 - For all padded instructions, put them one by one starting from the
     first available position (or higher slot).  */

  /* Step 1.  */
  for (i = 0; i < MAX_PACKET_INSNS; i++)
    if (!apacket->insns[i].pad)
      {
	/* Find the highest ndx that this instruction can go to.  */
	for (j = 0, found = FALSE; j < MAX_PACKET_INSNS && !found; j++)
	  if (apacket->insns[i].opcode->slots
	      & (1 << (MAX_PACKET_INSNS - j - 1)))
	    /* Try to allocate the ndx found or a lower one.  */
	    for (k = j; k < MAX_PACKET_INSNS && !found; k++)
	      if (fromto[k] >= MAX_PACKET_INSNS)
		{
		  /* Slot is free.  */
		  fromto[k] = i;
		  found = TRUE;
		}

	/* If all the positions after the wanted one are taken,
	   go back to the beginning of the array.  */
	for (j = 0; j < MAX_PACKET_INSNS && !found; j++)
	  if (fromto[j] >= MAX_PACKET_INSNS)
	    {
	      fromto[j] = i;
	      found = TRUE;
	    }
      }

  /* Step 2.  */
  for (i = 0; i < MAX_PACKET_INSNS; i++)
    if (apacket->insns[i].pad)
      /* Find the first unused position for this pad insn.  */
      for (j = 0; j < MAX_PACKET_INSNS; j++)
	if (fromto[j] >= MAX_PACKET_INSNS)
	  {
	    fromto[j] = i;
	    break;
	  }

  hexagon_shuffle_packet (apacket, fromto);
}

/* Main function for shuffling packet APACKET.  Returns true if a valid
   packet could be formed.  */
static int
hexagon_shuffle_do (hexagon_packet *apacket)
{
  size_t i;
  size_t fromto[MAX_PACKET_INSNS];

  hexagon_shuffle_prepare (apacket);

  /* Don't touch a packet with prefixes.  */
  if (hexagon_packet_has_prefix (apacket))
    return FALSE;

  /* Initialize the fromto map.  */
  for (i = 0; i < MAX_PACKET_INSNS; i++)
    {
      fromto[i] = MAX_PACKET_INSNS;
      apacket->insns[i].used = FALSE;
    }

  /* Apply architectural restrictions.  */
  if (hexagon_shuffle_helper (apacket, 0, fromto,
			      hexagon_packet_has_mem (apacket),
			      hexagon_packet_has_store (apacket),
			      hexagon_packet_has_store_not (apacket),
			      hexagon_packet_has_a_only (apacket)))
    {
      /* Shuffle the packet according to the from-to map.  */
      hexagon_shuffle_packet (apacket, fromto);
      /* Finish up the insns in the packet.  */
      hexagon_packet_finish (apacket);
      return TRUE;
    }
  else
    return FALSE;
}


/* High-level packet management.  */

/* Write out APACKET.  */
static void
hexagon_packet_write (hexagon_packet *apacket)
{
  hexagon_packet *zpacket;
  fragS *previous;
  char *first;
  size_t i;

  apacket->faligned = hexagon_faligning;
  hexagon_faligning = FALSE;

  hexagon_packet_fold (apacket);

  /* Make sure that packet frags have nothing else.  */
  if (obstack_object_size (&frchain_now->frch_obstack))
    {
      previous = frag_now;
      frag_wane (frag_now);
      frag_new (0);
      hexagon_frag_init (frag_now, previous);
    }

  /* Make room for maximum packet size and possible padding.  */
  previous = frag_now;
  frag_grow (MAX_FRAG_INSNS * HEXAGON_INSN_LEN);
  first = frag_more (hexagon_packet_length (apacket) * HEXAGON_INSN_LEN);
  hexagon_frag_init (frag_now, previous);

  /* Initialize scratch packet.  */
  zpacket = &frag_now->tc_frag_data->packet;
  *zpacket = *apacket;
  zpacket->size = 0;

  /* Recount to skip paddings.  */
  for (i = 0; i < apacket->size; i++)
    if (!apacket->insns[i].pad)
      {
	hexagon_packet_insn *zinsn = zpacket->insns + zpacket->size;
	*zinsn = apacket->insns[i];
	zpacket->size++;
      }

  /* Now emit the instructions.  */
  for (i = 0; i < zpacket->size; i++)
    {
      hexagon_packet_insn *zinsn = zpacket->insns + i;
      zinsn->insn = hexagon_set_parse_bits (zpacket, i);
      hexagon_insn_write (zinsn->insn, zinsn->fc, zinsn->operand, &zinsn->exp,
			  first, i * HEXAGON_INSN_LEN,
			  &zinsn->fix);
    }

  dwarf2_emit_insn (zpacket->size * HEXAGON_INSN_LEN);

  /* TODO: In order to conserve memory, if .falign is disabled, fewer frags
     could be used instead.  Then, frag_var and frag_grow above would not
     be needed, or at least no extra room for padding would be needed.  */
  previous = frag_now;
  frag_var (rs_machine_dependent,
	    (MAX_FRAG_INSNS - zpacket->size) * HEXAGON_INSN_LEN,
	    0, 0, NULL, 0, first);
  hexagon_frag_init (frag_now, previous);
  hexagon_packet_init (&frag_now->tc_frag_data->packet);

  /* Prepare packet for next insns.  */
  hexagon_packet_init (apacket);
}

/* End packet APACKET: check for various restrictions, shuffle packet insns
   into the correct order, and other end-of-packet processing.  */
static void
hexagon_packet_end (hexagon_packet *apacket)
{
  hexagon_in_packet = FALSE;

  /* Checking for multiple restrictions in packet.  */
  hexagon_packet_check (apacket);

  /* Attempt to shuffle even in the presence of errors.  */
  if (!hexagon_shuffle_do (apacket))
    as_bad (_("invalid instruction packet."));
}

/* Begin a new packet in APACKET.  */
static void
hexagon_packet_begin (hexagon_packet *apacket)
{
  if (hexagon_in_packet)
    {
      hexagon_packet_form (apacket, &hexagon_aqueue);
      hexagon_packet_end (apacket);
      hexagon_packet_write (apacket);
    }

  hexagon_in_packet = TRUE;
  hexagon_packet_init (apacket);
}


/* Relaxation support.  */

/* Relax branch by adding the extender. FRAGP is the relaxed fragment with
   room for the extension.  */
static int
hexagon_relax_branch (fragS *fragP)
{
  hexagon_packet *apacket;
  hexagon_operand *operand;
  fixS *fx, fxup;
  int fix;
  size_t i, j;

  apacket = &fragP->tc_frag_data->packet;
  if (!apacket->relax || !apacket->drlx)
    return FALSE;

  fix = fragP->fr_fix;

  /* Sanity check.  */
  /* FIXME: any remaining branch left not relaxed will overflow.
     assert (apacket->drlx + hexagon_packet_length (apacket) - apacket->relax
     <= MAX_PACKET_INSNS);
   */

  for (i = 0, fx = NULL;
       i < apacket->size && apacket->size < MAX_PACKET_INSNS; i++)
    if (apacket->insns[i].flags & HEXAGON_INSN_IS_RELAX
	&& apacket->insns[i].fc)
      {
	if (apacket->insns[i].relax == HEXAGON_RELAX_NONE
	    || apacket->insns[i].relax == HEXAGON_RELAX_DONE
	    || apacket->insns[i].relax % 2)
	  continue;

	fx = apacket->insns[i].fix;
	fxup = *fx;

	operand = fx->tc_fix_data;

	/* Adjusted extended insn.  */
	operand->flags |= HEXAGON_OPERAND_IS_KXED;
	apacket->insns[i].flags |= HEXAGON_INSN_IS_KXED;
	fx->fx_r_type = operand->reloc_kxed;

	/* Make room for extender.  */
	for (j = apacket->size; j > i; j--)
	  {
	    hexagon_insn *pi;

	    pi = ((hexagon_insn *) fragP->fr_literal) + j;
	    pi[0] = pi[-1];

	    apacket->insns[j] = apacket->insns[j - 1];
	    if (apacket->insns[j].fc && apacket->insns[j].fix)
	      {
		apacket->insns[j].fix->fx_where += HEXAGON_INSN_LEN;
		if (apacket->insns[j].fix->fx_pcrel)
		  apacket->insns[j].fix->fx_offset += HEXAGON_INSN_LEN;
	      }
	  }

	/* Create extender.  */
	apacket->insns[i] = hexagon_kext_insn;
	apacket->insns[i].operand
	  = xmalloc (sizeof (*apacket->insns[i].operand));
	*apacket->insns[i].operand
	  = *hexagon_lookup_reloc (operand->reloc_kxer, 0,
				   apacket->insns[i].opcode);
	apacket->insns[i].fc++;
	apacket->insns[i].fix
	  = fix_new (fragP, fxup.fx_where, HEXAGON_INSN_LEN, fxup.fx_addsy,
		     fxup.fx_offset, fxup.fx_pcrel, operand->reloc_kxer);
	apacket->insns[i].fix->fx_line = fxup.fx_line;
	apacket->insns[i].fix->tc_fix_data = apacket->insns[i].operand;

	/* Add extender.  */
	md_number_to_chars (fragP->fr_literal + i * HEXAGON_INSN_LEN,
			    apacket->insns[i].insn, HEXAGON_INSN_LEN);

	/* Sanity check.  */
	assert (apacket->size < MAX_PACKET_INSNS);
	apacket->size++;
	apacket->prefix++;
	apacket->relax--;
	apacket->drlx--;

	fragP->fr_fix += HEXAGON_INSN_LEN;

	/* Skip extended branch.  */
	i++;
	apacket->insns[i].relax = HEXAGON_RELAX_DONE;
      }

  /* Re-emit packet.  */
  for (i = 0; i < apacket->size; i++)
    {
      apacket->insns[i].insn = hexagon_set_parse_bits (apacket, i);
      md_number_to_chars (fragP->fr_literal + i * HEXAGON_INSN_LEN,
			  apacket->insns[i].insn, HEXAGON_INSN_LEN);
    }

  apacket->relax = apacket->drlx = apacket->ddrlx = 0;

  return fragP->fr_fix - fix;
}

/* Relax branch by extending it and adjusting it to accomodate the extension.
   FRAGP is the relaxable fragment with room for the extension.
   Returns the size delta.  */
static long
hexagon_relax_branch_try (fragS *fragP, segT segment, long stretch)
{
  const relax_typeS *before, *now;
  relax_substateT this = HEXAGON_RELAX_NONE, next = HEXAGON_RELAX_NONE;
  hexagon_packet *apacket;
  symbolS *sym;
  addressT from, to;
  offsetT aim;
  long delta, growth;
  size_t i;

  apacket = &fragP->tc_frag_data->packet;

  if (!apacket->relax)
    return FALSE;

  for (i = 0, delta = 0;
       i < apacket->size && apacket->size + apacket->drlx < MAX_PACKET_INSNS;
       i++)
    if (apacket->insns[i].flags & HEXAGON_INSN_IS_RELAX
	&& apacket->insns[i].fc)
      {
	if (apacket->insns[i].relax == HEXAGON_RELAX_DONE)
	  continue;

	sym = apacket->insns[i].fix->fx_addsy;
	if (sym)
	  {
	    to = S_GET_VALUE (sym);

	    if (stretch
		&& symbol_get_frag (sym)->relax_marker != fragP->relax_marker
		&& S_GET_SEGMENT (sym) == segment)
	      to += stretch;
	  }
	else
	  to = 0;

	if (apacket->insns[i].fc)
	  to += apacket->insns[i].fix->fx_offset;

	before = now = hexagon_relax_table + apacket->insns[i].relax;

	from = fragP->fr_address;
	aim = to - from;
	for (next = now->rlx_more;
	     next != HEXAGON_RELAX_NONE && next != HEXAGON_RELAX_DONE;)
	  if ((aim < 0 && aim >= now->rlx_backward)
	      || (aim >= 0 && aim <= now->rlx_forward))
	    next = HEXAGON_RELAX_NONE;
	  else
	    {
	      /* Grow to next state.  */
	      this = next;
	      now = hexagon_relax_table + this;
	      next = now->rlx_more;
	    }

	growth = now->rlx_length - before->rlx_length;
	if (growth)
	  {
	    apacket->insns[i].relax = this;

	    apacket->drlx += now->rlx_length / HEXAGON_INSN_LEN;

	    /* Replace any padding for the extension.  */
	    if (apacket->dpad)
	      {
		apacket->dpad -= now->rlx_length / HEXAGON_INSN_LEN;
		growth -= now->rlx_length;
	      }
	    else if (apacket->ddpad)
	      apacket->ddpad -= now->rlx_length / HEXAGON_INSN_LEN;
	  }
	delta += growth;
      }

  return delta;
}

/* Process the resulting padding delta for FRAGP.  */
static int
hexagon_relax_falign (fragS *fragP)
{
  hexagon_packet *apacket, *fpacket, packet;
  fragS *previous;
  size_t after, pad, pkt, duplex;
  size_t i;

  apacket = &fragP->tc_frag_data->packet;
  if (!apacket->dpad && !apacket->dpkt)
    return FALSE;

  /* Sanity checks.  */
  assert (apacket->dpad + hexagon_packet_length (apacket) <= MAX_PACKET_INSNS);
  assert (apacket->dpkt <= MAX_PACKET_INSNS);

  packet = *apacket;
  packet.relax = FALSE;		/* At this point, it won't be extended.  */
  pad = apacket->dpad;
  pkt = apacket->dpkt;

  /* Try to pad the packet.  */
  if (packet.dpad || packet.dpkt)
    {
      hexagon_packet_unfold (&packet);

      /* Pad the packet.  */
      while (packet.dpad)
	{
	  if (!hexagon_packet_insert (&packet, &hexagon_nop_insn, FALSE))
	    packet.dpkt++;
	  packet.dpad--;
	}

      /* Try to break a duplex.  */
      duplex = 0;
      if (packet.dpkt
	  && hexagon_packet_has_duplex (&packet, &duplex)
	  && packet.size < MAX_PACKET_INSNS
	  && !packet.insns[duplex].fc
	  && !(packet.insns[duplex].flags & HEXAGON_INSN_IS_KXED)
	  && packet.insns[duplex].left
	  && packet.insns[duplex].right
	  && hexagon_packet_insert (&packet, packet.insns[duplex].left, FALSE))
	{
	  packet.insns[duplex] = *packet.insns[duplex].right;
	  packet.duplex--;
	  packet.dpkt--;
	}

      /* Try to shuffle modified packet.  */
      if (hexagon_shuffle_do (&packet))
	{
	  /* Padding resulted in a well-formed packet.  */
	  hexagon_packet_fold (&packet);
	  hexagon_packet_unpad (&packet);

	  /* Re-emit packet.  */
	  for (i = 0; i < packet.size; i++)
	    {
	      packet.insns[i].insn = hexagon_set_parse_bits (&packet, i);
	      md_number_to_chars (fragP->fr_literal + i * HEXAGON_INSN_LEN,
				  packet.insns[i].insn, HEXAGON_INSN_LEN);
	    }

	  *apacket = packet;
	}
      else
	{
	  /* In order to avoid a malformed packet, convert the padding into a
	     padding packet.  */
	  packet = *apacket;
	  pkt = apacket->dpkt + apacket->dpad;
	}
    }

  after = apacket->size;

  /* Try to add a padding packet.  */
  for (; packet.dpkt; packet.dpkt--)
    {
      hexagon_insn insn = hexagon_nop_insn.insn;
      if (packet.dpkt % MAX_PACKET_INSNS == 1)
	insn = HEXAGON_END_PACKET_SET (insn, HEXAGON_END_PACKET);
      md_number_to_chars (fragP->fr_literal + after++ * HEXAGON_INSN_LEN,
			  insn, HEXAGON_INSN_LEN);
    }

  fragP->fr_fix += (pad + pkt) * HEXAGON_INSN_LEN;

  apacket->dpad = apacket->ddpad = 0;
  apacket->dpkt = apacket->ddpkt = 0;

  /* Find packet requesting .falign.  */
  for (previous = fragP, fpacket = NULL;
       previous && previous->tc_frag_data; 
       previous = previous->tc_frag_data->previous)
    {
      fpacket = &previous->tc_frag_data->packet;
      if (!fpacket || fpacket->faligned)
	break;
    }

  /* Collect .falign stats.  */
  if (fpacket)
    {
      if ((pad || pkt) && !(fpacket->stats & HEXAGON_STATS_FALIGN))
	{
	  fpacket->stats |= HEXAGON_STATS_FALIGN;
	  n_falign[HEXAGON_FALIGN_NEED]++;
	}

      if (pad && !(fpacket->stats & HEXAGON_STATS_PAD))
	{
	  fpacket->stats |= HEXAGON_STATS_PAD;
	  n_falign[HEXAGON_FALIGN_PAD]++;
	  if (hexagon_falign_warn)
	    as_warn_where (fragP->fr_file, fragP->fr_line,
			   _("inserted new `nop' instructions."));
	}

      if (pkt && !(fpacket->stats & HEXAGON_STATS_PACK))
	{
	  fpacket->stats |= HEXAGON_STATS_PACK;
	  n_falign[HEXAGON_FALIGN_PACK]++;
	  if (hexagon_falign_warn)
	    as_warn_where (fragP->fr_file, fragP->fr_line,
			   _("inserted new `nop' packet."));
	}
    }

  return TRUE;
}

/* Determine if packet corresponding to FRAGP is not fetch-aligned,
   and then request previous packets to grow through padding NOPs,
   if possible, or through inserting a NOP-packet.  */
static long
hexagon_relax_falign_try (fragS *fragP, segT segment)
{
  static segT saligning;
  static fragS *faligning;
  fragS *previous;
  hexagon_packet *apacket, *bpacket, *zpacket;
  addressT first, next;
  size_t size, delta, left, room;

  if (saligning && saligning == segment && faligning && faligning != fragP)
    return 0;
  else
    {
      saligning = NULL;
      faligning = NULL;
    }

  apacket = &fragP->tc_frag_data->packet;
  bpacket = (fragP->tc_frag_data->previous
	     ? &fragP->tc_frag_data->previous->tc_frag_data->packet
	     : NULL);

  delta = 0;

  size = (apacket->size + apacket->dpad + apacket->ddpad + apacket->drlx
	  + apacket->ddrlx);
  first = (fragP->fr_address / HEXAGON_INSN_LEN) % MAX_PACKET_INSNS;
  next = first + size;

  /* Check fetch-alignment.  */
  if (next > MAX_PACKET_INSNS && next % MAX_PACKET_INSNS)
    {
      saligning = segment;
      faligning = fragP;

      /* Check if still not fetch-aligned.  */
      for (previous = fragP->tc_frag_data->previous,
	     left = MAX_PACKET_INSNS - first;
	   previous && left;
	   previous = (previous->tc_frag_data
		       ? previous->tc_frag_data->previous
		       : NULL))
	{
	  zpacket = &previous->tc_frag_data->packet;
	  
	  if (previous->fr_type == rs_fill)	/* TODO: rs_space too? */
	    /* Skip standard frags.  */
	    continue;
	  else if (previous->fr_type != rs_machine_dependent)
	    /* Other frags must not be trespassed.  */
	    break;
	  
	  if (left && !hexagon_packet_has_solo (zpacket))
	    {
	      size = (MAX (hexagon_packet_length (zpacket)
			   + zpacket->drlx + zpacket->ddrlx,
			   hexagon_packet_slots (zpacket))
		      + zpacket->dpad + zpacket->ddpad);
	      assert (size <= MAX_PACKET_INSNS);
	      
	      if (zpacket->faligned)
		/* The room in a fetch-aligned packet must be
		   within its fetch window.  */
		next = ((previous->fr_address / HEXAGON_INSN_LEN + size)
			% MAX_PACKET_INSNS);
	      else
		next = 0;
	      
	      room = MAX_PACKET_INSNS - MAX (size, next);
	      if (left && room)
		{
		  /* Insert a padding NOP insn if there's room.  */
		  zpacket->ddpad += MIN (left, room);
		  left -= MIN (left, room);
		}
	      
	      size = (MAX ((hexagon_packet_length (zpacket)
			    + zpacket->drlx + zpacket->ddrlx),
			   hexagon_packet_slots (zpacket))
		      + zpacket->dpad + zpacket->ddpad);
	      assert (size <= MAX_PACKET_INSNS);
	    }
	  
	  if (zpacket->faligned)
	    /* Cannot go past a fetch-aligned packet.  */
	    break;
	}

      if (left)
	{
	  if (bpacket)
	    /* Force fetch-alignment by inserting a NOP-packet.  */
	    bpacket->ddpkt += ((bpacket->dpkt + left) % MAX_PACKET_INSNS
			       - bpacket->dpkt);
	  else
	    {
	      /* Without a previous packet, this packet cannot be
		 fetch-aligned.  */
	      saligning = NULL;
	      faligning = NULL;
	    }
	}
    }

  return HEXAGON_INSN_LEN * (int) delta;
}

/* Encode relax state from relocation type R.  */
static hexagon_relax_state
encode_relax (bfd_reloc_code_real_type r)
{
  if (hexagon_relax)
    {
      if (r == BFD_RELOC_HEX_B7_PCREL && hexagon_relax_long)
	return HEXAGON_RELAX_B7;
      else if (r == BFD_RELOC_HEX_B9_PCREL)
	return HEXAGON_RELAX_B9;
      else if (r == BFD_RELOC_HEX_B13_PCREL && hexagon_relax_long)
	return HEXAGON_RELAX_B13;
      else if (r == BFD_RELOC_HEX_B15_PCREL && hexagon_relax_long)
	return HEXAGON_RELAX_B15;
      else
	return HEXAGON_RELAX_NONE;
    }
  return HEXAGON_RELAX_NONE;
}

/* Implement md_estimate_size_before_relax.  */
int
hexagon_estimate_size_before_relax (fragS *fragP, segT segment)
{
  hexagon_packet *apacket;
  int delta;

  /* Avoid the empty fragments that result from frag_more ().  */
  if (!fragP->fr_fix)
    {
      frag_wane (fragP);
      return FALSE;
    }

  apacket = &fragP->tc_frag_data->packet;
  apacket->dpad += apacket->ddpad;
  apacket->dpkt += apacket->ddpkt;
  delta = HEXAGON_INSN_LEN * (apacket->drlx + apacket->dpad + apacket->dpkt);
  apacket->ddpad = apacket->ddpkt = 0;

  if (apacket->relax)
    {
      symbolS *sym;
      size_t i;
      hexagon_packet_insn *ainsn;

      for (i = 0, sym = NULL, ainsn = apacket->insns;
	   (i < apacket->size
	    && apacket->size + apacket->drlx < MAX_PACKET_INSNS);
	   i++, ainsn++)
	if (ainsn->flags & HEXAGON_INSN_IS_RELAX
	    && ainsn->fc
	    && ainsn->relax == HEXAGON_RELAX_NONE)
	  {
	    ainsn->relax = encode_relax (ainsn->operand->reloc_type);
	    if (ainsn->relax == HEXAGON_RELAX_NONE)
	      continue;

	    sym = ainsn->fix->fx_addsy;
	    if (S_GET_SEGMENT (sym) != segment
		|| (OUTPUT_FLAVOR == bfd_target_elf_flavour
		    && ((S_IS_EXTERNAL (sym) && !S_IS_DEFINED (sym))
			|| S_IS_WEAK (sym))))
	      {
		/* Symbol is external, in another segment, or weak, then
		   an extender should be added.  */
		apacket->drlx++;
		ainsn->relax = hexagon_relax_table[ainsn->relax].rlx_more;
		delta += hexagon_relax_table[ainsn->relax].rlx_length;
	      }
	  }
    }

  return delta;
}

/* Implement md_relax_frag.  */
long
hexagon_relax_frag (segT segment, fragS *fragP, long stretch)
{
  hexagon_packet *apacket = &fragP->tc_frag_data->packet;
  long delta = HEXAGON_INSN_LEN * (apacket->ddpad + apacket->ddpkt);

  apacket->dpad += apacket->ddpad;
  apacket->dpkt += apacket->ddpkt;
  apacket->ddpad = apacket->ddpkt = 0;
  if (apacket->relax)
    delta += hexagon_relax_branch_try (fragP, segment, stretch);
  if (apacket->faligned)
    delta += hexagon_relax_falign_try (fragP, segment);
  return delta;
}

/* Implement md_convert_frag.  */
void
hexagon_convert_frag (bfd *abfd ATTRIBUTE_UNUSED, segT sec ATTRIBUTE_UNUSED,
		      fragS *fragP)
{
  hexagon_packet *apacket = &fragP->tc_frag_data->packet;

  if (apacket->drlx)
    hexagon_relax_branch (fragP);
  if (apacket->dpad || apacket->dpkt)
    hexagon_relax_falign (fragP);
}


/* Target-specific initialization and cleanup.  */

/* Print Hexagon-specific statistics.  */
static void
hexagon_statistics (void)
{
  unsigned total = n_falign[HEXAGON_FALIGN_TOTAL];
  unsigned need = n_falign[HEXAGON_FALIGN_NEED];
  unsigned pack = n_falign[HEXAGON_FALIGN_PACK];

  if (hexagon_falign_info && total)
    {
      as_warn (_("%u of %u \".falign\" (%u%%) inserted new `nop' instructions."),
	       need, total, need * 100 / total);

      if (need)
	as_warn (_("%u of %u \".falign\" (%u%%) inserted new `nop' packets."),
		 pack, need, pack * 100 / need);
    }

  if (hexagon_falign_more && pack)
    {
      as_warn (_("reasons for \".falign\" inserting new `nop' packets:"));
      as_warn (_("  %u of %u (%u%%) reached a packet \".falign\"."),
	       n_falign[HEXAGON_FALIGN_FALIGN], pack,
	       n_falign[HEXAGON_FALIGN_FALIGN] * 100 / pack);
      as_warn (_("  %u of %u (%u%%) reached a single-instruction \".falign\"."),
	       n_falign[HEXAGON_FALIGN_FALIGN1], pack,
	       n_falign[HEXAGON_FALIGN_FALIGN1] * 100 / pack);
      as_warn (_("  %u of %u (%u%%) in different sections."),
	       n_falign[HEXAGON_FALIGN_SECTION], pack,
	       n_falign[HEXAGON_FALIGN_SECTION] * 100 / pack);
      as_warn (_("  %u of %u (%u%%) reached end of history."),
	       n_falign[HEXAGON_FALIGN_END], pack,
	       n_falign[HEXAGON_FALIGN_END] * 100 / pack);
      as_warn (_("  %u of %u (%u%%) exhausted history."),
	       n_falign[HEXAGON_FALIGN_TOP], pack,
	       n_falign[HEXAGON_FALIGN_TOP] * 100 / pack);
      as_warn (_("  %u of %u (%u%%) reached a label."),
	       n_falign[HEXAGON_FALIGN_LABEL], pack,
	       n_falign[HEXAGON_FALIGN_LABEL] * 100 / pack);
      as_warn (_("  %u of %u (%u%%) reached a \".align\"."),
	       n_falign[HEXAGON_FALIGN_ALIGN], pack,
	       n_falign[HEXAGON_FALIGN_ALIGN] * 100 / pack);
      as_warn (_("  %u of %u (%u%%) reached another `nop' packet."),
	       n_falign[HEXAGON_FALIGN_NOP], pack,
	       n_falign[HEXAGON_FALIGN_NOP] * 100 / pack);
      as_warn (_("  %u of %u (%u%%) failed inserting new `nop' instruction."),
	       n_falign[HEXAGON_FALIGN_SHUF], pack,
	       n_falign[HEXAGON_FALIGN_SHUF] * 100 / pack);
    }

  if (hexagon_pairs_info && n_pairs[HEXAGON_PAIRS_TOTAL])
    {
      as_warn (_("%u instruction pairings."), n_pairs[HEXAGON_PAIRS_TOTAL]);
    }
}

/* Invocation line includes a switch not recognized by the base assembler.
   See if it's a processor-specific option.  */
int
md_parse_option (int c, char *arg)
{
  static int post_stats;
  unsigned int i;
  int temp_hexagon_mach_type = 0;

  switch (c)
    {
    case OPTION_HEX_PAIR_INFO:
      hexagon_pairs_info = TRUE;
      if (!post_stats)
	{
	  post_stats = TRUE;
	  xatexit (hexagon_statistics);
	}
      break;

    case OPTION_HEX_FALIGN_MORE_INFO:
      hexagon_falign_more = TRUE;
      /* Fall through.  */

    case OPTION_HEX_FALIGN_INFO_NEW:
      hexagon_falign_info = TRUE;
      if (!post_stats)
	{
	  post_stats = TRUE;
	  xatexit (hexagon_statistics);
	}
      break;

    case OPTION_HEX_FALIGN_WARN:
      hexagon_falign_warn = TRUE;
      break;

    case OPTION_HEX_MV4:
    case OPTION_HEX_MV5:
    case OPTION_HEX_MV55:
    case OPTION_HEX_MARCH:
    case OPTION_HEX_MCPU:
      switch (c)
	{
	case OPTION_HEX_MV4:
	case OPTION_HEX_MV5:
	case OPTION_HEX_MV55:
	  /* -mv* options.  */
	  temp_hexagon_mach_type
	    = hexagon_marchs[c - OPTION_HEX_MV2].march_name_be;
	  break;

	default:
	  /* -march and- mcpu options.  */
	  for (i = 0; i < ARRAY_SIZE (hexagon_marchs); i++)
	    if (!strcmp (arg, hexagon_marchs[i].march_name_fe)
		|| !strcmp (arg, hexagon_marchs[i].march_alt_fe)
		|| !strcmp (arg, hexagon_marchs[i].march_short_fe))
	      {
		temp_hexagon_mach_type = hexagon_marchs[i].march_name_be;
		break;
	      }

	  if (i == ARRAY_SIZE (hexagon_marchs))
	    as_fatal (_("invalid architecture specified."));
	  break;
	}

      if (cmdline_set_hexagon_mach_type
	  && hexagon_mach_type != temp_hexagon_mach_type)
	as_fatal (_("conflicting architectures specified."));

      hexagon_mach_type = temp_hexagon_mach_type;
      cmdline_set_hexagon_mach_type = TRUE;
      break;

    case 'G':
      {
	int x;

	x = atoi (arg);

	if (x < 0)
	  as_warn (_("invalid value for \"-%c\"; defaulting to %d."),
		   c, x = HEXAGON_SMALL_GPSIZE);
	else
	  hexagon_gp_size = x;
      }
      break;

    case OPTION_HEX_MSORT_SDA:
      hexagon_sort_sda = TRUE;
      break;

    case OPTION_HEX_MNO_SORT_SDA:
      hexagon_sort_sda = FALSE;
      break;

    case OPTION_HEX_NO_2MEMORY:
      hexagon_no_dual_memory = TRUE;
      break;

    case OPTION_HEX_MNO_EXTENDER:
      hexagon_extender = FALSE;
      break;

    case OPTION_HEX_MNO_PAIRING:
      hexagon_pairing = hexagon_pairing_branch = hexagon_pairing_duplex = FALSE;
      break;

    case OPTION_HEX_MNO_PAIRING_B:
      hexagon_pairing_branch = FALSE;
      break;

    case OPTION_HEX_MNO_PAIRING_2:
      hexagon_pairing_duplex = FALSE;
      break;

    case OPTION_HEX_MNO_JUMPS:
      hexagon_relax = FALSE;
      break;

    case OPTION_HEX_MNO_JUMPS_LONG:
      hexagon_relax_long = FALSE;
      break;

    case OPTION_HEX_MNO_FALIGN:
      hexagon_fetch_align = FALSE;
      break;

    case OPTION_HEX_MNO_DEALLOC_RETURN:
      hexagon_dealloc_return = FALSE;
      break;

    default:
      return FALSE;
    }
  return TRUE;
}

void
md_show_usage (FILE *stream)
{
  fprintf (stream, "\
Hexagon Options:\n\
  -G<SIZE>                small-data size limit (default is \"%d\")\n\
  -march={v4|v5|v55}      assemble for the specified Hexagon architecture\n"
#ifdef __linux__
"                          (default is \"v5\")\n"
#else
"                          (default is \"v4\")\n"
#endif
"  -mcpu={v4|v5|v55}       equivalent to \"-march\"\n\
  -m{v4|v5|v55}           equivalent to \"-march\"\n\
  -mno-dealloc_return     disable use of the dealloc_return instruction\n\
  -mno-extender           disable the use of constant extenders\n\
  -mfalign-info           report \".falign\" statistics\n\
  -mfalign-warn           warn on \".falign\" activity\n\
  -mno-jumps              disable automatic extension of branch instructions\n\
  -mno-jumps-long         disable automatic extension of non-paired\n\
                          branch instructions\n\
  -mno-pairing            disable pairing of instructions\n\
  -mno-pairing-branch     disable pairing of direct branch instructions\n\
  -mno-pairing-duplex     disable pairing to duplex instructions\n\
  -mpairing-info          report instruction pairing statistics\n\
  -msort-sda              enable sorting the small-data area (default)\n\
", HEXAGON_SMALL_GPSIZE);
}

/* This function is called once, at assembler startup time.  It should
   set up all the tables, etc. that the MD part of the assembler will need.
   Opcode selection is deferred until later because we might see a .option
   command.  */
void
md_begin ()
{
  segT current_section = now_seg;
  int current_subsec = now_subseg;
  flagword applicable;

  if (!bfd_set_arch_mach (stdoutput, bfd_arch_hexagon, hexagon_mach_type))
    as_warn (_("architecture and machine types not set; using default settings."));

  /* Initialize the opcode tables for the instruction set selected by the
     command-line options.  */
  hexagon_opc_init (hexagon_mach_type);

  /* Initialize global NOP.  */
  hexagon_find_nop ();
  /* Initialize global k-extension.  */
  hexagon_find_kext ();

  /* Set the default alignment for the default sections.  */
  record_alignment (text_section, DEFAULT_CODE_ALIGNMENT);

  /* Hexagon V2 */
  applicable = bfd_applicable_section_flags (stdoutput);

  /* Create the sdata section.  */
  hexagon_sdata_section = subseg_new (SMALL_DATA_SECTION, 0);
  bfd_set_section_flags (stdoutput, hexagon_sdata_section,
			 (applicable & (SEC_ALLOC | SEC_LOAD | SEC_RELOC
					| SEC_DATA | SEC_SMALL_DATA)));
  elf_section_type (hexagon_sdata_section) = SHT_PROGBITS;
  record_alignment (hexagon_sdata_section, DEFAULT_DATA_ALIGNMENT);
  symbol_table_insert (section_symbol (hexagon_sdata_section));

  /* Create the sbss section.  */
  hexagon_sbss_section = subseg_new (SMALL_BSS_SECTION, 0);
  bfd_set_section_flags	(stdoutput, hexagon_sbss_section,
			 applicable & (SEC_ALLOC | SEC_SMALL_DATA));
  elf_section_type (hexagon_sbss_section) = SHT_NOBITS;
  seg_info (hexagon_sbss_section)->bss = TRUE;
  record_alignment (hexagon_sbss_section, DEFAULT_DATA_ALIGNMENT);
  symbol_table_insert (section_symbol (hexagon_sbss_section));

  /* We must construct a fake section similar to bfd_com_section,
     but with the name .scommon.  */
  hexagon_scom_section = bfd_com_section;
  hexagon_scom_section.name = SMALL_COM_SECTION;
  hexagon_scom_section.flags |= SEC_SMALL_DATA;
  hexagon_scom_section.output_section = &hexagon_scom_section;
  hexagon_scom_section.symbol = &hexagon_scom_symbol;
  hexagon_scom_section.symbol_ptr_ptr = &hexagon_scom_section.symbol;

  hexagon_scom_symbol = *bfd_com_section.symbol;
  hexagon_scom_symbol.name = SMALL_COM_SECTION;
  hexagon_scom_symbol.section = &hexagon_scom_section;

  /* Set the GP size.  */
  bfd_set_gp_size (stdoutput, hexagon_gp_size);

  /* Reset default section.  */
  subseg_set (current_section, current_subsec);
}

/* Initialize the various opcode and operand tables.  */
static void
hexagon_init (int mach)
{
  static int init_p;

  if (!init_p)
    {
      if (!bfd_set_arch_mach (stdoutput, bfd_arch_hexagon, mach))
	as_warn (_("architecture and machine types not set; using default settings."));

      /* This initializes the lookup tables for the indicated
	 instruction set.  */
      hexagon_opc_init (mach);

      /* Initialize global NOP.  */
      hexagon_find_nop ();
      /* Initialize global k-extension.  */
      hexagon_find_kext ();

      /* Initialize ISA-specific features.  */
      hexagon_autoand &= hexagon_if_arch_autoand ();
      hexagon_extender &= hexagon_if_arch_kext ();
      hexagon_pairing &= hexagon_if_arch_pairs ();
      hexagon_pairing_branch &= hexagon_pairing;
      hexagon_pairing_duplex &= hexagon_pairing;
      hexagon_relax &= hexagon_extender;
      hexagon_relax_long &= hexagon_relax;

      /* Tell `.option' it's too late.  */
      cpu_tables_init_p = TRUE;

      init_p = TRUE;
    }
}

/* Implement md_cleanup.  */
void
hexagon_cleanup (void)
{
  if (hexagon_in_packet)
    {
      as_warn (_("reached end of file before closing a packet."));

      hexagon_packet_form (&hexagon_apacket, &hexagon_aqueue);
      hexagon_packet_end (&hexagon_apacket);
      hexagon_packet_write (&hexagon_apacket);
    }
}


/* Parsing support.  */

/* Implement TC_START_LABEL.
   We need to distinguish a register pair name (e.g., r1:0 or p3:0)
   from a label.  */
int
hexagon_start_label (char c, char *before, char *after)
{
  static const char ex_before_legacy[]
    = "\\<((r((0*[12]?[13579])|31))|sp|lr|p3)$";
  static const char ex_after_legacy[] = "^((0*[12]?[02468])|30|fp)\\>";
  static const char ex_before_pairs[]
    = "\\<(((c|g|r)((0*[12]?[13579])|31))|(s((0*[12345]?[13579])|61|63))|sp|lr|p3)$";
  static const char ex_after_pairs[] = "^((0*[12345]?[02468])|60|62|fp)\\>";
  static regex_t re_before, re_after;
  static int re_ok;

  /* Labels require a colon.  */
  if (c != ':')
    return FALSE;

  /* The reader puts '\0' where the colon was.  */
  after++;

  if (!re_ok)
    {
      const char *ex_before, *ex_after;

      ex_before	= hexagon_if_arch_pairs () ? ex_before_pairs : ex_before_legacy;
      ex_after = hexagon_if_arch_pairs () ? ex_after_pairs : ex_after_legacy;

      /* Compile RE for GPR or predicate pairs.  */
      assert (!xregcomp (&re_before, ex_before,
			 REG_EXTENDED | REG_ICASE | REG_NOSUB));
      assert (!xregcomp (&re_after, ex_after,
			 REG_EXTENDED | REG_ICASE | REG_NOSUB));

      re_ok = TRUE;
    }

  /* Register pairs are not labels.  */
  if (!xregexec (&re_before, before, 0, NULL, 0)
      && !xregexec (&re_after, after, 0, NULL, 0))
    return FALSE;

  /* After everything else has been tried, this must be a label.  */
  return TRUE;
}

/* Implement tc_unrecognized_line.
   Called by the assembler parser when it can't recognize a line.
   At this point, CH is the next character to be processed and
   input_line_pointer has already been moved past CH.  */
int
hexagon_unrecognized_line (int ch ATTRIBUTE_UNUSED)
{
  char *str = input_line_pointer - 1;

  if (*str == PACKET_BEGIN)
    {
      str++;
      if (hexagon_in_packet)
	as_warn (_("found `%c' inside a packet."), PACKET_BEGIN);

      hexagon_packet_begin (&hexagon_apacket);
      return TRUE;
    }
  else if (*str == PACKET_END)
    {
      str++;
      if (!hexagon_in_packet)
	as_warn (_("found `%c' before opening a packet."), PACKET_END);

      while (ISBLANK (*str))
	str++;

      if (!strncasecmp (str, PACKET_END_INNER, strlen (PACKET_END_INNER)))
	{
	  hexagon_aqueue.is_inner = TRUE;
	  input_line_pointer = str += strlen (PACKET_END_INNER);
	}

      while (ISBLANK (*str))
	str++;

      if (!strncasecmp (str, PACKET_END_OUTER, strlen (PACKET_END_OUTER)))
	{
	  hexagon_aqueue.is_outer = TRUE;
	  input_line_pointer = str += strlen (PACKET_END_OUTER);
	}

      while (ISBLANK (*str))
	str++;

      if (!strncasecmp (str, PACKET_END_INNER, strlen (PACKET_END_INNER)))
	{
	  hexagon_aqueue.is_inner = TRUE;
	  input_line_pointer = str += strlen (PACKET_END_INNER);
	}

      if (hexagon_packet_form (&hexagon_apacket, &hexagon_aqueue))
	{
	  hexagon_packet_end (&hexagon_apacket);
	  hexagon_packet_write (&hexagon_apacket);
	}
      else
	hexagon_in_packet = FALSE;

      return TRUE;
    }
  else if (!strncasecmp (str, PACKET_END_INNER, strlen (PACKET_END_INNER)))
    {
      as_warn (_("found `%s' when not closing a packet."), PACKET_END_INNER);
      input_line_pointer += strlen (PACKET_END_INNER) - 1;
      return TRUE;
    }
  else if (!strncasecmp (str, PACKET_END_OUTER, strlen (PACKET_END_OUTER)))
    {
      as_warn (_("found `%s' when not closing a packet."), PACKET_END_OUTER);
      input_line_pointer += strlen (PACKET_END_OUTER) - 1;
      return TRUE;
    }

  /* Not a valid line */
  return FALSE;
}

/* Parse operands of the form "<symbol>@<suffix>+<nnn>" and other PIC or TLS
   references.  If one is found, set up the correct relocation and
   copy the input string, minus the "@..." into an allocated buffer for
   parsing by the calling routine.  Return this buffer set it to the length
   of the string that was removed from the input line.  Otherwise return
   NULL.  */
static char *
hexagon_parse_suffix (hexagon_suffix_type *type, char **extra)
{
  char *cp;
  size_t j;

  *type = SUF_NONE;

  for (cp = input_line_pointer; *cp != '@'; cp++)
    if (is_end_of_line[(unsigned char) *cp])
      return NULL;

  for (j = SUF_1ST; j < SUF_MAX; j++)
    {
      size_t len;

      /* FIXME: Assumes that the primary and secondary suffixes
         are the same length.  */
      len = strlen (hexagon_suffix[j].pri);
      if (!strncasecmp (cp + 1, hexagon_suffix[j].pri, len)
	  || (hexagon_suffix[j].sec
	      && !strncasecmp (cp + 1, hexagon_suffix[j].sec, len)))
	{
	  ptrdiff_t before, after;
	  char *tmp, *past;

	  /* The length of the before part of our input line.  */
	  before = cp - input_line_pointer;

	  /* The after part goes from after the relocation token until
	     (and including) an end_of_line char.  Don't use strlen
	     here as the end_of_line char may not be a NUL.  */
	  past = cp + 1 + len;
	  for (cp = past; !is_end_of_line[(unsigned char) *cp]; cp++)
	    ;
	  after = cp - past;

	  /* Allocate and form string.  */
	  tmp = xmalloc (before + after + 2);

	  strncpy (tmp, input_line_pointer, before);
	  /* Replace the '@' with ' ', so that errors like "foo@GOTOFF1"
	     will be detected.  */
	  tmp[before] = ' ';
	  strncpy (tmp + before + 1, past, after);
	  tmp[before + after + 1] = '\0';

	  *type = j;
	  if (extra)
	    *extra = past;

	  return tmp;
	}
    }

  /* Might be a symbol version string.  Don't as_bad here.  */
  return NULL;
}

/* Create a k-extend prefix with value XVALUE and store it in KEXT.
   Return true if successful.  */
static int
hexagon_prefix_kext (hexagon_packet_insn **kext, long xvalue)
{
  const hexagon_operand *operand;
  const char *syntax;
  long mask;

  if (!*kext)
    /* Allocate a prefix if one wasn't specified.  */
    *kext = xmalloc (sizeof (**kext));

  **kext = hexagon_kext_insn;

  for (syntax = (*kext)->opcode->syntax; *syntax; syntax++)
    if (ISSPACE (*syntax))
      break;

  /* Skip the '(' and any spaces around it.  */
  while (*syntax && ISSPACE (*syntax))
    syntax++;
  syntax++;
  while (*syntax && ISSPACE (*syntax))
    syntax++;

  operand = hexagon_lookup_operand (syntax);
  assert (operand);

  /* Truncate to as many bits as in the extension.  */
  mask = ~(~0L << (operand->bits + operand->shift_count));
  if (mask)
    xvalue &= mask;
  if (hexagon_encode_operand (operand, &(*kext)->insn, (*kext)->opcode,
			      xvalue, FALSE, NULL))
    {
      (*kext)->used = TRUE;
      return TRUE;
    }

  return FALSE;
}

/* Helper function:  look up the operand whose name matches that of the
   name of OPERAND with SUFFIX appended.  */
static const hexagon_operand *
hexagon_lookup_operand_suffix (const hexagon_operand *operand,
			       const char *suffix)
{
  char *buf;

  buf = alloca (strlen (operand->fmt) + strlen (suffix) + 1);
  strcpy (buf, operand->fmt);
  strcat (buf, suffix);

  return hexagon_lookup_operand_name (buf, 0);
}

/* Parse an immediate operand described by OPERAND for the insn in AINSN
   from the input string STR.  The value is stored in VAL as well as
   encoded into AINSN, and the updated input string pointer is returned.
   On error, a message is stored in ERRMSG (if it is non-null) and NULL
   is returned.  */
static char *
hexagon_parse_immediate (hexagon_packet_insn *ainsn,
			 const hexagon_operand *operand,
			 char *str, long *val, char **errmsg)
{
  char *hold;
  expressionS exp;
  const hexagon_operand *operandx;
  long value = 0;
  int is_may_x = FALSE, is_x = FALSE, is_hash = FALSE;
  int is_relax = FALSE;
  int is_lo16 = FALSE, is_hi16 = FALSE;
  char *suffix_line;
  hexagon_suffix_type suffix_type;

  is_may_x = HEXAGON_OPERAND_IS_EXTENDABLE (operand, ainsn->opcode);

  /* We only have the mandatory '#' for immediates that are NOT PC-relative */
  if (*str == '#')
    {
      is_hash = operand->flags & HEXAGON_OPERAND_PC_RELATIVE;
      str++;
      if (*str == '#')
	{
	  is_x = hexagon_extender;
	  str++;
	}
      else
	is_x = (hexagon_extender
		&& HEXAGON_OPCODE_IS_MUST_EXTEND (ainsn->opcode));
      is_hash = is_hash && !is_x;
    }
  else if (!(operand->flags & HEXAGON_OPERAND_PC_RELATIVE))
    return NULL;

  is_relax = (is_may_x && !is_x && !is_hash
	      && encode_relax (operand->reloc_type));

  /* Check if the operand can truly be extended.  */
  if (is_x && !ainsn->opcode->map && !is_may_x)
    {
      if (errmsg)
	*errmsg = _("operand cannot be extended.");
      return NULL;
    }

  /* Hexagon TODO: Allow white space between lo/hi and the paren */
  if (TOLOWER (str[0]) == 'l' && TOLOWER (str[1]) == 'o' && str[2] == '(')
    {
      /* Make sure we have a corresponding lo16 operand */
      operand = hexagon_lookup_operand_suffix (operand, "_lo16");
      if (!operand)
	return NULL;

      is_lo16 = 1;
      str += 3;
    }
  else if (TOLOWER (str[0]) == 'h' && TOLOWER (str[1]) == 'i' && str[2] == '(')
    {
      /* Make sure we have a corresponding hi16 operand */
      operand = hexagon_lookup_operand_suffix (operand, "_hi16");
      if (!operand)
	return NULL;

      is_hi16 = 1;
      str += 3;
    }

  hold = input_line_pointer;
  input_line_pointer = str;

  suffix_line = hexagon_parse_suffix (&suffix_type, &str);
  if (suffix_line)
    input_line_pointer = suffix_line;
  
  expression (&exp);
  
  if (!suffix_line)
    str = input_line_pointer;
  input_line_pointer = hold;

  if (suffix_type != SUF_NONE)
    {
      operandx = hexagon_lookup_operand_suffix (operand,
						hexagon_suffix[suffix_type].pri);
      if (!operandx && hexagon_suffix[suffix_type].sec)
	operandx = hexagon_lookup_operand_suffix (operand,
						  hexagon_suffix[suffix_type].sec);
      if (operandx)
	/* Get new PIC/TLS operand.  */
	operand = operandx;
      else
	{
	  if (errmsg)
	    *errmsg = _("invalid operand suffix.");
	  return NULL;
	}
    }

  if (is_lo16 || is_hi16)
    {
      while (ISSPACE (*str))
	str++;

      /* Check for closing paren */
      if (*str != ')')
	{
	  if (errmsg)
	    *errmsg = _("missing `)'.");
	  return NULL;
	}
      else
	str++;
    }

  if (exp.X_op == O_illegal)
    {
      if (errmsg)
	*errmsg = _("illegal operand.");
      return NULL;
    }
  else if (exp.X_op == O_absent)
    {
      if (errmsg)
	*errmsg = _("missing operand.");
      return NULL;
    }
  else if (exp.X_op == O_register)
    {
      if (errmsg)
	*errmsg = _("unexpected register.");
      return NULL;
    }
  else if (exp.X_op == O_constant)
    {
      /* Interpret value according to the 32-bit Hexagon ISA */
      value = (int32_t) exp.X_add_number;

      if (!hexagon_encode_operand (operand, &ainsn->insn, ainsn->opcode,
				   value, is_x, errmsg))
	return NULL;

      /* Emit prefix only if requested or needed.  */
      if (is_x)
	{
	  if (hexagon_prefix_kext (&ainsn->prefix, HEXAGON_KXER_MASK (value)))
	    ainsn->flags |= HEXAGON_INSN_IS_KXED;
	  else
	    return NULL;
	}
    }
  else
    {
      if (is_x)
	{
	  is_x = hexagon_prefix_kext (&ainsn->prefix, 0);
	  assert (is_x);

	  operandx = hexagon_lookup_reloc (operand->reloc_kxer, 0,
					   ainsn->prefix->opcode);
	  if (operandx)
	    {
	      ainsn->prefix->exp = exp;
	      ainsn->prefix->operand = xmalloc (sizeof (*operandx));
	      *ainsn->prefix->operand = *operandx;
	      ainsn->prefix->operand->reloc_kxer = operand->reloc_type;

	      ainsn->prefix->fc++;
	    }
	  else
	    {
	      if (errmsg)
		*errmsg = _("expression too complex.");
	      return NULL;
	    }
	}

      if ((is_x ? operand->reloc_kxed : operand->reloc_type) == BFD_RELOC_NONE)
	{
	  if (errmsg)
	    *errmsg = _("unexpected non-constant expression.");
	  return NULL;
	}

      /* This expression involves one or more symbols.
         Record a fixup to process later */
      if (ainsn->fc >= MAX_FIXUPS)
	if (errmsg)
	  *errmsg = _("expression too complex.");

      if (is_x)
	ainsn->flags |= HEXAGON_INSN_IS_KXED;
      if (is_relax)
	ainsn->flags |= HEXAGON_INSN_IS_RELAX;
      ainsn->exp = exp;
      ainsn->operand = xmalloc (sizeof (*operand));
      *ainsn->operand = *operand;
      if (is_x)
	ainsn->operand->flags |= HEXAGON_OPERAND_IS_KXED;
      ainsn->fc++;
    }

  /* Return the value before extension, if any, so that aliased insns
     can pick up the original value.  */
  *val = value;
  return str;
}

/* Create a literal section with the appropriate flags.  */
static segT
hexagon_create_literal_section (const char *name, flagword flags,
				unsigned int align2)
{
  segT current_section = now_seg;
  int current_subsec = now_subseg;
  flagword applicable = bfd_applicable_section_flags (stdoutput);
  segT new_section = subseg_new (name, 0);

  bfd_set_section_flags
    (stdoutput, new_section,
     applicable & (flags | SEC_ALLOC | SEC_LOAD | SEC_DATA | SEC_SMALL_DATA));
  record_alignment (now_seg, align2);
  symbol_table_insert (section_symbol (new_section));
  subseg_set (current_section, current_subsec);
  return new_section;
}

#define IS_SAME_SYMBOL(e,e1) (((e).X_op == (e1)->X_op) \
                              && (((e).X_op == O_symbol) || (e).X_op == O_absent) \
                              && ((e).X_op_symbol == (e1)->X_op_symbol) \
                              && ((e).X_add_symbol == (e1)->X_add_symbol) \
                              && ((e).X_add_number == (e1)->X_add_number))

/* add the expression exp to the .sdata literal pool */
static hexagon_literal *
hexagon_add_to_lit_pool (expressionS * exp, expressionS * exp1, size_t size)
{
  hexagon_literal *literal, *last;
  segT current_section = now_seg;
  int current_subsec = now_subseg;
  offsetT mask = (size == 8) ? 0xffffffffffffffffULL : 0xffffffffULL;
  const char *group_name = NULL;

  /* Sanity check for illegal constant literals.  */
  if (size != 8 && size != 4)
    as_fatal (_("invalid literal constant."));

  /* We must do things a little differently if a literal symbol reference
     appears in a COMDAT group.  */
  if ((exp->X_op == O_symbol) && (now_seg->flags & SEC_LINK_ONCE))
    group_name = elf_group_name (now_seg);

  /* Try to find an existing literal for the expression in order to
     reuse it.  */
  for (literal = last = hexagon_pool; literal != NULL;
       literal = literal->next)
    {
      /* Save the last node.  */
      last = literal;

      /* Check for a constant value.  */
      if (literal->e.X_op == exp->X_op
	  && literal->e.X_op == O_constant
	  && (literal->e.X_add_number & mask) == (exp->X_add_number & mask)
	  && literal->size == size)
	break;

      /* Check for 32-bit or 64-bit (two 32-bit) symbol.  */
      if (IS_SAME_SYMBOL (literal->e, exp)
	  && IS_SAME_SYMBOL (literal->e1, exp1)
	  && literal->size == size
	  && (!literal->group_name || group_name == literal->group_name))
	break;

      /* Check for a 32-bit symbol in a 64-bit (2 32-bit) symbol.  */
      if (IS_SAME_SYMBOL (literal->e1, exp)
	  && literal->size == 8
	  && size == 4
	  && (!literal->group_name || group_name == literal->group_name))
	break;
    }

  /* Do we need to create a new entry? */
  if (!literal)
    {
      if (hexagon_pool_counter >= MAX_LITERAL_POOL)
	{
	  as_bad (_("too many literal constants."));
	  return NULL;
	}

      literal = xmalloc (sizeof (*literal));
      literal->next = NULL;
      literal->size = size;

      /* Save the head pointer to "hexagon_pool".  */
      if (!hexagon_pool)
	hexagon_pool = last = literal;

      /* Get the expression.  */
      literal->e = *exp;
      literal->e1 = *exp1;

      /* Remember group info.  */
      literal->group_name = group_name;

      if (literal->e.X_op == O_constant)
	/* Create a constant symbol (with its value as the suffix).  */
	{
	  char *buf;
	  if (size == 8)
	    {
	      sprintf (literal->name,
#if defined (__MINGW32__)
		       "%s_%016I64x",
#else
		       "%s_%016llx",
#endif
		       LITERAL_PREFIX, (long long) literal->e.X_add_number);
	      buf = xmalloc (LITERAL_ONCE_8_LEN + MAX_LITERAL_NAME);
	      sprintf (buf, "%s%s", LITERAL_SECTION_ONCE_8, literal->name);
	    }
	  else
	    {
	      sprintf (literal->name, "%s_%08x",
		       LITERAL_PREFIX, (int) literal->e.X_add_number);
	      buf = xmalloc (LITERAL_ONCE_4_LEN + MAX_LITERAL_NAME);
	      sprintf (buf, "%s%s", LITERAL_SECTION_ONCE_4, literal->name);
	    }

	  literal->secname = buf;
	  literal->sec = hexagon_create_literal_section (buf, SEC_LINK_ONCE,
							 bfd_log2 (size));
	  literal->sub = LITERAL_SUBSECTION + (size == 8 ? 2 : 1);
	}
      else			/* if (literal->e.X_op == O_symbol) */
	/* Create a label symbol (with the literal order as the suffix).  */
	{
	  char *buf;
	  sprintf (literal->name, "%s_%04x", LITERAL_PREFIX,
		   hexagon_pool_counter);
	  if (group_name)
	    {
	      buf = xmalloc (LITERAL_A_LEN + 1 + strlen (group_name) + 1);
	      sprintf (buf, "%s.%s", LITERAL_SECTION_A, group_name);
	    }
	  else
	    {
	      buf = xmalloc (LITERAL_A_LEN + 1);
	      strcpy (buf, LITERAL_SECTION_A);
	    }
	  literal->secname = buf;
	  literal->sec = hexagon_create_literal_section (buf, 0,
							 bfd_log2 (size));
	  literal->sub = LITERAL_SUBSECTION;
	  if (group_name)
	    {
	      elf_group_name (literal->sec) = group_name;
	      literal->sec->flags |= SEC_LINK_ONCE;
	    }
	}

      /* Group the literals per size and type in separate subsections
         in order to minimize wasted space due to alignment.  */
      subseg_set (literal->sec, literal->sub);

      /* Set the alignment.  */
      frag_align (bfd_log2 (size), 0, 0);

      /* Define the symbol.  */
      literal->sym = symbol_new (literal->name, now_seg,
				 (valueT) frag_now_fix (), frag_now);
      symbol_table_insert (literal->sym);

      /* Set the size and type.  */
      S_SET_SIZE (literal->sym, size);
      symbol_get_bfdsym (literal->sym)->flags |= BSF_OBJECT;

      /* Set the scope.  */
      if (literal->e.X_op == O_constant)
	S_SET_EXTERNAL (literal->sym);

      /* Emit the data definition.  */
      if (literal->e1.X_op == O_symbol || literal->e1.X_op == O_constant)
	{
	  emit_expr (&literal->e, size / 2);
	  emit_expr (&literal->e1, size / 2);
	}
      else
	emit_expr (&literal->e, size);

      /* Restore the last section.  */
      subseg_set (current_section, current_subsec);

      hexagon_pool_counter++;

      /* Add literal to the literal pool list.  */
      if (hexagon_pool != literal)
	last->next = literal;
    }

  return literal;
}

/* This function searches the instruction string for GP related
 * instructions:
 * Rd32 = CONST32(#imm), Rd32 = CONST32(label)
 * Rdd32 = CONST64(#imm), Rdd32 = CONST64(label)
 * Rdd32 = CONST64(#imm|label, #imm|label)
 * If it is identified as such an instruction, following translation
 * will be performed:
 * 1. Add an internal reference to "#imm" or "label"
 * 2. Store the reference to ".sdata" section
 * 3. Translate the instruction into following format:
 * Rd32 = memw(#internal_reference)
 * Rdd32 = memd(#internal_reference)
 * The new instruction will be stored in "new_str"
 * A few details:
 * 1. If ".sdata" section does not exist, create one
 * 2. Keep track of the internal references created ("literal pool"),
 *    and reuse it whenever possible
 * 3. Only one ".sdata" will be created/used.
 * 4. The size of ".sdata" will be 1024 bytes, anything beyond that
 * will trigger an error message "literal pool (.sdata) overflow"
 *
 * Returns:
 * 1 if success (found and translated),
 * 0 for anything else.
 */

static int
hexagon_gp_const_lookup (char *str, char *new_str)
{
  static const char ex_c32[]
    = "=[[:space:]]*" "\\<const32\\>" "[[:space:]]*"
    "\\([[:space:]]*#?[[:space:]]*(.+)[[:space:]]*\\)";
  static const char ex_c64[]
    = "=[[:space:]]*" "\\<const64\\>" "[[:space:]]*"
    "\\([[:space:]]*#?[[:space:]]*(.+)[[:space:]]*\\)";
  static const char ex_c64_2[]
    = "=[[:space:]]*" "\\<const64\\>" "[[:space:]]*"
    "\\([[:space:]]*#?[[:space:]]*(.+)[[:space:]]*,"
    "[[:space:]]*#?[[:space:]]*(.+)[[:space:]]*\\)";
  static const char ex_r32[] = "^\\<(r((0*[12]?[0-9])|30|31))|sp|fp|lr\\>";
  static const char ex_r64[]
    = "^\\<((r((0*[12]?[13579])|31))|sp|lr):((0*[12]?[02468])|30|fp)\\>";
  static regex_t re_c32, re_c64, re_c64_2, re_r32, re_r64;
  regmatch_t rm_left[1], rm_right[3];
  static int re_ok;
  int size;
  expressionS exp, exp1;
  hexagon_literal *litcurptr;
  char *save;
  int num_args;

  if (!re_ok)
    {
      /* Compile REs.  */
      assert (!xregcomp (&re_c32, ex_c32, REG_EXTENDED | REG_ICASE));
      assert (!xregcomp (&re_c64, ex_c64, REG_EXTENDED | REG_ICASE));
      assert (!xregcomp (&re_c64_2, ex_c64_2, REG_EXTENDED | REG_ICASE));
      assert (!xregcomp (&re_r32, ex_r32, REG_EXTENDED | REG_ICASE));
      assert (!xregcomp (&re_r64, ex_r64, REG_EXTENDED | REG_ICASE));

      re_ok = TRUE;
    }

  /* Get the left and right-side expressions and distinguish between
     CONST32 and CONST64.  */
  if (!xregexec (&re_c32, str, 2, rm_right, 0))
    {
      if (rm_right[1].rm_so < 0
	  || rm_right[1].rm_eo < 0
	  || xregexec (&re_r32, str, 1, rm_left, 0))
	return FALSE;
      else
	size = 4;
      num_args = 1;
    }
  else if (!regexec (&re_c64_2, str, 3, rm_right, 0))
    {
      if (rm_right[1].rm_so < 0
	  || rm_right[1].rm_eo < 0
	  || regexec (&re_r64, str, 1, rm_left, 0))
	return FALSE;
      else
	size = 8;
      num_args = 2;
    }
  else if (!xregexec (&re_c64, str, 2, rm_right, 0))
    {
      if (rm_right[1].rm_so < 0
	  || rm_right[1].rm_eo < 0
	  || xregexec (&re_r64, str, 1, rm_left, 0))
	return FALSE;
      else
	size = 8;
      num_args = 1;
    }
  else
    return FALSE;

  if (!hexagon_gp_size)
    as_warn (_("using `CONST%d' with \"-G%d\"."), size * 8, hexagon_gp_size);

  /* Parse right-side expression.  */
  save = input_line_pointer;
  input_line_pointer = str + rm_right[1].rm_so;
  expression (&exp);
  if (num_args == 2)
    {
      input_line_pointer = str + rm_right[2].rm_so;
      expression (&exp1);
    }
  else
    {
      exp1.X_op = O_absent;
      exp1.X_add_symbol = exp1.X_op_symbol = NULL;
      exp1.X_add_number = 0;
    }
  input_line_pointer = save;

  /* 64-bit literals must be constants.  */
  if (exp.X_op != O_constant && size == 8 && num_args == 1)
    {
      as_bad (_("64-bit expression `%.*s' is not constant."),
	      rm_right[1].rm_eo - rm_right[1].rm_so, str + rm_right[1].rm_so);
      return FALSE;
    }

  if (num_args == 2 && size != 8)
    {
      as_bad (_("two arguments allowed only with `CONST64'."));
      return FALSE;
    }
  /* If both args are constants, then create a single experssion
     ((exp)<<32)|exp1.  */
  if (num_args == 2
      && size == 8
      && exp.X_op == O_constant
      && exp1.X_op == O_constant)
    {
      exp.X_add_number = (exp.X_add_number << 32) | exp1.X_add_number;
      exp1.X_op = O_absent;
      exp1.X_add_number = 0;
    }

  /* Add a literal for the expression.  */
  litcurptr = hexagon_add_to_lit_pool (&exp, &exp1, size);

  /* Replace original "insn" with a GP-relative load from the literal.  */
  if (litcurptr)
    snprintf (new_str, HEXAGON_MAPPED_LEN, "%.*s = mem%c (#%s)",
	      rm_left[0].rm_eo - rm_left[0].rm_so, str,
	      size == 4 ? 'w' : 'd', litcurptr->name);
  else
    return FALSE;

  return TRUE;
}

/* Check if the operands are consistent.  */
static int
hexagon_check_operand_args (const hexagon_operand_arg args[], size_t n)
{
  size_t i, j;

  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++)
      if (args[i].operand->bits
	  && args[i].operand->bits == args[j].operand->bits
	  && args[i].operand->enc_letter == args[j].operand->enc_letter
	  && args[i].value != args[j].value)
	return FALSE;

  return TRUE;
}

/* This routine is called for each instruction to be assembled.
   STR is the input instruction string, and the result is stored
   in AINSN.  PAIR is true when the function is called to attempt
   to form a pair; this has the effect of suppressing some error
   messages.
   Returns true if the instruction is parsed successfully.  */
int
hexagon_assemble (hexagon_packet_insn *ainsn, char *str, int pair)
{
  const hexagon_opcode *opcode;
  char *start;
  const char *syn;
  int is_id;
  char *mapped;
  hexagon_operand_arg op_args[MAX_OPERANDS];
  size_t op_ndx;
  char *errmsg = NULL;

  /* Opcode table initialization is deferred until here because we have to
     wait for a possible .option command.  */
  hexagon_init (hexagon_mach_type);

  /* Skip leading white space.  */
  while (ISSPACE (*str))
    str++;

  /* Special handling of GP-related syntax:
     - Rd32 = CONST32(#imm) or Rd32 = CONST32(label)
     - Rdd32 = CONST64 (#imm) or Rdd32 = CONST64 (label)
     or Rdd32 = CONST64 (#imm, #imm) */
  mapped = alloca (strlen (str) + HEXAGON_MAPPED_LEN);
  if (hexagon_gp_const_lookup (str, mapped))
    str = mapped;

  /* Keep looking until we find a match.  */
  start = str;
  hexagon_insn_init (ainsn);
  for (opcode = hexagon_opcode_lookup_asm (str);
       opcode; opcode = HEXAGON_CODE_NEXT_ASM (opcode))
    {
      free (ainsn->source);
      ainsn->source = NULL;

      /* Initialize the tentative insn.  */
      hexagon_insn_init (ainsn);
      ainsn->opcode = opcode;
      ainsn->source = xstrdup (start);
      /* Yank the packet termination out.  */
      str = strchr (ainsn->source, PACKET_END);
      if (str)
	*str = 0;

      /* Scan the syntax string.  If it doesn't match, try the next one.  */
      ainsn->insn = ainsn->opcode->insn;
      is_id = 0;
      op_ndx = 0;
      str = start;
      syn = ainsn->opcode->syntax;

      /* Compare this loop to hexagon_dis_opcode, which also walks the
	 opcode syntax string.  */
      while (*str && *syn)
	{
	  if ((ISUPPER (*syn) && (*syn != 'I')) || *syn == '#')
	    {
	      /* We have an operand.  */
	      const hexagon_operand *operandp = hexagon_lookup_operand (syn);
	      if (operandp)
		{
		  size_t len = strlen (operandp->fmt);
		  char *op_str = str;
		  ptrdiff_t op_len;
		  long op_val;

		  if (operandp->flags & HEXAGON_OPERAND_IS_CONSTANT)
		    goto NEXT_SYN;
		  else if (operandp->flags & HEXAGON_OPERAND_IS_IMMEDIATE)
		    {
		      str = hexagon_parse_immediate (ainsn, operandp, op_str,
						     &op_val,
						     !pair ? &errmsg : NULL);
		      if (!str)
			goto NEXT_OPCODE;
		    }
		  else
		    {
		      int is_op;

		      str = hexagon_parse_register (operandp, &ainsn->insn,
						    ainsn->opcode,
						    str, &op_val, &is_op,
						    !pair ? &errmsg : NULL);
		      if (!str)
			/* This instruction doesn't match the syntax */
			goto NEXT_OPCODE;

		      if (is_op & HEXAGON_OPERAND_IS_INVALID)
			goto END_OPCODE;
		      else if (is_op & HEXAGON_OPERAND_IS_PREDICATE
			       && HEXAGON_OPCODE_IS_CONDEXEC (ainsn->opcode))
			ainsn->pred_mask = HEXAGON_PRED_INIT (op_val,
							      ainsn->opcode);
		      else if (is_op & HEXAGON_OPERAND_IS_RNEW)
			{
			  ainsn->flags |= HEXAGON_INSN_IN_RNEW;
			  ainsn->ioperand = operandp;
			  ainsn->ireg = op_val;
			}
		    }

		  /* Store the operand value in case the insn is an alias.  */
		  assert (op_ndx < MAX_OPERANDS);
		  assert (str);

		  op_args[op_ndx].operand = operandp;
		  op_args[op_ndx].value = op_val;
		  op_len
		    = MIN (str - op_str,
			   (ptrdiff_t) sizeof (op_args[op_ndx].string) - 1);
		  strncpy (op_args[op_ndx].string, op_str, op_len);
		  op_args[op_ndx].string[op_len] = 0;
		  op_ndx++;

		  /* Move past the opcode specifier */
		  syn += len;
		  is_id = 0;
		}
	      else
		as_bad (_("operand not found for `%s'."), syn);
	    }
	  else
	    {
	      /* Non-operand chars must match exactly.  */
	    NEXT_SYN:

	      if (TOLOWER (*str) == *syn
		  || (*str == 'I' && *str == *syn))
		{
		  is_id = is_part_of_name (*syn);
		  ++syn;
		  ++str;
		}
	      else
		/* This instruction doesn't match the syntax */
		break;
	    }

	  if (ISSPACE (*syn))
	    {
	      while (ISSPACE (*syn))
		syn++;

	      /* If whitespace is required, make sure it's present */
	      if (is_id
		  && !ISSPACE (*str)
		  && (is_name_beginner (*syn) || *syn == '#')
		  /* TODO: make exception for "p0.new" in the syntax.  */
		  && syn[0] != '.' && syn[1] != 'n' && syn[2] != 'e'
		  && syn[3] != 'w')
		goto NEXT_OPCODE;

	      while (ISSPACE (*str))
		str++;
	    }
	  else
	    while (ISSPACE (*str))
	      str++;
	}

      /* If we're at the end of the syntax string, we're done.  */
      if ((!*str || *str == PACKET_END) && !*syn)
	{
	  char *file;
	  unsigned lineno;

	  if (!hexagon_check_operand_args (op_args, op_ndx))
	    goto NEXT_OPCODE;

	  if (ainsn->opcode->map)
	    {
	      size_t l;

	      l = strlen (str) + HEXAGON_MAPPED_LEN;
	      mapped = alloca (l);

	      /* Remap insn.  */
	      ainsn->opcode->map (mapped, l, op_args);

	      /* Concatenate the rest of the original insn
	         before assembling the remapped insn.  */
	      strncat (mapped, str, l - strlen (mapped) - 1);
	      return hexagon_assemble (ainsn, mapped, pair);
	    }

	  as_where (&file, &lineno);

	  ainsn->used = FALSE;
	  ainsn->pad = FALSE;
	  ainsn->lineno = lineno;

	  while (ISSPACE (*str))
	    ++str;

	  /* Check for the packet end string.  */
	  if (*str == PACKET_END)
	    {
	      str++;

	      if (!hexagon_in_packet)
		{
		  as_warn (_("found `%c' before opening a packet."),
			   PACKET_END);
		  return TRUE;
		}
	      else
		hexagon_in_packet = FALSE;

	      while (ISSPACE (*str))
		++str;

	      /* Check for the end inner/outer modifiers.
	         Note that they can appear in any order.  */
	      while (TRUE)
		{
		  if (!strncasecmp (str, PACKET_END_INNER,
				    strlen (PACKET_END_INNER)))
		    {
		      ainsn->is_inner = TRUE;
		      str += strlen (PACKET_END_INNER);

		      while (ISSPACE (*str))
			++str;
		    }
		  else if (!strncasecmp (str, PACKET_END_OUTER,
					 strlen (PACKET_END_OUTER)))
		    {
		      ainsn->is_outer = TRUE;
		      str += strlen (PACKET_END_OUTER);

		      while (ISSPACE (*str))
			++str;
		    }
		  else
		    break;
		}

	      if (!is_end_of_line[(unsigned char) *str])
		{
		  if (!pair)
		    as_bad (_("extra symbols at end of line: `%s'"), str);
		  else
		    return FALSE;
		}
	    }
	  else if (!is_end_of_line[(unsigned char) *str])
	    {
	      if (!pair)
		as_bad (_("extra symbols at end of line: `%s'"), str);
	      else
		return FALSE;
	    }

	  if (!hexagon_dealloc_return
	      && HEXAGON_OPCODE_IS_DEALLOCRET (ainsn->opcode))
	    {
	      as_bad (_("invalid instruction `%.*s'"), MAX_MESSAGE, start);
	      return FALSE;
	    }

	  /* All done.  */
	  return TRUE;
	}

      /* Try the next entry.  */
    NEXT_OPCODE:
      continue;

      /* Stop trying.  */
    END_OPCODE:
      break;
    }

  if (!pair)
    {
      int big = strlen (start) > MAX_MESSAGE - 3;

      if (errmsg)
	as_bad ("%s\n", errmsg);
      as_bad (_("invalid instruction `%.*s%s'"),
	      big ? MAX_MESSAGE - 3 : MAX_MESSAGE, start, big ? "..." : "");
    }

  return FALSE;
}

/* This routine is called for each instruction to be assembled.  */
void
md_assemble (char *str)
{
  hexagon_packet_insn insn, prefix;

  hexagon_insn_init (&insn);
  hexagon_insn_init (&prefix);

  insn.prefix = &prefix;

  if (hexagon_assemble (&insn, str, FALSE))
    {
      if (!hexagon_queue_insert (&hexagon_aqueue, &insn))
	{
	  int in_packet = hexagon_in_packet;

	  if (hexagon_packet_form (&hexagon_apacket, &hexagon_aqueue))
	    {
	      hexagon_packet_end (&hexagon_apacket);
	      hexagon_packet_write (&hexagon_apacket);
	    }
	  else
	    as_bad (_("too many instructions in packet."));

	  hexagon_in_packet = in_packet;
	  hexagon_queue_insert (&hexagon_aqueue, &insn);
	}

      if (!hexagon_in_packet
	  && hexagon_packet_form (&hexagon_apacket, &hexagon_aqueue))
	{
	  hexagon_packet_end (&hexagon_apacket);
	  hexagon_packet_write (&hexagon_apacket);
	}
    }
}


/* Miscellaneous target hooks.  */

/* Implement TC_FRAG_INIT to initialize custom data in FRAGP.  */
void
hexagon_frag_init (fragS *fragP, fragS *previous)
{
  /* By using xcalloc () here, the custom data is properly initialized.  */
  if (!fragP->tc_frag_data)
    fragP->tc_frag_data = xcalloc (1, sizeof (*fragP->tc_frag_data));

  if (previous && fragP != previous)
    fragP->tc_frag_data->previous = previous;
}

/* Support for HANDLE_ALIGN:  insert a NOP packet to align code.
   FRAGP is a pointer to current code fragment, and COUNT is the
   number of bytes to fill up.  */
void
hexagon_align_code (fragS *fragP, size_t count)
{
  const hexagon_insn a_nop = hexagon_nop_insn.insn | HEXAGON_END_NOT;
  const hexagon_insn z_nop = hexagon_nop_insn.insn | HEXAGON_END_PACKET;
  const hexagon_insn *p_nop;
  size_t offset;

  if (count > 0)
    {
      if ((fragP->fr_address + fragP->fr_fix + count) % HEXAGON_INSN_LEN)
	as_warn (_("code alignment must be a multiple of %d bytes."),
		 HEXAGON_INSN_LEN);

      offset = count % HEXAGON_INSN_LEN;
      if (offset)
	/* Pad to HEXAGON_INSN_LEN boundary first.  */
	memset (fragP->fr_literal + fragP->fr_fix, 0, offset);
      /* Add NOPs to packet.  */
      for (; offset + HEXAGON_INSN_LEN < count; offset += HEXAGON_INSN_LEN)
	{
	  if (offset / HEXAGON_INSN_LEN % MAX_PACKET_INSNS
	      < MAX_PACKET_INSNS - 1)
	    p_nop = &a_nop;
	  else
	    p_nop = &z_nop;
	  memcpy (fragP->fr_literal + fragP->fr_fix + offset, p_nop,
		  HEXAGON_INSN_LEN);
	}
      /* Finalize packet.  */
      if (offset + HEXAGON_INSN_LEN <= count)
	memcpy (fragP->fr_literal + fragP->fr_fix + offset, &z_nop,
		HEXAGON_INSN_LEN);

      fragP->fr_var = count;
    }
}

/* Implement md_elf_section_leter:  map 's' to SHF_HEX_GPREL.  */
bfd_vma
hexagon_elf_section_letter (int letter, char **ptr_msg)
{
  if (letter == 's')
    return SHF_HEX_GPREL;
 
  *ptr_msg = _("unrecognized .section attribute: want a,e,w,x,s,M,S,G,T");
  return -(bfd_vma)1;
}

flagword
hexagon_elf_section_flags (flagword flags, bfd_vma attr,
			   int type ATTRIBUTE_UNUSED)
{
  if (attr & SHF_HEX_GPREL)
    flags |= SEC_SMALL_DATA;
  
  return flags;
}
 
char *
md_atof (int type, char *litP, int *sizeP)
{
  return ieee_md_atof (type, litP, sizeP, target_big_endian);
}

/* Round up a section size to the appropriate boundary.  */
valueT
md_section_align (segT segment ATTRIBUTE_UNUSED, valueT size)
{
  return size;
}

/* We have no need to default values of symbols.  */
symbolS *
md_undefined_symbol (char *name)
{
  if (!strcmp (name, GLOBAL_OFFSET_TABLE_NAME))
    {
      if (!hexagon_got_symbol)
	{
	  if (symbol_find (name))
	    as_bad (_("GOT already in symbol table."));
	  hexagon_got_symbol
	    = symbol_new (name, undefined_section, 0, &zero_address_frag);
	};
      return hexagon_got_symbol;
    }

  return NULL;
}

#ifdef TARGET_USE_CFIPOP
/* Implement tci_cfi_frame_initial_instructions.  */
void
hexagon_cfi_frame_initial_instructions (void)
{
  /* On hexagon, the CFA is located at fp+#8 */
  /* (Not to be confused with r29 of the previous stack frame) */
  cfi_add_CFA_def_cfa (HEXAGON_FP, 8);

  /* The return address in 4 bytes below the CFA.  */
  cfi_add_CFA_offset (DWARF2_DEFAULT_RETURN_COLUMN, -4);
}

/* Implement tc_regname_to_dw2regnum.  */
int
hexagon_regname_to_dw2regnum (char *regname)
{
  unsigned int regnum = -1;
  unsigned int i;
  const char *p;
  char *q;
  static struct
  {
    char *name;
    int dw2regnum;
  } regnames[] = {
    {"sp", HEXAGON_SP},
    {"fp", HEXAGON_FP},
    {"lr", HEXAGON_LR},
  };

  for (i = 0; i < ARRAY_SIZE (regnames); ++i)
    if (strcmp (regnames[i].name, regname) == 0)
      return regnames[i].dw2regnum;

  if (regname[0] == 'r')
    {
      p = regname + 1;
      regnum = strtoul (p, &q, 10);
      if (p == q || *q || regnum >= 32)
	return -1;
    }

  return regnum;
}
#endif /* TARGET_USE_CFIPOP */


/* Implement Hexagon-specific assembler directives.  */

/* Mark the next packet for .falign.  */
void
hexagon_falign (int ignore ATTRIBUTE_UNUSED)
{
  if (!hexagon_faligning)
    {
      hexagon_faligning = hexagon_fetch_align;
      n_falign[HEXAGON_FALIGN_TOTAL]++;
    }

  demand_empty_rest_of_line ();

  /* Just in case out of .text.  */
  record_alignment (now_seg, DEFAULT_CODE_FALIGN);
}

/* Create a BSS section in the global data area.  */
static segT
hexagon_create_sbss_section (const char *name, flagword flags,
			     unsigned int is_access)
{
  segT current_section = now_seg;
  int current_subsec = now_subseg;
  segT small_section = NULL;
  char small_name[MAX_SMALL_SECTION];

  if (!is_access)
    strcpy (small_name, name);
  else if (snprintf (small_name, MAX_SMALL_SECTION, "%s.%d", name, is_access)
	   >= (int) MAX_SMALL_SECTION)
    return NULL;

  small_section = bfd_get_section_by_name (stdoutput, small_name);
  if (!small_section)
    {
      char *small_section_name;
      symbolS *small_symbol;

      small_section_name = xmalloc (MAX_SMALL_SECTION);
      strcpy (small_section_name, small_name);

      /* Create an sbss section.  */
      small_section = subseg_new (small_section_name, 0);
      bfd_set_section_flags (stdoutput, small_section,
			     flags | (is_access ? SEC_LOAD : 0));
      /* record_alignment (hexagon_small_section, DEFAULT_DATA_ALIGNMENT); */

      small_symbol = symbol_find (small_section_name);
      if (small_symbol)
	symbol_set_bfdsym (small_symbol, small_section->symbol);
      else
	symbol_table_insert (section_symbol (small_section));
    }

  subseg_set (current_section, current_subsec);

  return small_section;
}

/* Create a COMMON section in the global data area.  */
static segT
hexagon_create_scom_section (const char *name, flagword flags,
			     unsigned int is_access)
{
  segT current_section = now_seg;
  int current_subsec = now_subseg;
  segT small_section = NULL;
  asymbol *small_symbol;
  char small_name[MAX_SMALL_SECTION];

  if (!is_access)
    strcpy (small_name, name);
  else if (snprintf (small_name, MAX_SMALL_SECTION, "%s.%d", name, is_access)
	   >= (int) MAX_SMALL_SECTION)
      return NULL;

  small_section = bfd_get_section_by_name (stdoutput, small_name);
  if (!small_section)
    {
      char *small_section_name;

      small_section = xmalloc (sizeof (*small_section));
      small_symbol = xmalloc (sizeof (*small_symbol));
      small_section_name = xmalloc (MAX_SMALL_SECTION);

      strcpy (small_section_name, small_name);

      *small_section = hexagon_scom_section;
      small_section->name = small_section_name;
      small_section->flags |= flags | (is_access ? SEC_LOAD : 0);
      small_section->output_section = small_section;
      small_section->symbol = small_symbol;
      small_section->symbol_ptr_ptr = &small_section->symbol;

      *small_symbol = hexagon_scom_symbol;
      small_symbol->name = small_section_name;
      small_symbol->section = small_section;
    }

  subseg_set (current_section, current_subsec);

  return small_section;
}

/* Helper function for s_comm_internal:  complete parsing of a
   .common-like directive.  */
static symbolS *
hexagon_common_extra (int localScope, symbolS *symbolP, addressT sizearg)
{
  segT old_sec;
  int old_subsec;
  segT new_sec;
  int new_subsec;
  offsetT align, align2, alignb, accsize, temp;
  offsetT size = (offsetT) sizearg;

  assert (symbol_get_frag (symbolP) == &zero_address_frag);

  /* Start assuming that the alignment is 0, i.e.
     use the natural alignment for the symbol size.  */
  align = 0;
  /* Now parse the optional alignment field.  */
  if (*input_line_pointer == ',')
    {
      input_line_pointer++;
      align = get_absolute_expression ();

      if (align < 0)
	{
	  align = 0;
	  as_warn (_("invalid symbol alignment, defaulting to 0."));
	}
    }

  /* Convert alignment to a power of 2,
     if not provided, use the natural size alignment.  */
  temp = align ? align : MIN (size, MAX_DATA_ALIGNMENT);
  align2 = bfd_log2 (temp);
  alignb = 1 << align2;
  if (align && alignb != temp)
    {
      alignb = 1 << ++align2;
      as_warn (_("invalid symbol alignment, defaulting to %ld."),
	       (long) alignb);
    }

  /* Start assuming that the accsize is 0, i.e.
     use the natural access for the symbol size and alignment.  */
  accsize = 0;
  /* Now parse the optional accsize field.  */
  if (*input_line_pointer == ',')
    {
      input_line_pointer++;
      accsize = get_absolute_expression ();

      if (accsize && (accsize < 0 || accsize != (1 << bfd_log2 (accsize))))
	{
	  as_warn (_("invalid symbol access size, defaulting to 0."));
	  accsize = 0;
	}
    }
  if (!accsize)
    accsize = 1 << MIN ((offsetT) bfd_log2 (size), align2);

  if (localScope || symbol_get_obj (symbolP)->local)
    {
      /* Create a local unitialized symbol.  */
      char *pfrag;

      old_sec = now_seg;
      old_subsec = now_subseg;

      /* Check the symbol size against the specified small data limit.  */
      if ((size_t) size > hexagon_gp_size)
	{
	  /* Allocate in .bss.  */
	  new_sec = bss_section;
	  new_subsec = 0;
	}
      else
	{
	  /* Allocate in .sbss.  */
	  new_sec = hexagon_create_sbss_section (SMALL_BSS_SECTION,
						 SEC_ALLOC | SEC_DATA | SEC_SMALL_DATA,
						 hexagon_sort_sda ? accsize : 0);
	  assert (new_sec);
	  seg_info (new_sec)->bss = TRUE;
	  new_subsec = 0;
	}

      record_alignment (new_sec, align2);
      subseg_set (new_sec, new_subsec);

      /* Do alignment unconditionally to ensure we're at the start of
	 a frag.  */
      frag_align (align2, 0, 0);

      /* Detach from old frag.  */
      if (S_GET_SEGMENT (symbolP) == new_sec)
	symbol_get_frag (symbolP)->fr_symbol = NULL;

      symbol_set_frag (symbolP, frag_now);
      pfrag = frag_var (rs_org, 1, 1, 0, symbolP, size, NULL);
      *pfrag = 0;

      S_SET_SIZE (symbolP, size);
      symbol_get_obj (symbolP)->local = localScope;
      S_CLEAR_EXTERNAL (symbolP);
      S_SET_SEGMENT (symbolP, new_sec);

      subseg_set (old_sec, old_subsec);
    }
  else
    {
      /* Create a global unitialized common symbol.  */
      old_sec = now_seg;
      old_subsec = now_subseg;

      /* Check the symbol size against the specified small data limit.  */
      if ((size_t) size > hexagon_gp_size)
	new_sec = bfd_com_section_ptr;
      else
	{
	  new_sec = hexagon_create_scom_section (SMALL_COM_SECTION,
						 SEC_ALLOC | SEC_IS_COMMON
						 | SEC_DATA | SEC_SMALL_DATA,
						 hexagon_sort_sda ? accsize : 0);
	  assert (new_sec);
	}

      /* Create a global common symbol.  */
      S_SET_VALUE (symbolP, (valueT) size);
      S_SET_ALIGN (symbolP, alignb);
      S_SET_EXTERNAL (symbolP);
      S_SET_SEGMENT (symbolP, new_sec);

      subseg_set (old_sec, old_subsec);
    }

  symbol_get_bfdsym (symbolP)->flags |= BSF_OBJECT;

  return symbolP;
}

/* Parse .comm and .lcomm directives.  */
void
hexagon_common (int localScope)
{
  s_comm_internal (localScope, hexagon_common_extra);
}

/* Parse .option directive to select the cpu we're assembling for.  */
void
hexagon_option (int ignore ATTRIBUTE_UNUSED)
{
  int mach;
  char c;
  char *cpu;

  cpu = input_line_pointer;
  c = get_symbol_end ();
  mach = hexagon_get_mach (cpu);
  *input_line_pointer = c;

  /* If an instruction has already been seen, it's too late.  */
  if (cpu_tables_init_p)
    {
      as_bad (_("\".option\" directive must appear before any instructions."));
      ignore_rest_of_line ();
      return;
    }

  if (mach < 0)
    {
      as_bad (_("invalid architecture specified for \".option\"."));
      ignore_rest_of_line ();
      return;
    }
  else if (mach_type_specified_p && mach != hexagon_mach_type)
    {
      as_bad (_("architecture specified for \".option\" conflicts with current setting."));
      ignore_rest_of_line ();
      return;
    }
  else
    {
      /* The cpu may have been selected on the command line.  */
      if (mach != hexagon_mach_type)
	as_warn (_("\".option\" directive overrides default or command-line setting."));
      hexagon_mach_type = mach;

      if (!bfd_set_arch_mach (stdoutput, bfd_arch_hexagon, mach))
	as_fatal (_("assembler internal error."));

      mach_type_specified_p = TRUE;
    }

  demand_empty_rest_of_line ();
  return;
}

/* Parse an operand that is machine-specific.  */
void
md_operand (expressionS *expressionP ATTRIBUTE_UNUSED)
{
  return;
}


/* Functions concerning expressions.  */

static void
hexagon_code_symbol (expressionS *expressionP)
{
  if (expressionP->X_op == O_symbol && expressionP->X_add_number == 0)
    {
      expressionS two;
      expressionP->X_op = O_right_shift;
      expressionP->X_add_symbol->sy_value.X_op = O_constant;
      two.X_op = O_constant;
      two.X_add_symbol = two.X_op_symbol = NULL;
      two.X_add_number = 2;
      expressionP->X_op_symbol = make_expr_symbol (&two);
    }
  /* Allow %st(sym1-sym2)  */
  else if (expressionP->X_op == O_subtract
	   && expressionP->X_add_symbol != NULL
	   && expressionP->X_op_symbol != NULL
	   && expressionP->X_add_number == 0)
    {
      expressionS two;
      expressionP->X_add_symbol = make_expr_symbol (expressionP);
      expressionP->X_op = O_right_shift;
      two.X_op = O_constant;
      two.X_add_symbol = two.X_op_symbol = NULL;
      two.X_add_number = 2;
      expressionP->X_op_symbol = make_expr_symbol (&two);
    }
  else
    {
      as_bad (_("expression too complex."));
      return;
    }
}

/* Implement TC_PARSE_CONS_EXPRESSION to parse a .byte, .word, etc. expression.
   Values for the status register are specified with %st(label).
   `label' will be right shifted by 2.  */
void
hexagon_parse_cons_expression (expressionS *exp,
			       unsigned int nbytes ATTRIBUTE_UNUSED)
{
  char *p = input_line_pointer;
  int code_symbol_fix = 0;

  for (; !is_end_of_line[(unsigned char) *p]; p++)
    if (*p == '@' && !strncmp (p, "@h30", 4))
      {
	code_symbol_fix = 1;
	strcpy (p, ";   ");
      }
  expression (exp);

  if (code_symbol_fix)
    {
      hexagon_code_symbol (exp);
      input_line_pointer = p;
    }
}

/* Implement TC_CONS_FIX_NEW.  */
void
hexagon_cons_fix_new (fragS *frag ATTRIBUTE_UNUSED,
		      int where, int nbytes, expressionS *exp)
{
  bfd_reloc_code_real_type r_type = NO_RELOC;

  switch (nbytes)
    {
    case 1:
      r_type = BFD_RELOC_8;
      break;

    case 2:
      r_type = BFD_RELOC_16;
      break;

    case 4:
      if (exp->X_op == O_subtract
	  && exp->X_add_symbol == hexagon_got_symbol)
	r_type = BFD_RELOC_32_PCREL;
      else
	{
	  char *save = input_line_pointer;
	  r_type = BFD_RELOC_32;
	  /* Handle GOT and PLT expressions.  */
	  if (*save == '@')
	    {
	      hexagon_suffix_type suffix;
	      char *suffix_line = hexagon_parse_suffix (&suffix, NULL);
	      if (suffix_line)
		{
		  expressionS tmp;
		  input_line_pointer = suffix_line;
		  expression (&tmp);
		  exp->X_add_number += tmp.X_add_number;
		  
		  switch (suffix)
		    {
		    case PIC_PCREL:
		      r_type = BFD_RELOC_32_PCREL;
		      break;
		      
		    case PIC_GOT:
		      r_type = BFD_RELOC_HEX_GOT_32;
		      break;
		      
		    case PIC_GOTREL:
		      r_type = BFD_RELOC_32_GOTOFF;
		      break;
		      
		    case TLS_GD_GOT:
		      r_type = BFD_RELOC_HEX_GD_GOT_32;
		      break;
		      
		    case TLS_LD_GOT:
		      r_type = BFD_RELOC_HEX_LD_GOT_32;
		      break;

		    case TLS_IE:
		      r_type = BFD_RELOC_HEX_IE_32;
		      break;
		      
		    case TLS_IE_GOT:
		      r_type = BFD_RELOC_HEX_IE_GOT_32;
		      break;

		    case TLS_DTPREL:
		      r_type = BFD_RELOC_HEX_DTPREL_32;
		      break;

		    case TLS_TPREL:
		      r_type = BFD_RELOC_HEX_TPREL_32;
		      break;

		    default:
		      as_bad (_("unsupported suffix `%s'"), save);
		      break;
		    }
		}

	      while (!is_end_of_line[(unsigned char) *save++])
		;
	      save--;
	    }
	  input_line_pointer = save;
	}
      break;

    case 8:
      r_type = BFD_RELOC_64;
      break;

    default:
      as_bad (_("unsupported BFD relocation size of %u bytes"), nbytes);
      r_type = BFD_RELOC_32;
      break;
    }

  fix_new_exp (frag_now, where, (int) nbytes, exp, 0, r_type);
}


/* Functions concerning relocs and fixups.  */

/* Implement tc_fix_adjustable.
   Allow certain fixups to be adjusted to make them relative to the
   beginning of the section instead of the symbol.  */
int
hexagon_fix_adjustable (fixS *fixP)
{
  /* FIXME: x86-64 adds some other cases here.  */

  /* adjust_reloc_syms doesn't know about PIC or TLS.  */
  switch (fixP->fx_r_type)
    {
      /* PLT */
    case BFD_RELOC_HEX_PLT_B22_PCREL:
      /* GOT */
    case BFD_RELOC_HEX_GOTREL_LO16:
    case BFD_RELOC_HEX_GOTREL_HI16:
    case BFD_RELOC_32_GOTOFF:
    case BFD_RELOC_HEX_GOTREL_32_6_X:
    case BFD_RELOC_HEX_GOTREL_16_X:
    case BFD_RELOC_HEX_GOTREL_11_X:
    case BFD_RELOC_HEX_GOT_LO16:
    case BFD_RELOC_HEX_GOT_HI16:
    case BFD_RELOC_HEX_GOT_32:
    case BFD_RELOC_HEX_GOT_16:
    case BFD_RELOC_HEX_GOT_32_6_X:
    case BFD_RELOC_HEX_GOT_16_X:
    case BFD_RELOC_HEX_GOT_11_X:
      /* TLS */
    case BFD_RELOC_HEX_DTPREL_LO16:
    case BFD_RELOC_HEX_DTPREL_HI16:
    case BFD_RELOC_HEX_DTPREL_32:
    case BFD_RELOC_HEX_DTPREL_16:
    case BFD_RELOC_HEX_DTPREL_32_6_X:
    case BFD_RELOC_HEX_DTPREL_16_X:
    case BFD_RELOC_HEX_DTPREL_11_X:
    case BFD_RELOC_HEX_GD_PLT_B22_PCREL:
    case BFD_RELOC_HEX_LD_PLT_B22_PCREL:
    case BFD_RELOC_HEX_GD_GOT_LO16:
    case BFD_RELOC_HEX_GD_GOT_HI16:
    case BFD_RELOC_HEX_GD_GOT_32:
    case BFD_RELOC_HEX_GD_GOT_16:
    case BFD_RELOC_HEX_GD_GOT_32_6_X:
    case BFD_RELOC_HEX_GD_GOT_16_X:
    case BFD_RELOC_HEX_GD_GOT_11_X:
    case BFD_RELOC_HEX_LD_GOT_LO16:
    case BFD_RELOC_HEX_LD_GOT_HI16:
    case BFD_RELOC_HEX_LD_GOT_32:
    case BFD_RELOC_HEX_LD_GOT_16:
    case BFD_RELOC_HEX_LD_GOT_32_6_X:
    case BFD_RELOC_HEX_LD_GOT_16_X:
    case BFD_RELOC_HEX_LD_GOT_11_X:
    case BFD_RELOC_HEX_IE_LO16:
    case BFD_RELOC_HEX_IE_HI16:
    case BFD_RELOC_HEX_IE_32:
    case BFD_RELOC_HEX_IE_32_6_X:
    case BFD_RELOC_HEX_IE_16_X:
    case BFD_RELOC_HEX_IE_GOT_LO16:
    case BFD_RELOC_HEX_IE_GOT_HI16:
    case BFD_RELOC_HEX_IE_GOT_32:
    case BFD_RELOC_HEX_IE_GOT_16:
    case BFD_RELOC_HEX_IE_GOT_32_6_X:
    case BFD_RELOC_HEX_IE_GOT_16_X:
    case BFD_RELOC_HEX_IE_GOT_11_X:
    case BFD_RELOC_HEX_TPREL_LO16:
    case BFD_RELOC_HEX_TPREL_HI16:
    case BFD_RELOC_HEX_TPREL_32:
    case BFD_RELOC_HEX_TPREL_32_6_X:
    case BFD_RELOC_HEX_TPREL_16_X:
    case BFD_RELOC_HEX_TPREL_11_X:
      return FALSE;

    default:
      return TRUE;
    }
}

/* A PC-relative jump should be calculated from the beginning of the packet.  */
long
md_pcrel_from (fixS *fixP)
{
  return fixP->fx_frag->fr_address + fixP->fx_where + fixP->fx_pcrel_adjust;
}

/* Insert an operand value into an instruction.  */
static void
hexagon_insert_operand (char *where, const hexagon_operand *operand,
			offsetT val, fixS *fixP)
{
  hexagon_insn insn;
  const hexagon_opcode *opcode;
  char *errmsg = NULL;

  if (target_big_endian)
    insn = bfd_getb32 ((unsigned char *) where);
  else
    insn = bfd_getl32 ((unsigned char *) where);

  opcode = hexagon_lookup_insn (insn);
  if (!opcode)
    as_bad (_("opcode not found."));

  if (!hexagon_encode_operand (operand, &insn, opcode, val,
			       operand->flags & HEXAGON_OPERAND_IS_KXED,
			       &errmsg))
    if (errmsg)
      {
	if (fixP && fixP->fx_file)
	  {
	    char tmpError[200];
	    sprintf (tmpError,
		     _(" when resolving symbol in file %s at line %d."),
		     fixP->fx_file, fixP->fx_line);
	    strcat (errmsg, tmpError);
	  }

	as_bad ("%s\n", errmsg);
      }

  if (target_big_endian)
    bfd_putb32 ((bfd_vma) insn, (unsigned char *) where);
  else
    bfd_putl32 ((bfd_vma) insn, (unsigned char *) where);
}

/* Apply a fixup to the object code.  This is called for all the
   fixups we generated by the call to fix_new_exp, above.  In the call
   above we used a reloc code which was the largest legal reloc code
   plus the operand index.  Here we undo that to recover the operand
   index.  At this point all symbol values should be fully resolved,
   and we attempt to completely resolve the reloc.  If we can not do
   that, we determine the correct reloc code and put it back in the fixup.  */
void
md_apply_fix (fixS *fixP, valueT *valP, segT seg)
{
  const hexagon_operand *operand;
  valueT value = *valP;
  char *fixloc;

  /* On a 64-bit host, silently truncate to 32 bits for
     consistency with the behaviour on 32-bit hosts.  Remember value
     for emit_reloc.  */
  value &= 0xffffffff;
  value ^= 0x80000000;
  value -= 0x80000000;
  fixP->fx_addnumber = *valP = value;

  /* Same treatment again.  */
  fixP->fx_offset &= 0xffffffff;
  fixP->fx_offset ^= 0x80000000;
  fixP->fx_offset -= 0x80000000;

  /* We can't actually support subtracting a symbol.  */
  if (fixP->fx_subsy)
    as_bad_where (fixP->fx_file, fixP->fx_line, _("expression too complex."));

  if (!fixP->fx_addsy)
    fixP->fx_done = 1;
  else
    {
      if (fixP->fx_pcrel)
	{
	  /* Symbol is PC-relative.  */
	  if (fixP->fx_r_type == BFD_RELOC_32)
	    fixP->fx_r_type = BFD_RELOC_32_PCREL;

	  /* Hack around bfd_install_relocation brain damage.  */
	  if (S_GET_SEGMENT (fixP->fx_addsy) != seg)
	    value += md_pcrel_from (fixP);
	}
      else
	switch (fixP->fx_r_type)
	  {
	  case BFD_RELOC_HEX_GD_PLT_B22_PCREL:
	  case BFD_RELOC_HEX_LD_PLT_B22_PCREL:
	  case BFD_RELOC_HEX_GD_GOT_LO16:
	  case BFD_RELOC_HEX_GD_GOT_HI16:
	  case BFD_RELOC_HEX_GD_GOT_32:
	  case BFD_RELOC_HEX_GD_GOT_16:
	  case BFD_RELOC_HEX_LD_GOT_LO16:
	  case BFD_RELOC_HEX_LD_GOT_HI16:
	  case BFD_RELOC_HEX_LD_GOT_32:
	  case BFD_RELOC_HEX_LD_GOT_16:
	  case BFD_RELOC_HEX_IE_LO16:
	  case BFD_RELOC_HEX_IE_HI16:
	  case BFD_RELOC_HEX_IE_32:
	  case BFD_RELOC_HEX_IE_GOT_LO16:
	  case BFD_RELOC_HEX_IE_GOT_HI16:
	  case BFD_RELOC_HEX_IE_GOT_32:
	  case BFD_RELOC_HEX_IE_GOT_16:
	  case BFD_RELOC_HEX_DTPREL_LO16:
	  case BFD_RELOC_HEX_DTPREL_HI16:
	  case BFD_RELOC_HEX_DTPREL_32:
	  case BFD_RELOC_HEX_DTPREL_16:
	  case BFD_RELOC_HEX_TPREL_LO16:
	  case BFD_RELOC_HEX_TPREL_HI16:
	  case BFD_RELOC_HEX_TPREL_32:
	  case BFD_RELOC_HEX_TPREL_16:
	    /* Implicitly set type to TLS.  */
	    S_SET_THREAD_LOCAL (fixP->fx_addsy);
	    break;

	  default:
	    break;
	  }
    }

  operand = (hexagon_operand *) fixP->tc_fix_data;
  fixloc = fixP->fx_frag->fr_literal + fixP->fx_where;
  if (operand)
    {
      /* Fetch the instruction, insert the fully resolved operand
         value, and stuff the instruction back again.  */
      if (fixP->fx_done)
	{
	  reloc_howto_type *howto
	    = bfd_reloc_type_lookup (seg->owner,
				     (operand->flags & HEXAGON_OPERAND_IS_KXED
				      ? operand->reloc_kxed
				      : operand->reloc_type));

	  assert (howto);

	  value &= howto->src_mask;
	  hexagon_insert_operand (fixloc, operand, (offsetT) value, fixP);
	}
      else
	/* If any relocation is to be applied later, don't modify
	   the section contents here; we will use the addend in
	   the relocation to fix it up at link time...  */
	hexagon_insert_operand (fixloc, operand, 0, fixP);
    }
  else if (fixP->fx_done)
    {
      switch (fixP->fx_r_type)
	{
	case BFD_RELOC_8:
	  md_number_to_chars (fixloc, value, 1);
	  break;

	case BFD_RELOC_16:
	  md_number_to_chars (fixloc, value, 2);
	  break;

	case BFD_RELOC_32:
	  md_number_to_chars (fixloc, value, 4);
	  break;

	default:
	  {
	    asymbol *sym = symbol_get_bfdsym (fixP->fx_addsy);
	    as_bad_where (fixP->fx_file, fixP->fx_line,
			  _("unknown relocation for symbol `%s'."),
			  sym->name);
	  }
	}
    }
}

/* Translate internal representation of relocation info to BFD target
   format.  */
arelent *
tc_gen_reloc (asection *section ATTRIBUTE_UNUSED, fixS *fixP)
{
  arelent *reloc;

  reloc = xmalloc (sizeof (*reloc));

  reloc->sym_ptr_ptr = (asymbol **) xmalloc (sizeof (*reloc->sym_ptr_ptr));
  *reloc->sym_ptr_ptr = symbol_get_bfdsym (fixP->fx_addsy);
  reloc->address = fixP->fx_frag->fr_address + fixP->fx_where;
  reloc->howto = bfd_reloc_type_lookup (stdoutput, fixP->fx_r_type);
  if (reloc->howto == (reloc_howto_type *) NULL)
    {
      as_fatal (fixP->fx_file, fixP->fx_line,
		_("cannot export relocation type \"%s\"."),
		bfd_get_reloc_code_name (fixP->fx_r_type));
      return NULL;
    }

  assert (fixP->fx_pcrel == reloc->howto->pc_relative);

  /* fixP->fx_offset was not handled in md_apply_fix() so we
     need to propagate it into the (RELA) relocation */
  reloc->addend = fixP->fx_offset;

  return reloc;
}

