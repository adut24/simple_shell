#include "shell.h"

/**
 * _which - find the path of a command
 * @file: command
 * Return: string of the path
 */
char *_which(char *file)
{
	struct stat st;
	char *s = _strdup(_getenv("PATH"));
	char *p;
	char t[50];

	if (stat(file, &st) == 0)
	{
		free(s);
		return (_strdup(file));
	}

	p = strtok(s, ":");
	do {
		_strcpy(t, p);
		_strcat(t, "/");
		_strcat(t, file);
		if (stat(t, &st) == 0)
		{
			free(s);
			return (_strdup(t));
		}
		else
			t[0] = 0;
		p = strtok(NULL, ":");
	} while (p != NULL);

	free(s);
	return (NULL);
}
