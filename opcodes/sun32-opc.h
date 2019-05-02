/* DO NOT EDIT!  -*- buffer-read-only: t -*- vi:set ro:  */
/* Instruction opcode header for sun32.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 1996-2018 Free Software Foundation, Inc.

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

#ifndef SUN32_OPC_H
#define SUN32_OPC_H

#ifdef __cplusplus
extern "C" {
#endif

/* -- opc.h */
/* -- */
/* Enum declaration for sun32 instruction types.  */
typedef enum cgen_insn_type {
  SUN32_INSN_INVALID, SUN32_INSN_LDA_HI, SUN32_INSN_LDA_LO, SUN32_INSN_RET
 , SUN32_INSN_RETI, SUN32_INSN_ADD, SUN32_INSN_SUB, SUN32_INSN_SLL
 , SUN32_INSN_SRL, SUN32_INSN_SRA, SUN32_INSN_XOR, SUN32_INSN_OR
 , SUN32_INSN_AND, SUN32_INSN_MULT, SUN32_INSN_REM, SUN32_INSN_REMU
 , SUN32_INSN_DIV, SUN32_INSN_DIVU, SUN32_INSN_CMP, SUN32_INSN_ADDI
 , SUN32_INSN_SUBI, SUN32_INSN_SLLI, SUN32_INSN_SRLI, SUN32_INSN_SRAI
 , SUN32_INSN_XORI, SUN32_INSN_ORI, SUN32_INSN_ANDI, SUN32_INSN_MULTI
 , SUN32_INSN_REMI, SUN32_INSN_REMUI, SUN32_INSN_DIVI, SUN32_INSN_DIVUI
 , SUN32_INSN_CMPI, SUN32_INSN_LUI, SUN32_INSN_LW, SUN32_INSN_LH
 , SUN32_INSN_LB, SUN32_INSN_SW, SUN32_INSN_SH, SUN32_INSN_SB
 , SUN32_INSN_BNEPC, SUN32_INSN_BEQPC, SUN32_INSN_BGTPC, SUN32_INSN_BGEPC
 , SUN32_INSN_BLTPC, SUN32_INSN_BLEPC, SUN32_INSN_BPC, SUN32_INSN_BULTPC
 , SUN32_INSN_BULEPC, SUN32_INSN_BUGTPC, SUN32_INSN_BUGEPC, SUN32_INSN_CALLPC
 , SUN32_INSN_BNEREG, SUN32_INSN_BEQREG, SUN32_INSN_BGTREG, SUN32_INSN_BGEREG
 , SUN32_INSN_BLTREG, SUN32_INSN_BLEREG, SUN32_INSN_BREG, SUN32_INSN_BULTREG
 , SUN32_INSN_BULEREG, SUN32_INSN_BUGTREG, SUN32_INSN_BUGEREG, SUN32_INSN_CALLREG
} CGEN_INSN_TYPE;

/* Index of `invalid' insn place holder.  */
#define CGEN_INSN_INVALID SUN32_INSN_INVALID

/* Total number of insns in table.  */
#define MAX_INSNS ((int) SUN32_INSN_CALLREG + 1)

/* This struct records data prior to insertion or after extraction.  */
struct cgen_fields
{
  int length;
  long f_nil;
  long f_anyof;
  long f_type;
  long f_op;
  long f_rd;
  long f_ra;
  long f_rb;
  long f_x;
  long f_xxxh;
  long f_xxxl;
  long f_xxxt25;
  long f_sft;
  long f_a;
  long f_s;
  long f_u;
  long f_mems;
  long f_mem;
  long f_u18;
  long f_u14;
  long f_u20;
  long f_i15;
  long f_mode;
  long f_cond;
  long f_t25p;
  long f_t20r;
};

#define CGEN_INIT_PARSE(od) \
{\
}
#define CGEN_INIT_INSERT(od) \
{\
}
#define CGEN_INIT_EXTRACT(od) \
{\
}
#define CGEN_INIT_PRINT(od) \
{\
}


   #ifdef __cplusplus
   }
   #endif

#endif /* SUN32_OPC_H */
