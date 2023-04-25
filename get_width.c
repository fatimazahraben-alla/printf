#include "main.h"
/**
 *g_width - get_width func
 *@format: string
 *Return: int
 */
int g_width(const char *format)
{
	int w = 0;

	while (*format)
	{
		if (*format >= '0' && *format <= '9')
		{
			w = w * 10 + (*format - '0');
			format++;
		}
		else if (*format == '*')
		{
			return (-1);
		}
		else
		{
			break;
		}
	}
	return (w);
}
