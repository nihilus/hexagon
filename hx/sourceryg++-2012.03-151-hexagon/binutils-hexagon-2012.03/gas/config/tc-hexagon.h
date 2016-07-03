/* tc-hexagon.h - Macros and type defines for the Hexagon.
   Copyright 1994, 1995, 1997, 2000, 2001, 2002
   Free Software Foundation, Inc.
   Contributed by Doug Evans (dje@cygnus.com).

   This file is part of GAS, the GNU Assembler.

   GAS is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2,
   or (at your option) any later version.

   GAS is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
   the GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GAS; see the file COPYING.  If not, write to the Free
   Software Foundation, 59 Temple Place - Suite 330, Boston, MA
   02111-1307, USA.  */

#ifndef TC_HEXAGON
#define TC_HEXAGON 1

#define TARGET_BYTES_BIG_ENDIAN 0

#define LOCAL_LABELS_FB 1

#define DIFF_EXPR_OK
#define REGISTER_PREFIX '\0'
#define IMMEDIATE_PREFIX '#'

#ifdef TARGET_IS_LINUX
#define TARGET_FORMAT "elf32-hexagon-linux"
#else
#define TARGET_FORMAT "elf32-littlehexagon"
#endif
#define TARGET_ARCH bfd_arch_hexagon

#define WORKING_DOT_WORD

#define LISTING_HEADER "Hexagon GAS "

#define DOUBLESLASH_LINE_COMMENTS

#define TC_EXTRA_RELAX 1

/* THIS IS A BIG HACK!!!
   We need to look at stuff before and after the ":"
   so we access a variable here that is not passed to the macro
 */
#define TC_START_LABEL(C, B, A) hexagon_start_label (C, B, A)
extern int hexagon_start_label (char c, char *before, char *after);

/* The Hexagon needs to parse reloc specifiers in .word.  */
#define TC_PARSE_CONS_EXPRESSION(EXP, NBYTES) \
  hexagon_parse_cons_expression (EXP, NBYTES)
extern void hexagon_parse_cons_expression (struct expressionS *, unsigned);

#define TC_EQUAL_IN_INSN(C, PTR) (1)

#define GLOBAL_OFFSET_TABLE_NAME "_GLOBAL_OFFSET_TABLE_"
#define NO_RELOC BFD_RELOC_NONE

#define tc_fix_adjustable(X) hexagon_fix_adjustable(X)
extern int hexagon_fix_adjustable (struct fix *);

#define TC_CONS_FIX_NEW(FRAG, WHERE, NBYTES, EXP) \
  hexagon_cons_fix_new (FRAG, WHERE, NBYTES, EXP)
extern void hexagon_cons_fix_new (struct frag *, int, int, struct expressionS *);

#define tc_symbol_chars hexagon_symbol_chars
extern const char hexagon_symbol_chars[];

#define tc_parallel_separator_chars hexagon_parallel_separator_chars
extern const char hexagon_parallel_separator_chars[];

/* Actually a pointer to a hexagon_operand. */
#define TC_FIX_TYPE PTR
#define TC_INIT_FIX_DATA(F) ((F)->tc_fix_data = NULL)

#define TC_FRAG_TYPE struct hexagon_frag_data *
struct hexagon_frag_data;
#define TC_FRAG_INIT(F) hexagon_frag_init (F, NULL)
extern void hexagon_frag_init (fragS *, fragS *);

/* Make sure we don't resolve fixups for PC-relative relocations */
#define TC_FORCE_RELOCATION_LOCAL(FIX) \
  (!(FIX)->fx_pcrel \
   || !HEXAGON_IS_PC_RELATIVE_RELOC ((FIX)->fx_r_type) \
   || TC_FORCE_RELOCATION (FIX))

#define DWARF2_LINE_MIN_INSN_LENGTH 4

/* Values passed to md_apply_fix3 don't include the symbol value.  */
#define MD_APPLY_SYM_VALUE(FIX) 0

#define tc_unrecognized_line(ch) hexagon_unrecognized_line (ch)
extern int hexagon_unrecognized_line (int ch);

#define md_cleanup() hexagon_cleanup ()
extern void hexagon_cleanup (void);

/* This avoids the segments from filling up. */
#define SUB_SEGMENT_ALIGN(S, F) (0)

