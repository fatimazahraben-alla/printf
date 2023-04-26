#include "main.h"
/**
 *is_digit -  checks for a digit (0 through 9)
 *@c: The character
 *Return: 1 if c is a digit or 0 otherwise
 */
int is_digit(char c)
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
 *g_width - calculates the width 
 *@format: format
 *@i: args
 *@list: list of argument
 *Return: int
 */
int g_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}
