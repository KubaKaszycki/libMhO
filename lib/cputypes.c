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

#include <libmho/cputype.h>

const char     *
mho_ct2s(mho_cpu_type_t type)
{
	switch (type) {
	case MHO_CT_ANY:
		return "any CPU (any vendor)";
	case MHO_CT_VAX:
		return "VAX (Digital Equipment Corporation)";
	case MHO_CT_ROMP:
		return "Research OPD Micro Processor (IBM)";
	case MHO_CT_NS32032:
		return "NS32032 (National Semiconductor)";
	case MHO_CT_NS32332:
		return "NS32332 (National Semiconductor)";
	case MHO_CT_MC680x0:
		return "m68k";
	case MHO_CT_I386:
		return "x86 (Intel)";
	case MHO_CT_X86_64:
		return "x86 64-bit (Intel)";
	case MHO_CT_MIPS:
		return "mips";
	case MHO_CT_NS32532:
		return "NS32532 (National Semiconductor)";
	case MHO_CT_HPPA:
		return "hppa";
	case MHO_CT_ARM:
		return "arm";
	case MHO_CT_ARM64:
		return "arm64";
	case MHO_CT_MC88000:
		return "m88k";
	case MHO_CT_SPARC:
		return "sparc";
	case MHO_CT_I860:
		return "i860-big";
	case MHO_CT_I860_LITTLE:
		return "i860";
	case MHO_CT_RS6000:
		return "rs6000";
	case MHO_CT_POWERPC:
		return "ppc";
	case MHO_CT_POWERPC64:
		return "ppc64";
	default:
		return "unknown";
	}
}

const char     *
mho_cst2s(mho_cpu_type_t type, mho_cpu_subtype_t subtype)
{
	subtype &= 0xFF;
	switch (type) {
	case MHO_CT_ANY:
		return "any";
	case MHO_CT_VAX:
		switch (subtype) {
		case MHO_CST_VAX_ALL:
			return "all VAX";
		case MHO_CST_VAX780:
			return "VAX-11/780";
		case MHO_CST_VAX785:
			return "VAX-11/785";
		case MHO_CST_VAX750:
			return "VAX-11/750";
		case MHO_CST_VAX730:
			return "VAX-11/730";
		case MHO_CST_UVAXI:
			return "UVAXI";
		case MHO_CST_UVAXII:
			return "UVAXII";
		case MHO_CST_VAX8200:
			return "VAX 8200";
		case MHO_CST_VAX8500:
			return "VAX 8500";
		case MHO_CST_VAX8600:
			return "VAX 8600";
		case MHO_CST_VAX8650:
			return "VAX 8650";
		case MHO_CST_VAX8800:
			return "VAX 8800";
		case MHO_CST_UVAXIII:
			return "UVAXIII";
		default:
			return "unknown VAX";
		}
	case MHO_CT_ROMP:
		switch (subtype) {
		case MHO_CST_RT_ALL:
			return "any ROMP";
		case MHO_CST_RT_PC:
			return "RT/PC";
		case MHO_CST_RT_APC:
			return "RT/APC";
		case MHO_CST_RT_135:
			return "RT/135";
		default:
			return "unknown ROMP";
		}
	case MHO_CT_NS32032:
		switch (subtype) {
		case MHO_CST_MMAX_ALL:
			return "all 32032";
		case MHO_CST_MMAX_DPC:
			return "32032 with DPC";
		case MHO_CST_SQT:
			return "32032 with SQT";
		case MHO_CST_MMAX_APC_FPU:
			return "32032 with FPU";
		case MHO_CST_MMAX_APC_FPA:
			return "32032 with FPA";
		case MHO_CST_MMAX_XPC:
			return "32032 with XPC";
		default:
			return "unknown 32032";
		}
	case MHO_CT_NS32332:
		switch (subtype) {
		case MHO_CST_MMAX_ALL:
			return "all 32332";
		case MHO_CST_MMAX_DPC:
			return "32332 with DPC";
		case MHO_CST_SQT:
			return "32332 with SQT";
		case MHO_CST_MMAX_APC_FPU:
			return "32332 with FPU";
		case MHO_CST_MMAX_APC_FPA:
			return "32332 with FPA";
		case MHO_CST_MMAX_XPC:
			return "32332 with XPC";
		default:
			return "unknown 32332";
		}
	case MHO_CT_NS32532:
		switch (subtype) {
		case MHO_CST_MMAX_ALL:
			return "all 32532";
		case MHO_CST_MMAX_DPC:
			return "32532 with DPC";
		case MHO_CST_SQT:
			return "32532 with SQT";
		case MHO_CST_MMAX_APC_FPU:
			return "32532 with FPU";
		case MHO_CST_MMAX_APC_FPA:
			return "32532 with FPA";
		case MHO_CST_MMAX_XPC:
			return "32532 with XPC";
		default:
			return "unknown 32532";
		}
	case MHO_CT_I386:
		switch (subtype) {
		case MHO_CST_I386_ALL:
			return "any x86";
		case MHO_CST_386:
			return "i386";
		case MHO_CST_486:
			return "i486";
		case MHO_CST_586:
			return "i586 (Pentium)";
		case MHO_CST_686:
			return "i686";
		case MHO_CST_786:
			return "i786";
		case MHO_CST_HASWELL:
			return "Haswell";
		case MHO_CST_PENTPRO:
			return "Pentium Pro";
		case MHO_CST_PENTII_M3:
			return "Pentium II M3";
		case MHO_CST_PENTII_M5:
			return "Pentium II M5";
		case MHO_CST_PENTIUM_4:
			return "Pentium 4";
		default:
			return "unknown x86";
		}
	case MHO_CT_X86_64:
		switch (subtype) {
		case MHO_CST_X86_64_ALL:
			return "any x86 (64-bit)";
		case MHO_CST_386:
			return "i386 (64-bit)";
		case MHO_CST_486:
			return "i486 (64-bit)";
		case MHO_CST_586:
			return "i586 (Pentium, 64-bit)";
		case MHO_CST_686:
			return "i686 (64-bit)";
		case MHO_CST_786:
			return "i786 (64-bit)";
		case MHO_CST_HASWELL:
			return "Haswell (64-bit)";
		case MHO_CST_PENTPRO:
			return "Pentium Pro (64-bit)";
		case MHO_CST_PENTII_M3:
			return "Pentium II M3 (64-bit)";
		case MHO_CST_PENTII_M5:
			return "Pentium II M5 (64-bit)";
		case MHO_CST_PENTIUM_4:
			return "Pentium 4 (64-bit)";
		default:
			return "unknown x86 (64-bit)";
		}
	default:
		return "unknown";
	}
}
