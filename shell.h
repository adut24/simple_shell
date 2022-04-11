#ifndef SHELL_H
#define SHELL_H

#include "printf.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

/**
 * struct Token - linked list
 * @str: string with a token of the command
 * @next: pointer to the next node
 */
typedef struct Token
{
	char *str;
	struct Token *next;
} tok_t;

void inter(char *, char *, size_t, int, char **);
void non_int(char *, char *, size_t, int, char **);
void sigintHandler(int);

void execute_command(char *, char *, int, char **);
void cmd_null(char *, char *, char **, char *, int);
void exe_cmd(char **, char *);
void print_error(char *);

void printenv(char **);
int exit_value(char *);

tok_t *add_node(tok_t **, char *);
void free_list(tok_t **);

char *_which(char *, char **);
char *_getenv(const char *, char **);

int _strlen(char *);
char *_strcpy(char *, char *);
char *_strchr(char *, char);
char *_strcat(char *, char *);
char *_strdup(char *);
int _strcmp(char *, char *);

#endif /* SHELL_H */
