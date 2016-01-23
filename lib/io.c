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
