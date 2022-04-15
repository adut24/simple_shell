#include "main.h"

/**
 * exit_value - calculate the value exit will have
 * @n: supposed value of exit
 * Return: -1 for illegal numbers or a number between 0 and 255
 */
int exit_value(char *n)
{
	unsigned int nb = 0;

	if (!n)
		return (-2);

	for (; *n; n++)
	{
		if (*n < '0' || *n > '9')
			return (-1);

		nb = nb * 10 + (*n - '0');

		if (nb > 2147483648)
			return (-1);
	}

	while (nb > 255)
		nb -= 256;

	return (nb);
}

/**
 * print_env - Print the environnement variables
 *
 * @env: The variables
 */

void print_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * copyenv - Copy all the environment variables
 *
 * @env: All the environment variables
 * Return: The copy of the env
 */

char **copy_env(char **env)
{
	int i = 0, len;
	char **new_env;

	while (env[i])
		i++;

	new_env = malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return (NULL);

	for (i = 0; env[i]; i++)
	{
		len = _strlen(env[i]);

		new_env[i] = malloc(sizeof(char) * (len + 1));
		if (!new_env[i])
			return (NULL);

		_strcpy(new_env[i], env[i]);
	}
	new_env[i] = NULL;

	return (new_env);
}

/**
 * free_grid - Free the grid
 *
 * @grid: The grid
 */

void free_grid(char **grid)
{
	int i;

	for (i = 0; grid[i]; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
