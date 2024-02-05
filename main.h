#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * struct print_func - Struct print_func
 *
 * @specifier: Format specifier
 * @func: Function pointer
 */
typedef struct op
{
	char specifier;
	int (*func)(va_list);
} print_func_t;

int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);
void print_binary(unsigned int num);
print_func_t get_print_func(char specifier);
int _printf(const char *format, ...);


#endif /* MAIN_H */
