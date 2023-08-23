#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: format
 * Return: number of character printed
*/
int _printf(const char *format, ...)
{
	char *s;
	int ch, num, len, ch_printed = 0;
	unsigned int n;

	va_list(arg_list);

	if (format == NULL)
	{
		return (-1);
	}
	va_start(arg_list, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
			ch_printed++;
		}
		else
		{
			format++;
			switch (*format)
		{
			case 'c':
					ch = va_arg(arg_list, int);
					write(1, &ch, 1);
					ch_printed++;
					break;
			case 's':
				s = va_arg(arg_list, char*);
				write(1, s, strlen(s));
				ch_printed += strlen(s);
				break;
			case '%':
				write(1, format, 1);
				ch_printed++;
				break;
			case 'd':
					num = va_arg(arg_list, int);
					print_int(num);
					ch_printed++;
					break;
			case 'i':
					num = va_arg(arg_list, int);
					print_int(num);
					ch_printed++;
					break;
			case 'b':
					num = va_arg(arg_list, int);
					print_binary(num);
					ch_printed++;
					break;
			case 'u':
					num = va_arg(arg_list, int);
					n = (unsigned int) num;
					print_unsigned_int(n);
					ch_printed++;
					break;
			case 'o':
					num = va_arg(arg_list, int);
					print_octal(num, 1);
					ch_printed++;
					break;
			case 'x':
					num = va_arg(arg_list, int);
					print_hex(num, 'x', 0);
					ch_printed++;
					break;
			case 'X':
					num = va_arg(arg_list, int);
					print_hex(num, 'X', 0);
					ch_printed++;
					break;
			case 'S':
					s = va_arg(arg_list, char*);
					len = print_S_specifier(s);
					ch_printed += strlen(s) + len;
					break;
			case '+':
					format++;
					if (*format == 'd')
					{
						num = va_arg(arg_list, int);
						_plus_flag(num);
						ch_printed++;
					}
					break;
			case ' ':
					format++;
					if (*format == 'd')
					{
						num = va_arg(arg_list, int);
						space_flag(num);
						ch_printed++;
					}else if (*format == ' ')
					format++;
					break;
			case '#':
				format++;
				num = va_arg(arg_list, int);
				if (*format == 'o')
				print_octal(num, 0);
				else if (*format == 'x')
					print_hex(num, 'x', 1);
				else if (*format == 'X')
					print_hex(num, 'X', 1);
				ch_printed++;
				break;
				default:
					break;
			}
		}
		format++
	}
	va_end(arg_list);
	return (ch_printed);
}
