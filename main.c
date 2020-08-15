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
	(void)argv;

	if (isatty(STDIN_FILENO))
		func_loop(environ);
	else
		printf("no interative\n");
	return (0);
}
