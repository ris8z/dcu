USER MANUAL

Linux more command
Updated: 11/06/2021 by Computer Hope
more command

On Unix-like operating systems, the more command displays text, one screen at a time.

This page covers the GNU/Linux version of more.

    Description
    Syntax
    Commands
    Environment
    Examples
    Related commands
    Linux commands help

Description

more is a filter for paging through text one screen at a time. It does not provide as many options or enhancements as less, but is nevertheless quite useful and simple to use.
Syntax

more [-dlfpcsu] [-num lines] [+/pattern] [+linenum] [file ...]

Options
-num lines 	Sets the number of lines that makes up a screenful. The lines must be an integer.
-d 	With this option, more prompts the user with the message "[Press space to continue, 'q' to quit.]" and display "[Press 'h' for instructions.]" when an illegal key is pressed, instead of ringing a bell.
-l 	more usually treats ^L (CONTROL-L, the form feed) as a special character, and pauses after any line containing it. The -l option prevents this behavior.
-f 	Causes more to count logical, rather than screen lines (i.e., long lines are not wrapped).
-p 	Do not scroll. Instead, clear the whole screen and then display the text. This option is switched on automatically if the more executable is named page.
-c 	Do not scroll. Instead, paint each screen from the top, clearing the remainder of each line as it is displayed.
-s 	Squeeze multiple blank lines into one blank line.
-u 	Do not display underlines.
+/string 	Search for the string string, and advance to the first line containing string when the file is displayed.
+num 	Start displaying text at line number num.
Commands

When displaying a file, more can be controlled with a set of commands loosely based on the text editor vi. Some commands can be preceded by a decimal number, named k in the following descriptions.
h, ? 	Show help (display a brief command summary). If you forget all the other commands, remember this one!
[k]SPACE 	Pressing the spacebar displays the next k lines of text. If k is not specified, more displays a full screen of new text.
[k]z 	Like pressing SPACE, but k becomes the new default number of lines to display.
[k]RETURN 	Pressing Enter or Return displays next k lines of text. The default is 1 line. If specified, k becomes the new default.
[k]d, [k]^D 	Pressing d or CONTROL-D scrolls k lines. The default is the current scroll size, which is initially 11 lines. If specified, k becomes the new default.
q, Q, ^C 	Pressing q, Q, or CONTROL-C (the interrupt key) exits the program.
[k]s 	Skip forward k lines of text. Defaults to 1.
[k]f 	Skip forward k screenfuls of text. Defaults to 1.
b, ^B 	Pressing b or CONTROL-B skips backward k lines of text. Defaults to 1. (This only works when viewing files, not piped input).
' 	Go to the place where the previous search started.
= 	Display the current line number.
[k]/pattern 	Search for the kth occurrence of the regular expression pattern. Defaults to 1.
[k]n 	Search for the kth occurrence of the last regular expression searched for, which defaults to 1.
!command, :!command 	Execute command in a subshell.
v 	Start up an editor at current line. The editor is taken from the environment variable VISUAL if it's defined, or EDITOR if VISUAL is undefined; if neither is defined, defaults to "vi".
^L 	Pressing CONTROL-L redraws the screen.
[k]:n 	Go to the kth next file. Defaults to 1.
[k]:p 	Go to the kth previous file. Defaults to 1.
:f 	Display the current file name and line number.
. 	Repeat previous command.
Environment

more uses the values of the following environment variables, if they are defined:
MORE 	Default more options. If this variable is set, more reads as the default set of options to use. Any options specified on the command line override the options specified in $MORE.
SHELL 	The current shell in use (this variable is normally set by the shell itself at login time).
TERM 	The current terminal type. This value is used by more to determine the proper way to manipulate the screen.
Examples

more +3 myfile.txt

Display the contents of file myfile.txt, beginning at line 3.

more +/"hope" myfile.txt

Display the contents of file myfile.txt, beginning at the first line containing the string "hope".

ls | more

List the contents of the current directory with ls, using more to display the list one screen at a time.
Related commands

cat — Output the contents of a file.
csh — The C shell command interpreter.
ctags — Create tag files for source code.
less — Scrolling text viewer.
man — Display the manual page of a given command.
nroff — Format documents for terminal display or line-printer.
script — Record everything printed on your screen.
sh — The Bourne shell command interpreter.
ul — Translate underscores to underlining.

