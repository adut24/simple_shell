#include "shell.h"

/**
 * main - simple shell
 * @ac: number of arguments
 * @av: array of arguments
 * Return: 0
 */
int main(int ac, char **av)
{
	size_t bufsize = 0;
	char *buffer = NULL;
	int nb_cmd = 1;

	if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO))
	{
		non_interactive(av[0], buffer, bufsize, nb_cmd);
		return (0);
	}
	while (1)
	{
		interactive(av[0], buffer, bufsize, nb_cmd);
		nb_cmd++;
	}
	(void)ac;
	return (0);
}

/**
 * interactive - execute the simple shell in non interactive mode
 * @name: name of the executable
 * @buffer: buffer receiving getline
 * @bufsize: size of the buffer
 * @nb_cmd: number of command executed
 */
void interactive(char *name, char *buffer, size_t bufsize, int nb_cmd)
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
		execute_command(buffer, name, nb_cmd);
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
}

/**
 * non_interactive - execute the simple shell in non interactive mode
 * @name: name of the executable
 * @buffer: buffer receiving getline
 * @bufsize: size of the buffer
 * @nb_cmd: number of command executed
 */
void non_interactive(char *name, char *buffer, size_t bufsize, int nb_cmd)
{
	int nb = 0;

	while ((nb = getline(&buffer, &bufsize, stdin)) >= 0)
	{
		if (nb > 0)
			buffer[nb - 1] = '\0';
		if (*buffer != '\0')
			execute_command(buffer, name, nb_cmd);
		free(buffer);
		buffer = NULL;
	}
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
}
