/* DO NOT EDIT!  -*- buffer-read-only: t -*- vi:set ro:  */
/* CPU data for sun32.

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
#include <stdio.h>
#include <stdarg.h>
#include "ansidecl.h"
#include "bfd.h"
#include "symcat.h"
#include "sun32-desc.h"
#include "sun32-opc.h"
#include "opintl.h"
#include "libiberty.h"
#include "xregex.h"

/* Attributes.  */

static const CGEN_ATTR_ENTRY bool_attr[] =
{
  { "#f", 0 },
  { "#t", 1 },
  { 0, 0 }
};

static const CGEN_ATTR_ENTRY MACH_attr[] ATTRIBUTE_UNUSED =
{
  { "base", MACH_BASE },
  { "sun32", MACH_SUN32 },
  { "max", MACH_MAX },
  { 0, 0 }
};

static const CGEN_ATTR_ENTRY ISA_attr[] ATTRIBUTE_UNUSED =
{
  { "sun32", ISA_SUN32 },
  { "max", ISA_MAX },
  { 0, 0 }
};

const CGEN_ATTR_TABLE sun32_cgen_ifield_attr_table[] =
{
  { "MACH", & MACH_attr[0], & MACH_attr[0] },
  { "VIRTUAL", &bool_attr[0], &bool_attr[0] },
  { "PCREL-ADDR", &bool_attr[0], &bool_attr[0] },
  { "ABS-ADDR", &bool_attr[0], &bool_attr[0] },
  { "RESERVED", &bool_attr[0], &bool_attr[0] },
  { "SIGN-OPT", &bool_attr[0], &bool_attr[0] },
  { "SIGNED", &bool_attr[0], &bool_attr[0] },
  { 0, 0, 0 }
};

const CGEN_ATTR_TABLE sun32_cgen_hardware_attr_table[] =
{
  { "MACH", & MACH_attr[0], & MACH_attr[0] },
  { "VIRTUAL", &bool_attr[0], &bool_attr[0] },
  { "CACHE-ADDR", &bool_attr[0], &bool_attr[0] },
  { "PC", &bool_attr[0], &bool_attr[0] },
  { "PROFILE", &bool_attr[0], &bool_attr[0] },
  { 0, 0, 0 }
};

const CGEN_ATTR_TABLE sun32_cgen_operand_attr_table[] =
{
  { "MACH", & MACH_attr[0], & MACH_attr[0] },
  { "VIRTUAL", &bool_attr[0], &bool_attr[0] },
  { "PCREL-ADDR", &bool_attr[0], &bool_attr[0] },
  { "ABS-ADDR", &bool_attr[0], &bool_attr[0] },
  { "SIGN-OPT", &bool_attr[0], &bool_attr[0] },
  { "SIGNED", &bool_attr[0], &bool_attr[0] },
  { "NEGATIVE", &bool_attr[0], &bool_attr[0] },
  { "RELAX", &bool_attr[0], &bool_attr[0] },
  { "SEM-ONLY", &bool_attr[0], &bool_attr[0] },
  { 0, 0, 0 }
};

const CGEN_ATTR_TABLE sun32_cgen_insn_attr_table[] =
{
  { "MACH", & MACH_attr[0], & MACH_attr[0] },
  { "ALIAS", &bool_attr[0], &bool_attr[0] },
  { "VIRTUAL", &bool_attr[0], &bool_attr[0] },
  { "UNCOND-CTI", &bool_attr[0], &bool_attr[0] },
  { "COND-CTI", &bool_attr[0], &bool_attr[0] },
  { "SKIP-CTI", &bool_attr[0], &bool_attr[0] },
  { "DELAY-SLOT", &bool_attr[0], &bool_attr[0] },
  { "RELAXABLE", &bool_attr[0], &bool_attr[0] },
  { "RELAXED", &bool_attr[0], &bool_attr[0] },
  { "NO-DIS", &bool_attr[0], &bool_attr[0] },
  { "PBB", &bool_attr[0], &bool_attr[0] },
  { 0, 0, 0 }
};

/* Instruction set variants.  */

static const CGEN_ISA sun32_cgen_isa_table[] = {
  { "sun32", 32, 32, 32, 32 },
  { 0, 0, 0, 0, 0 }
};

/* Machine variants.  */

static const CGEN_MACH sun32_cgen_mach_table[] = {
  { "sun32", "sun32", MACH_SUN32, 0 },
  { 0, 0, 0, 0 }
};

