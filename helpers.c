#include "main.h"
#include <string.h>

/**
 * print_char - Prints a character to the stdout
 * @args: Variable argument
 * Return: 1 on success
 */
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	_putchar(c);
	return (1);
}

/**
 * print_string- Prints a string
 * @args: Variable arguments
 * Return: string len
 */
int print_string(va_list args)
{
	char *str;
	char null_str[5] = "(nil)";
	int i;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (i = 0; null_str[i] != '\0'; i++)
			_putchar(null_str[i]);
		return (5);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	return (strlen(str));
}

/**
 * print_percent - Print the % sign
 * @args: Variable args
 * Return: 1 on success
 */
int print_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}

/**
 * print_int - Print %d %i format specifier
 * @args: variable argument
 * Return: 1 on success
 */
int print_int(va_list args)
{
	int num, digit, count = 0, rev_num = 0;

	num = va_arg(args, int);
	if (num < 0)
	{
		_putchar('-');
		num = -num;
		count++;
	}
	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		digit = num % 10;
		rev_num = rev_num * 10 + digit;
		num /= 10;
	}
	while (rev_num > 0)
	{
		_putchar(rev_num % 10 + '0');
		rev_num /= 10;
		count++;
	}

	return (count);
}

/**
 * print_unsigned - Print an unsigned int with the %u specifier
 * @args: variable arguments
 * Return: 1 on success
 */
int print_unsigned(va_list args)
{
	unsigned int num, temp, digits, divisor, i, digit;

	num = va_arg(args, unsigned int);
	temp = num;
	digits = 0;

	if (temp == 0)
	{
		_putchar('0');
		return (1);
	}

	while (temp > 0)
	{
		temp /= 10;
		digits++;
	}
	while (digits > 0)
	{
		divisor = 1;
		for (i = 1; i < digits; i++)
			divisor *= 10;
		digit = num / divisor;
		num %= divisor;
		digits--;
	}
	return (digits);
}
