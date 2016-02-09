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
#include <stdio.h>

#ifndef _LIBMHO_LOAD_H
# define _LIBMHO_LOAD_H

struct mho_header mho_read_header(FILE * stream);
struct mho_fat_header mho_read_fhdr(FILE * stream);
struct mho_fat_arch mho_read_farch(FILE * stream);
struct mho_dylib mho_read_dylib(FILE * stream);
struct mho_fvmlib mho_read_fvmlib(FILE * stream);
void            mho_read_command(FILE * stream, void **result);

/**
 * The object file has no undefined references.
 */
# define MHO_FLAG_NOUNDEFS 0x1

/**
 * The output file is output of an incremental link of base file.
 */
# define MHO_FLAG_INCRLINK 0x2

/**
 * The object file is input for dynamic linker and can't be statically linked again.
 */
# define MHO_FLAG_DYLDLINK 0x4

/**
 * The object file's undefined references are bound by linker on load.
 */
# define MHO_FLAG_BINDATLOAD 0x8

/**
 * The file has its undefined references prebound.
 */
# define MHO_FLAG_PREBOUND 0x10

/**
 * The file has its read-only and read-write segments split.
 */
# define MHO_FLAG_SPLIT_SEGS 0x20

/**
 * The shared library init routine is to be run lazily via catching memory
 * faults to its writeable segments.
 * @deprecated obsolete
 */
# define MHO_FLAG_LAZY_INIT 0x40

/**
 * The image is using two-level name space bindings.
 */
# define MHO_FLAG_TWOLEVEL 0x80

/**
 * The executable is forcing all images to use flat name space bindings.
 */
# define MHO_FLAG_FORCE_FLAT 0x100

/**
 * 
 */
# define MHO_FLAG_NOMULTIDEFS 0x200
# define MHO_FLAG_NOFIXPREBINDING 0x400
# define MHO_FLAG_PREBINDABLE 0x800
# define MHO_FLAG_ALLMODSBOUND 0x1000
# define MHO_FLAG_SUBSECTIONS_VIA_SYMBOLS 0x2000
# define MHO_FLAG_CANONICAL 0x4000
# define MHO_FLAG_WEAK_DEFINES 0x8000
# define MHO_FLAG_BINDS_TO_WEAK 0x10000
# define MHO_FLAG_ALLOW_STACK_EXECUTION 0x20000
# define MHO_FLAG_ROOT_SAFE 0x40000
# define MHO_FLAG_SETUID_SAFE 0x80000
# define MHO_FLAG_NO_REEXPORTED_DYLIBS 0x100000
# define MHO_FLAG_PIE 0x200000
# define MHO_FLAG_DEAD_STRIPPABLE_DYLIB 0x400000

# define MHO_SEG_FLAG_HIGHVM 0x1
# define MHO_SEG_FLAG_FVMLIB 0x2
# define MGO_SEG_FLAG_NORELOC 0x4

# define MHO_SEC_TYPE 0x000000ff
# define MHO_SEC_ATTR 0xffffff00

# define MHO_SEC_REGULAR 0
# define MHO_SEC_ZEROFILL 1
# define MHO_SEC_CSTRING_LITERALS 2
# define MHO_SEC_4BYTE_LITERALS 3
# define MHO_SEC_8BYTE_LITERALS 4
# define MHO_SEC_LITERAL_POINTERS 5
# define MHO_SEC_NON_LAZY_SYMBOL_POINTERS 6
# define MHO_SEC_LAZY_SYMBOL_POINTERS 7
# define MHO_SEC_SYMBOL_STUBS 8
# define MHO_SEC_MOD_INIT_FUNC_POINTERS 9

# define MHO_SEC_ATTR_USR 0xff000000
# define MHO_SEC_ATTR_PURE_INSTRUCTIONS 0x80000000
# define MHO_SEC_ATTR_SYS 0x00ffff00
# define MHO_SEC_ATTR_SOME_INSTRUCTIONS 0x00000400
# define MHO_SEC_ATTR_EXT_RELOC 0x00000200
# define MHO_SEC_ATTR_LOC_RELOC 0x00000100

# define MHO_SEG_PAGEZERO "__PAGEZERO"
# define MHO_SEG_TEXT "__TEXT"
# define MHO_SEG_DATA "__DATA"
# define MHO_SEG_OBJC "__OBJC"

# define MHO_SEC_TEXT "__text"
# define MHO_SEC_FVMLIB_INIT0 "__fvmlib_init0"
# define MHO_SEC_FVMLIB_INIT1 "__fvmlib_init1"
# define MHO_SEC_DATA "__data"
# define MHO_SEC_BSS "__bss"
# define MHO_SEC_COMMON "__common"
# define MHO_SEC_OBJC_SYMBOLS "__symbol_table"
# define MHO_SEC_OBJC_MODULES "__module_info"
# define MHO_SEC_OBJC_STRINGS "__selector_strs"
# define MHO_SEC_OBJC_REFS "__selector_refs"

#endif
