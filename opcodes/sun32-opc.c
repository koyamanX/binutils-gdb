/* DO NOT EDIT!  -*- buffer-read-only: t -*- vi:set ro:  */
/* Instruction opcode table for sun32.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 1996-2019 Free Software Foundation, Inc.

This file is part of the GNU Binutils and/or GDB, the GNU debugger.

   This file is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.

*/

#include "sysdep.h"
#include "ansidecl.h"
#include "bfd.h"
#include "symcat.h"
#include "sun32-desc.h"
#include "sun32-opc.h"
#include "libiberty.h"

/* -- opc.c */
/* -- */
/* The hash functions are recorded here to help keep assembler code out of
   the disassembler and vice versa.  */

static int asm_hash_insn_p        (const CGEN_INSN *);
static unsigned int asm_hash_insn (const char *);
static int dis_hash_insn_p        (const CGEN_INSN *);
static unsigned int dis_hash_insn (const char *, CGEN_INSN_INT);

/* Instruction formats.  */

#define F(f) & sun32_cgen_ifld_table[SUN32_##f]
static const CGEN_IFMT ifmt_empty ATTRIBUTE_UNUSED = {
  0, 0, 0x0, { { 0 } }
};

static const CGEN_IFMT ifmt_lda_hi ATTRIBUTE_UNUSED = {
  32, 32, 0xfe000003, { { F (F_TYPE) }, { F (F_OP) }, { F (F_RD) }, { F (F_U18) }, { F (F_XXXH) }, { 0 } }
};

static const CGEN_IFMT ifmt_lda_lo ATTRIBUTE_UNUSED = {
  32, 32, 0xfe008000, { { F (F_TYPE) }, { F (F_OP) }, { F (F_RD) }, { F (F_RA) }, { F (F_XXXL) }, { F (F_U14) }, { 0 } }
};

static const CGEN_IFMT ifmt_ret ATTRIBUTE_UNUSED = {
  32, 32, 0xffffffff, { { F (F_TYPE) }, { F (F_COND) }, { F (F_MODE) }, { F (F_XXXT25) }, { 0 } }
};

static const CGEN_IFMT ifmt_add ATTRIBUTE_UNUSED = {
  32, 32, 0xfe0003ff, { { F (F_TYPE) }, { F (F_OP) }, { F (F_RD) }, { F (F_RA) }, { F (F_RB) }, { F (F_X) }, { 0 } }
};

static const CGEN_IFMT ifmt_addi ATTRIBUTE_UNUSED = {
  32, 32, 0xfe000000, { { F (F_TYPE) }, { F (F_OP) }, { F (F_RD) }, { F (F_RA) }, { F (F_I15) }, { 0 } }
};

static const CGEN_IFMT ifmt_lui ATTRIBUTE_UNUSED = {
  32, 32, 0xfe000000, { { F (F_TYPE) }, { F (F_OP) }, { F (F_RD) }, { F (F_U20) }, { 0 } }
};

static const CGEN_IFMT ifmt_lw ATTRIBUTE_UNUSED = {
  32, 32, 0xfe007000, { { F (F_TYPE) }, { F (F_OP) }, { F (F_RD) }, { F (F_RA) }, { F (F_U) }, { F (F_S) }, { F (F_A) }, { F (F_MEM) }, { 0 } }
};

static const CGEN_IFMT ifmt_bnepc ATTRIBUTE_UNUSED = {
  32, 32, 0xfe000000, { { F (F_TYPE) }, { F (F_COND) }, { F (F_MODE) }, { F (F_T25P) }, { 0 } }
};

static const CGEN_IFMT ifmt_bnereg ATTRIBUTE_UNUSED = {
  32, 32, 0xfe000000, { { F (F_TYPE) }, { F (F_COND) }, { F (F_MODE) }, { F (F_RA) }, { F (F_T20R) }, { 0 } }
};

#undef F

#define A(a) (1 << CGEN_INSN_##a)
#define OPERAND(op) SUN32_OPERAND_##op
#define MNEM CGEN_SYNTAX_MNEMONIC /* syntax value for mnemonic */
#define OP(field) CGEN_SYNTAX_MAKE_FIELD (OPERAND (field))

/* The instruction table.  */

