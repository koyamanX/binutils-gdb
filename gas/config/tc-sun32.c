/* 
   Copyright 2011
   Free Software Foundation. Inc.

   This file is part of GAS, the GNU Assembler.

   GAS is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GAS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GAS; see the file COPYING.  If not, write to
   the Free Software Foundation, 51 Franklin Street - Fifth Floor,
   Boston, MA 02110-1301, USA.  */

#include "as.h"
#include "subsegs.h"     
#include "symcat.h"
#include "opcodes/sun32-desc.h"
#include "opcodes/sun32-opc.h"
#include "cgen.h"

typedef struct sun32_insn sun32_insn;

struct sun32_insn
{
  const CGEN_INSN *	insn;
  const CGEN_INSN *	orig_insn;
  CGEN_FIELDS		fields;
#if CGEN_INT_INSN_P
  CGEN_INSN_INT         buffer [1];
#define INSN_VALUE(buf) (*(buf))
#else
  unsigned char         buffer [CGEN_MAX_INSN_SIZE];
#define INSN_VALUE(buf) (buf)
#endif
  char *		addr;
  fragS *		frag;
  int                   num_fixups;
  fixS *                fixups [GAS_CGEN_MAX_FIXUPS];
  int                   indices [MAX_OPERAND_INSTANCES];
};

const char comment_chars[]        = ";";
const char line_comment_chars[]   = "#;";
const char line_separator_chars[] = "!";
const char EXP_CHARS[]            = "eE";
const char FLT_CHARS[]            = "RrFf";

/* options */
const char *md_shortopts = "";

struct option md_longopts[] = {
  {NULL, no_argument, NULL, 0}
};
size_t md_longopts_size = sizeof (md_longopts);

unsigned long sun32_machine = 0; /* default */

int
md_parse_option (int c ATTRIBUTE_UNUSED, const char * arg ATTRIBUTE_UNUSED)
{
  return 0;
}

void
md_show_usage (FILE * stream ATTRIBUTE_UNUSED)
{
}

/* support pseudo-opts */
const pseudo_typeS md_pseudo_table[] =
{
  { NULL, 	NULL, 		0 }
};
void
md_begin (void)
{
  /* Initialize the `cgen' interface.  */

  /* Set the machine number and endian.  */
  gas_cgen_cpu_desc = sun32_cgen_cpu_open (CGEN_CPU_OPEN_MACHS, 0,
					    CGEN_CPU_OPEN_ENDIAN,
					    CGEN_ENDIAN_BIG,
					    CGEN_CPU_OPEN_END);

  sun32_cgen_init_asm (gas_cgen_cpu_desc);

  /* This is a callback from cgen to gas to parse operands.  */
  cgen_set_parse_operand_fn (gas_cgen_cpu_desc, gas_cgen_parse_operand);
}

void
md_assemble (char *str)
{
  sun32_insn insn;
  char *errmsg;
  
  /* Initialize GAS's cgen interface for a new instruction.  */
  gas_cgen_init_parse ();
  
  insn.insn = sun32_cgen_assemble_insn
    (gas_cgen_cpu_desc, str, & insn.fields, insn.buffer, &errmsg);
  
  if (!insn.insn)
    {
      as_bad ("%s", errmsg);
      return;
    }
  
  /* Doesn't really matter what we pass for RELAX_P here.  */
  gas_cgen_finish_insn (insn.insn, insn.buffer,
			CGEN_FIELDS_BITSIZE (& insn.fields), 1, NULL);
}

/* The syntax in the manual says constants begin with '#'.
   We just ignore it.  */

void 
md_operand (expressionS *expressionP)
{
  if (* input_line_pointer == '#')
    {
      input_line_pointer ++;
      expression (expressionP);
    }
}

valueT
md_section_align (segT segment, valueT size)
{
  int align = bfd_get_section_alignment (stdoutput, segment);
  return ((size + (1 << align) - 1) & ((unsigned)-1 << align));
}

symbolS *
md_undefined_symbol (char *name ATTRIBUTE_UNUSED)
{
  return NULL;
}

/* Interface to relax_segment.  */
int
md_estimate_size_before_relax (fragS *fragP ATTRIBUTE_UNUSED, segT segment ATTRIBUTE_UNUSED)
{
  /* No assembler relaxation is defined (or necessary) for this port.  */
  abort ();
} 

void
md_convert_frag (bfd *   abfd ATTRIBUTE_UNUSED,
		 segT    sec ATTRIBUTE_UNUSED,
		 fragS * fragP ATTRIBUTE_UNUSED)
{
  /* No assembler relaxation is defined (or necessary) for this port.  */
  abort ();
}


/* Functions concerning relocs.  */

/* The location from which a PC relative jump should be calculated,
   given a PC relative reloc. */

long
md_pcrel_from_section (fixS * fixP, segT sec ATTRIBUTE_UNUSED)
{
  
  return (fixP->fx_frag->fr_address + fixP->fx_where);
}

/* Return the bfd reloc type for OPERAND of INSN at fixup FIXP.
   Returns BFD_RELOC_NONE if no reloc type can be found.
   *FIXP may be modified if desired. */
#include <stdio.h>
bfd_reloc_code_real_type
md_cgen_lookup_reloc (const CGEN_INSN *    insn ATTRIBUTE_UNUSED,
		      const CGEN_OPERAND * operand,
		      fixS *               fixP)
{
	fixP->fx_pcrel = 0;

	switch (operand->type)
	{
		case SUN32_OPERAND_T25:
			fixP->fx_pcrel = 1;
			return BFD_RELOC_SUN32_PCREL_25;
		case SUN32_OPERAND_HI18:
			return BFD_RELOC_SUN32_HI_18;
		case SUN32_OPERAND_LO14:
			return BFD_RELOC_SUN32_LO_14;
			/*
		case SUN32_OPERAND_T20:
			return BFD_RELOC_SUN32_ABS_20;
			*/
		default : /* Avoid -Wall warning.  */
			break;
    }
	return BFD_RELOC_NONE;
}

/* Write a value out to the object file, using the appropriate endianness.  */

void
md_number_to_chars (char * buf, valueT val, int n)
{
  number_to_chars_bigendian (buf, val, n);
}

/* Turn a string in input_line_pointer into a floating point constant of type
   type, and store the appropriate bytes in *litP.  The number of LITTLENUMS
   emitted is stored in *sizeP .  An error message is returned, or NULL on OK.
*/

/* Equal to MAX_PRECISION in atof-ieee.c.  */
#define MAX_LITTLENUMS 6

const char *
md_atof (int type, char *litP, int *sizeP)
{
  return ieee_md_atof (type, litP, sizeP, TRUE);
}

