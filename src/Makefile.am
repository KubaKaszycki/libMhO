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

bin_PROGRAMS = mhodump
noinst_LTLIBRARIES = libutilities.la

mhodump_SOURCES = mhodump.c
mhodump_LDADD = -lmho -lutilities -lgnu -lintl
mhodump_LDFLAGS = -L../lib -L. -L../gnulib -L../intl

libutilities_la_SOURCES = version.c cow.c

AM_CPPFLAGS = -I ../include -I ../gnulib -I .. -I ../intl
