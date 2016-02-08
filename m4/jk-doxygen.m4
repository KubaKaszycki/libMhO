dnl jk-doxygen.m4 - Macros for Doxygen
dnl Copyright (C) 2016 Jakub Kaszycki
dnl 
dnl This program is free software: you can redistribute it and/or modify
dnl it under the terms of the GNU General Public License as published by
dnl the Free Software Foundation, either version 3 of the License, or
dnl (at your option) any later version.
dnl 
dnl This program is distributed in the hope that it will be useful,
dnl but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl GNU General Public License for more details.
dnl 
dnl You should have received a copy of the GNU General Public License
dnl along with this program.  If not, see <http://www.gnu.org/licenses/>.

AC_DEFUN([JK_PROG_DOXYGEN], [
	AC_CACHE_CHECK([whether to build doxygen documentation], [jk_cv_enable_doxygen], [
		AC_ARG_ENABLE([doxygen], [AS_HELP_STRING([--disable-doxygen], [Disable Doxygen documentation])], [jk_cv_enable_doxygen=$enableval], [jk_cv_enable_doxygen=yes])
	])
	AS_IF(test $jk_cv_enable_doxygen = "yes", [
		AC_ARG_VAR([DOXYGEN], [Doxygen (doxywizard is not recommended here)])
		AS_IF(test -z $DOXYGEN, [AC_PATH_PROGS([DOXYGEN], [doxygen])])
		AC_CONFIG_FILES([doc/Doxyfile])
	])
	AM_CONDITIONAL([ENABLE_DOXYGEN], test $jk_cv_enable_doxygen = "yes")
])
