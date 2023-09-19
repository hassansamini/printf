#include "main.h"
/**
 *
 *
 *
 */
int StringPrint(va_list kind)
{
	char *string;
	int i;

	string = va_arg(kind, char *);
	if (string == NULL)
		string = "(null)";
	for (i = 0; string[i]; i++)
	{
		_putchar(string[i]);
	}
	return (i);
}
