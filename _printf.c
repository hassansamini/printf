#include "main.h"
/**
  * Functions - function that help
  * @format: specifier
  * Return: returning null
  */
int (*Functions(const char *format))(va_list)
{
	unsigned int i = 0;
	layout types[] = {
		{"s", StringPrint}, {"x", hexPrint},
		{"c", CharPrint}, {"X", HexPrint},
		{"i", DecPrint}, {"p", PointerPrint},
		{"d", DecPrint}, {"u", UnsignedPrint},
		{"b", BinaryPrint}, {"o", OctalPrint},
		{NULL, NULL}
	};

	while (types[i].n)
	{
		if (types[i].n[0] == (*format))
		{
			return (types[i].f);
		}
		i++;
	}
	return ('\0');
}

/**
  * _printf - function that prints all types
  * @format: specifier
  * Return: the length of the string
  */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int a = 0, length = 0;
	int (*f)(va_list);

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	while (format[a])
	{
		for (; format[a] != '%' && format[a]; a++)
		{
			_putchar(format[a]);
			length++;
		}
		if (format[a] == '\0')
		{
			return (length);
		}
		f = Functions(&format[a + 1]);
		if (f != NULL)
		{
			length += f(args);
			a += 2;
			continue;
		}
		if (!format[a + 1])
		{
			return (-1);
		}
		_putchar(format[a]);
		length++;
		if (format[a + 1] == '%')
			a += 2;
		else
			a++;
	}
	va_end(args);
	return (length);
}
