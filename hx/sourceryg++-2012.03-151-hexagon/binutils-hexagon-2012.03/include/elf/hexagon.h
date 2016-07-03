
/* Hexagon ELF support for BFD.
   Copyright 1995, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.

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

/* This file holds definitions specific to the Hexagon ELF ABI.  */

#ifndef _ELF_HEX_H
#define _ELF_HEX_H

#include "elf/reloc-macros.h"

/* Relocations.  */
START_RELOC_NUMBERS (elf_hexagon_reloc_type)
/* V2 */
RELOC_NUMBER (R_HEX_NONE, 0)
RELOC_NUMBER (R_HEX_B22_PCREL, 1)
RELOC_NUMBER (R_HEX_B15_PCREL, 2)
RELOC_NUMBER (R_HEX_B7_PCREL, 3)
RELOC_NUMBER (R_HEX_LO16, 4)
RELOC_NUMBER (R_HEX_HI16, 5)
RELOC_NUMBER (R_HEX_32, 6)
RELOC_NUMBER (R_HEX_16, 7)
RELOC_NUMBER (R_HEX_8, 8)
RELOC_NUMBER (R_HEX_GPREL16_0, 9)
RELOC_NUMBER (R_HEX_GPREL16_1, 10)
RELOC_NUMBER (R_HEX_GPREL16_2, 11)
RELOC_NUMBER (R_HEX_GPREL16_3, 12) RELOC_NUMBER (R_HEX_HL16, 13)
/* V3 */
RELOC_NUMBER (R_HEX_B13_PCREL, 14)
/* V4 */
RELOC_NUMBER (R_HEX_B9_PCREL, 15)
/* V4 (extenders) */
RELOC_NUMBER (R_HEX_B32_PCREL_X, 16) RELOC_NUMBER (R_HEX_32_6_X, 17)
/* V4 (extended) */
RELOC_NUMBER (R_HEX_B22_PCREL_X, 18)
RELOC_NUMBER (R_HEX_B15_PCREL_X, 19)
RELOC_NUMBER (R_HEX_B13_PCREL_X, 20)
RELOC_NUMBER (R_HEX_B9_PCREL_X, 21)
RELOC_NUMBER (R_HEX_B7_PCREL_X, 22)
RELOC_NUMBER (R_HEX_16_X, 23)
RELOC_NUMBER (R_HEX_12_X, 24)
RELOC_NUMBER (R_HEX_11_X, 25)
RELOC_NUMBER (R_HEX_10_X, 26)
RELOC_NUMBER (R_HEX_9_X, 27)
RELOC_NUMBER (R_HEX_8_X, 28)
RELOC_NUMBER (R_HEX_7_X, 29) RELOC_NUMBER (R_HEX_6_X, 30)
/* V2 PIC */
RELOC_NUMBER (R_HEX_32_PCREL, 31)
RELOC_NUMBER (R_HEX_COPY, 32)
RELOC_NUMBER (R_HEX_GLOB_DAT, 33)
RELOC_NUMBER (R_HEX_JMP_SLOT, 34)
RELOC_NUMBER (R_HEX_RELATIVE, 35)
RELOC_NUMBER (R_HEX_PLT_B22_PCREL, 36)
RELOC_NUMBER (R_HEX_GOTREL_LO16, 37)
RELOC_NUMBER (R_HEX_GOTREL_HI16, 38)
RELOC_NUMBER (R_HEX_GOTREL_32, 39)
RELOC_NUMBER (R_HEX_GOT_LO16, 40)
RELOC_NUMBER (R_HEX_GOT_HI16, 41)
RELOC_NUMBER (R_HEX_GOT_32, 42) RELOC_NUMBER (R_HEX_GOT_16, 43)
/* V2 TLS */
RELOC_NUMBER (R_HEX_DTPMOD_32, 44)
RELOC_NUMBER (R_HEX_DTPREL_LO16, 45)
RELOC_NUMBER (R_HEX_DTPREL_HI16, 46)
RELOC_NUMBER (R_HEX_DTPREL_32, 47)
RELOC_NUMBER (R_HEX_DTPREL_16, 48)
RELOC_NUMBER (R_HEX_GD_PLT_B22_PCREL, 49)
RELOC_NUMBER (R_HEX_GD_GOT_LO16, 50)
RELOC_NUMBER (R_HEX_GD_GOT_HI16, 51)
RELOC_NUMBER (R_HEX_GD_GOT_32, 52)
RELOC_NUMBER (R_HEX_GD_GOT_16, 53)
RELOC_NUMBER (R_HEX_IE_LO16, 54)
RELOC_NUMBER (R_HEX_IE_HI16, 55)
RELOC_NUMBER (R_HEX_IE_32, 56)
RELOC_NUMBER (R_HEX_IE_GOT_LO16, 57)
RELOC_NUMBER (R_HEX_IE_GOT_HI16, 58)
RELOC_NUMBER (R_HEX_IE_GOT_32, 59)
RELOC_NUMBER (R_HEX_IE_GOT_16, 60)
RELOC_NUMBER (R_HEX_TPREL_LO16, 61)
RELOC_NUMBER (R_HEX_TPREL_HI16, 62)
RELOC_NUMBER (R_HEX_TPREL_32, 63) RELOC_NUMBER (R_HEX_TPREL_16, 64)
/* V4 PIC */
RELOC_NUMBER (R_HEX_6_PCREL_X, 65)
RELOC_NUMBER (R_HEX_GOTREL_32_6_X, 66)
RELOC_NUMBER (R_HEX_GOTREL_16_X, 67)
RELOC_NUMBER (R_HEX_GOTREL_11_X, 68)
RELOC_NUMBER (R_HEX_GOT_32_6_X, 69)
RELOC_NUMBER (R_HEX_GOT_16_X, 70) RELOC_NUMBER (R_HEX_GOT_11_X, 71)
/* V4 TLS */
RELOC_NUMBER (R_HEX_DTPREL_32_6_X, 72)
RELOC_NUMBER (R_HEX_DTPREL_16_X, 73)
RELOC_NUMBER (R_HEX_DTPREL_11_X, 74)
RELOC_NUMBER (R_HEX_GD_GOT_32_6_X, 75)
RELOC_NUMBER (R_HEX_GD_GOT_16_X, 76)
RELOC_NUMBER (R_HEX_GD_GOT_11_X, 77)
RELOC_NUMBER (R_HEX_IE_32_6_X, 78)
RELOC_NUMBER (R_HEX_IE_16_X, 79)
RELOC_NUMBER (R_HEX_IE_GOT_32_6_X, 80)
RELOC_NUMBER (R_HEX_IE_GOT_16_X, 81)
RELOC_NUMBER (R_HEX_IE_GOT_11_X, 82)
RELOC_NUMBER (R_HEX_TPREL_32_6_X, 83)
RELOC_NUMBER (R_HEX_TPREL_16_X, 84)
RELOC_NUMBER (R_HEX_TPREL_11_X, 85) 

