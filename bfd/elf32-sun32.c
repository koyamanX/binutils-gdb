/* 32-bit ELF support for SUN32
   Copyright (C) 2019 Free Software Foundation, Inc.

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
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#include "sysdep.h"
#include "bfd.h"
#include "bfdlink.h"
#include "libbfd.h"
#include "libiberty.h"
#include "elf-bfd.h"
#include "elf/sun32.h"

/* sun32_reloc_map array maps BFD relocation enum into a CRGAS relocation type.  */

struct sun32_reloc_map
{
  bfd_reloc_code_real_type bfd_reloc_enum; /* BFD relocation enum.  */
  unsigned short sun32_reloc_type;	   /* SUN32 relocation type.  */
};

static const struct sun32_reloc_map sun32_reloc_map[R_SUN32_max] = 
{
	{BFD_RELOC_NONE,			R_SUN32_NONE},
};

static reloc_howto_type sun32_elf_howto_table[] = 
{
	HOWTO (R_SUN32_NONE,		/* type */
		0,						/* rightshift */
		3,						/* size */
		0,						/* bitsize */
		FALSE,					/* pc_relative */
		0,						/* bitpos */
		complain_overflow_dont,	/* complain_on_overflow */
		bfd_elf_generic_reloc,	/* special_function */
		"R_SUN32_NONE",			/* name */
		FALSE,					/* partial_inplace */
		0,						/* src_mask */
		0,						/* dst_mask */
		FALSE),					/* pcrel_offset */
};

/* Retrieve a howto ptr using a BFD reloc_code. */

/* determine relocaiton type */
static reloc_howto_type *
elf_sun32_reloc_type_lookup (bfd *abfd,
								bfd_reloc_code_real_type code)
{
	unsigned int i;

	for (i = 0; i < R_SUN32_max; i++) {
		if(code == sun32_reloc_map[i].bfd_reloc_enum)
			return &sun32_elf_howto_table[sun32_reloc_map[i].sun32_reloc_type];
	}
	_bfd_error_handler (_("%pB: unsupported relocation type %#x"),
		abfd, code);
	return NULL;
}

/* determine relocation name */
static reloc_howto_type *
elf_sun32_reloc_name_lookup (bfd *abfd ATTRIBUTE_UNUSED,
								const char *r_name)
{
	unsigned int i;

	for (i = 0; ARRAY_SIZE (sun32_elf_howto_table); i++)
		if(sun32_elf_howto_table[i].name != NULL
			&& strcasecmp (sun32_elf_howto_table[i].name, r_name) == 0)
				return &sun32_elf_howto_table[i];
	return NULL;
}

static bfd_boolean 
sun32_info_to_howto_rela (bfd *abfd ATTRIBUTE_UNUSED,
			   arelent *cache_ptr,
			   Elf_Internal_Rela *dst)
{
  unsigned int r_type;

  r_type = ELF32_R_TYPE (dst->r_info);
  BFD_ASSERT (r_type < (unsigned int) R_SUN32_max);
  cache_ptr->howto = & sun32_elf_howto_table [r_type];

  return TRUE;
}


/*
static bfd_boolean
sun32_elf_check_relocs (bfd *abfd, struct bfd_link_info *info, asection *sec,
		       const Elf_Internal_Rela *relocs)
{
	return 0;
}

static bfd_reloc_status_type
sun32_elf_final_link_relocate (reloc_howto_type *howto,
			      bfd *input_bfd,
			      bfd *output_bfd ATTRIBUTE_UNUSED,
			      asection *input_section,
			      bfd_byte *contents,
			      bfd_vma offset,
			      bfd_vma Rvalue,
			      bfd_vma addend,
			      struct elf_link_hash_entry * h,
			      unsigned long symndx  ATTRIBUTE_UNUSED,
			      struct bfd_link_info *info ATTRIBUTE_UNUSED,
			      asection *sec ATTRIBUTE_UNUSED,
			      int is_local ATTRIBUTE_UNUSED)
{
}

static bfd_boolean
elf32_sun32_relocate_section (bfd *output_bfd, struct bfd_link_info *info,
			     bfd *input_bfd, asection *input_section,
			     bfd_byte *contents, Elf_Internal_Rela *relocs,
			     Elf_Internal_Sym *local_syms,
			     asection **local_sections)
{
}
*/

#define TARGET_BIG_SYM		  sun32_elf32_vec
#define TARGET_BIG_NAME		  "elf32-sun32"
#define ELF_ARCH				  bfd_arch_sun32
#define ELF_MACHINE_CODE		  EM_SUN32
#define ELF_MAXPAGESIZE			  0x1
#define elf_symbol_leading_char		  '_'

#define elf_backend_rela_normal	  1
#define elf_info_to_howto_rel	  NULL
#define elf_info_to_howto		sun32_info_to_howto_rela

#define bfd_elf32_bfd_reloc_type_lookup	elf_sun32_reloc_type_lookup
#define bfd_elf32_bfd_reloc_name_lookup	elf_sun32_reloc_name_lookup
/*
#define elf_backend_check_relocs		sun32_elf_check_relocs
#define elf_backend_relocate_section	elf32_sun32_relocate_section
*/

#include "elf32-target.h"


 
