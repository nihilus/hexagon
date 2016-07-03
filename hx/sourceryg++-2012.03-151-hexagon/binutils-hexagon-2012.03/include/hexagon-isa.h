/* Interface definition for Hexagon ISA support.
   Copyright 2012 Free Software Foundation, Inc.

   This file is part of BFD, the Binary File Descriptor library.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, 
   USA.  */

#ifndef HEXAGON_ISA_H
#define HEXAGON_ISA_H

/* This is the instruction size in bytes.  */
#define HEXAGON_INSN_LEN 4

/* Maximum number of insns in a packet.  */
#define MAX_PACKET_INSNS 4

/* Extract the low 16 bits.  */
#define HEXAGON_LO16(num) ((num) & ~(-1 << 16))

/* Extract the high 16 bits.  */
#define HEXAGON_HI16(num) HEXAGON_LO16 ((num) >> 16)

/* Extract the extender bits.  */
#define HEXAGON_KXER_MASK(num) ((num) & (~0L << 6))

/* Extract the extended bits.  */
#define HEXAGON_KXED_MASK(num) ((num) & ~(~0L << 6))

/* Specify the register sub-ranges.  */
#define HEXAGON_SUBREGS    16
#define HEXAGON_SUBREGS_LO  0
#define HEXAGON_SUBREGS_HI 16
#define HEXAGON_SUBREGS_TO(r, p)			      \
  (((r) < HEXAGON_SUBREGS_HI				      \
    ? (r)						      \
    : (r) - HEXAGON_SUBREGS / 2)			      \
   / ((p) ? 2 : 1))
#define HEXAGON_SUBREGS_FROM(r, p)					\
  ((r) * ((p) ? 2 : 1) < HEXAGON_SUBREGS / 2				\
   ? (r) * ((p) ? 2 : 1)						\
   : (r) * ((p) ? 2 : 1) - HEXAGON_SUBREGS / 2 + HEXAGON_SUBREGS_HI)


/* Type to denote an Hexagon instruction (at least a 32 bit unsigned int).  */
typedef unsigned int hexagon_insn;

/* Function type to implement instruction syntax mappings.  */
struct hexagon_operand_arg;
typedef void (*hexagon_mapping) (char *, size_t,
				 const struct hexagon_operand_arg *);

/* Opcode descriptors.  */
typedef struct _hexagon_opcode
{
  const char *syntax;		/* Syntax of insn.  */
  const char *enc;		/* String representing the encoding.  */

  /* Fixed part of encoding string translated to bitmap.  */
  hexagon_insn insn;

  /* These values are used for instruction lookup during assembly and
     disassembly.  Each opcode is on a linked list of related opcodes
     (same first letter for assembly, same insn code for disassembly).  */
  const struct _hexagon_opcode *next_asm;
  const struct _hexagon_opcode *next_dis;

  /* Macros to access `next_asm', `next_dis' so users needn't care about the
     underlying mechanism.  */
#define HEXAGON_CODE_NEXT_ASM(op) ((op) ? (op)->next_asm : (op))
#define HEXAGON_CODE_NEXT_DIS(op) ((op) ? (op)->next_dis : (op))

  /* Slots in which the instruction can go.  */
  unsigned int slots;
#define HEXAGON_SLOTS_DUPLEX 0x3  /* Paired isns.  */
#define HEXAGON_SLOTS_STORES 0x2  /* In-order dual-stores.  */
#define HEXAGON_SLOTS_1      0x2  /* Slot #1.  */
#define HEXAGON_SLOTS_MEM1   0x1  /* Preference for single memory access.  */

  /* Implicit register writes by this insn.  */
  unsigned int implicit;

  /* Values for implicit register mask.  */
#define IMPLICIT_LR     0x0001
#define IMPLICIT_SP     0x0002
#define IMPLICIT_FP     0x0004
#define IMPLICIT_PC     0x0008
#define IMPLICIT_LC0    0x0010
#define IMPLICIT_SA0    0x0020
#define IMPLICIT_LC1    0x0040
#define IMPLICIT_SA1    0x0080
#define IMPLICIT_SR_OVF 0x0100
#define IMPLICIT_P3     0x0200
#define IMPLICIT_P0     0x0400
#define IMPLICIT_P1     0x0800

  /* Interesting properties of this insn.  */
  unsigned int attributes;  

  /* Values for 'attributes'.  See macros below for documentation.  */
#define A_BRANCH			0x00000001
#define A_COMPOUND			0x00000002
#define A_CONDEXEC			0x00000004
#define A_CONDITION_DOTNEW		0x00000008
#define A_CONDITION_INVERTED		0x00000010
#define A_DUALJUMP_1			0x00000020
#define A_DUALJUMP_2			0x00000040
#define A_EXTENDABLE_LOWERCASE		0x00000080
#define A_EXTENDABLE_UPPERCASE		0x00000100
#define A_EXTENDER			0x00000200
#define A_HWLOOP			0x00000400
#define A_LATEPRED			0x00000800
#define A_MEMORY			0x00001000
#define A_MUST_EXTEND			0x00002000
#define A_NOP				0x00004000
#define A_PCREL_BRANCH			0x00008000
#define A_RESTRICT_AX			0x00010000
#define A_RESTRICT_AX_SOMEREGS		0x00020000
#define A_RESTRICT_SLOT1_AONLY		0x00040000
#define A_RESTRICT_SLOT1_EMPTY		0x00080000
#define A_RESTRICT_SLOT1_NOSTORE	0x00100000
#define A_SOLO				0x00200000
#define A_STORE				0x00400000
#define A_XFLOAT			0x00800000
#define A_DEALLOCRET			0x01000000

  /* If this opcode is mapped, then the function that performs the mapping.  */
  hexagon_mapping map;
} hexagon_opcode;

