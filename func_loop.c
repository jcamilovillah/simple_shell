#include "shell.h"
/**
 * exec - run the command in the PATH or in the builtin.
 * @str: string given by user.
 * @line_length: string size str.
 * @environ: environment variables.
 * @conter: execution counter.
 * Return: void
 */
void exec(char *str, ssize_t line_length, char **environ, int conter)
{
	char **argv;
	void (*validar)(char **, char **, int);
	int argc, i = 0, count = 0;

	argc = check_string(str, line_length);
	if (argc > 0)
	{
		argv = arguments(str);
		while (argv[i])
		{
			count = 0;
			while (argv[i][count])
				count++;
			if (count == 0)
				argv[i] = NULL;
			i++;
		}
		validar = builtin(argv[0]);
		if (validar)
			validar(argv, environ, conter);
		else
			search_command(argv, environ, conter);
	}
}
/**
 * func_loop - environment in interactive mode.
 * @environ: environment variables.
 */
void func_loop(char **environ)
{
	char *str = NULL;
	size_t size = 0;
	int count = 1;
	ssize_t line_length;

	write(STDIN_FILENO, "$shell ", 8);
	signal(SIGINT, newline);
	while (1)
	{
		line_length = getline(&str, &size, stdin);
		if (line_length == EOF)
		{
			write(STDIN_FILENO, "\n", 1);
			exit(0);
		}
		if (line_length > 1 && str[0] != '\n')
			exec(str, line_length, environ, count);
		count++;
		newline(1);
	}
}
