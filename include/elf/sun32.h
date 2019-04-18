/* SUN32 ELF support for BFD.
   Copyright (C) 2019 Free Software Foundation, Inc.
   Written By CKoyama <ckoyama.1996@gmail.com>   

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
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */

#ifndef _ELF_SUN32_H
#define _ELF_SUN32_H

#include "elf/reloc-macros.h"

/* Creating indices for reloc_map_index array.  */
START_RELOC_NUMBERS(elf_sun32_reloc_type)
  RELOC_NUMBER (R_SUN32_NONE,           0)
  RELOC_NUMBER (R_SUN32_32,             1)
  RELOC_NUMBER (R_SUN32_PCREL_25,       2)
  RELOC_NUMBER (R_SUN32_HI_18,       3)
  RELOC_NUMBER (R_SUN32_LO_14,       4)
END_RELOC_NUMBERS(R_SUN32_max)
#endif
