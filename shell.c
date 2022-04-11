#include "shell.h"

/**
 * main - simple shell
 * @ac: number of arguments
 * @av: array of arguments
 * @env: array of environment variables
 * Return: 0 or 1 or exit value
 */
int main(int ac, char **av, char **env)
{
	size_t bufsize = 0;
	char *buffer = NULL;
	int nb_cmd = 1;

	if (signal(SIGINT, sigintHandler) == SIG_ERR)
		return (1);

	if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO))
	{
		non_int(av[0], buffer, bufsize, nb_cmd, env);
		return (0);
	}

	while (1)
	{
		inter(av[0], buffer, bufsize, nb_cmd, env);
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
 */
void inter(char *name, char *buffer, size_t bufsize, int nb_cmd, char **env)
{
	int nb = 0;

	write(STDOUT_FILENO, "$ ", 2);
	nb = getline(&buffer, &bufsize, stdin);
	if (nb == -1)
	{
		write(STDOUT_FILENO, "\n", 1);
		if (buffer)
			free(buffer);
		exit(0);
	}
	if (nb > 0)
		buffer[nb - 1] = '\0';
	if (*buffer != '\0')
		execute_command(buffer, name, nb_cmd, env);
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
 */
void non_int(char *name, char *buffer, size_t bufsize, int nb_cmd, char **env)
{
	int nb = 0;

	while ((nb = getline(&buffer, &bufsize, stdin)) >= 0)
	{
		if (nb > 0)
			buffer[nb - 1] = '\0';
		if (*buffer != '\0')
			execute_command(buffer, name, nb_cmd, env);
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
	write(STDOUT_FILENO, "$ ", 2);
	(void)sig;
}
