#include "main.h"
/**
* _printf - a print function. works just like stdio print
* @format: strings and format characters to print
* Return: count of characters printed
**/
int _printf(const char *format, ...)
{
	va_list inputs;
	int (*printer)(va_list);
	unsigned int i = 0, counter = 0;

	if (format == NULL)
		return (-1);

	va_start(inputs, format);

	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			counter++;
			i++;
			continue;
		}
		else
		{
			if (format[i + 1] == '%')
			{
				_putchar('%');
				counter++;
				i += 2;
				continue;
			}
			else
			{
				printer = get_func(format[i + 1]);
				if (printer == NULL)
					return (-1);
				i += 2;
				counter += printer(inputs);
				continue;
			}
		}
		i++;
	}
	va_end(inputs);
	return (counter);
}
