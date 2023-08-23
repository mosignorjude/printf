#include "main.h"
/**
 * space_flag - prints space before a positive integer
 * @num: number
 * Return: void.
*/
void space_flag(int num)
{
	char buffer[98];
	char minus_sign = '-', space_char = ' ', ascii_0 = '0';
	int i = 0;

	if (num < 0)
	{
		write(1, &minus_sign, 1);
		num = -num;
	}
	else if (num > 0)
		write(1, &space_char, 1);
	if (num == 0)
		write(1, &ascii_0, 1);

	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (i > 0)
	{
		i--;
		write(1, &buffer[i], 1);
	}
}
/**
 * _plus_flag - prints the sign of a number
 * @num: number
 * Return: void
*/
void _plus_flag(int num)
{
	char buffer[98];
	char minus_sign = '-', plus_sign = '+', ascii_0 = '0';
	int i = 0;

	if (num < 0)
	{
		write(1, &minus_sign, 1);
		num = -num;
	}
	else if (num > 0)
		write(1, &plus_sign, 1);
	if (num == 0)
		write(1, &ascii_0, 1);

	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}

	while (i > 0)
	{
		i--;
		write(1, &buffer[i], 1);
	}
}
/**
 * print_S_specifier - prints the string
 * @str: string.
 * Return: void.
*/
int print_S_specifier(char *str)
{
	int ascii_val = 0, len = 0;
	char backslash = '\\';
	char letter_x = 'x';

	if (str == NULL)
		return (-1);
	while (*str != '\0')
	{
		ascii_val = (int) (*str);
		if (ascii_val < 32 || ascii_val >= 127)
		{
			write(1, &backslash, 1);
			write(1, &letter_x, 1);
			print_hex(ascii_val, 'X', 0);
		}
		else
		{
			write(1, str, 1);
		}
		len++;
		str++;
	}
	return (len + 4);
}
