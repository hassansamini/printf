#include "main.h"
/**
 *
 *
 *
 *
 */
int DecPrint(va_list kind)
{
	int x = va_arg(kind, int);
	int num = x, temporary = num;
	int i = 0;
	int multi = 1;

	if (x < 0)
	{
		_putchar('-');
		num = -num;
		i++;
	}

	while (temporary / 10 != 0)
	{
		multi *= 10;
		temporary /= 10;
	}
	while (multi > 0)
	{
		int dig = num / multi;
		_putchar(dig + '0');
		num -= dig * multi;
		multi /= 10;
		i++;
	}
	return (i);
}
