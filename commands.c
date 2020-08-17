#include "shell.h"
/**
 * ex - close the shell process.
 * @argv: user-given arguments.
 * @environ: environment variables.
 * @count: execution counter.
 */
void ex(char **argv, char **environ, int count)
{
	char *file;
	int fd, i = 0, flag = 0;

	file = divdir(environ, TITLE_FILE);
	if (argv[1])
	{
		while (argv[1][i])
		{
			if (_isdigit(argv[1][i]))
				i++;
			else
			{
				flag = 1;
				break;
			}
		}
	}
	if (flag)
		printerror(file, argv, count, "Illegal number");
	else
	{
		fd = close(STDIN_FILENO);
		if (fd == -1)
			perror("ERROR");
	}
}
/**
 * envir - print environment variables.
 * @argv: user-given arguments.
 * @environ: environment variables.
 * @count: execution counter.
 */
void envir(char **argv, char **environ, int count)
{
	int i = 0;
	char *file;

	file = divdir(environ, TITLE_FILE);
	if (argv[1] != NULL)
		printerror(file, argv, count, "No such file or directory");
	else
	{
		while (environ[i])
		{
			_putchar(environ[i]);
			write(STDIN_FILENO, "\n", 1);
			i++;
		}
	}

}
