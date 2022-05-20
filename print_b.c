#include "main.h"

/**
 * print_b - Convert decimal number to binary and prints it
 * @ar_list: Store the argument values
 * Return: count - The number of characters printed
 */

int print_b(va_list ar_list)
{
	unsigned int i, count, Num, binary, arr[32];

	i = 0, count = 0;
	Num = va_arg(ar_list, int);

	if (Num < 1)
	{
		_putchar(48);
		count++;
		return (count);
	}
	else
	{
		while (Num > 0)
		{
			binary = Num % 2;
			Num /= 2;
			arr[count] = binary;
			count++;
		}
		i = count - 1;
		while (i > 0)
		{
			_putchar('0' + arr[i]);
			i--;
		}
		_putchar('0' + arr[i]);
	}
	return (count);
}
