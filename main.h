#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/**
 * struct structure - the structure
 * @n: char
 * @f: int
 */
typedef struct structure
{
	char *n;
	int (*f)(va_list kind);
} layout;

int _printf(const char *format, ...);
int _putchar(char c);
int CharPrint(va_list kind);
int StringPrint(va_list kind);
int intPrint(va_list kind);
int BinaryPrint(va_list n);
int DecPrint(va_list kind);
int PerPrint(va_list kind);
int (*Functions(const char *format))(va_list);
#endif
