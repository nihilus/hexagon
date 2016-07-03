/* Opcode table for the Hexagon.
   Copyright 2004 Free Software Foundation, Inc.

   This file is part of GAS, the GNU Assembler, GDB, the GNU debugger, and
   the GNU Binutils.

   GAS/GDB is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   GAS/GDB is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GAS or GDB; see the file COPYING.	If not, write to
   the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */

#ifndef OPCODES_HEXAGON_H
#define OPCODES_HEXAGON_H 1

#include "hexagon-isa.h"

/* To support instruction mappings, we store both the parsed and unparsed
   forms of operands in a data structure where they can be accessed by the
   mapping functions.  */
#define HEXAGON_MAPPED_LEN 256
typedef struct hexagon_operand_arg
{
  const hexagon_operand *operand;
  long value;
  char string[HEXAGON_MAPPED_LEN];
} hexagon_operand_arg;

/* Packet delimiters.  */
#define PACKET_BEGIN     '{'	     /* Beginning of packet.  */
#define PACKET_END       '}'	     /* End of packet.  */
#define PACKET_END_INNER ":endloop0" /* End of inner loop.  */
#define PACKET_END_OUTER ":endloop1" /* End of outer loop.  */
#define PACKET_PAIR      ';'	     /* Sub-insn separator.  */

extern void hexagon_opc_init (int);
extern const hexagon_operand *hexagon_lookup_operand (const char *);
extern int hexagon_extract_operand
  (const hexagon_operand *, hexagon_insn, bfd_vma, const char *,
   int *, char **);
extern char *hexagon_dis_operand
  (const hexagon_operand *, hexagon_insn, bfd_vma, bfd_vma, const char *,
   char *, char **);
extern int hexagon_dis_opcode
  (char *, hexagon_insn, bfd_vma, const hexagon_opcode *, char **);
extern const hexagon_operand *hexagon_operand_find
  (const hexagon_operand *, const char *);

extern char *hexagon_parse_register
  (const hexagon_operand *, hexagon_insn *, const hexagon_opcode *,
   char *, long *, int *, char **);

#endif /* OPCODES_HEXAGON_H */
