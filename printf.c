#include "main.h"

/**
 * _printf - Produce output according to a format
 * @format: The string containing the format
 * Return: Number of printed char
 */
int _printf(const char *format, ...)
{
	int nb = 0;
	int (*ptr)(va_list);
	va_list list;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	va_start(list, format);
	for (; *format; format++)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				break;
			ptr = get_specifier(*format);
			if (ptr)
				nb += ptr(list);
			else
			{
				nb += _putchar('%');
				nb += _putchar(*format);
			}
		}
		else
			nb += _putchar(*format);
	}
	va_end(list);
	return (nb);
}

/**
 * get_specifier - Get the specifier object
 * @c: The specifier
 * Return: The pointer to the function
 */
int (*get_specifier(char c))(va_list)
{
	int i;

	spec_t function[] = {
		{'s', print_string},
		{'d', print_int}
		};

	for (i = 0; i < 2; i++)
	{
		if (function[i].c == c)
			return (function[i].f);
	}
	return (NULL);
}

/**
 * print_string - Print a string
 * @list: A string of the list
 * Return: Number of char printed
 */
int print_string(va_list list)
{
	char *s = va_arg(list, char *);

	if (!s)
		s = "(null)";
	return (_puts(s));
}

