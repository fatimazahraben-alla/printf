#include "main.h"
#include <stdarg.h>
/**
 *_printf - printf func
 *@format: first arg
 *Return: int
 */
int _printf(const char *format, ...)
{
	int length = 0;
	char *s, c;
	va_list ars;

	va_start(ars, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = va_arg(ars, int);
					_putchar(c);
					length++;
					break;
				case 's':
					s = va_arg(ars, char *);
					while (*s != '\0')
					{
					_putchar(*s);
					s++;
					length++;
					}
					break;
				case '%':
					_putchar('%');
					length++;
					break;
			}
		}
		else
			_putchar(*format);
			length++;
		format++;
	}
	va_end(ars);
	return (length);
}
