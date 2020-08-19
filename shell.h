#ifndef SHELL_H
#define SHELL_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

#define SEP_SLASH "/"
#define SEP_EQUAL "="
#define SEP_TPOIN ":"
#define SEP_ESPAC " "
#define TITLE_PATH "PATH"
#define TITLE_DIR "PWD"
#define TITLE_FILE "_"

/**
 * struct built_t - anothers commands.
 * @comand: command.
 * @func: function to executing.
 */
typedef struct built_t
{
	char *comand;
	void (*func)(char **, char **, int);
} built;

void func_loop(char **environ);
void (*builtin(char *s))(char **argv, char **environ, int count);

char **searchpath(char **argv, char **path, char *dir);
char **divpath(char **environ, char *dir);
char *divdir(char **environ, char *dir);
void search_command(char **argv, char **environ, int count);
char **arguments(char *s);
void ex(char **argv, char **environ, int count);
void envir(char **argv, char **environ, int count);
void _putchar(char *c);
void newline(int number);
void printerror(char *file, char **argv, int count, char *message);
void printnumber(int number);
void exec(char *str, ssize_t line_length, char **environ, int conter);
int check_string(char *str, ssize_t length);

int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _isdigit(char c);
<<<<<<< HEAD
int _strlen(char *s);
=======
int strarguments(char *argv);
int strpath(char **environ);
>>>>>>> 76a5d2e87d329476ccf845e7145d227802401254

#endif
