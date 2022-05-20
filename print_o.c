#include "main.h"

/**
 * print_o - prints an unsigned int in octal notation
 * @o: unsigned int to print
 * Return: counter - number of printed characters
 */
int print_o(va_list ar_list)
{
	unsigned int a[11];
	unsigned int j = 1, m = 1073741824, n, sum = 0;
	int counter;

	n = va_arg(ar_list, unsigned int);
	a[0] = n / m;
	for (; j < 11; j++)
	{
		m /= 8;
		a[j] = (n / m) % 8;
	}
	for (j = 0; j < 11; j++)
	{
		sum += a[j];
		if (sum || j == 10)
		{
			_putchar('0' + a[j]);
			counter++;
		}
	}
	return (counter);
}
