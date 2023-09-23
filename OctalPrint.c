#include "main.h"
/**
 *OctalPrint - prints octal numbers
 *@kind: int
 *Return: returns count
 */
int OctalPrint(va_list kind)
{
	unsigned int num = va_arg(kind, unsigned int);
	char oct[20];
	int i, count = 0;

	if (num == 0)
	{
		_putchar('0');
	}
	while (num != 0)
	{
		oct[count] = '0' + (num % 8);
		num /= 8;
		count++;
	}
	for (i = count - 1; i >= 0; i--)
	{
	_putchar(oct[i]);
	}
	return (count);
}
