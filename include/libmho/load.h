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
#define _LIBMHO_LOAD_H

struct mho_header mho_read_header(FILE * stream);
struct mho_fat_header mho_read_fhdr(FILE * stream);
struct mho_fat_arch mho_read_farch(FILE * stream);
struct mho_dylib mho_read_dylib(FILE * stream);
struct mho_fvmlib mho_read_fvmlib(FILE * stream);
void mho_read_command(FILE * stream, void **result);

#define MHO_FLAG_NOUNDEFS 0x1
#define MHO_FLAG_INCRLINK 0x2
#define MHO_FLAG_DYLDLINK 0x4
#define MHO_FLAG_BINDATLOAD 0x8
#define MHO_FLAG_PREBOUND 0x10
#define MHO_FLAG_SPLIT_SEGS 0x20
#define MHO_FLAG_LAZY_INIT 0x40
#define MHO_FLAG_TWOLEVEL 0x80
#define MHO_FLAG_FORCE_FLAT 0x100
#define MHO_FLAG_NOMULTIDEFS 0x200
#define MHO_FLAG_NOFIXPREBINDING 0x400
#define MHO_FLAG_PREBINDABLE 0x800
#define MHO_FLAG_ALLMODSBOUND 0x1000
#define MHO_FLAG_SUBSECTIONS_VIA_SYMBOLS 0x2000
#define MHO_FLAG_CANONICAL 0x4000
#define MHO_FLAG_WEAK_DEFINES 0x8000
#define MHO_FLAG_BINDS_TO_WEAK 0x10000
#define MHO_FLAG_ALLOW_STACK_EXECUTION 0x20000
#define MHO_FLAG_ROOT_SAFE 0x40000
#define MHO_FLAG_SETUID_SAFE 0x80000
#define MHO_FLAG_NO_REEXPORTED_DYLIBS 0x100000
#define MHO_FLAG_PIE 0x200000
#define MHO_FLAG_DEAD_STRIPPABLE_DYLIB 0x400000

#define MHO_LC_REQ_DYLD 0x80000000
#define MHO_LC_SEGMENT 1
#define MHO_LC_SYMTAB 2
#define MHO_LC_SYMSEG 3
#define MHO_LC_THREAD 4
#define MHO_LC_UNIXTHREAD 5
#define MHO_LC_LOADFVMLIB 6
#define MHO_LC_IDFVMLIB 7
#define MHO_LC_IDENT 8
#define MHO_LC_FVMFILE 9
#define MHO_LC_PREPAGE 10
#define MHO_LC_DYSYMTAB 11
#define MHO_LC_LOAD_DYLIB 12
#define MHO_LC_ID_DYLIB 13
#define MHO_LC_LOAD_DYLINKER 14
#define MHO_LC_ID_DYLINKER 15
#define MHO_LC_PREBOUND_DYLIB 16
#define MHO_LC_ROUTINES 17
#define MHO_LC_SUB_FRAMEWORK 18
#define MHO_LC_SUB_UMBRELLA 19
#define MHO_LC_SUB_CLIENT 20
#define MHO_LC_SUB_LIBRARY 21
#define MHO_LC_TWOLEVEL_HINTS 22
#define MHO_LC_PREBIND_CKSUM 23
#define MHO_LC_LOAD_WEAK_DYLIB (24 | MHO_LC_REQ_DYLD)
#define MHO_LC_SEGMENT_64 25
#define MHO_LC_ROUTINES_64 26
#define MHO_LC_UUID 27
#define MHO_LC_RPATH (28 | MHO_LC_REQ_DYLD)
#define MHO_LC_CODE_SIGNATURE 29
#define MHO_LC_SEGMENT_SPLIT_INFO 30
#define MHO_LC_REEXPORT_DYLIB (31 | MHO_LC_REQ_DYLD)
#define MHO_LC_LAZY_LOAD_DYLIB 32
#define MHO_LC_ENCRYPTION_INFO 33
#define MHO_LC_DYLD_INFO 34
#define MHO_LC_DYLD_INFO_ONLY (MHO_LC_DYLD_INFO | MHO_LC_REQ_DYLD)

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
