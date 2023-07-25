#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _putchar - A custom function to print a single character
 * @c: The character to be printed
 */
void _putchar(char c)
{
    putchar(c);
}

/**
 * handle_char - A helper function to handle the 'c' specifier
 * and print a single character.
 */
int handle_char(va_list args)
{
    char c = va_arg(args, int);
    _putchar(c);
    return 1;
}

/**
 * handle_string - A helper function to handle the 's' specifier
 * and print a string.
 */
int handle_string(va_list args)
{
    const char *str = va_arg(args, const char *);
    int count = 0;

    while (*str)
    {
        _putchar(*str);
        str++;
        count++;
    }
    return count;
}

/**
 * handle_percent - A helper function to handle the '%%' specifier
 * and print a literal '%'.
 */
int handle_percent(va_list args)
{
    (void)args; // Unused parameter
    _putchar('%');
    return 1;
}

/**
 * _printf - A function that prints the formatted output to stdout
 * @format: The format string containing the conversion specifiers
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    va_start(args, format);
    if (!format || !format[0])
        return -1;

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
            case 'c':
                count += handle_char(args);
                break;
            case 's':
                count += handle_string(args);
                break;
            case '%':
                count += handle_percent(args);
                break;
            default:
                _putchar(*format);
                count++;
                break;
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
    return count;
}
