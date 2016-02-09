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

#ifndef _LIBMHO_PROT_H
# define _LIBMHO_PROT_H

# define MHO_VM_PROT_NONE 0x00
# define MHO_VM_PROT_READ 0x01
# define MHO_VM_PROT_WRITE 0x02
# define MHO_VM_PROT_EXECUTE 0x04
# define MHO_VM_PROT_DEFAULT (MHO_VM_PROT_READ|MHO_VM_PROT_WRITE)
# define MHO_VM_PROT_ALL (MHO_VM_PROT_READ|MHO_VM_PROT_WRITE|MHO_VM_PROT_EXECUTE)

#endif
