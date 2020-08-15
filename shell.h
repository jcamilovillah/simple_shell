#ifndef SHELL_H
#define SHELL_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

/**
 * struct built_t - anothers commands.
 * @comand: command.
 * @next: points to the next node.
 * @func: function to executing
 */
typedef struct built_t
{
	char *comand;
	int (*func)(char **);
	struct built_t *next;
} built;

void func_loop(char **environ);
int (*builtin(char **s))(char **);

char **searchpath(char **argv, char **path, int status);
char **divpath(char **environ);
void search_command(char **argv, char **environ);
char **arguments(char *s);
int ex(char **environ);
int envir(char **environ);
int _putchar(char *c);
void newline(int number);

int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);

#endif
