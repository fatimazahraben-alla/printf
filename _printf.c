#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 *printf_buffer - print the contents of buffer
 *@buffer: buffer
 *@b: length
 *Return: void
 */
void printf_buffer(char buffer[], int *b)
{
	if (*b > 0)
	{
		write(1, &buffer[0], *b);
	}
	*b = 0;
}
/**
 *_printf - printf func
 *@format: first arg
 *Return: int
 */
int _printf(const char *format, ...)
{
	int b = 0, p = 0, pc = 0;
	int flags, width, prec, size, i;
	va_list args;
	char buffer[BUFFER_SIZE];

	if (!format)
		return (-1);
	va_start(args, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[b++]  = format[i];
			if (b == BUFFER_SIZE)
				printf_buffer(buffer, &b);
			pc++;
		}
		else
		{
			printf_buffer(buffer, &b);
			flags = g_flags(format, &i);
			width = g_width(format, &i, args);
			prec = g_precision(format, &i, args);
			size = g_size(format, &i);
			++i;
			p = handle_printf(format, &i, args, buffer, flags, width, prec, size);
			if (p == -1)
				return (-1);
			pc += p;
		}
	}
	printf_buffer(buffer, &b);
	va_end(args);
	return (pc);
}