static CGEN_KEYWORD_ENTRY sun32_cgen_opval_h_gr_entries[] =
{
  { "r0", 0, {0, {{{0, 0}}}}, 0, 0 },
  { "r1", 1, {0, {{{0, 0}}}}, 0, 0 },
  { "r2", 2, {0, {{{0, 0}}}}, 0, 0 },
  { "r3", 3, {0, {{{0, 0}}}}, 0, 0 },
  { "r4", 4, {0, {{{0, 0}}}}, 0, 0 },
  { "r5", 5, {0, {{{0, 0}}}}, 0, 0 },
  { "r6", 6, {0, {{{0, 0}}}}, 0, 0 },
  { "r7", 7, {0, {{{0, 0}}}}, 0, 0 },
  { "r8", 8, {0, {{{0, 0}}}}, 0, 0 },
  { "r9", 9, {0, {{{0, 0}}}}, 0, 0 },
  { "r10", 10, {0, {{{0, 0}}}}, 0, 0 },
  { "r11", 11, {0, {{{0, 0}}}}, 0, 0 },
  { "r12", 12, {0, {{{0, 0}}}}, 0, 0 },
  { "r13", 13, {0, {{{0, 0}}}}, 0, 0 },
  { "r14", 14, {0, {{{0, 0}}}}, 0, 0 },
  { "r15", 15, {0, {{{0, 0}}}}, 0, 0 },
  { "r16", 16, {0, {{{0, 0}}}}, 0, 0 },
  { "r17", 17, {0, {{{0, 0}}}}, 0, 0 },
  { "r18", 18, {0, {{{0, 0}}}}, 0, 0 },
  { "r19", 19, {0, {{{0, 0}}}}, 0, 0 },
  { "r20", 20, {0, {{{0, 0}}}}, 0, 0 },
  { "r21", 21, {0, {{{0, 0}}}}, 0, 0 },
  { "r22", 22, {0, {{{0, 0}}}}, 0, 0 },
  { "r23", 23, {0, {{{0, 0}}}}, 0, 0 },
  { "r24", 24, {0, {{{0, 0}}}}, 0, 0 },
  { "r25", 25, {0, {{{0, 0}}}}, 0, 0 },
  { "r26", 26, {0, {{{0, 0}}}}, 0, 0 },
  { "r27", 27, {0, {{{0, 0}}}}, 0, 0 },
  { "r28", 28, {0, {{{0, 0}}}}, 0, 0 },
  { "r29", 29, {0, {{{0, 0}}}}, 0, 0 },
  { "r30", 30, {0, {{{0, 0}}}}, 0, 0 },
  { "r31", 31, {0, {{{0, 0}}}}, 0, 0 },
  { "sp", 30, {0, {{{0, 0}}}}, 0, 0 },
  { "gp", 29, {0, {{{0, 0}}}}, 0, 0 }
};

CGEN_KEYWORD sun32_cgen_opval_h_gr =
{
  & sun32_cgen_opval_h_gr_entries[0],
  34,
  0, 0, 0, 0, ""
};


/* The hardware table.  */

#define A(a) (1 << CGEN_HW_##a)

