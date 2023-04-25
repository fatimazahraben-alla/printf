#include "main.h"
/**
 *spec_printf - returnn pointer
 *@format: format agr
 *Return: str pointer
 */
int (*spec_printf(const char *format))(va_list)
{
	int i = 0;
	f_str spec[] = {{"c", print_char}, {"s", print_string}, {NULL, NULL}};

	while (spec[i].ss)
	{
		if (*format == *(spec[i].ss))
			return (spec[i].j);
		i++;
	}
	return (NULL);
}
