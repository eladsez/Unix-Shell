# Unix-Shell
> Made by Elad Seznayev and Nerya Bigon


This project is a shell program made as an assignment for advanced programming course.

### Project Structure

    .
    ├── docs                    # Documentation and video files 
    ├── src                     # Source files
    ├── obj                     # Auto generated and auto deleted files (using make)
    ├── LICENSE
    └── README.md

# Some Possible Commands

All the bash usual commands work as they usually do.
- In addition, we've implemented all the required custom commands in the assignment

`quit` - exits the shell.

`cd` - change directory.  

`!!` - execute the last command.

`echo $?` - prints last command's status.

`$person = David` - variable declaration, also support change prompt with `prompt = <new prompt>` .

`read person` - wait for the user to input the person variable.

`echo` - prints what ever comes after the echo including variable as `echo $person`.

 `2>`, `>`, `>>` and `<` - redirect as usual as in bash (Note, make sure to put space between the command, the redirect, and the name of the file after the redirect)

You can use `|` pipe freely as you can see in the following video:    

https://user-images.githubusercontent.com/66886354/230582539-709448ae-4288-4740-85df-977cb6cac1af.webm  

   
     
      
### Logic
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
 cmake-build-debug   myshell	       pipe.webm	       src
 LICENSE	     myshell_history   README.md	       task1.pdf
 Makefile	     obj	      'running example.webm'
hello
```
Or alternatively (our implementation also supports this syntax):
```
if ls
then
echo hello
fi
```
Which will result with the same output.


We've also implemented navigation through the command history using the UP/DOWN arrow keys, this feature work as in bash - meaning you just need to go up and down between the commands and press `Enter` to execute. (not press enter to retrieve the command from history to the shell)

# Running Example

https://user-images.githubusercontent.com/66886354/230582545-40a3a4cc-e035-420f-9f58-67b76e164dee.webm



# How To Use
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
