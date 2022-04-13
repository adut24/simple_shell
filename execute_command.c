#include "main.h"

/**
 * execute_command - parse a string and execute the command contained in it
 * @str: string to parse that contains the command and arguments
 * @name: name of the executable
 * @nb_cmd: number of commands executed
 * @env: environment variables
 * @status: status of function
 */
void execute_command(char *str, char *name, int nb_cmd, char **env,
						int *status)
{
	tok_t *head = NULL, *tmp;
	char *tab, *copy_cmd, **cmd;
	int i = 1;

	tab = _strtok(str, " ");
	add_node(&head, tab);
	tmp = head;
	for (; tab; i++)
	{
		tab = _strtok(NULL, " ");
		add_node(&head, tab);
	}
	cmd = malloc((i + 1) * sizeof(char *));
	if (!cmd)
		return;
	for (i = 0; head; i++)
	{
		cmd[i] = head->str;
		head = head->next;
	}
	free_list(&tmp);
	cmd[i] = NULL;
	copy_cmd = _strdup(cmd[0]);
	cmd[0] = _which(cmd[0], env);
	if (!cmd[0])
		cmd_null(name, str, cmd, copy_cmd, nb_cmd, status);
	else
		exe_cmd(cmd, name, env);
	wait(status);
	free(cmd[0]);
	free(cmd);
	free(copy_cmd);
	*status /= 256;
}

/**
 * cmd_null - executed if a command isn't in PATH
 * @name: name of the executable
 * @str: original string of command typed
 * @cmd: the command to execute
 * @copy_cmd: copy of the command
 * @nb_cmd: number of command typed
 * @status: status of function
 */
void cmd_null(char *name, char *str, char **cmd, char *copy_cmd, int nb_cmd,
				int *status)
{
	int value = 0;

	if (_strcmp(copy_cmd, "exit") == 0)
	{
		value = exit_value(cmd[1]);
		if (value == -1)
		{
			*status = 512;
			_printf("%s: %d: exit: Illegal number: %s\n", name, nb_cmd, cmd[1]);
		}
		else
		{
			free(cmd[0]);
			free(cmd);
			free(copy_cmd);
			if (str)
				free(str);
			if (value == -2)
				exit(*status / 256);
			exit(value);
		}
	}
	else
	{
		_printf("%s: %d: %s: ", name, nb_cmd, copy_cmd);
		perror("");
	}
}

/**
 * exe_cmd - execute the command
 * @cmd: array of the command and arguments
 * @name: name of the executable
 * @env: environment variables
 */
void exe_cmd(char **cmd, char *name, char **env)
{
	if (fork() == 0)
	{
		if (execve(cmd[0], cmd, env) == -1)
		{
			print_error(name);
			exit(0);
		}
	}

}

/**
 * print_error - print the executable name on stderr
 * @name: name of the executable
 */
void print_error(char *name)
{
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	perror("");
}
