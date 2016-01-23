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

#include <libmho/types.h>
#include <stdio.h>

#ifndef _LIBMHO_LOAD_H
#define _LIBMHO_LOAD_H

struct mho_header mho_read_header(FILE * stream);
struct mho_fat_header mho_read_fhdr(FILE * stream);
struct mho_fat_arch mho_read_farch(FILE * stream);

#define MHO_FLAG_NOUNDEFS 0x1
#define MHO_FLAG_INCRLINK 0x2
#define MHO_FLAG_DYLDLINK 0x4
#define MHO_FLAG_BINDATLOAD 0x8
#define MHO_FLAG_PREBOUND 0x10

#define MHO_SEG_FLAG_HIGHVM 0x1
#define MHO_SEG_FLAG_FVMLIB 0x2
#define MGO_SEG_FLAG_NORELOC 0x4

#define MHO_SEC_TYPE 0x000000ff
#define MHO_SEC_ATTR 0xffffff00

#define MHO_SEC_REGULAR 0
#define MHO_SEC_ZEROFILL 1
#define MHO_SEC_CSTRING_LITERALS 2
#define MHO_SEC_4BYTE_LITERALS 3
#define MHO_SEC_8BYTE_LITERALS 4
#define MHO_SEC_LITERAL_POINTERS 5
#define MHO_SEC_NON_LAZY_SYMBOL_POINTERS 6
#define MHO_SEC_LAZY_SYMBOL_POINTERS 7
#define MHO_SEC_SYMBOL_STUBS 8
#define MHO_SEC_MOD_INIT_FUNC_POINTERS 9

#define MHO_SEC_ATTR_USR 0xff000000
#define MHO_SEC_ATTR_PURE_INSTRUCTIONS 0x80000000
#define MHO_SEC_ATTR_SYS 0x00ffff00
#define MHO_SEC_ATTR_SOME_INSTRUCTIONS 0x00000400
#define MHO_SEC_ATTR_EXT_RELOC 0x00000200
#define MHO_SEC_ATTR_LOC_RELOC 0x00000100

#define MHO_SEG_PAGEZERO "__PAGEZERO"
#define MHO_SEG_TEXT "__TEXT"
#define MHO_SEG_DATA "__DATA"
#define MHO_SEG_OBJC "__OBJC"

#define MHO_SEC_TEXT "__text"
#define MHO_SEC_FVMLIB_INIT0 "__fvmlib_init0"
#define MHO_SEC_FVMLIB_INIT1 "__fvmlib_init1"
#define MHO_SEC_DATA "__data"
#define MHO_SEC_BSS "__bss"
#define MHO_SEC_COMMON "__common"
#define MHO_SEC_OBJC_SYMBOLS "__symbol_table"
#define MHO_SEC_OBJC_MODULES "__module_info"
#define MHO_SEC_OBJC_STRINGS "__selector_strs"
#define MHO_SEC_OBJC_REFS "__selector_refs"

#endif
