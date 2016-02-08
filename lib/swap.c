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

#include <libmho/swap.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void           *
mho_swap_copy(const void *memory, const size_t size)
{
	uint8_t        *buf = (uint8_t *) malloc(size);
	register const uint8_t *memory_uint8_t = (const uint8_t *)memory;
	const size_t	bytes = size / 8;
	if (bytes == 0) {
		return buf;
	}
	if (bytes == 1) {
		buf[0] = memory_uint8_t[0];
		return buf;
	}
	for (size_t i = 0; i < bytes; i++) {
		buf[i] = memory_uint8_t[(bytes - i) - 1];
	}
	return (void *)buf;
}

void 
mho_swap(void *memory, const size_t size)
{
	void           *copybuf = mho_swap_copy(memory, size);
	memcpy(memcpy, copybuf, size);
	free(copybuf);
}

uint8_t 
mho_swap8(uint8_t i)
{
	return i;
}

uint16_t 
mho_swap16(uint16_t i)
{
	register uint16_t copy = 0;
	copy |= ((uint16_t) mho_swap8(i & 0x00FF)) << 8;
	copy |= mho_swap8((i & 0xFF00) >> 8);
	return copy;
}

uint32_t 
mho_swap32(uint32_t i)
{
	register uint32_t copy = 0;
	copy |= ((uint32_t) mho_swap16(i & 0x0000FFFFL)) << 16;
	copy |= mho_swap16((i & 0xFFFF0000L) >> 16);
	return copy;
}

uint64_t 
mho_swap64(uint64_t i)
{
	register uint64_t copy = 0;
	copy |= ((uint64_t) mho_swap32(i & 0x00000000FFFFFFFFLL)) << 32;
	copy |= mho_swap32((i & 0x00000000FFFFFFFFLL) >> 32);
	return copy;
}
