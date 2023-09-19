#include "main.h"
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int length = 0, i = 0, x;
	layout types[] = {
		{"%s", StringPrint}, {"%c", CharPrint},
		{"%%", PerPrint},
		{"%i", intPrint}, {"%d", DecPrint},
	};

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format[i] != '\0')
	{
		x = 13;
		while (x >= 0)
		{
			if (types[x].n[0] == format[i] && types[x].n[1] == format[i + 1])
			{
				length += types[x].f(args);
				i = i + 2;
				break;
			}
			x--;
		}
		if (x >= 0)
		continue;
		_putchar(format[i]);
		length++;
		i++;
	}
	va_end(args);
	return (length);
}
