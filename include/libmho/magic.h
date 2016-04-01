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
# define _LIBMHO_MAGIC_H

/**
 * The magic number of a 32-bit object.
 */
# define MHO_MAGIC 0xFEEDFACEL

/**
 * The magic number of a 64-bit object.
 */
# define MHO_MAGIC64 0xFEEDFACFL

/**
 * The magic number of an universal binary.
 */
# define MHO_MAGIC_FAT 0xCAFEBABEL

/**
 * The magic number of a 32-bit object, reverse-endian.
 */
# define MHO_CIGAM 0xCEFAEDFEL

/**
 * The magic number of a 64-bit object, reverse-endian.
 */
# define MHO_CIGAM64 0xCFFAEDFEL

/**
 * The magic number of an universal binary, reverse-endian.
 */
# define MHO_CIGAM_FAT 0xBEBAFECAL

# ifdef __LIBMHO_INTERNAL
/**
 * LibMhO internal routine.
 */
#  define __LIBMHO_MAGIC_H_INTERNAL_ROUTINE
# else
/**
 * LibMhO internal routine.
 */
#  define __LIBMHO_MAGIC_H_INTERNAL_ROUTINE __attribute__((deprecated("Internal routine")))
# endif

/**
 * Set to {@code true} if tests already done, to {@code false} otherwise.
 * @see mho_check_endian
 */
__LIBMHO_MAGIC_H_INTERNAL_ROUTINE extern bool mho_endian_checked;

/**
 * Set to true if data should be read as big or little endian.
 */
__LIBMHO_MAGIC_H_INTERNAL_ROUTINE extern bool mho_endian_little;

/**
 * Checks if number is a magic number of Mach object.
 * @param number number to check
 * @returns true if number is a magic number, false otherwise
 */
bool mho_is_magic (uint32_t number);

/**
 * Checks if number is a 64-bit magic number.
 * @param number number to check
 * @returns true if number is a magic number, false otherwise
 */
bool mho_magic_64 (uint32_t number);

/**
 * Checks if number is a universal binary magic number.
 * @param number number to check
 * @returns true if number is a magic number, false otherwise
 */
bool mho_magic_fat (uint32_t number);

/**
 * Checks if number is a little-endian magic number.
 * @param number number to check
 * @returns true if number is a little-endian magic number, false otherwise
 */
bool mho_magic_littleendian (uint32_t number);

/**
 * Checks if a number is a big-endian magic number.
 * @param number number to check
 * @retruns true if number is a big-endian magic number, false otherwise
 */
bool mho_magic_bigendian (uint32_t number);

/**
 * Perform endian tests.
 */
void mho_check_endian ();

/**
 * Checks if host is little-endian.
 * @returns true if host is little-endian, false otherwise
 */
bool mho_host_littleendian ();

/**
 * Checks if host is big-endian
 * @returns true if host is big-endian, false otherwise
 */
bool mho_host_bigendian ();

#endif
