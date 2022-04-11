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
	static char *copy;
	static int i;
	int j = 0, world_found = -1, blanks = 0;
	char *ret_str;

	if (src)
	{
		i = 0;
		copy = src;
	}
	while (copy[i])
	{
		while (delim[j])
		{
			if (copy[i] == delim[j])
			{
				blanks = 1;
				if (world_found <= 0)
				{
					copy[i++] = '\0';
					ret_str = copy + world_found;
					return (ret_str);
				}
			}
			j++;
		}
		j = 0;
		if (world_found == -1 && !blanks)
		{
			world_found = i;
		}
		blanks = 0;
		i++;
	}
	if (world_found == -1)
		return (0);
		ret_str = copy + world_found;
		return (ret_str);
}