#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 *printf_buffer - print the contents of buffer
 *@buffer: buffer
 *@b: length
 *Return: void
 */
void print_buffer(char buffer[], int *b)
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
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = g_flags(format, &i);
			width = g_width(format, &i, list);
			precision = g_precision(format, &i, list);
			size = g_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}
