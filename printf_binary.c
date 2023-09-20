#include "main.h"

/**
 * b_func - handle binary specifier
 * @args: pointer to the next argument
 * @len: pointer to buffer current length
 * @ret: pointer to total printed length
 * @buffer: buffer to store data before printing
 */

void b_func(va_list args, int *len, int *ret, char *buffer)
{
	unsigned int digit_arg, digit;
	int i = 0, j;
	char bin[32];

	digit_arg = va_arg(args, int);
	digit = digit_arg;

	if (digit == 0)
	{
		buffer_overflow(buffer, len, ret);
		buffer[(*len)++] = '0';
		return;
	}

	while (digit > 0)
	{
		bin[i] = (digit % 2 + '0');
		digit /= 2;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		buffer_overflow(buffer, len, ret);
		buffer[(*len)++] = bin[j];
	}
}
