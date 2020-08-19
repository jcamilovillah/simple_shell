#include "shell.h"
/**
 * get_command - pos get commands.
 * @argv: pointer string.
 * @environ: environment variables.
 * @count: execution counter.
 * @file: file
 * @out: out
 * Return: out
 */
int get_command(char **argv, char *file, char **environ, int count, int out)
{
	int (*validar)(char **, char *, char **, int, int);

	validar = builtin(argv[0]);
	if (validar)
		out = validar(argv, file, environ, count, out);
	else
		out = search_command(argv, file, environ, count);
	return (out);
}
/**
 * arguments - separate the user's string into arguments.
 * @s: pointer string.
 * @environ: environment variables.
 * @count: execution counter.
 * @file: file
 * @out: out
 * Return: out
 */
int arguments(char *s, char *file, char **environ, int count, int out)
{
	char **argv = NULL, *token = NULL;
	int index = 0;

	argv = malloc(64 * sizeof(char *));
	if (!argv)

	{
		perror("Error on allocation");
		exit(0);
	}
	token = strtok(s, SEP_ESPAC);
	while (token)
	{
		argv[index] = token;
		index++;
		token = strtok(NULL, SEP_ESPAC);
	}
	argv[index] = NULL;
	out = get_command(argv, file, environ, count, out);
	free(argv);
	return (out);
}
