/* Instruction printing code for the Hexagon.
   Copyright 1994, 1995, 1997, 1998, 2000, 2001, 2002
   Free Software Foundation, Inc.

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

#include "ansidecl.h"
#include "libiberty.h"
#include "dis-asm.h"
#include "hexagon-isa.h"
#include "opcode/hexagon.h"
#include "elf-bfd.h"
#include "elf/hexagon.h"
#include <string.h>
#include "opintl.h"

#include <stdarg.h>
#include "safe-ctype.h"


/* Disassemble INSN, which lives at ADDRESS, into BUFFER, using
   disassembler configuration INFO.  */
static void
hexagon_dis_inst (bfd_vma address, hexagon_insn insn, char *buffer,
		  disassemble_info *info)
{
  const hexagon_opcode *opcode;
  char *errmsg = NULL;

  opcode = hexagon_lookup_insn (insn);
  if (!hexagon_dis_opcode(buffer, insn, address, opcode, &errmsg))
    {
      if (!opcode)
	{
	  // Instruction not found
	  strcpy(buffer, "<unknown>");
	}
      else if (errmsg)
	{
	  /* Some kind of error! */
	  (*info->fprintf_func) (info->stream, errmsg);
	  strcpy(buffer, "");
	}
    }
}

/* Decode the instruction at ADDRESS, returning the size of the instruction
   in bytes.  */
static int
hexagon_decode_inst (bfd_vma address, disassemble_info *info)
{
  int status;
  hexagon_insn insn;
  bfd_byte insnbuf[HEXAGON_INSN_LEN];
  void *stream;			/* output stream  */
  fprintf_ftype func;
  char buffer[HEXAGON_MAPPED_LEN];
  int bytes;
  char *str;

  if (info == NULL) {
      /* Reset any disasm state & we're done.  */
      hexagon_dis_opcode(NULL, 0, 0, NULL, NULL);
      bytes = 0;
      goto done;
  }

  stream = info->stream;
  func = info->fprintf_func;

  status = (*info->read_memory_func) (address, insnbuf, HEXAGON_INSN_LEN, info);
  if (status != 0)
    {
      (*info->memory_error_func) (status, address, info);
      return -1;
    }
  insn = bfd_getl32 (insnbuf);

  /* Disassemble.   */
  hexagon_dis_inst (address, insn, buffer, info);

  /* Display the disassembly instruction.  */
  (*func) (stream, "%08x     ", insn);

  /* Print the instruction buffer.
     Watch out for placeholders where we want
     to print out the symbolic name for an address.  */
  str = buffer;
  while (*str)
    {
      char ch = *str++;
      if (ch == '@')
	{
	  bfd_vma addr = 0;
	  while (ISDIGIT (*str))
	    {
	      ch = *str++;
	      addr = 10 * addr + ch - '0';
	    }
	  (*info->print_address_func) (addr, info);
	}
      else
	(*func) (stream, "%c", ch);
    }

  bytes = HEXAGON_INSN_LEN;
done:
  return bytes;
}

/* Return the print_insn function to use for ABFD.  */
disassembler_ftype
hexagon_get_disassembler (bfd *abfd)
{
  unsigned long machine = bfd_get_mach (abfd);
  hexagon_opc_init (machine);
  return hexagon_decode_inst;
}
