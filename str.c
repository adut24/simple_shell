#include "main.h"

/**
 * _strlen - return the length of a string
 * @s: string
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * _strcpy - copy a string
 * @dest: destination of the string
 * @src: source of the string
 * Return: string to copy
 */
char *_strcpy(char *dest, char *src)
{
	int i, len = _strlen(src);

	for (i = 0; i <= len; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * _strcmp - compare two strings
 * @s1: string one
 * @s2: string two
 * Return: gap between the ASCII value of the two characters
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strcat - concatenate 2 strings together
 * @dest: the string receiving the other
 * @src: the string to concatenate
 * Return: concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int i, len = _strlen(dest);

	for (i = 0; src[i] != '\0' ; i++)
	{
		dest[len + i] = src[i];
	}
	dest[len + i] = '\0';
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
	int i, len = _strlen(str);
	char *s;

	s = malloc((len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	for (i = 0; i < len; i++, str++)
		s[i] = *str;
	s[i] = '\0';
	return (s);
}
