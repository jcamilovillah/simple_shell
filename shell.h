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
#define SEP_ESPAC " \t\r\n\a"
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
	int (*func)(char **, char *, char **, int, int);
} built;

void func_loop(char **environ, char *argv);
int (*builtin(char *s))(char **, char *, char **, int, int);

char **searchpath(char **argv, char **path, char *dir);
int divpath(char **argv, char *file, char **environ, int count);
char *divdir(char **environ, char *dir);
int search_command(char **argv, char *file, char **environ, int count);
int arguments(char *s, char *file, char **environ, int count, int out);
int ex(char **argv, char *file, char **environ, int count, int out);
int envir(char **argv, char *file, char **environ, int count, int out);
void _putchar(char *c);
void newline(int number);
void printerror(char *file, char *argv, int count, char *message);
void printnumber(int number);
int check_string(char *str, ssize_t length);
char *_getenv(char **environ, char *path);

int _strcmp(char *s1, char *s2);
void _strcat(char *dest, char *src);
char *_strdup(char *str);
int _isdigit(char c);
char *_stringscat(char *dest, char *src1, char *src2);
int lenarguments(char *s);
int get_command(char **argv, char *file, char **environ, int count, int out);
int _atoi(char *s);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *check_exec(char *path, char *command);
int executes(char **argv, char *file, char **path, int count);

#endif
