#include "shell.h"
/**
 * func_loop - environment in interactive mode.
 * @environ: environment variables.
 */
void func_loop(char **environ, char *file)
{
	char *str = NULL;
	int count = 1, out = 0;
	size_t size = 64;
	ssize_t line_length;

	write(STDIN_FILENO, "$shell ", 8);
	signal(SIGINT, newline);
	while (1)
	{
		str = malloc(sizeof(char) * size);
		if (!str)
		{
			perror("Error on allocation");
			exit(0);
		}
		line_length = getline(&str, &size, stdin);
		if (line_length == EOF)
		{
			write(STDIN_FILENO, "\n", 1);
			free(str);
			exit(out);
		}
		if (line_length > 1 && str[0] != '\n')
		{
			if (check_string(str, line_length) > 0)
				out = arguments(str, file, environ, count, out);
		}
		count++;
		free(str);
		newline(1);
	}
}
