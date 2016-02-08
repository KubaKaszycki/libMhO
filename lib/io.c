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

#include <libmho.h>
#include <string.h>
#include <stdlib.h>

int8_t
mho_read_8(FILE * stream)
{
	return getc(stream);
}

uint8_t
mho_read_u8(FILE * stream)
{
	return getc(stream);
}

int16_t
mho_read_16(FILE * stream)
{
	register int16_t result = 0;
	if (!mho_host_littleendian()) {
		result |= getc(stream);
		result |= getc(stream) << 8;
	} else {
		result |= getc(stream) << 8;
		result |= getc(stream);
	}
	return result;
}

uint16_t
mho_read_u16(FILE * stream)
{
	register uint16_t result = 0;
	if (!mho_host_littleendian()) {
		result |= getc(stream);
		result |= getc(stream) << 8;
	} else {
		result |= getc(stream) << 8;
		result |= getc(stream);
	}
	return result;
}

int32_t
mho_read_32(FILE * stream)
{
	register int32_t result = 0;
	if (!mho_host_littleendian()) {
		result |= getc(stream);
		result |= getc(stream) << 8;
		result |= getc(stream) << 16;
		result |= getc(stream) << 24;
	} else {
		result |= getc(stream) << 24;
		result |= getc(stream) << 16;
		result |= getc(stream) << 8;
		result |= getc(stream);
	}
	return result;
}

uint32_t
mho_read_u32(FILE * stream)
{
	register uint32_t result = 0;
	if (!mho_host_littleendian()) {
		result |= getc(stream);
		result |= getc(stream) << 8;
		result |= getc(stream) << 16;
		result |= getc(stream) << 24;
	} else {
		result |= getc(stream) << 24;
		result |= getc(stream) << 16;
		result |= getc(stream) << 8;
		result |= getc(stream);
	}
	return result;
}

int64_t 
mho_read_64(FILE * stream)
{
	register int64_t result = 0;
	if (!mho_host_littleendian()) {
		result |= getc(stream);
		result |= getc(stream) << 8;
		result |= getc(stream) << 16;
		result |= getc(stream) << 24;
		result |= ((int64_t) getc(stream)) << 32;
		result |= ((int64_t) getc(stream)) << 40;
		result |= ((int64_t) getc(stream)) << 48;
		result |= ((int64_t) getc(stream)) << 56;
	} else {
		result |= ((int64_t) getc(stream)) << 56;
		result |= ((int64_t) getc(stream)) << 48;
		result |= ((int64_t) getc(stream)) << 40;
		result |= ((int64_t) getc(stream)) << 32;
		result |= getc(stream) << 24;
		result |= getc(stream) << 16;
		result |= getc(stream) << 8;
		result |= getc(stream);
	}
	return result;
}

uint64_t 
mho_read_u64(FILE * stream)
{
	register uint64_t result = 0;
	if (!mho_host_littleendian()) {
		result |= getc(stream);
		result |= getc(stream) << 8;
		result |= getc(stream) << 16;
		result |= getc(stream) << 24;
		result |= ((uint64_t) getc(stream)) << 32;
		result |= ((uint64_t) getc(stream)) << 40;
		result |= ((uint64_t) getc(stream)) << 48;
		result |= ((uint64_t) getc(stream)) << 56;
	} else {
		result |= ((uint64_t) getc(stream)) << 56;
		result |= ((uint64_t) getc(stream)) << 48;
		result |= ((uint64_t) getc(stream)) << 40;
		result |= ((uint64_t) getc(stream)) << 32;
		result |= getc(stream) << 24;
		result |= getc(stream) << 16;
		result |= getc(stream) << 8;
		result |= getc(stream);
	}
	return result;
}

struct mho_header mho_read_header(FILE* stream) {
	struct mho_header result;
	result.magic = mho_read_u32(stream);
	result.cputype = mho_read_u32(stream);
	result.cpusubtype = mho_read_u32(stream);
	result.filetype = mho_read_u32(stream);
	result.ncmds = mho_read_u32(stream);
	result.sizeofcmds = mho_read_u32(stream);
	result.flags = mho_read_u32(stream);
	return result;
}

struct mho_fat_header mho_read_fhdr(FILE* stream) {
	struct mho_fat_header result;
	result.magic = mho_read_u32(stream);
	result.nfat_arch = mho_read_u32(stream);
	return result;
}

