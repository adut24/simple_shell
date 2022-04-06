#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * struct tokens - linked list
 * @str: string with a token of the command
 * @next: pointer to the next node
 */
typedef struct tokens
{
	char *str;
	struct tokens *next;
} tok_t;

void execute_command(char *str);
tok_t *add_node(tok_t **head, char *s);
void free_list(tok_t **head);
char *_getenv(const char *name);

extern char **environ;

#endif /* SHELL_H */
