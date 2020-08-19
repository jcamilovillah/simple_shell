#include "shell.h"
/**
 * searchpath - look for the command in the PWD and PATH directories.
 * @argv: user-given arguments.
 * @path: PATH directories.
 * @dir: PWD directory.
 * Return: the location of the command or NULL.
 */
char **searchpath(char **argv, char **path, char *dir)
{
	int i = 0;
	struct stat buf;
	char *aux;

	while (path[i])
	{
		aux = _strdup(path[i]);
		_strcat(aux, SEP_SLASH);
		_strcat(aux, argv[0]);
		if (stat(aux, &buf) == 0)
		{
			argv[0] = _strdup(aux);
			free(aux);
			return (argv);
		}
		i++;
		free(aux);
	}
	aux = _strdup(dir);
	_strcat(aux, argv[0]);
	if (stat(aux, &buf) == 0)
	{
		argv[0] = _strdup(aux);
		return (argv);
	}
	return (NULL);
}
/**
 * divpath - separate the string PATH into arguments.
 * @environ: environment variables.
 * @dir: environment variable to search.
 * Return: PATH directories.
 */
char **divpath(char **environ, char *dir)
{
	int index = 0, i = 0, count = 1;
	char *aux;
	char **argv;

	while (environ[index])
	{
		aux = _strdup(environ[index]);
		if (_strcmp(strtok(aux, SEP_EQUAL), dir) != 0)
			index++;
		else
			break;
		free(aux);
	}
	while (environ[index][i])
	{
		if (environ[index][i] == ':')
			count++;
		i++;
	}
	argv = malloc(sizeof(char *) * count);
	i = 0;
	aux = strtok(NULL, SEP_TPOIN);
	while (aux)
	{
		argv[i] = _strdup(aux);
		i++;
		aux = strtok(NULL, SEP_TPOIN);
	}
	argv[i] = NULL;
	return (argv);
}
/**
 * divdir - find the PWD directory.
 * @environ: environment variables.
 * @dir: environment variable to search.
 * Return: PWD directory.
 */
char *divdir(char **environ, char *dir)
{
	int index = 0;
	char *aux;

	while (environ[index])
	{
		aux = _strdup(environ[index]);
		if (_strcmp(strtok(aux, SEP_EQUAL), dir) != 0)
			index++;
		else
			break;
		free(aux);
	}
	aux = strtok(NULL, "\n");
	return (aux);
}
/**
 * search_command - find and run a command.
 * @argv: user-given arguments.
 * @environ: environment variables.
 * @count: execution counter.
 */
void search_command(char **argv, char **environ, int count)
{
	char **path, **exe, *dir, *file;
	struct stat buf;
	
	path = divpath(environ, TITLE_PATH);
	dir = divdir(environ, TITLE_DIR);
	file = divdir(environ, TITLE_FILE);
	if (argv[0][0] == '/')
	{
		if (fork() == 0)
		{
			if (stat(argv[0], &buf) == 0)
				execve(argv[0], argv, NULL);
			else
				printerror(file, argv, count, "not found");
			if (kill(getpid(), 1) == -1)
				printerror(file, argv, count, "not found");
		}
		wait(NULL);
	}
	else
	{
		exe = searchpath(argv, path, dir);
		if (exe && fork() == 0)
			execve(exe[0], exe, NULL);
		else if (!exe)
			printerror(file, argv, count, "not found");
		wait(NULL);
	}
	/*while(i >= 0)
	{
		free(path[i]);
		i--;
	}
	i = 0;
	while(i >= 0)
	{
		free(exe[i]);
		i--;
	}*/
}
