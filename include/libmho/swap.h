/*
 * Copyright (c) 2016 Jakub Kaszycki This file is part of libMhO.
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

#include <sys/types.h>
#include <stdint.h>
#include <inttypes.h>

#ifndef _LIBMHO_SWAP_H
#define _LIBMHO_SWAP_H

void           *mho_swap_copy(const void *memory, const size_t size);
void		mho_swap  (void *memory, const size_t size);

uint8_t		mho_swap8(uint8_t number);
uint16_t	mho_swap16(uint16_t number);
uint32_t	mho_swap32(uint32_t number);
uint64_t	mho_swap64(uint64_t number);

#endif
