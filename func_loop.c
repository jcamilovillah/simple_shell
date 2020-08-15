#include "shell.h"
/**
 * func_loop - loop infinite.
 * @environ: environ.
 * Return: void
 */
void func_loop(char **environ)
{
	char *str = NULL, **argv;
	size_t size = 0;
	int i = 0, count = 0;
	int (*validar)(char **);

	write(STDIN_FILENO, "$shell ", 8);
	signal(SIGINT, newline);
	while (1)
	{
		if (getline(&str, &size, stdin) == EOF)
		{
			write(STDIN_FILENO, "\n", 1);
			exit(0);
		}
		if (str[0] != '\n')
		{
			argv = arguments(str);
			validar = builtin(argv);
			if (validar)
				validar(environ);
			else
				search_command(argv, environ);
		}
		newline(1);
	}
}
