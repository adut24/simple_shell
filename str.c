#include "shell.h"

/**
 * _strlen - return the length of a string
 * @s: string
 * Return: length of the string
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
		length++;
	return (length);
}

/**
 * *_strcpy - copy a string
 * @dest: destination of the string
 * @src: source of the string
 * Return: string to copy
 */
char *_strcpy(char *dest, char *src)
{
	int i, length = _strlen(src);

	for (i = 0; i <= length; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * *_strchr - locate a character in a string
 * @s: string to verify
 * @c: character to check if present
 * Return: pointer to the position of c or 0
 */
char *_strchr(char *s, char c)
{
	for (; *s; s++)
	{
		if (*s == c)
			break;
	}
	if (!*s && c)
		return (0);
	return (s);
}

/**
 * *_strcat - concatenate 2 strings together
 * @dest: the string receiving the other
 * @src: the string to concatenate
 * Return: concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int i, length = _strlen(dest);

	for (i = 0; src[i] != '\0' ; i++)
	{
		dest[length + i] = src[i];
	}
	dest[length + i] = '\0';
	return (dest);
}

/**
 * *_strdup - copy a string
 * @str: string to copy
 *
 * Return: NULL or pointer to the copy
 */
char *_strdup(char *str)
{
	int i, length = _strlen(str);
	char *s = malloc(length * sizeof(char) + 1);

	if (s == NULL)
		return (NULL);
	for (i = 0; i < length; i++)
	{
		s[i] = *str;
		str++;
	}
	s[i] = '\0';
	return (s);
}
