#include "main.h"
/**
 *g_flags - get flags
 *@format: format
 *@a: arg
 *Return: int
 */
int g_flags(const char *format, int *a)
{
	int flags = 0, i, j;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_A[] = {FLAG_MINUS, FLAG_PLUS,
		FLAG_ZERO, FLAG_HASH, FLAG_SPACE, 0};

	for (j = *a + 1; format[j] != '\0'; j++)
	{
		for (i = 0; FLAGS_CHAR[i] != '\0'; i++)
		{
			if (format[j] == FLAGS_CHAR[i])
			{
				flags |= FLAGS_A[i];
				break;
			}
		}
		if (FLAGS_CHAR[i] == 0)
			break;
	}
	*a = j - 1;
	return (flags);
}
