#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 *print_buffer - print th contents of buffer
 *@buffer: buffer
 *@s: size
 *Return: void
 */
void print_buffer(char *buffer, int s)
{
	writr(1, buffer, s);
}
/**
 *_printf - printf func
 *@format: first arg
 *Return: int
 */
int _printf(const char *format, ...)
{
	int width, precis, length = 0;
	char *flags, size;
	const char *m;
	va_list ars;

	va_start(ars, format);
	for (m = format, *m != '\0'; m++)
	{
		if (*m != '%')
		{
			length += print_buffer(m, 1);
			continue;
		}
		m++;
		flags = g_flags(&m);
		width = g_width(&m, ars);
		precis = g_precision(&m, ars);
		size = g_size(&m);
		length += handle_p(&m, ars, flags, width, precis, size);
	}

	print_buffer(NULL, 0);
	va_end(ars);
	return (length);
}
