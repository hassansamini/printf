#include "main.h"
/**
 * CharPrint - prints a char
 * @kind: int
 * Return: returns 1
 */
int CharPrint(va_list kind)
{
	char x;

	x = va_arg(kind, int);
	_putchar(x);
	return (1);
}
