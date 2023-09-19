#include "main.h"
/**
 *
 *
 *
 *
 */
int intPrint(va_list kind)
{
	int x = va_arg(kind, int);
	int dig, temporary = x;
	int last = x % 10, multi = 1;
	int i = 0;

	if (last < 0)
	{
		_putchar('-');
		x = -x;
		i++;
	}
	if (x == 0)
	{
		_putchar('0');
		return (1);
	}
	while (temporary != 0)
	{
		multi *= 10;
		temporary /= 10;
	}
	while (multi > 1)
	{
		multi /= 10;
		dig = (x / multi) % 10;
		_putchar(dig + '0');
		i++;
	}
	return (i + 1);
}
