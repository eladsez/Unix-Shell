# Unix-Shell
> Made by Elad Seznayev and Nerya Bigon


This project is a shell program made as an assignment for advanced programming course.

# Some Possible Commands

Most of the bash usual commands should work as they usually do.

`quit` - exits the shell.

`echo` - prints what ever comes after the `echo`.

`cd` - change directory.  

`ls` - list the content of the current directory.

`!!` - execute the last command.

`echo $?` - prints last command's status.

`$person = David` - variable decleration.

`>` and `>>` - redirect as usual as in bash.

You can use `|` (pipes) freely.  

You can use logic (e.g. if/else) with the following syntax:
```
if <command>
then
<command>
else
<command>
```
For example:  
```
if ls
then
echo hello
else
echo hello world
```
Which will result with:
```
cmd_helper.c history.c LICENSE main.o   myshell README.md  shell_lib.a  util.c 
cmd_helper.o history.o main.c   Makefile myshell_history shell.h  task1.pdf  util.o
hello
```
We've also implemented nvaigation through the command history using the UP/DOWN arrow keys. 

# Video



# HowTo Use
1. Download this repository.
2. Extract the files.
3. Open a terminal in the main directory of the project and execute the following command:
```
make all
```
4. To activate the shell execute:
```
./myshell
```

5. To clean all the files created execute:
```
make clean
```
