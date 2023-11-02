# Simple Shell
- Write a simple UNIX command interpreter.

## Authors
1. [Shonisani Netshidzivhani](https://github.com/Sanieeme)
2. [Mthabisi Ndlovu](https://github.com/blvck-root)

## Introduction
The Simple Shell project challenged everything we learned about the fundamentals of programming in C, thinking like an engineer, problem solving, learning how to learn, and collaborating with others.

## Learning Objectives
Be able to explain to anyone in simple terms:
- How does the shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of `main`
- How does the shell use the `PATH` to find the programs
- How to execute another program with the `execve` system call
- How to suspend the execution of a process until one of its children terminates
- What is `EOF`/"end-of-file"?

## Requirements
- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 20.04 LTS using `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- Your code should use the `Betty` style. It will be checked using `betty-style.pl` and `betty-doc.pl`
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when absolutely necessary
- Write a `README` with the description of your project
- Add an `AUTHORS` file at the root of your repository, listing all individuals who contributed to the project.

## More Info
### Output
- Unless specified otherwise, the program must have the exact same output as sh (/bin/sh) as well as the exact same error output.

### List of allowed functions and system calls
- `access`
- `chdir`
- `close`
- `closedir`
- `execve`
- `exit`
- `_exit`
- `fflush`
- `fork`
- `free`
- `getcwd`
- `getline`
- `getpid`
- `isatty`
- `kill`
- `malloc`
- `open`
- `opendir`
- `perror`
- `read`
- `readdir`
- `signal`
- `stat`
- `lstat`
- `fstat`
- `strtok`
- `wait`
- `waitpid`
- `wait3`
- `wait4`
- `write`

### Compilation
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

### Testing
The shell should work in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

