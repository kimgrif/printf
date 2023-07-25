#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int chars_printed = 0;
    char c;
    while ((c = *format++) != '\0') {
        if (c == '%') {
            char next_c = *format++;
            switch (next_c) {
                case 'c':
                    // Print a single character
                    putchar(va_arg(args, int));
                    chars_printed++;
                    break;
                case 's': {
                    // Print a string
                    const char *str = va_arg(args, const char *);
                    while (*str != '\0') {
                        putchar(*str);
                        str++;
                        chars_printed++;
                    }
                    break;
                }
                case '%':
                    // Print a literal %
                    putchar('%');
                    chars_printed++;
                    break;
                default:
                    // Ignore unsupported specifiers
                    break;
            }
        } else {
            // Print regular characters
            putchar(c);
            chars_printed++;
        }
    }

    va_end(args);
    return chars_printed;
}

int main() {
    int num_chars = _printf("This is a test: %c, %s, %c%%\n", 'A', "Hello, world!", 'B');
    printf("Number of characters printed: %d\n", num_chars);
    return 0;
}
