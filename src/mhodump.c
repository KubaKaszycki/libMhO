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
#include <gettext.h>
#include <locale.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <version.h>
#include <cow.h>
#include <libgen.h>
#include <xlocale.h>
#include <errno.h>
#include <sys/stat.h>
#undef __LIBMHO_INTERNAL

#undef _
#define _(x) dgettext("libmho", x)

#ifdef ENABLE_NLS
# define printf(x, ...) printf_l(uselocale(NULL), x, ##__VA_ARGS__)
# define fprintf(f, x, ...) fprintf_l(f, uselocale(NULL), x, ##__VA_ARGS__)
#endif

int
verify_file(const char *path)
{
	struct stat     st_buf;
	errno = 0;
	stat(path, &st_buf);
	if (errno != 0) {
		char           *buf = (char *) malloc(1024);
		strerror_r(errno, buf, 1024);
		fprintf(stderr, "%s: %s\n", path, buf);
		free(buf);
		goto invalid;
	}
	errno = 0;
	switch (st_buf.st_mode & S_IFMT) {
	case S_IFDIR:
		fprintf(stderr, "%s: %s\n", path, _("Is a directory"));
		goto invalid;
	case S_IFSOCK:
		fprintf(stderr, "%s: %s\n", path,
			_("Operation not supported on socket"));
		goto invalid;
	case S_IFWHT:
		fprintf(stderr, "%s: %s\n", path, _("No such file"));
		goto invalid;
	}
	errno = 0;
	if ((st_buf.st_mode & 04) == 0) {	// Read for others
		if (((st_buf.st_mode & 040) == 0)
		    || (getegid() != st_buf.st_gid)) {
			if (((st_buf.st_mode & 0400) == 0)
			    || (geteuid() != st_buf.st_uid)) {
				fprintf(stderr, "%s: %s\n", path,
					_("No read permission"));
				goto invalid;
			}
		}
	}
	errno = 0;
	FILE           *stream = fopen(path, "r");
	if (errno != 0) {
		char           *buf = (char *) malloc(1024);
		strerror_r(errno, buf, 1024);
		fprintf(stderr, "%s: %s: %s\n", path, _("I/O error"), buf);
		free(buf);
		goto invalid;
	}
	if (stream == NULL) {
		fprintf(stderr, "%s: %s\n", path, _("I/O error"));
		goto invalid;
	}
	struct mho_header hdr = mho_read_header(stream);
	if (errno != 0) {
		char           *buf = (char *) malloc(1024);
		strerror_r(errno, buf, 1024);
		fprintf(stderr, "%s: %s: %s\n", path, _("I/O error"), buf);
		free(buf);
		goto invalid;
	}
	if (!mho_is_magic(hdr.magic)) {
		fprintf(stderr, "%s: %s\n", path, _("Not a Mach object"));
		goto invalid;
	}
	goto valid;
      valid:
	return 0;
      invalid:
	return 1;
}

char           *alias;

