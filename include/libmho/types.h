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

#ifndef _LIBMHO_TYPES_H
#define _LIBMHO_TYPES_H

typedef int32_t	mho_cpu_type_t;
typedef int32_t	mho_cpu_subtype_t;
typedef int32_t	mho_vm_prot_t;

union mho_lc_str {
	unsigned long	off;
#ifndef __LP64__
	char           *ptr;
#endif
};

struct mho_header {
	uint32_t	magic;
	mho_cpu_type_t	cputype;
	mho_cpu_subtype_t cpusubtype;
	uint32_t	filetype;
	uint32_t	ncmds;
	uint32_t	sizeofcmds;
	uint32_t	flags;
};

struct mho_fat_header {
	uint32_t	magic;
	uint32_t	nfat_arch;
};

struct mho_fat_arch {
	mho_cpu_type_t	cputype;
	mho_cpu_subtype_t cpusubtype;
	uint32_t	offset;
	uint32_t	size;
	uint32_t	alignment;
};

struct mho_load_command {
	uint32_t	cmd;
	uint32_t	cmdsize;
};

struct mho_segment_command {
	uint32_t	cmd;
	uint32_t	cmdsize;
	char		segname   [16];
	uint32_t	vmaddr;
	uint32_t	vmsize;
	uint32_t	fileoff;
	uint32_t	filesize;
	mho_vm_prot_t	maxprot;
	mho_vm_prot_t	initprot;
	uint32_t	nsects;
	uint32_t	flags;
};

struct mho_segment_command_64 {
	uint32_t	cmd;
	uint32_t	cmdsize;
	char		segname   [16];
	uint64_t	vmaddr;
	uint64_t	vmsize;
	uint32_t	fileoff;
	uint32_t	filesize;
	mho_vm_prot_t	maxprot;
	mho_vm_prot_t	initprot;
	uint32_t	nsects;
	uint32_t	flags;
};

struct mho_section {
	char		sectname  [16];
	char		segname   [16];
	uint32_t	addr;
	uint32_t	size;
	uint32_t	offset;
	uint32_t	align;
	uint32_t	reloff;
	uint32_t	nreloc;
	uint32_t	flags;
	uint32_t	reserved1;
	uint32_t	reserved2;
};

struct mho_section_64 {
	char		sectname  [16];
	char		segname   [16];
	uint64_t	addr;
	uint64_t	size;
	uint32_t	offset;
	uint32_t	align;
	uint32_t	reloff;
	uint32_t	nreloc;
	uint32_t	flags;
	uint32_t	reserved1;
	uint32_t	reserved2;
};

struct mho_fvmlib {
	union mho_lc_str name;
	uint32_t	minor_version;
	uint32_t	header_addr;
};

struct mho_fvmlib_command {
	uint32_t	cmd;
	uint32_t	cmdsize;
	struct mho_fvmlib fvmlib;
};

struct mho_dylib {
	union mho_lc_str name;
	uint32_t	timestamp;
	uint32_t	current_version;
	uint32_t	compatibility_version;
};

struct mho_dylib_command {
	uint32_t	cmd;
	uint32_t	cmdsize;
	struct mho_dylib dylib;
};

struct mho_prebound_dylib_command {
	uint32_t	cmd;
	uint32_t	cmdsize;
	union mho_lc_str name;
	uint32_t	nmodules;
	union mho_lc_str linked_modules;
};

struct mho_dylinker_command {
	uint32_t	cmd;
	uint32_t	cmdsize;
	union mho_lc_str name;
};

struct mho_thread_command {
	uint32_t	cmd;
	uint32_t	cmdsize;
};

struct mho_symtab_command {
	uint32_t	cmd;
	uint32_t	cmdsize;
	uint32_t	symoff;
	uint32_t	nsyms;
	uint32_t	stroff;
	uint32_t	strsize;
};

struct mho_dynsymtab_command {
	uint32_t	cmd;
	uint32_t	cmdsize;
	uint32_t	ilocalsym;
	uint32_t	nlocalsym;
	uint32_t	iextdefsym;
	uint32_t	nextdefsym;
	uint32_t	iundefsym;
	uint32_t	nundefsym;
	uint32_t	tocoff;
	uint32_t	ntoc;
	uint32_t	modtaboff;
	uint32_t	nmodtab;
	uint32_t	extrefsymoff;
	uint32_t	nextrefsyms;
	uint32_t	indirectsymoff;
	uint32_t	nindirectsyms;
	uint32_t	extreloff;
	uint32_t	nextrel;
	uint32_t	locreloff;
	uint32_t	nlocrel;
};

struct mho_dylib_toc {
	uint32_t	symbol_index;
	uint32_t	module_index;
};

struct mho_dylib_module {
	uint32_t	module_name;
	uint32_t	iextdefsym;
	uint32_t	nextdefsym;
	uint32_t	irefsym;
	uint32_t	nrefsym;
	uint32_t	ilocalsym;
	uint32_t	nlocalsym;
	uint32_t	iextrel;
	uint32_t	nextrel;
	uint32_t	iinit;
	uint32_t	ninit;
	uint32_t	objc_module_info_addr;
	uint32_t	objc_module_info_size;
};

struct mho_dylib_module_64 {
	uint32_t	module_name;
	uint32_t	iextdefsym;
	uint32_t	nextdefsym;
	uint32_t	irefsym;
	uint32_t	nrefsym;
	uint32_t	ilocalsym;
	uint32_t	nlocalsym;
	uint32_t	iextrel;
	uint32_t	nextrel;
	uint32_t	iinit_iterm;
	uint32_t	ninit_iterm;
	uint32_t	objc_module_info_size;
	uint64_t	objc_module_info_addr;
};

struct mho_dylib_reference {
	unsigned	isym:	24;
	uint8_t		flags;
};

struct mho_symseg_command {
	uint32_t	cmd;
	uint32_t	cmdsize;
	uint32_t	offset;
	uint32_t	size;
};

struct mho_ident_command {
	uint32_t	cmd;
	uint32_t	cmdsize;
};

struct mho_fvmfile_command {
	uint32_t	cmd;
	uint32_t	cmdsize;
	union mho_lc_str name;
	uint32_t	header_addr;
};

#endif
