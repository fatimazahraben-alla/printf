#include "main.h"
/**
 *print_char - print character
 *@cl: char
 *Return: len
 */
int print_char(va_list cl)
{
	char c = va_arg(cl, int);

	_putchar(c);
	return (1);
}
/**
 *print_string - print str
 *@sl: str
 *Return: len
 */
int print_string(va_list sl)
{
	int len = 0;
	char *s;

	s = va_arg(sl, char *);
	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		_putchar(*s);
		s++;
		len++;
	}
	return (len);
}
