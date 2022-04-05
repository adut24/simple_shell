#include "shell.h"

/**
 * execute_command - parse a string and execute the command contained in it
 * @str: string to parse that contains the command and arguments
 */
void execute_command(char *str)
{
	tok_t *head, *tmp;
	char *tab;
	char **argv;
	int i = 0;

	head = NULL;
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
	i = 0;
	while (head)
	{
		argv[i] = head->str;
		head = head->next;
		i++;
	}
	head = tmp;
	free_list(&head);
	argv[i] = NULL;
	if (fork() == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			perror("Error:");
	}
	wait(NULL);
	free(argv);
}