static const CGEN_OPCODE sun32_cgen_insn_opcode_table[MAX_INSNS] =
{
  /* Special null first entry.
     A `num' value of zero is thus invalid.
     Also, the special `invalid' insn resides here.  */
  { { 0, 0, 0, 0 }, {{0}}, 0, {0}},
/* ldh $rd,$hi18 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (HI18), 0 } },
    & ifmt_lda_hi, { 0x50000000 }
  },
/* ldl $rd,$ra,$lo14 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RA), ',', OP (LO14), 0 } },
    & ifmt_lda_lo, { 0x68000000 }
  },
/* ret */
  {
    { 0, 0, 0, 0 },
    { { MNEM, 0 } },
    & ifmt_ret, { 0xac000000 }
  },
/* reti */
  {
    { 0, 0, 0, 0 },
    { { MNEM, 0 } },
    & ifmt_ret, { 0xb0000000 }
  },
/* add $rd,$ra,$rb */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RA), ',', OP (RB), 0 } },
    & ifmt_add, { 0x0 }
  },
/* sub $rd,$ra,$rb */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RA), ',', OP (RB), 0 } },
    & ifmt_add, { 0x20000000 }
  },
/* sll $rd,$ra,$rb */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RA), ',', OP (RB), 0 } },
    & ifmt_add, { 0x2000000 }
  },
/* srl $rd,$ra,$rb */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RA), ',', OP (RB), 0 } },
    & ifmt_add, { 0x4000000 }
  },
/* sra $rd,$ra,$rb */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RA), ',', OP (RB), 0 } },
    & ifmt_add, { 0x6000000 }
  },
/* xor $rd,$ra,$rb */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RA), ',', OP (RB), 0 } },
    & ifmt_add, { 0x8000000 }
  },
/* or $rd,$ra,$rb */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RA), ',', OP (RB), 0 } },
    & ifmt_add, { 0x28000000 }
  },
/* and $rd,$ra,$rb */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RA), ',', OP (RB), 0 } },
    & ifmt_add, { 0xa000000 }
  },
/* mult $rd,$ra,$rb */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RA), ',', OP (RB), 0 } },
    & ifmt_add, { 0xc000000 }
  },
/* multu $rd,$ra,$rb */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RA), ',', OP (RB), 0 } },
    & ifmt_add, { 0x2c000000 }
  },
/* div $rd,$ra,$rb */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RA), ',', OP (RB), 0 } },
    & ifmt_add, { 0xe000000 }
  },
/* divu $rd,$ra,$rb */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RA), ',', OP (RB), 0 } },
    & ifmt_add, { 0x2e000000 }
  },
/* cmp $rd,$ra,$rb */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (RA), ',', OP (RB), 0 } },
    & ifmt_add, { 0x30000000 }
  },
/* add $rd,$i15($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I15), '(', OP (RA), ')', 0 } },
    & ifmt_addi, { 0x40000000 }
  },
/* sub $rd,$i15($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I15), '(', OP (RA), ')', 0 } },
    & ifmt_addi, { 0x40000000 }
  },
/* sll $rd,$i15($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I15), '(', OP (RA), ')', 0 } },
    & ifmt_addi, { 0x42000000 }
  },
/* srl $rd,$i15($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I15), '(', OP (RA), ')', 0 } },
    & ifmt_addi, { 0x44000000 }
  },
/* sra $rd,$i15($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I15), '(', OP (RA), ')', 0 } },
    & ifmt_addi, { 0x46000000 }
  },
/* xor $rd,$i15($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I15), '(', OP (RA), ')', 0 } },
    & ifmt_addi, { 0x48000000 }
  },
/* or $rd,$i15($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I15), '(', OP (RA), ')', 0 } },
    & ifmt_addi, { 0x68000000 }
  },
/* and $rd,$i15($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I15), '(', OP (RA), ')', 0 } },
    & ifmt_addi, { 0x4a000000 }
  },
/* mult $rd,$i15($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I15), '(', OP (RA), ')', 0 } },
    & ifmt_addi, { 0x4c000000 }
  },
/* multu $rd,$i15($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I15), '(', OP (RA), ')', 0 } },
    & ifmt_addi, { 0x6c000000 }
  },
/* div $rd,$i15($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I15), '(', OP (RA), ')', 0 } },
    & ifmt_addi, { 0x4e000000 }
  },
/* divu $rd,$i15($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I15), '(', OP (RA), ')', 0 } },
    & ifmt_addi, { 0x6e000000 }
  },
/* cmp $rd,$i15($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (I15), '(', OP (RA), ')', 0 } },
    & ifmt_addi, { 0x60000000 }
  },
/* lui $rd,$u20 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (U20), 0 } },
    & ifmt_lui, { 0x50000000 }
  },
/* lw $rd,$m12($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (M12), '(', OP (RA), ')', 0 } },
    & ifmt_lw, { 0x72000000 }
  },
/* lh $rd,$m12($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (M12), '(', OP (RA), ')', 0 } },
    & ifmt_lw, { 0x74000000 }
  },
/* lb $rd,$m12($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (M12), '(', OP (RA), ')', 0 } },
    & ifmt_lw, { 0x76000000 }
  },
/* sw $rd,$m12($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (M12), '(', OP (RA), ')', 0 } },
    & ifmt_lw, { 0x7a000000 }
  },
/* sh $rd,$m12($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (M12), '(', OP (RA), ')', 0 } },
    & ifmt_lw, { 0x7c000000 }
  },
/* sb $rd,$m12($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (RD), ',', OP (M12), '(', OP (RA), ')', 0 } },
    & ifmt_lw, { 0x7e000000 }
  },
/* bne $t25 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T25), 0 } },
    & ifmt_bnepc, { 0x80000000 }
  },
/* beq $t25 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T25), 0 } },
    & ifmt_bnepc, { 0x84000000 }
  },
/* bgt $t25 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T25), 0 } },
    & ifmt_bnepc, { 0x88000000 }
  },
/* bge $t25 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T25), 0 } },
    & ifmt_bnepc, { 0x8c000000 }
  },
/* blt $t25 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T25), 0 } },
    & ifmt_bnepc, { 0x90000000 }
  },
/* ble $t25 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T25), 0 } },
    & ifmt_bnepc, { 0x94000000 }
  },
/* b $t25 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T25), 0 } },
    & ifmt_bnepc, { 0x98000000 }
  },
/* bult $t25 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T25), 0 } },
    & ifmt_bnepc, { 0x9c000000 }
  },
/* bule $t25 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T25), 0 } },
    & ifmt_bnepc, { 0xa0000000 }
  },
/* bugt $t25 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T25), 0 } },
    & ifmt_bnepc, { 0xa4000000 }
  },
/* buge $t25 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T25), 0 } },
    & ifmt_bnepc, { 0xa8000000 }
  },
/* call $t25 */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T25), 0 } },
    & ifmt_bnepc, { 0xb4000000 }
  },
