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

lib_LTLIBRARIES = libmho.la
libmho_la_SOURCES = magic.c swap.c cputypes.c io.c filetype.c init-intl.c
libmho_la_LIBADD = -lgnu -lintl
libmho_la_LDFLAGS = -L../gnulib -L../intl

AM_CPPFLAGS = -I ../include -I ../gnulib

dirs.h: stamp-dirs-h
	rm -f $@
	echo '#define localedir "$(localedir)"' >> dirs.h

stamp-dirs-h: Makefile Makefile.in Makefile.am ../configure ../configure.ac
	touch $@

init-intl.lo: dirs.h
