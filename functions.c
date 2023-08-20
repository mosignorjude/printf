#include "main.h"
/**
 * print_int - print number using p
 * @num: number to print.
 * Return: void
*/
void print_int(int num)
{
    char buffer[98];
    int i = 0;
    /*for negative number*/
    if (num < 0)
    {
        putchar('-');
    }
    /*for zero*/
    if (num == 0)
    {
        putchar('0');
    }
    /*extracting, converting and storing the numbers*/
    while (num > 0)
    {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }
    /*printing the reverse*/
    while (i > 0)
    {
        i--;
        putchar(buffer[i]);
    }
}
