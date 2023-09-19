#include "main.h"
/**
 *_printf - function that prints all types
 *@format: the format string
 *Return: returns the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int lenght = 0, i = 0, x;

	layout types[] = {
		{"c", CharPrint},
		{"s", StringPrint},
		{"d", DecPrint},
		{"i", intPrint},
		{"%%", PerPrint},
		{NULL, NULL}
	};

	va_start(args, format);
		if (format == NULL || (format[0] == '%' format[1] == '\0'))
			return (-1);
Here:
		while (format[i] != '\0')
		{
			x = 13;
			while (x >= 0)
			{
			if (types[x].n[0] == format[i] && types[x].n[1] == format[i + 1])
			{
					lenght += types[x].f(args);
					i = i + 2;
					goto Here;
				}
				x--;
			}
			_putchar('%');
			lenght++;
			i++;
		}
	}
	va_end(args);
	return (lenght);
}
