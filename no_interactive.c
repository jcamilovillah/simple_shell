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
		exit(0);
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
 * check_string1 - check the string
 * @str: string
 * @length: size string
 * Return: 0 or 1;
 */
int check_string1(char *str, ssize_t length)
{
	ssize_t i = 0;

	while (i < length)
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
/**
 * no_interactive - environment in no-interactive mode.
 * @environ: environment variables.
 * @file: file
 */
void no_interactive(char **environ, char *file)
{
	char *str = NULL, buf = '\0';
	int out = 0;
	size_t size = 64, multi = 1, index = 0;

	str = malloc(sizeof(char) * size);
	if (!str)
		exit(0);
	while (read(STDIN_FILENO, &buf, 1) > 0)
	{
		str[index] = buf;
		if (buf == '\0' || buf == '\n')
		{
			str[index + 1] = '\0';
			if (check_string1(str, _strlen(str)) == 0)
				out = arguments1(file, environ, str);
			index = -1;
			free(str);
			str = malloc(sizeof(char) * size);
			if (!str)
				exit(0);
		}
		if (index == (size * multi) - 2)
		{
			str[index + 1] = '\0';
			str = _realloc(str, size * multi, size * (multi + 1));
			multi++;
		}
		index++;
		/*printf("%d\n", index);*/
	}
	free(str);
	exit(out);
}
