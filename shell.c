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
	int nb = 0;

	if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO))
	{
		while (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO))
		{
			nb = getline(&buffer, &bufsize, stdin);
			if (nb == -1)
				return (0);
			buffer[nb - 1] = '\0';
			if (*buffer != '\0')
				execute_command(buffer, av[0]);
		}
	}
	else
	{
		while (1)
		{
			_printf("€ ");
			nb = getline(&buffer, &bufsize, stdin);
			if (nb == -1)
			{
				_printf("\n");
				if (buffer)
					free(buffer);
				return (-1);
			}
			buffer[nb - 1] = '\0';
			if (*buffer != '\0')
				execute_command(buffer, av[0]);
			if (buffer)
			{
				free(buffer);
				buffer = NULL;
			}
		}
	}
	(void)ac;
	return (0);
}
