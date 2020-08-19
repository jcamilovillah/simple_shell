#include "shell.h"
/**
 * ex - close the shell process.
 * @argv: user-given arguments.
 * @environ: environment variables.
 * @count: execution counter.
 * @file: file
 * @out: out
 * Return: out
 */
int ex(char **argv, char *file, char **environ, int count, int out)
{
	int i = 0;
	(void)environ;

	if (argv[1])
	{
		while (argv[1][i])
		{
			if (_isdigit(argv[1][i]))
				i++;
			else
			{
				printerror(file, argv[0], count, "Illegal number");
				return (127);
			}
		}
		free(argv);
		exit(_atoi(argv[1]));
	}
	free(argv);
	exit(out);
}
/**
 * envir - print environment variables.
 * @argv: user-given arguments.
 * @environ: environment variables.
 * @count: execution counter.
 * @file: file
 * @out: out
 * Return: 0
 */
int envir(char **argv, char *file, char **environ, int count, int out)
{
	int i = 0;

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
