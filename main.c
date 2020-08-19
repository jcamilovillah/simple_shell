#include "shell.h"
/**
 * main - the principal function for shell.
 * @argc: Arguments numbers.
 * @argv: string arguments.
 * @environ: environ.
 * Return: 0 always.
 */
int main(int argc, char **argv, char **environ)
{
	(void)argc;

	if (isatty(STDIN_FILENO))
		func_loop(environ, argv[0]);
	else
		no_interactive(environ, argv[0]);
	return (0);
}