/* bne $t20($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T20), '(', OP (RA), ')', 0 } },
    & ifmt_bnereg, { 0x82000000 }
  },
/* beq $t20($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T20), '(', OP (RA), ')', 0 } },
    & ifmt_bnereg, { 0x86000000 }
  },
/* bgt $t20($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T20), '(', OP (RA), ')', 0 } },
    & ifmt_bnereg, { 0x8a000000 }
  },
/* bge $t20($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T20), '(', OP (RA), ')', 0 } },
    & ifmt_bnereg, { 0x8e000000 }
  },
/* blt $t20($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T20), '(', OP (RA), ')', 0 } },
    & ifmt_bnereg, { 0x92000000 }
  },
/* ble $t20($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T20), '(', OP (RA), ')', 0 } },
    & ifmt_bnereg, { 0x96000000 }
  },
/* b $t20($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T20), '(', OP (RA), ')', 0 } },
    & ifmt_bnereg, { 0x9a000000 }
  },
/* bult $t20($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T20), '(', OP (RA), ')', 0 } },
    & ifmt_bnereg, { 0x9e000000 }
  },
/* bule $t20($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T20), '(', OP (RA), ')', 0 } },
    & ifmt_bnereg, { 0xa2000000 }
  },
/* bugt $t20($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T20), '(', OP (RA), ')', 0 } },
    & ifmt_bnereg, { 0xa6000000 }
  },
/* buge $t20($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T20), '(', OP (RA), ')', 0 } },
    & ifmt_bnereg, { 0xaa000000 }
  },
/* call $t20($ra) */
  {
    { 0, 0, 0, 0 },
    { { MNEM, ' ', OP (T20), '(', OP (RA), ')', 0 } },
    & ifmt_bnereg, { 0xb6000000 }
  },
};

#undef A
#undef OPERAND
#undef MNEM
#undef OP

/* Formats for ALIAS macro-insns.  */

#define F(f) & sun32_cgen_ifld_table[SUN32_##f]
#undef F

/* Each non-simple macro entry points to an array of expansion possibilities.  */

#define A(a) (1 << CGEN_INSN_##a)
#define OPERAND(op) SUN32_OPERAND_##op
#define MNEM CGEN_SYNTAX_MNEMONIC /* syntax value for mnemonic */
#define OP(field) CGEN_SYNTAX_MAKE_FIELD (OPERAND (field))

/* The macro instruction table.  */

static const CGEN_IBASE sun32_cgen_macro_insn_table[] =
{
};

/* The macro instruction opcode table.  */

static const CGEN_OPCODE sun32_cgen_macro_insn_opcode_table[] =
{
};

#undef A
#undef OPERAND
#undef MNEM
#undef OP

#ifndef CGEN_ASM_HASH_P
#define CGEN_ASM_HASH_P(insn) 1
#endif

