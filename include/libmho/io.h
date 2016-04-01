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
# define _LIBMHO_IO_H

/**
 * Read a 8-bit signed integer from file.
 * @param stream open file
 * @returns read number
 */
int8_t mho_read_8 (FILE * stream);

/**
 * Read a 8-bit unsigned integer from file.
 * @param stream open file
 * @returns read number
 */
uint8_t mho_read_u8 (FILE * stream);

/**
 * Read a 16-bit signed integer from file.
 * @param stream open file
 * @returns read number
 */
int16_t mho_read_16 (FILE * stream);

/**                                 
 * Read a 16-bit unsigned integer from file.
 * @param stream open file
 * @returns read number
 */
uint16_t mho_read_u16 (FILE * stream);

/**                                 
 * Read a 32-bit signed integer from file.
 * @param stream open file
 * @returns read number
 */
int32_t mho_read_32 (FILE * stream);

/**                                 
 * Read a 32-bit unsigned integer from file.
 * @param stream open file
 * @returns read number
 */
uint32_t mho_read_u32 (FILE * stream);

/**                                 
 * Read a 64-bit signed integer from file.
 * @param stream open file
 * @returns read number
 */
int64_t mho_read_64 (FILE * stream);

/**                                 
 * Read a 64-bit unsigned integer from file.
 * @param stream open file
 * @returns read number
 */
uint64_t mho_read_u64 (FILE * stream);

/**
 * Reads bytes from file.
 * @param stream open file
 * @returns buffer (has to be freed)
 */
void *mho_read (FILE * stream, size_t size);

#endif
