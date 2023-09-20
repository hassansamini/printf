#include "main.h"
/**
 * _putchar - prints a char
 * @c: the character being printed
 * Return: retunrs
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
