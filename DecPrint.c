#include "main.h"
/**
 *DecPrint - prints a decimal
 *@kind: int
 *Return: returns i
 */
int DecPrint(va_list kind)
{
	int lenght, p, y, num, digit, x;
	int count = 0;

	x = va_arg(kind, int);
	if (x != 0)
	{
		if (x < 0)
		{
			_putchar('-');
			count++;
		}
		num = x;
		lenght = 0;
		while (num != 0)
		{
			num /= 10;
			lenght++;
		}
		p = 1;
		for (y = 1; y <= lenght - 1; y++)
			p *= 10;
		for (y = 1; y <= lenght; y++)
		{
			digit = x / p;
			if (x < 0)
				_putchar((digit * -1) + 48);
			else
				_putchar(digit + '0');
			count++;
			x -= digit * p;
			p /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
