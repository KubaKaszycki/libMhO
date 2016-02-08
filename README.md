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
 - mho\` and MHO\` prefix before anything declared - namespace safety and clearness
 - Not limited by any standards
 - Good English (I'm on level B2)

## Building
### Prerequirements
**SKIP THIS STEP IF YOU HAVE ALREADY FILES: `Makefile.in`, `configure.ac`, `configure` and `m4/libtool.m4`**
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
 - Libtool (should be one package, if also there is a package called `libtool-dev`, get it too)
 - autoconf-dev (if present)

### Configuration
#### Getting M4 files for libtool and ltmain.sh
The `.gitignores` say there should be omitted some files, all matching regular expression `^l[it][a-z~]+\.m4$`. These files are **Libtool macro definitions**. They are essential when configuring, so they
need to be fetched. Also, one file in `build-aux` is omitted the same reason - `ltmain.sh`. All these files can be grabbed by doing:

	libtoolize -c

The `-c` option is not required, but it makes libtoolize copy, not symlink files, which is better. If some files left, you may use `-f` option to force overwriting them.

#### Loading macros
This step will probably last the most, because aclocal is pretty slow. To link all M4 files into one, we use:

	aclocal -I m4

This will collect all files in system, Automake's and our location. Yes, option `-I` is similar to one in GCC; it is used to specify include directories for M4. But including is term different in GCC and
M4. A macro file is included if it contains definition, **not override** of macro called from another file. I don't know what about infinite recursion.

This step probably can't be done by you manually.
Trust aclocal. I do.

#### Getting configuration file
**AFTER THIS STEP DO NOT RUN `./configure`! THIS IS NOT THE LAST!**
The `configure.ac` seems to be a M4 file, it's similar to Libtool ones. Instead of definitions, there are more calls. This is a **configuration script template**. You can modify it, but you may spoil
something. The best way is to trust me and use the file unchanged. The command to create `configure` shell script (very portable) from `configure.ac` is:

	autoconf

This will do the task.

#### Creating Makefile.in
**AFTER THIS STEP DO NOT RUN MAKE! THIS DOES NOT CREATE `Makefile` files!**

There are files called `Makefile.am` in most subdirectories. We need `Makefile` files. The middle step in this conversion is `Makefile.in`. To generate it, a program has to trace substainations in autoconf,
place variables in `Makefile.in`, push `Makefile.am` there and add some make rules. This seems complete Makefile. **NO!** This has many sequences like:

	CC=@CC@

Your C compiler is not `@CC@`.
To generate `Makefile`s, call

	automake --add-missing --copy

This will also add missing auxiliary files. `--copy` can be omitted, but this will result in symlinking instead of copying files.

#### Configuring
Finally the last step! The name of this step in fact comes from name of configure script: `configure`. You can run it using:
 - `./configure` - Use system shell
 - `sh configure` - Use system shell
 - `bash configure` - Use GNU bash (recommended)
 - `xxx configure` - Use `xxx` shell
You may also pass some command-line arguments. The most important are:
 - `--disable-shared` - Build only static libraries (default: no)
 - `--disable-static` - Build only shared libraries (default: no)
Note that disabling both library types is stupid.
 - `--without-pic` - Disable Position Independ Compilation (PIC). This will probably have same consequences as `--disable-shared`. (default: no)
 - `--prefix=/my/prefix` - Change prefix to `/my/prefix` (default: `/usr/local`)
 - `CC=my-cc` - Change C compiler to `my-cc`
 - `--exec-prefix=/binary/prefix` - Change prefix for platform dependent files to `/binary/prefix` (default: the value of `--prefix`)
 - `-C` - Cache test results, speed up reconfigurations
 - `--enable-silent-rules` - Enable silent rules (e.g. `CC test.lo` instead of `libtool: link: gcc -o test.lo test.c`)
There are many other possibilities; invoke configure with `--help` parameter to get more help.

### Compilation
To compile the package, run `make`.

#### Reconfiguration
Some helpers will re-generate all files you have generated. They also will call a command, called `config.status`. This magic file is a `configure` result manager. It will run:

	config.status --recheck
	config.status

The first will re-run configure, with all settings same as first. Second will regenerate all `Makefile`s, etc.

#### Compilation
Depending on your settings, you may have long lines with compilation commands or short mnemonics. The compilation will first compile all source files to objects (this has mnemonic `CC` or GCC option
`-c`), then link them (this has mnemonic `CCLD` or no GCC option `-c`). The second time `make` runs, it will recompile only these objects whose source files changed and relink these binaries, whose
objects changed.

#### Tests
To test libMhO, run `make check`.

#### Installation
To install platform-independent files in `prefix` and others in `exec-prefix`, invoke:

	make install

You can revert it:

	make uninstall

#### Invoking a rule
Imagine a make rule `myrule`. Invoking it is simple:

	make myrule

#### More rules
Read [GNU Automake manual](http://www.gnu.org/software/automake/manual/automake.html)
