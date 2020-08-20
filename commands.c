#include "shell.h"
/**
 * ex - close the shell process.
 * @s: string.
 * @argv: user-given arguments.
 * @environ: environment variables.
 * @count: execution counter.
 * @file: file
 * @out: out
 * Return: out
 */
int ex(char *s, char **argv, char *file, char **environ, int count, int out)
{
	(void)environ;

	if (argv[1])
	{
		printerrorex(file, argv, count, "Illegal number");
		exit (2);
	}
	free(argv);
	free(s);
	exit(out);
}
/**
 * envir - print environment variables.
 * @s: string.
 * @argv: user-given arguments.
 * @environ: environment variables.
 * @count: execution counter.
 * @file: file
 * @out: out
 * Return: 0
 */
int envir(char *s, char **argv, char *file, char **environ, int count, int out)
{
	int i = 0;
	(void)s;

	if (argv[1] != NULL)
	{
		printerror(file, argv[0], count, "No such file or directory");
		return (127);
	}
	while (environ[i])
	{
		_putchar(environ[i]);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (out);
}