struct mho_fat_arch mho_read_farch(FILE* stream) {
	struct mho_fat_arch result;
	result.cputype = mho_read_u32(stream);
	result.cpusubtype = mho_read_u32(stream);
	result.offset = mho_read_u32(stream);
	result.size = mho_read_u32(stream);
	result.alignment = mho_read_u32(stream);
	return result;
}

struct mho_fvmlib mho_read_fvmlib(FILE* stream) {
	struct mho_fvmlib result;
	result.name.off = mho_read_u32(stream);
	result.minor_version = mho_read_u32(stream);
	result.header_addr = mho_read_u32(stream);
	return result;
}

struct mho_dylib mho_read_dylib(FILE * stream) {
	struct mho_dylib result;
	result.name.off = mho_read_u32(stream);
	return result;
}

void mho_read_command(FILE* stream, void** result) {
	int cmd = mho_read_u32(stream);
	int cmdsize = mho_read_u32(stream);
	struct mho_load_command* command;
	struct mho_segment_command* seg_command;
	struct mho_segment_command_64* seg_command_64;
	struct mho_fvmlib_command* fvmlib_cmd;
	struct mho_dylib_command* dylib_cmd;
	struct mho_symtab_command* symtab_cmd;
	struct mho_symseg_command* symseg_cmd;
	char buf[16];
	switch(cmd) {
		case MHO_LC_SEGMENT:
			seg_command = malloc(sizeof(struct mho_segment_command));
			seg_command->cmd = cmd;
			seg_command->cmdsize = cmdsize;
			fread(buf, sizeof(char), 16, stream);
			strcpy(seg_command->segname, buf);
			seg_command->vmaddr = mho_read_u32(stream);
			seg_command->vmsize = mho_read_u32(stream);
			seg_command->fileoff = mho_read_u32(stream);
			seg_command->filesize = mho_read_u32(stream);
			seg_command->maxprot = mho_read_u32(stream);
			seg_command->initprot = mho_read_u32(stream);
			seg_command->nsects = mho_read_u32(stream);
			seg_command->flags = mho_read_u32(stream);
			*result = seg_command;
			break;
		case MHO_LC_SYMTAB:
			symtab_cmd = malloc(sizeof(struct mho_symtab_command));
			symtab_cmd->cmd = cmd;
			symtab_cmd->cmdsize = cmdsize;
			symtab_cmd->symoff = mho_read_u32(stream);
			symtab_cmd->nsyms = mho_read_u32(stream);
			symtab_cmd->stroff = mho_read_u32(stream);
			symtab_cmd->strsize = mho_read_u32(stream);
			*result = symtab_cmd;
			break;
		case MHO_LC_IDFVMLIB:
			fvmlib_cmd = malloc(sizeof(struct mho_fvmlib_command));
			fvmlib_cmd->cmd = cmd;
			fvmlib_cmd->cmdsize = cmdsize;
			fvmlib_cmd->fvmlib = mho_read_fvmlib(stream);
			*result = fvmlib_cmd;
			break;
		case MHO_LC_REEXPORT_DYLIB:
			dylib_cmd = malloc(sizeof(struct mho_dylib_command));
			dylib_cmd->cmd = cmd;
			dylib_cmd->cmdsize = cmdsize;
			*result = dylib_cmd;
			break;
		case MHO_LC_SEGMENT_64:
			seg_command_64 = malloc(sizeof(struct mho_segment_command_64));
			seg_command_64->cmd = cmd;
			seg_command_64->cmdsize = cmdsize;
			fread(buf, sizeof(char), 16, stream);
			strcpy(seg_command_64->segname, buf);
			seg_command_64->vmaddr = mho_read_u64(stream);
			seg_command_64->vmsize = mho_read_u64(stream);
			seg_command_64->fileoff = mho_read_u32(stream);
			seg_command_64->filesize = mho_read_u32(stream);
			seg_command_64->maxprot = mho_read_u32(stream);
			seg_command_64->initprot = mho_read_u32(stream);
			seg_command_64->nsects = mho_read_u32(stream);
			seg_command_64->flags = mho_read_u32(stream);
			*result = seg_command_64;
			break;
		default:
			command = malloc(sizeof(struct mho_load_command));
			command->cmd = cmd;
			command->cmdsize = cmdsize;
			fseek(stream, command->cmdsize - 8, SEEK_CUR);
			*result = command;
	}
}
