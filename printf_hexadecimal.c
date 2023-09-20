#include "main.h"

/**
 * h_func - handle hexa-decimal specifier in lower case
 * @args: pointer to the next argument
 * @len: pointer to buffer current length
 * @ret: pointer to total printed length
 * @buffer: buffer to store data before printing
 */

void h_func(va_list args, int *len, int *ret, char *buffer)
{
	unsigned int digit_arg, digit;
	int i = 0, j;
	char hex[32];
	char hex_car[6] = {'a', 'b', 'c', 'd', 'e', 'f'};

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
		if (digit % 16 < 10)
			hex[i] = (digit % 16 + '0');
		else
			hex[i] = hex_car[(digit % 16) - 10];
		digit /= 16;
		i++;

	}

	for (j = i - 1; j >= 0; j--)
	{
		buffer_overflow(buffer, len, ret);
		buffer[(*len)++] = hex[j];
	}
}

/**
 * H_func - handle hexa-decimal specifier in upper case
 * @args: pointer to the next argument
 * @len: pointer to buffer current length
 * @ret: pointer to total printed length
 * @buffer: buffer to store data before printing
 */

void H_func(va_list args, int *len, int *ret, char *buffer)
{
	unsigned int digit_arg, digit;
	int i = 0, j;
	char hex[32];
	char hex_car[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

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
		if (digit % 16 < 10)
			hex[i] = (digit % 16 + '0');
		else
			hex[i] = hex_car[(digit % 16) - 10];
		digit /= 16;
		i++;

	}

	for (j = i - 1; j >= 0; j--)
	{
		buffer_overflow(buffer, len, ret);
		buffer[(*len)++] = hex[j];
	}
}
