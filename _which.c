#include "shell.h"

/**
 * _which - find the path of a command
 * @file: command
 * Return: string of the path
 */
char *_which(char *file)
{
	struct stat st;
	char *s = _getenv("PATH");
	char *p = NULL, *temp = NULL;
	char t[50];

	if (stat(file, &st) == 0)
		return (file);

	do {
		p = _strchr(s, ':');
		if (p != NULL)
			p[0] = 0;
		_strcpy(t, s);
		_strcat(t, "/");
		_strcat(t, file);
		if (stat(t, &st) == 0)
		{
			temp = t;
			return (temp);
		}
		s = p + 1;
	} while (p != NULL);

	return (NULL);
}
