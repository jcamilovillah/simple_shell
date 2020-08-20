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
	int (*func)(char *, char **, char *, char **, int, int);
} built;

/* Interactive mode */
void func_loop(char **environ, char *argv);
int check_string(char *str, ssize_t length);

/* no-Interactive mode */
void no_interactive(char **environ, char *file);
int arguments1(char *file, char **environ, char *s);
int check_string1(char *str, ssize_t length);

/* Arguments configuration */
int arguments(char *s, char *file, char **environ, int count, int out);
int get_command(char *s, char **av, char *fl, char **env, int count, int out);

/* Commands structure */
int (*builtin(char *s))(char *, char **, char *, char **, int, int);
int ex(char *s, char **argv, char *file, char **environ, int count, int out);
int envir(char *s, char **av, char *fl, char **env, int count, int out);

/* Commands search in the path */
int search_command(char **argv, char *file, char **environ, int count);
int divpath(char **argv, char *file, char **environ, int count);
char *_getenv(char **environ, char *path);
char *check_exec(char *path, char *command);

/* Strings functions */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void _strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);

/* Numbers functions */
int _isdigit(char c);
int _atoi(char *s);

/* Alloc Memory */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _memcpy(char *dest, char *src, unsigned int n);

/* Print functions */
void _putchar(char *c);
void newline(int number);
void printerror(char *file, char *argv, int count, char *message);
void printnumber(int number);
void printerrorex(char *file, char **argv, int count, char *message);

#endif
