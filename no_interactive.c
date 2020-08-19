#include "shell.h"
/**
 * arguments1 - separate the user's string into arguments.
 * @file: file
 * @environ: environment variables.
 * @s: pointer string.
 * Return: out
 */
int arguments1(char *file, char **environ, char *s)
{
	char **argv = NULL, *token = NULL;
	int index = 0, count = 1, out = 0;

	argv = malloc(64 * sizeof(char *));
	if (!argv)
	{
		perror("Error on allocation");
		exit(0);
	}
	token = strtok(s, SEP_ESPAC);
	while (token)
	{
		argv[index] = token;
		index++;
		token = strtok(NULL, SEP_ESPAC);
	}
	argv[index] = NULL;
	out = get_command(argv, file, environ, count, out);
	free(argv);
	return (out);
}
/**
 * no_interactive - environment in no-interactive mode.
 * @environ: environment variables.
 * @file: file
 */
void no_interactive(char **environ, char *file)
{
	char *str = NULL, buf = '\0';
	int index = 0, out = 0;
	size_t size = 64;

	str = malloc(sizeof(char) * size);
	if (!str)
		exit(0);
	while (read(STDIN_FILENO, &buf, 1) > 0)
	{
		str[index] = buf;
		if (buf == '\0' || buf == '\n')
		{
			str[index + 1] = '\0';
			if (check_string(str, _strlen(str)) > 0)
				out = arguments1(file, environ, str);
			free(str);
		    exit(out);
		}
		index++;
	}
}
