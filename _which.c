#include "shell.h"

/**
 * _which - find the path of a command
 * @cmd: command
 * Return: string of the path
 */
char *_which(char *cmd)
{
	struct stat st;
	char *s = _strdup(_getenv("PATH"));
	char *p;
	char t[50];

	if (stat(cmd, &st) == 0)
	{
		free(s);
		return (_strdup(cmd));
	}

	p = strtok(s, ":");
	do {
		_strcpy(t, p);
		_strcat(t, "/");
		_strcat(t, cmd);
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
