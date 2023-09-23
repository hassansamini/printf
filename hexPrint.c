#include "main.h"
/**
 *hexPrint - prints hexadecimals lowercase
 *@kind: int
 *Return: returns count
 */
int hexPrint(va_list kind)
{
	int *ar;
	int i, count;
	unsigned int number = va_arg(kind, unsigned int), t = number;

	while (number / 16 != 0)
	{
		number /= 16;
		count++;
	}
	count++;
	ar = malloc(count * sizeof(int));
	for (i = 0; i < count; i++)
	{
		ar[i] = t % 16;
		t /= 16;
	}
	for (i = count - 1; i >= 0; i--)
	{
		if (ar[i] > 9)
		{
			ar[i] = ar[i] + 39;
			_putchar(ar[i] + '0');
		}
	}
		free(ar);
		return (count);
}
