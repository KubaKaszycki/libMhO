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

#define __LIBMHO_INTERNAL // Suppress warnings
#include <libmho/magic.h>
#undef __LIBMHO_INTERNAL

bool	mho_endian_checked;
bool	mho_endian_little;

bool
mho_bytecmp(uint32_t i1, uint32_t i2)
{
	return (i1 & 0xFF) == (i2 & 0xFF) && (i1 & 0xFF00) == (i2 & 0xFF00) && (i1 & 0xFF0000) == (i2 & 0xFF0000) && (i1 & 0xFF000000) == (i2 & 0xFF000000);
}

void
mho_check_endian()
{
	if (mho_endian_checked)
		return;
	mho_endian_checked = true;
	uint16_t	i1 = 0xAB;
	uint16_t	i2 = 0xCD;
	mho_endian_little = mho_bytecmp(0xABCD, (i1 << 8) | i2);
}

bool
mho_host_bigendian()
{
	mho_check_endian();
	return mho_endian_little;
}

bool
mho_host_littleendian()
{
	mho_check_endian();
	return !mho_endian_little;
}

bool
mho_is_magic(uint32_t number)
{
	return number == MHO_MAGIC || number == MHO_CIGAM || number == MHO_MAGIC64 || number == MHO_CIGAM64 || number == MHO_MAGIC_FAT || number == MHO_CIGAM_FAT;
}

bool
mho_magic_64(uint32_t number)
{
	if (!mho_is_magic(number))
		return false;
	return number == MHO_MAGIC64 || number == MHO_CIGAM64;
}

bool 
mho_magic_fat(uint32_t number)
{
	if (!mho_is_magic(number)) {
		return false;
	}
	return number == MHO_MAGIC_FAT || number == MHO_CIGAM_FAT;
}

bool
mho_magic_littleendian(uint32_t number)
{
	if (!mho_is_magic(number))
		return false;
	if (mho_host_littleendian()) {
		return mho_bytecmp(number, MHO_MAGIC) || mho_bytecmp(number, MHO_MAGIC64) || mho_bytecmp(number, MHO_MAGIC_FAT);
	}
	return mho_bytecmp(number, MHO_CIGAM) || mho_bytecmp(number, MHO_CIGAM64) || mho_bytecmp(number, MHO_CIGAM_FAT);
}
