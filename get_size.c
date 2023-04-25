#include "main.h"
/**
 *g_size - get_size func
 *@format: string
 *Return: char
 */
char g_size(const char *format)
{
	char s = '\0';

	while (*format)
	{
		if (*format == 'j' || *format == 'h' || *format == 'l' || *format == 'L' || *format == 't' || *format == 'z')
		{
			s = *format;
			break;
		}
		format++;
	}
	return (s);
}
