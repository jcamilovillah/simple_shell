<img src="https://pbs.twimg.com/media/EfpJUkaXkAAwhhT?format=jpg&name=900x900" alt="shell" width="1000">

# S I M P L E   S H E L L

## Introduction 🚀

The simple shell project is a collaboration between **Oscar De León** and **Juan Camilo Villa**, Full Stack Software Engineering students at **Holberton School**, with which we can emulate the operation of a shell, which contains some of its most basic characteristics, such as : Handle `PATH`, Handle command lines with `arguments`.

## Table of Contents
1. [Description](#description-)
2. [Requirements](#requirements-)
3. [Installation and Compilation](#installation-and-compilation)
4. [Example of Use](#example-of-use-)
5. [Authors](#authors-%EF%B8%8F)

## Description 📖

Holberton School Shell (hsh), is a simple program of the line commands. This simple shell recreates basic and some more complex functionalities to result in our own Shell. This shell si developed in the programming language c. This shell takes the keyboard commands and delivers them to the system to be executed. some built-in commands implement: exit, env, help, cd.

## Requirements 📋

Simple_shell is designed to run in the `Ubuntu 14.04 LTS` linux environment and to be compiled using the GNU compiler collection v. `gcc 4.8.4` with flags `-Wall, -Werror, -Wextra, and -pedantic`.

## Installation and Compilation🔧

Do you need clone [this repository](https://github.com/jcamilovillah/simple_shell):
```
	git clone https://github.com/jcamilovillah/simple_shell
```
and then you can compile with this command:
```
	gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
after compilation you can excecute with this command:
```
	./hsh
```

## Example of Use 💻

* Compile the program to create the `hsh` executable file (see instructions above).
* run the executable as follows `./hsh`
* Enter basic commands like: `ls`, you can add flags along with `ls` command such as `-l`, `-la`(`ls -l`, `ls -la`)
* press enter after entering the command
* to end the execution of the `simple_shell` program press `ctrl + d` or write the word `exit`

Your shell should work like this in interactive mode:
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
```
## Authors ✒️

<p align="left">
    <h3 align="left"> Oscar De León Giraldo </h3>
      <p align="left">
	   </a>
		<p align="left">
        <a href="https://twitter.com/oscardeleon95" target="_blank">
            <img alt="twitter_page" src="https://github.com/gedafu/readme-template/blob/master/images/twitter.png" style="float: center; margin-right: 10px" height="50" width="50">
        </a>
        <a href="https://www.linkedin.com/in/oscar-javier-de-le%C3%B3n-giraldo-aa712515b/" target="_blank">
            <img alt="linkedin_page" src="https://github.com/gedafu/readme-template/blob/master/images/linkedin.png" style="float: center; margin-right: 10px" height="50"  width="50">
        </a>
        <a href="https://medium.com/@1839" target="_blank">
            <img alt="medium_page" src="https://github.com/gedafu/readme-template/blob/master/images/medium.png" style="float: center; margin-right: 10px" height="50" width="50">
			</a>
			<h3 align="left">Juan Camilo Villa H. </h3>
      		<p align="left">
	   		</a>
			<p align="left">
        <a href="https://twitter.com/jcamilovillah" target="_blank">
            <img alt="twitter_page" src="https://github.com/gedafu/readme-template/blob/master/images/twitter.png" style="float: center; margin-right: 10px" height="50" width="50">
        </a>
        <a href="https://www.linkedin.com/in/juan-camilo-villa/" target="_blank">
            <img alt="linkedin_page" src="https://github.com/gedafu/readme-template/blob/master/images/linkedin.png" style="float: center; margin-right: 10px" height="50"  width="50">
        </a>
        <a href="https://medium.com/@juancamilovilla" target="_blank">
            <img alt="medium_page" src="https://github.com/gedafu/readme-template/blob/master/images/medium.png" style="float: center; margin-right: 10px" height="50" width="50">
			 </a>
</p>
