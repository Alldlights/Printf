#include "main.h"

/**
 * _putchar - Funtion that prints a character to the stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_binary - Print a number converted to binary
 * @num: number
 * Return: Nothing
 */
void print_binary(unsigned int num)
{
	if (num > 1)
		print_binary(num / 2);
	_putchar('0' + num % 2);
}
