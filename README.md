# Project 0x15 - simple_shell

The goal of this project was to build a very simple version of the UNIX command language interpreter. The shell should display a prompt that would allow a user to type in a command. Once the command is executed, the prompt will display again. The command line is able to handle errors or display an error message if a command is not executable. 

## Getting Started

The following instructions will allow you to get you a copy of our shell (squirtle) up and running on your local machine! The lastest version of the MASTER branch should be git cloned in order to begin using the shell.

### Prerequisites
```
Basic understanding of what a shell is and how it works.
Ubuntu LTS v14.04
GCC should be installed on terminal in order to compile.
```

### Installing

A step by step series of examples that tell you how to get a development env running

1. Cloning the repo

```
git clone https://github.com/747-diego/SquirtleSquirtle.git
```

2. Compile all .h(header) and .c(files written in c, that can be compiled) files using GCC

```
$ gcc shell.h squirtle.c vect.c helperfunctions.c PATH.c -o hsh
```

3. Run the executable file
```
$ ./hsh
```

4. Enjoy using squirtle shell!

```
$ 
```

## Built With

* [Emacs](https://www.gnu.org/software/emacs/) - The best text editor.
* [Virtual Box](https://www.virtualbox.org) - Virtual Machine creator.
* [Vagrant](https://www.vagrantup.com) - VM environments mangaer.

## See Other Files

File|Description
---|---
[shell.h](./shell.h)|header
[squirtle.c](./squirtle.c)|main point for shell
[helperfunctions.c](./helperfunctions.c)|built-in support functions
[PATH.c](./PATH.c)|looks for path in env
[vect.c](./vect.c)|token function
[man_1_simple_shell](./man_1_simple_shell)|man page
[authors](./authors)|author page

---
## Authors

* **Alisha Smith** - [Alisha Smith](https://github.com/alishabelle)
* **Diego Tardio** - [Diego Tardio](https://github.com/747-diego)

## License

This project does not have a license. Built in accordance to the Holberton Guidelines by Holberton Students.