#include "shell.h"

char *_getenv(const char *name)
{
	char *s = strdup(name);
	char *r;
	int i, j;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
		{
			if (environ[i][j] == s[j])
				continue;
			else if (environ[i][j] == '=' && s[j] == '\0')
			{
				r = strtok(environ[i], "=");
				r = strtok(NULL, "=");
				free(s);
				return (r);
			}
			else
				break;
		}
	}
	free(s);
	return (NULL);
}
