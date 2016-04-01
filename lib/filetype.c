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

#include <libmho.h>
#include <gettext.h>

#undef _
#define _(x) dgettext("libmho", x)

const char *
mho_ft2s (int ft)
{
  switch (ft)
    {
    case MHO_OBJECT:
      return _("Object");
    case MHO_EXECUTE:
      return _("Executable");
    case MHO_FVMLIB:
      return _("FVMlib");
    case MHO_CORE:
      return _("Core");
    case MHO_PRELOAD:
      return _("Preloaded");
    case MHO_DYLIB:
      return _("Dynamic library");
    case MHO_DYLINKER:
      return _("Dynamic linker");
    case MHO_BUNDLE:
      return _("Bundle");
    default:
      return _("Unknown");
    }
}
