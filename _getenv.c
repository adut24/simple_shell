#include "shell.h"
/**
 * _getenv - find the value of an environment variable
 * @name: environment variable
 * Return: pointer to the content of the environment variable
 */
char *_getenv(const char *name)
{
	char *r = NULL;
	int i, j;
	char temp[150];

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
		{
			if (environ[i][j] == name[j])
				continue;
			else if (environ[i][j] == '=' && name[j] == '\0')
			{
				_strcpy(temp, environ[i]);
				r = strtok(temp, "=");
				r = strtok(NULL, "=");
				return (r);
			}
			else
				break;
		}
	}
	return (NULL);
}
