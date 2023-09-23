#include "main.h"
/**
 * PointerPrint - prints a pointer address
 * @kind: int
 * Return: returns the result
 */
int PointerPrint(va_list kind)
{
	void *p = va_arg(kind, void*);
	long int a;
	int i, b;
	char *s = "(nil)";

	if (p == NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			_putchar(s[i]);
		}
		return (i);
	}
	a = (unsigned long int)p;
	_putchar('0');
	_putchar('x');
	b = HexPrint_Pointer(a);
	return (b + 2);
}