RELOC_NUMBER (R_HEX_LD_PLT_B22_PCREL, 86)

RELOC_NUMBER (R_HEX_LD_GOT_LO16, 87)
RELOC_NUMBER (R_HEX_LD_GOT_HI16, 88)
RELOC_NUMBER (R_HEX_LD_GOT_32, 89)
RELOC_NUMBER (R_HEX_LD_GOT_16, 90)
RELOC_NUMBER (R_HEX_LD_GOT_32_6_X, 91)
RELOC_NUMBER (R_HEX_LD_GOT_16_X, 92)
RELOC_NUMBER (R_HEX_LD_GOT_11_X, 93)

END_RELOC_NUMBERS (R_HEX_max)

/* Processor-specific flags for the ELF header e_type field.  */
/* Object is WHIRL, matching ET_SGI_IR. */
#define ET_HEX_IR ET_LOPROC

/* Processor-specific flags for the ELF header e_flags field.  */
/* Four-bit machine type field.  */
#define EF_HEX_MACH 0x0f
/* Limit to 16 CPU types for now. */
#define EF_HEX_MACH_VER(e_flags) ((e_flags) & EF_HEX_MACH)
/* Various CPU types.  */
#define EF_HEX_MACH_V1 0
#define EF_HEX_MACH_V2 1
#define EF_HEX_MACH_V3 2
#define EF_HEX_MACH_V4 3
#define EF_HEX_MACH_V5 4
#define EF_HEX_MACH_V55 5
/* File contains position independent code.  */
#define EF_HEX_PIC 0x00000100

/* Processor-specific section indices.  These sections do not actually
   exist.  Symbols with a st_shndx field corresponding to one of these
   values have a special meaning.  */
/* Small common symbol.  Note that code in elf32-hexagon.c is aware that
   these section indices are consecutive.  */
#define SHN_HEX_SCOMMON   (SHN_LOPROC + 0)
#define SHN_HEX_SCOMMON_1 (SHN_LOPROC + 1)
#define SHN_HEX_SCOMMON_2 (SHN_LOPROC + 2)
#define SHN_HEX_SCOMMON_4 (SHN_LOPROC + 3)
#define SHN_HEX_SCOMMON_8 (SHN_LOPROC + 4)

/* Processor-specific section flags.  */
/* This section must be in the global data area.  */
#define SHF_HEX_GPREL 0x10000000

/* Processor-specific section type.  */
/* Link editor is to sort the entries in this section based on their sizes. */
#define SHT_HEX_ORDERED (SHT_LOPROC + 0)

/* Processor specific program header types.  */
/* Different memory types. */
#define PT_HEX_EBI PT_LOAD
#define PT_HEX_SMI (PT_LOPROC + 0)
#define PT_HEX_TCM (PT_LOPROC + 1)

/* Processor-specific program header flags.  */
/* Cacheability memory flags. */
#define PF_HEX_UC 0x80000000	/* Cacheable/uncacheable */
#define PF_HEX_WT 0x40000000	/* Write-back/write-through */
#define PF_HEX_U2 0x20000000	/* L2 cacheable/uncacheable */
#define PF_HEX_SH 0x10000000	/* Non-shared/shared */

/* Processor-specific dynamic array tags.  */
#define DT_HEX_SYMSZ (DT_LOPROC + 0)	/* Size, in bytes, of the .dynsym section, also DT_SYMTAB. */
#define DT_HEX_VER   (DT_LOPROC + 1)	/* Version of the dynamic sections. */

/* Various port-specific parameters. */
/* Default alignments. */
#define DEFAULT_CODE_ALIGNMENT 2	/* log2 (4) */
#define DEFAULT_CODE_FALIGN    4	/* log2 (16) */
#define DEFAULT_DATA_ALIGNMENT 3	/* log2 (8) */
#define HEXAGON_NOP     "nop"
/* Default GP size. */
#define HEXAGON_SMALL_GPSIZE 8

#endif /* _ELF_HEX_H */
