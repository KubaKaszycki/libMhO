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

#ifndef _LIBMHO_COMMAND_H
# define _LIBMHO_COMMAND_H

/**
 * If the dynamic linker sees such a load command it does not understand,
 * it will issue a "unknown load command required for execution" error and
 * refuse to use this image.  Other load commands without this bit that
 * are not understood will simply be ignored.
 */
# define MHO_LC_REQ_DYLD 0x80000000

/**
 * Segment to be mapped.
 */
# define MHO_LC_SEGMENT 1

/**
 * Link-edit stab symbol table info.
 * @see MHO_LC_DYSYMTAB
 */
# define MHO_LC_SYMTAB 2

/**
 * Link-edit GDB symbol table info.
 * @deprecated obsolete
 */
# define MHO_LC_SYMSEG 3

/**
 * Thread.
 */
# define MHO_LC_THREAD 4

/**
 * Unix thread.
 */
# define MHO_LC_UNIXTHREAD 5

/**
 * Fixed VM library load.
 */
# define MHO_LC_LOADFVMLIB 6

/**
 * Fixed VM library identification.
 */
# define MHO_LC_IDFVMLIB 7

/**
 * Object identification info.
 * @deprecated obsolete
 */
# define MHO_LC_IDENT 8

/**
 * Fixed VM library inclusion (internal use).
 */
# define MHO_LC_FVMFILE 9

/**
 * Prepage command (internal use).
 */
# define MHO_LC_PREPAGE 10

/**
 * Dynamic link-edit symbol table info.
 * @see MHO_LC_SYMTAB
 */
# define MHO_LC_DYSYMTAB 11

/**
 * Load shared library.
 */
# define MHO_LC_LOAD_DYLIB 12

/**
 * Shared library identification.
 */
# define MHO_LC_ID_DYLIB 13

/**
 * Load dynamic linker.
 */
# define MHO_LC_LOAD_DYLINKER 14

/**
 * Dynamic linker identification.
 */
# define MHO_LC_ID_DYLINKER 15

/**
 * Prebound shared library.
 */
# define MHO_LC_PREBOUND_DYLIB 16

/**
 * Image routines.
 */
# define MHO_LC_ROUTINES 17

/**
 * Sub framework.
 */
# define MHO_LC_SUB_FRAMEWORK 18

/**
 * Sub umbrella.
 */
# define MHO_LC_SUB_UMBRELLA 19

/**
 * Sub client.
 */
# define MHO_LC_SUB_CLIENT 20

/**
 * Sub library.
 */
# define MHO_LC_SUB_LIBRARY 21

/**
 * Two-level namespace lookup hints.
 */
# define MHO_LC_TWOLEVEL_HINTS 22

/**
 * Prebind checksum.
 */
# define MHO_LC_PREBIND_CKSUM 23

/**
 * Load weak dylib.
 */
# define MHO_LC_LOAD_WEAK_DYLIB (24 | MHO_LC_REQ_DYLD)

/**
 * 64-bit segment to be mapped.
 */
# define MHO_LC_SEGMENT_64 25

/**
 * 64-bit image routines.
 */
# define MHO_LC_ROUTINES_64 26

/**
 * The UUID.
 */
# define MHO_LC_UUID 27

/**
 * Runpath additions.
 */
# define MHO_LC_RPATH (28 | MHO_LC_REQ_DYLD)

/**
 * Code signature.
 */
# define MHO_LC_CODE_SIGNATURE 29

/**
 * Segment splitting info.
 */
# define MHO_LC_SEGMENT_SPLIT_INFO 30

/**
 * Load and re-export shared library.
 */
# define MHO_LC_REEXPORT_DYLIB (31 | MHO_LC_REQ_DYLD)

/**
 * Load shared library on first use.
 */
# define MHO_LC_LAZY_LOAD_DYLIB 32

/**
 * Segment encryption info.
 */
# define MHO_LC_ENCRYPTION_INFO 33

/**
 * Compressed dynamic linker information.
 */
# define MHO_LC_DYLD_INFO 34

/**
 * Compressed dynamic linker information only.
 */
# define MHO_LC_DYLD_INFO_INLY (MHO_LC_DYLD_INFO | MHO_LC_REQ_DYLD)

/**
 * Load upward shared library.
 */
# define MHO_LC_LOAD_UPWARD_DYLUB (35 | MHO_LC_REQ_DYLD)

/**
 * Apple only: Mac OS X minimal version.
 */
# define MHO_LC_VERSION_MIN_MACOSX 36

/**
 * Apple only: iPhoneOS/iOS minimal version.
 */
# define MHO_LC_VERSION_MIN_IPHONEOS 37

/**
 * Compressed table of function start addresses.
 */
# define MHO_LC_FUNCTION_START 38

/**
 * Strings for dynamic linker to thread as environment variables.
 */
# define MHO_LC_DYLD_ENVIRONMENT 39

/**
 * Replacement for {@link MHO_LC_UNIXTHREAD}.
 */
# define MHO_LC_MAIN (40 | MHO_LC_REQ_DYLD)

/**
 * Table of non-instructions in __text.
 */
# define MHO_LC_DATA_IN_CODE 41

/**
 * Source version used to build the binary.
 */
# define MHO_LC_SOURCE_VERSION 42

/**
 * DRs copied from loaded shared libraries.
 */
# define MHO_LC_DYLIB_CODE_SIGN_DRS 43

/**
 * 64-bit encrypted segment information.
 */
# define MHO_LC_ENCRYPTION_INFO_64 44

/**
 * Linker options in {@link MHO_OBJECT} files.
 */
# define MHO_LC_LINKER_OPTION 45

/**
 * Linker optimization hints in {@link MHO_OBJECT} files.
 */
# define MHO_LC_LINKER_OPTIMIZATION_HINT 46

/**
 * Apple only: TVOS minimal version.
 */
# define MHO_LC_VERSION_MIN_TVOS 47

/**
 * Apple only: WatchOS minimal version.
 */
# define MHO_LC_VERSION_MIN_WATCHOS 48

#endif
