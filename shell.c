#include "shell.h"

/**
 * main - simple shell
 * Return: 0 or -1
 */
int main(void)
{
	size_t bufsize = 0;
	char *buffer = "";
	int nb = 0;

	if (!isatty(STDIN_FILENO) || !isatty(STDOUT_FILENO))
	{
		nb = getline(&buffer, &bufsize, stdin);
		if (nb == -1)
		{
			printf("\n");
			return (-1);
		}
		buffer[nb - 1] = '\0';
		printf("%s\n", buffer);
		execute_command(buffer);
		free(buffer);
	}
	else
	{
		while (1)
		{
			printf("€ ");
			nb = getline(&buffer, &bufsize, stdin);
			if (nb == -1)
			{
				printf("\n");
				return (-1);
			}
			buffer[nb - 1] = '\0';
			execute_command(buffer);
			free(buffer);
		}
	}
	return (0);
}
