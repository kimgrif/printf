#include <unistd.h>
#include "main.h"

/**
 * main - Entry point of the program
 *
 * Description:  prints _putchar, followed by a new line
 *
 * Return: Always 0 (indicating success)
 */

int _putchar(char c)
{
 return (write(1, &c, 1));
}