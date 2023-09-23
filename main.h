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
int PointerPrint(va_list kind);
int HexPrint(va_list kind);
int hexPrint(va_list kind);
int HexPrint_Pointer(unsigned long int number);
int OctalPrint(va_list kind);
int UnsignedPrint(va_list kind);
#endif
