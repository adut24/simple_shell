#include "shell.h"

/**
 * execute_command - parse a string and execute the command contained in it
 * @str: string to parse that contains the command and arguments
 * @name: name of the executable
 * @nb_cmd: number of commands executed
 */
void execute_command(char *str, char *name, int nb_cmd)
{
	tok_t *head = NULL, *tmp;
	char *tab, *a;
	char **argv;
	int i = 1;

	tab = strtok(str, " ");
	add_node(&head, tab);
	tmp = head;
	for (; tab; i++)
	{
		tab = strtok(NULL, " ");
		add_node(&head, tab);
	}
	argv = malloc((i + 1) * sizeof(char *));
	if (!argv)
		return;
	for (i = 0; head; i++)
	{
		argv[i] = head->str;
		head = head->next;
	}
	free_list(&tmp);
	argv[i] = NULL;
	a = _strdup(argv[0]);
	argv[0] = _which(argv[0]);
	if (!argv[0])
	{
		_printf("%s: %d: %s: ", name, nb_cmd, a);
		perror("");
	}
	else
	{
		if (fork() == 0)
			exe_cmd(argv, a);
		wait(NULL);
		free(argv[0]);
	}
	free(argv);
	free(a);
}

/**
 * exe_cmd - execute the command
 * @argv: array of the command and arguments
 * @name: name of the executable
 */
void exe_cmd(char **argv, char *name)
{
	if (execve(argv[0], argv, NULL) == -1)
	{
		print_error(name);
		exit(0);
	}
}

/**
 * print_error - print the executable name on stderr
 * @name: name of the executable
 */
void print_error(char *name)
{
	printf("name:%s\n", name);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	perror("");
}
