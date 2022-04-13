# 0x16. C - Simple Shell

![Team project Simple Shell](./pictures/shell.png)

## Installation

This project was realised on **Ubuntu 20.04 LTS** and compiled with **GCC 9.4.0**. Depending on the changes, it may not work on future version. If you want to download and test our project, follow these steps:

```
$ git clone git@github.com:adut24/simple_shell.git
$ cd simple_shell
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Description
The Simple Shell is the second team project realised in Holberton School. The purpose is to replicate the shell (`sh`) present in Linux. The shell takes different prompts and interprets them to execute them.

## Output

This simple shell works in "interactive mode":
```
$ ./hsh
> /bin/ls
hsh main.c shell.c
```

As well as in "non-interactive mode":
```
$ echo "ls" | ./hsh
hsh main.c shell.c
$ cat test_ls_2
ls
ls
$ cat test_ls_2 | ./hsh
hsh main.c shell.c
hsh main.c shell.c
```

## Specifications present
| Specification | Description |
| --- | --- |
| `/bin/ls` | Command executed by putting the path of it |
| `pwd` | Command executed by just putting the command |
| `ls -l` | Handle arguments to the command |
| `exit [status]` | built-in to exit with a specific status |
| `env` | built-in to print all the environment variables |
