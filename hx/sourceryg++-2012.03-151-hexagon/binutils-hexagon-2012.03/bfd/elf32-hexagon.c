/* Hexagon-specific support for 32-bit ELF.
   PIC and DSO support based primarily on the CRIS, i386, PPC, x86-64 ports.

   Copyright 1994, 1995, 1997, 1999, 2001, 2002
   Free Software Foundation, Inc.

   This file is part of BFD, the Binary File Descriptor library.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */

#include "bfd.h"
#include "sysdep.h"
#include "bfdlink.h"
#include "libbfd.h"
#include "elf32-hexagon.h"
#include "libiberty.h"
#include "hexagon-isa.h"
#include <assert.h>

#define HEXAGON_TRAMPOLINE_PREFIX     ".L"
#define HEXAGON_TRAMPOLINE_PREFIX_LEN (sizeof (HEXAGON_TRAMPOLINE_PREFIX))
#define HEXAGON_TRAMPOLINE_RANGE(D, B) \
  ((bfd_signed_vma) llabs (D) \
   > (~(~(bfd_signed_vma) 0 << ((B) - 1)) \
      & -(MAX_PACKET_INSNS * HEXAGON_INSN_LEN)))
#define HEXAGON_TRAMPOLINE_NEEDED(R, D) \
  (((R == R_HEX_PLT_B22_PCREL || R == R_HEX_B22_PCREL)		   \
    && HEXAGON_TRAMPOLINE_RANGE (D, 24))			   \
   || ((R == R_HEX_B15_PCREL) && HEXAGON_TRAMPOLINE_RANGE (D, 17)) \
   || ((R == R_HEX_B13_PCREL) && HEXAGON_TRAMPOLINE_RANGE (D, 15)) \
   || ((R == R_HEX_B9_PCREL) && HEXAGON_TRAMPOLINE_RANGE (D, 11)))

/* The name of the dynamic interpreter.  This is put in the .interp section.  */
#define ELF_DYNAMIC_INTERPRETER "/lib/ld.so"

/* The name of the function __tls_get_addr and its transition stubs.  */
#define TLS_GET_ADDR_GD "__tls_get_addr"
#define TLS_GET_ADDR_IE "__hexagon_ie_tls_get_addr"
#define TLS_GET_ADDR_LE "__hexagon_le_tls_get_addr"
/* The name of the single GOT entry for LD TLS variables.  */
#define TLS_GOT_ENTRY_LD "__hexagon_ld_tls_index"

#define PLT_ENTRY_NEW(ABFD) \
  ((bfd_get_arch_info (ABFD))->mach >= bfd_mach_hexagon_v4)

/* Select the PLT template based on the ISA version.  */
#define PLT_ENTRY_TEMP(ABFD) \
  (PLT_ENTRY_NEW (ABFD) ? hexagon_plt_entry_v4 : hexagon_plt_entry_v2)
/* The size of a PLT entry depends on the ISA version.  */
#define PLT_ENTRY_SIZE(ABFD) \
  (PLT_ENTRY_NEW (ABFD) \
   ? sizeof (hexagon_plt_entry_v4) : sizeof (hexagon_plt_entry_v2))

/* Select the template of the PLT first few entries based on the
   ISA version.  */
#define PLT_INITIAL_ENTRY_TEMP(ABFD) \
  (PLT_ENTRY_NEW (ABFD)	\
   ? hexagon_plt_initial_entry_v4 : hexagon_plt_initial_entry_v2)

/* The size of the PLT first few entries reserved for the dynamic linker.  */
#define PLT_INITIAL_ENTRY_LENGTH 12
#define PLT_INITIAL_ENTRY_SIZE   \
  (PLT_INITIAL_ENTRY_LENGTH * HEXAGON_INSN_LEN)

/* The size in bytes of an entry in the GOT, per the ABI.  */
#define GOT_ENTRY_SIZE 4
/* The size of the of the first few GOT entries reserved for the dynamic linker,
   per the ABI.  */
#define GOT_INITIAL_ENTRY_LENGTH 4
#define GOT_INITIAL_ENTRY_SIZE   (GOT_INITIAL_ENTRY_LENGTH * GOT_ENTRY_SIZE)

/* If ELIMINATE_COPY_RELOCS is non-zero, the linker will try to avoid
   copying dynamic variables from a shared lib into an app's dynbss
   section, and instead use a dynamic relocation to point into the
   shared lib.  */
#define ELIMINATE_COPY_RELOCS 1

#define hexagon_hash_entry(E) ((hexagon_link_hash_entry *) (E))
#define hexagon_hash_table(I) ((hexagon_link_hash_table *) ((I)->hash))

/* Compute the output base vma of a section.  */
#define section_base(s) \
  ((s)->output_section->vma + (s)->output_offset)

/* Compute the address of an elf_link_hash_entry object.  */
#define elf_hash_base(h) \
  ((h)->root.u.def.section->output_section->vma	\
   + (h)->root.u.def.section->output_offset)
#define elf_hash_address(h) \
  ((h)->root.u.def.value + elf_hash_base (h))

/* Similarly for a hexagon_link_hash_entry object.  */
#define hexagon_hash_base(h) \
  ((h)->elf.root.u.def.section->output_section->vma	\
   + (h)->elf.root.u.def.section->output_offset)
#define hexagon_hash_address(h) \
  ((h)->elf.root.u.def.value + hexagon_hash_base (h))

static reloc_howto_type *hexagon_elf_reloc_type_lookup
  (bfd * abfd, bfd_reloc_code_real_type code);
static void hexagon_info_to_howto_rel
  (bfd *, arelent *, Elf_Internal_Rela *);
static bfd_boolean hexagon_elf_object_p (bfd *);
static void hexagon_elf_final_write_processing (bfd *, bfd_boolean);
static bfd_reloc_status_type hexagon_elf_reloc
  (bfd *, arelent *, asymbol *, PTR, asection *, bfd *, char **);
static bfd_boolean hexagon_elf_link_output_symbol_hook
  (struct bfd_link_info *, const char *, Elf_Internal_Sym *, asection *,
   struct elf_link_hash_entry *);
static bfd_boolean hexagon_elf_section_from_bfd_section
  (bfd *, asection *, int *);
static void hexagon_elf_symbol_processing (bfd *, asymbol *);
static bfd_boolean hexagon_elf_common_definition (Elf_Internal_Sym *);
static bfd_boolean hexagon_elf_add_symbol_hook
  (bfd *, struct bfd_link_info *, Elf_Internal_Sym *,
   const char **, flagword *, asection **, bfd_vma *);
static bfd_boolean hexagon_elf_section_from_shdr
  (bfd *, Elf_Internal_Shdr *, const char *, int);
static bfd_boolean hexagon_elf_fake_sections
  (bfd *, Elf_Internal_Shdr *, asection *);
static bfd_boolean hexagon_elf_relocate_section
  (bfd *, struct bfd_link_info *, bfd *, asection *, bfd_byte *,
   Elf_Internal_Rela *, Elf_Internal_Sym *, asection **);
static bfd_boolean hexagon_elf_gc_sweep_hook
  (bfd *, struct bfd_link_info *, asection *, const Elf_Internal_Rela *);
static bfd_boolean hexagon_elf_check_relocs
  (bfd *, struct bfd_link_info *, asection *, const Elf_Internal_Rela *);
static bfd_boolean hexagon_elf_relax_section
  (bfd *, asection *, struct bfd_link_info *, bfd_boolean *);
static void hexagon_elf_copy_indirect_symbol
  (struct bfd_link_info *, struct elf_link_hash_entry *,
   struct elf_link_hash_entry *);
static int hexagon_elf_additional_program_headers
  (bfd *, struct bfd_link_info *);
/* PIC & DSO */
static bfd_boolean hexagon_elf_adjust_dynamic_symbol
  (struct bfd_link_info *, struct elf_link_hash_entry *);
static bfd_boolean hexagon_elf_finish_dynamic_symbol
  (bfd *, struct bfd_link_info *, struct elf_link_hash_entry *,
   Elf_Internal_Sym *);
static bfd_boolean hexagon_elf_create_dynamic_sections
  (bfd *, struct bfd_link_info *);
static bfd_boolean hexagon_elf_size_dynamic_sections
  (bfd *, struct bfd_link_info *);
static bfd_boolean hexagon_elf_finish_dynamic_sections
  (bfd *, struct bfd_link_info *);
static enum elf_reloc_type_class hexagon_elf_reloc_type_class
  (const Elf_Internal_Rela *);
static bfd_vma hexagon_elf_plt_sym_val
  (bfd_vma, const asection *, const arelent *);
static bfd_boolean hexagon_elf_hash_symbol (struct elf_link_hash_entry *);
/* TLS */
static bfd_vma hexagon_elf_dtpoff (struct bfd_link_info *, bfd_vma);
static bfd_vma hexagon_elf_tpoff (struct bfd_link_info *, bfd_vma);
void hexagon_elf_check_tls_symbols (bfd *, struct bfd_link_info *);

typedef struct elf_dyn_relocs hexagon_dyn_reloc;

typedef struct _hexagon_link_hash_entry
{
  struct elf_link_hash_entry elf;
  /* Hexagon data.  */
  hexagon_dyn_reloc *dyn_relocs;
  /* Break up of GOT and PLT references, including TLS-specific ones.  */
  struct
  {
    bfd_signed_vma refcount;
  } ok_got, gd_got, gd_plt, ie_got;
} hexagon_link_hash_entry;

#define LGOT_OK(S, N) ((N) + 1 * (S)->sh_info)
#define LGOT_GD(S, N) ((N) + 2 * (S)->sh_info)
#define LGOT_IE(S, N) ((N) + 3 * (S)->sh_info)
#define LPLT_GD(S, N) ((N) + 4 * (S)->sh_info)
#define LGOT_SZ(S)    (      5 * (S)->sh_info)

/* Only GD->IE and LD->LE transitions are supported.  IOW, supporting PIC code
   being linked in a program.

   Unlike other ports, the linker does not patch the code.  Rather, it is left
   unmodified and, instead of calling the actual __tls_get_addr, appropriate
   stubs are created and called.  These stubs, however, require that the
   original dynamic relocations be transitioned to the respective
   executable ones.

   Since Hexagon can execute branches efficiently, the stubs add only 3 (GD->IE)
   or 2 (LD->LE) cycles.  Although possibly not as fast as if code patching was
   used, the difficulty of reshuffling the insns in a packet makes the
   return on the invested implementation effort of the latter alternative
   relatively low.

   This macro can be called before the linker has marked common symbols as
   defined, therefore look for such common symbols explicitly on the
   assumption that they will become defined.

   TODO: should the test include SYMBOL_REFERENCES_LOCAL?
*/
#define TLS_TRANSIT_OK(I, H)						\
  ((I)->executable							\
   && (!(H)								\
       || ((H)								\
	   && (H)->type == STT_TLS					\
	   && ((H)->def_regular						\
	       || (H)->root.type == bfd_link_hash_common		\
	       || (H)->root.type == bfd_link_hash_defined))))

typedef struct _hexagon_link_hash_table
{
  struct elf_link_hash_table elf;
  /* Hexagon data.  */
  /* Shortcuts to get to dynamic linker sections.  */
  struct
  {
    asection *s, *r;
  } bss, sbss;
  struct
  {
    asection *s;
    hexagon_link_hash_entry *h;
  } sda;
  /* Small local symbol to section mapping cache.  */
  struct sym_cache sym_cache;
  /* References to __tls_get_addr.  */
  struct
  {
    bfd_signed_vma refcount;
    /* The actual one, the IE and the LE transition stubs.  */
    hexagon_link_hash_entry *gd_get, *ie_get, *le_get;
  } gd_plt;
  /* References to the LD special-case of tls_index.  */
  struct
  {
    bfd_signed_vma refcount;
    hexagon_link_hash_entry *ld_got;
  } gd_got;
  /* Whether to use trampolines.  */
  bfd_boolean use_trampolines;
} hexagon_link_hash_table;

typedef struct
{
  unsigned r_type, r_hi, r_lo, pc_relative:1;
  bfd_vma entry;		/* Where the trampoline begins.  */
  bfd_vma offset;		/* Where the relocation applies.  */
  bfd_signed_vma addend;	/* Adjust where the relocation applies.  */
  size_t length;
  hexagon_insn insns[16];	/* Actually <length> insns.  */
} hexagon_trampoline;

typedef enum _hexagon_trampoline_type
{
  HEXAGON_TRAMPOLINE_ABS,
  HEXAGON_TRAMPOLINE_PIC,
  HEXAGON_TRAMPOLINE_V4,
  HEXAGON_TRAMPOLINE_MAX
} hexagon_trampoline_type;

#define HEXAGON_TRAMPOLINE_TYPE(INFO, ABFD)		 \
  (bfd_get_mach (ABFD) >= bfd_mach_hexagon_v4 ? HEXAGON_TRAMPOLINE_V4 \
   : (INFO)->shared? HEXAGON_TRAMPOLINE_PIC: HEXAGON_TRAMPOLINE_ABS)

/* The relocation type R_HEX_HL16 is used only internally by the linker.
   So, in order to support different types of trampolines, overload it
   according to the specific type required (e.g., PIC).  */
#define R_HEX_TRAMPOLINE         R_HEX_HL16
#define BFD_RELOC_HEX_TRAMPOLINE BFD_RELOC_HEX_HL16

static const hexagon_trampoline hexagon_trampolines[] = {
  {
   R_HEX_TRAMPOLINE, R_HEX_HI16, R_HEX_LO16, FALSE,
   0, 2 * HEXAGON_INSN_LEN, 0, 7,
   {
    /* This trampoline requires 2 absolute relocations.  */
    0xbffd7f1d,		/* { sp = add (sp, #-8)      */
    0xa79dfcfe,		/*   memw (sp + #-8) = r28 } */
    0x723cc000,		/* r28.h = #HI (foo)         */
    0x713cc000,		/* r28.l = #LO (foo)         */
    0xb01d411d,		/* { sp = add (sp, #8)       */
    0x529c4000,		/*   jumpr r28               */
    0x919dc01c,		/*   r28 = memw (sp) }       */
    }
  },
  {
   R_HEX_TRAMPOLINE, R_HEX_HI16, R_HEX_LO16, TRUE,
   0, 3 * HEXAGON_INSN_LEN, 4, 9,
   {
    /* This trampoline requires 2 PC-relative relocations.  */
    0xbffd7e1d,		/* { r29 = add (sp, #-16)        */
    0xa7ddeefe,		/*   memd (sp + #-16) = r15:14 } */
    0x6a09400f,		/* { r15 = pc                    */
    0x722ec000,		/*   r14.h = #HI (foo@PCREL) }   */
    0x712ec000,		/* r14.l = #LO (foo@PCREL)       */
    0xf30ecf0e,		/* r14 = add (r14, r15)          */
    0xb01d421d,		/* { sp = add (sp, #16)          */
    0x528e4000,		/*  jumpr r14                    */
    0x91ddc00e,		/*  r15:14 = memd (sp) }         */
    }
  },
  {
    R_HEX_TRAMPOLINE, R_HEX_B32_PCREL_X, R_HEX_B22_PCREL_X, TRUE,
    0, 0, 0, 2,
    {
      0x00004000, /*  { immext(#) */
      0x5800c000, /*    jump ## } */
    }
  }
};

/* Reserved entries that are placed at the start of the PLT, used to marshal
   the dynamic linker for lazy binding.  */
static const hexagon_insn
  hexagon_plt_initial_entry_v2[PLT_INITIAL_ENTRY_LENGTH] = {
  0x6a09400f,	/* { r15 = pc                # address of PLT           */
  0x723cc000,	/*   r28.h = #hi (PLT@GOTOFF) }                         */
  0x713cc000,	/* r28.l = #lo (PLT@GOTOFF)  # offset of PLT from GOT0  */
  0xf33ccf1c,	/* r28 = sub (r15, r28)      # address of GOT0          */
  0xe29c420e,	/* { r14 -= add (r28, #16))  # offset of GOTn from GOTa */
  0x919c404f,	/*   r15 = memw (r28 + #8) } # object ID at GOT2        */
  0x919cc03c,	/*   r28 = memw (r28 + #4) } # dynamic link at GOT1     */
  0x8c0e420e,	/* { r14 = asr (r14, #2)     # index of PLTn            */
  0x529cc000,	/*   jumpr r28 }             # call dynamic linker      */
};
static const hexagon_insn
hexagon_plt_initial_entry_v4[PLT_INITIAL_ENTRY_LENGTH] = {
  0x00004000,	/* { immext (#0)                                        */
  0x6a49c01c,	/*   r28 = add (pc, ##GOT0@PCREL) } # address of GOT0   */
  0xe29c420e,	/* { r14 -= add (r28, #16)   # offset of GOTn from GOTa */
  0x919c404f,	/*   r15 = memw (r28 + #8)   # object ID at GOT2        */
  0x919cc03c,	/*   r28 = memw (r28 + #4) } # dynamic link at GOT1     */
  0x8c0e420e,	/* { r14 = asr (r14, #2)     # index of PLTn            */
  0x529cc000,	/*   jumpr r28 }             # call dynamic linker      */
};

/* PLT entries */
static const hexagon_insn hexagon_plt_entry_v2[] = {
  0x6a09400f,	/* { r15 = pc                  # address of PLTn          */
  0x723cc000,	/*   r28.h = #hi (GOTn - PLTn) }                          */
  0x713cc000,	/* r28.l = #lo (GOTn - PLTn)   # offset of GOTn from PLTn */
  0xf30fdc0e,	/* r14 = add (r15, r28)        # address of GOTn          */
  0x918ec01c,	/* r28 = memw (r14)            # contents of GOTn         */
  0x529cc000,	/* jumpr r28                   # call it                  */
};
static const hexagon_insn hexagon_plt_entry_v4[] = {
  0x00004000,	/* { immext (#0)                                       */
  0x6a49c00e,	/*   r14 = add (pc, ##GOTn@PCREL) } # address of GOTn  */
  0x918ec01c,	/* r28 = memw (r14)                 # contents of GOTn */
  0x529cc000,	/* jumpr r28                        # call it          */
};

/* Stub code for getting the address of TLS variables when a GD access
   is transitioned to IE.  */
static const hexagon_insn hexagon_ie_get[] = {
  0x6a0a401c,	/* { r28 = ugp                  # the TP                */
  0x9180c020,	/*   r0 = memw (r0 + #4) }      # offset from the TP    */
  0xf3005c00,	/* { r0 = add (r0, r28)         # address of variable   */
  0x529fc000,	/*   jumpr lr }                 # return it             */
};

/* Stub code for getting the TP when an LD access is transitioned to LE.  */
static const hexagon_insn hexagon_le_get[] = {
  0x6a0a4000,	/* { r0 = ugp                   # the TP                */
  0x529fc000,	/*   jumpr lr }                 # return it             */
};

