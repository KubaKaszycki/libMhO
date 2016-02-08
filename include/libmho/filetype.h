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

#define MHO_OBJECT 1
#define MHO_EXECUTE 2
#define MHO_FVMLIB 3
#define MHO_CORE 4
#define MHO_PRELOAD 5
#define MHO_DYLIB 6
#define MHO_DYLINKER 7
#define MHO_BUNDLE 8

const char     *mho_ft2s(int);

#endif
