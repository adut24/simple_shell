#include "shell.h"

/**
 * _strtok - tokenizes a string by a charactere delimiter.
 * @src: the string to be tokenize on the first call, should be NULL
 * when tokenizing the same string.
 * @delim: the delimiter to tokenize by.
 * Return: pointer to the beginning of the new token.
 */
char *_strtok(char *src, char delim)
{
	static char *start;
	static char *last_null;
	char *ret = NULL;

	if (src)
		start = src;

	if (!start)
		return (NULL);

	if (*start == '\0')
	{
		if (start == last_null)
		{
			start = NULL;
			return (NULL);
		}
		last_null = start;
		return (start);
	}

	ret = start;
	while (*start)
	{
		if (*start == delim)
		{
			*start = '\0';
			last_null = start;
			start++;
			return (ret);
		}
		start++;
	}
	last_null = start;

	return (ret);
}