/* Predicate macros for opcodes.  */

/* The instruction is a direct or indirect branch, excluding loops.  */
#define HEXAGON_OPCODE_IS_BRANCH(x) \
  ((x)->attributes & A_BRANCH)

/* Instruction is compound.  */
#define HEXAGON_OPCODE_IS_COMPOUND(x)		\
  ((x)->attributes & A_COMPOUND)

/* Instruction is a conditional.  */
#define HEXAGON_OPCODE_IS_CONDEXEC(x) \
  ((x)->attributes & A_CONDEXEC)

/* Instruction uses a .new predicate conditional.  */
#define HEXAGON_OPCODE_IS_CONDITION_DOTNEW(x) \
  ((x)->attributes & A_CONDITION_DOTNEW)

/* Instruction uses an inverted conditional.  */
#define HEXAGON_OPCODE_IS_CONDITION_INVERTED(x)	\
  ((x)->attributes & A_CONDITION_INVERTED)

/* Branch instructions that can be combined in a packet with certain other
   branches, and can be the first/second (respectively) in assembly order.  */
#define HEXAGON_OPCODE_IS_DUALJUMP_1(x) \
  ((x)->attributes & A_DUALJUMP_1)
#define HEXAGON_OPCODE_IS_DUALJUMP_2(x) \
  ((x)->attributes & A_DUALJUMP_2)

/* Instruction accepts an extender for the operand indicated with
   the lowercase/uppercase encoding letter (respectively).  */
#define HEXAGON_OPCODE_IS_EXTENDABLE_LOWERCASE(x) \
  ((x)->attributes & A_EXTENDABLE_LOWERCASE)
#define HEXAGON_OPCODE_IS_EXTENDABLE_UPPERCASE(x) \
  ((x)->attributes & A_EXTENDABLE_UPPERCASE)

/* This instruction is a constant extender instruction.  */
#define HEXAGON_OPCODE_IS_EXTENDER(x) \
  ((x)->attributes & A_EXTENDER)

/* This instruction sets up hardware loop registers.  */
#define HEXAGON_OPCODE_IS_HWLOOP(x) \
  ((x)->attributes & A_HWLOOP)

/* The predicate generated by this instruction cannot be used as a .new
   predicate, nor can it be automatically ANDed with another predicate.  */
#define HEXAGON_OPCODE_IS_LATEPRED(x) \
  ((x)->attributes & A_LATEPRED)

/* Instruction is a memory operation.  */
#define HEXAGON_OPCODE_IS_MEMORY(x) \
  ((x)->attributes & A_MEMORY)

/* Instruction has an operand that is always extended.  */
#define HEXAGON_OPCODE_IS_MUST_EXTEND(x) \
  ((x)->attributes & A_MUST_EXTEND)

/* This instruction is a NOP.  */
#define HEXAGON_OPCODE_IS_NOP(x) \
  ((x)->attributes & A_NOP)

