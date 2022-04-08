#include "shell.h"
/**
 * _getenv - find the value of an environment variable
 * @name: environment variable
 * Return: pointer to the content of the environment variable
 */
char *_getenv(const char *name)
{
	int i, j;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
		{
			if (environ[i][j] == name[j])
				continue;
			else if (environ[i][j] == '=' && name[j] == '\0')
			{
				return (&environ[i][j + 1]);
			}
			else
				break;
		}
	}
	return (NULL);
}
