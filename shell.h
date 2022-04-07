#ifndef SHELL_H
#define SHELL_H

#include "./printf.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
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

void execute_command(char *str, char *name, int nb_cmd);
tok_t *add_node(tok_t **head, char *s);
void free_list(tok_t **head);
char *_getenv(const char *name);
int check_exist(char *str);
char *_which(char *str);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
void print_error(char *name);
void exe_cmd(char **argv, char *name);

extern char **environ;

#endif /* SHELL_H */
