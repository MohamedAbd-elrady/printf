#include "main.h"

/**
 * p_func - handle address specifier
 * @args: pointer to the next argument
 * @len: pointer to buffer current length
 * @ret: pointer to total printed length
 * @buffer: buffer to store data before printing
 */

void p_func(va_list args, int *len, int *ret, char *buffer)
{
	char *str = "(nil)";
	char hex[32], hex_car[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	unsigned long int address, digit;
	int i = 0, j;

	address = va_arg(args, unsigned long int);

	if (address == '\0')
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			buffer_overflow(buffer, len, ret);
			buffer[(*len)++] = str[i];
		}
	}
	else
	{
		digit = address;
		while (digit > 0)
		{
			if (digit % 16 < 10)
				hex[i] = (digit % 16 + '0');
			else
				hex[i] = hex_car[(digit % 16) - 10];
			digit /= 16;
			i++;

		}

		buffer_overflow(buffer, len, ret);
		buffer[(*len)++] = '0';
		buffer[(*len)++] = 'x';

		for (j = i - 1; j >= 0; j--)
		{
			buffer_overflow(buffer, len, ret);
			buffer[(*len)++] = hex[j];
		}
	}
}
