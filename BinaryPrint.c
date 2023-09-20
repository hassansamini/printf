#include "main.h"
/**
 *BinaryPrint - prints binary
 *@n: int
 *Return: returns n
 */
int BinaryPrint(va_list n)
{
	int x = 0, y = 0, a = 1, b, i;
	unsigned int j = va_arg(n, unsigned int);
	unsigned int p;

	for (i = 0; i < 32; i++)
	{
		p = ((a << (31 - i)) & j);
		if (p >> (31 - i))
			x = 1;
		if (x)
		{
			b = p >> (31 - i);
			_putchar(b + 48);
			y++;
		}
	}
	if (y == 0)
	{
		y++;
		_putchar('0');
	}
	return (y);
}