void
print_help()
{
	print_version();
	printf("%s - %s\n"
	       "\n"
	       "%s: mhodump <%s> [%s...]\n"
	       "\n"
	       "%s:\n"
	       "   help          - %s\n"
	       "   version       - %s\n"
	       "   header        - %s\n"
	       "   load-commands - %s\n"
	       "   segments      - %s\n"
	       "   sections      - %s\n"
	       "   symbols       - %s\n"
	       "%s\n",
	       alias, _("Dump something from Mach-O file"), _("Usage"), _("SUBCOMMAND"),
	       _("options"), _("Subcommands"), _("Display this help text"),
	       _("Display version of libMhO"), _("Display Mach header"),
	       _("Display load commands"), _("Display segments (in one file)"),
	       _("Display sections (in one segment)"), _("Display symbols (in one section)"),
	       _("There is also one easter milk (I meant egg)... Try to find it!"));
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

int             header(int, char **);
int             load_commands(int, char **);
int             segments(int, char **);
int             sections(int, char **);
int             symbols(int, char **);
int             moo(int, char **);

int
subcommand_not_found(int argc, char **argv)
{
	fprintf(stderr, "%s: %s!\n", _("Command not found"), argv[0]);
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
	alias = strdup(basename(argv[0]));
	if (argc == 1) {
		fprintf(stderr, "%s: %s: %s\n", alias, _("Error"),
			_("Missing subcommand"));
		fprintf(stderr, _("For details type: %s help\n"), alias);
		return 1;
	}
	subcommand_t    sc = get_subcommand(argv[1]);
	int             result = sc(argc - 1, argv + 1);
	free(alias);
	return result;
}

int
header(int argc, char **argv)
{
	if (verify_file(argv[1]) == 1) {
		return 1;
	}
	FILE           *stream = fopen(argv[1], "r");
	struct mho_header header = mho_read_header(stream);
	printf("%s: 0x%x (", _("Magic number"), header.magic);
	if (mho_is_magic(header.magic)) {
		if (mho_magic_64(header.magic)) {
			printf("64-bit, ");
		} else if (mho_magic_fat(header.magic)) {
			printf("%s, ", _("universal"));
		} else {
			printf("32-bit, ");
		}
		if (mho_magic_littleendian(header.magic)) {
			if (mho_host_littleendian()) {
				printf("%s", _("little endian"));
			} else
				printf("%s", _("big endian"));
		} else {
			if (mho_host_littleendian()) {
				printf("%s", _("big endian"));
			} else
				printf("%s", _("little endian"));
		}
	} else {
		printf(_("invalid"));
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
		printf("%s: %u\n", _("Architecture count"),
		       fhdr.nfat_arch);
		for (uint32_t i = 0; i < fhdr.nfat_arch; i++) {
			struct mho_fat_arch arch = mho_read_farch(stream);
			printf("%s %u:\n", _("Architecture"), i + 1);
			printf("\t%s: 0x%x (%s)\n", _("CPU type"), arch.cputype,
			       mho_ct2s(arch.cputype));
			printf("\t%s: 0x%x (%s)\n", _("CPU subtype"),
			       arch.cpusubtype & MHO_CPU_SUBTYPE_MASK,
			       mho_cst2s(arch.cputype,
					 arch.cpusubtype &
					 MHO_CPU_SUBTYPE_MASK));
			printf("\t%s: %u\n", _("Offset"), arch.offset);
			printf("\t%s: %u\n", _("Size"), arch.size);
			printf("\t%s: %u\n", _("Alignment"), arch.alignment);
		}
		return 0;
	} else {
		printf("%s: 0x%x (%s)\n", _("CPU type"), header.cputype,
		       mho_ct2s(header.cputype));
		printf("%s: 0x%x (%s)\n", _("CPU subtype"),
		       header.cpusubtype & MHO_CPU_SUBTYPE_MASK,
		       mho_cst2s(header.cputype,
				 header.cpusubtype &
				 MHO_CPU_SUBTYPE_MASK));
	}
	printf("%s: %hd (%s)\n", _("File type"), (short) header.filetype,
	       mho_ft2s((short) header.filetype));
	printf("%s: %d\n", _("Commands count"), header.ncmds);
	printf("%s: %d\n", _("Commands sumaric size"), header.sizeofcmds);
	printf("%s:", _("Flags"));
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
	if (mho_magic_64(header.magic)) {
		struct mho_header_64 *hdr64 =
		    (struct mho_header_64 *) &header;
		printf("%s: 0x%x\n", _("Reserved (no purpose)"), hdr64->reserved);
	}
	fclose(stream);
	return 0;
}

int
load_commands(int argc, char **argv)
{
	FILE           *stream = fopen(argv[1], "r");
	struct mho_header hdr = mho_read_header(stream);
	if (mho_magic_fat(hdr.magic)) {
		fprintf(stderr, "%s\n", _("Universal binaries not supported yet"));
		fclose(stream);
		return 1;
	}
	struct mho_load_command *lc;
	for (uint32_t i = 0; i < hdr.ncmds; i++) {
		mho_read_command(stream, (void **) &lc);
		printf("%s #%d:\n", _("Command"), i + 1);
		printf("\t%s: %d\n", _("Type"), lc->cmd);
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
