#!/bin/bash

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

rm -f 'Makefile.am'

FILES=`find . | grep '\.h$' | sed 's/^\.\///g'`

echo '# -*- Automake -*-
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

EXTRA_DIST = update_makefile_am.sh' >> Makefile.am

echo -n 'nobase_include_HEADERS = ' >> 'Makefile.am'

for A in $FILES; do
	echo '\' >> 'Makefile.am'
	echo -n "$A " >> 'Makefile.am'
done
