#include "shell.h"
/**
 * get_command - pos get commands.
 * @s: string.
 * @av: pointer string.
 * @env: environment variables.
 * @count: execution counter.
 * @fl: file
 * @out: out
 * Return: out
 */
int get_command(char *s, char **av, char *fl, char **env, int count, int out)
{
	int (*validar)(char *, char **, char *, char **, int, int);

	validar = builtin(av[0]);
	if (validar)
		out = validar(s, av, fl, env, count, out);
	else
		out = search_command(av, fl, env, count);
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
	out = get_command(s, argv, file, environ, count, out);
	free(argv);
	return (out);
}
