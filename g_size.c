#include "main.h"
/**
 *g_size - get size
 *@format: format
 *@a: args
 *Return: int
 */
int g_size(const char *format, int *a)
{
	int i = *a + 1, size = 0;

	if (format[i] == 'l')
		size = SIZE_L;
	else if (format[i] == 'h')
		size = SIZE_S;

	if (size == 0)
		*a = i - 1;
	else
		*a = i;
	return (size);
}
