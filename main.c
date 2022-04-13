#include "main.h"

/**
 * main - simple shell
 * @ac: number of arguments
 * @av: array of arguments
 * @env: array of environment variables
 * Return: 0, 1, 2 or exit value
 */
int main(int ac, char **av, char **env)
{
	size_t bufsize = 0;
	char *buffer = NULL;
	int nb_cmd = 1, status = 0;

	if (signal(SIGINT, sigintHandler) == SIG_ERR)
		return (1);

	if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO))
	{
		non_int(av[0], buffer, bufsize, nb_cmd, env, &status);
		return (status);
	}

	while (1)
	{
		inter(av[0], buffer, bufsize, nb_cmd, env, &status);
		nb_cmd++;
	}
	(void)ac;
	return (0);
}

/**
 * inter - execute the simple shell in normal mode
 * @name: name of the executable
 * @buffer: buffer receiving getline
 * @bufsize: size of the buffer
 * @nb_cmd: number of command executed
 * @env: environment variables
 * @status: status of function
 */
void inter(char *name, char *buffer, size_t bufsize, int nb_cmd, char **env,
			int *status)
{
	int nb = 0, i = 0, check = 0;

	write(STDOUT_FILENO, "> ", 2);
	nb = getline(&buffer, &bufsize, stdin);
	if (nb == -1)
	{
		write(STDOUT_FILENO, "\n", 1);
		if (buffer)
			free(buffer);
		exit(*status);
	}
	if (nb > 0)
		buffer[nb - 1] = '\0';
	if (*buffer)
	{
		while (buffer[i] != '#' && buffer[i])
			i++;
		buffer[i] = '\0';

		for (i = 0; buffer[i]; i++)
		{
			if (buffer[i] != ' ')
			{
				check = 1;
				break;
			}
		}
		if (check == 1)
			execute_command(buffer, name, nb_cmd, env, status);
	}
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
}

/**
 * non_int - execute the simple shell in non interactive mode
 * @name: name of the executable
 * @buffer: buffer receiving getline
 * @bufsize: size of the buffer
 * @nb_cmd: number of command executed
 * @env: environment variables
 * @status: status of function
 */
void non_int(char *name, char *buffer, size_t bufsize, int nb_cmd, char **env,
				int *status)
{
	int nb = 0, i = 0, check = 0;

	while ((nb = getline(&buffer, &bufsize, stdin)) >= 0)
	{
		if (nb > 0)
			buffer[nb - 1] = '\0';
	if (*buffer)
	{
		while (buffer[i] != '#' && buffer[i])
			i++;
		buffer[i] = '\0';

		for (i = 0; buffer[i]; i++)
		{
			if (buffer[i] != ' ')
			{
				check = 1;
				break;
			}
		}
		if (check == 1)
			execute_command(buffer, name, nb_cmd, env, status);
	}
		free(buffer);
		buffer = NULL;
	}
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
}

/**
 * sigintHandler - if Ctrl+C is pressed
 * @sig: signal sent to the function
 */
void sigintHandler(int sig)
{
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "> ", 2);
	(void)sig;
}