#ifndef CGEN_DIS_HASH_P
#define CGEN_DIS_HASH_P(insn) 1
#endif

/* Return non-zero if INSN is to be added to the hash table.
   Targets are free to override CGEN_{ASM,DIS}_HASH_P in the .opc file.  */

static int
asm_hash_insn_p (const CGEN_INSN *insn ATTRIBUTE_UNUSED)
{
  return CGEN_ASM_HASH_P (insn);
}

static int
dis_hash_insn_p (const CGEN_INSN *insn)
{
  /* If building the hash table and the NO-DIS attribute is present,
     ignore.  */
  if (CGEN_INSN_ATTR_VALUE (insn, CGEN_INSN_NO_DIS))
    return 0;
  return CGEN_DIS_HASH_P (insn);
}

#ifndef CGEN_ASM_HASH
#define CGEN_ASM_HASH_SIZE 127
#ifdef CGEN_MNEMONIC_OPERANDS
#define CGEN_ASM_HASH(mnem) (*(unsigned char *) (mnem) % CGEN_ASM_HASH_SIZE)
#else
#define CGEN_ASM_HASH(mnem) (*(unsigned char *) (mnem) % CGEN_ASM_HASH_SIZE) /*FIXME*/
#endif
#endif

/* It doesn't make much sense to provide a default here,
   but while this is under development we do.
   BUFFER is a pointer to the bytes of the insn, target order.
   VALUE is the first base_insn_bitsize bits as an int in host order.  */

#ifndef CGEN_DIS_HASH
#define CGEN_DIS_HASH_SIZE 256
#define CGEN_DIS_HASH(buf, value) (*(unsigned char *) (buf))
#endif

/* The result is the hash value of the insn.
   Targets are free to override CGEN_{ASM,DIS}_HASH in the .opc file.  */

static unsigned int
asm_hash_insn (const char *mnem)
{
  return CGEN_ASM_HASH (mnem);
}

/* BUF is a pointer to the bytes of the insn, target order.
   VALUE is the first base_insn_bitsize bits as an int in host order.  */

static unsigned int
dis_hash_insn (const char *buf ATTRIBUTE_UNUSED,
		     CGEN_INSN_INT value ATTRIBUTE_UNUSED)
{
  return CGEN_DIS_HASH (buf, value);
}

/* Set the recorded length of the insn in the CGEN_FIELDS struct.  */

static void
set_fields_bitsize (CGEN_FIELDS *fields, int size)
{
  CGEN_FIELDS_BITSIZE (fields) = size;
}

/* Function to call before using the operand instance table.
   This plugs the opcode entries and macro instructions into the cpu table.  */

void
sun32_cgen_init_opcode_table (CGEN_CPU_DESC cd)
{
  int i;
  int num_macros = (sizeof (sun32_cgen_macro_insn_table) /
		    sizeof (sun32_cgen_macro_insn_table[0]));
  const CGEN_IBASE *ib = & sun32_cgen_macro_insn_table[0];
  const CGEN_OPCODE *oc = & sun32_cgen_macro_insn_opcode_table[0];
  CGEN_INSN *insns = xmalloc (num_macros * sizeof (CGEN_INSN));

  /* This test has been added to avoid a warning generated
     if memset is called with a third argument of value zero.  */
  if (num_macros >= 1)
    memset (insns, 0, num_macros * sizeof (CGEN_INSN));
  for (i = 0; i < num_macros; ++i)
    {
      insns[i].base = &ib[i];
      insns[i].opcode = &oc[i];
      sun32_cgen_build_insn_regex (& insns[i]);
    }
  cd->macro_insn_table.init_entries = insns;
  cd->macro_insn_table.entry_size = sizeof (CGEN_IBASE);
  cd->macro_insn_table.num_init_entries = num_macros;

  oc = & sun32_cgen_insn_opcode_table[0];
  insns = (CGEN_INSN *) cd->insn_table.init_entries;
  for (i = 0; i < MAX_INSNS; ++i)
    {
      insns[i].opcode = &oc[i];
      sun32_cgen_build_insn_regex (& insns[i]);
    }

  cd->sizeof_fields = sizeof (CGEN_FIELDS);
  cd->set_fields_bitsize = set_fields_bitsize;

  cd->asm_hash_p = asm_hash_insn_p;
  cd->asm_hash = asm_hash_insn;
  cd->asm_hash_size = CGEN_ASM_HASH_SIZE;

  cd->dis_hash_p = dis_hash_insn_p;
  cd->dis_hash = dis_hash_insn;
  cd->dis_hash_size = CGEN_DIS_HASH_SIZE;
}
