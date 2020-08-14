#include "shell.h"
/**
 * builtin - Indicates the function to follow according.
 * @s: is the command to compare.
 * Return: 0 always.
 */
int (*builtin(char **s))(void)
{
	built ops[] = {
		{"exit", ex},
		{"env", envir},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].comand)
	{
		if (strcmp(ops[i].comand, s[0]) == 0)
			return (ops[i].func);
		i++;
	}
	return (NULL);
}
