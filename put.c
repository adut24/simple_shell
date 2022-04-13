#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
 * _puts - Print a string
 * @str: the string
 * Return: Number of char printed
 */
int _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);

}

/**
 * print_number - Print an int
 * @n: The int
 */
void print_number(int n)
{
	int a = 0;

	if (n == -2147483648)
	{
		n /= 10;
		a = 1;
	}

	if (n < 0)
	{
		_putchar('-');
		n = n * -1;
	}

	if (n / 10)
		print_number(n / 10);

	_putchar(n % 10 + '0');

	if (a == 1)
		_putchar('8');
}

/**
 * countDigit - Count the number of digit in an int
 * @n: The int
 * Return: The count
 */
int countDigit(int n)
{
	int i = 0, m = 0;

	if (n < 0)
		m = 1;
	while (n /= 10)
		i++;
	return (i + m + 1);
}

/**
 * print_int - Print an int
 * @list: An int of the list
 * Return: Number of char printed
 */
int print_int(va_list list)
{
	int n = va_arg(list, int);
	int count = countDigit(n);

	print_number(n);
	return (count);
}
