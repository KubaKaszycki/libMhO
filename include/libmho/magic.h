/*
 * Copyright (c) 2016 Jakub Kaszycki
 * This file is part of libMhO.
 * 
 * LibMhO is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 * 
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libmho/types.h>
#include <stdbool.h>

#ifndef _LIBMHO_MAGIC_H
#define _LIBMHO_MAGIC_H

#define MHO_MAGIC 0xFEEDFACEL
#define MHO_MAGIC_B0 ((MHO_MAGIC & 0xFF000000) >> 24)
#define MHO_MAGIC_B1 ((MHO_MAGIC & 0x00FF0000) >> 16)
#define MHO_MAGIC_B2 ((MHO_MAGIC & 0x0000FF00) >> 8)
#define MHO_MAGIC_B3 (MHO_MAGIC & 0x000000FF)
#define MHO_MAGIC64 0xFEEDFACFL
#define MHO_MAGIC64_B0 ((MHO_MAGIC64 & 0xFF000000) >> 24)
#define MHO_MAGIC64_B1 ((MHO_MAGIC64 & 0x00FF0000) >> 16)
#define MHO_MAGIC64_B2 ((MHO_MAGIC64 & 0x0000FF00) >> 8)
#define MHO_MAGIC64_B3 (MHO_MAGIC64 & 0x000000FF)
#define MHO_MAGIC_FAT 0xCAFEBABEL
#define MHO_MAGIC_FAT_B0 ((MHO_MAGIC_FAT & 0xFF000000) >> 24)
#define MHO_MAGIC_FAT_B1 ((MHO_MAGIC_FAT & 0x00FF0000) >> 16)
#define MHO_MAGIC_FAT_B2 ((MHO_MAGIC_FAT & 0x0000FF00) >> 8)
#define MHO_MAGIC_FAT_B3 (MHO_MAGIC_FAT & 0x000000FF)
#define MHO_CIGAM 0xCEFAEDFEL
#define MHO_CIGAM_B0 ((MHO_CIGAM & 0xFF000000) >> 24)
#define MHO_CIGAM_B1 ((MHO_CIGAM & 0x00FF0000) >> 16)
#define MHO_CIGAM_B2 ((MHO_CIGAM & 0x0000FF00) >> 8)
#define MHO_CIGAM_B3 (MHO_CIGAM & 0x000000FF)
#define MHO_CIGAM64 0xCFFAEDFEL
#define MHO_CIGAM64_B0 ((MHO_CIGAM64 & 0xFF000000) >> 24)
#define MHO_CIGAM64_B1 ((MHO_CIGAM64 & 0x00FF0000) >> 16)
#define MHO_CIGAM64_B2 ((MHO_CIGAM64 & 0x0000FF00) >> 8)
#define MHO_CIGAM64_B3 (MHO_CIGAM64 & 0x000000FF)
#define MHO_CIGAM_FAT 0xBEBAFECAL
#define MHO_CIGAM_FAT_B0 ((MHO_CIGAM_FAT & 0xFF000000) >> 24)
#define MHO_CIGAM_FAT_B1 ((MHO_CIGAM_FAT & 0x00FF0000) >> 16)
#define MHO_CIGAM_FAT_B2 ((MHO_CIGAM_FAT & 0x0000FF00) >> 8)
#define MHO_CIGAM_FAT_B3 (MHO_CIGAM_FAT & 0x000000FF)

#ifdef __LIBMHO_INTERNAL
#define __LIBMHO_MAGIC_H_INTERNAL_ROUTINE
#else
#define __LIBMHO_MAGIC_H_INTERNAL_ROUTINE __attribute__((deprecated("Internal routine")))
#endif

__LIBMHO_MAGIC_H_INTERNAL_ROUTINE extern bool mho_endian_checked;
__LIBMHO_MAGIC_H_INTERNAL_ROUTINE extern bool mho_endian_little;

bool		mho_is_magic(uint32_t number);
bool		mho_magic_64(uint32_t number);
bool		mho_magic_fat(uint32_t number);
bool		mho_magic_littleendian(uint32_t number);
bool		mho_magic_bigendian(uint32_t number);
void		mho_check_endian();
bool		mho_host_littleendian();
bool		mho_host_bigendian();

#endif