/* This instruction contains a PC-plus-immediate operation.  */
#define HEXAGON_OPCODE_IS_PCREL_BRANCH(x) \
  ((x)->attributes & A_PCREL_BRANCH)

/* This instruction may only exist in a packet where the other instructions
   are restricted to A-type or non-float X-type.  */
#define HEXAGON_OPCODE_IS_RESTRICT_AX(x) \
  ((x)->attributes & A_RESTRICT_AX)

/* This attribute is used on some instructions with RESTRICT_AX to
   indicate that the restriction only applies if certain registers
   are being modified.  */
#define HEXAGON_OPCODE_IS_RESTRICT_AX_SOMEREGS(x) \
  ((x)->attributes & A_RESTRICT_AX_SOMEREGS)

/* Slot 1 instruction must be empty or an A-type.  This is used on cache
   instructions for V4 and up.  */
#define HEXAGON_OPCODE_IS_RESTRICT_SLOT1_AONLY(x)	\
  ((x)->attributes & A_RESTRICT_SLOT1_AONLY)

/* No slot 1 instruction allowed in the packet.  This is used on cache
   operations for V2 and V3.  */
#define HEXAGON_OPCODE_IS_RESTRICT_SLOT1_EMPTY(x) \
  ((x)->attributes & A_RESTRICT_SLOT1_EMPTY)

/* A packet containing this instruction must not have a store in slot 1.
   It is used on dealloc_return and some other insns.  */
#define HEXAGON_OPCODE_IS_RESTRICT_SLOT1_NOSTORE(x) \
  ((x)->attributes & A_RESTRICT_SLOT1_NOSTORE)

/* The instruction can only appear as a solo instruction.  */
#define HEXAGON_OPCODE_IS_SOLO(x) \
  ((x)->attributes & A_SOLO)

/* Instruction is a store.  */
#define HEXAGON_OPCODE_IS_STORE(x) \
  ((x)->attributes & A_STORE)

/* Instruction is an X-type float op.  */
#define HEXAGON_OPCODE_IS_XFLOAT(x) \
  ((x)->attributes & A_XFLOAT)

/* The instruction is or contains a dealloc_return.  */
#define HEXAGON_OPCODE_IS_DEALLOCRET(x) \
  ((x)->attributes & A_DEALLOCRET)

/* The instruction is a duplex.  */
#define HEXAGON_OPCODE_IS_DUPLEX(x) \
  (HEXAGON_END_PACKET_GET((x)->insn) == HEXAGON_END_PAIR)

/* Usual idiom for matching an extendable immediate operand with an opcode.  */
#define HEXAGON_OPERAND_IS_EXTENDABLE(operand, opcode) \
  ((HEXAGON_OPCODE_IS_EXTENDABLE_LOWERCASE (opcode)   \
    && ISLOWER ((operand)->enc_letter))			  \
   || (HEXAGON_OPCODE_IS_EXTENDABLE_UPPERCASE (opcode)   \
       && ISUPPER ((operand)->enc_letter)))

typedef size_t hexagon_hash;

/* Operand descriptors.  */
typedef struct _hexagon_operand
{
  /* Format that appears in the hexagon_opcode syntax.  */
  const char *fmt;

  /* Significant positions in the format.  If zero, all of the format
     is significant.  */
  unsigned char len;

  /* The number of bits in the operand (may be unused for a modifier).  */
  unsigned char bits;

  /* The letter that identifies this operand in the hexagon_opcode enc
     string.  */
  char enc_letter;

  /* For immediate arguments, the value should be shifted right by this
     amount.  */
  unsigned char shift_count;

  /* The relocation type and that of the extension and itself after
     being extended.  */
  bfd_reloc_code_real_type reloc_type, reloc_kxer, reloc_kxed;

  /* Various flag bits.  */
  int flags;

  /* Values for `flags'.  */
#define HEXAGON_OPERAND_IS_IMMEDIATE	0x00000001
#define HEXAGON_OPERAND_PC_RELATIVE  	0x00000002
#define HEXAGON_OPERAND_IS_SIGNED	0x00000004
#define HEXAGON_OPERAND_IS_PAIR		0x00000008
#define HEXAGON_OPERAND_IS_SUBSET	0x00000010
#define HEXAGON_OPERAND_IS_MODIFIER	0x00000020
#define HEXAGON_OPERAND_IS_PREDICATE	0x00000040
#define HEXAGON_OPERAND_IS_CONTROL	0x00000080
#define HEXAGON_OPERAND_IS_SYSTEM	0x00000100
#define HEXAGON_OPERAND_IS_LO16		0x00000200
#define HEXAGON_OPERAND_IS_HI16		0x00000400
#define HEXAGON_OPERAND_IS_READ		0x00000800
#define HEXAGON_OPERAND_IS_WRITE	0x00001000
#define HEXAGON_OPERAND_IS_MODIFIED	0x00002000
#define HEXAGON_OPERAND_IS_NEGATIVE	0x00004000
#define HEXAGON_OPERAND_IS_CONSTANT	0x00008000
#define HEXAGON_OPERAND_IS_NEW		0x00010000
#define HEXAGON_OPERAND_IS_GUEST	0x00020000
#define HEXAGON_OPERAND_IS_REGISTER	0x00040000
#define HEXAGON_OPERAND_IS_RNEW		0x00080000
#define HEXAGON_OPERAND_IS_GPREL_OR_ABS	0x00100000
#define HEXAGON_OPERAND_IS_RELAX	0x10000000
#define HEXAGON_OPERAND_IS_KXER		0x20000000
#define HEXAGON_OPERAND_IS_KXED		0x40000000
#define HEXAGON_OPERAND_IS_INVALID	0x80000000

  /* Format string for disassembly.  */
  char *dis_fmt;

} hexagon_operand;

