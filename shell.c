#include "shell.h"

/**
 * main - simple shell
 * @ac: number of arguments
 * @av: array of arguments
 * Return: 0 or -1
 */
int main(int ac, char **av)
{
	size_t bufsize = 0;
	char *buffer = NULL;
	int nb = 0, nb_cmd = 1;

	if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO))
	{
		while ((nb = getline(&buffer, &bufsize, stdin)) >= 0)
		{
			if (nb > 0)
				buffer[nb - 1] = '\0';
			else
				buffer[nb] = '\0';
			if (*buffer != '\0')
				execute_command(buffer, av[0], nb_cmd);
			free(buffer);
			buffer = NULL;
		}
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (0);
	}
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		nb = getline(&buffer, &bufsize, stdin);
		if (nb == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			if (buffer)
				free(buffer);
			return (-1);
		}
		buffer[nb - 1] = '\0';
		if (*buffer != '\0')
			execute_command(buffer, av[0], nb_cmd);
		nb_cmd++;
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
	}
	(void)ac;
	return (0);
}
