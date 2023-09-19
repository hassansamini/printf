#include "main.h"
/**
 *
 *
 *
 *
 */
int CharPrint(va_list kind)
{
	char x;

	x = va_arg(kind, int);
	_putchar(x);
	return (1);
}
