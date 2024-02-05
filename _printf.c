#include "main.h"

/**
 * _printf - Function that prints output acording to format specified
 * @format: The specified format to print
 * Return: The number of charcated printed
 * write the output to the stdout
 */
int _printf(const char *format, ...)
{
	va_list args;
	print_func_t f;
	int count = 0;
	unsigned int num;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'b')
			{
				num = va_arg(args, unsigned int);
				print_binary(num);
				count += 32;
			}
			else
			{
				f = get_print_func(*format);
				if (f.func)
					count += f.func(args);
				else
				{
					_putchar('%');
					count++;
				}
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
