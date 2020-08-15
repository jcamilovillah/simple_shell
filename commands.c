#include "shell.h"
/**
 * ex - closed shell process.
 * @environ: environ.
 * Return: 0 always.
 */
int ex(char **environ)
{
	(void)environ;
	int fd;

	fd = close(STDIN_FILENO);
	if (fd == -1)
		perror("ERROR");
	return (0);
}
/**
 * envir - print environment.
 * @environ: environ
 * Return: 0 always.
 */
int envir(char **environ)
{
	int i = 0;

	while (environ[i])
	{
		_putchar(environ[i]);
		write(STDIN_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
