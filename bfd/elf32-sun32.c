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
	{BFD_RELOC_32,				R_SUN32_32},
	{BFD_RELOC_SUN32_PCREL_25,	R_SUN32_PCREL_25},
	{BFD_RELOC_SUN32_HI_18,		R_SUN32_HI_18},
	{BFD_RELOC_SUN32_LO_14,		R_SUN32_LO_14},
	//{BFD_RELOC_SUN32_ABS_20,	R_SUN32_ABS_20},
};

static reloc_howto_type sun32_elf_howto_table[] = 
{
	HOWTO (R_SUN32_NONE,		/* type */
		0,						/* rightshift */
		2,						/* size */
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
	HOWTO (R_SUN32_32,	   		/* type */
		0,						/* rightshift */
		2,						/* size */
		32,						/* bitsize */
		FALSE,					/* pc_relative */
		0,						/* bitpos */
		complain_overflow_dont,	/* complain_on_overflow */
		bfd_elf_generic_reloc,	/* special_function */
		"R_SUN32_32",			/* name */
		FALSE,					/* partial_inplace */
		0x00000000,				/* src_mask */
		0xffffffff,				/* dst_mask */
		FALSE),					/* pcrel_offset */
	HOWTO (R_SUN32_PCREL_25,	/* type */
		2,						/* rightshift */
		2,						/* size */
		25,						/* bitsize */
		TRUE,					/* pc_relative */
		0,						/* bitpos */
		complain_overflow_signed,	/* complain_on_overflow */
		bfd_elf_generic_reloc,	/* special_function */
		"R_SUN32_PCREL_25",		/* name */
		FALSE,					/* partial_inplace */
		0x00000000,				/* src_mask */
		0x01ffffff,				/* dst_mask */
		TRUE),					/* pcrel_offset */
	HOWTO (R_SUN32_HI_18,		/* type */
		14,						/* rightshift */
		2,						/* size */
		18,						/* bitsize */
		FALSE,					/* pc_relative */
		0,						/* bitpos */
		complain_overflow_signed,	/* complain_on_overflow */
		bfd_elf_generic_reloc,	/* special_function */
		"R_SUN32_HI_18",		/* name */
		FALSE,					/* partial_inplace */
		0x00000000,				/* src_mask */
		0x0003ffff,				/* dst_mask */
		FALSE),					/* pcrel_offset */
	HOWTO (R_SUN32_LO_14,		/* type */
		0,						/* rightshift */
		2,						/* size */
		14,						/* bitsize */
		FALSE,					/* pc_relative */
		0,						/* bitpos */
		complain_overflow_signed,	/* complain_on_overflow */
		bfd_elf_generic_reloc,	/* special_function */
		"R_SUN32_LO_14",		/* name */
		FALSE,					/* partial_inplace */
		0x00000000,				/* src_mask */
		0x00003fff,				/* dst_mask */
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
  
static bfd_boolean
sun32_elf_check_relocs (bfd *abfd, 
				struct bfd_link_info *info,
				asection *sec,
				const Elf_Internal_Rela *relocs)
{
  Elf_Internal_Shdr *symtab_hdr;
  struct elf_link_hash_entry **sym_hashes;
  const Elf_Internal_Rela *rel;
  const Elf_Internal_Rela *rel_end;

  if (bfd_link_relocatable (info))
    return TRUE;

  symtab_hdr = &elf_tdata (abfd)->symtab_hdr;
  sym_hashes = elf_sym_hashes (abfd);

  rel_end = relocs + sec->reloc_count;
  for (rel = relocs; rel < rel_end; rel++)
    {
      struct elf_link_hash_entry *h;
      unsigned long r_symndx;

      r_symndx = ELF32_R_SYM (rel->r_info);
      if (r_symndx < symtab_hdr->sh_info)
        h = NULL;
      else
	{
	  h = sym_hashes[r_symndx - symtab_hdr->sh_info];
	  while (h->root.type == bfd_link_hash_indirect
		 || h->root.type == bfd_link_hash_warning)
	    h = (struct elf_link_hash_entry *) h->root.u.i.link;
	}
    }

  return TRUE;
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
			      struct elf_link_hash_entry * h ATTRIBUTE_UNUSED,
			      unsigned long symndx  ATTRIBUTE_UNUSED,
			      struct bfd_link_info *info ATTRIBUTE_UNUSED,
			      asection *sec ATTRIBUTE_UNUSED,
			      int is_local ATTRIBUTE_UNUSED)
{
	bfd_reloc_status_type r = bfd_reloc_ok;
	bfd_vma x;
	switch(howto->type) {
		case R_SUN32_HI_18:
		case R_SUN32_LO_14:
			contents += offset;
			Rvalue += addend;
			Rvalue = (Rvalue >> howto->rightshift) & howto->dst_mask;
			x = bfd_get_32 (input_bfd, contents);
			x = (x & ~howto->dst_mask) | Rvalue;
			bfd_put_32 (input_bfd, x, contents);
			break;
		default:
			r = _bfd_final_link_relocate (howto, input_bfd, input_section,
			contents, offset,
			Rvalue, addend);
			break;
	}

	return r;
}

/* Relocate a SUN32 ELF section.  */

static bfd_boolean
elf32_sun32_relocate_section (bfd *output_bfd, struct bfd_link_info *info,
			     bfd *input_bfd, asection *input_section,
			     bfd_byte *contents, Elf_Internal_Rela *relocs,
			     Elf_Internal_Sym *local_syms,
			     asection **local_sections)
{
  Elf_Internal_Shdr *symtab_hdr;
  struct elf_link_hash_entry **sym_hashes;
  Elf_Internal_Rela *rel, *relend;

  symtab_hdr = &elf_tdata (input_bfd)->symtab_hdr;
  sym_hashes = elf_sym_hashes (input_bfd);

  rel = relocs;
  relend = relocs + input_section->reloc_count;
  for (; rel < relend; rel++)
    {
      int r_type;
      reloc_howto_type *howto;
      unsigned long r_symndx;
      Elf_Internal_Sym *sym;
      asection *sec;
      struct elf_link_hash_entry *h;
      bfd_vma relocation;
      bfd_reloc_status_type r;

      r_symndx = ELF32_R_SYM (rel->r_info);
      r_type = ELF32_R_TYPE (rel->r_info);
      howto = sun32_elf_howto_table + (r_type);

      h = NULL;
      sym = NULL;
      sec = NULL;
      if (r_symndx < symtab_hdr->sh_info)
	{
	  sym = local_syms + r_symndx;
	  sec = local_sections[r_symndx];
	  relocation = _bfd_elf_rela_local_sym (output_bfd, sym, &sec, rel);
	}
      else
	{
	  bfd_boolean unresolved_reloc, warned, ignored;

	  RELOC_FOR_GLOBAL_SYMBOL (info, input_bfd, input_section, rel,
				   r_symndx, symtab_hdr, sym_hashes,
				   h, sec, relocation,
				   unresolved_reloc, warned, ignored);
	}

      if (sec != NULL && discarded_section (sec))
	RELOC_AGAINST_DISCARDED_SECTION (info, input_bfd, input_section,
					 rel, 1, relend, howto, 0, contents);

      if (bfd_link_relocatable (info))
	continue;

      r = sun32_elf_final_link_relocate (howto, input_bfd, output_bfd,
					input_section,
					contents, rel->r_offset,
					relocation, rel->r_addend,
					(struct elf_link_hash_entry *) h,
					r_symndx,
					info, sec, h == NULL);

      if (r != bfd_reloc_ok)
	{
	  const char *name;
	  const char *msg = NULL;

	  if (h != NULL)
	    name = h->root.root.string;
	  else
	    {
	      name = (bfd_elf_string_from_elf_section
		      (input_bfd, symtab_hdr->sh_link, sym->st_name));
	      if (name == NULL || *name == '\0')
		name = bfd_section_name (input_bfd, sec);
	    }

	  switch (r)
	    {
	     case bfd_reloc_overflow:
	       (*info->callbacks->reloc_overflow)
		 (info, (h ? &h->root : NULL), name, howto->name,
		  (bfd_vma) 0, input_bfd, input_section, rel->r_offset);
	       break;

	     case bfd_reloc_undefined:
	       (*info->callbacks->undefined_symbol)
		 (info, name, input_bfd, input_section, rel->r_offset, TRUE);
	       break;

	     case bfd_reloc_outofrange:
	       msg = _("internal error: out of range error");
	       goto common_error;

	     case bfd_reloc_notsupported:
	       msg = _("internal error: unsupported relocation error");
	       goto common_error;

	     case bfd_reloc_dangerous:
	       msg = _("internal error: dangerous error");
	       goto common_error;

	     default:
	       msg = _("internal error: unknown error");
	       /* Fall through.  */

	     common_error:
	       (*info->callbacks->warning) (info, msg, name, input_bfd,
					    input_section, rel->r_offset);
		   	return FALSE;
	    }
	}
    }

  return TRUE;
}

static asection *
sun32_elf_gc_mark_hook (asection *sec,
			 struct bfd_link_info *info,
			 Elf_Internal_Rela *rel,
			 struct elf_link_hash_entry *h,
			 Elf_Internal_Sym *sym)
{
  return _bfd_elf_gc_mark_hook (sec, info, rel, h, sym);
}


#define TARGET_BIG_SYM		  sun32_elf32_vec
#define TARGET_BIG_NAME		  "elf32-sun32"
#define ELF_ARCH				  bfd_arch_sun32
#define ELF_MACHINE_CODE		  EM_SUN32
#define ELF_MAXPAGESIZE			  0x1
#define elf_symbol_leading_char		  '_'

#define elf_backend_gc_mark_hook        sun32_elf_gc_mark_hook
#define elf_backend_can_gc_sections	1
#define elf_backend_rela_normal	  1
#define elf_info_to_howto_rel	  NULL
#define elf_info_to_howto		sun32_info_to_howto_rela

#define bfd_elf32_bfd_reloc_type_lookup	elf_sun32_reloc_type_lookup
#define bfd_elf32_bfd_reloc_name_lookup	elf_sun32_reloc_name_lookup
#define elf_backend_check_relocs		sun32_elf_check_relocs
#define elf_backend_relocate_section	elf32_sun32_relocate_section

#include "elf32-target.h"


 
