/* BFD support for SUN32.
   Copyright (C) 2019 Free Software Foundation, Inc.
   Written by koyamanX <ckoyama.1996@gmail.com>
	   References to cpu-cr16.c

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
   along with this program; see the file COPYING3. If not,
   see <http://www.gnu.org/licenses/>.  */


#include "sysdep.h"
#include "bfd.h"
#include "libbfd.h"

const bfd_arch_info_type bfd_sun32_arch =
{
	32,		      /* 32 bits in a word.  */
    32,		      /* 32 bits in an address.  */
    8,		      /*  8 bits in a byte.  */
    bfd_arch_sun32,    /* enum bfd_architecture arch.  */
    bfd_mach_sun32,
    "SUN32",	      /* Arch name.  */
    "SUN32",	      /* Printable name.  */
    2,		      /* Unsigned int section alignment power.  */
    TRUE,	      /* The one and only.  */
    bfd_default_compatible,
    bfd_default_scan,
    bfd_arch_default_fill,
    0,
};
