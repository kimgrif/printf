#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int global_chars_printed = 0; // Global variable to store the total characters printed

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    char c;
    while ((c = *format++) != '\0') {
        if (c == '%') {
            char next_c = *format++;
            switch (next_c) {
                case 'c':
                    // Print a single character
                    putchar(va_arg(args, int));
                    global_chars_printed++;
                    break;
                case 's': {
                    // Print a string
                    const char *str = va_arg(args, const char *);
                    while (*str != '\0') {
                        putchar(*str);
                        str++;
                        global_chars_printed++;
                    }
                    break;
                }
                case '%':
                    // Print a literal %
                    putchar('%');
                    global_chars_printed++;
                    break;
                default:
                    // Ignore unsupported specifiers
                    break;
            }
        } else {
            // Print regular characters
            putchar(c);
            global_chars_printed++;
        }
    }

    va_end(args);
    return global_chars_printed;
}

int main() {
    int num_chars_1 = _printf("This is a test: %c, %s, %c%%\n", 'A', "Hello, world!", 'B');
    int num_chars_2 = _printf("Another test: %c, %s, %c%%\n", 'X', "Hi there!", 'Y');

    printf("Number of characters printed in the first call: %d\n", num_chars_1);
    printf("Number of characters printed in the second call: %d\n", num_chars_2);
    printf("Total number of characters printed: %d\n", global_chars_printed);
    return 0;
}
