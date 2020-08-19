#include "shell.h"
/**
 * _isdigit - check if a character is a number.
 * @c: is the character.
 * Return: 1 digit or 0 otherwise.
 */
int _isdigit(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int lenarguments(char *s)
{
	int index = 0, count = 1;
	
	while (s[index])
    {
        if (s[index] == ':')
            count++;
        index++;
    }
	count++;
	return(count);
}
/**
 * _strcat - concatenate two strings.
 * @src: First string to append.
 * @dest: Second string to append.
 * Return: Pointer to the resulting string.
 **/
char *_stringscat(char *dest, char *src1, char *src2)
{
	int i = 0, j = 0, k = 0;
	char *result;

	while (dest[i] != '\0')
		i++;
	while (src1[j] != '\0')
		j++;
	while (src2[k] != '\0')
		k++;
	result = malloc(sizeof(char) * (i + j + k + 1));
	i = 0;
	for (j = 0; dest[j] != '\0'; j++, i++)
		result[i] = dest[j];
	for (j = 0; src1[j] != '\0'; j++, i++)
		result[i] = src1[j];
	for (j = 0; src2[j] != '\0'; j++, i++)
		result[i] = src2[j];
	result[i] = '\0';
	return (result);
}

int get_command (char **argv, char *file, char **environ, int count, int out)
{
	int (*validar)(char **, char *, char **, int, int);

	validar = builtin(argv[0]);
	if (validar)
		out = validar(argv, file, environ, count, out);
	else
		out = search_command(argv, file, environ, count);
	return (out);
}

/**
 * _atoi - convert a string to an integer.
 *
 * @s: pointer.
 *
 * Return: result entero.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int total = 0;
	char working = 0;

	while (*s)
	{
		if (*s == '-')
			sign = sign * -1;
		if (*s >= '0' && *s <= '9')
		{
			working = 1;
			total = total * 10 + *s - '0';
		}
		else if (*s < '0' || *s > '9')
		{
			if (working)
				break;
		}
		s++;
	}
	if (sign < 0)
		total = (-(total));
	while (total > 255)
		total -= 256;
	return (total);
}
/**
 * _strlen - length of a string.
 *
 * @s: pointer.
 *
 * Return: result.
 */
int _strlen(char *s)
{
	int cifras = 0;

	while (*(s + cifras) != '\0')
		cifras++;
	return (cifras);
}
/**
 * _strcpy - copies the string pointed to by src.
 *
 * @dest: pointer.
 * @src: pointer.
 *
 * Return: void.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}