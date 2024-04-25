# Simple Shell
## Description
This is a simple shell written in C language.  This simple shell emulates a UNIX shell, handling the basics functionalities and commands with arguments.  It works in interactive and non interactive mode. This project was the last task required to pass the first trimester. It had requirements and some parameters we had to follow in order to achieve our goal. The parameters were as follows:

## General requirements
-   Allowed editors: `vi`, `vim`, `emacs`
-   All your files will be compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
-   All your files should end with a new line
-   A `README.md` file, at the root of the folder of the project is mandatory
-   Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/hs-hq/Betty/blob/master/betty-doc.pl "betty-doc.pl")
-   Your shell should not have any memory leaks
-   No more than 5 functions per file
-   All your header files should be include guarded
 
## Allowed funcitons
-   all functions from string.h
-   `access` (man 2 access)
-   `chdir` (man 2 chdir)
-   `close` (man 2 close)
-   `closedir` (man 3 closedir)
-   `execve` (man 2 execve)
-   `exit` (man 3 exit)
-   `_exit` (man 2 _exit)
-   `fflush` (man 3 fflush)
-   `fork` (man 2 fork)
-   `free` (man 3 free)
-   `getcwd` (man 3 getcwd)
-   `getline` (man 3 getline)
-   `getpid` (man 2 getpid)
-   `isatty` (man 3 isatty)
-   `kill` (man 2 kill)
-   `malloc` (man 3 malloc)
-   `open` (man 2 open)
-   `opendir` (man 3 opendir)
-   `perror` (man 3 perror)
-   `printf` (man 3 printf)
-   `fprintf` (man 3 fprintf)
-   `vfprintf` (man 3 vfprintf)
-   `sprintf` (man 3 sprintf)
-   `putchar` (man 3 putchar)
-   `read` (man 2 read)
-   `readdir` (man 3 readdir)
-   `signal` (man 2 signal)
-   `stat` (__xstat) (man 2 stat)
-   `lstat` (__lxstat) (man 2 lstat)
-   `fstat` (__fxstat) (man 2 fstat)
-   `strtok` (man 3 strtok)
-   `wait` (man 2 wait)
-   `waitpid` (man 2 waitpid)
-   `wait3` (man 2 wait3)
-   `wait4` (man 2 wait4)
-   `write` (man 2 write)

## Compilation
The program will be compiled this way: 

``` gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh ```

To execute the simple shell:
``` ./hsh ```

## Example of simple shell
This the simple shell in interactive mode:
```
$ ls
file1  file2  file3  hsh
$ pwd
/home/michael/Pruebas/READMe_
$ echo Hello World!
Hello World!
$ /bin/ls
file1  file2  file3  hsh
$ /bin/pwd
/home/michael/Pruebas/READMe_
$ /bin/echo Hello World!
Hello World!
``` 

This is the simple shell in non interactive mode:
```
$ echo "/bin/mkdir test_repo" | ./hsh
$ echo "/bin/ls" | ./hsh
file1 file2 file 3 hsh test_repo
```
## Authors

- Alex Carrasquillo - alexmd11@live.com
- Christian Diaz - christianda3@gmail.com
- Michael Hernandez - 9013@holbertonstudents.com


