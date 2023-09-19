#include "main.h"
/**
 *
 *
 *
 *
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
	if (*format == '%')
	{
		if (format == NULL || format[1] == '\0')
			return (-1);

		while (format[i] != '\0')
		{
			x = 13;
			while (x >=0)
			{
				if (types[x].n[0] == format[i] && types[x].n[1] == format[i + 1 ])
				{
					lenght += types[x].f(args);
					i = i + 2;
					break;
				}
				x--;
			}
			if (x >= 0)
				continue;
			_putchar(format[i]);
			lenght++;
			i++;
		}
	}
	va_end(args);
	return (lenght);
}
