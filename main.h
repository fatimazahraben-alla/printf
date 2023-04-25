#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stfarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

#define SIZE_S 1
#define SIZE_L 2
int _putchar(char c);
int _isdigit(char c);
/**
 *struct ff_str - structure
 *@ss: pointer
 *@fmt: format
 */
typedef struct ff_str
{
	char fmt;
	int (*ss)(va_list, char[], int, int, int, int);
} f_str;

int _printf(const char *format, ...);
int print_char(va_list cl);
int print_string(va_list sl);
int print_percent(va_list pl);

int handle_printf(const char *fmt, int *a, va_list args,
char buffer[], int flags, int width, int precision, int size);

int g_flags(const char *format, int *a);
int g_precision(const char *format, int *a, va_list args);
int g_size(const char *format, int *a);
int g_size(const char *format, int *a, va_list args);

#endif