#define md_do_align(n, fill, len, max, around)	\
{						\
  if ((n) 					\
      && !need_pass_2				\
      && !(fill)				\
      && subseg_text_p (now_seg))		\
  {						\
    frag_align_code ((n), (max));		\
    goto around;				\
  }						\
}

#define HANDLE_ALIGN(fragP)					\
{								\
  if ((fragP)->fr_type == rs_align_code)			\
    hexagon_align_code ((fragP), ((fragP)->fr_next->fr_address	\
				  - (fragP)->fr_address		\
				  - (fragP)->fr_fix));		\
}
extern void hexagon_align_code (fragS *, size_t);

/* #define TC_GENERIC_RELAX_TABLE hexagon_relax_table */
extern const struct relax_type hexagon_relax_table[];

#define md_convert_frag hexagon_convert_frag
extern void hexagon_convert_frag (bfd *, segT, fragS *);
#define md_estimate_size_before_relax hexagon_estimate_size_before_relax
extern int hexagon_estimate_size_before_relax (fragS *, segT);

#define md_relax_frag hexagon_relax_frag
extern long hexagon_relax_frag (segT segment, fragS * fragP, long stretch);

#define md_number_to_chars(buf, val, n)		\
  (target_big_endian				\
   ? number_to_chars_bigendian (buf, val, n)	\
   : number_to_chars_littleendian (buf, val, n))

#define HEXAGON_IS_GP_RELATIVE_RELOC(R) \
  ((R) == BFD_RELOC_HEX_GPREL16_3 \
   || (R) == BFD_RELOC_HEX_GPREL16_2 \
   || (R) == BFD_RELOC_HEX_GPREL16_1 \
   || (R) == BFD_RELOC_HEX_GPREL16_0)

/* Hexagon 7 bit pc-relative branch.
   The lowest 2 bits must be zero and are not stored in the instruction.*/
#define HEXAGON_IS_PC_RELATIVE_RELOC(R) \
   ((R) == BFD_RELOC_HEX_B32_PCREL_X \
    || (R) == BFD_RELOC_HEX_B22_PCREL \
    || (R) == BFD_RELOC_HEX_B22_PCREL_X \
    || (R) == BFD_RELOC_HEX_B15_PCREL \
    || (R) == BFD_RELOC_HEX_B15_PCREL_X \
    || (R) == BFD_RELOC_HEX_B13_PCREL \
    || (R) == BFD_RELOC_HEX_B13_PCREL_X \
    || (R) == BFD_RELOC_HEX_B9_PCREL \
    || (R) == BFD_RELOC_HEX_B9_PCREL_X \
    || (R) == BFD_RELOC_HEX_B7_PCREL)

#ifdef OBJ_ELF

#define md_elf_section_letter hexagon_elf_section_letter
extern bfd_vma hexagon_elf_section_letter (int, char **);
#define md_elf_section_flags hexagon_elf_section_flags
extern flagword hexagon_elf_section_flags (flagword, bfd_vma, int);

#define ELF_TC_SPECIAL_SECTIONS \
  { ".sdata", SHT_PROGBITS, SHF_ALLOC + SHF_WRITE + SHF_HEX_GPREL }, \
  { ".sbss",  SHT_NOBITS,   SHF_ALLOC + SHF_WRITE + SHF_HEX_GPREL },
#endif

/* The upper limit is arbitrarily set to 17 because that is what
   it was in 2.14 */
#define TC_ALIGN_LIMIT 17

/* r31 holds the return address */
#define DWARF2_DEFAULT_RETURN_COLUMN 31

/* Both code and data are aligned on 4-byte boundaries */
#define DWARF2_CIE_DATA_ALIGNMENT   4
#define DWARF2_LINE_MIN_INSN_LENGTH 4

#ifdef TARGET_USE_CFIPOP
/* Enable .cfi_* pseudo-ops for generating unwind info. */
#define tc_regname_to_dw2regnum hexagon_regname_to_dw2regnum
extern int hexagon_regname_to_dw2regnum (char *regname);

#define tc_cfi_frame_initial_instructions hexagon_cfi_frame_initial_instructions
extern void hexagon_cfi_frame_initial_instructions (void);
#endif

#endif /* TC_HEXAGON */
