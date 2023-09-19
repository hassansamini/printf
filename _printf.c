#include "main.h"
/**
 *CharPrint - prints a char
 *@kind : types of arguments
 *Return: returns nothing
 */
int CharPrint(va_list kind)
{
	char c;

	c = va_arg(kind, int);
	_putchar(c);
	return (0);
}
/**
 *StringPrint - prints a string
 *@kind: types of arguments
 *Return: returns the number of chars printed
 */
int StringPrint(va_list kind)
{
	int lenght = 0;
	char *string;

	string = va_arg(kind, char *);
	if (string == NULL)
		string = "(null)";

	while (*string)
	{
		_putchar(*string);
		string++, lenght++;
	}
	return (lenght);
}
/**
 *intPrint - prints an int
 *@kind: types of arguments
 *Return: returns the number of integers printed
 */
int intPrint(va_list kind)
{
	int n = va_arg(kind, int);
	int digits;
	int i = 0, count = 0, divisor = 1;

	if (n == 0)
	{
		_putchar('0');
	}
	if (n < 0)
	{
		_putchar('-');
		count++;
		n = -n;
	}
	while (n / divisor > 0)
	{
		divisor *= 10;
		i++;
	}
	while (i > 0)
	{
		divisor /= 10;
		digits = (n / divisor) % 10;
		_putchar('0' + digits);
		count++, i++;
	}
	return (count);
}
/**
 *_printf - function that produces output according to a format
 *@format: the format of string
 *Return: returns the number of chars printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			while (*format == ' ')
				format++;

			if (*format == 'c' || *format == 's' || *format == 'd' || *format == 'i')
			{
				layout types[] = {
					{"c", CharPrint},
					{"s", StringPrint},
					{"d", intPrint},
					{"i", intPrint},
					{NULL, NULL}
				};
				int i = 0, found = 0;

				while (types[i].n)
				{
					if (*(types[i].n) == *format)
					{
						count += types[i].f(args);
						found = 1;
					}
					i++;
				}
				if (!found)
				{
					_putchar('%');
					_putchar(*format);
					count += 2;
				}
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				count += 2;
			}
		}
			else
			{
				_putchar(*format);
				count++;
			}
			format++;
		}
		va_end(args);
		return (count);
	}

