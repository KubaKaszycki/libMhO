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

#include <libmho/cputype.h>
#include <gettext.h>

#undef _
#define _(x) dgettext("libmho", x)

const char *
mho_ct2s (mho_cpu_type_t type)
{
  switch (type)
    {
    case MHO_CT_ANY:
      return _("any CPU (any vendor)");
    case MHO_CT_VAX:
      return _("VAX (Digital Equipment Corporation)");
    case MHO_CT_ROMP:
      return _("Research OPD Micro Processor (IBM)");
    case MHO_CT_NS32032:
      return _("NS32032 (National Semiconductor)");
    case MHO_CT_NS32332:
      return _("NS32332 (National Semiconductor)");
    case MHO_CT_MC680x0:
      return _("M68k (Motorola)");
    case MHO_CT_I386:
      return _("x86 (Intel)");
    case MHO_CT_X86_64:
      return _("x86 64-bit (Intel)");
    case MHO_CT_MIPS:
      return _("Mips (Mips Computer Systems)");
    case MHO_CT_NS32532:
      return _("NS32532 (National Semiconductor)");
    case MHO_CT_HPPA:
      return _("HPPA (Hewlett-Packard)");
    case MHO_CT_ARM:
      return _("ARM (ARM Holdings)");
    case MHO_CT_ARM64:
      return _("AArch64 (ARM Holdings)");
    case MHO_CT_MC88000:
      return _("M88k (Motorola)");
    case MHO_CT_SPARC:
      return _("SPARC (Sun)");
    case MHO_CT_SPARC64:
      return _("SPARC 64-bit (Sun)");
    case MHO_CT_I860:
      return _("i860 big endian (Intel)");
    case MHO_CT_I860_LITTLE:
      return _("i860 (Intel)");
    case MHO_CT_RS6000:
      return _("RS6000 (IBM)");
    case MHO_CT_POWERPC:
      return _("PowerPC (Apple+IBM+Motorola)");
    case MHO_CT_POWERPC64:
      return _("PowerPC 64-bit (Apple+IBM+Motorola)");
    default:
      return _("Unknown");
    }
}

const char *
mho_cst2s (mho_cpu_type_t type, mho_cpu_subtype_t subtype)
{
  subtype &= 0xFF;
  switch (type)
    {
    case MHO_CT_ANY:
      return _("any");
    case MHO_CT_VAX:
      switch (subtype)
	{
	case MHO_CST_VAX_ALL:
	  return _("any VAX");
	case MHO_CST_VAX780:
	  return _("VAX-11/780");
	case MHO_CST_VAX785:
	  return _("VAX-11/785");
	case MHO_CST_VAX750:
	  return _("VAX-11/750");
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
      switch (subtype)
	{
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
      switch (subtype)
	{
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
      switch (subtype)
	{
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
      switch (subtype)
	{
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
      switch (subtype)
	{
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
      switch (subtype)
	{
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
    case MHO_CT_MIPS:
      switch (subtype)
	{
	case MHO_CST_MIPS_ALL:
	  return "any Mips";
	case MHO_CST_MIPS_R2300:
	  return "R2300";
	case MHO_CST_MIPS_R2600:
	  return "R2600";
	case MHO_CST_MIPS_R2800:
	  return "R2800";
	case MHO_CST_MIPS_R2000a:
	  return "R2000a";
	default:
	  return "unknown Mips";
	}
    case MHO_CT_MC680x0:
      switch (subtype)
	{
	case MHO_CST_MC68030:
	  return "MC68030";
	case MHO_CST_MC68040:
	  return "MC68040";
	case MHO_CST_MC68030_ONLY:
	  return "MC68030 only";
	default:
	  return "unknown M68K";
	}
    case MHO_CT_HPPA:
      switch (subtype)
	{
	case MHO_CST_HPPA_7100:
	  return "7100";
	case MHO_CST_HPPA_7100LC:
	  return "7100LC";
	default:
	  return "unknown HPPA";
	}
    case MHO_CT_ARM:
      switch (subtype)
	{
	case MHO_CST_ARM_ALL:
	  return "any ARM";
	case MHO_CST_ARM_A500_ARCH:
	  return "A500 ARCH";
	case MHO_CST_ARM_A500:
	  return "A500";
	case MHO_CST_ARM_A440:
	  return "A440";
	case MHO_CST_ARM_M4:
	  return "M4";
	case MHO_CST_ARM_V4T:
	  return "V4T";
	case MHO_CST_ARM_V6:
	  return "V6";
	case MHO_CST_ARM_V5TEJ:
	  return "V5TEJ";
	case MHO_CST_XSCALE:
	  return "XSCALE";
	case MHO_CST_ARM_V7:
	  return "V7";
	case MHO_CST_ARM_V7F:
	  return "V7F";
	case MHO_CST_ARM_V7S:
	  return "V7S";
	case MHO_CST_ARM_V7K:
	  return "V7K";
	case MHO_CST_ARM_V6M:
	  return "V6M";
	case MHO_CST_ARM_V7M:
	  return "V7M";
	case MHO_CST_ARM_V7EM:
	  return "V7EM";
	case MHO_CST_ARM_V8:
	  return "V8";
	default:
	  return "unknown ARM";
	}
    case MHO_CT_ARM64:
      switch (subtype)
	{
	case MHO_CST_ARM64_ALL:
	  return "any ARM (64-bit)";
	case MHO_CST_ARM64_V8:
	  return "V8 (64-bit)";
	default:
	  return "unknown ARM (64-bit)";
	}
    case MHO_CT_MC88000:
      switch (subtype)
	{
	case MHO_CST_MC88000_ALL:
	  return "any M88K";
	default:
	  return "unknown M88K";
	}
    case MHO_CT_POWERPC:
      switch (subtype)
	{
	default:
	  return "unknown PowerPC";
	}
    case MHO_CT_POWERPC64:
      switch (subtype)
	{
	default:
	  return "unknown PowerPC (64-bit)";
	}
    case MHO_CT_I860:
      switch (subtype)
	{
	default:
	  return "unknown I860";
	}
    case MHO_CT_I860_LITTLE:
      switch (subtype)
	{
	default:
	  return "unknown I860 (little-endian)";
	}
    case MHO_CT_RS6000:
      switch (subtype)
	{
	default:
	  return "unknown RS6000";
	}
    case MHO_CT_SPARC:
      switch (subtype)
	{
	default:
	  return "unknown SPARC";
	}
    case MHO_CT_SPARC64:
      switch (subtype)
	{
	default:
	  return "unknown SPARC";
	}
    default:
      return _("Unknown");
    }
}
