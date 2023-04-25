#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 *_isdigit -  checks for a digit (0 through 9)
 *@c: The character
 *Return: 1 if c is a digit or 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 *_printf - printf func
 *@format: first arg
 *Return: int
 */
int _printf(const char *format, ...)
{
	int (*j)(va_list), a = 0, b = 0, k = 0, w = 0;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
		return (-1);
	while (format && format[a])
	{
		if (format[a] == '%')
		{
			if (_isdigit(format[a + 1]))
			{
				w = format[a + 1] - '0';
				b = a + 2;
				while (_isdigit(format[b]))
				{
					w = w * 10 + (format[b] - '0');
					b++;
				}
				a = b - 1;
			}
			if (format[a + 1] == '\0')
				return (-1);
			while (format[a + 1] == ' ')
			{
				if (format[a + 2] == '\0')
					return (-1);
				a++;
			}
			j = spec_printf(&format[++a]);
			k += j ? j(arg) : _putchar('%') + _putchar(format[a]);
		}
		else
			k += _putchar(format[a]);
	}
	va_end(arg);
	return (k);
}
