/* Opcode table for the Hexagon.
   Copyright 2004
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */

#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "sysdep.h"
#include "ansidecl.h"
#include "bfd.h"
#include "hexagon-isa.h"
#include "opcode/hexagon.h"
#include "safe-ctype.h"
#include "libiberty.h"

/* Hexagon instructions.

   Longer versions of insns must appear before shorter ones.

   Instructions that are really macros based on other insns must appear
   before the real insn so they're chosen when disassembling. */

/* Suck in definitions of mapping functions referenced in the opcodes.  */
#define HEXAGON_MAP_FNAME(TAG) hexagon_map_##TAG
#include "opcode/hexagon_asm_maps.h"

/* Suck in the mappings.  */

#define HEXAGON_OPCODE(syntax, enc, slots, implicit, attributes)
#define HEXAGON_MAPPING(syntax, enc, map) \
  { syntax, enc, 0, NULL, NULL, 0xf, 0, 0, map }, 

static hexagon_opcode hexagon_mappings_v2[] = {
#include "opcode/hexagon_iset_v2.h"
};

static hexagon_opcode hexagon_mappings_v3[] = {
#include "opcode/hexagon_iset_v3.h"
};

static hexagon_opcode hexagon_mappings_v4[] = {
#include "opcode/hexagon_iset_v4.h"
};

static hexagon_opcode hexagon_mappings_v5[] = {
#include "opcode/hexagon_iset_v5.h"
};

static hexagon_opcode hexagon_mappings_v55[] = {
#include "opcode/hexagon_iset_v55.h"
#include "opcode/hexagon_iset_v5.h"
};

#undef HEXAGON_OPCODE
#undef HEXAGON_MAPPING

static hexagon_opcode *hexagon_mappings[] =
  {
    hexagon_mappings_v2,
    hexagon_mappings_v3,
    hexagon_mappings_v4,
    hexagon_mappings_v5,
    hexagon_mappings_v55
  };

static size_t hexagon_mappings_count[] =
  {
    sizeof (hexagon_mappings_v2) / sizeof (hexagon_opcode),
    sizeof (hexagon_mappings_v3) / sizeof (hexagon_opcode),
    sizeof (hexagon_mappings_v4) / sizeof (hexagon_opcode),
    sizeof (hexagon_mappings_v5) / sizeof (hexagon_opcode),
    sizeof (hexagon_mappings_v55) / sizeof (hexagon_opcode)
  };


/* Support for register lookup.  */

/* Register descriptor, used for assembly and disassembly.  */
typedef struct hexagon_reg
{
  const char *name;
  int reg_num;
  int flags;

  /* Values for flags. */
#define HEXAGON_REG_IS_READONLY  (1 << 0)
#define HEXAGON_REG_IS_WRITEONLY (1 << 1)
#define HEXAGON_REG_IS_READWRITE (1 << 2)
#define HEXAGON_MACH_TO_BITMASK(mach) \
  (1 << (31 - ((mach) - bfd_mach_hexagon_v2)))
#define HEXAGON_IS_V2 HEXAGON_MACH_TO_BITMASK (bfd_mach_hexagon_v2)
#define HEXAGON_IS_V3 HEXAGON_MACH_TO_BITMASK (bfd_mach_hexagon_v3)
#define HEXAGON_IS_V4 HEXAGON_MACH_TO_BITMASK (bfd_mach_hexagon_v4)
#define HEXAGON_IS_V5 HEXAGON_MACH_TO_BITMASK (bfd_mach_hexagon_v5)
#define HEXAGON_IS_V55 HEXAGON_MACH_TO_BITMASK (bfd_mach_hexagon_v55)
#define HEXAGON_V2_AND_V3 (HEXAGON_IS_V3 | HEXAGON_IS_V2)
#define HEXAGON_V2_AND_UP (HEXAGON_IS_V55 | HEXAGON_IS_V5 | HEXAGON_IS_V4 \
			   | HEXAGON_IS_V3 | HEXAGON_IS_V2)
#define HEXAGON_V3_AND_UP (HEXAGON_IS_V55 | HEXAGON_IS_V5 | HEXAGON_IS_V4 \
			   | HEXAGON_IS_V3)
#define HEXAGON_V4_AND_UP (HEXAGON_IS_V55 | HEXAGON_IS_V5 | HEXAGON_IS_V4)
#define HEXAGON_RESERVED 0
} hexagon_reg;

/* Register names, by class.  Note that these arrays are searched
   sequentially during parsing, so longer names must appear before
   shorter ones.  */
