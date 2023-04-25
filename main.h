#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stfarg.h>

int _putchar(char c);
/**
 *struct ff_str - structure
 *@j: pointer
 *@ss: pointer
 */
typedef struct ff_str
{
	int (*j)(va_list);
	char *ss;
} f_str;
int (*spec_printf(const char *format))(va_list);
int _printf(const char *format, ...);
int print_char(va_list cl);
int print_string(va_list sl);
int print_percent(va_list pl);

#endif
