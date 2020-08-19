#include "shell.h"
/**
 * _getenv - get env.
 * @environ: environment variables.
 * @variable: variable.
 * Return: result.
 */
char *_getenv(char **environ, char *variable)
{
	int index = 0, i, length;
	char *path = NULL, *token = NULL, *result = NULL;

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
	path = malloc(sizeof(char) * (_strlen(environ[index]) + 1));
	if (!path)
		return (NULL);
	_strcpy(path, environ[index]);
	token = strtok(path, "=");
	token = strtok(NULL, "");
	result = malloc(sizeof(char) * (_strlen(token) + 1));
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
 * check_exec - check exec.
 * @path: path.
 * @command: command.
 * Return: NULL.
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
		dir_command[0] = '\0';
		_strcat(dir_command, dir);
		_strcat(dir_command, SEP_SLASH);
		_strcat(dir_command, command);
		entry = access(dir_command, F_OK | X_OK | R_OK);
		if (entry == 0)
			return (dir_command);
		free(dir_command);
		dir = strtok(NULL, ":\n");
	}
	return (NULL);
}
/**
 * divpath - separate the string PATH into arguments.
 * @argv: pointer string.
 * @environ: environment variables.
 * @count: execution counter.
 * @file: file
 * Return: 0
 */
int divpath(char **argv, char *file, char **environ, int count)
{
	char *env = NULL, *copy = NULL;
	pid_t mypid;
	int state;
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
		return (127);
	}
	free(env);
	mypid = fork();
	if (mypid == 0)
	{
		execve(argv[0], argv, environ);
		exit(0);
	}
	wait(&state);
	free(argv[0]);
	return (0);
}
/**
 * search_command - find and run a command.
 * @argv: user-given arguments.
 * @environ: environment variables.
 * @file: file
 * @count: count
 * Return: out
 */
int search_command(char **argv, char *file, char **environ, int count)
{
	int entry, out;
	pid_t mypid;
	int state;

	entry = access(argv[0], F_OK | X_OK | R_OK);
	if (entry == 0)
	{
		mypid = fork();
		if (mypid == 0)
		{
			execve(argv[0], argv, environ);
			exit(0);
		}
		wait(&state);
	}
	else
		out = divpath(argv, file, environ, count);
	return (out);
}