static const hexagon_reg hexagon_gp_regs[] = {
  {"sp", 29, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"fp", 30, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"lr", 31, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
};
static const size_t hexagon_gp_regs_count =
  sizeof (hexagon_gp_regs) / sizeof (hexagon_gp_regs[0]);

static hexagon_reg hexagon_supervisor_regs[] = {
  /* Remapped V4 system registers.  */
  {"sgp0", 0, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"sgp1", 1, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"stid", 2, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"elr", 3, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"badva0", 4, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"badva1", 5, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"ssr", 6, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"ccr", 7, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"htid", 8, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"badva", 9, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"imask", 10, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"modectl", 17, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"ipend", 20, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"vid", 21, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"iad", 22, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"iel", 24, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"iahl", 26, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"cfgbase", 27, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"diag", 28, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"rev", 29, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"pcyclelo", 30, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"pcyclehi", 31, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"brkptpc0", 36, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"brkptcfg0", 37, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"brkptpc1", 38, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"brkptcfg1", 39, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"isdbmbxin", 40, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"isdbmbxout", 41, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"isdben", 42, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"isdbgpr", 43, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},

  {"s40", 40, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"s39", 39, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s29", 29, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"s28", 28, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s25", 25, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s22", 22, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"s19", 19, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s10", 10, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s9", 9, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"s8", 8, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"s7", 7, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s1", 1, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},

  /* Legacy system register map.  */
  {"sgp", 0, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"sgpr1", 1, HEXAGON_RESERVED},
  {"ssr", 2, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"imask", 3, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"badva", 4, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"elr", 5, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"tid", 6, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"evb", 16, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"ipend", 17, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READONLY},
  {"syscfg", 18, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"modectl", 19, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READONLY},
  {"rev", 20, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READONLY},
  {"tlbhi", 21, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"tlblo", 22, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"tlbidx", 23, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"diag", 24, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"iad", 25, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READONLY},
  {"iel", 26, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"iahl", 27, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"pcyclehi", 30, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"pcyclelo", 31, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"isdbst", 32, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READONLY},
  {"isdbcfg0", 33, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"isdbcfg1", 34, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"brkptpc0", 35, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"brkptcfg0", 36, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"brkptpc1", 37, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"brkptcfg1", 38, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"isdbmbxin", 39, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READONLY},
  {"isdbmbxout", 40, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"isdben", 41, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"isdbgpr", 42, HEXAGON_V2_AND_V3 | HEXAGON_REG_IS_READWRITE},
  {"pmucnt0", 48, HEXAGON_V3_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"pmucnt1", 49, HEXAGON_V3_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"pmucnt2", 50, HEXAGON_V3_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"pmucnt3", 51, HEXAGON_V3_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"pmucnt4", 44, HEXAGON_IS_V55 | HEXAGON_REG_IS_READWRITE},
  {"pmucnt5", 45, HEXAGON_IS_V55 | HEXAGON_REG_IS_READWRITE},
  {"pmucnt6", 46, HEXAGON_IS_V55 | HEXAGON_REG_IS_READWRITE},
  {"pmucnt7", 47, HEXAGON_IS_V55 | HEXAGON_REG_IS_READWRITE},
  {"pmuevtcfg", 52, HEXAGON_V3_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"pmuevtcfg1", 54, HEXAGON_IS_V55 | HEXAGON_REG_IS_READWRITE},
  {"pmucfg", 53, HEXAGON_V3_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"acc0", 61, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"acc1", 62, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"chicken", 63, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},

  {"s63", 63, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s62", 62, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s61", 61, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s60", 60, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s59", 59, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s58", 58, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s57", 57, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s56", 56, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},

  {"s55", 55, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s54", 54, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s53", 53, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s52", 52, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s51", 51, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s50", 50, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s49", 49, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s48", 48, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},

  {"s47", 47, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s46", 46, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s45", 45, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s44", 44, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s43", 43, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s42", 42, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s41", 41, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s40", 40, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},

  {"s39", 39, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READONLY},
  {"s38", 38, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s37", 37, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s36", 36, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"livelock", 35, HEXAGON_IS_V55 | HEXAGON_REG_IS_READWRITE},
  {"s35", 35, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s34", 34, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s33", 33, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s32", 32, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READONLY},

  {"s31", 31, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s30", 30, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s29", 29, HEXAGON_RESERVED},
  {"s28", 28, HEXAGON_RESERVED},
  {"s27", 27, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s26", 26, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s25", 25, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READONLY},
  {"s24", 24, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},

  {"s23", 23, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s22", 22, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s21", 21, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s20", 20, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READONLY},
  {"s19", 19, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READONLY},
  {"s18", 18, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s17", 17, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READONLY},
  {"s16", 16, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},

  {"s15", 15, HEXAGON_RESERVED},
  {"s14", 14, HEXAGON_RESERVED},
  {"s13", 13, HEXAGON_RESERVED},
  {"s12", 12, HEXAGON_RESERVED},
  {"s11", 11, HEXAGON_RESERVED},
  {"s10", 10, HEXAGON_RESERVED},
  {"s9", 9, HEXAGON_RESERVED},
  {"s8", 8, HEXAGON_RESERVED},

  {"s7", 7, HEXAGON_RESERVED},
  {"s6", 6, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s5", 5, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s4", 4, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s3", 3, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s2", 2, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"s1", 1, HEXAGON_RESERVED},
  {"s0", 0, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
};
static const size_t hexagon_supervisor_regs_count =
  sizeof (hexagon_supervisor_regs) / sizeof (hexagon_supervisor_regs[0]);

static const hexagon_reg hexagon_control_regs[] = {
  {"sa0", 0, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"lc0", 1, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"sa1", 2, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"lc1", 3, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"p3:0", 4, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"p3:2", 5, HEXAGON_RESERVED},
  {"m0", 6, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"m1", 7, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"usr", 8, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"pc", 9, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READONLY},
  {"ugp", 10, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"gp", 11, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"cs0", 12, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"cs1", 13, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"upcyclelo", 24, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"upcyclehi", 25, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"upmucnt0", 26, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"upmucnt1", 27, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"upmucnt2", 28, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"upmucnt3", 29, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},

  {"c29", 29, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"c28", 28, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"c27", 27, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"c26", 26, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"c25", 25, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"c24", 24, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},

  {"c13", 13, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"c12", 12, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"c11", 11, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"c10", 10, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"c9", 9, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READONLY},

  {"c8", 8, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"c7", 7, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"c6", 6, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},

  {"c4", 4, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"c3", 3, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"c2", 2, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"c1", 1, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"c0", 0, HEXAGON_V2_AND_UP | HEXAGON_REG_IS_READWRITE},
};
static const size_t hexagon_control_regs_count =
  sizeof (hexagon_control_regs) / sizeof (hexagon_control_regs[0]);

static const hexagon_reg hexagon_guest_regs[] = {
  {"gpcyclelo", 24, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"gpcyclehi", 25, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"gpmucnt0", 26, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"gpmucnt1", 27, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"gpmucnt2", 28, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"gpmucnt3", 29, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"gpmucnt4", 16, HEXAGON_IS_V55 | HEXAGON_REG_IS_READONLY},
  {"gpmucnt5", 17, HEXAGON_IS_V55 | HEXAGON_REG_IS_READONLY},
  {"gpmucnt6", 18, HEXAGON_IS_V55 | HEXAGON_REG_IS_READONLY},
  {"gpmucnt7", 19, HEXAGON_IS_V55 | HEXAGON_REG_IS_READONLY},

  {"g29", 29, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"g28", 28, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"g27", 27, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"g26", 26, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"g25", 25, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},
  {"g24", 24, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READONLY},

  {"g19", 19, HEXAGON_IS_V55 | HEXAGON_REG_IS_READONLY},
  {"g18", 18, HEXAGON_IS_V55 | HEXAGON_REG_IS_READONLY},
  {"g17", 17, HEXAGON_IS_V4 | HEXAGON_IS_V55 | HEXAGON_REG_IS_READONLY},
  {"g16", 16, HEXAGON_IS_V4 | HEXAGON_IS_V55 | HEXAGON_REG_IS_READONLY},

  {"g3", 3, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"g2", 2, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"g1", 1, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
  {"g0", 0, HEXAGON_V4_AND_UP | HEXAGON_REG_IS_READWRITE},
};
static const size_t hexagon_guest_regs_count =
  sizeof (hexagon_guest_regs) / sizeof (hexagon_guest_regs[0]);

/* Parse syntax such as "Rnn", a prefix character followed by the register
   number.  On success modifies *input to point past the parsed substring,
   and returns the register number.  Returns -1 on error (and doesn't touch
   *input).  */
static int
hexagon_reg_num (char **input, char prefix)
{
  unsigned long regn;
  char *first = *input;
  char *next;

  if (TOLOWER (first[0]) == TOLOWER (prefix) && ISDIGIT (first[1]))
    {
      /* Skip the letter */
      first++;

      regn = strtoul (first, &next, 10);
      if (regn != ULONG_MAX && first != next && !ISALPHA (*next))
	{
	  *input = next;
	  return (int) regn;
	}
    }
  return -1;
}

/* Match the input against the possible register names.  In addition to
   matching the input exactly, if the prefix char is nonzero, also match
   ":nn" pair syntax where the ':' maps onto the given prefix char.
   On success, update *input, store the index of the matching reg in *ix,
   and return the register number.  On failure, return -1.  */
static int
hexagon_reg_match (char **input, char prefix, const hexagon_reg *regs,
		   size_t count, size_t *ix)
{
  size_t i;
  char *first = *input;
  int current_mach_bitmask = HEXAGON_MACH_TO_BITMASK (hexagon_arch ());

  /* Determine the right prefix handling.  */
  if (*first != ':')
    prefix = '\0';		/* Prefix only used with pair syntax.  */
  else
    {
      first++;			/* Skip the pair separator.  */
      if (!ISDIGIT (*first))    /* Prefix won't match this input.  */
	prefix = '\0';	
    }

  for (i = 0; i < count; i++)
    {
      size_t len;
      char *next = NULL;
      
      if (!(regs[i].flags & current_mach_bitmask))
	continue;

      len = strlen (regs[i].name);

      if (prefix)
	{
	  if (TOLOWER (regs[i].name[0]) == prefix
	      && !strncasecmp (first, regs[i].name + 1, len - 1))
	    next = first + len - 1;
	}
      else if (!strncasecmp (first, regs[i].name, len))
	next = first + len;
      
      /* Don't return a match that is just a prefix of some longer token
	 in the input stream.  */
      if (next && !ISALNUM (*next))
	{
	  *input = next;
	  if (ix)
	    *ix = i;
	  return regs[i].reg_num;
	}
    }
  return -1;
}

/* Parse a general-purpose register string, including both the Rnn and
 * alias forms.  */
static int
hexagon_gp_reg_num (char **input, int pair)
{
  int result = hexagon_reg_num (input, pair ? ':' : 'r');
  if (result >= 0)
    return result;
  return hexagon_reg_match (input, '\0', hexagon_gp_regs, hexagon_gp_regs_count,
			    NULL);
}

/* Perform sanity-checking on a purported register pair.  Returns TRUE
   if things are ok, otherwise sets errmsg (if it's non-NULL) and returns
   FALSE.  */
static int
hexagon_check_regpair (int reg_odd, int reg_even, char **errmsg)
{
  if (reg_odd < 0 || reg_even < 0)
    return FALSE;

  /* Make sure the odd register number is odd.  */
  if (reg_odd % 2 != 1)
    {
      if (errmsg)
	{
	  static char buf[100];
	  sprintf (buf, "invalid odd register number: %d", reg_odd);
	  *errmsg = buf;
	}
      return FALSE;
    }

  /* Make sure the even register number is even. */
  if (reg_even % 2 != 0)
    {
      if (errmsg)
	{
	  static char buf[100];
	  sprintf (buf, "invalid even register number: %d", reg_even);
	  *errmsg = buf;
	}
      return FALSE;
    }

  /* Make sure the registers are consecutive.  */
  if (reg_odd != reg_even + 1)
    {
      if (errmsg)
	{
	  static char buf[100];
	  sprintf (buf, "registers must be consecutive: %d:%d",
		   reg_odd, reg_even);
	  *errmsg = buf;
	}
      return FALSE;
    }
  return TRUE;
}

/* Check whether the operand is trying to write to a read-only register.
   If reg0 and reg1 are both supplied, they specify a register pair.
   reg1 can be omitted for a single register check.  If an invalid
   operation is detected, errmsg is set (if it is non-NULL) and
   the HEXAGON_OPERAND_IS_INVALID bit in flag (if it is non-null).  */
static void
hexagon_check_reg_readonly (const hexagon_reg *reg0,
			    const hexagon_reg *reg1,
			    const hexagon_operand *operand,
			    int *flag,
			    char **errmsg)
{
  static char buf[150];
  if (operand->flags & HEXAGON_OPERAND_IS_WRITE
      && (reg0->flags & HEXAGON_REG_IS_READONLY
	  || (reg1 && reg1->flags & HEXAGON_REG_IS_READONLY)))
    {
      if (errmsg)
	{
	  sprintf (buf, "cannot write to read-only register `%s%s%s'.",
		   reg0->name,
		   (reg1 ? ":" : ""),
		   (reg1 ? reg1->name : ""));
	  *errmsg = buf;
	}
      if (flag)
	*flag |= HEXAGON_OPERAND_IS_INVALID;
    }
}

/* Parse various flavors of register operands.  */
char *
hexagon_parse_register (const hexagon_operand *operand, hexagon_insn *insn,
			const hexagon_opcode *opcode, char *input, long *val,
			int *flag, char **errmsg)
{
  int reg, reg0, reg1;

  if (flag)
    *flag = 0;

  if (operand->flags & HEXAGON_OPERAND_IS_REGISTER)
    {
      if (operand->flags & HEXAGON_OPERAND_IS_PAIR)
	{
	  reg1 = hexagon_gp_reg_num (&input, FALSE);
	  reg0 = hexagon_gp_reg_num (&input, TRUE);
	  if (!hexagon_check_regpair (reg1, reg0, errmsg))
	    return NULL;
	}
      else
	{
	  reg0 = hexagon_gp_reg_num (&input, FALSE);
	  if (reg0 < 0
	      || (operand->fmt[0] == 'S' && operand->fmt[1] == 'p'
		  && reg0 != 29)
	      || (operand->fmt[0] == 'L' && operand->fmt[1] == 'r'
		  && reg0 != 31))
	    return NULL;
	}
    }
  else if (operand->flags & HEXAGON_OPERAND_IS_SUBSET)
    {
      int n = 0;
      const char *fmt;
      for (fmt = operand->fmt; !n && *fmt; fmt++)
	if (*fmt == '8')
	  n = 8;
        else if (*fmt == '1' && *(fmt + 1) == '6')
	  n = 16;
      if (!n)
	abort ();

      if (operand->flags & HEXAGON_OPERAND_IS_PAIR)
	{
	  reg1 = hexagon_gp_reg_num (&input, FALSE);
	  reg0 = hexagon_gp_reg_num (&input, TRUE);
	  if (!hexagon_check_regpair (reg1, reg0, errmsg))
	    return NULL;
	  if (n == 8
	      && (((reg1 < 1 || reg1 > 7) && (reg1 < 17 || reg1 > 23))
		  || (reg0 > 6 && (reg0 < 16 || reg0 > 22))))
	    return NULL;
	  if (n == 16 && (reg1 < 1 || reg1 > 31 || reg0 < 0 || reg0 > 30))
	    return NULL;
	}
      else
	{
	  reg0 = hexagon_gp_reg_num (&input, FALSE);
	  if (reg0 < 0)
	    return NULL;
	  if (n == 8 && reg0 > 3 && (reg0 < 16 || reg0 > 19))
	    return NULL;
	  if (n == 16 && reg0 > 7 && (reg0 < 16 || reg0 > 23))
	    return NULL;
	}
    }
  else if (operand->flags & HEXAGON_OPERAND_IS_NEW)
    {
      reg0 = hexagon_gp_reg_num (&input, FALSE);
      if (reg0 < 0 || reg0 > 31)
	return NULL;
      if (flag)
	*flag |= HEXAGON_OPERAND_IS_RNEW;
    }
  else if (operand->flags & HEXAGON_OPERAND_IS_PREDICATE)
    {
      reg0 = hexagon_reg_num (&input, 'p');
      if (reg0 < 0)
	return NULL;
      if (flag)
	*flag |= HEXAGON_OPERAND_IS_PREDICATE;
    }
  else if (operand->flags & HEXAGON_OPERAND_IS_MODIFIER)
    {
      reg0 = hexagon_reg_num (&input, 'm');
      if (reg0 < 0)
	return NULL;
    }
  else
    {
      const hexagon_reg *regs;
      size_t count;
      char prefix;
      if (operand->flags & HEXAGON_OPERAND_IS_CONTROL)
	{
	  regs = hexagon_control_regs;
	  count = hexagon_control_regs_count;
	  prefix = 'c';
	}
      else if (operand->flags & HEXAGON_OPERAND_IS_GUEST)
	{
	  regs = hexagon_guest_regs;
	  count = hexagon_guest_regs_count;
	  prefix = 'g';
	}
      else if (operand->flags & HEXAGON_OPERAND_IS_SYSTEM)
	{
	  regs = hexagon_supervisor_regs;
	  count = hexagon_supervisor_regs_count;
	  prefix = 's';
	}
      else
	abort ();

      if (operand->flags & HEXAGON_OPERAND_IS_PAIR)
	{
	  size_t rege, rego;

	  reg1 = hexagon_reg_match (&input, '\0', regs, count, &rego);
	  reg0 = hexagon_reg_match (&input, prefix, regs, count, &rege);
	  if (!hexagon_check_regpair (reg1, reg0, errmsg))
	    return NULL;
	  hexagon_check_reg_readonly (&regs[rego], &regs[rege],
				      operand, flag, errmsg);
	}
      else
	{
	  size_t regn;
	  reg0 = hexagon_reg_match (&input, '\0', regs, count, &regn);
	  if (reg0 < 0)
	    return NULL;
	  hexagon_check_reg_readonly (&regs[regn], NULL, operand, flag, errmsg);
	}
    }

  if (operand->flags & HEXAGON_OPERAND_IS_NEW)
    reg = reg0 % 2;
  else
    reg = reg0;
  if (hexagon_encode_operand (operand, insn, opcode, reg, FALSE, errmsg))
    {
      *val = reg0;
      return input;
    }

  return NULL;
}


/* Additional assembler/disassembler helper functions.  */

/* Initialization for assembler/disassembler, with additional instructions
   mapped to "real" instructions.  */
void
hexagon_opc_init (int mach)
{
  hexagon_isa_init (mach, hexagon_mappings, hexagon_mappings_count);
}

/* Find the operand descriptor matching SYNTAX, up to its next separator
   character.  */
const hexagon_operand *
hexagon_lookup_operand (const char *syntax)
{
  return hexagon_lookup_operand_name (syntax, strcspn (syntax, " .,"));
}

/* Extract bits for OPERAND from INSN, returning result in RETURN_VALUE.
   ADDR is added to the result if the operand is PC-relative.  ENC is the
   encoding string for this instruction.  Returns true on success; on
   failure, sets *errmsg and returns false.  */
int
hexagon_extract_operand (const hexagon_operand *operand, hexagon_insn insn,
			 bfd_vma addr, const char *enc, int *return_value,
			 char **errmsg)
{
  int value = 0;
  char enc_letter = operand->enc_letter;
  const char *enc_ptr = enc;
  unsigned int bits_found;
  hexagon_insn mask;

  /* Grab the bits from the instruction.  */
  mask = 1 << 31;
  bits_found = 0;
  while (*enc_ptr)
    {
      char ch = *enc_ptr++;

      if (!ISSPACE (ch))
	{
	  if (ch == enc_letter)
	    {
	      value = (value << 1) + ((insn & mask) ? 1 : 0);
	      bits_found++;
	    }
	  mask >>= 1;
	}
    }

  /* Check that we got the right number of bits.  */
  if (bits_found != operand->bits)
    {
      if (errmsg)
	{
	  static char xx[100];

	  sprintf (xx,
		   "operand %c wrong number of bits found in %s, %d != %d",
		   operand->enc_letter, enc, bits_found, operand->bits);
	  *errmsg = xx;
	}
      return FALSE;
    }

  if (operand->flags & HEXAGON_OPERAND_IS_SIGNED)
    {
      /* Might need to sign extend.  */
      if (value & (1 << (bits_found - 1)))
	{
	  value <<= 32 - bits_found;
	  value >>= 32 - bits_found;
	}
    }

  value <<= operand->shift_count;

  if (operand->flags & HEXAGON_OPERAND_PC_RELATIVE)
    value += addr;

  if (operand->flags & HEXAGON_OPERAND_IS_SUBSET)
    value = HEXAGON_SUBREGS_FROM (value,
				  operand->flags & HEXAGON_OPERAND_IS_PAIR);

  *return_value = value;
  return TRUE;
}

/* Disassemble the name of the register numbered VALUE into BUF.  REGS is
   the register class array to look up in, and COUNT is the number of
   elements in the array.  On success, returns a pointer to the next char
   in BUF; on failure, sets *ERRMSG and returns null.  */
static char *
hexagon_dis_named_reg (int value, int count, const hexagon_reg *regs,
		       char *buf, char **errmsg)
{
  int n = 0;
  int found = 0;
  int i;
  int current_mach_bitmask = HEXAGON_MACH_TO_BITMASK (hexagon_arch ());

  for (i = 0; i < count; i++)
    {
      if (regs[i].flags & current_mach_bitmask && value == regs[i].reg_num)
	{
	  found = 1;
	  n = sprintf (buf, "%s", regs[i].name);
	  break;
	}
    }

  if (!found)
    {
      if (errmsg)
	{
	  static char xx[100];
	  sprintf (xx, "control register not found: %d", value);
	  *errmsg = xx;
	}
      return NULL;
    }

  return buf + n;
}

/* Disassemble OPERAND from INSN into BUF.  IADDR is the offset of the
   instruction while PADDR is the offset of the containing packet.  ENC
   is the encoding string for INSN.  On success, returns the next char
   in BUF past the disassembled operand; on failure, sets *ERRMSG and
   returns NULL.  */
char *
hexagon_dis_operand (const hexagon_operand *operand, hexagon_insn insn,
		     bfd_vma iaddr, bfd_vma paddr, const char *enc, char *buf,
		     char **errmsg)
{
  static bfd_vma previous;
  static int xer, xreg, xvalue;
  int xed, value;
  static struct
  {
    int n, y;
  } reg[MAX_PACKET_INSNS];
  size_t ireg;
  int n;

  if ( operand == NULL)
    {
      /* Reset our internal state.  */
      previous = 0;
      xer = xreg = xvalue = 0;
      return NULL;
    }

  if (!hexagon_extract_operand (operand, insn, paddr, enc, &value, errmsg))
    return NULL;

  /* Handle extenders.  */
  xed = FALSE;
  if (operand->flags & HEXAGON_OPERAND_IS_KXER)
    {
      xreg++;
      xer = TRUE;
      xvalue = value;
    }
  else if (xer && operand->flags & HEXAGON_OPERAND_IS_KXED)
    {
      if (operand->flags & HEXAGON_OPERAND_PC_RELATIVE)
	{
	  xed = FALSE;
	  value -= paddr;
	  value >>= operand->shift_count;
	  value = HEXAGON_KXED_MASK (value);
	  value += xvalue + paddr;
	}
      else
	{
	  xed = TRUE;
	  value >>= operand->shift_count;
	  value = HEXAGON_KXED_MASK (value);
	  value += xvalue;
	}
      xer = xvalue = 0;
    }

  /* Handle R.NEW.  */
  if (previous != paddr)
    {
      previous = paddr;
      xreg = 0;
      memset (reg, 0, sizeof (reg));
    }

  ireg = (((iaddr - paddr) % (MAX_PACKET_INSNS * HEXAGON_INSN_LEN))
	  / MAX_PACKET_INSNS);
  ireg -= xreg;
  if (operand->flags & HEXAGON_OPERAND_IS_WRITE
      && (operand->flags & HEXAGON_OPERAND_IS_REGISTER
	  || operand->flags & HEXAGON_OPERAND_IS_PAIR
	  || operand->flags & HEXAGON_OPERAND_IS_SUBSET))
    {
      if (!reg[ireg].y)
	{
	  reg[ireg].n = value;
	  reg[ireg].y = TRUE;
	}
    }
  else if (operand->flags & HEXAGON_OPERAND_IS_READ
	   && operand->flags & HEXAGON_OPERAND_IS_NEW)
    {
      value = (reg[ireg - (value / 2)].n
	       + ((reg[ireg - (value / 2)].n % 2) ^ (value % 2)));
    }

  if (operand->flags & HEXAGON_OPERAND_IS_PAIR)
    n = sprintf (buf, operand->dis_fmt, value + 1, value);
  else if (operand->flags & HEXAGON_OPERAND_IS_CONTROL)
    return hexagon_dis_named_reg (value,
				  hexagon_control_regs_count,
				  hexagon_control_regs, buf, errmsg);
  else if (operand->flags & HEXAGON_OPERAND_IS_GUEST)
    return hexagon_dis_named_reg (value,
				  hexagon_guest_regs_count,
				  hexagon_guest_regs, buf, errmsg);
  else if (operand->flags & HEXAGON_OPERAND_IS_SYSTEM)
    return hexagon_dis_named_reg (value,
				  hexagon_supervisor_regs_count,
				  hexagon_supervisor_regs, buf, errmsg);
  else if (operand->flags & HEXAGON_OPERAND_IS_GPREL_OR_ABS)
    {
      if (xed)
	n = sprintf (buf, "##@%u", value);
      else
	n = sprintf (buf, "gp + #%u", value);
    }
  else
    {
      n = 0;
      if (xed)
	buf[n++] = '#';
      n += sprintf (buf + n, operand->dis_fmt, value);
    }

  if (n > 0)
    return buf + n;
  else
    {
      if (errmsg)
	{
	  static char xx[100];
	  sprintf (xx, "bad return code from sprintf: %d", n);
	  *errmsg = xx;
	}
      return NULL;
    }
}

/* Disassemble the instruction INSN, which corresponds to OPCODE, into
   BUF.  ADDRESS is the offset of the instruction.  On success, returns true;
   otherwise sets *ERRMSG and returns false.  */
int
hexagon_dis_opcode (char *buf, hexagon_insn insn, bfd_vma address,
		    const hexagon_opcode *opcode, char **errmsg)
{
  static char temp[40];
  static int in_packet;
  static int end_inner;
  static int end_outer;
  static bfd_vma packet_addr;
  int rc = FALSE;
  hexagon_insn packet_bits;
  int end_packet = FALSE;
  const char *syn;
  char *dst;

  if (opcode == NULL)
    {
      /* Reset our internal state.  */
      in_packet = end_inner = end_outer = 0;
      packet_addr = 0;
      dst = hexagon_dis_operand (NULL, 0, 0, 0, NULL, NULL, NULL);
      goto done;
    }

  packet_bits = HEXAGON_END_PACKET_GET (insn);
  syn = opcode->syntax;
  dst = buf;

  switch (packet_bits)
    {
    case HEXAGON_END_PACKET:
    case HEXAGON_END_PAIR:
      if (in_packet)
	dst += sprintf (dst, "  ");
      else
        {
	  dst += sprintf (dst, "%c ", PACKET_BEGIN);
	  ++in_packet;
	  packet_addr = address;
	}
      end_packet = TRUE;
      break;

    case HEXAGON_END_LOOP:
    case HEXAGON_END_NOT:
      if (!in_packet)
	{
	  dst += sprintf (dst, "%c ", PACKET_BEGIN);
	  packet_addr = address;
	}
      else
	dst += sprintf (dst, "  ");

      ++in_packet;

      if (packet_bits == HEXAGON_END_LOOP)
	{
	  if (in_packet == 1)
	    end_inner = TRUE;
	  if (in_packet == 2)
	    end_outer = TRUE;
	}
      break;

    default:
      if (errmsg)
	{
	  snprintf (temp, sizeof (temp), "invalid packet bits: %.8x",
		    packet_bits);
	  *errmsg = temp;
	}
      goto done;
    }

  /* Compare this loop to hexagon_assemble in tc-hexagon.c, which also
     walks the opcode syntax string.  */
  while (*syn)
    {
      if ((ISUPPER (*syn) && TOUPPER (*syn) != 'I') || *syn == '#')
	{
	  /* We have an operand.  */
	  const hexagon_operand *operandp = hexagon_lookup_operand (syn);
	  if (operandp)
	    {
	      hexagon_operand operand = *operandp;
	      if (HEXAGON_OPCODE_IS_EXTENDER (opcode))
		operand.flags |= HEXAGON_OPERAND_IS_KXER;
	      else if (operand.flags & HEXAGON_OPERAND_IS_IMMEDIATE
		       && HEXAGON_OPERAND_IS_EXTENDABLE (&operand, opcode))
		/* Not necessarily extended, but maybe so. */
		operand.flags |= HEXAGON_OPERAND_IS_KXED;
	      
	      dst = hexagon_dis_operand (&operand, insn, address,
					 packet_addr, opcode->enc,
					 dst, errmsg);
	      if (!dst)
		{
		  /* Some kind of error!  */
		  sprintf (buf, "<unknown insn 0x%08x>", insn);
		  goto done;
		}
	      
	      /* Move past the opcode specifier.  */
	      syn += strlen (operand.fmt);
	    }

	  else
	    {
	      sprintf (buf, "<unknown insn 0x%08x>", insn);
	      if (errmsg)
		{
		  snprintf (temp, sizeof (temp), "unknown operand: %s", syn);
		  *errmsg = temp;
		}
	      goto done;
	    }
	}
      else
	{
	  /* Beautify disassembly.  */
	  switch (*syn)
	    {
	      /* Skip space after.  */
	    case '(':
	    case '!':
	      *dst++ = *syn++;

	      while (ISBLANK (syn[0]))
		syn++;
	      break;

	      /* Delete space before.  */
	    case ')':
	    case '.':
	    case ',':
	    case ':':
	      while (ISBLANK (dst[-1]))
		dst--;

	      *dst++ = *syn++;
	      break;

	      /* Nothing, just copy.  */
	    default:
	      *dst++ = *syn++;
	      break;
	    }
	}
    }

  *dst = '\0';

  rc = TRUE;
done:
  if (in_packet && end_packet && dst)
    {
      dst += sprintf (dst, " %c", PACKET_END);

      if (end_inner)
	dst += sprintf (dst, PACKET_END_INNER);
      if (end_outer)
	dst += sprintf (dst, PACKET_END_OUTER);
    }

  if (end_packet || rc == FALSE)
    {
      in_packet = FALSE;
      end_inner = FALSE;
      end_outer = FALSE;
    }

  return rc;
}

