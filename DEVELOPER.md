# Developer notes
## Coding style
We use here modified GNU coding style. Everything goes indented with two spaces, macros by one space. This is equivalent to call
to GNU indent:

	indent -gnu file

If you have this tool, I kindly ask you to put some effort and format the files.

## Useful code snippets
If working directory is not mentioned, I mean SOURCES ROOT.

### Indent all sources

	for X in `find . | grep -E '\.[ch]$' | grep -vF 'gnulib' | grep -vF 'intl'`; do indent -gnu $X; done

Before calling this, ensure two things:
 - You don't have important environment variable X (would be overwritten)
 - You know what you do

### Delete all temporary files

	for X in `find . | grep -E '(\~|\.BAK)$'`; do rm -rf $X; done

Delete all temporary/backup files (ending with ~ or .BAK).

## Your private scripts
.gitignore mentions that each file with name \_\_priv\_\_ will be omitted from commit. This can be file or directory with
your private stuff. I have some useful scripts there. To get a copy, mail me:
[Jakub Kaszycki](mailto:kaszycki@mail.com?subject=libMhO+__priv__+scripts).
