# libMhO
Mach-O support library for non-Mach systems.
## Why this?
This solution does not require any high-level libraries, such as BFD. It uses its own mechanism, prepared especially for Mach-O (anything prepared uniquely for this must be better than something generic).
It also seems to be pretty fast (it may cause SIGSEGVs if file is inaccessible, because it does little checks). **This library does not support and will never support ar(5) archives!**. This library is
just for manipulating object files.
## Features:
 - ANSI C
 - Low requirements
 - Endian interface
 - Data can be read by high-level, endian caring solutions, or just by fread.
 - API + CLI = **SUCCESS**
 - mho\_ and MHO\_ prefix before anything declared - name safety
 - Not limited by any standards
 - Good English (I'm B2)
