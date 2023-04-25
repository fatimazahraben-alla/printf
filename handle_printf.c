#include "main.h"
/**
 *handle_printf - Prints an argument based on its type
 *@fmt: Formatted string in which to print the arguments.
 *@args: List of arguments to be printed.
 *@a: a
 *@buffer: Buffer array to handle print.
 *@flags: Calculates active flags
 *@width: get width.
 *@precision: Precision specification.
 *@size: Size specifier
 *Return: int
*/
int handle_printf(const char *fmt, int *a, va_list args,
		char buffer[], int flags, int width, int precision, int size)
{
	int i, length = 0, pc = -1;
	f_str spec[] = {{'c', print_char}, {'s', print_string}, {'%', print_percent},
			{'i', print_integer}, {'d', print_integer}, {'b', print_binary}};

	for (i = 0; spec[i].fmt != '\0'; i++)
	{
		if (fmt[*a] == spec[i].fmt)
			return (spec[i].ss(args, buffer, flags, width, precision, size));
	}
	if (spec[i].fmt == '\0')
	{
		if (fmt[*a] == '\0')
			return (-1);
		length += write(1, "%%", 1);
		if (fmt[*a - 1] == ' ')
			length += write(1, " ", 1);
		else if (width)
		{
			--(*a);
			while (fmt[*a] != ' ' && fmt[*a] != '%')
				--(*a);
			if (fmt[*a] == ' ')
				--(*a);
			return (1);
		}
		length += write(1, &fmt[*a], 1);
		return (length);
	}
	return (pc);
}
