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

typedef int	mho_cpu_type_t;
typedef int	mho_cpu_subtype_t;
typedef int	mho_vm_prot_t;

union mho_lc_str {
	unsigned long	off;
	              //A trick - long is the same size, as a pointer
	char           *ptr;
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
	unsigned long	cmd;
	unsigned long	cmdsize;
};

struct mho_segment_command {
	unsigned long	cmd;
	unsigned long	cmdsize;
	char		segname   [16];
	unsigned long	vmaddr;
	unsigned long	vmsize;
	unsigned long	fileoff;
	unsigned long	filesize;
	mho_vm_prot_t	maxprot;
	mho_vm_prot_t	initprot;
	unsigned long	nsects;
	unsigned long	flags;
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
	unsigned long	addr;
	unsigned long	size;
	unsigned long	offset;
	unsigned long	align;
	unsigned long	reloff;
	unsigned long	nreloc;
	unsigned long	flags;
	unsigned long	reserved1;
	unsigned long	reserved2;
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
	unsigned long	minor_version;
	unsigned long	header_addr;
};

struct mho_fvmlib_command {
	unsigned long	cmd;
	unsigned long	cmdsize;
	struct mho_fvmlib fvmlib;
};

struct mho_dylib {
	union mho_lc_str name;
	unsigned long	timestamp;
	unsigned long	current_version;
	unsigned long	compatibility_version;
};

struct mho_dylib_command {
	unsigned long	cmd;
	unsigned long	cmdsize;
	struct mho_dylib dylib;
};

struct mho_prebound_dylib_command {
	unsigned long	cmd;
	unsigned long	cmdsize;
	union mho_lc_str name;
	unsigned long	nmodules;
	union mho_lc_str linked_modules;
};

struct mho_dylinker_command {
	unsigned long	cmd;
	unsigned long	cmdsize;
	union mho_lc_str name;
};

struct mho_thread_command {
	unsigned long	cmd;
	unsigned long	cmdsize;
};

struct mho_symtab_command {
	unsigned long	cmd;
	unsigned long	cmdsize;
	unsigned long	symoff;
	unsigned long	nsyms;
	unsigned long	stroff;
	unsigned long	strsize;
};

struct mho_dynsymtab_command {
	unsigned long	cmd;
	unsigned long	cmdsize;
	unsigned long	ilocalsym;
	unsigned long	nlocalsym;
	unsigned long	iextdefsym;
	unsigned long	nextdefsym;
	unsigned long	iundefsym;
	unsigned long	nundefsym;
	unsigned long	tocoff;
	unsigned long	ntoc;
	unsigned long	modtaboff;
	unsigned long	nmodtab;
	unsigned long	extrefsymoff;
	unsigned long	nextrefsyms;
	unsigned long	indirectsymoff;
	unsigned long	nindirectsyms;
	unsigned long	extreloff;
	unsigned long	nextrel;
	unsigned long	locreloff;
	unsigned long	nlocrel;
};

struct mho_dylib_toc {
	unsigned long	symbol_index;
	unsigned long	module_index;
};

struct mho_dylib_module {
	unsigned long	module_name;
	unsigned long	iextdefsym;
	unsigned long	nextdefsym;
	unsigned long	irefsym;
	unsigned long	nrefsym;
	unsigned long	ilocalsym;
	unsigned long	nlocalsym;
	unsigned long	iextrel;
	unsigned long	nextrel;
	unsigned long	iinit;
	unsigned long	ninit;
	unsigned long	objc_module_info_addr;
	unsigned long	objc_module_info_size;
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
	unsigned long	cmd;
	unsigned long	cmdsize;
	unsigned long	offset;
	unsigned long	size;
};

struct mho_ident_command {
	unsigned long	cmd;
	unsigned long	cmdsize;
};

struct mho_fvmfile_command {
	unsigned long	cmd;
	unsigned long	cmdsize;
	union mho_lc_str name;
	unsigned long	header_addr;
};

#endif
