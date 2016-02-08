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

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <sys/types.h>

#ifndef _LIBMHO_IO_H
#define _LIBMHO_IO_H

int8_t		mho_read_8(FILE * stream);
uint8_t		mho_read_u8(FILE * stream);
int16_t		mho_read_16(FILE * stream);
uint16_t	mho_read_u16(FILE * stream);
int32_t		mho_read_32(FILE * stream);
uint32_t	mho_read_u32(FILE * stream);
int64_t		mho_read_64(FILE * stream);
uint64_t	mho_read_u64(FILE * stream);
void           *mho_read(FILE * stream, size_t size);

#endif
