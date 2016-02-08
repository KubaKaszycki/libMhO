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

#include <libmho/types.h>

#ifndef _LIBMHO_CPUTYPE_H
#define _LIBMHO_CPUTYPE_H

#define MHO_CPU_SUBTYPE_MASK 0xff000000
#define MHO_ARCH_ABI64 0x01000000

#define MHO_CT_ANY (-1)
#define MHO_CT_VAX 1
#define MHO_CT_ROMP 2
#define MHO_CT_NS32032 4
#define MHO_CT_NS32332 5
#define MHO_CT_MC680x0 6
#define MHO_CT_I386 7
#define MHO_CT_X86 MHO_CT_I386
#define MHO_CT_X86_64 (MHO_CT_I386 | MHO_ARCH_ABI64)
#define MHO_CT_MIPS 8
#define MHO_CT_NS32532 9
#define MHO_CT_MC98000 10
#define MHO_CT_HPPA 11
#define MHO_CT_ARM 12
#define MHO_CT_ARM64 (MHO_CT_ARM | MHO_ARCH_ABI64)
#define MHO_CT_MC88000 13
#define MHO_CT_SPARC 14
#define MHO_CT_SPARC64 (MHO_CT_SPARC | MHO_ARCH_ABI64)
#define MHO_CT_I860 15
#define MHO_CT_I860_LITTLE 16
#define MHO_CT_RS6000 17
#define MHO_CT_POWERPC 18
#define MHO_CT_POWERPC64 (MHO_CT_POWERPC | MHO_ARCH_ABI64)

#define MHO_CST_MULTIPLE (-1)

// VAX
#define MHO_CST_VAX_ALL 0
#define MHO_CST_VAX780 1
#define MHO_CST_VAX785 2
#define MHO_CST_VAX750 3
#define MHO_CST_VAX730 4
#define MHO_CST_UVAXI 5
#define MHO_CST_UVAXII 6
#define MHO_CST_VAX8200 7
#define MHO_CST_VAX8500 8
#define MHO_CST_VAX8600 9
#define MHO_CST_VAX8650 10
#define MHO_CST_VAX8800 11
#define MHO_CST_UVAXIII 12

// ROMP
#define MHO_CST_RT_ALL 0
#define MHO_CST_RT_PC 1
#define MHO_CST_RT_APC 2
#define MHO_CST_RT_135 3

// NS32x32
#define MHO_CST_MMAX_ALL 0
#define MHO_CST_MMAX_DPC 1
#define MHO_CST_SQT 2
#define MHO_CST_MMAX_APC_FPU 3
#define MHO_CST_MMAX_APC_FPA 4
#define MHO_CST_MMAX_XPC 5

// i386
#define MHO_CST_I386_ALL 0
#define MHO_CST_X86_64_ALL MHO_CST_I386_ALL
#define MHO_CST_386 3
#define MHO_CST_486 4
#define MHO_CST_586 5
#define MHO_CST_686 6
#define MHO_CST_786 7
#define MHO_INTEL_CST(__family__, __model__) ((__family__) + ((__model__) << 4))
#define MHO_CST_PENT MHO_INTEL_CST(5, 0)
#define MHO_CST_PENTPRO MHO_INTEL_CST(6, 1)
#define MHO_CST_PENTII_M3 MHO_INTEL_CST(6, 3)
#define MHO_CST_PENTII_M5 MHO_INTEL_CST(6, 5)
#define MHO_CST_PENTIUM_4 MHO_INTEL_CST(10, 0)
#define MHO_CST_HASWELL 8
#define MHO_INTEL_FAMILY(x) ((x) & 0xF)
#define MHO_INTEL_MODEL(x) (((x) & 0xF0) >> 4)

// Mips
#define MHO_CST_MIPS_ALL 0
#define MHO_CST_MIPS_R2300 1
#define MHO_CST_MIPS_R2600 2
#define MHO_CST_MIPS_R2800 3
#define MHO_CST_MIPS_R2000a 4

// 680 x0
#define MHO_CST_MC680x0_ALL 1
#define MHO_CST_MC68030 1
#define MHO_CST_MC68040 2
#define MHO_CST_MC68030_ONLY 3

// HPPA
#define MHO_CST_HPPA_ALL 0
#define MHO_CST_HPPA_7100 0
#define MHO_CST_HPPA_7100LC 1

// ARM
#define MHO_CST_ARM_ALL 0
#define MHO_CST_ARM_A500_ARCH 1
#define MHO_CST_ARM_A500 2
#define MHO_CST_ARM_A440 3
#define MHO_CST_ARM_M4 4
#define MHO_CST_ARM_V4T 5
#define MHO_CST_ARM_V6 6
#define MHO_CST_ARM_V5TEJ 7
#define MHO_CST_XSCALE 8
#define MHO_CST_ARM_V7 9
#define MHO_CST_ARM_V7F 10
#define MHO_CST_ARM_V7S 11
#define MHO_CST_ARM_V7K 12
#define MHO_CST_ARM_V6M 14
#define MHO_CST_ARM_V7M 15
#define MHO_CST_ARM_V7EM 16
#define MHO_CST_ARM_V8 13

#define MHO_CST_ARM64_ALL 0
#define MHO_CST_ARM64_V8 1

// 88000
#define MHO_CST_MC88000_ALL 0
#define MHO_CST_MMAX_JPC 1
#define MHO_CST_MC88100 1
#define MHO_CST_MC88110 2

// 98000(PowerPC)
#define MHO_CST_MC98000_ALL 0
#define MHO_CST_MC98601 1

// i860
#define MHO_CST_I860_ALL 0
#define MHO_CST_I860 1

// i860 little - endian
#define MHO_CST_I860_LITTLE_ALL 0
#define MHO_CST_I860_LITTLE 1

// RS6000
#define MHO_CST_RS6000_ALL 0
#define MHO_CST_RS6000 1

// Sun4
#define MHO_CST_SUN4_ALL 0
#define MHO_CST_SUN4_260 1
#define MHO_CST_SUN4_110 2

// Sparc
#define MHO_CST_SPARC_ALL 0

// PowerPC
#define MHO_CST_POWERPC_ALL 0
#define MHO_CST_POWERPC_601 1
#define MHO_CST_POWERPC_602 2
#define MHO_CST_POWERPC_603 3
#define MHO_CST_POWERPC_603e 4
#define MHO_CST_POWERPC_603ev 5
#define MHO_CST_POWERPC_604 6
#define MHO_CST_POWERPC_604e 7
#define MHO_CST_POWERPC_620 8
#define MHO_CST_POWERPC_750 9
#define MHO_CST_POWERPC_7400 10
#define MHO_CST_POWERPC_7500 11
#define MHO_CST_POWERPC_970 100

// VEO
#define MHO_CST_VEO_ALL 0
#define MHO_CST_VEO_1 1
#define MHO_CST_VEO_2 2
#define MHO_CST_VEO_3 3
#define MHO_CST_VEO_4 4

	const char     *mho_ct2s(mho_cpu_type_t);
	const char     *mho_cst2s(mho_cpu_type_t, mho_cpu_subtype_t);

#endif
