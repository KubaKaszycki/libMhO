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

#ifndef _LIBMHO_FILETYPE_H
#define _LIBMHO_FILETYPE_H

/**
 * Object/relocatable file.
 */
#define MHO_OBJECT 1

/**
 * Executable file.
 */
#define MHO_EXECUTE 2

/**
 * Fixed VM shared library.
 */
#define MHO_FVMLIB 3

/**
 * Core file.
 */
#define MHO_CORE 4

/**
 * Preloaded executable file.
 */
#define MHO_PRELOAD 5

/**
 * Dynamic library.
 */
#define MHO_DYLIB 6

/**
 * Dynamic linker.
 */
#define MHO_DYLINKER 7

/**
 * Bundle.
 */
#define MHO_BUNDLE 8

/**
 * Get a string which describes the file type best. The result
 * is not writable.
 * @param filetype file type
 * @returns description, no need to be freed
 */
const char     *mho_ft2s(int filetype);

#endif
