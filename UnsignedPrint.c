#include "main.h"
/**
 *UnsignedPrint - prints an unsigned int
 *@kind: int
 *Return: returns i
 */
int UnsignedPrint(va_list kind)
{
	unsigned int num = va_arg(kind, unsigned int);
	int i = 0, x, digit;
	unsigned int t;

	if (num == 0)
	{
		_putchar('0');
	}
	x = 1;
	t = num;
	while (t >= 10)
	{
		t /= 10;
		x *= 10;
	}
	while (x > 0)
	{
		digit = num / x;
		_putchar(digit + '0');
		num %= x;
		x /= 10;
		i++;
	}
	return (i);
}
