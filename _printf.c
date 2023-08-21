#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	printed_chars = format_handler(format, args);
	va_end(args);

	return (printed_chars);
}

/**
 * format_handler - Handles the format string and arguments
 * @format: The format string
 * @args: The va_list of arguments
 *
 * Return: The number of characters printed
 */
int format_handler(const char *format, va_list args)
{
	int i = 0, printed_chars = 0;

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			printed_chars++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			if (format[i] == '%')
			{
				_putchar('%');
				printed_chars++;
			}
			else
			{
				printed_chars += convert_handler(format[i], args);
			}
		}
		i++;
	}
	return (printed_chars);
}

/**
 * convert_handler - Handles the conversion specifiers
 * @specifier: The conversion specifier
 * @args: The va_list of arguments
 *
 * Return: The number of characters printed
 */
int convert_handler(char specifier, va_list args)
{
	int printed_chars = 0;
	char c;

	if (specifier == 'c')
	{
		c = va_arg(args, int);
		_putchar(c);
		printed_chars++;
	}
	else if (specifier == 's')
	{
		printed_chars += print_string(va_arg(args, char *));
	}
	return (printed_chars);
}

/**
 * print_string - Prints a string
 * @str: The string to print
 *
 * Return: The number of characters printed
 */
int print_string(char *str)
{
	int i = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

