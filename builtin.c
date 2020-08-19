#include "shell.h"
/**
 * builtin - indicates the function to perform, according to s.
 * @s: is the command to compare.
 * Return: function to perform or NULL.
 */
int (*builtin(char *s))(char **, char *, char **, int, int)
{
	built ops[] = {
		{"exit", ex},
		{"env", envir},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].comand)
	{
		if (_strcmp(ops[i].comand, s) == 0)
			return (ops[i].func);
		i++;
	}
	return (NULL);
}
