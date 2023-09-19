#include "main.h"
/**
 *_printf - function that prints all types
 *@format: the format string
 *Return: returns the number of characters printed
 */
int _printf(const char *format, ...)
{
	layout m[] = {
		{"c", CharPrint},
		{"s", StringPrint},
		{"d", DecPrint},
		{"i", intPrint},
		{"%%", PerPrint},
		{NULL, NULL}
	};
	va_list args;
	int i = 0, lenght = 0, x;

	va_start(args, format);
		if (format == NULL || (format[0] == '%' && format[1] == '\0'))
			return (-1);

		while (format[i] != '\0')
		{
			x = 13;
			while (x >= 0)
			{
			if (m[x].n[0] == format[i] && m[x].n[1] == format[i + 1])
			{
					lenght += m[x].f(args);
					i = i + 2;
					break;
				}
				x--;
			}
			if (x >= 0)
				continue;
			_putchar('%');
			lenght++;
			i++;
		}
	va_end(args);
	return (lenght);
}