const CGEN_HW_ENTRY sun32_cgen_hw_table[] =
{
  { "h-memory", HW_H_MEMORY, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-sint", HW_H_SINT, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-uint", HW_H_UINT, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-addr", HW_H_ADDR, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-iaddr", HW_H_IADDR, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-pc", HW_H_PC, CGEN_ASM_NONE, 0, { 0|A(PC), { { { (1<<MACH_BASE), 0 } } } } },
  { "h-gr", HW_H_GR, CGEN_ASM_KEYWORD, (PTR) & sun32_cgen_opval_h_gr, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-int12", HW_H_INT12, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-int15", HW_H_INT15, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-uint20", HW_H_UINT20, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-int25", HW_H_INT25, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-int20", HW_H_INT20, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-uint18", HW_H_UINT18, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { "h-uint14", HW_H_UINT14, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
  { 0, 0, CGEN_ASM_NONE, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } }
};

#undef A


/* The instruction field table.  */

#define A(a) (1 << CGEN_IFLD_##a)

const CGEN_IFLD sun32_cgen_ifld_table[] =
{
  { SUN32_F_NIL, "f-nil", 0, 0, 0, 0, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_ANYOF, "f-anyof", 0, 0, 0, 0, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_TYPE, "f-type", 0, 32, 31, 2, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_OP, "f-op", 0, 32, 29, 5, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_RD, "f-rd", 0, 32, 24, 5, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_RA, "f-ra", 0, 32, 19, 5, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_RB, "f-rb", 0, 32, 14, 5, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_X, "f-x", 0, 32, 9, 10, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_XXXH, "f-xxxh", 0, 32, 1, 2, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_XXXL, "f-xxxl", 0, 32, 15, 1, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_XXXT25, "f-xxxt25", 0, 32, 24, 25, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_XXX20, "f-xxx20", 0, 32, 19, 20, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_SFT, "f-sft", 0, 32, 11, 3, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_A, "f-a", 0, 32, 12, 1, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_S, "f-s", 0, 32, 13, 1, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_U, "f-u", 0, 32, 14, 1, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_MEMS, "f-mems", 0, 32, 8, 9, { 0|A(ABS_ADDR), { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_MEM, "f-mem", 0, 32, 11, 12, { 0|A(ABS_ADDR), { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_U18, "f-u18", 0, 32, 19, 18, { 0|A(ABS_ADDR), { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_U14, "f-u14", 0, 32, 13, 14, { 0|A(ABS_ADDR), { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_U20, "f-u20", 0, 32, 19, 20, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_I15, "f-i15", 0, 32, 14, 15, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_MODE, "f-mode", 0, 32, 25, 1, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_COND, "f-cond", 0, 32, 29, 4, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_T25P, "f-t25p", 0, 32, 24, 25, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { SUN32_F_T20R, "f-t20r", 0, 32, 19, 20, { 0, { { { (1<<MACH_BASE), 0 } } } }  },
  { 0, 0, 0, 0, 0, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } }
};

#undef A



/* multi ifield declarations */



/* multi ifield definitions */


/* The operand table.  */

#define A(a) (1 << CGEN_OPERAND_##a)
#define OPERAND(op) SUN32_OPERAND_##op

const CGEN_OPERAND sun32_cgen_operand_table[] =
{
/* pc: program counter */
  { "pc", SUN32_OPERAND_PC, HW_H_PC, 0, 0,
    { 0, { (const PTR) &sun32_cgen_ifld_table[SUN32_F_NIL] } },
    { 0|A(SEM_ONLY), { { { (1<<MACH_BASE), 0 } } } }  },
/* rd: destination register */
  { "rd", SUN32_OPERAND_RD, HW_H_GR, 24, 5,
    { 0, { (const PTR) &sun32_cgen_ifld_table[SUN32_F_RD] } },
    { 0, { { { (1<<MACH_BASE), 0 } } } }  },
/* ra: source register a */
  { "ra", SUN32_OPERAND_RA, HW_H_GR, 19, 5,
    { 0, { (const PTR) &sun32_cgen_ifld_table[SUN32_F_RA] } },
    { 0, { { { (1<<MACH_BASE), 0 } } } }  },
/* rb: source register b */
  { "rb", SUN32_OPERAND_RB, HW_H_GR, 14, 5,
    { 0, { (const PTR) &sun32_cgen_ifld_table[SUN32_F_RB] } },
    { 0, { { { (1<<MACH_BASE), 0 } } } }  },
/* u20: u20 long imm */
  { "u20", SUN32_OPERAND_U20, HW_H_UINT20, 19, 20,
    { 0, { (const PTR) &sun32_cgen_ifld_table[SUN32_F_U20] } },
    { 0, { { { (1<<MACH_BASE), 0 } } } }  },
/* i15: i15 imm without shift */
  { "i15", SUN32_OPERAND_I15, HW_H_INT15, 14, 15,
    { 0, { (const PTR) &sun32_cgen_ifld_table[SUN32_F_I15] } },
    { 0, { { { (1<<MACH_BASE), 0 } } } }  },
/* m9: i9 byte aligned memory */
  { "m9", SUN32_OPERAND_M9, HW_H_ADDR, 8, 9,
    { 0, { (const PTR) &sun32_cgen_ifld_table[SUN32_F_MEMS] } },
    { 0|A(ABS_ADDR), { { { (1<<MACH_BASE), 0 } } } }  },
/* m12: i12 byte aligned memory */
  { "m12", SUN32_OPERAND_M12, HW_H_ADDR, 11, 12,
    { 0, { (const PTR) &sun32_cgen_ifld_table[SUN32_F_MEM] } },
    { 0|A(ABS_ADDR), { { { (1<<MACH_BASE), 0 } } } }  },
/* t25: i25 word aligned */
  { "t25", SUN32_OPERAND_T25, HW_H_IADDR, 24, 25,
    { 0, { (const PTR) &sun32_cgen_ifld_table[SUN32_F_T25P] } },
    { 0, { { { (1<<MACH_BASE), 0 } } } }  },
/* t20: i20 word aligned */
  { "t20", SUN32_OPERAND_T20, HW_H_IADDR, 19, 20,
    { 0, { (const PTR) &sun32_cgen_ifld_table[SUN32_F_T20R] } },
    { 0, { { { (1<<MACH_BASE), 0 } } } }  },
/* hi18: 18 bit imm */
  { "hi18", SUN32_OPERAND_HI18, HW_H_UINT18, 19, 18,
    { 0, { (const PTR) &sun32_cgen_ifld_table[SUN32_F_U18] } },
    { 0|A(ABS_ADDR), { { { (1<<MACH_BASE), 0 } } } }  },
/* lo14: 14 bit imm */
  { "lo14", SUN32_OPERAND_LO14, HW_H_UINT14, 13, 14,
    { 0, { (const PTR) &sun32_cgen_ifld_table[SUN32_F_U14] } },
    { 0|A(ABS_ADDR), { { { (1<<MACH_BASE), 0 } } } }  },
/* sentinel */
  { 0, 0, 0, 0, 0,
    { 0, { (const PTR) 0 } },
    { 0, { { { (1<<MACH_BASE), 0 } } } } }
};

#undef A


/* The instruction table.  */

#define OP(field) CGEN_SYNTAX_MAKE_FIELD (OPERAND (field))
#define A(a) (1 << CGEN_INSN_##a)

static const CGEN_IBASE sun32_cgen_insn_table[MAX_INSNS] =
{
  /* Special null first entry.
     A `num' value of zero is thus invalid.
     Also, the special `invalid' insn resides here.  */
  { 0, 0, 0, 0, { 0, { { { (1<<MACH_BASE), 0 } } } } },
/* ldh $rd,$hi18 */
  {
    SUN32_INSN_LDA_HI, "lda-hi", "ldh", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* ldl $rd,$ra,$lo14 */
  {
    SUN32_INSN_LDA_LO, "lda-lo", "ldl", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* ret */
  {
    SUN32_INSN_RET, "ret", "ret", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* reti */
  {
    SUN32_INSN_RETI, "reti", "reti", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* add $rd,$ra,$rb */
  {
    SUN32_INSN_ADD, "add", "add", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* sub $rd,$ra,$rb */
  {
    SUN32_INSN_SUB, "sub", "sub", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* sll $rd,$ra,$rb */
  {
    SUN32_INSN_SLL, "sll", "sll", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srl $rd,$ra,$rb */
  {
    SUN32_INSN_SRL, "srl", "srl", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* sra $rd,$ra,$rb */
  {
    SUN32_INSN_SRA, "sra", "sra", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* xor $rd,$ra,$rb */
  {
    SUN32_INSN_XOR, "xor", "xor", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* or $rd,$ra,$rb */
  {
    SUN32_INSN_OR, "or", "or", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* and $rd,$ra,$rb */
  {
    SUN32_INSN_AND, "and", "and", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* mult $rd,$ra,$rb */
  {
    SUN32_INSN_MULT, "mult", "mult", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* rem $rd,$ra,$rb */
  {
    SUN32_INSN_REM, "rem", "rem", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* remu $rd,$ra,$rb */
  {
    SUN32_INSN_REMU, "remu", "remu", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* div $rd,$ra,$rb */
  {
    SUN32_INSN_DIV, "div", "div", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* divu $rd,$ra,$rb */
  {
    SUN32_INSN_DIVU, "divu", "divu", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* cmp $rd,$ra,$rb */
  {
    SUN32_INSN_CMP, "cmp", "cmp", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* add $rd,$i15($ra) */
  {
    SUN32_INSN_ADDI, "addi", "add", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* sub $rd,$i15($ra) */
  {
    SUN32_INSN_SUBI, "subi", "sub", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* sll $rd,$i15($ra) */
  {
    SUN32_INSN_SLLI, "slli", "sll", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* srl $rd,$i15($ra) */
  {
    SUN32_INSN_SRLI, "srli", "srl", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* sra $rd,$i15($ra) */
  {
    SUN32_INSN_SRAI, "srai", "sra", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* xor $rd,$i15($ra) */
  {
    SUN32_INSN_XORI, "xori", "xor", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* or $rd,$i15($ra) */
  {
    SUN32_INSN_ORI, "ori", "or", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* and $rd,$i15($ra) */
  {
    SUN32_INSN_ANDI, "andi", "and", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* mult $rd,$i15($ra) */
  {
    SUN32_INSN_MULTI, "multi", "mult", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* rem $rd,$i15($ra) */
  {
    SUN32_INSN_REMI, "remi", "rem", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* remu $rd,$i15($ra) */
  {
    SUN32_INSN_REMUI, "remui", "remu", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* div $rd,$i15($ra) */
  {
    SUN32_INSN_DIVI, "divi", "div", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* divu $rd,$i15($ra) */
  {
    SUN32_INSN_DIVUI, "divui", "divu", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* cmp $rd,$i15($ra) */
  {
    SUN32_INSN_CMPI, "cmpi", "cmp", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* lui $rd,$u20 */
  {
    SUN32_INSN_LUI, "lui", "lui", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* mcsr $rd */
  {
    SUN32_INSN_MCSR, "mcsr", "mcsr", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* mrcs $rd */
  {
    SUN32_INSN_MRCS, "mrcs", "mrcs", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* lw $rd,$m12($ra) */
  {
    SUN32_INSN_LW, "lw", "lw", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* lh $rd,$m12($ra) */
  {
    SUN32_INSN_LH, "lh", "lh", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* lb $rd,$m12($ra) */
  {
    SUN32_INSN_LB, "lb", "lb", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* sw $rd,$m12($ra) */
  {
    SUN32_INSN_SW, "sw", "sw", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* sh $rd,$m12($ra) */
  {
    SUN32_INSN_SH, "sh", "sh", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* sb $rd,$m12($ra) */
  {
    SUN32_INSN_SB, "sb", "sb", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* lhu $rd,$m12($ra) */
  {
    SUN32_INSN_LHU, "lhu", "lhu", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* lbu $rd,$m12($ra) */
  {
    SUN32_INSN_LBU, "lbu", "lbu", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* bne $t25 */
  {
    SUN32_INSN_BNEPC, "bnepc", "bne", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* beq $t25 */
  {
    SUN32_INSN_BEQPC, "beqpc", "beq", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* bgt $t25 */
  {
    SUN32_INSN_BGTPC, "bgtpc", "bgt", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* bge $t25 */
  {
    SUN32_INSN_BGEPC, "bgepc", "bge", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* blt $t25 */
  {
    SUN32_INSN_BLTPC, "bltpc", "blt", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* ble $t25 */
  {
    SUN32_INSN_BLEPC, "blepc", "ble", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* b $t25 */
  {
    SUN32_INSN_BPC, "bpc", "b", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* bult $t25 */
  {
    SUN32_INSN_BULTPC, "bultpc", "bult", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* bule $t25 */
  {
    SUN32_INSN_BULEPC, "bulepc", "bule", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* bugt $t25 */
  {
    SUN32_INSN_BUGTPC, "bugtpc", "bugt", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* buge $t25 */
  {
    SUN32_INSN_BUGEPC, "bugepc", "buge", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* call $t25 */
  {
    SUN32_INSN_CALLPC, "callpc", "call", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* bne $t20($ra) */
  {
    SUN32_INSN_BNEREG, "bnereg", "bne", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* beq $t20($ra) */
  {
    SUN32_INSN_BEQREG, "beqreg", "beq", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* bgt $t20($ra) */
  {
    SUN32_INSN_BGTREG, "bgtreg", "bgt", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* bge $t20($ra) */
  {
    SUN32_INSN_BGEREG, "bgereg", "bge", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* blt $t20($ra) */
  {
    SUN32_INSN_BLTREG, "bltreg", "blt", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* ble $t20($ra) */
  {
    SUN32_INSN_BLEREG, "blereg", "ble", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* b $t20($ra) */
  {
    SUN32_INSN_BREG, "breg", "b", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* bult $t20($ra) */
  {
    SUN32_INSN_BULTREG, "bultreg", "bult", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* bule $t20($ra) */
  {
    SUN32_INSN_BULEREG, "bulereg", "bule", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* bugt $t20($ra) */
  {
    SUN32_INSN_BUGTREG, "bugtreg", "bugt", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* buge $t20($ra) */
  {
    SUN32_INSN_BUGEREG, "bugereg", "buge", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
/* call $t20($ra) */
  {
    SUN32_INSN_CALLREG, "callreg", "call", 32,
    { 0, { { { (1<<MACH_BASE), 0 } } } }
  },
};

#undef OP
#undef A

/* Initialize anything needed to be done once, before any cpu_open call.  */

static void
init_tables (void)
{
}

#ifndef opcodes_error_handler
#define opcodes_error_handler(...) \
  fprintf (stderr, __VA_ARGS__); fputc ('\n', stderr)
#endif

static const CGEN_MACH * lookup_mach_via_bfd_name (const CGEN_MACH *, const char *);
static void build_hw_table      (CGEN_CPU_TABLE *);
static void build_ifield_table  (CGEN_CPU_TABLE *);
static void build_operand_table (CGEN_CPU_TABLE *);
static void build_insn_table    (CGEN_CPU_TABLE *);
static void sun32_cgen_rebuild_tables (CGEN_CPU_TABLE *);

/* Subroutine of sun32_cgen_cpu_open to look up a mach via its bfd name.  */

static const CGEN_MACH *
lookup_mach_via_bfd_name (const CGEN_MACH *table, const char *name)
{
  while (table->name)
    {
      if (strcmp (name, table->bfd_name) == 0)
	return table;
      ++table;
    }
  return NULL;
}

/* Subroutine of sun32_cgen_cpu_open to build the hardware table.  */

static void
build_hw_table (CGEN_CPU_TABLE *cd)
{
  int i;
  int machs = cd->machs;
  const CGEN_HW_ENTRY *init = & sun32_cgen_hw_table[0];
  /* MAX_HW is only an upper bound on the number of selected entries.
     However each entry is indexed by it's enum so there can be holes in
     the table.  */
  const CGEN_HW_ENTRY **selected =
    (const CGEN_HW_ENTRY **) xmalloc (MAX_HW * sizeof (CGEN_HW_ENTRY *));

  cd->hw_table.init_entries = init;
  cd->hw_table.entry_size = sizeof (CGEN_HW_ENTRY);
  memset (selected, 0, MAX_HW * sizeof (CGEN_HW_ENTRY *));
  /* ??? For now we just use machs to determine which ones we want.  */
  for (i = 0; init[i].name != NULL; ++i)
    if (CGEN_HW_ATTR_VALUE (&init[i], CGEN_HW_MACH)
	& machs)
      selected[init[i].type] = &init[i];
  cd->hw_table.entries = selected;
  cd->hw_table.num_entries = MAX_HW;
}

/* Subroutine of sun32_cgen_cpu_open to build the hardware table.  */

static void
build_ifield_table (CGEN_CPU_TABLE *cd)
{
  cd->ifld_table = & sun32_cgen_ifld_table[0];
}

/* Subroutine of sun32_cgen_cpu_open to build the hardware table.  */

static void
build_operand_table (CGEN_CPU_TABLE *cd)
{
  int i;
  int machs = cd->machs;
  const CGEN_OPERAND *init = & sun32_cgen_operand_table[0];
  /* MAX_OPERANDS is only an upper bound on the number of selected entries.
     However each entry is indexed by it's enum so there can be holes in
     the table.  */
  const CGEN_OPERAND **selected = xmalloc (MAX_OPERANDS * sizeof (* selected));

  cd->operand_table.init_entries = init;
  cd->operand_table.entry_size = sizeof (CGEN_OPERAND);
  memset (selected, 0, MAX_OPERANDS * sizeof (CGEN_OPERAND *));
  /* ??? For now we just use mach to determine which ones we want.  */
  for (i = 0; init[i].name != NULL; ++i)
    if (CGEN_OPERAND_ATTR_VALUE (&init[i], CGEN_OPERAND_MACH)
	& machs)
      selected[init[i].type] = &init[i];
  cd->operand_table.entries = selected;
  cd->operand_table.num_entries = MAX_OPERANDS;
}

/* Subroutine of sun32_cgen_cpu_open to build the hardware table.
   ??? This could leave out insns not supported by the specified mach/isa,
   but that would cause errors like "foo only supported by bar" to become
   "unknown insn", so for now we include all insns and require the app to
   do the checking later.
   ??? On the other hand, parsing of such insns may require their hardware or
   operand elements to be in the table [which they mightn't be].  */

static void
build_insn_table (CGEN_CPU_TABLE *cd)
{
  int i;
  const CGEN_IBASE *ib = & sun32_cgen_insn_table[0];
  CGEN_INSN *insns = xmalloc (MAX_INSNS * sizeof (CGEN_INSN));

  memset (insns, 0, MAX_INSNS * sizeof (CGEN_INSN));
  for (i = 0; i < MAX_INSNS; ++i)
    insns[i].base = &ib[i];
  cd->insn_table.init_entries = insns;
  cd->insn_table.entry_size = sizeof (CGEN_IBASE);
  cd->insn_table.num_init_entries = MAX_INSNS;
}

/* Subroutine of sun32_cgen_cpu_open to rebuild the tables.  */

static void
sun32_cgen_rebuild_tables (CGEN_CPU_TABLE *cd)
{
  int i;
  CGEN_BITSET *isas = cd->isas;
  unsigned int machs = cd->machs;

  cd->int_insn_p = CGEN_INT_INSN_P;

  /* Data derived from the isa spec.  */
#define UNSET (CGEN_SIZE_UNKNOWN + 1)
  cd->default_insn_bitsize = UNSET;
  cd->base_insn_bitsize = UNSET;
  cd->min_insn_bitsize = 65535; /* Some ridiculously big number.  */
  cd->max_insn_bitsize = 0;
  for (i = 0; i < MAX_ISAS; ++i)
    if (cgen_bitset_contains (isas, i))
      {
	const CGEN_ISA *isa = & sun32_cgen_isa_table[i];

	/* Default insn sizes of all selected isas must be
	   equal or we set the result to 0, meaning "unknown".  */
	if (cd->default_insn_bitsize == UNSET)
	  cd->default_insn_bitsize = isa->default_insn_bitsize;
	else if (isa->default_insn_bitsize == cd->default_insn_bitsize)
	  ; /* This is ok.  */
	else
	  cd->default_insn_bitsize = CGEN_SIZE_UNKNOWN;

	/* Base insn sizes of all selected isas must be equal
	   or we set the result to 0, meaning "unknown".  */
	if (cd->base_insn_bitsize == UNSET)
	  cd->base_insn_bitsize = isa->base_insn_bitsize;
	else if (isa->base_insn_bitsize == cd->base_insn_bitsize)
	  ; /* This is ok.  */
	else
	  cd->base_insn_bitsize = CGEN_SIZE_UNKNOWN;

	/* Set min,max insn sizes.  */
	if (isa->min_insn_bitsize < cd->min_insn_bitsize)
	  cd->min_insn_bitsize = isa->min_insn_bitsize;
	if (isa->max_insn_bitsize > cd->max_insn_bitsize)
	  cd->max_insn_bitsize = isa->max_insn_bitsize;
      }

  /* Data derived from the mach spec.  */
  for (i = 0; i < MAX_MACHS; ++i)
    if (((1 << i) & machs) != 0)
      {
	const CGEN_MACH *mach = & sun32_cgen_mach_table[i];

	if (mach->insn_chunk_bitsize != 0)
	{
	  if (cd->insn_chunk_bitsize != 0 && cd->insn_chunk_bitsize != mach->insn_chunk_bitsize)
	    {
	      opcodes_error_handler
		(/* xgettext:c-format */
		 _("internal error: sun32_cgen_rebuild_tables: "
		   "conflicting insn-chunk-bitsize values: `%d' vs. `%d'"),
		 cd->insn_chunk_bitsize, mach->insn_chunk_bitsize);
	      abort ();
	    }

 	  cd->insn_chunk_bitsize = mach->insn_chunk_bitsize;
	}
      }

  /* Determine which hw elements are used by MACH.  */
  build_hw_table (cd);

  /* Build the ifield table.  */
  build_ifield_table (cd);

  /* Determine which operands are used by MACH/ISA.  */
  build_operand_table (cd);

  /* Build the instruction table.  */
  build_insn_table (cd);
}

/* Initialize a cpu table and return a descriptor.
   It's much like opening a file, and must be the first function called.
   The arguments are a set of (type/value) pairs, terminated with
   CGEN_CPU_OPEN_END.

   Currently supported values:
   CGEN_CPU_OPEN_ISAS:    bitmap of values in enum isa_attr
   CGEN_CPU_OPEN_MACHS:   bitmap of values in enum mach_attr
   CGEN_CPU_OPEN_BFDMACH: specify 1 mach using bfd name
   CGEN_CPU_OPEN_ENDIAN:  specify endian choice
   CGEN_CPU_OPEN_END:     terminates arguments

   ??? Simultaneous multiple isas might not make sense, but it's not (yet)
   precluded.  */

CGEN_CPU_DESC
sun32_cgen_cpu_open (enum cgen_cpu_open_arg arg_type, ...)
{
  CGEN_CPU_TABLE *cd = (CGEN_CPU_TABLE *) xmalloc (sizeof (CGEN_CPU_TABLE));
  static int init_p;
  CGEN_BITSET *isas = 0;  /* 0 = "unspecified" */
  unsigned int machs = 0; /* 0 = "unspecified" */
  enum cgen_endian endian = CGEN_ENDIAN_UNKNOWN;
  va_list ap;

  if (! init_p)
    {
      init_tables ();
      init_p = 1;
    }

  memset (cd, 0, sizeof (*cd));

  va_start (ap, arg_type);
  while (arg_type != CGEN_CPU_OPEN_END)
    {
      switch (arg_type)
	{
	case CGEN_CPU_OPEN_ISAS :
	  isas = va_arg (ap, CGEN_BITSET *);
	  break;
	case CGEN_CPU_OPEN_MACHS :
	  machs = va_arg (ap, unsigned int);
	  break;
	case CGEN_CPU_OPEN_BFDMACH :
	  {
	    const char *name = va_arg (ap, const char *);
	    const CGEN_MACH *mach =
	      lookup_mach_via_bfd_name (sun32_cgen_mach_table, name);

	    if (mach != NULL)
	      machs |= 1 << mach->num;
	    break;
	  }
	case CGEN_CPU_OPEN_ENDIAN :
	  endian = va_arg (ap, enum cgen_endian);
	  break;
	default :
	  opcodes_error_handler
	    (/* xgettext:c-format */
	     _("internal error: sun32_cgen_cpu_open: "
	       "unsupported argument `%d'"),
	     arg_type);
	  abort (); /* ??? return NULL? */
	}
      arg_type = va_arg (ap, enum cgen_cpu_open_arg);
    }
  va_end (ap);

  /* Mach unspecified means "all".  */
  if (machs == 0)
    machs = (1 << MAX_MACHS) - 1;
  /* Base mach is always selected.  */
  machs |= 1;
  if (endian == CGEN_ENDIAN_UNKNOWN)
    {
      /* ??? If target has only one, could have a default.  */
      opcodes_error_handler
	(/* xgettext:c-format */
	 _("internal error: sun32_cgen_cpu_open: no endianness specified"));
      abort ();
    }

  cd->isas = cgen_bitset_copy (isas);
  cd->machs = machs;
  cd->endian = endian;
  /* FIXME: for the sparc case we can determine insn-endianness statically.
     The worry here is where both data and insn endian can be independently
     chosen, in which case this function will need another argument.
     Actually, will want to allow for more arguments in the future anyway.  */
  cd->insn_endian = endian;

  /* Table (re)builder.  */
  cd->rebuild_tables = sun32_cgen_rebuild_tables;
  sun32_cgen_rebuild_tables (cd);

  /* Default to not allowing signed overflow.  */
  cd->signed_overflow_ok_p = 0;

  return (CGEN_CPU_DESC) cd;
}

/* Cover fn to sun32_cgen_cpu_open to handle the simple case of 1 isa, 1 mach.
   MACH_NAME is the bfd name of the mach.  */

CGEN_CPU_DESC
sun32_cgen_cpu_open_1 (const char *mach_name, enum cgen_endian endian)
{
  return sun32_cgen_cpu_open (CGEN_CPU_OPEN_BFDMACH, mach_name,
			       CGEN_CPU_OPEN_ENDIAN, endian,
			       CGEN_CPU_OPEN_END);
}

/* Close a cpu table.
   ??? This can live in a machine independent file, but there's currently
   no place to put this file (there's no libcgen).  libopcodes is the wrong
   place as some simulator ports use this but they don't use libopcodes.  */

void
sun32_cgen_cpu_close (CGEN_CPU_DESC cd)
{
  unsigned int i;
  const CGEN_INSN *insns;

  if (cd->macro_insn_table.init_entries)
    {
      insns = cd->macro_insn_table.init_entries;
      for (i = 0; i < cd->macro_insn_table.num_init_entries; ++i, ++insns)
	if (CGEN_INSN_RX ((insns)))
	  regfree (CGEN_INSN_RX (insns));
    }

  if (cd->insn_table.init_entries)
    {
      insns = cd->insn_table.init_entries;
      for (i = 0; i < cd->insn_table.num_init_entries; ++i, ++insns)
	if (CGEN_INSN_RX (insns))
	  regfree (CGEN_INSN_RX (insns));
    }

  if (cd->macro_insn_table.init_entries)
    free ((CGEN_INSN *) cd->macro_insn_table.init_entries);

  if (cd->insn_table.init_entries)
    free ((CGEN_INSN *) cd->insn_table.init_entries);

  if (cd->hw_table.entries)
    free ((CGEN_HW_ENTRY *) cd->hw_table.entries);

  if (cd->operand_table.entries)
    free ((CGEN_HW_ENTRY *) cd->operand_table.entries);

  free (cd);
}

