
/* BFD support for the Hexagon processor
   Copyright 1994, 1995, 1997, 2001, 2002 Free Software Foundation, Inc.
   Contributed by Doug Evans (dje@cygnus.com).

This file is part of BFD, the Binary File Descriptor library.

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

#include "bfd.h"
#include "sysdep.h"
#include "libbfd.h"

static const bfd_arch_info_type *hexagon_bfd_compatible
  (const bfd_arch_info_type *a, const bfd_arch_info_type *b);

#define HEXAGON_ARCH_INFO(MACH, ARCH, NAME, DEFAULT, NEXT) \
  {					 \
    32,	/* 32 bits in a word  */	 \
    32,	/* 32 bits in an address  */	 \
    8,	/* 8 bits in a byte  */		 \
    bfd_arch_hexagon,			 \
    MACH,				 \
    ARCH,				 \
    NAME,				 \
    4, /* section alignment power  */	 \
    DEFAULT,				 \
    hexagon_bfd_compatible,		 \
    bfd_default_scan,			 \
    NEXT,				 \
  }

static const bfd_arch_info_type hexagon_arch_info[] = {
  /* These are the other supported ISAs. */
  HEXAGON_ARCH_INFO (bfd_mach_hexagon_v2, "qdsp6", "qdsp6v2", TRUE,
		     hexagon_arch_info + 1),
  HEXAGON_ARCH_INFO (bfd_mach_hexagon_v3, "hexagon", "hexagonv3", FALSE,
		     hexagon_arch_info + 2),
  HEXAGON_ARCH_INFO (bfd_mach_hexagon_v3, "qdsp6", "qdsp6v3", FALSE,
		     hexagon_arch_info + 3),
  HEXAGON_ARCH_INFO (bfd_mach_hexagon_v4, "hexagon", "hexagonv4", FALSE,
		     hexagon_arch_info + 4),
  HEXAGON_ARCH_INFO (bfd_mach_hexagon_v4, "qdsp6", "qdsp6v4", FALSE,
		     hexagon_arch_info + 5),
  HEXAGON_ARCH_INFO (bfd_mach_hexagon_v5, "hexagon", "hexagonv5", FALSE,
		     hexagon_arch_info + 6),
  HEXAGON_ARCH_INFO (bfd_mach_hexagon_v55, "hexagon", "hexagonv55", FALSE,
		     NULL),
};

/* This is the default ISA. */
const bfd_arch_info_type bfd_hexagon_arch =
HEXAGON_ARCH_INFO (bfd_mach_hexagon_v4, "hexagon", "hexagonv4", TRUE,
		   hexagon_arch_info + 0);

/* Utility routines.  */
int hexagon_get_mach (char *);

/** Given CPU type, return its bfd_mach_hexagon* value.

@param name CPU type.
@return bfd_mach_hexagon* value if successful or -1 otherwise.
*/
int
hexagon_get_mach (char *name)
{
  const bfd_arch_info_type *p;

  for (p = &bfd_hexagon_arch; p != NULL; p = p->next)
    if (!strcmp (name, p->printable_name))
      return p->mach;

  return -1;
}

static const bfd_arch_info_type *
hexagon_bfd_compatible (const bfd_arch_info_type *a,
			const bfd_arch_info_type *b)
{
  if (a->arch != bfd_arch_hexagon || b->arch != bfd_arch_hexagon)
    return NULL;

  /* The V2 ABI was superseded by the V3 ABI. */
  if ((a->mach == bfd_mach_hexagon_v2 || b->mach == bfd_mach_hexagon_v2)
      && a->mach != b->mach)
    return NULL;

  /* Return the most recent one. */
  return a->mach > b->mach ? a : b;
}
