#include "main.h"

/**
* _printf - a print function. works just like stdio print
* @format: strings and format characters to print
* Return: count of characters printed
**/
int _printf(const char *format, ...)
{
	int count = -1;

	if (format != NULL)
	{
		int i;
		va_list inputs;
		int (*printer)(va_list);

		va_start(inputs, format);
		if (format[0] == '%' && format[1] == '\0')
			return (-1);
		count = 0;

		for (i = 0; format[i] != '\0'; i++)
		{
			if (format[i] == '%')
			{
				if (format[i + 1] == '%')
				{
					count += _putchar(format[i]);
					i++;
				}
				else if (format[i + 1] != '\0')
				{
					printer = get_func(format[i + 1]);
					if (printer)
						count += printer(inputs);
					else
						count += _putchar(format[i]);
						count += _putchar(format[i + 1]);
					i++;
				}
			}
			else
				count += _putchar(format[i]);
		}
		va_end(inputs);
	}

	return (count);
}
