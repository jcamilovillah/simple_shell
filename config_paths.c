#include "shell.h"
/**
 * searchpath - search the path.
 * @argv: string of arguments
 * @path: directories
 * @status: type execution
 * Return: Argv.
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
	char *aux;
	char **argv;

	while (environ[index])
	{
		aux = strdup(environ[index]);
		if (_strcmp(strtok(aux, "="), "PATH") != 0)
			index++;
		else
			break;
	}
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
/**
 * search_command - search for the command.
 * @argv: arguments whit command
 * @environ: environ
 * Return: result string
 */
void search_command(char **argv, char **environ)
{
	int i = 0, indicator;
	char **path, **exe;
	pid_t pid;
	struct stat buf;

	path = divpath(environ);
	if (argv[0][0] == '/')
	{
		if (fork() == 0)
		{
			if (stat(argv[0], &buf) == 0)
				execve(argv[0], argv, NULL);
			printf("hola\n");
			if (kill(getpid(), 1) == -1)
				printf("falló esta monda\n");
		}
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

