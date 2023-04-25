#include "main.h"
/**
 *g_flags - get_flags
 *@format: format
 *Return: char
 */
char g_flags(const char **format)
{
	const char *m = *format;
	char f = '\0';

	while (*m == '-' || *m == '+' || *m == '0' || *m == '#' || *m == ' ')
	{
		switch (*m)
		{
			case '-':
				f |= FLAG_MINUS;
				break;
			case '+':
				f |= FLAG_PLUS;
				break;
			case '0':
				f |= FLAG_ZERO;
				break;
			case '#':
				f |= FLAG_HASH;
				break;
			case ' ':
				f |= FLAG_SPACE;
				break;
			default:
				break;
		}
		m++;
	}
	*format = m;
	return (f);
}
