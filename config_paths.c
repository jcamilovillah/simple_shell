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
		aux = _stringscat(path[i], SEP_SLASH, argv[0]);
		if (access(aux, F_OK) != -1)
		{
			argv[0] = _strdup(aux);
			free(aux);
			return (argv);
		}
		i++;
		free(aux);
	}
	_strcat(dir, argv[0]);
	if (stat(dir, &buf) == 0)
	{
		argv[0] = _strdup(dir);
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
char *_getenv(char **environ, char *variable)
{
	int index = 0, i, length;
	char *path, *token, *result;

	length = _strlen(variable);
	while (environ[index])
	{
		i = 0;
		while (variable[i])
		{
			if (variable[i] != environ[index][i])
				break;
			i++;
		}
		if (i == length)
			break;
		  index++;
	}
	path = malloc(sizeof(char) * _strlen(environ[index]));
	if (!path)
		return (NULL);
	_strcpy(path, environ[index]);
	token = strtok(path, "=");
	token = strtok(NULL, "");
	result = malloc(sizeof(char) * _strlen(token));
	if (!result)
	{
		free(path);
		return (NULL);
	}
	_strcpy(result, token);
	free(path);
	return (result);
}
/**
 * divpath - separate the string PATH into arguments.
 * @environ: environment variables.
 * @dir: environment variable to search.
 * Return: PATH directories.
 */
char *check_exec(char *path, char *command)
{
	char *dir = NULL, *dir_command = NULL;
	int length, entry;

	dir = strtok(path, ":\n");
	while (dir)
	{
		length = _strlen(path);
		length += _strlen(command);
		dir_command = malloc(sizeof(char) * (length + 2));
		if (!dir_command)
			return (NULL);
		_strcat(dir_command, dir);
		_strcat(dir_command, SEP_SLASH);
		_strcat(dir_command, command);
		entry = access(dir_command, F_OK | X_OK | R_OK);
		if (entry == 0)
			return(dir_command);
		free(dir_command);
		dir = strtok(NULL, ":\n");
	}
	return (NULL);
}
/**
 * divpath - separate the string PATH into arguments.
 * @environ: environment variables.
 * @dir: environment variable to search.
 * Return: PATH directories.
 */
int divpath(char **argv, char *file, char **environ, int count)
{
	char *env = NULL, *copy = NULL;
	pid_t mypid;
	(void)file;
	(void)count;

	env = _getenv(environ, "PATH");
	copy = argv[0];
	argv[0] = check_exec(env, argv[0]);
	if (argv[0] == NULL)
	{
		printerror(file, copy, count, "not found");
		if (env)
			free(env);
		return(127);
	}
	free(env);
	mypid = fork();
	if (mypid == 0)
	{
		execve(argv[0], argv, environ);
		exit(0);
	}
	wait(NULL);
	free(argv[0]);
	return (0);
}
/**
 * search_command - find and run a command.
 * @argv: user-given arguments.
 * @environ: environment variables.
 * @count: execution counter.
 */
int search_command(char **argv, char *file, char **environ, int count)
{
	int entry, out;
	pid_t mypid;

	entry = access(argv[0], F_OK | X_OK | R_OK);
	if (entry == 0)
	{
		mypid = fork();
		if (mypid == 0)
		{
			execve(argv[0], argv, environ);
			exit(0);
		}
		wait(NULL);
	}
	else
		out = divpath(argv, file, environ, count);
	return (out);
}
