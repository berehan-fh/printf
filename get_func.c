#include "main.h"
/**
* get_func - search and return the correct printer function
* according to the format specifier
* @s: format specifier
* Return: return a function pointer
**/
int (*get_func(char s))(va_list)
{
	printer_list ops[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_d},
		{"i", print_i},
		{"b", print_b},
		{NULL, NULL}
	};

	int i;

	for (i = 0; ops[i].c != NULL; i++)
	{
		if (*ops[i].c == s)
			return (ops[i].f);
	}
	return (NULL);
}
