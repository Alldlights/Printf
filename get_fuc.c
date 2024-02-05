#include "main.h"

/**
 * get_print_func - Get the function for call back
 * @specifier: Format specifer
 * Return: struct of print_func
 */
print_func_t get_print_func(char specifier)
{
	print_func_t func_array[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{'\0', NULL}
	};
	print_func_t default_func;
	int i;

	for (i = 0; func_array[i].specifier != '\0'; i++)
	{
		if (func_array[i].specifier == specifier)
			return (func_array[i]);
	}
	default_func.specifier = '\0';
	default_func.func = NULL;

	return (default_func);
}
