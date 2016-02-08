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
 - mho\_ and MHO\_ prefix before anything declared - namespace safety and clearness
 - Not limited by any standards
 - Good English (I'm on level B2)
## Building
### Prerequirements
**SKIP THIS STEP IF YOU HAVE ALREADY FILES: _Makefile.in_, _configure.ac_, _configure_ and _m4/libtool.m4_**
 - [Perl](http://www.perl.org)
 - [GNU M4](http://www.gnu.org/software/m4)
 - [GNU Autoconf](http://www.gnu.org/software/autoconf)
 - [GNU Automake](http://www.gnu.org/software/automake)
 - [GNU Libtool](http://www.gnu.org/software/libtool)
Note that M4 does not depend on Perl.
Please install these in order given to get more benefits from co-installation and do this task faster. Notice that in fact instead of downloading sources (which may be heavy, like of Perl), you **may**
try using binary distributions. In such case please download:
 - A binary package for M4
 - Perl core
 - Basic modules for Perl (when running autoconf or automake you will notice if you did not download required module)
 - Autoconf (should be one package)
 - Automake (should be one package)
 - Libtool (should be one package, if also there is a package called _libtool-dev_, get it too)
 - autoconf-dev (if present)
### Configuration
#### Getting M4 files for libtool and ltmain.sh
The _.gitignores_ say there should be omitted some files, all matching regular expression _^l[it][a-z~]+\.m4$_. These files are **Libtool macro definitions**. They are essential when configuring, so they
need to be fetched. Also, one file in _build-aux_ is omitted the same reason - _ltmain.sh_. All these files can be grabbed by doing:
	libtoolize -c
The _-c_ option is not required, but it makes libtoolize copy, not symlink files, which is better. If some files left, you may use _-f_ option to force overwriting them.
#### Loading macros
This step will probably last the most, because aclocal is pretty slow. To link all M4 files into one, we use:
	aclocal -I m4
This will collect all files in system, Automake's and our location. Yes, option _-I_ is similar to one in GCC; it is used to specify include directories for M4. But including is term different in GCC and
M4. A macro file is included if it contains definition, **not override** of macro called from another file. I don't know what about infinite recursion. This step probably can't be done by you manually.
Trust aclocal. I do.
#### Getting configuration step
**AFTER THIS STEP DO NOT RUN _./configure_! THIS IS NOT THE LAST!**
The _configure.ac_ seems to be a M4 file, it's similar to Libtool ones. Instead of definitions, there are more calls. This is a **configuration script template**. You can modify it, but you may spoil
something. The best way is to trust me and use the file unchanged. The command to create _configure_ shell script (very portable) from _configure.ac_ is:
	autoconf
This will do the task.
#### Creating _Makefile.in_s
**AFTER THIS STEP DO NOT RUN MAKE! THIS DOES NOT CREATE _Makefile_s!**
There are files called _Makefile.am_ in most subdirectories. We need _Makefile_s. The middle step in this conversion is _Makefile.in_. To generate it, a program has to trace substainations in autoconf,
place variables in _Makefile.in_, push _Makefile.am_ there and add some make rules. This seems complete Makefile. **NO!** This has many sequences like:
	CC=@CC@
Your C compiler is not _@CC@_.
To generate _Makefile_s, call
	automake --add-missing --copy
This will also add missing auxiliary files. _--copy_ can be omitted, but this will result in symlinking instead of copying files.
#### Configuring
Finally the last step! The name of this step in fact comes from name of configure script: _configure_. You can run it using:
 - _./configure_ - Use system shell
 - _sh configure_ - Use system shell
 - _bash configure_ - Use GNU bash (recommended)
 - _xxx configure_ - Use _xxx_ shell
You may also pass some command-line arguments. The most important are:
 - _--disable-shared_ - Build only static libraries (default: no)
 - _--disable-static_ - Build only shared libraries (default: no)
Note that disabling both library types is stupid.
 - _--without-pic_ - Disable Position Independ Compilation (PIC). This will probably have same consequences as _--disable-shared_. (default: no)
 - _--prefix=/my/prefix_ - Change prefix to _/my/prefix_ (default: _/usr/local_)
 - _CC=my-cc_ - Change C compiler to _my-cc_
 - _--exec-prefix=/binary/prefix_ - Change prefix for platform dependent files to _/binary/prefix_ (default: the value of _--prefix_)
 - _-C_ - Cache test results, speed up reconfigurations
 - _--enable-silent-rules_ - Enable silent rules (e.g. _CC test.lo_ instead of _libtool: link: gcc -o test.lo test.c_)
There are many other possibilities; invoke configure with _--help_ parameter to get more help.
### Compilation
To compile the package, run _make_.
#### Reconfiguration
Some helpers will re-generate all files you have generated. They also will call a command, called _config.status_. This magic file is a _configure_ result manager. It will run:
	config.status --recheck
	config.status
The first will re-run configure, with all settings same as first. Second will regenerate all _Makefile_s, etc.
#### Compilation
Depending on your settings, you may have long lines with compilation commands or short mnemonics. The compilation will first compile all source files to objects (this has mnemonic _CC_ or GCC option
_-c_), then link them (this has mnemonic _CCLD_ or no GCC option _-c_). The second time _make_ runs, it will recompile only these objects whose source files changed and relink these binaries, whose
objects changed.
#### Tests
To test libMhO, run _make check_.
#### Installation
To install platform-independent files in _prefix_ and others in _exec-prefix_, invoke:
	make install
You can revert it:
	make uninstall
#### Invoking a rule
Imagine a make rule _myrule_. Invoking it is simple:
	make myrule
#### More rules
Read [http://www.gnu.org/software/automake/manual/automake.html](Automake manual)
