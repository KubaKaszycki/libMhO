# Developer notes
## Coding style
We use here modified Berkeley coding style. Everything goes indented with a tab, macros by one space. This is equivalent to call
to GNU indent:

	indent -orig -ppi1 -i8 -ut file

If you have this tool, I kindly ask you to put some effort and format the files.

## Useful code snippets
If working directory is not mentioned, I mean SOURCES ROOT.

### Indent all sources

	for X in `find . | grep -E '\.[ch]$' | grep -vF 'gnulib'`; do indent -orig -ppi1 -i8 -ut $X; done

Before calling this, ensure two things:
 - You don't have important environment variable X (would be overwritten)
 - You know what you do

### Delete all temporary files

	for X in `find . | grep -E '(\~|\.BAK)$'`; do rm -rf $X; done

Delete all temporary/backup files (ending with ~ or .BAK).
