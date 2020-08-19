#include "shell.h"
/**
 * check_string - verify that the string is not empty.
 * @str: is the string.
 * @length: string size.
 * Return: 1 if the string is valid, else 0.
 **/
int check_string(char *str, ssize_t length)
{
	ssize_t i = 0, count = 1;

	while (i < length)
	{
		if (str[i] == '\t'
				|| (str[i] == ' ' && str[i + 1] == ' ')
				|| (str[i] == ' ' && str[i + 1] == '\n'))
		{
			if (str[i] == '\t')
				str[i] = ' ';
			count++;
		}
		i++;
	}
	if (count == i)
		return (0);
	return (1);
}
/**
 * func_loop - environment in interactive mode.
 * @environ: environment variables.
 * @file: file
 */
void func_loop(char **environ, char *file)
{
	char *str = NULL;
	int count = 1, out = 0;
	size_t size = 64;
	ssize_t line_length;

	signal(SIGINT, newline);
	while (1)
	{
		write(STDIN_FILENO, "hsh$ ", 5);
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
		write(STDIN_FILENO, "\n", 1);
		free(str);
	}
}
