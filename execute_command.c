#include "shell.h"

/**
 * execute_command - parse a string and execute the command contained in it
 * @str: string to parse that contains the command and arguments
 * @name: name of the executable
 */
void execute_command(char *str, char *name)
{
	tok_t *head = NULL, *tmp;
	char *tab;
	char **argv;
	int i = 0;

	tab = strtok(str, " ");
	add_node(&head, tab);
	i++;
	tmp = head;
	while (tab)
	{
		tab = strtok(NULL, " ");
		add_node(&head, tab);
		i++;
	}
	argv = malloc((i + 1) * sizeof(char *));
	if (!argv)
		return;
	i = 0;
	while (head)
	{
		argv[i] = head->str;
		head = head->next;
		i++;
	}
	free_list(&tmp);
	argv[i] = NULL;
	argv[0] = _which(argv[0]);
	if (fork() == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			print_error(name);
			perror("");
			free(argv);
			kill(getpid(), SIGSEGV);
		}
	}
	wait(NULL);
	free(argv);
}

/**
 * print_error - print the executable name on stderr
 * @name: name of the executable
 */
void print_error(char *name)
{
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
}
