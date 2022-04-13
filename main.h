#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

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

void inter(char *, char *, size_t, int, char **, int *);
void non_int(char *, char *, size_t, int, char **, int *);
void sigintHandler(int);

void execute_command(char *, char *, int, char **, int *);
void cmd_null(char *, char *, char **, char *, int, int *);
void exe_cmd(char **, char *, char **);
void print_error(char *);

int exit_value(char *);
void print_env(char **);

tok_t *add_node(tok_t **, char *);
void free_list(tok_t **);

char *_which(char *, char **);
char *_getenv(const char *, char **);

unsigned int check_delim(char c, const char *str);
char *_strtok(char *str, const char *delim);

int _strlen(char *);
char *_strcpy(char *, char *);
char *_strcat(char *, char *);
char *_strdup(char *);
int _strcmp(char *, char *);

/* Printf function */

/**
 * struct Specifier - Struct specifier
 * @c: The specifier
 * @f: The function
 */
typedef struct Specifier
{
	char c;
	int (*f)(va_list);
} spec_t;


int _printf(const char *format, ...);
int (*get_specifier(char c))(va_list);
int _putchar(char c);
int _puts(char *str);
void print_number(int n);
int print_string(va_list);
int countDigit(int n);
int print_int(va_list);

#endif /* MAIN_H */
