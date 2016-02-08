#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

# Copyright (c) 2016 Jakub Kaszycki
# This file is part of libMhO.
#
# LibMhO is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

AC_PREREQ([2.69])
AC_INIT([libMhO], [0.2], [kaszycki@mail.com], [libmho])
AC_CONFIG_SRCDIR([include/libmho/load.h])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign])

AH_TOP([/*
 * Copyright (c) 2016 Jakub Kaszycki
 * This file is part of libMhO.
 * 
 * LibMhO is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */])

# Checks for programs.
JK_PROG_DOXYGEN
AC_PROG_CC
gl_EARLY
gl_INIT
LT_INIT

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdint.h inttypes.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_UINT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
gl_STDLIB_H
gl_STDIO_H
gl_UNISTD_H

# Checks for library functions.
gl_FUNC_MALLOC_GNU
gl_FUNC_FSEEK
gl_FUNC_FCLOSE
gl_FUNC_FOPEN
gl_FUNC_GETOPT_GNU

AC_CONFIG_FILES([Makefile
		 doc/Makefile
		 gnulib/Makefile
		 include/Makefile
		 lib/Makefile
		 src/Makefile])
AC_OUTPUT
