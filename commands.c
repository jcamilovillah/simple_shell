#include "shell.h"
/**
 * ex - close the shell process.
 * @argv: user-given arguments.
 * @environ: environment variables.
 * @count: execution counter.
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
		exit(_atoi(argv[1]));
	}
	exit(out);
}
/**
 * envir - print environment variables.
 * @argv: user-given arguments.
 * @environ: environment variables.
 * @count: execution counter.
 */
int envir(char **argv, char *file, char **environ, int count, int out)
{
	int i = 0;
	(void)out;

	if (argv[1] != NULL)
	{
		printerror(file, argv[0], count, "No such file or directory");
		return (127);
	}
	while (environ[i])
	{
		_putchar(environ[i]);
		write(STDIN_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