static reloc_howto_type hexagon_elf_howto_table[] = {
  /* This relocation does nothing.  */
  EMPTY_HOWTO (R_HEX_NONE),
  /* PC-relative 22-bit branch.  */
  HOWTO (R_HEX_B22_PCREL, 2, 2, 24, TRUE, 0, complain_overflow_signed,
	 hexagon_elf_reloc, "R_HEX_B22_PCREL", FALSE, -1L, 0x01ff3ffe, FALSE),
  /* PC-relative 15-bit branch.  */
  HOWTO (R_HEX_B15_PCREL, 2, 2, 17, TRUE, 0, complain_overflow_signed,
	 hexagon_elf_reloc, "R_HEX_B15_PCREL", FALSE, -1L, 0x00df20fe, FALSE),
  /* PC-relative 7-bit branch.  */
  HOWTO (R_HEX_B7_PCREL, 2, 2, 9, TRUE, 0, complain_overflow_signed,
	 hexagon_elf_reloc, "R_HEX_B7_PCREL", FALSE, -1L, 0x00001f18, FALSE),
  /* Low 16-bit of a 32-bit address.  */
  HOWTO (R_HEX_LO16, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_LO16", FALSE, -1L, 0x00c03fff, FALSE),
  /* High 16-bit of a 32-bit address.  */
  HOWTO (R_HEX_HI16, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_HI16", FALSE, -1L, 0x00c03fff, FALSE),
  /* 32-bit address.  */
  HOWTO (R_HEX_32, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 bfd_elf_generic_reloc, "R_HEX_32", FALSE, 0, 0xffffffff, FALSE),
  /* 16-bit address.  */
  HOWTO (R_HEX_16, 0, 1, 16, FALSE, 0, complain_overflow_bitfield,
	 bfd_elf_generic_reloc, "R_HEX_16", FALSE, 0, 0xffff, FALSE),
  /* 8-bit address.  */
  HOWTO (R_HEX_8, 0, 0, 8, FALSE, 0, complain_overflow_bitfield,
	 bfd_elf_generic_reloc, "R_HEX_8", FALSE, 0, 0xff, FALSE),
  /* GP-relative offset for bytes.  */
  HOWTO (R_HEX_GPREL16_0, 0, 2, 16, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_GPREL16_0", FALSE, -1L, 0x061f2ff, FALSE),
  /* GP-relative offset for half-words.  */
  HOWTO (R_HEX_GPREL16_1, 1, 2, 17, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_GPREL16_1", FALSE, -1L, 0x061f2ff, FALSE),
  /* GP-relative offset for words.  */
  HOWTO (R_HEX_GPREL16_2, 2, 2, 18, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_GPREL16_2", FALSE, -1L, 0x061f2ff, FALSE),
  /* GP-relative offset for double-words.  */
  HOWTO (R_HEX_GPREL16_3, 3, 2, 19, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_GPREL16_3", FALSE, -1L, 0x061f2ff, FALSE),
  /* High and low 16-bit of a 32-bit number applied to 2 insns
     back-to-back.   Or const extender and jump.  */
  HOWTO (R_HEX_TRAMPOLINE, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_TRAMPOLINE", FALSE, -1L, 0x00c03fff,
	 FALSE),
  /* PC-relative 13-bit branch.  */
  HOWTO (R_HEX_B13_PCREL, 2, 2, 15, TRUE, 0, complain_overflow_signed,
	 hexagon_elf_reloc, "R_HEX_B13_PCREL", FALSE, -1L, 0x00202ffe, FALSE),
  /* PC-relative 9-bit branch.  */
  HOWTO (R_HEX_B9_PCREL, 2, 2, 11, TRUE, 0, complain_overflow_signed,
	 hexagon_elf_reloc, "R_HEX_B9_PCREL", FALSE, -1L, 0x00c000ff, FALSE),
  /* PC-relative 32-bit extended branch.  */
  HOWTO (R_HEX_B32_PCREL_X, 6, 2, 32, TRUE, 0, complain_overflow_signed,
	 hexagon_elf_reloc, "R_HEX_B32_PCREL_X", FALSE, ~0x3f, 0x0fff3fff,
	 FALSE),
  /* Extended 32-bit address.  */
  HOWTO (R_HEX_32_6_X, 6, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_32_6_X", FALSE, ~0x3f, 0x0fff3fff, FALSE),
  /* Extended PC-relative 22-bit branch.  */
  HOWTO (R_HEX_B22_PCREL_X, 2, 2, 6, TRUE, 0, complain_overflow_signed,
	 hexagon_elf_reloc, "R_HEX_B22_PCREL_X", FALSE, 0x3f, 0x01ff3ffe,
	 FALSE),
  /* Extended PC-relative 15-bit branch.  */
  HOWTO (R_HEX_B15_PCREL_X, 2, 2, 6, TRUE, 0, complain_overflow_signed,
	 hexagon_elf_reloc, "R_HEX_B15_PCREL_X", FALSE, 0x3f, 0x00df20fe,
	 FALSE),
  /* An extended relative 13-bit branch.  */
  HOWTO (R_HEX_B13_PCREL_X, 2, 2, 6, TRUE, 0, complain_overflow_signed,
	 hexagon_elf_reloc, "R_HEX_B13_PCREL_X", FALSE, 0x3f, 0x00202ffe,
	 FALSE),
  /* Extended PC-relative 9-bit branch.  */
  HOWTO (R_HEX_B9_PCREL_X, 2, 2, 6, TRUE, 0, complain_overflow_signed,
	 hexagon_elf_reloc, "R_HEX_B9_PCREL_X", FALSE, 0x3f, 0x00c000ff,
	 FALSE),
  /* Extended PC-relative 7-bit branch.  */
  HOWTO (R_HEX_B7_PCREL_X, 2, 2, 6, TRUE, 0, complain_overflow_signed,
	 hexagon_elf_reloc, "R_HEX_B7_PCREL_X", FALSE, 0x3f, 0x00001f18,
	 FALSE),
  /* Extended signed 16-bit address.  */
  HOWTO (R_HEX_16_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_16_X", FALSE, 0x3f, 0, FALSE),
  /* Extended signed 12-bit address.  */
  HOWTO (R_HEX_12_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_12_X", FALSE, 0, 0, FALSE),
  /* Extended 11-bit address for bytes.  */
  HOWTO (R_HEX_11_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_11_X", FALSE, 0x3f, 0, FALSE),
  /* Extended signed 10-bit address.  */
  HOWTO (R_HEX_10_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_10_X", FALSE, 0x3f, 0, FALSE),
  /* Extended signed 9-bit address.  */
  HOWTO (R_HEX_9_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_9_X", FALSE, 0x3f, 0, FALSE),
  /* Extended signed 8-bit address.  */
  HOWTO (R_HEX_8_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_8_X", FALSE, 0x3f, 0, FALSE),
  /* Extended signed 7-bit address.  */
  HOWTO (R_HEX_7_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_7_X", FALSE, 0x3f, 0, FALSE),
  /* Extended signed 6-bit address.  */
  HOWTO (R_HEX_6_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_6_X", FALSE, 0x3f, 0, FALSE),
  /* 32-bit PC-relative address.  */
  HOWTO (R_HEX_32_PCREL, 0, 2, 32, TRUE, 0, complain_overflow_bitfield,
	 bfd_elf_generic_reloc, "R_HEX_32_PCREL", FALSE, 0, 0xffffffff, TRUE),
  /* Copy initial value from DSO.  */
  HOWTO (R_HEX_COPY, 0, 2, 32, FALSE, 0, complain_overflow_dont,
	 bfd_elf_generic_reloc, "R_HEX_COPY", FALSE, 0, 0xffffffff, FALSE),
  /* GOT entry.  */
  HOWTO (R_HEX_GLOB_DAT, 0, 2, 32, FALSE, 0, complain_overflow_dont,
	 bfd_elf_generic_reloc, "R_HEX_GLOB_DAT", FALSE, 0, 0xffffffff,
	 FALSE),
  /* GOT entry for a PLT entry.  */
  HOWTO (R_HEX_JMP_SLOT, 0, 2, 32, FALSE, 0, complain_overflow_dont,
	 bfd_elf_generic_reloc, "R_HEX_JMP_SLOT", FALSE, 0, 0xffffffff,
	 FALSE),
  /* 32-bit image-relative address.  */
  HOWTO (R_HEX_RELATIVE, 0, 2, 32, FALSE, 0, complain_overflow_dont,
	 bfd_elf_generic_reloc, "R_HEX_RELATIVE", FALSE, 0, 0xffffffff,
	 FALSE),
  /* PC-relative 22-bit branch to a PLT entry.  */
  HOWTO (R_HEX_PLT_B22_PCREL, 2, 2, 22, TRUE, 0, complain_overflow_signed,
	 hexagon_elf_reloc, "R_HEX_PLT_B22_PCREL", FALSE, 0, 0x01ff3ffe,
	 FALSE),
  /* Low 16-bit of a 32-bit offset from GOT.  */
  HOWTO (R_HEX_GOTREL_LO16, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_GOTREL_LO16", FALSE, 0, 0x00c03fff, FALSE),
  /* High 16-bit of a 32-bit offset from GOT.  */
  HOWTO (R_HEX_GOTREL_HI16, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_GOTREL_HI16", FALSE, 0, 0x00c03fff, FALSE),
  /* 32-bit offset from GOT.  */
  HOWTO (R_HEX_GOTREL_32, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 bfd_elf_generic_reloc, "R_HEX_GOTREL_32", FALSE, 0, 0xffffffff,
	 FALSE),
  /* Low 16-bit of a 32-bit offset of a GOT entry.  */
  HOWTO (R_HEX_GOT_LO16, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_GOT_LO16", FALSE, 0, 0x00c03fff, FALSE),
  /* High 16-bit of a 32-bit offset of a GOT entry.  */
  HOWTO (R_HEX_GOT_HI16, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_GOT_HI16", FALSE, 0, 0x00c03fff, FALSE),
  /* 32-bit offset of a GOT entry.  */
  HOWTO (R_HEX_GOT_32, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 bfd_elf_generic_reloc, "R_HEX_GOT_32", FALSE, 0, 0xffffffff, FALSE),
  /* 16-bit offset of a GOT entry.  */
  HOWTO (R_HEX_GOT_16, 0, 2, 16, FALSE, 0, complain_overflow_signed,
	 hexagon_elf_reloc, "R_HEX_GOT_16", FALSE, 0, 0x00c03fff, FALSE),
  /* 32-bit TLS module ID.  */
  HOWTO (R_HEX_DTPMOD_32, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 bfd_elf_generic_reloc, "R_HEX_DTPMOD_32", FALSE, 0, 0xffffffff,
	 FALSE),
  /* Low 16-bit of a 32-bit TLS symbol offset.  */
  HOWTO (R_HEX_DTPREL_LO16, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_DTPREL_LO16", FALSE, 0, 0x00c03fff, FALSE),
  /* High 16-bit of a 32-bit TLS symbol offset.  */
  HOWTO (R_HEX_DTPREL_HI16, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_DTPREL_HI16", FALSE, 0, 0x00c03fff, FALSE),
  /* 32-bit TLS symbol offset.  */
  HOWTO (R_HEX_DTPREL_32, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 bfd_elf_generic_reloc, "R_HEX_DTPREL_32", FALSE, 0, 0xffffffff,
	 FALSE),
  /* 16-bit TLS symbol offset.  */
  HOWTO (R_HEX_DTPREL_16, 0, 2, 16, FALSE, 0, complain_overflow_signed,
	 hexagon_elf_reloc, "R_HEX_DTPREL_16", FALSE, 0, 0x00c03fff, FALSE),
  /* PC-relative 22-bit branch to the TLS PLT entry.  */
  HOWTO (R_HEX_GD_PLT_B22_PCREL, 2, 2, 22, TRUE, 0, complain_overflow_signed,
	 hexagon_elf_reloc, "R_HEX_GD_PLT_B22_PCREL", FALSE, 0, 0x01ff3ffe,
	 FALSE),
  /* Low 16-bit of a 32-bit offset of GOT entries for a TLS GD descriptor.  */
  HOWTO (R_HEX_GD_GOT_LO16, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_GD_GOT_LO16", FALSE, 0, 0x00c03fff, FALSE),
  /* High 16-bit of a 32-bit offset of GOT entries for a TLS GD descriptor.  */
  HOWTO (R_HEX_GD_GOT_HI16, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_GD_GOT_HI16", FALSE, 0, 0x00c03fff, FALSE),
  /* 32-bit offset of GOT entries for a TLS GD descriptor.  */
  HOWTO (R_HEX_GD_GOT_32, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 bfd_elf_generic_reloc, "R_HEX_GD_GOT_32", FALSE, 0, 0xffffffff,
	 FALSE),
  /* 16-bit offset of GOT entries for a TLS GD descriptor.  */
  HOWTO (R_HEX_GD_GOT_16, 0, 2, 16, FALSE, 0, complain_overflow_signed,
	 hexagon_elf_reloc, "R_HEX_GD_GOT_16", FALSE, 0, 0x00c03fff, FALSE),
  /* Low 16-bit of a 32-bit address of a GOT entry for a TLS IE symbol.  */
  HOWTO (R_HEX_IE_LO16, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_IE_LO16", FALSE, 0, 0x00c03fff, FALSE),
  /* High 16-bit of a 32-bit address of GOT entry for a TLS IE symbol.  */
  HOWTO (R_HEX_IE_HI16, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_IE_HI16", FALSE, 0, 0x00c03fff, FALSE),
  /* 32-bit address of GOT entry for a TLS IE symbol.  */
  HOWTO (R_HEX_IE_32, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 bfd_elf_generic_reloc, "R_HEX_IE_32", FALSE, 0, 0xffffffff, FALSE),
  /* Low 16-bit of a 32-bit offset of a GOT entry for a TLS IE symbol.  */
  HOWTO (R_HEX_IE_GOT_LO16, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_IE_GOT_LO16", FALSE, 0, 0x00c03fff, FALSE),
  /* High 16-bit of a 32-bit offset of a GOT entry for a TLS IE symbol.  */
  HOWTO (R_HEX_IE_GOT_HI16, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_IE_GOT_HI16", FALSE, 0, 0x00c03fff, FALSE),
  /* 32-bit offset of GOT entry for a TLS IE symbol.  */
  HOWTO (R_HEX_IE_GOT_32, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 bfd_elf_generic_reloc, "R_HEX_IE_GOT_32", FALSE, 0, 0xffffffff,
	 FALSE),
  /* 16-bit offset of GOT entry for a TLS IE symbol.  */
  HOWTO (R_HEX_IE_GOT_16, 0, 2, 16, FALSE, 0, complain_overflow_signed,
	 hexagon_elf_reloc, "R_HEX_IE_GOT_16", FALSE, 0, 0x00c03fff, FALSE),
  /* Low 16-bit of a 32-bit offset from the TP.  */
  HOWTO (R_HEX_TPREL_LO16, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_TPREL_LO16", FALSE, 0, 0x00c03fff, FALSE),
  /* High 16-bit of a 32-bit offset from the TP.  */
  HOWTO (R_HEX_TPREL_HI16, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_TPREL_HI16", FALSE, 0, 0x00c03fff, FALSE),
  /* 32-bit offset from the TP.  */
  HOWTO (R_HEX_TPREL_32, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 bfd_elf_generic_reloc, "R_HEX_TPREL_32", FALSE, 0, 0xffffffff,
	 FALSE),
  /* 16-bit offset from the TP.  */
  HOWTO (R_HEX_TPREL_16, 0, 2, 16, FALSE, 0, complain_overflow_signed,
	 hexagon_elf_reloc, "R_HEX_TPREL_16", FALSE, 0, 0x00c03fff, FALSE),
  /* Extended 6-bit PC-relative address.  */
  HOWTO (R_HEX_6_PCREL_X, 0, 2, 6, TRUE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_6_PCREL_X", FALSE, 0x3f, 0, TRUE),
  /* Extended 32-bit offset from GOT.  */
  HOWTO (R_HEX_GOTREL_32_6_X, 6, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_GOTREL_32_6_X", FALSE, ~0x3f, 0x0fff3fff,
	 FALSE),
  /* Extended signed 16-bit offset from GOT.  */
  HOWTO (R_HEX_GOTREL_16_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_GOTREL_16_X", FALSE, 0x3f, 0, FALSE),
  /* Extended signed 11-bit offset from GOT.  */
  HOWTO (R_HEX_GOTREL_11_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_GOTREL_11_X", FALSE, 0x3f, 0, FALSE),
  /* Extended 32-bit offset of a GOT entry.  */
  HOWTO (R_HEX_GOT_32_6_X, 6, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_GOT_32_6_X", FALSE, ~0x3f, 0x0fff3fff,
	 FALSE),
  /* Extended signed 16-bit offset of a GOT entry.  */
  HOWTO (R_HEX_GOT_16_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_GOT_16_X", FALSE, 0x3f, 0, FALSE),
  /* Extended signed 11-bit offset of a GOT entry.  */
  HOWTO (R_HEX_GOT_11_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_GOT_11_X", FALSE, 0x3f, 0, FALSE),
  /* Extended 32-bit TLS symbol offset.  */
  HOWTO (R_HEX_DTPREL_32_6_X, 6, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_DTPREL_32_6_X", FALSE, ~0x3f, 0x0fff3fff,
	 FALSE),
  /* Extended signed 16-bit TLS symbol offset.  */
  HOWTO (R_HEX_DTPREL_16_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_DTPREL_16_X", FALSE, 0x3f, 0, FALSE),
  /* Extended signed 11-bit TLS symbol offset.  */
  HOWTO (R_HEX_DTPREL_11_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_DTPREL_11_X", FALSE, 0x3f, 0, FALSE),
  /* Extended 32-bit offset of GOT entries for a TLS GD descriptor.  */
  HOWTO (R_HEX_GD_GOT_32_6_X, 6, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_GD_GOT_32_6_X", FALSE, ~0x3f, 0x0fff3fff,
	 FALSE),
  /* Extended signed 16-bit offset of GOT entries for a TLS GD descriptor.  */
  HOWTO (R_HEX_GD_GOT_16_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_GD_GOT_16_X", FALSE, 0x3f, 0, FALSE),
  /* Extended signed 11-bit offset of GOT entries for a TLS GD descriptor.  */
  HOWTO (R_HEX_GD_GOT_11_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_GD_GOT_11_X", FALSE, 0x3f, 0, FALSE),
  /* Extended 32-bit address of GOT entry for a TLS IE symbol.  */
  HOWTO (R_HEX_IE_32_6_X, 6, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_IE_32_6_X", FALSE, ~0x3f, 0x0fff3fff,
	 FALSE),
  /* Extended 16-bit address of GOT entry for a TLS IE symbol.  */
  HOWTO (R_HEX_IE_16_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_IE_16_X", FALSE, 0x3f, 0, FALSE),
  /* Extended 32-bit offset of a GOT entry for a TLS IE symbol.  */
  HOWTO (R_HEX_IE_GOT_32_6_X, 6, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_IE_GOT_32_6_X", FALSE, ~0x3f, 0x0fff3fff,
	 FALSE),
  /* Extended signed 16-bit offset of a GOT entry for a TLS IE symbol.  */
  HOWTO (R_HEX_IE_GOT_16_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_IE_GOT_16_X", FALSE, 0x3f, 0, FALSE),
  /* Extended signed 11-bit offset of a GOT entry for a TLS IE symbol.  */
  HOWTO (R_HEX_IE_GOT_11_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_IE_GOT_11_X", FALSE, 0x3f, 0, FALSE),
  /* Extended 32-bit offset from the TP.  */
  HOWTO (R_HEX_TPREL_32_6_X, 6, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_TPREL_32_6_X", FALSE, ~0x3f, 0x0fff3fff,
	 FALSE),
  /* Extended signed 16-bit offset from the TP.  */
  HOWTO (R_HEX_TPREL_16_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_TPREL_16_X", FALSE, 0x3f, 0, FALSE),
  /* Extended signed 11-bit offset from the TP.  */
  HOWTO (R_HEX_TPREL_11_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_TPREL_11_X", FALSE, 0x3f, 0, FALSE),
  /* PC-relative 22-bit branch to the TLS PLT entry.  */
  HOWTO (R_HEX_LD_PLT_B22_PCREL, 2, 2, 22, TRUE, 0, complain_overflow_signed,
	 hexagon_elf_reloc, "R_HEX_LD_PLT_B22_PCREL", FALSE, 0, 0x01ff3ffe,
	 FALSE),
  /* Low 16-bit of a 32-bit offset of GOT entries for a TLS GD descriptor.  */
  HOWTO (R_HEX_LD_GOT_LO16, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_LD_GOT_LO16", FALSE, 0, 0x00c03fff, FALSE),
  /* High 16-bit of a 32-bit offset of GOT entries for a TLS GD descriptor.  */
  HOWTO (R_HEX_LD_GOT_HI16, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_LD_GOT_HI16", FALSE, 0, 0x00c03fff, FALSE),
  /* 32-bit offset of GOT entries for a TLS GD descriptor.  */
  HOWTO (R_HEX_LD_GOT_32, 0, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 bfd_elf_generic_reloc, "R_HEX_LD_GOT_32", FALSE, 0, 0xffffffff,
	 FALSE),
  /* 16-bit offset of GOT entries for a TLS GD descriptor.  */
  HOWTO (R_HEX_LD_GOT_16, 0, 2, 16, FALSE, 0, complain_overflow_signed,
	 hexagon_elf_reloc, "R_HEX_LD_GOT_16", FALSE, 0, 0x00c03fff, FALSE),
  /* Extended 32-bit offset of GOT entries for a TLS GD descriptor.  */
  HOWTO (R_HEX_LD_GOT_32_6_X, 6, 2, 32, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_LD_GOT_32_6_X", FALSE, ~0x3f, 0x0fff3fff,
	 FALSE),
  /* Extended signed 16-bit offset of GOT entries for a TLS GD descriptor.  */
  HOWTO (R_HEX_LD_GOT_16_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_LD_GOT_16_X", FALSE, 0x3f, 0, FALSE),
  /* Extended signed 11-bit offset of GOT entries for a TLS GD descriptor.  */
  HOWTO (R_HEX_LD_GOT_11_X, 0, 2, 6, FALSE, 0, complain_overflow_bitfield,
	 hexagon_elf_reloc, "R_HEX_LD_GOT_11_X", FALSE, 0x3f, 0, FALSE),
};

/* Returns true if R_TYPE is a GD_GOT relocation.  */

static bfd_boolean
is_gd_rel (unsigned int r_type)
{
  switch (r_type)
    {
    case R_HEX_GD_GOT_LO16:
    case R_HEX_GD_GOT_HI16:
    case R_HEX_GD_GOT_32:
    case R_HEX_GD_GOT_16:
    case R_HEX_GD_GOT_32_6_X:
    case R_HEX_GD_GOT_16_X:
    case R_HEX_GD_GOT_11_X:
    case R_HEX_GD_PLT_B22_PCREL:
      return TRUE;
    default:
      return FALSE;
    }
}

/* Returns true if R_TYPE is a LD_GOT relocation.  */

static bfd_boolean
is_ld_rel (unsigned int r_type)
{
  switch (r_type)
    {
    case R_HEX_LD_GOT_LO16:
    case R_HEX_LD_GOT_HI16:
    case R_HEX_LD_GOT_32:
    case R_HEX_LD_GOT_16:
    case R_HEX_LD_GOT_32_6_X:
    case R_HEX_LD_GOT_16_X:
    case R_HEX_LD_GOT_11_X:
    case R_HEX_LD_PLT_B22_PCREL:
      return TRUE;
    default:
      return FALSE;
    }
}

/* Hexagon ELF uses two common sections.  One is the usual one, and the
   other is for small objects.  All the small objects are kept
   together, and then referenced via the GP-register, which yields
   faster assembler code.  This is what we use for the small common
   section.  This approach is copied from ecoff.c.  */
#define N_SHN_HEX_SCOMMON SHN_HEX_SCOMMON_8 - SHN_HEX_SCOMMON + 1

static asection hexagon_scom_section[N_SHN_HEX_SCOMMON];
static asymbol hexagon_scom_symbol[N_SHN_HEX_SCOMMON];
static const char *hexagon_scom_name[N_SHN_HEX_SCOMMON]
= {".scommon", ".scommon.1", ".scommon.2", ".scommon.4", ".scommon.8"};

#define HEXAGON_SCOM_SECTION(shn) \
  hexagon_scom_section[(shn) - SHN_HEX_SCOMMON]
#define HEXAGON_SCOM_SYMBOL(shn) \
  hexagon_scom_symbol[(shn) - SHN_HEX_SCOMMON]
#define HEXAGON_SCOM_NAME(shn) \
  hexagon_scom_name[(shn) - SHN_HEX_SCOMMON]

/* Map BFD reloc types to Hexagon ELF reloc types.  */

struct hexagon_reloc_map
{
  bfd_reloc_code_real_type bfd_reloc_val;
  unsigned int elf_reloc_val;
  int operand_flag;
};

static const struct hexagon_reloc_map hexagon_reloc_map[] = {
  {BFD_RELOC_NONE, R_HEX_NONE, 0},
  {BFD_RELOC_HEX_B32_PCREL_X, R_HEX_B32_PCREL_X, 0},	/* K-ext */
  {BFD_RELOC_HEX_B22_PCREL, R_HEX_B22_PCREL, 0},
  {BFD_RELOC_HEX_B22_PCREL_X, R_HEX_B22_PCREL_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_B15_PCREL, R_HEX_B15_PCREL, 0},
  {BFD_RELOC_HEX_B15_PCREL_X, R_HEX_B15_PCREL_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_B13_PCREL, R_HEX_B13_PCREL, 0},
  {BFD_RELOC_HEX_B13_PCREL_X, R_HEX_B13_PCREL_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_B9_PCREL, R_HEX_B9_PCREL, 0},
  {BFD_RELOC_HEX_B9_PCREL_X, R_HEX_B9_PCREL_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_B7_PCREL, R_HEX_B7_PCREL, 0},
  {BFD_RELOC_HEX_B7_PCREL_X, R_HEX_B7_PCREL_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_LO16, R_HEX_LO16, 0},
  {BFD_RELOC_HEX_HI16, R_HEX_HI16, 0},
  {BFD_RELOC_HEX_TRAMPOLINE, R_HEX_TRAMPOLINE, 0},
  {BFD_RELOC_HEX_32_6_X, R_HEX_32_6_X, 0},	/* K-ext */
  {BFD_RELOC_32_PCREL, R_HEX_32_PCREL, 0},
  {BFD_RELOC_32, R_HEX_32, 0},
  {BFD_RELOC_16, R_HEX_16, 0},
  {BFD_RELOC_8, R_HEX_8, 0},
  {BFD_RELOC_HEX_16_X, R_HEX_16_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_12_X, R_HEX_12_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_11_X, R_HEX_11_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_10_X, R_HEX_10_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_9_X, R_HEX_9_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_8_X, R_HEX_8_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_7_X, R_HEX_7_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_6_X, R_HEX_6_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_6_PCREL_X, R_HEX_6_PCREL_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_GPREL16_0, R_HEX_GPREL16_0, 0},
  {BFD_RELOC_HEX_GPREL16_1, R_HEX_GPREL16_1, 0},
  {BFD_RELOC_HEX_GPREL16_2, R_HEX_GPREL16_2, 0},
  {BFD_RELOC_HEX_GPREL16_3, R_HEX_GPREL16_3, 0},
  /* DSO */
  {BFD_RELOC_HEX_COPY, R_HEX_COPY, 0},
  {BFD_RELOC_HEX_GLOB_DAT, R_HEX_GLOB_DAT, 0},
  {BFD_RELOC_HEX_JMP_SLOT, R_HEX_JMP_SLOT, 0},
  {BFD_RELOC_HEX_RELATIVE, R_HEX_RELATIVE, 0},
  /* PLT */
  {BFD_RELOC_HEX_PLT_B22_PCREL, R_HEX_PLT_B22_PCREL, 0},
  /* GOT */
  {BFD_RELOC_HEX_GOTREL_LO16, R_HEX_GOTREL_LO16, 0},
  {BFD_RELOC_HEX_GOTREL_HI16, R_HEX_GOTREL_HI16, 0},
  {BFD_RELOC_32_GOTOFF, R_HEX_GOTREL_32, 0},
  {BFD_RELOC_HEX_GOTREL_32_6_X, R_HEX_GOTREL_32_6_X, 0},	/* K-ext */
  {BFD_RELOC_HEX_GOTREL_16_X, R_HEX_GOTREL_16_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_GOTREL_11_X, R_HEX_GOTREL_11_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_GOT_LO16, R_HEX_GOT_LO16, 0},
  {BFD_RELOC_HEX_GOT_HI16, R_HEX_GOT_HI16, 0},
  {BFD_RELOC_HEX_GOT_32, R_HEX_GOT_32, 0},
  {BFD_RELOC_HEX_GOT_16, R_HEX_GOT_16, 0},
  {BFD_RELOC_HEX_GOT_32_6_X, R_HEX_GOT_32_6_X, 0},	/* K-ext */
  {BFD_RELOC_HEX_GOT_16_X, R_HEX_GOT_16_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_GOT_11_X, R_HEX_GOT_11_X, HEXAGON_OPERAND_IS_KXED},
  /* TLS */
  {BFD_RELOC_HEX_DTPMOD_32, R_HEX_DTPMOD_32, 0},
  {BFD_RELOC_HEX_DTPREL_LO16, R_HEX_DTPREL_LO16, 0},
  {BFD_RELOC_HEX_DTPREL_HI16, R_HEX_DTPREL_HI16, 0},
  {BFD_RELOC_HEX_DTPREL_32, R_HEX_DTPREL_32, 0},
  {BFD_RELOC_HEX_DTPREL_16, R_HEX_DTPREL_16, 0},
  {BFD_RELOC_HEX_DTPREL_32_6_X, R_HEX_DTPREL_32_6_X, 0},	/* K-ext */
  {BFD_RELOC_HEX_DTPREL_16_X, R_HEX_DTPREL_16_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_DTPREL_11_X, R_HEX_DTPREL_11_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_GD_PLT_B22_PCREL, R_HEX_GD_PLT_B22_PCREL, 0},
  {BFD_RELOC_HEX_LD_PLT_B22_PCREL, R_HEX_LD_PLT_B22_PCREL, 0},
  {BFD_RELOC_HEX_GD_GOT_LO16, R_HEX_GD_GOT_LO16, 0},
  {BFD_RELOC_HEX_GD_GOT_HI16, R_HEX_GD_GOT_HI16, 0},
  {BFD_RELOC_HEX_GD_GOT_32, R_HEX_GD_GOT_32, 0},
  {BFD_RELOC_HEX_GD_GOT_16, R_HEX_GD_GOT_16, 0},
  {BFD_RELOC_HEX_GD_GOT_32_6_X, R_HEX_GD_GOT_32_6_X, 0},	/* K-ext */
  {BFD_RELOC_HEX_GD_GOT_16_X, R_HEX_GD_GOT_16_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_GD_GOT_11_X, R_HEX_GD_GOT_11_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_LD_GOT_LO16, R_HEX_LD_GOT_LO16, 0},
  {BFD_RELOC_HEX_LD_GOT_HI16, R_HEX_LD_GOT_HI16, 0},
  {BFD_RELOC_HEX_LD_GOT_32, R_HEX_LD_GOT_32, 0},
  {BFD_RELOC_HEX_LD_GOT_16, R_HEX_LD_GOT_16, 0},
  {BFD_RELOC_HEX_LD_GOT_32_6_X, R_HEX_LD_GOT_32_6_X, 0},	/* K-ext */
  {BFD_RELOC_HEX_LD_GOT_16_X, R_HEX_LD_GOT_16_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_LD_GOT_11_X, R_HEX_LD_GOT_11_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_IE_LO16, R_HEX_IE_LO16, 0},
  {BFD_RELOC_HEX_IE_HI16, R_HEX_IE_HI16, 0},
  {BFD_RELOC_HEX_IE_32, R_HEX_IE_32, 0},
  {BFD_RELOC_HEX_IE_32_6_X, R_HEX_IE_32_6_X, 0},	/* K-ext */
  {BFD_RELOC_HEX_IE_16_X, R_HEX_IE_16_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_IE_GOT_LO16, R_HEX_IE_GOT_LO16, 0},
  {BFD_RELOC_HEX_IE_GOT_HI16, R_HEX_IE_GOT_HI16, 0},
  {BFD_RELOC_HEX_IE_GOT_32, R_HEX_IE_GOT_32, 0},
  {BFD_RELOC_HEX_IE_GOT_16, R_HEX_IE_GOT_16, 0},
  {BFD_RELOC_HEX_IE_GOT_32_6_X, R_HEX_IE_GOT_32_6_X, 0},	/* K-ext */
  {BFD_RELOC_HEX_IE_GOT_16_X, R_HEX_IE_GOT_16_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_IE_GOT_11_X, R_HEX_IE_GOT_11_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_TPREL_LO16, R_HEX_TPREL_LO16, 0},
  {BFD_RELOC_HEX_TPREL_HI16, R_HEX_TPREL_HI16, 0},
  {BFD_RELOC_HEX_TPREL_32, R_HEX_TPREL_32, 0},
  {BFD_RELOC_HEX_TPREL_16, R_HEX_TPREL_16, 0},
  {BFD_RELOC_HEX_TPREL_32_6_X, R_HEX_TPREL_32_6_X, 0},	/* K-ext */
  {BFD_RELOC_HEX_TPREL_16_X, R_HEX_TPREL_16_X, HEXAGON_OPERAND_IS_KXED},
  {BFD_RELOC_HEX_TPREL_11_X, R_HEX_TPREL_11_X, HEXAGON_OPERAND_IS_KXED},
};

/* Implement bfd_elf32_bfd_reloc_type_lookup.  */
static reloc_howto_type *
hexagon_elf_reloc_type_lookup (bfd *abfd ATTRIBUTE_UNUSED,
			       bfd_reloc_code_real_type code)
{
  size_t i;

  for (i = ARRAY_SIZE (hexagon_reloc_map); i--;)
    if (hexagon_reloc_map[i].bfd_reloc_val == code)
      {
	reloc_howto_type *howto
	  = hexagon_elf_howto_table + hexagon_reloc_map[i].elf_reloc_val;
	BFD_ASSERT (howto->type == hexagon_reloc_map[i].elf_reloc_val);

	return howto;
      }

  return NULL;
}

/* Return the relocation type for ELF_RELOC_VAL in hexagon_reloc_map,
   setting *FLAG to the associated flag.  */
static bfd_reloc_code_real_type
hexagon_elf_reloc_val_lookup (unsigned char elf_reloc_val, int *flag)
{
  unsigned int i;

  for (i = ARRAY_SIZE (hexagon_reloc_map); i--;)
    if (hexagon_reloc_map[i].elf_reloc_val == elf_reloc_val)
      {
	if (flag)
	  *flag = hexagon_reloc_map[i].operand_flag;
	return hexagon_reloc_map[i].bfd_reloc_val;
      }

  if (flag)
    *flag = 0;

  return BFD_RELOC_NONE;
}

/* Implement bfd_elf32_bfd_reloc_name_lookup.  */
static reloc_howto_type *
hexagon_elf_reloc_name_lookup (bfd *abfd ATTRIBUTE_UNUSED, const char *r_name)
{
  unsigned int i;

  for (i = 0; i < ARRAY_SIZE (hexagon_elf_howto_table); i++)
    if (hexagon_elf_howto_table[i].name
	&& !strcasecmp (hexagon_elf_howto_table[i].name, r_name))
      return hexagon_elf_howto_table + i;

  return NULL;
}

/* Set the howto pointer for a Hexagon ELF reloc CACHE_PTR by examining
   the relocation info in DST.  */
static void
hexagon_info_to_howto_rel (bfd *abfd, arelent *cache_ptr,
			   Elf_Internal_Rela *dst)
{
  unsigned int r_type;

  r_type = ELF32_R_TYPE (dst->r_info);
  if (r_type >= R_HEX_max)
    {
      (*_bfd_error_handler) (_("%B: invalid relocation type %d"),
			     abfd, (int) r_type);
      r_type = R_HEX_NONE;
    }
  else
    BFD_ASSERT (hexagon_elf_howto_table[r_type].type == r_type);

  cache_ptr->howto = hexagon_elf_howto_table + r_type;
}

/* Return the DTPREL offset value for ADDRESS.  */
static bfd_vma
hexagon_elf_dtpoff (struct bfd_link_info *info, bfd_vma address)
{
  if (elf_hash_table (info)->tls_sec)
    return address - elf_hash_table (info)->tls_sec->vma;
  else
    return 0;
}

/* Return the TPREL offset value for ADDRESS  */
static bfd_vma
hexagon_elf_tpoff (struct bfd_link_info *info, bfd_vma address)
{
  if (elf_hash_table (info)->tls_sec)
    return hexagon_elf_dtpoff (info, address) - elf_hash_table (info)->tls_size;
  else
    return 0;
}

/* Implement elf_backend_object_p.  Sets the right machine number for a
   Hexagon ELF file.  */
static bfd_boolean
hexagon_elf_object_p (bfd *abfd)
{
  unsigned int mach = bfd_mach_hexagon_v2;

  /* Set our target machine number.  */
  if (elf_elfheader (abfd)->e_machine == EM_HEXAGON)
    {
      unsigned long arch = elf_elfheader (abfd)->e_flags & EF_HEX_MACH;

      switch (EF_HEX_MACH_VER (arch))
	{
	case EF_HEX_MACH_V2:
	  mach = bfd_mach_hexagon_v2;
	  break;

	case EF_HEX_MACH_V3:
	  mach = bfd_mach_hexagon_v3;
	  break;

	case EF_HEX_MACH_V4:
	  mach = bfd_mach_hexagon_v4;
	  break;

	case EF_HEX_MACH_V5:
	  mach = bfd_mach_hexagon_v5;
	  break;

	case EF_HEX_MACH_V55:
	  mach = bfd_mach_hexagon_v55;
	  break;

	default:
	  if (elf_elfheader (abfd)->e_type != ET_HEX_IR)
	    {
	      /* Unless the object is a WHIRL, barf.  */
	      fprintf (stderr, "Unsupported machine architecure %ld\n", arch);
	      abort ();
	    }
	}
    }

  return bfd_default_set_arch_mach (abfd, bfd_arch_hexagon, mach);
}

/* Implement elf_backend_final_write_processing.
   This gets the Hexagon architecture right based on the machine number.  */
static void
hexagon_elf_final_write_processing (bfd *abfd,
				    bfd_boolean linker ATTRIBUTE_UNUSED)
{
  unsigned long val;

  switch (bfd_get_mach (abfd))
    {
    case bfd_mach_hexagon_v2:
      val = EF_HEX_MACH_V2;
      break;

    case bfd_mach_hexagon_v3:
      val = EF_HEX_MACH_V3;
      break;

    case bfd_mach_hexagon_v4:
      val = EF_HEX_MACH_V4;
      break;

    case bfd_mach_hexagon_v5:
      val = EF_HEX_MACH_V5;
      break;

    case bfd_mach_hexagon_v55:
      val = EF_HEX_MACH_V55;
      break;

    default:
      fprintf (stderr, "Unsupported machine architecure.\n");
      abort ();
    }

  elf_elfheader (abfd)->e_flags &= ~EF_HEX_MACH;
  elf_elfheader (abfd)->e_flags |= val;
}



/* Small data base pointer handling.  */

/* The base address of the small data section for GP-relative addressing
   is normally provided by defining _SDA_BASE_ in the linker script.  
   However, we may need to process GP-relative symbols before we've seen
   that definition, hence provide another default definition to use
   meanwhile.  */
#define SDA_BASE "_SDA_BASE_"
#define DEFAULT_SDA_BASE "__default_sda_base__"

static struct bfd_link_hash_entry *hexagon_sda_base;

/* Return the arch-specific required alignment of the GP.  */
int
hexagon_sda_base_align (bfd *obfd)
{
  if (bfd_get_arch_info (obfd)->mach < bfd_mach_hexagon_v4)
    return 0x80000;
  else
    return 0x1000;
}

/* We have to figure out the SDA_BASE value, so that we can adjust the
   symbol value correctly.  We look up the symbol _SDA_BASE_ in the output
   BFD.  If we can't find it, we're stuck.  We cache it in the ELF
   target data.  We don't need to adjust the symbol value for an
   external symbol if we are producing relocatable output.  */
static bfd_reloc_status_type
hexagon_elf_final_sda_base (bfd *obfd, char **errmsg, bfd_vma *psb)
{
  if (obfd)
    {
      *psb = 0;
      return bfd_reloc_ok;
    }
  else if (hexagon_sda_base && hexagon_sda_base->type == bfd_link_hash_defined)
    {
      *psb = (hexagon_sda_base->u.def.value
	      + hexagon_sda_base->u.def.section->output_section->vma
	      + hexagon_sda_base->u.def.section->output_offset);
      return bfd_reloc_ok;
    }
  else
    {
      if (errmsg)
	*errmsg = _("GP-relative relocation when _SDA_BASE_ not defined");
      *psb = 0;
      return bfd_reloc_dangerous;
    }
}

/* Implement bfd_elf32_bfd_get_relocated_section_contents.  */
static bfd_byte *
hexagon_elf_get_relocated_section_contents (bfd *obfd,
					    struct bfd_link_info *link_info,
					    struct bfd_link_order *link_order,
					    bfd_byte *data,
					    bfd_boolean relocatable,
					    asymbol **symbols)
{
  struct bfd_link_hash_entry *hash;
  bfd_vma vma;

  /* Get the hash table entry for _SDA_BASE_.  */
  hash = bfd_link_hash_lookup (link_info->hash, SDA_BASE, FALSE, FALSE, FALSE);
  if (hash)
    hexagon_sda_base = hash;
  /* In case of relying on _SDA_BASE_ being provided by the linker script,
     the look up above will fail, for it's too soon to provide its value.
     Instead, look up the alternate symbol that will be provided later on.  */
  else
    {
      hash = bfd_link_hash_lookup (link_info->hash, DEFAULT_SDA_BASE,
				   FALSE, FALSE, FALSE);
      if (hash)
	hexagon_sda_base = hash;
    }
  /* At this point, if no _SDA_BASE_, either the alternate or the proper one,
     is resolved, then GP-relocation overflow errors are likely.  */

  /* Try to validate the effective value of _SDA_BASE_.  */
  if (hexagon_sda_base)
    {
      if (bfd_reloc_ok != hexagon_elf_final_sda_base (obfd, NULL, &vma))
	{
	  fprintf (stderr, _("_SDA_BASE_ must be defined.\n"));
	  abort ();
	}
      else if (vma % hexagon_sda_base_align (obfd))
	fprintf (stderr, _("_SDA_BASE_ not correctly aligned.\n"));
    }

  /* Call the default.  */
  return bfd_generic_get_relocated_section_contents
	  (obfd, link_info, link_order, data, relocatable, symbols);
}

/* Create the .sdata section and define SDA_BASE to point at it when
   we've seen a GP-relative relocation that requires it.  */
static bfd_boolean
hexagon_elf_sda_base (bfd *abfd ATTRIBUTE_UNUSED, struct bfd_link_info *info)
{
  hexagon_link_hash_table *htab;

  if (info->relocatable)
    return TRUE;

  htab = hexagon_hash_table (info);

  if (!htab->sda.s)
    {
      /* Create output SDA.  */
      htab->sda.s = bfd_get_section_by_name (info->output_bfd, ".sdata");
      if (!htab->sda.s)
	{
	  flagword flags = (SEC_ALLOC | SEC_LOAD | SEC_HAS_CONTENTS
			    | SEC_IN_MEMORY | SEC_LINKER_CREATED);

	  htab->sda.s
	    = bfd_make_section_with_flags (info->output_bfd, ".sdata", flags);
	  if (!htab->sda.s)
	    return FALSE;
	}
    }

  if (!htab->sda.h)
    {
      /* Create the SDA pointer.  */
      struct bfd_link_hash_entry *bh;

      bh = bfd_link_hash_lookup	(&htab->elf.root, SDA_BASE,
				 FALSE, FALSE, FALSE);
      if ((!bh || bh->type == bfd_link_hash_undefined)
	  && !_bfd_generic_link_add_one_symbol
	       (info, info->output_bfd,	SDA_BASE, BSF_GLOBAL,
		htab->sda.s, 0, NULL, FALSE,
		get_elf_backend_data (abfd)->collect, &bh))
	return FALSE;

      htab->sda.h = hexagon_hash_entry (bh);
      htab->sda.h->elf.def_regular = 1;
      htab->sda.h->elf.type = STT_OBJECT;
      htab->sda.h->elf.other
	= (htab->sda.h->elf.other & ~ELF_ST_VISIBILITY (-1)) | STV_HIDDEN;
    }

  return TRUE;
}


/* Relocation support.  */

/* Apply the relocation described by HOWTO to INSN and the value OFFSET.
   Returns TRUE on success, otherwise returns FALSE and sets *ERRMSG.

   The Hexagon ABI defines relocations that may use different bits in the
   instruction encoding depending on what opcode they apply to.  So,
   this function has to disassemble INSN to determine the opcode, map the
   relocation onto an operand descriptor, and then encode the bits of the
   value as appropriate for that operand.  */
static int
hexagon_reloc_operand (reloc_howto_type *howto, hexagon_insn *insn,
		       bfd_vma offset, char **errmsg)
{
  int flag;
  const hexagon_opcode *opcode = hexagon_lookup_insn (*insn);
  bfd_reloc_code_real_type type = hexagon_elf_reloc_val_lookup (howto->type,
								&flag);
  const hexagon_operand *operand = hexagon_lookup_reloc (type, flag, opcode);
  long value = offset;

  if (!opcode || !operand)
    return FALSE;
  else
    return hexagon_encode_operand (operand, insn, opcode, value,
				   flag & HEXAGON_OPERAND_IS_KXED,
				   errmsg);
}

static bfd_reloc_status_type
hexagon_elf_reloc (bfd *abfd, arelent *reloc_entry, asymbol *symbol,
		   PTR data, asection *isection, bfd *obfd,
		   char **error_message)
{
  reloc_howto_type *howto = reloc_entry->howto;
  bfd_size_type octets_per_byte = bfd_octets_per_byte (abfd);
  bfd_size_type octets = reloc_entry->address * octets_per_byte;
  bfd_reloc_status_type status;
  bfd_reloc_status_type flag = bfd_reloc_ok;
  bfd_vma relocation;

  /* bfd_perform_relocation () performed this test before calling
     howto->special_function (), but that gets ignored if we return
     bfd_reloc_ok (which we do, below) so we need to re-do this
     test here. The real bug is probably in bfd_perform_relocation ()
     but it is better not to modify the common code.  */
  if (!obfd
      && bfd_is_und_section (symbol->section)
      && !(symbol->flags & BSF_WEAK))
    return bfd_reloc_undefined;

  /* If linking, back up the final symbol address by the address of the
     reloc.  This cannot be accomplished by setting the pcrel_offset
     field to TRUE, as bfd_install_relocation will detect this and refuse
     to install the offset in the first place, but bfd_perform_relocation
     will still insist on removing it.  */
  if (!obfd && howto->pc_relative)
    reloc_entry->addend -= reloc_entry->address;

  /* Fall through to the default elf reloc handler.  */
  status = bfd_elf_generic_reloc (abfd, reloc_entry, symbol, data,
				  isection, obfd, error_message);
  if (status != bfd_reloc_continue)
    return status;

  /* Handle PC relative relocatable output.  */
  if (obfd
      && reloc_entry->howto->pc_relative
      && (!reloc_entry->howto->partial_inplace || !reloc_entry->addend))
    {
      reloc_entry->address += isection->output_offset;
      return bfd_reloc_ok;
    }

  /* NOTE:  This code was pasted/modified from bfd_perform_relocation.
     We can't use that code (which would happen if we returned
     bfd_reloc_continue) because it assumes the operand goes
     into a contiguous range of bits.  */

  /* Is the address of the relocation really within the section?  */
  if (reloc_entry->address > isection->size / bfd_octets_per_byte (abfd))
    return bfd_reloc_outofrange;

  /* Work out which section the relocation is targetted at and the
     initial relocation command value.  */

  /* Get symbol value.  (Common symbols are special.)  */
  if (bfd_is_com_section (symbol->section))
    relocation = 0;
  else
    relocation = symbol->value;

  /* Convert input-section-relative symbol value to absolute.  */
  if ((obfd && !howto->partial_inplace) || !symbol->section->output_section)
    relocation += symbol->section->output_offset;
  else
    relocation += section_base (symbol->section);

  /* Add in supplied addend.  */
  relocation += reloc_entry->addend;

  /* Here the variable relocation holds the final address of the
     symbol we are relocating against, plus any addend.  */
  if (howto->type == R_HEX_GPREL16_0
      || howto->type == R_HEX_GPREL16_1
      || howto->type == R_HEX_GPREL16_2
      || howto->type == R_HEX_GPREL16_3)
    {
      bfd_vma sda_base;

      status = hexagon_elf_final_sda_base (obfd, error_message, &sda_base);
      if (status != bfd_reloc_ok)
	return status;

      /* At this point `relocation' contains the object's address.  */
      relocation -= sda_base;
    }

  if (howto->pc_relative)
    {
      /* This is a PC relative relocation.  We want to set RELOCATION
         to the distance between the address of the symbol and the
         location.  RELOCATION is already the address of the symbol.

         We start by subtracting the address of the section containing
         the location.

         If pcrel_offset is set, we must further subtract the position
         of the location within the section.  Some targets arrange for
         the addend to be the negative of the position of the location
         within the section; for example, i386-aout does this.  For
         i386-aout, pcrel_offset is FALSE.  Some other targets do not
         include the position of the location; for example, m88kbcs,
         or ELF.  For those targets, pcrel_offset is TRUE.

         If we are producing relocatable output, then we must ensure
         that this reloc will be correctly computed when the final
         relocation is done.  If pcrel_offset is FALSE we want to wind
         up with the negative of the location within the section,
         which means we must adjust the existing addend by the change
         in the location within the section.  If pcrel_offset is TRUE
         we do not want to adjust the existing addend at all.

         FIXME: This seems logical to me, but for the case of
         producing relocatable output it is not what the code
         actually does.  I don't want to change it, because it seems
         far too likely that something will break.  */
      relocation -= section_base (isection);
      if (howto->pcrel_offset)
	relocation -= reloc_entry->address;
    }

  if (obfd)
    {
      if (!howto->partial_inplace)
	{
	  /* This is a partial relocation, and we want to apply the relocation
	     to the reloc entry rather than the raw data. Modify the reloc
	     inplace to reflect what we now know.  */
	  reloc_entry->addend = relocation;
	  reloc_entry->address += isection->output_offset;
	  return flag;
	}
      else
	{
	  /* This is a partial relocation, but inplace, so modify the
	     reloc record a bit.

	     If we've relocated with a symbol with a section, change
	     into a ref to the section belonging to the symbol.  */
	  reloc_entry->address += isection->output_offset;
	  reloc_entry->addend = relocation;
	}
    }
  else
    reloc_entry->addend = 0;

  /* If we have a PC-relative reference to an undefined weak symbol,
     the relocation may exceed the range of the call/jump instruction.
     Since the symbol is not really supposed to be branched to, it
     doesn't matter how we relocate the instruction, so just insert
     0x00000000 into the call/jump.  */
  if (!obfd
      && howto->pc_relative
      && bfd_is_und_section (symbol->section)
      && symbol->flags & BSF_WEAK)
    relocation = 0;

  /* FIXME: This overflow checking is incomplete, because the value
     might have overflowed before we get here.  For a correct check we
     need to compute the value in a size larger than bitsize, but we
     can't reasonably do that for a reloc the same size as a host
     machine word.
     FIXME: We should also do overflow checking on the result after
     adding in the value contained in the object file.  */
  if (howto->complain_on_overflow != complain_overflow_dont
      && flag == bfd_reloc_ok)
    flag = bfd_check_overflow (howto->complain_on_overflow, howto->bitsize,
			       howto->rightshift,
			       bfd_arch_bits_per_address (abfd), relocation);

  switch (howto->size)
    {
    case 1:
      {
	hexagon_insn insn = bfd_get_16 (abfd, (bfd_byte *) data + octets);

	if (!hexagon_reloc_operand (howto, &insn, relocation, error_message))
	  return bfd_reloc_overflow;
	bfd_put_16 (abfd, (bfd_vma) insn, (unsigned char *) data);
      }
      break;

    case 2:
      {
	hexagon_insn insn = bfd_get_32 (abfd, (bfd_byte *) data + octets);

	if (!hexagon_reloc_operand (howto, &insn, relocation, error_message))
	  return bfd_reloc_overflow;
	bfd_put_32 (abfd, (bfd_vma) insn, (bfd_byte *) data + octets);
      }
      break;

    default:
      return bfd_reloc_other;
    }

  return bfd_reloc_ok;
}


/* Section and symbol processing hooks.  */

/* Implement elf_backend_fake_sections.
   Set up any other section flags and such that may be necessary.  */
static bfd_boolean
hexagon_elf_fake_sections (bfd *abfd ATTRIBUTE_UNUSED,
			   Elf_Internal_Shdr *shdr, asection *asect)
{
  if (asect->flags & SEC_SORT_ENTRIES)
    shdr->sh_type = SHT_HEX_ORDERED;
  return TRUE;
}

/* Implement elf_backend_section_from_shdr.
   This is called when elfcode.h finds a section with an unknown type.  */
static bfd_boolean
hexagon_elf_section_from_shdr (bfd *abfd, Elf_Internal_Shdr *hdr,
			       const char *name, int shindex)
{
  asection *newsect;
  flagword flags;

  if (!_bfd_elf_make_section_from_shdr (abfd, hdr, name, shindex))
    return FALSE;
  newsect = hdr->bfd_section;
  flags = bfd_get_section_flags (abfd, newsect);
  if (hdr->sh_type == SHT_HEX_ORDERED)
    flags |= SEC_SORT_ENTRIES;
  bfd_set_section_flags (abfd, newsect, flags);
  return TRUE;
}

/* Implement elf_backend_add_symbol_hook, which is called by the linker
   routine that adds symbols from an object file.  We use it to put
   .comm items in .sbss, and not .bss.  */
static bfd_boolean
hexagon_elf_add_symbol_hook (bfd *abfd,
			     struct bfd_link_info *info ATTRIBUTE_UNUSED,
			     Elf_Internal_Sym *sym,
			     const char **namep ATTRIBUTE_UNUSED,
			     flagword *flagsp ATTRIBUTE_UNUSED,
			     asection **secp, bfd_vma *valp)
{
  /* This step must be performed even for partial links because otherwise
     the special sections would not be created, resulting in a subsequent
     error check higher up failing.  */
  if (bfd_get_flavour (abfd) == bfd_target_elf_flavour)
    {
      switch (sym->st_shndx)
	{
	case SHN_COMMON:
	  /* Common symbols less than the GP size are automatically
	     treated as SHN_HEX_SCOMMON symbols.  */
	  if (sym->st_size > elf_gp_size (abfd))
	    break;

	  /* Choose which section to place them in.  */
	  if (sym->st_size > 8)
	    sym->st_shndx = SHN_HEX_SCOMMON;
	  else if (sym->st_size > 4)
	    sym->st_shndx = SHN_HEX_SCOMMON_8;
	  else if (sym->st_size > 2)
	    sym->st_shndx = SHN_HEX_SCOMMON_4;
	  else if (sym->st_size > 1)
	    sym->st_shndx = SHN_HEX_SCOMMON_2;
	  else
	    sym->st_shndx = SHN_HEX_SCOMMON_1;
	  /* Fall through.  */

	case SHN_HEX_SCOMMON:
	case SHN_HEX_SCOMMON_8:
	case SHN_HEX_SCOMMON_4:
	case SHN_HEX_SCOMMON_2:
	case SHN_HEX_SCOMMON_1:
	  /* Small common symbols are placed in their originally intended
	     .scommon sections.  */
	  *secp = bfd_make_section_old_way (abfd,
					    HEXAGON_SCOM_NAME (sym->st_shndx));
	  bfd_set_section_flags (abfd, *secp,
				 (SEC_ALLOC | SEC_IS_COMMON
				  | SEC_LINKER_CREATED));
	  *valp = sym->st_size;
	  break;
	}
    }

  return TRUE;
}

/* Implement elf_backend_symbol_processing.
   Handle the special Hexagon section numbers that a symbol may use.  */
void
hexagon_elf_symbol_processing (bfd *abfd, asymbol *asym)
{
  elf_symbol_type *elfsym = (elf_symbol_type *) asym;
  unsigned shndx = elfsym->internal_elf_sym.st_shndx;
  bfd_vma size = elfsym->internal_elf_sym.st_size;

  /* Decide if a common symbol should be considered small or not.  */
  switch (shndx)
    {
    case SHN_COMMON:
      /* Common symbols less than the GP size are automatically
         treated as SHN_HEX_SCOMMON symbols.  */
      if (asym->value > elf_gp_size (abfd))
	break;

      /* Choose which section to place them in.  */
      if (size > 8)
	shndx = SHN_HEX_SCOMMON;
      else if (size > 4)
	shndx = SHN_HEX_SCOMMON_8;
      else if (size > 2)
	shndx = SHN_HEX_SCOMMON_4;
      else if (size > 1)
	shndx = SHN_HEX_SCOMMON_2;
      else
	shndx = SHN_HEX_SCOMMON_1;
      elfsym->internal_elf_sym.st_shndx = shndx;
      /* Fall through.  */

    case SHN_HEX_SCOMMON:
    case SHN_HEX_SCOMMON_8:
    case SHN_HEX_SCOMMON_4:
    case SHN_HEX_SCOMMON_2:
    case SHN_HEX_SCOMMON_1:
      {
	/* Small common symbols are placed in their originally intended
	   .scommon sections.  */
	asection *scom_section = &(HEXAGON_SCOM_SECTION (shndx));
	asymbol *scom_symbol = &(HEXAGON_SCOM_SYMBOL (shndx));

	if (!scom_section->name)
	  {
	    const char *scom_name = HEXAGON_SCOM_NAME (shndx);

	    /* Initialize the small common section.  */
	    scom_section->name = scom_name;
	    scom_section->flags = SEC_IS_COMMON | SEC_SMALL_DATA;
	    if (shndx > SHN_HEX_SCOMMON)
	      scom_section->flags |= SEC_LOAD | SEC_DATA;
	    scom_section->output_section = scom_section;
	    scom_section->symbol = scom_symbol;
	    scom_section->symbol_ptr_ptr = &scom_section->symbol;

	    scom_symbol->name = scom_name;
	    scom_symbol->flags = BSF_SECTION_SYM;
	    scom_symbol->section = scom_section;
	  }

	asym->section = scom_section;
	asym->value = size;
      }
      break;
    }
}

/* Implement elf_backend_common_definition.  */
static bfd_boolean
hexagon_elf_common_definition (Elf_Internal_Sym *sym)
{
  return (sym->st_shndx == SHN_COMMON
	  || (sym->st_shndx >= SHN_HEX_SCOMMON
	      && sym->st_shndx <= SHN_HEX_SCOMMON_8));
}

/* Work over a section just before writing it out. FIXME: We recognize
   sections that need the SHF_HEX_GPREL flag by name; there has to be
   a better way.  */
static void
hexagon_elf_adjust_section_flags (bfd *abfd ATTRIBUTE_UNUSED,
				  asection *asect,
				  void *fsarg ATTRIBUTE_UNUSED)
{
  struct bfd_elf_section_data *esd = elf_section_data (asect);
  Elf_Internal_Shdr *hdr = &esd->this_hdr;
  if (hdr->bfd_section)
    {
      const char *name = bfd_get_section_name (abfd, hdr->bfd_section);

      if (CONST_STRNEQ (name, ".sdata"))
	{
	  hdr->sh_flags |= SHF_ALLOC | SHF_WRITE | SHF_HEX_GPREL;
	  hdr->sh_type = SHT_PROGBITS;
	}
      else if (CONST_STRNEQ (name, ".sbss"))
	{
	  hdr->sh_flags |= SHF_ALLOC | SHF_WRITE | SHF_HEX_GPREL;
	  hdr->sh_type = SHT_NOBITS;
	}
    }
}

/* Implement elf_backend_post_process_headers.  */
static void
hexagon_elf_post_process_headers (bfd *abfd,
				  struct bfd_link_info *info ATTRIBUTE_UNUSED)
{
  bfd_map_over_sections (abfd, hexagon_elf_adjust_section_flags, NULL);
}

/* Try to map NAME onto one of the small common sections.  Set *RETVAL
   and return TRUE if a match is found, else return FALSE.  */
static bfd_boolean
hexagon_elf_section_from_scom_name (const char *name, int *retval)
{
  if (CONST_STRNEQ (name, hexagon_scom_name[0]))
    {
      if (!strcmp (name, HEXAGON_SCOM_NAME (SHN_HEX_SCOMMON_8)))
	*retval = SHN_HEX_SCOMMON_8;
      else if (!strcmp (name, HEXAGON_SCOM_NAME (SHN_HEX_SCOMMON_4)))
	*retval = SHN_HEX_SCOMMON_4;
      else if (!strcmp (name, HEXAGON_SCOM_NAME (SHN_HEX_SCOMMON_2)))
	*retval = SHN_HEX_SCOMMON_2;
      else if (!strcmp (name, HEXAGON_SCOM_NAME (SHN_HEX_SCOMMON_1)))
	*retval = SHN_HEX_SCOMMON_1;
      else
	*retval = SHN_HEX_SCOMMON;
      return TRUE;
    }
  return FALSE;
}

/* Implement elf_backend_section_from_bfd_section.
   Given a BFD section, try to locate the corresponding ELF section index.  */
bfd_boolean
hexagon_elf_section_from_bfd_section (bfd *abfd ATTRIBUTE_UNUSED,
				      asection *sec, int *retval)
{
  const char *name = bfd_get_section_name (abfd, sec);
  return hexagon_elf_section_from_scom_name (name, retval);
}

/* Implement elf_backend_link_output_symbol_hook.
   This hook function is called before the linker writes out a global
   symbol.  We mark symbols as small common if appropriate.  */
bfd_boolean
hexagon_elf_link_output_symbol_hook (struct bfd_link_info *info ATTRIBUTE_UNUSED,
				     const char *name ATTRIBUTE_UNUSED,
				     Elf_Internal_Sym *sym,
				     asection *input_sec,
				     struct elf_link_hash_entry *h ATTRIBUTE_UNUSED)
{
  int shndx;
  
  /* If we see a common symbol, which implies a relocatable link, then
     if a symbol was small common in an input file, mark it as small
     common in the output file.  */
  if (sym->st_shndx == SHN_COMMON
      && elf_gp_size (info->output_bfd)
      && sym->st_size > elf_gp_size (info->output_bfd)
      && hexagon_elf_section_from_scom_name (input_sec->name, &shndx))
    sym->st_shndx = shndx;
  return TRUE;
}

static inline hexagon_insn
hexagon_get_insn (bfd *ibfd, reloc_howto_type *howto, bfd_byte *offset)
{
  switch (howto->size)
    {
    case 0:
      return bfd_get_8 (ibfd, offset);

    case 1:
      return bfd_get_16 (ibfd, offset);

    case 2:
      return bfd_get_32 (ibfd, offset);

    default:
      fprintf (stderr,
	       "%s: Unrecognized howto->size  ==%d\n", __func__, howto->size);
      abort ();
    }
  return 0;
}

static inline void
hexagon_put_insn (bfd *ibfd, reloc_howto_type *howto, bfd_byte *offset,
		  hexagon_insn insn)
{
  switch (howto->size)
    {
    case 0:
      return bfd_put_8 (ibfd, insn, offset);

    case 1:
      return bfd_put_16 (ibfd, insn, offset);

    case 2:
      return bfd_put_32 (ibfd, insn, offset);

    default:
      fprintf (stderr,
	       "%s: Unrecognized howto->size  ==%d\n", __func__, howto->size);
      abort ();
    }
}

static bfd_boolean
hexagon_kept_hash_lookup (bfd *obfd ATTRIBUTE_UNUSED,
			  struct bfd_link_info *info,
			  bfd *ibfd ATTRIBUTE_UNUSED,
			  Elf_Internal_Rela *rel ATTRIBUTE_UNUSED,
			  struct elf_link_hash_entry *h)
{
  bfd *b;

  /* Check for a relocation that is actually dangling.  */
  if ((h->root.type != bfd_link_hash_defined
       && h->root.type != bfd_link_hash_defweak)
      || !elf_discarded_section (h->root.u.def.section))
    return TRUE;

  for (b = info->input_bfds; b; b = b->link_next)
    {
      asection *s = bfd_get_section_by_name (b, h->root.u.def.section->name);
      if (s && !elf_discarded_section (s))
	{
	  h->root.u.def.section = s;
	  return TRUE;
	}
    }

  return FALSE;
}

/* Called from hexagon_before_allocation.  */
void
hexagon_use_trampolines (struct bfd_link_info *info)
{
  hexagon_link_hash_table *htab = hexagon_hash_table (info);
  htab->use_trampolines = TRUE;
}

/* Implement bfd_elf32_bfd_merge_private_bfd_data.  */
static bfd_boolean
hexagon_elf_merge_private_bfd_data (bfd *ibfd, bfd *obfd)
{
  const bfd_arch_info_type *c = bfd_arch_get_compatible (ibfd, obfd, TRUE);
  if (!c)
    return FALSE;
  if (c != bfd_get_arch_info (obfd))
    bfd_set_arch_info (obfd, c);
  return TRUE;
}

#define JUMP_AROUND_TRAMPS_NAME "__jump_around_trampolines"
#define HEXAGON_JUMP24 0x5800c000

/* Allocate a new trampoline at the end of an input section.  */
static bfd_boolean
hexagon_add_tramp (bfd *ibfd, asection *isec, struct bfd_link_info *info,
		   Elf_Internal_Rela *irel, char *t_name,
		   bfd_signed_vma *t_offset, struct elf_link_hash_entry **ph)
{
  bfd_boolean rc = FALSE;
  struct elf_link_hash_entry *t_h;
  bfd_byte *contents = NULL;
  char *str, *name;
  bfd_vma t_at;
  bfd_size_type isec_size = 0;
  hexagon_trampoline_type type;
  size_t i = 0, j = 0;

  /* Access the section contents.  */
  contents = elf_section_data (isec)->this_hdr.contents;
  if (!contents)
    if (!bfd_malloc_and_get_section (ibfd, isec, &contents))
      goto error_return;

  /* If this is the first trampoline for this input section,
     insert a jump at the current end of the section which will
     go around the trampolines.  A symbol records that we have
     emitted the jump and its location.  */
  str = JUMP_AROUND_TRAMPS_NAME;
  name = bfd_malloc (HEXAGON_TRAMPOLINE_PREFIX_LEN + 8 + 1 + strlen (str) + 1);
  sprintf (name, HEXAGON_TRAMPOLINE_PREFIX "%08x.%s",
	   isec->id & 0xffffffff, str);

  t_h = (struct elf_link_hash_entry *) bfd_link_hash_lookup
    (info->hash, name, TRUE, FALSE, TRUE);
  BFD_ASSERT (t_h);

  if (t_h->root.u.def.value)
    free (name);
  else
    {
      hexagon_insn hexagon_jump = HEXAGON_JUMP24;

      _bfd_elf_define_linkage_sym (ibfd, info, isec, name);
      t_h->type = STT_NOTYPE;
      t_h->size = 4;
      t_h->root.u.def.value =
	t_at =
	isec_size = bfd_section_size (ibfd, isec);
      BFD_ASSERT (isec_size);

      isec_size += sizeof (hexagon_insn);
      *t_offset += sizeof (hexagon_insn);
      elf_section_data (isec)->this_hdr.contents
	= contents = bfd_realloc_or_free (contents, isec_size);
      if (!contents)
	goto error_return;
      if (!bfd_set_section_size (ibfd, isec, isec_size))
	goto error_return;

      bfd_put_32 (ibfd, hexagon_jump, contents + t_at);

      /* The jump's target will be fixed up once we have
	 emitted all trampolines for this input section.  */
    }

  /* Add room for the new trampoline. */
  t_at =
    isec_size = bfd_section_size (ibfd, isec);
  type = HEXAGON_TRAMPOLINE_TYPE (info, isec->output_section->owner);

  isec_size += hexagon_trampolines [type].length
    * sizeof (hexagon_trampolines [type].insns [0]);
  elf_section_data (isec)->this_hdr.contents =
    contents = bfd_realloc_or_free (contents, isec_size);
  if (!contents)
    goto error_return;
  if (!bfd_set_section_size (ibfd, isec, isec_size))
    goto error_return;

  /* Create the trampoline symbol. */
  t_h = (struct elf_link_hash_entry *) bfd_link_hash_lookup
    (info->hash, t_name, TRUE, FALSE, TRUE);
  BFD_ASSERT (t_h);

  _bfd_elf_define_linkage_sym (ibfd, info, isec, t_name);

  t_h->type = STT_FUNC;
  t_h->size = hexagon_trampolines [type].length
    * sizeof (hexagon_trampolines [type].insns [0]);
  t_h->root.u.def.section = isec;
  t_h->root.u.def.value
    = t_at + hexagon_trampolines [type].entry;

  /* Add a trampoline at the end of the section. */
  for (i = 0,
       j = 0;
       j < hexagon_trampolines [type].length;
       i += sizeof (hexagon_trampolines [type].insns [0]),
       ++j)
    bfd_put_32 (ibfd, hexagon_trampolines [type].insns [j],
		contents + t_at + i);

  /* Set up a relocation for the trampoline.
     Re-use the relocation for the original jump.  */
  if (hexagon_trampolines [type].r_type != R_HEX_NONE)
    {
      irel->r_info = ELF32_R_INFO (ELF32_R_SYM (irel->r_info),
				   hexagon_trampolines [type].r_type);
      irel->r_offset = t_at + hexagon_trampolines [type].offset;
      irel->r_addend += hexagon_trampolines [type].addend;
    }

  *ph = t_h;
  rc = TRUE;
error_return:
  if (contents && elf_section_data (isec)->this_hdr.contents != contents)
    free (contents);
  return rc;
}

/* An linker-internal reloc for a reference to a trampoline.  */
struct fixup
{
  unsigned ireloc;			/* index to the original reloc */
  bfd_vma r_offset;			/* offset in original reloc */
					/* == offset of jump to tramp */
  bfd_vma r_info;			/* type & symndex in original reloc */
  bfd_vma r_addend;			/* addend in original reloc */
  unsigned short disabled;		/* set if the fixup should be ignored */
  unsigned short pk_adjust;		/* insn's packet offset (loc - pkt) */
  struct elf_link_hash_entry *t_h;	/* symbol referenced */
};

/* Save a new internal fixup for a call / jump to a trampoline.  */
static bfd_boolean
hexagon_save_fixup_to_tramp (asection *isec, unsigned ireloc,
			     bfd_vma r_offset, bfd_vma r_info, bfd_vma r_addend,
			     bfd_signed_vma pk_adjust,
			     struct elf_link_hash_entry *t_h)
{
  bfd_boolean rc = FALSE;
  unsigned i, count = isec->relax_count;
  struct fixup *fixups = (struct fixup *) isec->relax;

  /* Search for an existing entry.  */
  for (i = 0; i < count; ++i)
    {
      if (fixups[i].r_offset == r_offset)
	{
	  /* Don't add if we already have it.  */
	  if (! fixups[i].disabled)
	    goto ok_return;

	  /* Update & re-enable it.  */
	  break;
	}
    }

  if (count == 0)
    {
      fixups = (struct fixup *) bfd_malloc (sizeof (struct fixup));
      if (! fixups)
	goto error_return;
      ++count;
    }
  else if (i == count)
    {
      fixups = (struct fixup *)
	bfd_realloc_or_free (isec->relax, (count + 1) * sizeof (struct fixup));
      if (! fixups)
	goto error_return;
      ++count;
    }

  fixups[i].ireloc = ireloc;
  fixups[i].r_offset = r_offset;
  fixups[i].r_info = r_info;
  fixups[i].r_addend = r_addend;
  fixups[i].disabled = FALSE;
  fixups[i].pk_adjust = (unsigned short) pk_adjust;
  fixups[i].t_h = t_h;
  isec->relax = (struct relax_table *) fixups;
  isec->relax_count = count;

ok_return:
  rc = TRUE;
error_return:
  if (fixups && isec->relax != (struct relax_table *)fixups)
    free (fixups);
  return rc;
}

/* Apply internal fixups for references to a trampoline.  */
static void
hexagon_apply_fixups_to_tramps (bfd *ibfd, asection *isec,
				Elf_Internal_Rela *irelbuf, bfd_byte *contents,
				unsigned *min_ireloc)
{
  int i, count = isec->relax_count;
  struct fixup *fixups = (struct fixup *) isec->relax;

  for (i = 0; i < count; ++i)
    {
      struct fixup *fixup = fixups + i;
      bfd_vma r_offset = fixup->r_offset;
      unsigned r_type = ELF32_R_TYPE (fixup->r_info);
      struct elf_link_hash_entry *t_h = fixup->t_h;
      bfd_signed_vma offset;
      hexagon_insn insn;

      if (fixup->disabled)
	continue;

      offset =
	(t_h->root.u.def.section->output_section->vma
	 + t_h->root.u.def.section->output_offset + t_h->root.u.def.value)
	- (isec->output_section->vma + isec->output_offset + r_offset)
	+ fixup->pk_adjust;

      /* Check if the trampoline is now beyond reach.  */
      if (HEXAGON_TRAMPOLINE_NEEDED (r_type, offset))
	{
	  /* This trampoline is out of range.
	     Mark this internal fixup as disabled.
	     The original reloc is restored and will be re-processed.  */
	  fixup->disabled = TRUE;

	  irelbuf[fixup->ireloc].r_offset = fixup->r_offset;
	  irelbuf[fixup->ireloc].r_info = fixup->r_info;
	  irelbuf[fixup->ireloc].r_addend = fixup->r_addend;

	  if (fixup->ireloc < *min_ireloc)
	    *min_ireloc = fixup->ireloc;

	  continue;
	}

      insn = hexagon_get_insn
	(ibfd, hexagon_elf_howto_table + r_type, contents + r_offset);
      if (hexagon_reloc_operand
	  (hexagon_elf_howto_table + r_type, &insn, offset, NULL))
	hexagon_put_insn
	  (ibfd, hexagon_elf_howto_table + r_type, contents + r_offset, insn);
    }
}

/* Implement bfd_elf32_bfd_relax_section.  */
static bfd_boolean
hexagon_elf_relax_section (bfd *ibfd, asection *isec,
			   struct bfd_link_info *info, bfd_boolean *again)
{
  Elf_Internal_Shdr *symtab_hdr = NULL;
  Elf_Internal_Rela *irelbuf = NULL;
  Elf_Internal_Rela *irel;
  unsigned ireloc;
  bfd_byte *contents = NULL;
  Elf_Internal_Sym *isymbuf = NULL;
  struct elf_link_hash_entry **sym_hashes;
  size_t r_symndx;
  hexagon_link_hash_table *htab;
  struct elf_link_hash_entry *h = NULL;
  struct elf_link_hash_entry *t_h;
  bfd_boolean rc = TRUE;
  bfd_size_type isec_size = 0;
  char *name, *t_name;
  hexagon_insn insn;
  bfd_boolean trampFound;
  size_t i = 0;

  *again = FALSE;

  if (info->relocatable || !(isec->flags & SEC_RELOC) || !isec->reloc_count)
    return rc;

  htab = hexagon_hash_table (info);
  if (!htab->use_trampolines)
    return rc;

  /* If needed, initialize this section's cooked size.  */
  if (isec->size == 0)
    isec->size = isec->rawsize;

  /* It's quite hard to get rid of the relocation table once it's been read.
     Ideally, any relocations required by the trampoline should be added to it,
     but it seems that everything falls off if the table is changed in any way.
     Since the original relocation is voided, it and only it may be reused by
     the trampoline.
     TODO: instead of keeping the memory around, perhaps manually setting
     "elf_section_data (o)->relocs" if there's any change would use up
     less memory.  */
  irelbuf = _bfd_elf_link_read_relocs (ibfd, isec, NULL, NULL,
				       info->keep_memory);
  if (!irelbuf)
    goto error_return;

  /* This loop's limit uses "<=" vs "<" to get one extra iteration.
     That iteration is used to run loop post-processing within the loop body.
     Now we can re-run part of the normal iterations, if required.  */
  for (ireloc = 0; ireloc <= isec->reloc_count; ++ireloc)
    {
      bfd_vma pk_base, ju_base, tr_base, to_base;
      bfd_vma pk_ofst, ju_ofst, tr_ofst, to_ofst;
      bfd_signed_vma offset;
      unsigned r_type;
      bfd_boolean is_def;
      bfd_vma r_info, r_addend;

      /* If this is the last iteration, run the loop post-processing.  */
      if (ireloc == isec->reloc_count)
	{
	  /* If there are no internal fixups, post-processing is not required
	     and we exit from the loop.  */
	  if (! isec->relax_count)
	    break;

	  /* Access the section contents.  */
	  if (!contents)
	    contents = elf_section_data (isec)->this_hdr.contents;
	  if (!contents)
	    if (!bfd_malloc_and_get_section (ibfd, isec, &contents))
	      goto error_return;

	  /* Fixup the original calls / jumps.  */
	  hexagon_apply_fixups_to_tramps (ibfd, isec, irelbuf, contents,
					  &ireloc);
	  elf_section_data (isec)->this_hdr.contents = contents;

	  /* If there is a need to re-run part of the loop, ireloc has been
	     decremented to the first reloc that needs to be re-evaluated.
	     Run the loop again.  */
	  if (ireloc < isec->reloc_count)
	    {
	      --ireloc;	  /* adjust for increment by "continue" */
	      continue;
	    }

	  /* Otherwise, exit from the loop.  */
	  break;
	}

      /* Generally in this code,
	 The jump packet is at: pk_base + pk_ofst
	 The jump is at: ju_base + ju_ofst
	 The trampoline is at: tr_base + tr_ofst
	 The target is at: to_base + to_ofst  */

      irel = irelbuf + ireloc;

      /* Check relocation overflows at branches.  Add trampolines if needed.  */
      r_type = ELF32_R_TYPE (irel->r_info);
      if (r_type != R_HEX_PLT_B22_PCREL
	  && r_type != R_HEX_B22_PCREL
	  && r_type != R_HEX_B15_PCREL
	  && r_type != R_HEX_B13_PCREL
	  && r_type != R_HEX_B9_PCREL)
	continue;

      isec_size = bfd_section_size (ibfd, isec);

      ju_ofst = irel->r_offset;
      ju_base = section_base (isec);
      if (ju_ofst >= isec_size)
	{
	  /*
	     (*_bfd_error_handler) (_("%B: 0x%lx: warning: bad relocation"),
	     ibfd, NULL,
	     (unsigned long) irel->r_offset);
	     */
	  continue;
	}

      /* This will do for now, but it must be corrected since the addendum
	 is also offset by the position of the branch in the packet.
	 That is, pc-rel offsets are relative to the packet not the insn.  */
      pk_base = ju_base;
      pk_ofst = ju_ofst;

      symtab_hdr = &elf_tdata (ibfd)->symtab_hdr;
      r_symndx = ELF32_R_SYM (irel->r_info);
      sym_hashes = elf_sym_hashes (ibfd);

      /* Read this BFD's symbols if we haven't done so already.  */
      if (isymbuf == NULL && symtab_hdr->sh_info != 0)
	{
	  isymbuf = (Elf_Internal_Sym *) symtab_hdr->contents;
	  if (!isymbuf)
	    isymbuf = bfd_elf_get_elf_syms
		        (ibfd, symtab_hdr, symtab_hdr->sh_info, 0, NULL, NULL, NULL);
	  if (!isymbuf)
	    goto error_return;
	}

      /* Get the value of the symbol referred to by the reloc.  */
      if (r_symndx < symtab_hdr->sh_info)
	{
	  /* A local symbol.  */
	  static size_t l_count;
	  Elf_Internal_Sym *isym = isymbuf + r_symndx;
	  asection *asec = bfd_section_from_elf_index (ibfd, isym->st_shndx);

	  name = bfd_malloc (sizeof (l_count) * 2 + 1);
	  sprintf (name, "%0*lx",
		   (int) sizeof (l_count) * 2, (long) l_count++);
 
	  is_def = TRUE;
	  to_ofst = isym->st_value + irel->r_addend;
	  to_base = asec ? section_base (asec) : 0;
	}
      else
	{
	  /* A global symbol.  */
	  h = sym_hashes[r_symndx - symtab_hdr->sh_info];
	  while (h
		 && (h->root.type == bfd_link_hash_indirect
		     || h->root.type == bfd_link_hash_warning))
	    h = (struct elf_link_hash_entry *) h->root.u.i.link;
	  if (!h)
	    continue;

	  name = (char *) h->root.root.string;

	  switch (h->root.type)
	    {
	    case bfd_link_hash_defined:
	    case bfd_link_hash_defweak:
	      if (SYMBOL_CALLS_LOCAL (info, &hexagon_hash_entry (h)->elf))
		{
		  is_def = TRUE;
		  to_ofst = h->root.u.def.value + irel->r_addend;
		  to_base = elf_hash_base (h);
		}
	      else if (h->plt.offset != -(bfd_vma) 1)
		{
		  /* Use the PLT entry for a defined symbol using one.  */
		  is_def = TRUE;
		  to_ofst = h->plt.offset + irel->r_addend;
		  to_base = section_base (htab->elf.splt);
		}
	      else
		{
		  /* Cannot handle it; let it overflow.  */
		  is_def = FALSE;
		  continue;
		}
	      break;

	    case bfd_link_hash_undefined:
	    case bfd_link_hash_undefweak:
	      if (h->plt.offset != -(bfd_vma) 1)
		{
		  /* Use the PLT entry for an undefined symbol using
		     one.  */
		  is_def = TRUE;
		  to_ofst = h->plt.offset + irel->r_addend;
		  to_base = section_base (htab->elf.splt);
		}
	      else
		{
		  /* Cannot handle it; let it overflow.  */
		  is_def = FALSE;
		  continue;
		}
	      break;

	    default:
		{
		  /* Cannot handle it; let it overflow.  */
		  is_def = FALSE;
		  continue;
		}
	      break;
	    }
	}

      /* If the target is within range, a trampoline is not needed  */
      offset = (to_base + to_ofst) - (pk_base + pk_ofst);
      if (! is_def || ! HEXAGON_TRAMPOLINE_NEEDED (r_type, offset))
	continue;

      /* A trampoline is needed.  */

      if (h && h->def_dynamic && h->plt.offset != -(bfd_vma) 1)
	{
	  /* Perform belated GOT and PLT accounting
	     for symbols defined in a DSO.  */
	  if (!htab->elf.dynobj)
	    htab->elf.dynobj = ibfd;
	  if (!_bfd_elf_make_dynamic_reloc_section
	      (isec, htab->elf.dynobj, 2, ibfd, TRUE))
	    continue;

	  h->non_got_ref = TRUE;
	  h->pointer_equality_needed = TRUE;
	  h->needs_plt = TRUE;
	}

      /* Access the section contents.  */
      if (!contents)
	contents = elf_section_data (isec)->this_hdr.contents;
      if (!contents
	  && !bfd_malloc_and_get_section (ibfd, isec, &contents))
	goto error_return;

      /* Save these original reloc values.  */
      r_info = irel->r_info;
      r_addend = irel->r_addend;

      /* Subtract the offset of the branch into the packet from
	 the addendum.  */
      for (;
	   pk_ofst >= HEXAGON_INSN_LEN;
	   pk_ofst -= HEXAGON_INSN_LEN, irel->r_addend -= HEXAGON_INSN_LEN)
	{
	  hexagon_insn hinsn
	    = hexagon_get_insn (ibfd,
				hexagon_elf_howto_table + r_type,
				contents + pk_ofst - HEXAGON_INSN_LEN);
	  if (HEXAGON_END_PACKET_GET (hinsn) == HEXAGON_END_PACKET
	      || HEXAGON_END_PACKET_GET (hinsn) == HEXAGON_END_PAIR)
	    break;
	}

      /* Look for an existing trampoline that will work.  */
      trampFound = FALSE;
#define HEXAGON_MAX_TRAMP_NAMES 256
      for (i = 0; i < HEXAGON_MAX_TRAMP_NAMES; ++i)
	{
	  t_name
	    = bfd_malloc
		(HEXAGON_TRAMPOLINE_PREFIX_LEN
		 + 1 + strlen (name)	/* name of target symbol */
		 + 1 + 3		/* re-use number */
		 + 1			/* terminator */
		 );
          sprintf (t_name, HEXAGON_TRAMPOLINE_PREFIX ".%s.%d", name, i);

	  t_h = (struct elf_link_hash_entry *)
	        bfd_link_hash_lookup (info->hash, t_name, FALSE, FALSE, TRUE);
	  if (!t_h)
	    {
	      /* There is no trampoline by that (or subsequent) names.  */
	      break;
	    }

	  /* Get the effective address of the trampoline. */
	  tr_base = t_h->root.u.def.section->output_section->vma +
		    + t_h->root.u.def.section->output_offset;
	  tr_ofst = t_h->root.u.def.value;

	  /* Check if the trampoline is beyond reach.  */
	  offset = (tr_base + tr_ofst) - (pk_base + pk_ofst);
	  if (HEXAGON_TRAMPOLINE_NEEDED (r_type, offset))
	    {
	      /* This trampoline is out of range.  Try another.  */
	      continue;
	    }

	  /* Check if the trampoline belongs to another section, 
	     to avoid conditions like overlapping overlay sections.  */
	  if (t_h->root.u.def.section->output_section->id
	      != isec->output_section->id)
	    continue;

	  /* Use this trampoline.  */
	  trampFound = TRUE;
	  break;
	}
      if (i == HEXAGON_MAX_TRAMP_NAMES)
	{
	  /* No more trampoline names.
	     No more processing for this relocation. It will overflow.  */
	  continue;
	}
#undef HEXAGON_MAX_TRAMP_NAMES

      if (trampFound)
	{
	  /* Neutralize the current reloc.  */
	  irel->r_info = ELF32_R_INFO (ELF32_R_SYM (irel->r_info), R_HEX_NONE);
	}
      else
	{
	  /* If we can reach the end of the input section, add a new
	     trampoline there.  It will re-use the current reloc.  */
          offset = bfd_section_size (ibfd, isec) - pk_ofst;
          if (! HEXAGON_TRAMPOLINE_NEEDED (r_type, offset))
	    {
	      trampFound = hexagon_add_tramp (ibfd, isec, info, irel, t_name,
  					      &offset, &t_h);
	      if (trampFound)
		{
		  /* A new trampoline was added.
		     Other branches may have been pushed out of range.  */
	  	  contents = elf_section_data (isec)->this_hdr.contents;
		  *again = TRUE;
		}
	    }
	  if (! trampFound)
	    {
	      /* We could not add a trampoline.
		 No more processing for this relocation. It will overflow.  */
	      continue;
	    }
	}

      /* Add an internal fixup.  */
      if (! hexagon_save_fixup_to_tramp (isec, ireloc,
					 ju_ofst, r_info, r_addend,
 					 ju_ofst - pk_ofst, t_h))
	goto error_return;
    }
 
   /* If this input section has a jump around its trampolines, fix up the
      jump's offset.  */
  name = JUMP_AROUND_TRAMPS_NAME;
  t_name
    = bfd_malloc (HEXAGON_TRAMPOLINE_PREFIX_LEN + 8 + 1 + strlen (name) + 1);
  sprintf (t_name, HEXAGON_TRAMPOLINE_PREFIX "%08x.%s",
	   isec->id & 0xffffffff, name);

  t_h = (struct elf_link_hash_entry *)
    bfd_link_hash_lookup (info->hash, t_name, FALSE, FALSE, TRUE);
  if (!t_h)
    free (t_name);
  else
    {
      bfd_vma from, to;
      bfd_signed_vma offset;
      unsigned r_type = R_HEX_B22_PCREL;

      /* Fix up the branch around the trampolines. */
      from = t_h->root.u.def.value;

      to =
	isec_size = bfd_section_size (ibfd, isec);

      offset = to - from;
      if (HEXAGON_TRAMPOLINE_NEEDED (r_type, offset))
	{
	  /* No room to put the target.  */
	  (*_bfd_error_handler)
	    (_("%B: No room for trampoline, section=%A offset=0x%lx."),
	     ibfd, isec, (long)from);
	  bfd_set_error (bfd_error_bad_value);
	  goto error_return;
	}

      /* Make sure the contents are available.  */
      if (!contents)
	contents = elf_section_data (isec)->this_hdr.contents;
      if (!contents)
	if (!bfd_malloc_and_get_section (ibfd, isec, &contents))
	  goto error_return;

      /* Fix up the branch around the trampolines by pointing it here. */
      insn = bfd_get_32 (ibfd, (bfd_byte *) contents + from);
      offset >>= 1;
      insn =  HEXAGON_JUMP24;
      insn |= 0x01ff0000 & (offset << 2);
      insn |= 0x00003ffe & offset;
      bfd_put_32 (ibfd, insn, contents + from);
    }

ok_return:
  if (isymbuf && symtab_hdr->contents != (unsigned char *) isymbuf)
    free (isymbuf);
  if (contents && elf_section_data (isec)->this_hdr.contents != contents)
    free (contents);
  if (irelbuf && elf_section_data (isec)->relocs != irelbuf)
    free (irelbuf);

  return rc;

error_return:
  rc = FALSE;
  goto ok_return;
}

/* Implement elf_backend_copy_indirect_symbol.
   Copy the extra info we tack onto an elf_link_hash_entry.  */
static void
hexagon_elf_copy_indirect_symbol (struct bfd_link_info *info,
				  struct elf_link_hash_entry *dir,
				  struct elf_link_hash_entry *ind)
{
  hexagon_link_hash_entry *edir, *eind;

  edir = hexagon_hash_entry (dir);
  eind = hexagon_hash_entry (ind);

  if (eind->dyn_relocs)
    {
      if (edir->dyn_relocs)
	{
	  hexagon_dyn_reloc *p, **pp;

	  if (ind->root.type == bfd_link_hash_indirect)
	    abort ();

	  /* Add relocation counts against the weak symbol to the strong
	     symbol list.  Merge any entries against the same section.  */
	  for (pp = &eind->dyn_relocs; (p = *pp);)
	    {
	      hexagon_dyn_reloc *q;

	      for (q = edir->dyn_relocs; q; q = q->next)
		if (q->sec == p->sec)
		  {
		    q->pc_count += p->pc_count;
		    q->count += p->count;
		    *pp = p->next;
		    break;
		  }
	      if (!q)
		pp = &p->next;
	    }
	  *pp = edir->dyn_relocs;
	}

      edir->dyn_relocs = eind->dyn_relocs;
      eind->dyn_relocs = NULL;
    }

  if (ind->root.type == bfd_link_hash_indirect)
    {
      edir->ok_got.refcount += eind->ok_got.refcount;
      eind->ok_got.refcount = 0;
      edir->gd_got.refcount += eind->gd_got.refcount;
      eind->gd_got.refcount = 0;
      edir->gd_plt.refcount += eind->gd_plt.refcount;
      eind->gd_plt.refcount = 0;
      edir->ie_got.refcount += eind->ie_got.refcount;
      eind->ie_got.refcount = 0;
    }

  if (ELIMINATE_COPY_RELOCS
      && ind->root.type != bfd_link_hash_indirect
      && dir->dynamic_adjusted)
    {
      /* If called to transfer flags for a weakdef during processing
         of elf_adjust_dynamic_symbol, don't copy non_got_ref.
         We clear it ourselves for ELIMINATE_COPY_RELOCS.  */
      dir->ref_dynamic |= ind->ref_dynamic;
      dir->ref_regular |= ind->ref_regular;
      dir->ref_regular_nonweak |= ind->ref_regular_nonweak;
      dir->needs_plt |= ind->needs_plt;
      dir->pointer_equality_needed |= ind->pointer_equality_needed;
    }
  else
    _bfd_elf_link_hash_copy_indirect (info, dir, ind);
}

/* Create an entry in an ELF linker hash table.  */

static struct bfd_hash_entry *
hexagon_elf_link_hash_newfunc (struct bfd_hash_entry *entry,
			       struct bfd_hash_table *table,
			       const char *string)
{
  /* Allocate the structure if it has not already been allocated by a
     subclass.  */
  if (!entry)
    {
      entry = bfd_hash_allocate (table, sizeof (hexagon_link_hash_entry));
      if (!entry)
	return NULL;
    }

  /* Call the allocation method of the superclass.  */
  entry = _bfd_elf_link_hash_newfunc (entry, table, string);
  if (entry)
    {
      hexagon_hash_entry (entry)->dyn_relocs = NULL;
      hexagon_hash_entry (entry)->ok_got.refcount = 0;
      hexagon_hash_entry (entry)->gd_got.refcount = 0;
      hexagon_hash_entry (entry)->gd_plt.refcount = 0;
      hexagon_hash_entry (entry)->ie_got.refcount = 0;
    }

  return entry;
}

/* Implement bfd_elf32_bfd_link_hash_table_create.  */
static struct bfd_link_hash_table *
hexagon_elf_link_hash_table_create (bfd *abfd)
{
  hexagon_link_hash_table *htab
    = bfd_zalloc (abfd, sizeof (hexagon_link_hash_table));

  if (!htab)
    return NULL;
  if (!_bfd_elf_link_hash_table_init (&htab->elf, abfd,
				      hexagon_elf_link_hash_newfunc,
				      sizeof (struct _hexagon_link_hash_entry),
				      HEXAGON_ELF_DATA))
    {
      free (htab);
      return NULL;
    }

  htab->sym_cache.abfd = NULL;
  htab->gd_plt.refcount = 0;
  htab->gd_plt.gd_get = htab->gd_plt.ie_get = htab->gd_plt.le_get = NULL;
  htab->gd_got.refcount = 0;
  htab->gd_got.ld_got = NULL;
  htab->sda.s = NULL;
  htab->sda.h = NULL;
  htab->use_trampolines = FALSE;
  return &htab->elf.root;
}

/* Implement elf-backend_additional_program_headers.
   We may need to bump up the number of program headers beyond .text
   and .data.  */
static int
hexagon_elf_additional_program_headers
  (bfd *abfd,
   struct bfd_link_info *info ATTRIBUTE_UNUSED)
{
  asection *s;
  int extra = 0;

  /* In a good family, it would be merged with text.  */
  s = bfd_get_section_by_name (abfd, ".hash");
  if (s && s->flags & SEC_LOAD)
    extra++;

  /* Just in case, as used only by stand-alone mode.  */
  s = bfd_get_section_by_name (abfd, ".start");
  if (s && s->flags & SEC_LOAD)
    extra++;

  s = bfd_get_section_by_name (abfd, ".text");
  if (s && s->flags & SEC_LOAD)
    extra++;

  s = bfd_get_section_by_name (abfd, ".rodata");
  if (s && s->flags & SEC_LOAD)
    extra++;

  return extra;
}

/* Implement elf_backend_gc_mark_hook.  */
static asection *
hexagon_elf_gc_mark_hook (asection *sec,
			  struct bfd_link_info *info ATTRIBUTE_UNUSED,
			  Elf_Internal_Rela *rel ATTRIBUTE_UNUSED,
			  struct elf_link_hash_entry *h,
			  Elf_Internal_Sym *sym)
{
  if (h)
    {
      /* Global symbol.  */
      switch (h->root.type)
	{
	case bfd_link_hash_defined:
	case bfd_link_hash_defweak:
	  return h->root.u.def.section;

	case bfd_link_hash_common:
	  return h->root.u.c.p->section;

	default:
	  break;
	}
    }
  else
    /* Local symbol.  */
    return bfd_section_from_elf_index (sec->owner, sym->st_shndx);

  return NULL;
}

/* Create IE stub.  */

static void
hexagon_init_ie_get (bfd *abfd, struct bfd_link_info *info)
{
  asection *s;
  size_t size = sizeof (hexagon_ie_get);
  size_t i, j;
  hexagon_link_hash_table *htab = hexagon_hash_table (info);

  if (htab->gd_plt.ie_get)
    return;

  /* Create section for stub.  */
  s = bfd_make_section_with_flags
    (abfd, ".text" "." TLS_GET_ADDR_IE,
     (SEC_ALLOC | SEC_LOAD | SEC_CODE | SEC_LINK_ONCE
      | SEC_HAS_CONTENTS | SEC_IN_MEMORY));
  BFD_ASSERT (s);

  /* Initialize stub section.  */
  bfd_set_section_alignment (abfd, s, bfd_log2 (size));
  bfd_set_section_size (abfd, s, size);
  s->contents = bfd_malloc (size);
  for (i = 0, j = 0; i < size; i += HEXAGON_INSN_LEN, j++)
    bfd_put_32 (abfd, hexagon_ie_get[j], s->contents + i);

  /* Create the symbol for the stub.  */
  htab->gd_plt.ie_get
    = hexagon_hash_entry
    (bfd_link_hash_lookup (info->hash, TLS_GET_ADDR_IE,
			   TRUE, FALSE, TRUE));
  BFD_ASSERT (htab->gd_plt.ie_get);

  _bfd_elf_define_linkage_sym (abfd, info, s, TLS_GET_ADDR_IE);

  htab->gd_plt.ie_get->elf.type = STT_FUNC;
  htab->gd_plt.ie_get->elf.size = size;
}

/* Create LE stub.  */

static void
hexagon_init_le_get (bfd *abfd, struct bfd_link_info *info)
{
  asection *s;
  size_t size = sizeof (hexagon_le_get);
  size_t i, j;
  hexagon_link_hash_table *htab = hexagon_hash_table (info);

  if (htab->gd_plt.le_get)
    return;

  /* Create section for stub.  */
  s = bfd_make_section_with_flags
    (abfd, ".text" "." TLS_GET_ADDR_LE,
     (SEC_ALLOC | SEC_LOAD | SEC_CODE | SEC_LINK_ONCE
      | SEC_HAS_CONTENTS | SEC_IN_MEMORY));
  BFD_ASSERT (s);

  /* Initialize stub section.  */
  bfd_set_section_alignment (abfd, s, bfd_log2 (size));
  bfd_set_section_size (abfd, s, size);
  s->contents = bfd_malloc (size);
  for (i = 0, j = 0; i < size; i += HEXAGON_INSN_LEN, j++)
    bfd_put_32 (abfd, hexagon_le_get[j], s->contents + i);

  /* Create the symbol for the stub.  */
  htab->gd_plt.le_get
    = hexagon_hash_entry
    (bfd_link_hash_lookup (info->hash, TLS_GET_ADDR_LE,
			   TRUE, FALSE, TRUE));
  BFD_ASSERT (htab->gd_plt.le_get);

  _bfd_elf_define_linkage_sym (abfd, info, s, TLS_GET_ADDR_LE);

  htab->gd_plt.le_get->elf.type = STT_FUNC;
  htab->gd_plt.le_get->elf.size = size;
}

/* Lookup or create __tls_get_addr symbol.  */

static void
hexagon_init_gd_get (bfd *abfd, struct bfd_link_info *info)
{
  hexagon_link_hash_table *htab = hexagon_hash_table (info);

  /* Lookup for  __tls_get_addr.  */
  if (!htab->gd_plt.gd_get)
    htab->gd_plt.gd_get
      = hexagon_hash_entry
      (bfd_link_hash_lookup (info->hash, TLS_GET_ADDR_GD,
			     FALSE, FALSE, TRUE));
  if (htab->gd_plt.gd_get)
    {
      while (htab->gd_plt.gd_get->elf.root.type == bfd_link_hash_indirect)
	htab->gd_plt.gd_get = htab->gd_plt.gd_get->elf.root.u.i.link;
      return;
    }

  /* Create the symbol for __tls_get_addr.  */
  htab->gd_plt.gd_get
    = hexagon_hash_entry
    (bfd_link_hash_lookup (info->hash, TLS_GET_ADDR_GD,
			   TRUE, FALSE, TRUE));
  BFD_ASSERT (htab->gd_plt.gd_get);

  htab->gd_plt.gd_get->elf.root.type =
    bfd_link_hash_undefined;
  htab->gd_plt.gd_get->elf.root.u.undef.abfd = abfd;
  bfd_link_add_undef (&htab->elf.root,
		      &htab->gd_plt.gd_get->elf.root);

  htab->gd_plt.gd_get->elf.type = STT_FUNC;
}

/* Create the __hexagon_ld_tls_index symbol.  */

static void
hexagon_init_ld_got (bfd *abfd, struct bfd_link_info *info)
{
  hexagon_link_hash_table *htab = hexagon_hash_table (info);

  if (htab->gd_got.ld_got)
    return;

  /* Create the symbol for the entry.  */
  htab->gd_got.ld_got
    = hexagon_hash_entry
    (bfd_link_hash_lookup (info->hash, TLS_GOT_ENTRY_LD,
			   TRUE, FALSE, TRUE));
  BFD_ASSERT (htab->gd_got.ld_got);
  _bfd_elf_define_linkage_sym
    (abfd, info, bfd_abs_section_ptr, TLS_GOT_ENTRY_LD);
}

/* Implement elf_backend_relocate_section.  */
static bfd_boolean
hexagon_elf_relocate_section (bfd *obfd, struct bfd_link_info *info,
			      bfd *ibfd, asection *isection,
			      bfd_byte *contents,
			      Elf_Internal_Rela *relocs,
			      Elf_Internal_Sym *local_syms,
			      asection **local_sections)
{
  hexagon_link_hash_table *htab;
  Elf_Internal_Shdr *symtab_hdr;
  struct elf_link_hash_entry **sym_hashes;
  bfd_vma *local_got_offsets;
  Elf_Internal_Rela *rel;
  const Elf_Internal_Rela *relend;

  if (info->relocatable)
    return TRUE;

  htab = hexagon_hash_table (info);
  symtab_hdr = &elf_tdata (ibfd)->symtab_hdr;
  sym_hashes = elf_sym_hashes (ibfd);
  local_got_offsets = elf_local_got_offsets (ibfd);
  relend = relocs + isection->reloc_count;

  for (rel = relocs; rel < relend; rel++)
    {
      unsigned int r_type;
      reloc_howto_type *howto;
      size_t r_symndx;
      Elf_Internal_Sym *sym = NULL;
      asection *sec = NULL;
      struct elf_link_hash_entry *h = NULL;
      hexagon_link_hash_entry *eh = NULL;
      bfd_vma relocation, offset;
      bfd_vma lmask = ~(bfd_vma) 0, rmask = ~(bfd_vma) 0;
      bfd_reloc_status_type r;
      asection *sreloc = NULL;
      const char *name = NULL;
      bfd_boolean initialized;

      r_type = ELF32_R_TYPE (rel->r_info);
      r_symndx = ELF32_R_SYM (rel->r_info);

      if (r_type >= R_HEX_max)
	{
	  (*_bfd_error_handler)
	    (_("%B: invalid relocation type `%d\' in section `%A\'"),
	     ibfd, isection, r_type);
	  bfd_set_error (bfd_error_bad_value);
	  return FALSE;
	}
      else
	howto = hexagon_elf_howto_table + r_type;

      if (r_symndx < symtab_hdr->sh_info)
	{
	  /* Local symbol.  */
	  sym = local_syms + r_symndx;
	  sec = local_sections[r_symndx];

	  if (sec && elf_discarded_section (sec))
	    RELOC_AGAINST_DISCARDED_SECTION (info, ibfd, isection,
					     rel, relend, howto, contents);

	  name = bfd_elf_string_from_elf_section (ibfd, symtab_hdr->sh_link,
						  sym->st_name);
	  if (!name || !*name)
	    name = bfd_section_name (ibfd, sec);

	  if (r_type == R_HEX_GD_PLT_B22_PCREL
	      || r_type == R_HEX_LD_PLT_B22_PCREL
	      || r_type == R_HEX_GD_GOT_LO16
	      || r_type == R_HEX_GD_GOT_HI16
	      || r_type == R_HEX_GD_GOT_32
	      || r_type == R_HEX_GD_GOT_16
	      || r_type == R_HEX_LD_GOT_LO16
	      || r_type == R_HEX_LD_GOT_HI16
	      || r_type == R_HEX_LD_GOT_32
	      || r_type == R_HEX_LD_GOT_16)
	    /* Calculate the relocation further down,
	       in case a transition is due.  */
	    relocation = FALSE;
	  else
	    relocation = _bfd_elf_rela_local_sym (obfd, sym, &sec, rel);
	}
      else
	{
	  /* Global symbol.  */
	  h = sym_hashes[r_symndx - symtab_hdr->sh_info];
	  while (h->root.type == bfd_link_hash_indirect
		 || h->root.type == bfd_link_hash_warning)
	    h = (struct elf_link_hash_entry *) h->root.u.i.link;
	  eh = hexagon_hash_entry (h);
	  name = h->root.root.string;

	  if (h->root.type == bfd_link_hash_defined
	      || h->root.type == bfd_link_hash_defweak)
	    {
	      /* TODO: is this condition OK for dynamic linking? */
	      if (elf_discarded_section (h->root.u.def.section)
		  && !hexagon_kept_hash_lookup (obfd, info, ibfd, rel, h))
		{
		  if (isection->flags & SEC_DEBUGGING)
		    {
		      /* For relocs in debug section against symbols from
		         discarded sections, avoid any special processing.  */
		      rel->r_info = 0;
		      rel->r_addend = 0;
		      continue;
		    }
		  else
		    {
		      info->callbacks->undefined_symbol
			(info, h->root.root.string, ibfd,
			 isection, rel->r_offset, 0);
		      return FALSE;
		    }
		}

	      /* TODO: in some cases, the output section will not be knwon,
	         such as when the symbol is in a DSO, otherwise consider them
	         errors.  */
	      relocation = TRUE;
	      switch (r_type)
		{
		case R_HEX_TRAMPOLINE:
		case R_HEX_B32_PCREL_X:
		case R_HEX_B22_PCREL:
		case R_HEX_B22_PCREL_X:
		case R_HEX_B15_PCREL:
		case R_HEX_B15_PCREL_X:
		case R_HEX_B13_PCREL:
		case R_HEX_B13_PCREL_X:
		case R_HEX_B9_PCREL:
		case R_HEX_B9_PCREL_X:
		case R_HEX_B7_PCREL:
		case R_HEX_B7_PCREL_X:
		  /* TODO: In PPC the tests in all cases include
		     visibility too.  */
		  if (info->shared
		      && !SYMBOL_CALLS_LOCAL (info, h)
		      && isection->flags & SEC_ALLOC)
		    relocation = FALSE;

		  /* Fall-through.  */

		case R_HEX_PLT_B22_PCREL:
		  if (!SYMBOL_CALLS_LOCAL (info, h)
		      && h->plt.offset != -(bfd_vma) 1)
		    relocation = FALSE;
		  break;

		case R_HEX_GD_PLT_B22_PCREL:
		case R_HEX_LD_PLT_B22_PCREL:
		  /* Mapped onto either the actual __tls_get_addr
		     or the local stub below.  */
		  relocation = FALSE;
		  break;

		case R_HEX_GOT_LO16:
		case R_HEX_GOT_HI16:
		case R_HEX_GOT_32:
		case R_HEX_GOT_16:
		case R_HEX_GOT_32_6_X:
		case R_HEX_GOT_16_X:
		case R_HEX_GOT_11_X:
		case R_HEX_GD_GOT_LO16:
		case R_HEX_GD_GOT_HI16:
		case R_HEX_GD_GOT_32:
		case R_HEX_GD_GOT_16:
		case R_HEX_GD_GOT_32_6_X:
		case R_HEX_GD_GOT_16_X:
		case R_HEX_GD_GOT_11_X:
		case R_HEX_LD_GOT_LO16:
		case R_HEX_LD_GOT_HI16:
		case R_HEX_LD_GOT_32:
		case R_HEX_LD_GOT_16:
		case R_HEX_LD_GOT_32_6_X:
		case R_HEX_LD_GOT_16_X:
		case R_HEX_LD_GOT_11_X:
		case R_HEX_IE_LO16:
		case R_HEX_IE_HI16:
		case R_HEX_IE_32:
		case R_HEX_IE_32_6_X:
		case R_HEX_IE_16_X:
		case R_HEX_IE_GOT_LO16:
		case R_HEX_IE_GOT_HI16:
		case R_HEX_IE_GOT_32:
		case R_HEX_IE_GOT_16:
		case R_HEX_IE_GOT_32_6_X:
		case R_HEX_IE_GOT_16_X:
		case R_HEX_IE_GOT_11_X:
		  if (htab->elf.dynamic_sections_created
		      && !SYMBOL_REFERENCES_LOCAL (info, h))
		    relocation = FALSE;
		  break;

		case R_HEX_LO16:
		case R_HEX_HI16:
		case R_HEX_32:
		  if (!SYMBOL_REFERENCES_LOCAL (info, h) && !h->non_got_ref)
		    relocation = FALSE;
		  break;
		}

	      if (relocation)
		{
		  if (!h->root.u.def.section->output_section)
		    {
		      relocation = FALSE;
		      (*_bfd_error_handler)
			(_
			 ("%B: relocation %s for symbol `%s\' in section `%A\' "
			  "cannot be resolved"),
			 ibfd, isection,
			 hexagon_elf_howto_table[r_type].name, name);
		      bfd_set_error (bfd_error_bad_value);
		      return FALSE;
		    }
		  else
		    relocation = elf_hash_address (h);
		}
	    }
	  else if (h->root.type == bfd_link_hash_undefweak)
	    relocation = FALSE;
	  else if (info->shared
		   && info->unresolved_syms_in_objects <= RM_IGNORE
		   && ELF_ST_VISIBILITY (h->other) == STV_DEFAULT)
	    relocation = FALSE;
	  else if (!((*info->callbacks->undefined_symbol)
		     (info, h->root.root.string, ibfd, isection, rel->r_offset,
		      (info->executable
		       || (info->unresolved_syms_in_objects
			   >= RM_GENERATE_WARNING)
		       || ELF_ST_VISIBILITY (h->other)))))
	    return FALSE;
	  else
	    {
	      relocation = FALSE;
	      continue;
	    }
	}

      /* Check relocations for correctness.  */
      switch (r_type)
	{
	case R_HEX_GOTREL_LO16:
	case R_HEX_GOTREL_HI16:
	case R_HEX_GOTREL_32:
	case R_HEX_GOTREL_32_6_X:
	case R_HEX_GOTREL_16_X:
	case R_HEX_GOTREL_11_X:
	  /* This can happen if we get a link error with the input ELF
	     variant mismatching the output variant.  Emit an error so
	     it's noticed if it happens elsewhere.  */
	  if (!htab->elf.sgotplt)
	    {
	      (*_bfd_error_handler)
		(_("%B: relocation %s for symbol `%s\' in section `%A\' "
		   "cannot be handled with no GOT created"),
		 ibfd, isection, hexagon_elf_howto_table[r_type].name, name);
	      bfd_set_error (bfd_error_bad_value);
	      return FALSE;
	    }
	  break;
	}

      /* Preprocess relocations for dynamic linking.  */
      switch (r_type)
	{
	case R_HEX_GOT_LO16:
	case R_HEX_GOT_HI16:
	case R_HEX_GOT_32:
	case R_HEX_GOT_16:
	case R_HEX_GOT_32_6_X:
	case R_HEX_GOT_16_X:
	case R_HEX_GOT_11_X:
	  if (h)
	    {
	      /* Global symbol.  */
	      BFD_ASSERT (h->got.offset != -(bfd_vma) 1);
	      offset = h->got.offset;

	      if (!WILL_CALL_FINISH_DYNAMIC_SYMBOL 
		    (htab->elf.dynamic_sections_created, info->shared, h)
		  || (info->shared && SYMBOL_REFERENCES_LOCAL (info, h))
		  || (ELF_ST_VISIBILITY (h->other)
		      && h->root.type == bfd_link_hash_undefweak))
		{
		  /* This wasn't checked above for non-shared, but must hold
		     true through here: the symbol must be defined in the
		     program, or be weakly undefined.  */
		  BFD_ASSERT (!htab->elf.dynamic_sections_created
			      || info->shared
			      || h->def_regular
			      || h->root.type == bfd_link_hash_undefweak);

		  /* This is actually a static link, or it is a -Bsymbolic
		     link and the symbol is defined locally, or is weakly
		     undefined, or the symbol was forced to be local because
		     of a version file, or not linking a dynamic object.
		     This GOT entry must be initialized.  Since the offset
		     must always be a multiple of 4, the least significant bit
		     is used to record whether the entry has already been
		     initialized.

		     If this GOT entry should be initialized at run-time,
		     a relocation in .rela.got willbe created then.  This
		     is done in finish_dynamic_symbol.  */
		  BFD_ASSERT ((offset & 2) == 0);
		  if (offset & 1)
		    offset &= ~1;
		  else
		    {
		      if (relocation)
			bfd_put_32 (obfd, relocation,
				    htab->elf.sgot->contents + offset);

		      h->got.offset |= 1;
		    }
		}
	    }
	  else
	    {
	      /* Local symbol.  */
	      BFD_ASSERT (local_got_offsets
			  && local_got_offsets[r_symndx] != -(bfd_vma) 1);
	      offset = local_got_offsets[r_symndx];

	      /* Since the offset must always be a multiple of 4, the least
	         significant bit is used to record whether the GOT entry has
	         already been initialized.  */
	      BFD_ASSERT ((offset & 2) == 0);
	      if (offset & 1)
		offset &= ~1;
	      else
		{
		  if (info->shared)
		    {
		      Elf_Internal_Rela outrel;
		      bfd_byte *loc;

		      outrel.r_info = ELF32_R_INFO (0, R_HEX_RELATIVE);
		      outrel.r_offset = section_base (htab->elf.sgot) + offset;
		      outrel.r_addend = relocation;

		      BFD_ASSERT ((htab->elf.srelgot->reloc_count
				   * sizeof (Elf32_External_Rela))
				  < htab->elf.srelgot->size);
		      loc = (htab->elf.srelgot->contents
			     + htab->elf.srelgot->reloc_count++
			     * sizeof (Elf32_External_Rela));
		      bfd_elf32_swap_reloca_out (obfd, &outrel, loc);
		    }
		  else
		    bfd_put_32 (obfd, relocation,
				htab->elf.sgot->contents + offset);

		  local_got_offsets[r_symndx] |= 1;
		}
	    }

	  relocation = (section_base (htab->elf.sgot)
			- section_base (htab->elf.sgotplt)
			+ offset);
	  break;

	case R_HEX_GOTREL_LO16:
	case R_HEX_GOTREL_HI16:
	case R_HEX_GOTREL_32:
	case R_HEX_GOTREL_32_6_X:
	case R_HEX_GOTREL_16_X:
	case R_HEX_GOTREL_11_X:
	  /* These relocations are like a PC-relative one, except the
	     reference point is the location of _GLOBAL_OFFSET_TABLE_.  Note
	     that sgot->output_offset is not involved in this calculation.
	     We always want the start of entire GOT section, or wherever
	     _GLOBAL_OFFSET_TABLE_ is, not the position after the reserved
	     header.  */
	  relocation -= section_base (htab->elf.sgotplt);
	  break;

	case R_HEX_TRAMPOLINE:
	case R_HEX_PLT_B22_PCREL:
	case R_HEX_B32_PCREL_X:
	case R_HEX_B22_PCREL:
	case R_HEX_B22_PCREL_X:
	case R_HEX_B15_PCREL:
	case R_HEX_B15_PCREL_X:
	case R_HEX_B13_PCREL:
	case R_HEX_B13_PCREL_X:
	case R_HEX_B9_PCREL:
	case R_HEX_B9_PCREL_X:
	case R_HEX_B7_PCREL:
	case R_HEX_B7_PCREL_X:
	  /* Relocation is to the entry for this symbol in the PLT.  */
	  if (SYMBOL_CALLS_LOCAL (info, h))
	    /* Resolve a PLT relocation against a local symbol directly,
	       without using the PLT.  */
	    break;

	  if (h->plt.offset != -(bfd_vma) 1 && htab->elf.splt)
	    {
	      /* We did make a PLT entry for this symbol.  This does not happen
	         when linking PIC code statically or when using -Bsymbolic.  */
	      relocation = section_base (htab->elf.splt) + h->plt.offset;
	      break;
	    }

	  if (r_type == R_HEX_TRAMPOLINE || r_type == R_HEX_PLT_B22_PCREL)
	    break;

	  /* Fall-through.  */

	case R_HEX_LO16:
	case R_HEX_HI16:
	case R_HEX_32:
	case R_HEX_16:
	case R_HEX_8:
	case R_HEX_32_6_X:
	case R_HEX_16_X:
	case R_HEX_12_X:
	case R_HEX_11_X:
	case R_HEX_10_X:
	case R_HEX_9_X:
	case R_HEX_8_X:
	case R_HEX_7_X:
	case R_HEX_6_X:
	  /* r_symndx will be zero only for relocations against symbols from
	     removed link-once sections or from sections discarded by the
	     linker script.  */
	  if (!r_symndx || !(isection->flags & SEC_ALLOC))
	    break;

	  if ((info->shared
	       && (!h
		   || ELF_ST_VISIBILITY (h->other) == STV_DEFAULT
		   || h->root.type != bfd_link_hash_undefweak)
	       && (!howto->pc_relative
		   || !SYMBOL_CALLS_LOCAL (info, h)))
	      || (ELIMINATE_COPY_RELOCS
		  && info->executable
		  && h
		  && h->dynindx != -1
		  && !h->non_got_ref
		  && h->def_dynamic
		  && !h->def_regular))
	    {
	      /* When generating a DSO, these relocations are copied into
	         the output file to be resolved at run-time.  */

	      Elf_Internal_Rela outrel;
	      bfd_byte *loc;
	      bfd_boolean skip, relocate;

	      sreloc = elf_section_data (isection)->sreloc;
	      /* FIXME: This can happen when creating a DSO and an object
	         contains a non-PLT branch to a symbol in another DSO.
	         The same condition is harmless when creating a program.  */
	      if (!sreloc || !sreloc->contents)
		{
		  if (info->shared)
		    sreloc = _bfd_elf_get_dynamic_reloc_section (ibfd, isection,
								 TRUE);
		  if (!sreloc || !sreloc->contents)
		    {
		      if (h)
			(*_bfd_error_handler)
			  (_("%B: erroneous reference to symbol `%s\'"
			     " in section `%A\'"),
			   ibfd, isection,
			   h->root.root.string);
		      else
			(*_bfd_error_handler)
			  (_("%B: erroneous reference in section `%A\'"),
			   ibfd, isection);
		      bfd_set_error (bfd_error_bad_value);
		      return FALSE;
		    }
		}

	      skip = FALSE;
	      relocate = FALSE;
	      outrel.r_offset = _bfd_elf_section_offset (obfd, info, isection,
							 rel->r_offset);
	      if (outrel.r_offset == -(bfd_vma) 1)
		skip = TRUE;
	      else if (outrel.r_offset == -(bfd_vma) 2)
		{
		  skip = TRUE;
		  relocate = TRUE;
		}
	      else
		outrel.r_offset += section_base (isection);

	      if (skip)
		memset (&outrel, 0, sizeof (outrel));
	      /* h->dynindx may be -1 if the symbol was marked to
		 become local.  */
	      else if (h
		       && h->dynindx != -1
		       && (howto->pc_relative
			   || info->executable
			   || !SYMBOLIC_BIND (info, h)
			   || !h->def_regular))
		{
		  outrel.r_info = ELF32_R_INFO (h->dynindx, r_type);
		  outrel.r_addend = relocation + rel->r_addend;
		}
	      else
		{
		  if (r_type == R_HEX_32)
		    {
		      relocate = TRUE;
		      outrel.r_info = ELF32_R_INFO (0, R_HEX_RELATIVE);
		      outrel.r_addend = relocation + rel->r_addend;
		    }
		  else
		    {
		      int indx;

		      if (!h)
			sec = local_sections[r_symndx];
		      else
			{
			  BFD_ASSERT (h->root.type == bfd_link_hash_defined
				      || (h->root.type
					  == bfd_link_hash_defweak));
			  sec = h->root.u.def.section;
			}

		      if (sec && bfd_is_abs_section (sec))
			indx = 0;
		      else if (!sec || !sec->owner)
			{
			  /* TODO: Add error message.  */
			  bfd_set_error (bfd_error_bad_value);
			  return FALSE;
			}
		      else
			{
			  asection *outsec = sec->output_section;
			  indx = elf_section_data (outsec)->dynindx;
			  if (!indx)
			    {
			      outsec = htab->elf.text_index_section;
			      indx = elf_section_data (outsec)->dynindx;
			    }
			  BFD_ASSERT (indx > 0);
			}

		      outrel.r_info = ELF32_R_INFO (indx, r_type);
		      outrel.r_addend = relocation + rel->r_addend;
		    }
		}

	      BFD_ASSERT (sreloc->reloc_count * sizeof (Elf32_External_Rela)
			  < sreloc->size);
	      loc = (sreloc->contents
		     + sreloc->reloc_count++ * sizeof (Elf32_External_Rela));
	      bfd_elf32_swap_reloca_out (obfd, &outrel, loc);

	      /* This relocation will be computed at runtime, so there's no
	         need to do anything now, except for R_HEX_32 relocations
	         that have been turned into R_HEX_RELATIVE.  */
	      if (!relocate)
		continue;
	    }
	  break;
	}

      /* Preprocess the relocations for TLS types.  */
      switch (r_type)
	{
	case R_HEX_GD_GOT_LO16:
	case R_HEX_GD_GOT_HI16:
	case R_HEX_GD_GOT_32:
	case R_HEX_GD_GOT_16:
	case R_HEX_GD_GOT_32_6_X:
	case R_HEX_GD_GOT_16_X:
	case R_HEX_GD_GOT_11_X:
	case R_HEX_LD_GOT_LO16:
	case R_HEX_LD_GOT_HI16:
	case R_HEX_LD_GOT_32:
	case R_HEX_LD_GOT_16:
	case R_HEX_LD_GOT_32_6_X:
	case R_HEX_LD_GOT_16_X:
	case R_HEX_LD_GOT_11_X:
	  if (is_gd_rel (r_type))
	    {
	      if (h)
		{
		  /* Global symbol.  */
		  BFD_ASSERT (h->got.offset != -(bfd_vma) 1);
		  BFD_ASSERT (h != &htab->gd_got.ld_got->elf);
		  offset = h->got.offset;
		}
	      else
		{
		  /* Local symbol.  */
		  BFD_ASSERT (local_got_offsets
			      && local_got_offsets[r_symndx] != -(bfd_vma) 1);
		  offset = local_got_offsets[r_symndx];
		  relocation = _bfd_elf_rela_local_sym (obfd, sym, &sec, rel);
		}

	      initialized = offset & 1;
	      offset &= ~3;
	      if (!initialized)
		{
		  if (relocation)
		    bfd_put_32
		      (obfd,
		       (TLS_TRANSIT_OK (info, h)
			? hexagon_elf_tpoff (info, relocation)
			: hexagon_elf_dtpoff (info, relocation)),
		       htab->elf.sgot->contents + offset + GOT_ENTRY_SIZE);

		  if (!h)
		    {
		      Elf_Internal_Rela rela;
		      rela.r_offset = section_base (htab->elf.sgot) + offset;
		      rela.r_info = ELF32_R_INFO (0, R_HEX_DTPMOD_32);
		      rela.r_addend = 0;
		      BFD_ASSERT ((htab->elf.srelgot->reloc_count
				   * sizeof (Elf32_External_Rela))
				  < htab->elf.srelgot->size);
		      bfd_elf32_swap_reloca_out
			(obfd, &rela,
			 (htab->elf.srelgot->contents
			  + (htab->elf.srelgot->reloc_count++
			     * sizeof (Elf32_External_Rela))));
		    }

		  if (h)
		    h->got.offset |= 1;
		  else
		    local_got_offsets[r_symndx] |= 1;
		}
	    }
	  else
	    {
	      /* Local symbol.  */
	      BFD_ASSERT (htab->gd_got.ld_got
			  && (htab->gd_got.ld_got->elf.got.offset
			      != -(bfd_vma) 1));
	      offset = htab->gd_got.ld_got->elf.got.offset;

	      initialized = offset & 1;
	      offset &= ~3;
	      if (!initialized)
		{
		  Elf_Internal_Rela rela;
		  rela.r_offset = section_base (htab->elf.sgot) + offset;
		  rela.r_info = ELF32_R_INFO (0, R_HEX_DTPMOD_32);
		  rela.r_addend = 0;
		  BFD_ASSERT ((htab->elf.srelgot->reloc_count
			       * sizeof (Elf32_External_Rela))
			      < htab->elf.srelgot->size);
		  bfd_elf32_swap_reloca_out
		    (obfd, &rela,
		     (htab->elf.srelgot->contents
		      + (htab->elf.srelgot->reloc_count++
			 * sizeof (Elf32_External_Rela))));

		  htab->gd_got.ld_got->elf.got.offset |= 1;
		}
	    }

	  relocation = (section_base (htab->elf.sgot)
			- section_base (htab->elf.sgotplt)
			+ offset);
	  break;

	case R_HEX_IE_LO16:
	case R_HEX_IE_HI16:
	case R_HEX_IE_32:
	case R_HEX_IE_32_6_X:
	case R_HEX_IE_16_X:
	case R_HEX_IE_GOT_LO16:
	case R_HEX_IE_GOT_HI16:
	case R_HEX_IE_GOT_32:
	case R_HEX_IE_GOT_16:
	case R_HEX_IE_GOT_32_6_X:
	case R_HEX_IE_GOT_16_X:
	case R_HEX_IE_GOT_11_X:
	  {
	    bfd_vma adjust = 0;

	    if (h)
	      {
		/* Global symbol.  */
		BFD_ASSERT (h->got.offset != -(bfd_vma) 1);
		offset = h->got.offset;
		if (eh->gd_got.refcount > 0)
		  adjust = GOT_ENTRY_SIZE * 2;

		initialized = offset & 2;
		offset &= ~3;
		if (!initialized)
		  {
		    if (relocation)
		      bfd_put_32 (obfd, hexagon_elf_tpoff (info, relocation),
				  htab->elf.sgot->contents + offset + adjust);
		    h->got.offset |= 2;
		  }
	      }
	    else
	      {
		bfd_signed_vma *local_got_refcounts;

		local_got_refcounts = elf_local_got_refcounts (ibfd);
		/* Local symbol.  */
		BFD_ASSERT (local_got_offsets
			    && local_got_offsets[r_symndx] != -(bfd_vma) 1);
		offset = local_got_offsets[r_symndx];
		if (local_got_refcounts[LGOT_GD (symtab_hdr, r_symndx)] > 0)
		  adjust = GOT_ENTRY_SIZE * 2;

		initialized = offset & 2;
		offset &= ~3;
		if (!initialized)
		  {
		    if (info->shared)
		      {
			Elf_Internal_Rela outrel;
			bfd_byte *loc;

			outrel.r_info = ELF32_R_INFO (0, R_HEX_TPREL_32);
			outrel.r_offset = (section_base (htab->elf.sgot)
					   + offset + adjust);
			outrel.r_addend = hexagon_elf_dtpoff (info, relocation);

			BFD_ASSERT ((htab->elf.srelgot->reloc_count
				     * sizeof (Elf32_External_Rela))
				    < htab->elf.srelgot->size);
			loc = (htab->elf.srelgot->contents
			       + htab->elf.srelgot->reloc_count++
			       * sizeof (Elf32_External_Rela));
			bfd_elf32_swap_reloca_out (obfd, &outrel, loc);
		      }
		    else
		      bfd_put_32 (obfd, hexagon_elf_tpoff (info, relocation),
				  htab->elf.sgot->contents + offset + adjust);
		    local_got_offsets[r_symndx] |= 2;
		  }
	      }

	    switch (r_type)
	      {
	      case R_HEX_IE_LO16:
	      case R_HEX_IE_HI16:
	      case R_HEX_IE_32:
	      case R_HEX_IE_32_6_X:
	      case R_HEX_IE_16_X:
		/* Resolves to the address of a GOT entry.  */
		relocation = section_base (htab->elf.sgot) + offset + adjust;
		break;

	      case R_HEX_IE_GOT_LO16:
	      case R_HEX_IE_GOT_HI16:
	      case R_HEX_IE_GOT_32:
	      case R_HEX_IE_GOT_16:
	      case R_HEX_IE_GOT_32_6_X:
	      case R_HEX_IE_GOT_16_X:
	      case R_HEX_IE_GOT_11_X:
		/* Resolves to the offset of a GOT entry.  */
		relocation = (section_base (htab->elf.sgot)
			      - section_base (htab->elf.sgotplt)
			      + offset + adjust);
		break;
	      }
	  }
	  break;

	case R_HEX_DTPREL_LO16:
	case R_HEX_DTPREL_HI16:
	case R_HEX_DTPREL_32:
	case R_HEX_DTPREL_16:
	case R_HEX_DTPREL_32_6_X:
	case R_HEX_DTPREL_16_X:
	case R_HEX_DTPREL_11_X:
	  if (!TLS_TRANSIT_OK (info, h))
	    {
	      relocation = hexagon_elf_dtpoff (info, relocation);
	      break;
	    }

	  /* Fall-through.  */

	case R_HEX_TPREL_LO16:
	case R_HEX_TPREL_HI16:
	case R_HEX_TPREL_32:
	case R_HEX_TPREL_16:
	case R_HEX_TPREL_32_6_X:
	case R_HEX_TPREL_16_X:
	case R_HEX_TPREL_11_X:
	  relocation = hexagon_elf_tpoff (info, relocation);
	  break;

	case R_HEX_GD_PLT_B22_PCREL:
	case R_HEX_LD_PLT_B22_PCREL:
	  if (TLS_TRANSIT_OK (info, h))
	    relocation = hexagon_hash_address (r_type == R_HEX_LD_PLT_B22_PCREL
					       ? htab->gd_plt.le_get
					       : htab->gd_plt.ie_get);
	  else
	    {
	      /* Request the actual __tls_get_addr.  */
	      hexagon_init_gd_get (ibfd, info);
	      if (htab->elf.splt
		  && htab->gd_plt.gd_get->elf.plt.offset != -(bfd_vma) 1)
		relocation = (section_base (htab->elf.splt)
			      + htab->gd_plt.gd_get->elf.plt.offset);
	      else if (htab->gd_plt.gd_get
		       && (htab->gd_plt.gd_get->elf.root.type
			   == bfd_link_hash_defined))
		relocation = hexagon_hash_address (htab->gd_plt.gd_get);
	      else
		BFD_ASSERT (FALSE);
	    }

	  break;
	}

      /* Apply relocation.  */
      switch (r_type)
	{
	  hexagon_insn insn;

	case R_HEX_32_6_X:
	case R_HEX_GOTREL_32_6_X:
	case R_HEX_GOT_32_6_X:
	case R_HEX_GD_GOT_32_6_X:
	case R_HEX_LD_GOT_32_6_X:
	case R_HEX_IE_32_6_X:
	case R_HEX_IE_GOT_32_6_X:
	case R_HEX_DTPREL_32_6_X:
	case R_HEX_TPREL_32_6_X:
	  rmask = howto->src_mask;
	  /* Fall through.  */

	case R_HEX_6_X:
	case R_HEX_7_X:
	case R_HEX_8_X:
	case R_HEX_9_X:
	case R_HEX_10_X:
	case R_HEX_11_X:
	case R_HEX_12_X:
	case R_HEX_16_X:
	case R_HEX_GOTREL_16_X:
	case R_HEX_GOTREL_11_X:
	case R_HEX_GOT_16_X:
	case R_HEX_GOT_11_X:
	case R_HEX_GD_GOT_16_X:
	case R_HEX_GD_GOT_11_X:
	case R_HEX_LD_GOT_16_X:
	case R_HEX_LD_GOT_11_X:
	case R_HEX_IE_16_X:
	case R_HEX_IE_GOT_16_X:
	case R_HEX_IE_GOT_11_X:
	case R_HEX_DTPREL_16_X:
	case R_HEX_DTPREL_11_X:
	case R_HEX_TPREL_16_X:
	case R_HEX_TPREL_11_X:
	  lmask = ~(~(bfd_vma) 0 << howto->bitsize);
	  /* Fall through.  */

	case R_HEX_LO16:
	case R_HEX_HI16:
	case R_HEX_GOTREL_LO16:
	case R_HEX_GOTREL_HI16:
	case R_HEX_GOT_LO16:
	case R_HEX_GOT_HI16:
	case R_HEX_GOT_16:
	case R_HEX_GD_GOT_LO16:
	case R_HEX_GD_GOT_HI16:
	case R_HEX_GD_GOT_16:
	case R_HEX_LD_GOT_LO16:
	case R_HEX_LD_GOT_HI16:
	case R_HEX_LD_GOT_16:
	case R_HEX_IE_LO16:
	case R_HEX_IE_HI16:
	case R_HEX_IE_GOT_LO16:
	case R_HEX_IE_GOT_HI16:
	case R_HEX_IE_GOT_16:
	case R_HEX_DTPREL_LO16:
	case R_HEX_DTPREL_HI16:
	case R_HEX_DTPREL_16:
	case R_HEX_TPREL_LO16:
	case R_HEX_TPREL_HI16:
	case R_HEX_TPREL_16:
	  offset = (relocation + rel->r_addend) & lmask & rmask;
	  insn = hexagon_get_insn (ibfd, howto, contents + rel->r_offset);
	  if (!hexagon_reloc_operand (howto, &insn, offset, NULL)
	      && (!h || h->root.type != bfd_link_hash_undefined))
	    r = info->callbacks->reloc_overflow (info,
						 h ? &h->root : NULL,
						 name, howto->name, 0,
						 ibfd, isection, rel->r_offset);
	  else
	    hexagon_put_insn (ibfd, howto, contents + rel->r_offset, insn);
	  break;

	case R_HEX_TRAMPOLINE:
	  offset = relocation + rel->r_addend;
	  {
	    hexagon_trampoline_type type;
	    struct reloc_howto_struct howto1;
	    bfd_vma val;

	    /* Trampoline type.  */
	    type = HEXAGON_TRAMPOLINE_TYPE (info, obfd);

	    /* First instruction (HI/B32_PCREL_X).  */
	    howto1 = hexagon_elf_howto_table[hexagon_trampolines[type].r_hi];
	    howto1.pc_relative = hexagon_trampolines[type].pc_relative;
	    insn = hexagon_get_insn (ibfd, &howto1,
				     contents + rel->r_offset + 0);
	    val = offset;
	    if (howto1.pc_relative)
	      val -= section_base (isection) + rel->r_offset;
	    if (hexagon_trampolines [type].r_hi == R_HEX_B32_PCREL_X)
	      val &= ~(bfd_vma) 0 << howto1.rightshift;
	    if (!hexagon_reloc_operand (&howto1, &insn, val, NULL)
		&& (!h || h->root.type != bfd_link_hash_undefined))
	      r = info->callbacks->reloc_overflow (info,
						   h ? &h->root : NULL,
						   name, howto1.name, 0,
						   ibfd, isection,
						   rel->r_offset + 0);
	    else
	      hexagon_put_insn (ibfd, &howto1,
				contents + rel->r_offset + 0, insn);

	    /* Second instruction (LO).  */
	    howto1 = hexagon_elf_howto_table[hexagon_trampolines[type].r_lo];
	    howto1.pc_relative = hexagon_trampolines[type].pc_relative;
	    insn = hexagon_get_insn (ibfd, &howto1,
				     contents + rel->r_offset + sizeof (insn));
	    val = offset;
	    if (howto1.pc_relative)
	      val -= section_base (isection) + rel->r_offset;
	    if (hexagon_trampolines [type].r_lo == R_HEX_B22_PCREL_X)
	      val &= ~(~(bfd_vma) 0 << howto1.bitsize);
	    if (!hexagon_reloc_operand(&howto1, &insn, val, NULL)
		&& (!h || h->root.type != bfd_link_hash_undefined))
	      r = info->callbacks->reloc_overflow
		    (info,
		     h ? &h->root : NULL,
		     name, howto1.name, 0, ibfd, isection,
		     rel->r_offset + HEXAGON_INSN_LEN);
	    else
	      hexagon_put_insn (ibfd, &howto1,
				contents + rel->r_offset + HEXAGON_INSN_LEN,
				insn);
	  }
	  break;

	case R_HEX_GPREL16_0:
	case R_HEX_GPREL16_1:
	case R_HEX_GPREL16_2:
	case R_HEX_GPREL16_3:
	  if (!elf_gp (obfd))
	    {
	      if (htab->sda.h
		  && htab->sda.h->elf.root.type == bfd_link_hash_defined
		  && htab->sda.h->elf.root.u.def.section->output_section)
		/* Record the base of the SDA if things look kosher.  */
		elf_gp (obfd) = hexagon_hash_address (htab->sda.h);
	      else
		{
		  /* Otherwise...  */
		  if (htab->sda.h
		      && htab->sda.h->elf.root.type != bfd_link_hash_defined)
		    /* an undefined symbol.  */
		    (*_bfd_error_handler)
		      (_("%B: relocation %s for undefined symbol `%s\'"),
		       ibfd, hexagon_elf_howto_table[r_type].name, name);
		  else
		    /* A possible reason is that the output section
		       hasn't been defined in a custom linker script.  */
		    (*_bfd_error_handler)
		      (_("%B: relocation %s for symbol `%s\' in section `%A\' "
			 "requires that the output section `.sdata\' be "
			 "defined in the linker script"),
		       ibfd, sec, hexagon_elf_howto_table[r_type].name, name);
		  bfd_set_error (bfd_error_bad_value);
		  return FALSE;
		}
	    }
	  /* Rebase the relocation to the SDA.  */
	  relocation -= elf_gp (obfd);
	  insn = hexagon_get_insn (ibfd, howto, contents + rel->r_offset);
	  offset = relocation + rel->r_addend;
	  if (!hexagon_reloc_operand (howto, &insn, offset, NULL)
	      && (!h || h->root.type != bfd_link_hash_undefined))
	    r = info->callbacks->reloc_overflow (info,
						 h ? &h->root : NULL,
						 name, howto->name, 0,
						 ibfd, isection, rel->r_offset);
	  else
	    hexagon_put_insn (ibfd, howto, contents + rel->r_offset, insn);
	  break;

	case R_HEX_B32_PCREL_X:
	case R_HEX_B22_PCREL_X:
	case R_HEX_B15_PCREL_X:
	case R_HEX_B13_PCREL_X:
	case R_HEX_B9_PCREL_X:
	case R_HEX_B7_PCREL_X:
	case R_HEX_6_PCREL_X:
	  if (r_type == R_HEX_B32_PCREL_X)
	    rmask = ~(bfd_vma) 0 << howto->rightshift;
	  else
	    lmask = ~(~(bfd_vma) 0 << howto->bitsize);
	  /* Fall through.  */

	case R_HEX_GD_PLT_B22_PCREL:
	case R_HEX_LD_PLT_B22_PCREL:
	case R_HEX_PLT_B22_PCREL:
	case R_HEX_B22_PCREL:
	case R_HEX_B15_PCREL:
	case R_HEX_B13_PCREL:
	case R_HEX_B9_PCREL:
	case R_HEX_B7_PCREL:
	  offset = ((relocation
		     + rel->r_addend
		     - (section_base (isection)	+ rel->r_offset))
		    & lmask & rmask);
	  insn = hexagon_get_insn (ibfd, howto, contents + rel->r_offset);
	  if (!hexagon_reloc_operand (howto, &insn, offset, NULL)
	      && (!h || h->root.type != bfd_link_hash_undefined))
	    r = info->callbacks->reloc_overflow (info,
						 h ? &h->root : NULL,
						 name, howto->name, 0,
						 ibfd, isection, rel->r_offset);
	  else
	    hexagon_put_insn (ibfd, howto, contents + rel->r_offset, insn);
	  break;

	case R_HEX_32:
	case R_HEX_16:
	case R_HEX_8:
	case R_HEX_32_PCREL:
	case R_HEX_GOT_32:
	case R_HEX_GOTREL_32:
	case R_HEX_GD_GOT_32:
	case R_HEX_LD_GOT_32:
	case R_HEX_IE_32:
	case R_HEX_IE_GOT_32:
	case R_HEX_DTPREL_32:
	case R_HEX_TPREL_32:
	  /* Fall through.  */

	case R_HEX_NONE:
	  /* Default relocation handling.  */
	  r = _bfd_final_link_relocate (howto, ibfd, isection,
					contents, rel->r_offset,
					relocation, rel->r_addend);
	  if (r != bfd_reloc_ok)
	    {
	      const char *msg = NULL;

	      switch (r)
		{
		case bfd_reloc_overflow:
		  r = info->callbacks->reloc_overflow (info,
						       h ? &h->root : NULL,
						       name, howto->name, 0,
						       ibfd, isection,
						       rel->r_offset);
		  break;

		case bfd_reloc_undefined:
		  r = info->callbacks->undefined_symbol
		        (info, name, ibfd, isection, rel->r_offset,
			 (info->executable
			  || (info->unresolved_syms_in_objects
			      >= RM_GENERATE_WARNING)
			  || ELF_ST_VISIBILITY (h->other)));
		  break;

		case bfd_reloc_outofrange:
		  msg = _("internal error: out of range error");
		  break;

		case bfd_reloc_notsupported:
		  msg = _("internal error: unsupported relocation error");
		  break;

		case bfd_reloc_dangerous:
		  msg = _("internal error: dangerous relocation");
		  break;

		default:
		  msg = _("internal error: unknown error");
		  break;
		}

	      if (msg)
		r = info->callbacks->warning (info, msg, name, ibfd,
					      isection, rel->r_offset);

	      if (!r)
		return FALSE;
	    }
	  break;

	default:
	  info->callbacks->warning
	    (info, _("internal error: unrecognized relocation type"),
	     name, ibfd, isection, rel->r_offset);
	  return FALSE;
	}
    }

  return TRUE;
}

/* Generate error and return false if we're generating pic code, otherwise
   return true.  */

static bfd_boolean
hexagon_check_not_pic (bfd *abfd, struct bfd_link_info *info, asection *sec,
		       hexagon_link_hash_entry *h, unsigned int r_type)
{
  if (!info->shared)
    return TRUE;

  /* Do not complain about sections that we don't care about, such as
     debug or non-constant sections.  */
  if (!(sec->flags & SEC_ALLOC
	&& sec->flags & SEC_READONLY))
    return TRUE;

  if (h)
    (*_bfd_error_handler)
      (_("%B: relocation %s for symbol `%s\' in section `%A\' cannot be handled "
	 "in a shared object; recompile with `-fpic\'"), abfd, sec,
       hexagon_elf_howto_table[r_type].name,
       h->elf.root.root.string);
  else
    (*_bfd_error_handler)
      (_("%B: relocation %s in section `%A\' cannot be handled "
	 "in a shared object; recompile with `-fpic\'"), abfd, sec,
       hexagon_elf_howto_table[r_type].name);

  bfd_set_error (bfd_error_bad_value);

  return FALSE;
}

/* Generate error and return false if we're generating a shared lib, otherwise
   return true.  */

static bfd_boolean
hexagon_check_not_shared_lib (bfd *abfd, struct bfd_link_info *info, asection *sec,
			      hexagon_link_hash_entry *h, unsigned int r_type)
{
  if (!(info->shared 
	&& !info->pie))
    return TRUE;

  /* Do not complain about sections that we don't care about, such as
     debug or non-constant sections.  */
  if (!(sec->flags & SEC_ALLOC
	&& sec->flags & SEC_READONLY))
    return TRUE;

  if (h)
    (*_bfd_error_handler)
      (_("%B: relocation %s for symbol `%s\' in section `%A\' cannot be "
	 "handled in a shared object"), abfd, sec,
       hexagon_elf_howto_table[r_type].name,
       h->elf.root.root.string);
  else
    (*_bfd_error_handler)
      (_("%B: relocation %s in section `%A\' cannot be handled "
	 "in a shared object"), abfd, sec,
       hexagon_elf_howto_table[r_type].name);
  
  bfd_set_error (bfd_error_bad_value);

  return FALSE;
}

/* Generate error and return false if we're not generating an executable,
   otherwise return true.  */

static bfd_boolean
hexagon_check_executable (bfd *abfd, struct bfd_link_info *info, asection *sec,
			  hexagon_link_hash_entry *h, unsigned int r_type)
{
  if (info->executable)
    return TRUE;

  /* Do not complain about sections that we don't care about, such as
     debug or non-constant sections.  */
  if (!(sec->flags & SEC_ALLOC
	&& sec->flags & SEC_READONLY))
    return TRUE;

  if (h)
    (*_bfd_error_handler)
      (_("%B: relocation %s for symbol `%s\' in section `%A\' can only be "
	 "handled in an executable object"), abfd, sec,
       hexagon_elf_howto_table[r_type].name,
       h->elf.root.root.string);
  else
    (*_bfd_error_handler)
      (_("%B: relocation %s in section `%A\' can only be handled "
	 "in an executable object"), abfd, sec,
       hexagon_elf_howto_table[r_type].name);

  bfd_set_error (bfd_error_bad_value);

  return FALSE;
}


/* PIC & DSO */

/* Implement elf_backend_check_relocs.
   Look through the relocations during the first phase, and allocate space
   in the GOT, the PLT and dynamic relocation sections.  */
static bfd_boolean
hexagon_elf_check_relocs (bfd *abfd, struct bfd_link_info *info,
			  asection *sec, const Elf_Internal_Rela *relocs)
{
  hexagon_link_hash_table *htab;
  Elf_Internal_Shdr *symtab_hdr;
  struct elf_link_hash_entry **sym_hashes;
  const Elf_Internal_Rela *rel;
  asection *sreloc;
  bfd_signed_vma *local_got_refcounts;

  if (info->relocatable)
    return TRUE;

  htab = hexagon_hash_table (info);

  symtab_hdr = &elf_tdata (abfd)->symtab_hdr;
  sym_hashes = elf_sym_hashes (abfd);
  sreloc = NULL;

  for (rel = relocs; rel < relocs + sec->reloc_count; rel++)
    {
      unsigned int r_type;
      size_t r_symndx;
      reloc_howto_type *howto;
      hexagon_link_hash_entry *h;
      Elf_Internal_Sym *isym;

      r_type = ELF32_R_TYPE (rel->r_info);
      r_symndx = ELF32_R_SYM (rel->r_info);
      howto = hexagon_elf_howto_table + r_type;

      if (r_symndx < symtab_hdr->sh_info)
	{
	  /* Symbol is local.  */
	  isym = bfd_sym_from_r_symndx (&htab->sym_cache, abfd, r_symndx);
	  if (!isym)
	    return FALSE;
	  h = NULL;

	  /* This is a GOT entry for a local symbol.  */
	  local_got_refcounts = elf_local_got_refcounts (abfd);
	  if (!local_got_refcounts)
	    {
	      bfd_size_type size;

	      size = LGOT_SZ (symtab_hdr) * sizeof (*local_got_refcounts) + 1;
	      local_got_refcounts = (bfd_signed_vma *) bfd_zalloc (abfd, size);
	      if (!local_got_refcounts)
		return FALSE;
	      elf_local_got_refcounts (abfd) = local_got_refcounts;
	    }
	}
      else
	{
	  /* Symbol is global.  */
	  isym = NULL;
	  h = ((hexagon_link_hash_entry *)
	       (sym_hashes[r_symndx - symtab_hdr->sh_info]));
	  while (h->elf.root.type == bfd_link_hash_indirect
		 || h->elf.root.type == bfd_link_hash_warning)
	    h = (hexagon_link_hash_entry *) h->elf.root.u.i.link;
	  local_got_refcounts = NULL;
	}

      /* If a relocation refers to the _GLOBAL_OFFSET_TABLE_ symbol,
         create the GOT.  */
      if (!htab->elf.sgotplt
	  && h
	  && !strcmp (h->elf.root.root.string, "_GLOBAL_OFFSET_TABLE_"))
	{
	  /* Create the GOT.  */
	  if (!htab->elf.dynobj)
	    htab->elf.dynobj = abfd;
	  if (!_bfd_elf_create_got_section (htab->elf.dynobj, info))
	    return FALSE;
	}

      /* Perform SDA checks.  */
      switch (r_type)
	{
	case R_HEX_GPREL16_0:
	case R_HEX_GPREL16_1:
	case R_HEX_GPREL16_2:
	case R_HEX_GPREL16_3:
	  hexagon_elf_sda_base (abfd, info);
	  break;
	}

      /* Perform GOT, PLT and TLS accounting.  */
      switch (r_type)
	{
	case R_HEX_LD_GOT_LO16:
	case R_HEX_LD_GOT_HI16:
	case R_HEX_LD_GOT_32:
	case R_HEX_LD_GOT_16:
	case R_HEX_LD_GOT_32_6_X:
	case R_HEX_LD_GOT_16_X:
	case R_HEX_LD_GOT_11_X:
	  /* Use single GOT entry for local symbol.  */
	  hexagon_init_ld_got (abfd, info);
	  h = htab->gd_got.ld_got;

	  /* Fall-through.  */

	case R_HEX_GD_GOT_LO16:
	case R_HEX_GD_GOT_HI16:
	case R_HEX_GD_GOT_32:
	case R_HEX_GD_GOT_16:
	case R_HEX_GD_GOT_32_6_X:
	case R_HEX_GD_GOT_16_X:
	case R_HEX_GD_GOT_11_X:
	case R_HEX_GOT_LO16:
	case R_HEX_GOT_HI16:
	case R_HEX_GOT_32:
	case R_HEX_GOT_16:
	case R_HEX_GOT_32_6_X:
	case R_HEX_GOT_16_X:
	case R_HEX_GOT_11_X:
	case R_HEX_IE_LO16:
	case R_HEX_IE_HI16:
	case R_HEX_IE_32:
	case R_HEX_IE_32_6_X:
	case R_HEX_IE_16_X:
	case R_HEX_IE_GOT_LO16:
	case R_HEX_IE_GOT_HI16:
	case R_HEX_IE_GOT_32:
	case R_HEX_IE_GOT_16:
	case R_HEX_IE_GOT_32_6_X:
	case R_HEX_IE_GOT_16_X:
	case R_HEX_IE_GOT_11_X:
	  /* This symbol requires a GOT entry.  */
	  if (h)
	    {
	      /* Symbol is global.  */
	      h->elf.got.refcount++;

	      switch (r_type)
		{
		case R_HEX_GOT_LO16:
		case R_HEX_GOT_HI16:
		case R_HEX_GOT_32:
		case R_HEX_GOT_16:
		case R_HEX_GOT_32_6_X:
		case R_HEX_GOT_16_X:
		case R_HEX_GOT_11_X:
		  h->ok_got.refcount++;
		  break;

		case R_HEX_GD_GOT_LO16:
		case R_HEX_GD_GOT_HI16:
		case R_HEX_GD_GOT_32:
		case R_HEX_GD_GOT_16:
		case R_HEX_GD_GOT_32_6_X:
		case R_HEX_GD_GOT_16_X:
		case R_HEX_GD_GOT_11_X:
		case R_HEX_LD_GOT_LO16:
		case R_HEX_LD_GOT_HI16:
		case R_HEX_LD_GOT_32:
		case R_HEX_LD_GOT_16:
		case R_HEX_LD_GOT_32_6_X:
		case R_HEX_LD_GOT_16_X:
		case R_HEX_LD_GOT_11_X:
		  h->gd_got.refcount++;
		  break;

		case R_HEX_IE_LO16:
		case R_HEX_IE_HI16:
		case R_HEX_IE_32:
		case R_HEX_IE_32_6_X:
		case R_HEX_IE_16_X:
		case R_HEX_IE_GOT_LO16:
		case R_HEX_IE_GOT_HI16:
		case R_HEX_IE_GOT_32:
		case R_HEX_IE_GOT_16:
		case R_HEX_IE_GOT_32_6_X:
		case R_HEX_IE_GOT_16_X:
		case R_HEX_IE_GOT_11_X:
		  h->ie_got.refcount++;
		  break;
		}
	    }
	  else
	    {
	      /* Symbol is local.  */
	      local_got_refcounts[r_symndx]++;

	      switch (r_type)
		{
		case R_HEX_GOT_LO16:
		case R_HEX_GOT_HI16:
		case R_HEX_GOT_32:
		case R_HEX_GOT_16:
		case R_HEX_GOT_32_6_X:
		case R_HEX_GOT_16_X:
		case R_HEX_GOT_11_X:
		  local_got_refcounts[LGOT_OK (symtab_hdr, r_symndx)]++;
		  break;

		case R_HEX_GD_GOT_LO16:
		case R_HEX_GD_GOT_HI16:
		case R_HEX_GD_GOT_32:
		case R_HEX_GD_GOT_16:
		case R_HEX_GD_GOT_32_6_X:
		case R_HEX_GD_GOT_16_X:
		case R_HEX_GD_GOT_11_X:
		case R_HEX_LD_GOT_LO16:
		case R_HEX_LD_GOT_HI16:
		case R_HEX_LD_GOT_32:
		case R_HEX_LD_GOT_16:
		case R_HEX_LD_GOT_32_6_X:
		case R_HEX_LD_GOT_16_X:
		case R_HEX_LD_GOT_11_X:
		  local_got_refcounts[LGOT_GD (symtab_hdr, r_symndx)]++;
		  break;

		case R_HEX_IE_LO16:
		case R_HEX_IE_HI16:
		case R_HEX_IE_32:
		case R_HEX_IE_32_6_X:
		case R_HEX_IE_16_X:
		case R_HEX_IE_GOT_LO16:
		case R_HEX_IE_GOT_HI16:
		case R_HEX_IE_GOT_32:
		case R_HEX_IE_GOT_16:
		case R_HEX_IE_GOT_32_6_X:
		case R_HEX_IE_GOT_16_X:
		case R_HEX_IE_GOT_11_X:
		  local_got_refcounts[LGOT_IE (symtab_hdr, r_symndx)]++;
		  break;
		}
	    }
	  /* Fall through */

	case R_HEX_GOTREL_LO16:
	case R_HEX_GOTREL_HI16:
	case R_HEX_GOTREL_32:
	case R_HEX_GOTREL_32_6_X:
	case R_HEX_GOTREL_16_X:
	case R_HEX_GOTREL_11_X:
	  /* This symbol requires a GOT.  */
	  if (!htab->elf.sgotplt)
	    {
	      /* Create the GOT.  */
	      if (!htab->elf.dynobj)
		htab->elf.dynobj = abfd;
	      if (!_bfd_elf_create_got_section (htab->elf.dynobj, info))
		return FALSE;
	    }
	  break;

	case R_HEX_GPREL16_0:
	case R_HEX_GPREL16_1:
	case R_HEX_GPREL16_2:
	case R_HEX_GPREL16_3:

	case R_HEX_LO16:
	case R_HEX_HI16:
	case R_HEX_32:
	case R_HEX_16:
	case R_HEX_8:
	case R_HEX_32_6_X:
	case R_HEX_16_X:
	case R_HEX_12_X:
	case R_HEX_11_X:
	case R_HEX_10_X:
	case R_HEX_9_X:
	case R_HEX_8_X:
	case R_HEX_7_X:
	case R_HEX_6_X:
	  if (h && info->executable)
	    {
	      /* If this relocation is in a read-only section, we might
	         need a copy-relocation.  We can't reliably check at
	         this stage whether the section is read-only, as input
	         sections have not yet been mapped to output sections.
	         Tentatively set the flag for now, and correct in
	         adjust_dynamic_symbol.  */
	      h->elf.non_got_ref = TRUE;
	      h->elf.pointer_equality_needed = TRUE;
	      /* A PLT entry may be needed if this relocation refers to
	         a function in a shared library.  */
	      h->elf.plt.refcount++;
	    }
	  break;

	case R_HEX_B32_PCREL_X:
	case R_HEX_B22_PCREL:
	case R_HEX_B22_PCREL_X:
	case R_HEX_B15_PCREL:
	case R_HEX_B15_PCREL_X:
	case R_HEX_B13_PCREL:
	case R_HEX_B13_PCREL_X:
	case R_HEX_B9_PCREL:
	case R_HEX_B9_PCREL_X:
	case R_HEX_B7_PCREL:
	case R_HEX_B7_PCREL_X:
	  /* A PLT entry may be needed if this relocation refers to
	     a function in a shared library.  */

	  /* Fall through.  */

	case R_HEX_PLT_B22_PCREL:
	  /* This symbol requires a PLT entry.  We actually build the entry
	     in adjust_dynamic_symbol because this might be a case of
	     linking PIC code which is never referenced by a dynamic object,
	     when we don't need to generate a PLT entry after all.       */
	  if (h)
	    {
	      /* But only if it's a global symbol, otherwise don't use
		 a PLT.  */
	      h->elf.needs_plt = TRUE;
	      h->elf.plt.refcount++;
	    }
	  break;

	case R_HEX_GD_PLT_B22_PCREL:
	case R_HEX_LD_PLT_B22_PCREL:
	  /* This TLS symbol requires either the actual __tls_get_addr
	     or a local stub.  */
	  htab->gd_plt.refcount++;
	  if (h)
	    h->gd_plt.refcount++;
	  else
	    local_got_refcounts[LPLT_GD (symtab_hdr, r_symndx)]++;

	  /* This is conservative: we sometimes generate these stubs when not
	     needed.
	     Ideally, we would use TLS_TRANSIT_OK to decide whether to generate
	     or not, but TLS_TRANSIT_OK might evaluate to false here, but later
	     to true, causing the stub to be used, but not generated.
	   */
	  /* Create the  __tls_get_addr stubs.  */
	  if (is_ld_rel (r_type))
	    hexagon_init_le_get (abfd, info);
	  if (is_gd_rel (r_type))
	    hexagon_init_ie_get (abfd, info);

	  if (!TLS_TRANSIT_OK (info, h ? &h->elf : NULL))
	    {
	      /* Request the actual __tls_get_addr.  */
	      hexagon_init_gd_get (abfd, info);
	      /* Request a PLT entry for __tls_get_addr.  */
	      htab->gd_plt.gd_get->elf.needs_plt = TRUE;
	      htab->gd_plt.gd_get->elf.plt.refcount++;
	    }
	  break;
	}

      /* Perform copy-relocation checks.  */
      switch (r_type)
	{
	case R_HEX_GPREL16_0:
	case R_HEX_GPREL16_1:
	case R_HEX_GPREL16_2:
	case R_HEX_GPREL16_3:

	case R_HEX_LO16:
	case R_HEX_HI16:
	case R_HEX_32:
	case R_HEX_16:
	case R_HEX_8:
	case R_HEX_32_6_X:
	case R_HEX_16_X:
	case R_HEX_12_X:
	case R_HEX_11_X:
	case R_HEX_10_X:
	case R_HEX_9_X:
	case R_HEX_8_X:
	case R_HEX_7_X:
	case R_HEX_6_X:

	  /* FIXME: How about R_HEX_32_PCREL? */
	case R_HEX_B32_PCREL_X:
	case R_HEX_B22_PCREL:
	case R_HEX_B22_PCREL_X:
	case R_HEX_B15_PCREL:
	case R_HEX_B15_PCREL_X:
	case R_HEX_B13_PCREL:
	case R_HEX_B13_PCREL_X:
	case R_HEX_B9_PCREL:
	case R_HEX_B9_PCREL_X:
	case R_HEX_B7_PCREL:
	case R_HEX_B7_PCREL_X:
	  /* If we are creating a shared library, and this is a relocation
	     against a global symbol, or a non PC-relative relocation
	     against a local symbol, then we need to copy the relocation
	     into the shared library.  However, if we are linking with
	     -Bsymbolic, we do not need to copy a relocation against a
	     global symbol which is defined in an object we are
	     including in the link (i.e., DEF_REGULAR is set).  At this
	     point we have not seen all the input files, so it is possible
	     that DEF_REGULAR is not set now but will be set later
	     (it is never cleared).  In case of a weak definition,
	     DEF_REGULAR may be cleared later by a strong definition in a
	     shared library.  We account for that possibility below by
	     storing information in the relocs_copied field of the hash table
	     entry.  A similar situation occurs when creating shared libraries
	     and symbol visibility changes render the symbol local.  If, on
	     the other hand, we are creating an executable, we may need to
	     keep relocations for symbols satisfied by a dynamic library if
	     we manage to avoid copy relocations for the symbol.  */
	  if ((info->shared
	       && sec->flags & SEC_ALLOC
	       && (!howto->pc_relative
		   || (h
		       && (!SYMBOLIC_BIND (info, &h->elf)
			   || h->elf.root.type == bfd_link_hash_defweak
			   || !h->elf.def_regular))))
	      || ((ELIMINATE_COPY_RELOCS || info->nocopyreloc)
		  && info->executable
		  && sec->flags & SEC_ALLOC
		  && h
		  && (h->elf.root.type == bfd_link_hash_defweak
		      || !h->elf.def_regular)))
	    {
	      hexagon_dyn_reloc *p, **head;

	      /* We must copy these relocations into the output file. Create
	         a relocation section in the dynamic object and make room for
	         this relocation.  */
	      if (!sreloc)
		{
		  if (!htab->elf.dynobj)
		    htab->elf.dynobj = abfd;
		  sreloc = _bfd_elf_make_dynamic_reloc_section
			     (sec, htab->elf.dynobj, 2, abfd, TRUE);
		  if (!sreloc)
		    return FALSE;
		}

	      /* If this is a global symbol, we count the number of
	         relocations needed for this symbol.  */
	      if (h)
		head = &h->dyn_relocs;
	      else
		{
		  /* Track dynamic relocations needed for local symbols too.
		     We really need local symbols available to do this
		     easily.  */
		  asection *s;
		  Elf_Internal_Sym *isym1;

		  isym1 = bfd_sym_from_r_symndx (&htab->sym_cache, abfd,
						 r_symndx);
		  if (!isym1)
		    return FALSE;
		  s = bfd_section_from_elf_index (abfd, isym1->st_shndx);
		  if (!s)
		    s = sec;
		  head = ((hexagon_dyn_reloc **)
			  &elf_section_data (s)->local_dynrel);
		}

	      p = *head;
	      if (!p || p->sec != sec)
		{
		  p = ((hexagon_dyn_reloc *)
		       bfd_zalloc (htab->elf.dynobj, sizeof (*p)));
		  if (!p)
		    return FALSE;
		  p->next = *head;
		  *head = p;
		  p->sec = sec;
		}

	      if (howto->pc_relative)
		p->pc_count++;
	      else
		p->count++;
	    }
	  break;
	}

      /* Validate relocations.  */
      switch (r_type)
	{
	case R_HEX_GPREL16_0:
	case R_HEX_GPREL16_1:
	case R_HEX_GPREL16_2:
	case R_HEX_GPREL16_3:
	  /* These relocations cannot be used in shared libraries because
	     there should not be an SDA in a shared library for the time being.  */

	  if (!hexagon_check_not_shared_lib (abfd, info, sec, h, r_type))
	    return FALSE;
	  break;

	case R_HEX_IE_LO16:
	case R_HEX_IE_HI16:
	case R_HEX_IE_32:
	case R_HEX_IE_32_6_X:
	case R_HEX_IE_16_X:
	  /* These relocations cannot be used in pic code.  */

	  if (!hexagon_check_not_pic (abfd, info, sec, h, r_type))
	    return FALSE;
	  break;
 
	case R_HEX_TPREL_LO16:
	case R_HEX_TPREL_HI16:
	case R_HEX_TPREL_32:
	case R_HEX_TPREL_16:
	case R_HEX_TPREL_32_6_X:
	case R_HEX_TPREL_16_X:
	case R_HEX_TPREL_11_X:
	  /* These relocations can only be used in executables.  */

	  if (!hexagon_check_executable (abfd, info, sec, h, r_type))
	    return FALSE;
	  break;

	case R_HEX_LO16:
	case R_HEX_HI16:
	case R_HEX_32:
	case R_HEX_16:
	case R_HEX_8:
	case R_HEX_32_6_X:
	case R_HEX_16_X:
	case R_HEX_12_X:
	case R_HEX_11_X:
	case R_HEX_10_X:
	case R_HEX_9_X:
	case R_HEX_8_X:
	case R_HEX_7_X:
	case R_HEX_6_X:
	  /* These relocations cannot be used in shared libraries or for
	     symbols in shared libraries.  */

	  if (!hexagon_check_not_shared_lib (abfd, info, sec, h, r_type))
	    return FALSE;

	  /* Fall-through.  */

	case R_HEX_32_PCREL:
	  /* This relocation cannot be used for symbols in shared libraries.  */

	  /* Do not complain about sections that we don't care about, such as
	     debug or non-constant sections.  */
	  if ((ELIMINATE_COPY_RELOCS || info->nocopyreloc)
		   && info->executable
		   && sec->flags & SEC_ALLOC
		   && sec->flags & SEC_READONLY
		   && h
		   && (h->elf.root.type == bfd_link_hash_defined
		       || h->elf.root.type == bfd_link_hash_defweak)
		   && !h->elf.def_regular
		   && !h->elf.non_got_ref)
	    {
	      (*_bfd_error_handler)
		(_("%B: relocation %s for symbol `%s\' in section `%A\' "
		   "cannot be handled when it is defined by a shared library"),
		 abfd, sec,
		 hexagon_elf_howto_table[r_type].name,
		 h->elf.root.root.string);
	      bfd_set_error (bfd_error_bad_value);
	      return FALSE;
	    }
	  break;
	}

      /* Mark file with the kind of TLS scheme that it uses.  */
      switch (r_type)
	{
	case R_HEX_IE_LO16:
	case R_HEX_IE_HI16:
	case R_HEX_IE_32:
	case R_HEX_IE_32_6_X:
	case R_HEX_IE_16_X:
	case R_HEX_IE_GOT_LO16:
	case R_HEX_IE_GOT_HI16:
	case R_HEX_IE_GOT_32:
	case R_HEX_IE_GOT_16:
	case R_HEX_IE_GOT_32_6_X:
	case R_HEX_IE_GOT_16_X:
	case R_HEX_IE_GOT_11_X:
	case R_HEX_TPREL_LO16:
	case R_HEX_TPREL_HI16:
	case R_HEX_TPREL_32:
	case R_HEX_TPREL_16:
	case R_HEX_TPREL_32_6_X:
	case R_HEX_TPREL_16_X:
	case R_HEX_TPREL_11_X:
	  /* These relocations require that a DSO is of type Initial Executable.
	     Like in other targets, this flag is not reset even if they are
	     garbage-collected.  */
	  if (info->shared)
	    info->flags |= DF_STATIC_TLS;
	  break;
	}
    }

  return TRUE;
}

/* Implement elf_backend_gc_sweep_hook.
   Update the GOT entry reference counts for the section being removed.  */
static bfd_boolean
hexagon_elf_gc_sweep_hook (bfd *abfd ATTRIBUTE_UNUSED,
			   struct bfd_link_info *info ATTRIBUTE_UNUSED,
			   asection *sec,
			   const Elf_Internal_Rela *relocs ATTRIBUTE_UNUSED)
{
  Elf_Internal_Shdr *symtab_hdr;
  struct elf_link_hash_entry **sym_hashes;
  bfd_signed_vma *local_got_refcounts;
  const Elf_Internal_Rela *rel;

  elf_section_data (sec)->local_dynrel = NULL;

  symtab_hdr = &elf_tdata (abfd)->symtab_hdr;
  sym_hashes = elf_sym_hashes (abfd);
  local_got_refcounts = elf_local_got_refcounts (abfd);

  for (rel = relocs; rel < relocs + sec->reloc_count; rel++)
    {
      unsigned int r_type;
      size_t r_symndx, l_symndx;
      struct elf_link_hash_entry *h = NULL;
      hexagon_link_hash_entry *eh = NULL;

      r_symndx = ELF32_R_SYM (rel->r_info);
      if (r_symndx >= symtab_hdr->sh_info)
	{
	  hexagon_dyn_reloc *p, **pp;

	  h = sym_hashes[r_symndx - symtab_hdr->sh_info];
	  eh = hexagon_hash_entry (h);
	  for (pp = &eh->dyn_relocs; (p = *pp) != NULL; pp = &p->next)
	    if (p->sec == sec)
	      {
		/* Everything must go for SEC.  */
		*pp = p->next;
		break;
	      }
	}

      r_type = ELF32_R_TYPE (rel->r_info);
      switch (r_type)
	{
	case R_HEX_GOT_LO16:
	case R_HEX_GOT_HI16:
	case R_HEX_GOT_32:
	case R_HEX_GOT_16:
	case R_HEX_GOT_32_6_X:
	case R_HEX_GOT_16_X:
	case R_HEX_GOT_11_X:
	case R_HEX_GD_GOT_LO16:
	case R_HEX_GD_GOT_HI16:
	case R_HEX_GD_GOT_32:
	case R_HEX_GD_GOT_16:
	case R_HEX_GD_GOT_32_6_X:
	case R_HEX_GD_GOT_16_X:
	case R_HEX_GD_GOT_11_X:
	case R_HEX_LD_GOT_LO16:
	case R_HEX_LD_GOT_HI16:
	case R_HEX_LD_GOT_32:
	case R_HEX_LD_GOT_16:
	case R_HEX_LD_GOT_32_6_X:
	case R_HEX_LD_GOT_16_X:
	case R_HEX_LD_GOT_11_X:
	case R_HEX_IE_LO16:
	case R_HEX_IE_HI16:
	case R_HEX_IE_32:
	case R_HEX_IE_32_6_X:
	case R_HEX_IE_16_X:
	case R_HEX_IE_GOT_LO16:
	case R_HEX_IE_GOT_HI16:
	case R_HEX_IE_GOT_32:
	case R_HEX_IE_GOT_16:
	case R_HEX_IE_GOT_32_6_X:
	case R_HEX_IE_GOT_16_X:
	case R_HEX_IE_GOT_11_X:

	  switch (r_type)
	    {
	    case R_HEX_GOT_LO16:
	    case R_HEX_GOT_HI16:
	    case R_HEX_GOT_32:
	    case R_HEX_GOT_16:
	    case R_HEX_GOT_32_6_X:
	    case R_HEX_GOT_16_X:
	    case R_HEX_GOT_11_X:
	      l_symndx = LGOT_OK (symtab_hdr, r_symndx);
	      if (eh && eh->ok_got.refcount > 0)
		eh->ok_got.refcount--;
	      break;

	    case R_HEX_GD_GOT_LO16:
	    case R_HEX_GD_GOT_HI16:
	    case R_HEX_GD_GOT_32:
	    case R_HEX_GD_GOT_16:
	    case R_HEX_GD_GOT_32_6_X:
	    case R_HEX_GD_GOT_16_X:
	    case R_HEX_GD_GOT_11_X:
	    case R_HEX_LD_GOT_LO16:
	    case R_HEX_LD_GOT_HI16:
	    case R_HEX_LD_GOT_32:
	    case R_HEX_LD_GOT_16:
	    case R_HEX_LD_GOT_32_6_X:
	    case R_HEX_LD_GOT_16_X:
	    case R_HEX_LD_GOT_11_X:
	      l_symndx = LGOT_GD (symtab_hdr, r_symndx);
	      if (eh && eh->gd_got.refcount > 0)
		eh->gd_got.refcount--;
	      break;

	    case R_HEX_IE_LO16:
	    case R_HEX_IE_HI16:
	    case R_HEX_IE_32:
	    case R_HEX_IE_32_6_X:
	    case R_HEX_IE_16_X:
	    case R_HEX_IE_GOT_LO16:
	    case R_HEX_IE_GOT_HI16:
	    case R_HEX_IE_GOT_32:
	    case R_HEX_IE_GOT_16:
	    case R_HEX_IE_GOT_32_6_X:
	    case R_HEX_IE_GOT_16_X:
	    case R_HEX_IE_GOT_11_X:
	      l_symndx = LGOT_IE (symtab_hdr, r_symndx);
	      if (eh && eh->ie_got.refcount > 0)
		eh->ie_got.refcount--;
	      break;

	    default:
	      /* Make some versions of the compiler happy,
	         but this code should never run.  */
	      l_symndx = r_symndx;
	      BFD_ASSERT (FALSE);
	      break;
	    }

	  if (h)
	    {
	      /* Global symbol.  */
	      if (h->got.refcount > 0)
		h->got.refcount--;
	    }
	  else if (local_got_refcounts)
	    {
	      if (local_got_refcounts[r_symndx] > 0)
		local_got_refcounts[r_symndx]--;
	      if (local_got_refcounts[l_symndx] > 0)
		local_got_refcounts[l_symndx]--;
	    }
	  break;

	case R_HEX_LO16:
	case R_HEX_HI16:
	case R_HEX_32:
	case R_HEX_16:
	case R_HEX_8:
	case R_HEX_32_6_X:
	case R_HEX_16_X:
	case R_HEX_12_X:
	case R_HEX_11_X:
	case R_HEX_10_X:
	case R_HEX_9_X:
	case R_HEX_8_X:
	case R_HEX_7_X:
	case R_HEX_6_X:
	  if (info->shared)
	    break;

	  /* Fall thru */

	case R_HEX_PLT_B22_PCREL:
	case R_HEX_B32_PCREL_X:
	case R_HEX_B22_PCREL:
	case R_HEX_B22_PCREL_X:
	case R_HEX_B15_PCREL:
	case R_HEX_B15_PCREL_X:
	case R_HEX_B13_PCREL:
	case R_HEX_B13_PCREL_X:
	case R_HEX_B9_PCREL:
	case R_HEX_B9_PCREL_X:
	case R_HEX_B7_PCREL:
	case R_HEX_B7_PCREL_X:
	  /* FIXME: should symbol visibility matter? */
	  /* Global symbol.  */
	  if (h && h->plt.refcount > 0)
	    h->plt.refcount--;

	  break;

	default:
	  break;
	}
    }

  return TRUE;
}

/* Implement elf_backend_finish_dynamic_symbol.  */
static bfd_boolean
hexagon_elf_finish_dynamic_symbol (bfd *obfd, struct bfd_link_info *info,
				   struct elf_link_hash_entry *h,
				   Elf_Internal_Sym *sym)
{
  hexagon_link_hash_table *htab;
  hexagon_link_hash_entry *eh;

  htab = hexagon_hash_table (info);
  eh = hexagon_hash_entry (h);

  if (h->plt.offset != -(bfd_vma) 1)
    {
      /* This symbol has a PLT entry.  */
      bfd_vma plt_index, got_offset, offset;
      Elf_Internal_Rela rela;

      if (h->dynindx == -1
	  || !htab->elf.splt
	  || !htab->elf.sgotplt
	  || !htab->elf.srelplt)
	abort ();

      /* Get the index in the PLT which corresponds to this symbol.  This is
         the index of this symbol in all the symbols for which we are making
         PLT entries.  The first few entries in the PLT are reserved.  */
      plt_index = ((h->plt.offset - PLT_INITIAL_ENTRY_SIZE)
		   / PLT_ENTRY_SIZE (obfd));

      /* Get the offset into the GOT of the entry that corresponds to this
         PLT entry.  The first few GOT entries are reserved.  */
      got_offset = plt_index * GOT_ENTRY_SIZE + GOT_INITIAL_ENTRY_SIZE;

      /* Initialize the PLT entry.  */
      memcpy (htab->elf.splt->contents + h->plt.offset,
	      PLT_ENTRY_TEMP (obfd), PLT_ENTRY_SIZE (obfd));

      /* Compute the difference between the address of the GOT entry and
	 the address of the PLT entry.  */
      offset
	= (section_base (htab->elf.sgotplt) + got_offset
	   - section_base (htab->elf.splt) - h->plt.offset);

      /* Relocate insns in the PLT entry.  */
      if (!PLT_ENTRY_NEW (obfd))
	{
	  hexagon_reloc_operand
	    (hexagon_elf_howto_table + R_HEX_HI16,
	     (hexagon_insn *) (htab->elf.splt->contents + h->plt.offset
			       + 1 * HEXAGON_INSN_LEN),
	     offset, NULL);
	  hexagon_reloc_operand
	    (hexagon_elf_howto_table + R_HEX_LO16,
	     (hexagon_insn *) (htab->elf.splt->contents + h->plt.offset
			       + 2 * HEXAGON_INSN_LEN),
	     offset, NULL);
	}
      else
	{
	  /* Extended instruction.  */
	  hexagon_reloc_operand
	    (hexagon_elf_howto_table + R_HEX_B32_PCREL_X,
	     (hexagon_insn *) (htab->elf.splt->contents + h->plt.offset
			       + 0 * HEXAGON_INSN_LEN),
	     (~(bfd_vma) 0 << hexagon_elf_howto_table[R_HEX_B32_PCREL_X].rightshift
	      & offset),
	     NULL);
	  hexagon_reloc_operand
	    (hexagon_elf_howto_table + R_HEX_6_PCREL_X,
	     (hexagon_insn *) (htab->elf.splt->contents + h->plt.offset +
			       1 * HEXAGON_INSN_LEN),
	     (hexagon_elf_howto_table[R_HEX_6_PCREL_X].src_mask
	      & offset),
	     NULL);
	}

      /* Intialize the GOT entry corresponding to this PLT entry to initially
         point to the 0th PLT entry, which marshalls the dynamic linker
         to resolve this symbol lazily.  */
      bfd_put_32 (obfd,
		  section_base (htab->elf.splt),
		  htab->elf.sgotplt->contents + got_offset);

      /* Fill in the entry in the .rela.plt section.  */
      rela.r_info = ELF32_R_INFO (h->dynindx, R_HEX_JMP_SLOT);
      rela.r_offset = section_base (htab->elf.sgotplt) + got_offset;
      rela.r_addend = 0;
      bfd_elf32_swap_reloca_out	(obfd, &rela,
				 (htab->elf.srelplt->contents
				  + plt_index * sizeof (Elf32_External_Rela)));

      if (!h->def_regular)
	{
	  /* Mark the symbol as undefined, rather than as defined in
	     the .plt section.  Leave the value alone.  This is a clue
	     for the dynamic linker, to make function pointer
	     comparisons work between an application and shared
	     library.  */
	  sym->st_shndx = SHN_UNDEF;
	  /* If the symbol is weak, we do need to clear the value.
	     Otherwise, the PLT entry would provide a definition for
	     the symbol even if the symbol wasn't defined anywhere,
	     and so the symbol would never be NULL.  */
	  /* FIXME: Is this still necessary with the addition of the
	     next test? */
	  if (!h->ref_regular_nonweak)
	    sym->st_value = 0;
	  if (!h->pointer_equality_needed)
	    sym->st_value = 0;
	}
    }

  /* We don't emit GOT relocations for symbols that aren't in the
     dynamic-symbols table for an ordinary program and are either defined
     by the program or undefined weak symbols.  */
  if (h->got.offset != -(bfd_vma) 1)
    {
      /* This symbol has a GOT entry.  */
      Elf_Internal_Rela rela;
      bfd_vma offset = h->got.offset & ~(bfd_vma) 3;

      /* This symbol has an entry in the GOT.  Set it up.  */
      if (!htab->elf.sgot || !htab->elf.srelgot)
	abort ();
      rela.r_offset = section_base (htab->elf.sgot) + offset;

      /* If this is a static link, or it is a -Bsymbolic link and the
         symbol is defined locally or was forced to be local because
         of a version file, we just want to emit a RELATIVE relocation.
         The entry in the GOT is initialized in relocate_section.  */
      if (info->shared && SYMBOL_REFERENCES_LOCAL (info, h))
	{
	  if (eh->ok_got.refcount > 0)
	    {
	      rela.r_info = ELF32_R_INFO (0, R_HEX_RELATIVE);
	      rela.r_addend = elf_hash_address (h);
	      BFD_ASSERT ((htab->elf.srelgot->reloc_count
			   * sizeof (Elf32_External_Rela))
			  < htab->elf.srelgot->size);
	      bfd_elf32_swap_reloca_out	(obfd, &rela,
					 (htab->elf.srelgot->contents
					  + (htab->elf.srelgot->reloc_count++
					     * sizeof (Elf32_External_Rela))));
	      bfd_put_32 (obfd, rela.r_addend,
			  htab->elf.sgot->contents + offset);
	    }
	  else
	    {
	      bfd_vma adjust = 0;

	      if (eh->gd_got.refcount > 0)
		{
		  rela.r_info = ELF32_R_INFO (0, R_HEX_DTPMOD_32);
		  rela.r_addend = 0;
		  BFD_ASSERT ((htab->elf.srelgot->reloc_count
			       * sizeof (Elf32_External_Rela))
			      < htab->elf.srelgot->size);
		  bfd_elf32_swap_reloca_out (obfd, &rela,
					     (htab->elf.srelgot->contents
					      + htab->elf.srelgot->reloc_count++
					      * sizeof (Elf32_External_Rela)));
		  if (eh != htab->gd_got.ld_got && h->def_regular)
		    bfd_put_32 (obfd,
				TLS_TRANSIT_OK (info, h)
				? hexagon_elf_tpoff (info, elf_hash_address (h))
				: hexagon_elf_dtpoff (info, elf_hash_address (h)),
				(htab->elf.sgot->contents + offset
				 + GOT_ENTRY_SIZE));
		  adjust = GOT_ENTRY_SIZE * 2;
		}

	      if (eh->ie_got.refcount > 0)
		{
		  if (info->shared)
		    {
		      rela.r_info = ELF32_R_INFO (0, R_HEX_TPREL_32);
		      rela.r_offset += adjust;
		      rela.r_addend
			= hexagon_elf_dtpoff (info, elf_hash_address (h));
		      BFD_ASSERT ((htab->elf.srelgot->reloc_count
				   * sizeof (Elf32_External_Rela))
				  < htab->elf.srelgot->size);
		      bfd_elf32_swap_reloca_out
			(obfd, &rela,
			 (htab->elf.srelgot->contents
			  + (htab->elf.srelgot->reloc_count++
			     * sizeof (Elf32_External_Rela))));
		    }
		  else
		    bfd_put_32 (obfd,
				hexagon_elf_tpoff (info, elf_hash_address (h)),
				htab->elf.sgot->contents + offset + adjust);
		}
	    }
	}
      else
	{
	  if (eh->ok_got.refcount > 0)
	    {
	      rela.r_info = ELF32_R_INFO (h->dynindx, R_HEX_GLOB_DAT);
	      rela.r_addend = 0;
	      BFD_ASSERT ((htab->elf.srelgot->reloc_count
			   * sizeof (Elf32_External_Rela))
			  < htab->elf.srelgot->size);
	      bfd_elf32_swap_reloca_out	(obfd, &rela,
					 (htab->elf.srelgot->contents
					  + (htab->elf.srelgot->reloc_count++
					     * sizeof (Elf32_External_Rela))));
	      if (h->def_regular)
		bfd_put_32 (obfd,
			    elf_hash_address (h),
			    htab->elf.sgot->contents + offset);
	    }
	  else
	    {
	      bfd_vma adjust = 0;

	      if (eh->gd_got.refcount > 0)
		{
		  rela.r_info = ELF32_R_INFO (h->dynindx, R_HEX_DTPMOD_32);
		  rela.r_addend = 0;
		  BFD_ASSERT ((htab->elf.srelgot->reloc_count
			       * sizeof (Elf32_External_Rela))
			      < htab->elf.srelgot->size);
		  if (!TLS_TRANSIT_OK (info, h))
		    bfd_elf32_swap_reloca_out
		      (obfd, &rela,
		       (htab->elf.srelgot->contents
			+ (htab->elf.srelgot->reloc_count++
			   * sizeof (Elf32_External_Rela))));
		  adjust += GOT_ENTRY_SIZE;
		  rela.r_offset += GOT_ENTRY_SIZE;
		  rela.r_info = ELF32_R_INFO (h->dynindx,
					      TLS_TRANSIT_OK (info, h)
					      ? R_HEX_TPREL_32
					      : R_HEX_DTPREL_32);
		  rela.r_addend = 0;
		  BFD_ASSERT ((htab->elf.srelgot->reloc_count
			       * sizeof (Elf32_External_Rela)
			       < htab->elf.srelgot->size));
		  bfd_elf32_swap_reloca_out
		    (obfd, &rela,
		     (htab->elf.srelgot->contents
		      + (htab->elf.srelgot->reloc_count++
			 * sizeof (Elf32_External_Rela))));
		  if (h->def_regular)
		    bfd_put_32
		      (obfd,
		       TLS_TRANSIT_OK (info, h)
		       ? hexagon_elf_tpoff (info, elf_hash_address (h))
		       : hexagon_elf_dtpoff (info, elf_hash_address (h)),
 		       htab->elf.sgot->contents + offset + adjust);

 		  adjust += GOT_ENTRY_SIZE;
 		  rela.r_offset += GOT_ENTRY_SIZE;
		}

	      if (eh->ie_got.refcount > 0)
		{
		  rela.r_info = ELF32_R_INFO (h->dynindx, R_HEX_TPREL_32);
		  rela.r_addend = 0;

		  BFD_ASSERT ((htab->elf.srelgot->reloc_count
			       * sizeof (Elf32_External_Rela))
			      < htab->elf.srelgot->size);
		  bfd_elf32_swap_reloca_out
		    (obfd, &rela,
		     (htab->elf.srelgot->contents
		      + (htab->elf.srelgot->reloc_count++
			 * sizeof (Elf32_External_Rela))));

		  if (h->def_regular)
		    bfd_put_32
		      (obfd,
		       hexagon_elf_tpoff (info, elf_hash_address (h)),
		       htab->elf.sgot->contents + offset + adjust);
		}
	    }
	}
    }

  if (h->needs_copy)
    {
      /* This symbol needs a copy reloc.  */
      Elf_Internal_Rela rela;
      unsigned int gp_size = elf_gp_size (htab->elf.dynobj);
      asection *s
	= (gp_size && h->size <= gp_size ) ? htab->sbss.r : htab->bss.r;

      if (h->dynindx == -1
	  || (h->root.type != bfd_link_hash_defined
	      && h->root.type != bfd_link_hash_defweak)
	  || !s)
	abort ();

      rela.r_info = ELF32_R_INFO (h->dynindx, R_HEX_COPY);
      rela.r_offset = elf_hash_address (h);
      rela.r_addend = 0;

      BFD_ASSERT (s->reloc_count * sizeof (Elf32_External_Rela) < s->size);
      bfd_elf32_swap_reloca_out
	(obfd, &rela,
	 s->contents + s->reloc_count++ * sizeof (Elf32_External_Rela));
    }

  /* Mark _DYNAMIC and _GLOBAL_OFFSET_TABLE_ as absolute.  */
  if (CONST_STRNEQ (h->root.root.string, "_DYNAMIC")
      || CONST_STRNEQ (h->root.root.string, "_GLOBAL_OFFSET_TABLE_"))
    sym->st_shndx = SHN_ABS;

  return TRUE;
}

/* Implement elf_backend_finish_dynamic_sections.  */
static bfd_boolean
hexagon_elf_finish_dynamic_sections (bfd *obfd, struct bfd_link_info *info)
{
  hexagon_link_hash_table *htab;
  bfd *dynobj;
  asection *sdyn, *sdynsym;

  htab = hexagon_hash_table (info);
  dynobj = htab->elf.dynobj;
  sdyn = bfd_get_section_by_name (dynobj, ".dynamic");
  sdynsym = bfd_get_section_by_name (obfd, ".dynsym");

  if (htab->elf.dynamic_sections_created)
    {
      Elf32_External_Dyn *dyncon;

      if (!sdyn || !htab->elf.sgot)
	abort ();

      for (dyncon = (Elf32_External_Dyn *) sdyn->contents;
	   dyncon < (Elf32_External_Dyn *) (sdyn->contents + sdyn->size);
	   dyncon++)
	{
	  Elf_Internal_Dyn dyn;

	  bfd_elf32_swap_dyn_in (dynobj, dyncon, &dyn);

	  switch (dyn.d_tag)
	    {
	    default:
	      continue;

	    case DT_PLTGOT:
	      dyn.d_un.d_ptr = section_base (htab->elf.sgotplt);
	      break;

	    case DT_JMPREL:
	      dyn.d_un.d_ptr = section_base (htab->elf.srelplt);
	      break;

	    case DT_PLTRELSZ:
	      dyn.d_un.d_val = htab->elf.srelplt->output_section->size;
	      break;

	    case DT_RELASZ:
	      /* The procedure linkage table relocs (DT_JMPREL) should
	         not be included in the overall relocs (DT_RELA).
	         Therefore, we override the DT_RELASZ entry here to
	         make it not include the JMPREL relocs.  Since the
	         linker script arranges for .rela.plt to follow all
	         other relocation sections, we don't have to worry
	         about changing the DT_RELA entry.  */
	      if (htab->elf.srelplt)
		{
		  dyn.d_un.d_val -= htab->elf.srelplt->output_section->size;
		  break;
		}
	      else
		continue;

	    case DT_RELA:
	      /* We may not be using the standard ELF linker script.
	         If .rela.plt is the first .rela section, we adjust
	         DT_REL to not include it.  */
	      if (!htab->elf.srelplt)
		continue;
	      else if (dyn.d_un.d_ptr != section_base (htab->elf.srelplt))
		continue;
	      else
		dyn.d_un.d_ptr += htab->elf.srelplt->size;
	      break;

	    case DT_HEX_SYMSZ:
	      if (sdynsym)
		{
		  dyn.d_un.d_val = bfd_section_size (obfd, sdynsym);
		  break;
		}
	      else
		continue;

	    case DT_HEX_VER:
	      dyn.d_un.d_val = 3;
	    }

	  bfd_elf32_swap_dyn_out (obfd, &dyn, dyncon);
	}

      /* Fill in the special first entry in the PLT.  */
      if (htab->elf.splt && htab->elf.splt->size > 0)
	{
	  bfd_vma offset;

	  /* PLT [0] contains the code that marshalls the dynamic linker to
	     resolve symbols used by the other PLT entries.  */
	  memcpy (htab->elf.splt->contents,
		  PLT_INITIAL_ENTRY_TEMP (obfd), PLT_INITIAL_ENTRY_SIZE);

	  /* Compute the difference between the address of the PLT and
	     of the GOT.  */
	  offset
	    = section_base (htab->elf.splt) - section_base (htab->elf.sgotplt);

	  if (!PLT_ENTRY_NEW (obfd))
	    {
	      /* A couple of insns contain the difference between the address
	         of the PLT and of the GOT.  */
	      hexagon_reloc_operand
		(hexagon_elf_howto_table + R_HEX_HI16,
		 (hexagon_insn *) (htab->elf.splt->contents
				   + 1 * HEXAGON_INSN_LEN),
		 offset, NULL);
	      hexagon_reloc_operand
		(hexagon_elf_howto_table + R_HEX_LO16,
		 (hexagon_insn *) (htab->elf.splt->contents
				   + 2 * HEXAGON_INSN_LEN),
		 offset, NULL);
	    }
	  else
	    {
	      /* An extended insn.  */
	      /* The PLT uses an Add To PC (there is no subtract from PC)
		 so invert the offset.  */
	      offset = -offset;
	      hexagon_reloc_operand
		(hexagon_elf_howto_table + R_HEX_B32_PCREL_X,
		 (hexagon_insn *) (htab->elf.splt->contents
				   + 0 * HEXAGON_INSN_LEN),
		 ((~(bfd_vma) 0
		   << hexagon_elf_howto_table[R_HEX_B32_PCREL_X].rightshift)
		  & offset),
		 NULL);
	      hexagon_reloc_operand
		(hexagon_elf_howto_table + R_HEX_6_PCREL_X,
		 (hexagon_insn *) (htab->elf.splt->contents
				   + 1 * HEXAGON_INSN_LEN),
		 (hexagon_elf_howto_table[R_HEX_6_PCREL_X].src_mask & offset),
		 NULL);
	    }

	  elf_section_data (htab->elf.splt->output_section)->this_hdr.sh_entsize
	    = PLT_ENTRY_SIZE (obfd);
	}
    }

  if (htab->elf.sgotplt)
    {
      /* Initialize the first few reserved entries of the GOT.  */
      if (htab->elf.sgotplt->size > 0)
	{
	  /* Set GOT [0] to the address of _DYNAMIC.  */
	  bfd_put_32 (obfd,
		      (sdyn ? section_base (sdyn) : 0),
		      htab->elf.sgotplt->contents + GOT_ENTRY_SIZE * 0);
	  /* Set GOT [1] and GOT [2], needed for the dynamic linker.  */
	  bfd_put_32 (obfd, 0,
		      htab->elf.sgotplt->contents + GOT_ENTRY_SIZE * 1);
	  bfd_put_32 (obfd, 0,
		      htab->elf.sgotplt->contents + GOT_ENTRY_SIZE * 2);
	}

      elf_section_data (htab->elf.sgotplt->output_section)->this_hdr.sh_entsize
	= GOT_ENTRY_SIZE;
    }

  if (htab->elf.sgot && htab->elf.sgot->size > 0)
    elf_section_data (htab->elf.sgot->output_section)->this_hdr.sh_entsize
      = GOT_ENTRY_SIZE;

  return TRUE;
}

/* Implement elf_backend_adjust_dynamic_symbol.
   Adjust a symbol defined by a dynamic object and referenced by a regular
   object.  The current definition is in some section of the dynamic
   object, but we're not including those sections.  We have to change
   the definition to something the rest of the link can understand.  */
static bfd_boolean
hexagon_elf_adjust_dynamic_symbol (struct bfd_link_info *info,
				   struct elf_link_hash_entry *h)
{
  hexagon_link_hash_table *htab;
  unsigned int gp_size;
  asection *s;

  htab = hexagon_hash_table (info);

  /* Make sure we know what is going on here.  */
  BFD_ASSERT (htab->elf.dynobj
	      && (h->needs_plt
		  || h->type == STT_GNU_IFUNC
		  || h->u.weakdef
		  || (h->def_dynamic && h->ref_regular && !h->def_regular)));

  /* If this is a function, put it in the PLT.  We will fill in the contents
     of the PLT later, when we know the address of the GOT section.  */
  if (h->type == STT_FUNC || h->needs_plt)
    {
      if (h->plt.refcount <= 0
	  || SYMBOL_CALLS_LOCAL (info, h)
	  || (ELF_ST_VISIBILITY (h->other) != STV_DEFAULT
	      && h->root.type == bfd_link_hash_undefweak))
	{
	  /* This case can occur if we saw a PLT relocation in an input
	     object, but the symbol was never referred to by a dynamic
	     object, or if all references were garbage collected.  In
	     such a case, we don't actually need to build a PLT, and
	     we can just do a PC-RELATIVE relocation instead.  */
	  h->plt.offset = -(bfd_vma) 1;
	  h->needs_plt = FALSE;
	}
      return TRUE;
    }
  else
    /* It's possible that we incorrectly decided that a PLT relocation was
       needed for a PC-relative relocation to a non-function symbol in
       check_relocs.  We can't decide accurately between function and
       non-function symbols in check-relocs; objects loaded later in
       the link may change h->type.  So fix it now.  */
    h->plt.offset = -(bfd_vma) 1;

  /* If this is a weak symbol, and there is a real definition, the
     processor-independent code will have arranged for us to see the
     real definition first, and we can just use the same value.  */
  if (h->u.weakdef)
    {
      BFD_ASSERT (h->u.weakdef->root.type == bfd_link_hash_defined
		  || h->u.weakdef->root.type == bfd_link_hash_defweak);
      h->root.u.def.section = h->u.weakdef->root.u.def.section;
      h->root.u.def.value = h->u.weakdef->root.u.def.value;
      if (ELIMINATE_COPY_RELOCS || info->nocopyreloc)
	h->non_got_ref = h->u.weakdef->non_got_ref;
      return TRUE;
    }

  /* This is a reference to a symbol defined by a dynamic object which
     is not a function.  */

  /* If we are creating a shared library, we must presume that the
     only references to the symbol are via the global offset table.
     For such cases we need not do anything here; the relocations will
     be handled correctly by relocate_section.  */
  if (info->shared)
    return TRUE;

  /* If there are no references to this symbol that do not use the
     GOT, we don't need to generate a copy reloc.  */
  if (!h->non_got_ref)
    return TRUE;

  /* If -z nocopyreloc was given, we won't generate them either.  */
  if (info->nocopyreloc)
    {
      h->non_got_ref = FALSE;
      return TRUE;
    }

  if (ELIMINATE_COPY_RELOCS)
    {
      hexagon_dyn_reloc *p;

      for (p = hexagon_hash_entry (h)->dyn_relocs; p; p = p->next)
	{
	  s = p->sec->output_section;
	  if (s && (s->flags & SEC_READONLY))
	    break;
	}

      /* If we didn't find any dynamic relocations in read-only sections,
	 then we'll be keeping the dynamic relocations and avoiding the
	 copy reloc.  */
      if (!p)
	{
	  h->non_got_ref = FALSE;
	  return TRUE;
	}
    }

  /* We must allocate the symbol in our .dynbss section, which will become
     part of the .[s]bss section of the executable.  There will be an entry
     for this symbol in the .dynsym section.  The dynamic object will contain
     position-independent code, so all references from the dynamic object to
     this symbol will go through the GOT.  The dynamic linker will use the
     .dynsym entry to determine the address it must put in the GOT, so both
     the dynamic object and the regular object will refer to the same memory
     location for the variable.  */

  /* We must generate a R_HEX_COPY reloc to tell the dynamic linker
     to copy the initial value out of the dynamic object and into the
     runtime process image.  */
  gp_size = elf_gp_size (htab->elf.dynobj);
  if (h->root.u.def.section->flags & SEC_ALLOC)
    {
      asection *r
	= (gp_size && h->size <= gp_size) ? htab->sbss.r : htab->bss.r;
      BFD_ASSERT (r);
      r->size += sizeof (Elf32_External_Rela);
      h->needs_copy = 1;
    }

  /* If a symbol has no size and does not require a PLT entry, R_HEX_COPY
     would probably do the wrong thing.  */
  if (!h->size && !h->needs_plt)
    {
      (*_bfd_error_handler)
	(_("warning: size of dynamic symbol `%s' is zero"),
	 h->root.root.string);
      return TRUE;
    }

  /* Choose the proper section.  */
  s = (gp_size && h->size <= gp_size) ? htab->sbss.s : htab->bss.s;
  return _bfd_elf_adjust_dynamic_copy (h, s);
}

/* Allocate space in PLT, GOT and associated relocation sections for
   dynamic relocations.  */
static bfd_boolean
hexagon_allocate_dynrel (struct elf_link_hash_entry *h,
			 struct bfd_link_info *info)
{
  hexagon_link_hash_table *htab;
  hexagon_link_hash_entry *eh;
  hexagon_dyn_reloc *p;

  if (h->root.type == bfd_link_hash_indirect)
    return TRUE;

  if (h->root.type == bfd_link_hash_warning)
    /* When warning symbols are created, they **replace** the "real"
       entry in the hash table, thus we never get to see the real
       symbol in a hash traversal.  So look at it now.  */
    h = (struct elf_link_hash_entry *) h->root.u.i.link;

  htab = hexagon_hash_table (info);
  eh = hexagon_hash_entry (h);

  if (htab->elf.dynamic_sections_created && h->plt.refcount > 0)
    {
      /* Make sure that this symbol is output as a dynamic symbol.
         Undefined weak symbols won't be marked as dynamic just yet.  */
      if (h->dynindx == -1
	  && !h->forced_local
	  && !bfd_elf_link_record_dynamic_symbol (info, h))
	return FALSE;

      if (info->shared
	  || WILL_CALL_FINISH_DYNAMIC_SYMBOL (TRUE, info->shared, h))
	{
	  /* If this is the first PLT entry, make room for the reserved
	     entries.  */
	  if (!htab->elf.splt->size)
	    htab->elf.splt->size = PLT_INITIAL_ENTRY_SIZE;
	  h->plt.offset = htab->elf.splt->size;

	  /* If this symbol is not defined in a regular file, then set the
	     symbol to its PLT entry.  This is required to make function
	     pointers compare as equal between the normal executable and
	     the shared library.  */
	  if (!h->def_regular)
	    {
	      h->root.u.def.section = htab->elf.splt;
	      h->root.u.def.value = h->plt.offset;
	    }

	  /* Make room for this entry.  */
	  htab->elf.splt->size += PLT_ENTRY_SIZE (htab->elf.splt->owner);

	  /* We also need to make an entry in the .got.plt section, which
	     will be placed in the GOT section by the linker script.  */
	  htab->elf.sgotplt->size += GOT_ENTRY_SIZE;

	  /* We also need to make an entry in the .rela.plt section.  */
	  htab->elf.srelplt->size += sizeof (Elf32_External_Rela);
	}
      else
	{
	  h->plt.offset = -(bfd_vma) 1;
	  h->needs_plt = FALSE;
	}
    }
  else
    {
      h->plt.offset = -(bfd_vma) 1;
      h->needs_plt = FALSE;
    }

  if (h->got.refcount > 0)
    {
      int nslots;

      /* Make sure this symbol is output as a dynamic symbol.  Undefined
         weak symbols won't be marked as dynamic just yet.  */
      if (h->dynindx == -1
	  && !h->forced_local
	  && !bfd_elf_link_record_dynamic_symbol (info, h))
	return FALSE;

      nslots = (eh->gd_got.refcount > 0
		? (eh->ie_got.refcount > 0 ? 3 : 2)
		: 1);
      h->got.offset = htab->elf.sgot->size;
      htab->elf.sgot->size += GOT_ENTRY_SIZE * nslots;

      if (info->shared
	  || WILL_CALL_FINISH_DYNAMIC_SYMBOL
	       (htab->elf.dynamic_sections_created, info->shared, h)
	  || eh->gd_got.refcount > 0
	  || eh->ie_got.refcount > 0)
	/* TLS variables made local may require just one or no relocations,
	   but it's better to be safe.  */
	htab->elf.srelgot->size += sizeof (Elf32_External_Rela) * nslots;

      if (eh == htab->gd_got.ld_got)
	{
	  BFD_ASSERT (eh->elf.root.type == bfd_link_hash_defined);

	  eh->elf.root.u.def.section = htab->elf.sgot;
	  eh->elf.root.u.def.value = htab->gd_got.ld_got->elf.got.offset;
	}
    }
  else
    h->got.offset = -(bfd_vma) 1;

  if (!eh->dyn_relocs)
    return TRUE;

  if (info->shared)
    {
      /* In the shared -Bsymbolic case, discard space allocated for dynamic
         PC-relative relocations against symbols which turn out to be
	 defined in regular objects.  For the shared case, discard space
	 for PC-relative relocations that have become local due to symbol
	 visibility changes.  */
      if (SYMBOL_CALLS_LOCAL (info, h))
	{
	  hexagon_dyn_reloc **pp;

	  for (pp = &eh->dyn_relocs; (p = *pp);)
	    {
	      if (p->count)
		p->count -= p->pc_count;
	      p->pc_count = 0;
	      if (!p->count)
		*pp = p->next;
	      else
		pp = &p->next;
	    }
	}

      /* Also discard relocs on undefined weak syms with non-default
         visibility.  */
      if (eh->dyn_relocs && h->root.type == bfd_link_hash_undefweak)
	{
	  if (ELF_ST_VISIBILITY (h->other) != STV_DEFAULT)
	    eh->dyn_relocs = NULL;

	  /* Make sure undefined weak symbols are output as a dynamic
	     symbol in PIEs.  */
	  else if (h->dynindx == -1
		   && !h->forced_local
		   && !bfd_elf_link_record_dynamic_symbol (info, h))
	    return FALSE;
	}
    }
  else if (ELIMINATE_COPY_RELOCS || info->nocopyreloc)
    {
      /* For the non-shared case, discard space for relocations against
         symbols which turn out to need copy-relocations or are not
	 dynamic.  */
      if (!h->non_got_ref
	  && ((h->def_dynamic && !h->def_regular)
	      || (htab->elf.dynamic_sections_created
		  && (h->root.type == bfd_link_hash_undefweak
		      || h->root.type == bfd_link_hash_undefined))))
	{
	  /* Make sure this symbol is output as a dynamic symbol.
	     Undefined weak symbols won't be marked as dynamic just yet.  */
	  if (h->dynindx == -1
	      && !h->forced_local
	      && !bfd_elf_link_record_dynamic_symbol (info, h))
	    return FALSE;

	  /* If that succeeded, we know we'll be keeping all the
	     relocations.  */
	  if (h->dynindx == -1)
	    eh->dyn_relocs = NULL;
	}
      else
	eh->dyn_relocs = NULL;
    }

  /* Finally, allocate space.  */
  for (p = eh->dyn_relocs; p; p = p->next)
    elf_section_data (p->sec)->sreloc->size
      += p->count * sizeof (Elf32_External_Rela);

  return TRUE;
}

/* Find any dynamic relocations that apply to read-only sections and,
   if so, mark the object as having relative relocations.  */
static bfd_boolean
hexagon_readonly_dynrel (struct elf_link_hash_entry *h,
			 struct bfd_link_info *info)
{
  hexagon_dyn_reloc *p;

  if (h->root.type == bfd_link_hash_indirect)
    return TRUE;

  if (h->root.type == bfd_link_hash_warning)
    h = (struct elf_link_hash_entry *) h->root.u.i.link;

  for (p = hexagon_hash_entry (h)->dyn_relocs; p; p = p->next)
    {
      asection *s = p->sec->output_section;

      if (s && s->flags & SEC_READONLY && s->flags & SEC_ALLOC)
	{
	  info->flags |= DF_TEXTREL;

	  /* Not an error, just cut short the traversal.  */
	  return FALSE;
	}
    }
  return TRUE;
}

/* Implement elf_backend_size_dynamic_sections.  */
static bfd_boolean
hexagon_elf_size_dynamic_sections (bfd *obfd ATTRIBUTE_UNUSED,
				   struct bfd_link_info *info)
{
  hexagon_link_hash_table *htab;
  bfd *dynobj;
  asection *s;
  bfd_boolean relocs;
  bfd *ibfd;
  size_t i;
  bfd_vma *local_got_offsets;

  htab = hexagon_hash_table (info);
  dynobj = htab->elf.dynobj;
  if (!dynobj)
    abort ();

  if (htab->elf.dynamic_sections_created && info->executable)
    {
      /* Set the contents of the .interp section to the interpreter.  */
      s = bfd_get_section_by_name (dynobj, ".interp");
      if (!s)
	abort ();
      s->size = sizeof (ELF_DYNAMIC_INTERPRETER);
      s->contents = (bfd_byte *) ELF_DYNAMIC_INTERPRETER;
    }

  /* Set up GOT offsets for local symbols and space for local dynamic
     relocations.  */
  for (ibfd = info->input_bfds; ibfd; ibfd = ibfd->link_next)
    {
      bfd_signed_vma *local_got_refcounts;
      Elf_Internal_Shdr *symtab_hdr;

      if (bfd_get_flavour (ibfd) != bfd_target_elf_flavour)
	continue;

      for (s = ibfd->sections; s; s = s->next)
	{
	  hexagon_dyn_reloc *p;

	  for (p = (hexagon_dyn_reloc *) elf_section_data (s)->local_dynrel;
	       p; p = p->next)
	    {
	      if (!bfd_is_abs_section (p->sec)
		  && bfd_is_abs_section (p->sec->output_section))
		{
		  /* Input section has been discarded, either because it is
		     a copy of a link-once section or due to linker script,
		     so we'll discard the relocations too.  */
		}
	      else if (p->count)
		{
		  elf_section_data (p->sec)->sreloc->size
		    += p->count * sizeof (Elf32_External_Rela);
		  if (p->sec->output_section->flags & SEC_READONLY)
		    info->flags |= DF_TEXTREL;
		}
	    }
	}

      local_got_offsets = elf_local_got_offsets (ibfd);

      symtab_hdr = &elf_tdata (ibfd)->symtab_hdr;
      for (local_got_refcounts = elf_local_got_refcounts (ibfd), i = 0;
	   local_got_refcounts && i < symtab_hdr->sh_info; i++)
	{
	  if (local_got_refcounts[i] > 0)
	    {
	      int is_gd, is_ie, nslots = 0;
	      local_got_refcounts[i] = htab->elf.sgot->size;
	      is_gd = local_got_refcounts[LGOT_GD (symtab_hdr, i)] > 0;
	      is_ie = local_got_refcounts[LGOT_IE (symtab_hdr, i)] > 0;
	      if (is_gd)
		nslots += 2;
	      if (is_ie)
		nslots += 1;

	      if (nslots > 0)
		{
		  local_got_offsets[i] = htab->elf.sgot->size;
		  htab->elf.sgot->size += GOT_ENTRY_SIZE * nslots;
		}

	      /* FIXME: perhaps not when IE.  */
	      if (info->shared || is_gd || is_ie)
		htab->elf.srelgot->size
		  += (sizeof (Elf32_External_Rela)
		      * (is_gd ? (is_ie ? 3 : 2) : 1));
	    }
	  else
	    local_got_refcounts[i] = -(bfd_vma) 1;
	}
    }

  /* Allocate global symbol's PLT and GOT entries, as well as space for
     global symbols dynamic relocations.  */
  elf_link_hash_traverse (&htab->elf, hexagon_allocate_dynrel, (PTR) info);

  /* check_relocs and adjust_dynamic_symbol have determined the sizes of
     the various dynamic sections.  Allocate memory for them.  */
  relocs = FALSE;
  for (s = dynobj->sections; s; s = s->next)
    {
      bfd_boolean strip = TRUE;

      if (!(s->flags & SEC_LINKER_CREATED))
	continue;

      if (s == htab->elf.splt
	  || s == htab->elf.sgot
	  || s == htab->elf.sgotplt
	  || s == htab->bss.s
	  || s == htab->sbss.s)
	{
	  /* Strip this section if we don't need it; see comment below.  */
	  if (htab->elf.hplt)
	    strip = FALSE;
	}
      else if (CONST_STRNEQ (bfd_get_section_name (dynobj, s), ".rela"))
	{
	  if (s->size && s != htab->elf.srelplt)
	    relocs = TRUE;

	  /* We use the reloc_count field as a counter if we need to copy
	     relocations into the output file.  */
	  s->reloc_count = 0;
	}
      else
	/* It's not one of our sections, so don't allocate space.  */
	continue;

      if (!s->size)
	{
	  /* If we don't need this section, strip it from the output file.
	     This is mostly to handle .rela.[s]bss and .rela.plt.  We must
	     create both sections in create_dynamic_sections, because they
	     must be created before the linker maps input sections to output
	     sections.  The linker does that before adjust_dynamic_symbol is
	     called, and it is that function that decides whether anything
	     needs to go into these sections.  */
	  if (strip)
	    s->flags |= SEC_EXCLUDE;
	  continue;
	}

      if (!(s->flags & SEC_HAS_CONTENTS))
	continue;

      /* Allocate memory for the section contents.  We use bfd_zalloc here
         in case unused entries are not reclaimed before the contents of the
         section are written out.  This should not happen, but if
         it does, we get a R_HEX_NONE relocATION instead of garbage.  */
      s->contents = (bfd_byte *) bfd_zalloc (dynobj, s->size);
      if (!s->contents)
	return FALSE;
    }

  if (htab->elf.dynamic_sections_created)
    {
      /* Add some entries to the .dynamic section.  We fill in the values
         later, in finish_dynamic_sections, but we must add the entries now
         so that we get the correct size for the .dynamic section.  The
         DT_DEBUG entry is filled in by the dynamic linker and used by the
         debugger.  */
      if (info->executable
	  && !_bfd_elf_add_dynamic_entry (info, DT_DEBUG, 0))
	return FALSE;

      if (htab->elf.splt->size
	  && (!_bfd_elf_add_dynamic_entry (info, DT_PLTGOT, 0)
	      || !_bfd_elf_add_dynamic_entry (info, DT_PLTRELSZ, 0)
	      || !_bfd_elf_add_dynamic_entry (info, DT_PLTREL, DT_RELA)
	      || !_bfd_elf_add_dynamic_entry (info, DT_JMPREL, 0)))
	return FALSE;

      if (relocs)
	{
	  if (!_bfd_elf_add_dynamic_entry (info, DT_RELA, 0)
	      || !_bfd_elf_add_dynamic_entry (info, DT_RELASZ, 0)
	      || !_bfd_elf_add_dynamic_entry (info, DT_RELAENT,
					      sizeof (Elf32_External_Rela)))
	    return FALSE;

	  /* If any dynamic relocations apply to a read-only section, then we
	     need a DT_TEXTREL entry.  */
	  if (!(info->flags & DF_TEXTREL))
	    elf_link_hash_traverse (&htab->elf, hexagon_readonly_dynrel, info);

	  if (info->flags & DF_TEXTREL
	      && !_bfd_elf_add_dynamic_entry (info, DT_TEXTREL, 0))
	    return FALSE;
	}

      /* FIXME: this dynamic tag is redundant, since it can be infered by
         multiplying DT_SYMENT by nchain in DT_HASH.  If the CStomer is
         adamant about it, then add it.  */
      if (FALSE)
	{
	  if (!_bfd_elf_add_dynamic_entry (info, DT_HEX_SYMSZ, 0))
	    return FALSE;
	}

      if (!_bfd_elf_add_dynamic_entry (info, DT_HEX_VER, 0))
	return FALSE;
    }

  return TRUE;
}

/* Implement elf_backend_reloc_type_class.
   Used to decide how to sort relocs in an optimal manner for the dynamic
   linker before writing them out.  */
static enum elf_reloc_type_class
hexagon_elf_reloc_type_class (const Elf_Internal_Rela *rela)
{
  switch (ELF32_R_TYPE (rela->r_info))
    {
    case R_HEX_RELATIVE:
      return reloc_class_relative;
    case R_HEX_JMP_SLOT:
      return reloc_class_plt;
    case R_HEX_COPY:
      return reloc_class_copy;
    default:
      return reloc_class_normal;
    }
}

/* Implement elf_backend_create_dynamic_sections.
   Create .plt, .rela.plt, .got, .got.plt, .rela.got, .dynbss, .dynsbss,
   .rela.bss and .rela.sbss sections in the dynamic object and set up
   shortcuts to them in our hash table.  */
static bfd_boolean
hexagon_elf_create_dynamic_sections (bfd *abfd, struct bfd_link_info *info)
{
  hexagon_link_hash_table *htab;
  const flagword flags = get_elf_backend_data (abfd)->dynamic_sec_flags;

  htab = hexagon_hash_table (info);

  if (!_bfd_elf_create_dynamic_sections (abfd, info))
    return FALSE;

  /* Some addressing modes are shifted by the data size, so offsets from
     the GOT must be a multiple of its natural alignment.  Since the largest
     native data size is 8, make sure that the GOT is thusly aligned.  */
  if (!bfd_set_section_alignment (abfd, htab->elf.sgotplt, bfd_log2 (8)))
    return FALSE;

  if (get_elf_backend_data (abfd)->want_plt_sym)
    /* Enable pretty disassembly of the PLT.  */
    htab->elf.hplt->type = STT_FUNC;

  htab->bss.s = bfd_get_section_by_name (abfd, ".dynbss");
  if (info->executable)
    htab->bss.r = bfd_get_section_by_name (abfd, ".rela.bss");

  if (elf_gp_size (htab->elf.dynobj))
    {
      htab->sbss.s
	= bfd_make_section_with_flags (abfd, ".dynsbss",
				       SEC_ALLOC | SEC_LINKER_CREATED);
      if (info->executable)
	{
	  htab->sbss.r
	    = bfd_make_section_with_flags (abfd, ".rela.sbss",
					   flags | SEC_READONLY);
	  /* .rela.sbss should have 4-bytes alignment.  */
	  if (!bfd_set_section_alignment (abfd, htab->sbss.r, bfd_log2 (4)))
	    return FALSE;
	}

      if (!htab->sbss.s || (info->executable && !htab->sbss.r))
	abort ();
    }

  return TRUE;
}

/* Implement elf_backend_plt_sym_val.
   Return address for nth PLT entry in the PLT, for a given relocation,
   or (bfd_vma) -1 if it should not be included.  */
static bfd_vma
hexagon_elf_plt_sym_val (bfd_vma i, const asection *plt,
			 const arelent *rel ATTRIBUTE_UNUSED)
{
  return plt->vma + i * PLT_ENTRY_SIZE (plt->owner) + PLT_INITIAL_ENTRY_SIZE;
}

/* Implement elf_backend_hash_symbol.
   Return TRUE if symbol should be hashed in the `.gnu.hash' section.  */
static bfd_boolean
hexagon_elf_hash_symbol (struct elf_link_hash_entry *h)
{
  if (h->plt.offset != (bfd_vma) - 1
      && !h->def_regular
      && !h->pointer_equality_needed)
    return FALSE;

  return _bfd_elf_hash_symbol (h);
}



/* BFD configuration.  */

#define TARGET_LITTLE_SYM			bfd_elf32_littlehexagon_vec
#define TARGET_LITTLE_NAME			"elf32-littlehexagon"
#define ELF_TARGET_ID				HEXAGON_ELF_DATA
#define ELF_ARCH				bfd_arch_hexagon
#define ELF_MACHINE_CODE			EM_HEXAGON
#define ELF_MINPAGESIZE				0x1000
#define ELF_MAXPAGESIZE				0x1000
#define ELF_COMMONPAGESIZE			0x1000

#define elf_backend_may_use_rel_p		0
#define	elf_backend_may_use_rela_p		1
#define	elf_backend_default_use_rela_p		1
#define elf_backend_rela_normal			1
#define elf_backend_can_gc_sections		1
#define elf_backend_can_refcount		1
#define elf_backend_got_header_size		GOT_INITIAL_ENTRY_SIZE
#define elf_backend_plt_header_size		PLT_INITIAL_ENTRY_SIZE
#define elf_backend_plt_alignment		4
#define elf_backend_plt_readonly		1
#define elf_backend_want_got_plt		1
#define elf_backend_want_plt_sym		1

#define elf_info_to_howto			0
#define elf_info_to_howto_rel			hexagon_info_to_howto_rel
#define bfd_elf32_bfd_reloc_type_lookup		hexagon_elf_reloc_type_lookup
#define bfd_elf32_bfd_reloc_name_lookup		hexagon_elf_reloc_name_lookup

#define elf_backend_relocs_compatible		_bfd_elf_relocs_compatible
#define elf_backend_object_p			hexagon_elf_object_p
#define elf_backend_gc_mark_hook		hexagon_elf_gc_mark_hook
#define elf_backend_gc_sweep_hook		hexagon_elf_gc_sweep_hook
#define elf_backend_final_write_processing	hexagon_elf_final_write_processing
#define elf_backend_section_from_shdr		hexagon_elf_section_from_shdr
#define elf_backend_add_symbol_hook		hexagon_elf_add_symbol_hook
#define elf_backend_fake_sections		hexagon_elf_fake_sections
#define elf_backend_symbol_processing		hexagon_elf_symbol_processing
#define elf_backend_post_process_headers	hexagon_elf_post_process_headers
#define elf_backend_section_from_bfd_section	hexagon_elf_section_from_bfd_section
#define elf_backend_link_output_symbol_hook	hexagon_elf_link_output_symbol_hook
#define elf_backend_copy_indirect_symbol	hexagon_elf_copy_indirect_symbol
#define elf_backend_additional_program_headers	hexagon_elf_additional_program_headers
#define elf_backend_reloc_type_class		hexagon_elf_reloc_type_class
#define elf_backend_common_definition		hexagon_elf_common_definition
#define elf_backend_plt_sym_val		        hexagon_elf_plt_sym_val
#define elf_backend_hash_symbol		        hexagon_elf_hash_symbol

#define elf_backend_check_relocs		hexagon_elf_check_relocs
#define elf_backend_adjust_dynamic_symbol	hexagon_elf_adjust_dynamic_symbol
#define elf_backend_size_dynamic_sections	hexagon_elf_size_dynamic_sections
#define bfd_elf32_bfd_merge_private_bfd_data	hexagon_elf_merge_private_bfd_data
#define bfd_elf32_bfd_relax_section		hexagon_elf_relax_section
#define elf_backend_relocate_section		hexagon_elf_relocate_section
#define elf_backend_finish_dynamic_symbol	hexagon_elf_finish_dynamic_symbol
#define elf_backend_finish_dynamic_sections	hexagon_elf_finish_dynamic_sections
#define elf_backend_create_dynamic_sections	hexagon_elf_create_dynamic_sections

#define bfd_elf32_bfd_get_relocated_section_contents \
                                                hexagon_elf_get_relocated_section_contents
#define bfd_elf32_bfd_link_hash_table_create	hexagon_elf_link_hash_table_create

#include "elf32-target.h"

/* hexagon-linux BFD configuration.  */

#undef TARGET_LITTLE_SYM
#undef TARGET_LITTLE_NAME
#undef ELF_MAXPAGESIZE
#undef elf32_bed
#define elf32_bed				hexagon_linux_elf_bed

#define TARGET_LITTLE_SYM			bfd_elf32_hexagon_linux_vec
#define TARGET_LITTLE_NAME			"elf32-hexagon-linux"
#define ELF_MAXPAGESIZE			       0x10000

#include "elf32-target.h"

/* Backwards-compatible BFD configuration.  */

#undef TARGET_LITTLE_SYM
#undef TARGET_LITTLE_NAME

#define TARGET_LITTLE_SYM			bfd_elf32_littleqdsp6_vec
#define TARGET_LITTLE_NAME			"elf32-littleqdsp6"

#undef elf32_bed
#define elf32_bed				qdsp6_elf_bed

#include "elf32-target.h"
