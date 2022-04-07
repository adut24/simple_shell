#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

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

#endif /* PRINTF_H */
