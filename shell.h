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
typedef struct Token
{
	char *str;
	struct Token *next;
} tok_t;

void execute_command(char *str, char *name, int nb_cmd);
void interactive(char *name, char *buffer, size_t bufsize, int nb_cmd);
void non_interactive(char *name, char *buffer, size_t bufsize, int nb_cmd);
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
void free_grid(char **grid, int height);

extern char **environ;

#endif /* SHELL_H */
