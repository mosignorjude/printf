#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#define BUFF_SIZE 1024
int _printf(const char *format, ...);
void print_int(int num);
void print_unsigned_int(unsigned int num);
void print_binary(unsigned int num);
void print_octal(unsigned int num, int pre_num);
void print_hex(unsigned int num, char x_case, int pretext);
int print_S_specifier(char *str);
void print_address(void *ptr);
void _plus_flag(int num);
void space_flag(int num);
#endif

