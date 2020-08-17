#include "shell.h"
/**
 * builtin - indicates the function to perform, according to s.
 * @s: is the command to compare.
 * Return: function to perform or NULL.
 */
void (*builtin(char *s))(char **argv, char **environ, int count)
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
