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
 */
typedef struct built_t
{
	char *comand;
	int (*func)(void);
	struct built_t *next;
} built;

void func_loop(void);
int (*builtin(char **s))(void);

char **searchpath(char **argv, char **path, int status);
char **divpath(char **environ);
void search_command(char **argv);
char **arguments(char *s);
int ex(void);
int envir(void);
int _putchar(char *c);
void newline(int number);

int _strcmp(char *s1, char *s2);
char *_strncat(char *dest, char *src, int n);

#endif
