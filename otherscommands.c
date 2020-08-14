#include "shell.h"
/**
 * ex - closed shell process.
 * Return: 0 always.
 */
int ex(void)
{
	int fd;

	fd = close(STDIN_FILENO);
	if (fd == -1)
		perror("ERROR");
	return (0);
}
/**
 * envir - print environment.
 * Return: 0 always.
 */
int envir(void)
{
        extern char **environ;
	int i = 0;

	while (environ[i])
	{
		_putchar(environ[i]);
		write(STDIN_FILENO, "\n", 1);
		i++;
	}
        return (0);
}
