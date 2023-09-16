#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...);

int main() {
    int count = _printf("Hello, %s! The character is %c and this is a %%.\n", "John", 'A');
    printf("Total characters printed: %d\n", count);
    return 0;
}

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;  // Initialize the character count

    while (*format) {
        if (*format == '%') {
            format++;  // Move past the '%'

            // Check the conversion specifier
            switch (*format) {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    count += printf("%s", va_arg(args, char *));
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    // Handle unsupported specifiers
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        } else {a
            // Output regular characters
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}
