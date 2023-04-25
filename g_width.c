#include "main.h"
/**
 *_isdigit -  checks for a digit (0 through 9)
 *@c: The character
 *Return: 1 if c is a digit or 0 otherwise
 */
int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 *g_size - get size
 *@format: format
 *@a: args
 *@args: args
 *Return: int
 */
int g_size(const char *format, int *a, va_list args)
{
	int i, width = 0;

	for (i = *a + 1; format[i] != '\0'; i++)
	{
		if (_isdigit(format[i]))
		{
			width = width * 10 + (format[i] - '0');
		}
		else if (format[i] == '*')
		{
			i++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}
	*a = i - 1;
	return (width);
}
