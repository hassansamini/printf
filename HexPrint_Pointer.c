#include "main.h"
/**
 * HexPrint_Pointer - prints hexa
 * @number: int
 * Return: returns count
 */
int HexPrint_Pointer(unsigned long int number)
{
	long int *ar;
	long int i, count = 0;
	unsigned long int t = number;

	while (number / 16 != 0)
	{
		number /= 16;
		count++;
	}
	count++;
	ar = malloc(count * sizeof(long int));
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
