#include "main.h"
/**
 * print_binary - prints number in base 2
 * @num: number
 * Return void
*/
void print_binary(unsigned int num)
{
	unsigned int i = 0, n;
	unsigned char bin_buffer[98], ascii_0 = '0';

	if (num == 0)
		write(1, &ascii_0, 1);

	while (num > 0)
	{
		n = num % 2;
		bin_buffer[i++] = n + '0';
		num /= 2;
	}
	while (i > 0)
	{
		i--;
		write(1, &bin_buffer[i], 1);
	}
}
/**
 * print_hex - prints hex number
 * @num: number
 * @x_case: case of the hex characters
 * @pretext: select 0x pretext format
 * Return void;
*/
void print_hex(unsigned int num, char x_case, int pretext)
{
	unsigned int i = 0, len = 0, n;
	char pretext_lc[2] = "0x", pretext_uc[2] = "0X";
	unsigned char hex_buffer[98], ascii_0 = '0';

	if (num == 0)
		write(1, &ascii_0, 1);
	while (num > 0)
	{
		n = num % 16;
		if (n >= 10 && n < 16)
		{
			if (x_case == 'x')
				hex_buffer[i++] = 'a' + (n - 10);
			else if (x_case == 'X')
				hex_buffer[i++] = 'A' + (n - 10);
		}
		else
			hex_buffer[i++] = n + '0';
		num /= 16;
		len++;
	}
	if (pretext == 1 && x_case == 'x')
		write(1, &pretext_lc, 2);
	else if (pretext == 1 && x_case == 'X')
		write(1, &pretext_uc, 2);
	else if (pretext == 0)
	{
	}
	else
	{
		return;
	}
	while (i > 0)
	{
		i--;
		if (len < 2)
			write(1, &ascii_0, 1);
		write(1, &hex_buffer[i], 1);
	}
}

/**
 * print_octal - prints octal number
 * @num: number
 * @pre_num: number 0 before the octal
 * Return void;
*/
void print_octal(unsigned int num, int pre_num)
{
	unsigned int i = 0, n;
	unsigned char oct_buffer[98], ascii_0 = '0';

	if (num == 0)
		write(1, &ascii_0, 1);

	while (num > 0)
	{
		n = num % 8;
		oct_buffer[i++] = n + '0';
		num /= 8;
	}
	if (pre_num == 0)
		write(1, &ascii_0, 1);
	else if (pre_num != 0)
	{
	};
	while (i > 0)
	{
		i--;
		write(1, &oct_buffer[i], 1);
	}
}
/**
 * print_int - print integers
 * @num: number to print.
 * Return: void
*/
void print_int(int num)
{
	char buffer[20];
	char sign = '-', ascii_0 = '0';
	int i = 0;

	if (num < 0)
	{
		write(1, &sign, 1);
		num = -num;
	}
	if (num == 0)
	{
		write(1, &ascii_0, 1);
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
		write(1, &buffer[i], 1);
	}
}
/**
 * print_unsigned_int - print unsigned int
 * @num: number to print.
 * Return: void
*/
void print_unsigned_int(unsigned int num)
{
	unsigned char buffer[20], ascii_0 = '0';
	int i = 0;

	/*for zero*/
	if (num == 0)
		write(1, &ascii_0, 1);
	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}
	/*printing the reverse*/
	while (i > 0)
	{
		i--;
		write(1, &buffer[i], 1);
	}
}
