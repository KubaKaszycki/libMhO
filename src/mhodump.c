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

#define __LIBMHO_INTERNAL
#include <libmho.h>
#include <config.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <version.h>
#include <cow.h>
#undef __LIBMHO_INTERNAL

static struct option OPTIONS[] = {
	{"help", no_argument, NULL, 'h'},
	{NULL, 0, NULL, 0}
};

void
print_help()
{
	print_version();
	printf("mhodump - Dump something from Mach-O file\n"
	       "\n"
	       "Usage: mhodump <SUBCOMMAND> [options...]\n"
	       "\n"
	       "Subcommands:\n"
	       "   help          - Display this help text\n"
	       "   version       - Display version\n"
	       "   header        - Display Mach-O header\n"
	       "   load-commands - Display load commands\n"
	       "   segments      - Display segments (in one file)\n"
	       "   sections      - Display sections (in one segment)\n"
	       "   symbols       - Display symbols (in one section)\n"
	       "There is also one easter milk (I meant egg)... Try to find it!\n");
}

typedef int     (*subcommand_t) (int, char **);

int
help(int argc, char **argv)
{
	print_help();
	return 0;
}

int
version(int argc, char **argv)
{
	print_version();
	return 0;
}

int		header     (int, char **);
int		load_commands(int, char **);
int		segments   (int, char **);
int		sections   (int, char **);
int		symbols    (int, char **);
int		moo        (int, char **);

int
subcommand_not_found(int argc, char **argv)
{
	fprintf(stderr, "Command not found: %s!\n", argv[0]);
	return 1;
}

subcommand_t
get_subcommand(const char *name)
{
#define register_scmd(fn, nam) if(strcmp(name, nam) == 0) return fn
	register_scmd(help, "help");
	register_scmd(version, "version");
	register_scmd(header, "header");
	register_scmd(load_commands, "load-commands");
	register_scmd(segments, "segments");
	register_scmd(sections, "sections");
	register_scmd(symbols, "symbols");
	register_scmd(moo, "moo");
#undef register_scmd
	return subcommand_not_found;
}

int
main(int argc, char **argv)
{
	if (argc == 1) {
		fprintf(stderr, "Error: missing subcommand\n");
		fprintf(stderr, "For details type: %s help\n", argv[0]);
		return 1;
	}
	subcommand_t	sc = get_subcommand(argv[1]);
	return sc(argc - 1, argv + 1);
}

int
header(int argc, char **argv)
{
	FILE           *stream = fopen(argv[1], "r");
	struct mho_header header = mho_read_header(stream);
	if (!mho_is_magic(header.magic)) {
		fprintf(stderr, "Not an object file\n");
		fclose(stream);
		return 1;
	}
	printf("Magic number: 0x%x (", header.magic);
	if (mho_is_magic(header.magic)) {
		if (mho_magic_64(header.magic)) {
			printf("64-bit, ");
		} else if (mho_magic_fat(header.magic)) {
			printf("universal, ");
		} else {
			printf("32-bit, ");
		}
		if (mho_magic_littleendian(header.magic)) {
			if (mho_host_littleendian()) {
				printf("little-endian");
			} else
				printf("big-endian");
		} else {
			if (mho_host_littleendian()) {
				printf("big-endian");
			} else
				printf("little-endian");
		}
	} else {
		printf("invalid");
	}
	if (mho_magic_littleendian(header.magic)) {
		if (mho_host_bigendian()) {
			mho_endian_little = !mho_endian_little;
		}
	} else {
		if (mho_host_littleendian()) {
			mho_endian_little = !mho_endian_little;
		}
	}
	printf(")\n");
	if (mho_magic_fat(header.magic)) {
		fseek(stream, -sizeof(struct mho_header), SEEK_CUR);
		struct mho_fat_header fhdr = mho_read_fhdr(stream);
		printf("Architecture count: %u\n", fhdr.nfat_arch);
		for (uint32_t i = 0; i < fhdr.nfat_arch; i++) {
			struct mho_fat_arch arch = mho_read_farch(stream);
			printf("Architecture #%u:\n", i + 1);
			printf("\tCPU type: 0x%x (%s)\n", arch.cputype, mho_ct2s(arch.cputype));
			printf("\tCPU sub-type: 0x%x (%s)\n", arch.cpusubtype & MHO_CPU_SUBTYPE_MASK, mho_cst2s(arch.cputype, arch.cpusubtype & MHO_CPU_SUBTYPE_MASK));
			printf("\tOffset: %u\n", arch.offset);
			printf("\tSize: %u\n", arch.size);
			printf("\tAlignment: %u\n", arch.size);
		}
		return 0;
	}
	printf("CPU type: 0x%x (%s)\n", header.cputype, mho_ct2s(header.cputype));
	printf("CPU sub-type: 0x%x (%s)\n", header.cpusubtype & MHO_CPU_SUBTYPE_MASK, mho_cst2s(header.cputype, header.cpusubtype & MHO_CPU_SUBTYPE_MASK));
	printf("File type: %hd (%s)\n", (short)header.filetype, mho_ft2s((short)header.filetype));
	printf("Commands count: %d\n", header.ncmds);
	printf("Commands sumaric size: %d\n", header.sizeofcmds);
	printf("Flags:");
#define __flag__(x) do { \
if(header.flags & MHO_FLAG_##x) { \
printf(" MH_" #x); \
} \
} while(0)
	__flag__(NOUNDEFS);
	__flag__(INCRLINK);
	__flag__(DYLDLINK);
	__flag__(BINDATLOAD);
	__flag__(PREBOUND);
	__flag__(SPLIT_SEGS);
	__flag__(LAZY_INIT);
	__flag__(TWOLEVEL);
	__flag__(FORCE_FLAT);
	__flag__(NOMULTIDEFS);
	__flag__(NOFIXPREBINDING);
	__flag__(PREBINDABLE);
	__flag__(ALLMODSBOUND);
	__flag__(SUBSECTIONS_VIA_SYMBOLS);
	__flag__(CANONICAL);
	__flag__(WEAK_DEFINES);
	__flag__(BINDS_TO_WEAK);
	__flag__(ALLOW_STACK_EXECUTION);
	__flag__(ROOT_SAFE);
	__flag__(SETUID_SAFE);
	__flag__(NO_REEXPORTED_DYLIBS);
	__flag__(PIE);
	__flag__(DEAD_STRIPPABLE_DYLIB);
#undef __flag__
	printf("\n");
	fclose(stream);
	return 0;
}

int
load_commands(int argc, char **argv)
{
	FILE* stream = fopen(argv[1], "r");
	struct mho_header hdr = mho_read_header(stream);
	if(mho_magic_fat(hdr.magic)) {
		fprintf(stderr, "Universal binaries not supported yet\n");
		fclose(stream);
		return 1;
	}
	struct mho_load_command *lc;
	for(uint32_t i = 0; i < hdr.ncmds; i++) {
		mho_read_command(stream, (void**) &lc);
		printf("Command #%d:\n", i + 1);
		printf("\tType: %d\n", lc->cmd);
	}
	return 0;
}
int
segments(int argc, char **argv)
{
	fprintf(stderr, "TODO :-(\n");
	return 0;
}
int
sections(int argc, char **argv)
{
	fprintf(stderr, "TODO :-(\n");
	return 0;
}
int
symbols(int argc, char **argv)
{
	fprintf(stderr, "TODO :-(\n");
	return 0;
}

int 
moo(int argc, char **argv)
{
	puts(cow_said_characters);
	return 0;
}