/* Special opcodes objects used by the assembler.  */
extern const hexagon_opcode *hexagon_nop_opcode, *hexagon_kext_opcode;

/* Bits 15:14 in the instruction mark packet boundaries.  */
#define HEXAGON_END_PACKET_POS  14
#define HEXAGON_END_PACKET_MASK (3 << HEXAGON_END_PACKET_POS)
/* End of packet.  */
#define HEXAGON_END_PACKET      (3 << HEXAGON_END_PACKET_POS) 
/* End of loop.  */
#define HEXAGON_END_LOOP        (2 << HEXAGON_END_PACKET_POS) 
/* Neither.  */
#define HEXAGON_END_NOT         (1 << HEXAGON_END_PACKET_POS)
/* Compound insn.  */
#define HEXAGON_END_PAIR        (0 << HEXAGON_END_PACKET_POS) 

/* Get, set and reset packet bits in insn.  */
#define HEXAGON_END_PACKET_GET(insn) \
  ((insn) & HEXAGON_END_PACKET_MASK)
#define HEXAGON_END_PACKET_SET(insn, bits) \
  (((insn) & ~HEXAGON_END_PACKET_MASK) | (bits))
#define HEXAGON_END_PACKET_RESET(insn) \
  HEXAGON_END_PACKET_SET ((insn),					\
			  (HEXAGON_END_PACKET_GET (insn) == HEXAGON_END_PAIR \
			   ? HEXAGON_END_PAIR				\
			   : HEXAGON_END_NOT))

/* Test for arch version.  */
#define hexagon_if_arch_v2() hexagon_if_arch (bfd_mach_hexagon_v2)
#define hexagon_if_arch_v3() hexagon_if_arch (bfd_mach_hexagon_v3)
#define hexagon_if_arch_v4() hexagon_if_arch (bfd_mach_hexagon_v4)
#define hexagon_if_arch_v5() hexagon_if_arch (bfd_mach_hexagon_v5)
#define hexagon_if_arch_v55() hexagon_if_arch (bfd_mach_hexagon_v55)

/* Extern declarations.  */
extern int hexagon_arch (void);
extern int hexagon_if_arch (int);
extern int hexagon_if_arch_kext (void);
extern int hexagon_if_arch_pairs (void);
extern int hexagon_if_arch_autoand (void);

extern void hexagon_isa_init (int, hexagon_opcode **, size_t *);

extern int hexagon_encode_operand
  (const hexagon_operand *, hexagon_insn *, const hexagon_opcode *,
   long, int, char **);
extern const hexagon_operand *hexagon_lookup_reloc
  (bfd_reloc_code_real_type, int, const hexagon_opcode *);
extern const hexagon_operand *hexagon_lookup_operand_name
  (const char *, size_t);
extern const hexagon_opcode *hexagon_opcode_lookup_asm (const char *);
extern const hexagon_opcode *hexagon_opcode_lookup_dis (hexagon_insn);
extern const hexagon_opcode *hexagon_lookup_insn (hexagon_insn);

#endif  /* HEXAGON_ISA_H */


