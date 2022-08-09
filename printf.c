#include "main.h"

/**
 * _printf - Custom function to print to STDOUT
 * @format: input character string
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	const char *input;
	char *s;
	unsigned int i, count = 0;

	va_list args;

	va_start(args, format);

	for (input = format; *input != '\0'; input++)
	{
		while (*input != '%')
		{
			putchar(*input);
			count++;
			input++;
		}

		input++;

		switch (*input)
		{
			case 'c':
				i = va_arg(args, int);
				putchar(i);
				count++;
				break;

			case 's':
				s = va_arg(args, char *);
				puts(s);
				count += str_len(s);
				break;
		}
	}

	va_end(args);
	return (count);
}

/**
 * str_len - Calculates the length of a string
 * @s: input string
 * Return: Length of the input string
 */

int str_len(char *s)
{
	int length = 0, i;

	for (i = 0; s[i] != '\0'; i++)
		length++;
	return (length);
}
