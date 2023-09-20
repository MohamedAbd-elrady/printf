#include "main.h"

/**
 * o_func - handle octal specifier
 * @args: pointer to the next argument
 * @len: pointer to buffer current length
 * @ret: pointer to total printed length
 * @buffer: buffer to store data before printing
 */

void o_func(va_list args, int *len, int *ret, char *buffer)
{
	unsigned int digit_arg, digit;
	long  int i = 0, j;
	char oct[32];

	digit_arg = va_arg(args, unsigned int);
	digit = digit_arg;

	if (digit == 0)
	{
		buffer_overflow(buffer, len, ret);
		buffer[(*len)++] = '0';
		return;
	}

	while (digit > 0)
	{
		oct[i] = (digit % 8 + '0');
		digit /= 8;
		i++;

	}

	for (j = i - 1; j >= 0; j--)
	{
		buffer_overflow(buffer, len, ret);
		buffer[(*len)++] = oct[j];
	}
}
