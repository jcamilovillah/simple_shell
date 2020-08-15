#include "shell.h"
/**
 * searchpath -
 *
 */
char **searchpath(char **argv, char **path, int status)
{
	int i = 0;
	struct stat buf;
	char *aux;

	if (status == 1)
	{
		while (path[i])
		{
			aux = strdup(path[i]);
			_strcat(aux, "/");
                        _strcat(aux, argv[0]);
			if (stat(aux, &buf) == 0)
			{
				argv[0] = strdup(aux);
				return (argv);
			}
			i++;
		}
		return (NULL);
	}
}
/**
 * divpath - separate the directories.
 * @environ: enviroment.
 * Return: result string.
 */
char **divpath(char **environ)
{
	int index = 0, i = 0, count = 1;
	char *aux, flag = 0;
	char **argv;

	while (environ[index])
	{
		aux = strdup(environ[index]);
		if (_strcmp(strtok(aux, "="), "PATH") != 0)
			index++;
		else
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		while (environ[index][i])
        	{
                	if (environ[index][i] == ':')
                        	count++;
                	i++;
        	}
		argv = malloc(sizeof(char *) * count);
		i = 0;
		aux = strtok(NULL, ":");
		while (aux)
		{
			argv[i] = strdup(aux);
			i++;
			aux = strtok(NULL, ":");
		}
		argv[i] = NULL;
		return (argv);
	}
	return (NULL);
}
/**
 * search_command - search for the command.
 * @argv: arguments whit command
 * Return: result string
 */
void search_command(char **argv)
{
	extern char **environ;
	int i = 0, indicator;
	char **path, **exe;
	pid_t pid;

	path = divpath(environ);
	if (argv[0][0] == '/')
	{
		if (fork() == 0)
			execve(argv[0], argv, NULL);
		wait(NULL);
	}
	else
	{
		exe = searchpath(argv, path, 1);
		if (exe && fork() == 0)
			execve(exe[0], exe, NULL);
		wait(NULL);
	}
}
/**
 * func_loop - loop infinite.
 */
void func_loop(void)
{
	char *str = NULL, **argv;
	size_t size = 0;
	int i = 0, count = 0;
	int (*validar)(void);

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
				validar();
			else
				search_command(argv);
		}
		newline(1);
	}
}
