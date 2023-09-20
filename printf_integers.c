#include "main.h"

/**
 * d_func - handle signed integer specifier
 * @args: pointer to the next argument
 * @len: pointer to buffer current length
 * @ret: pointer to total printed length
 * @buffer: buffer to store data before printing
 */

void d_func(va_list args, int *len, int *ret, char *buffer)
{
	unsigned int tens, digit;
	long int num_arg, number;
	double t_beg = 1;

	num_arg = va_arg(args, int);
	number = num_arg;

	if (number == 0)
	{
		buffer_overflow(buffer, len, ret);
		buffer[(*len)++] = '0';
	}
	else
	{
		if (number < 0)
		{
			number = number * -1;
			buffer_overflow(buffer, len, ret);
			buffer[(*len)++] = '-';
		}

		while (t_beg <= number)
			t_beg *= 10;
		tens = t_beg / 10;

		while (tens >= 1)
		{
			digit = number / tens;

			buffer_overflow(buffer, len, ret);
			buffer[(*len)++] = (digit + '0');

			number = (number - (tens * digit));
			tens /= 10;
		}
	}
}

/**
 * u_func - handle unsigned integer specifier
 * @args: pointer to the next argument
 * @len: pointer to buffer current length
 * @ret: pointer to total printed length
 * @buffer: buffer to store data before printing
 */

void u_func(va_list args, int *len, int *ret, char *buffer)
{
	unsigned int tens, digit, num_arg, number;
	double t_beg = 1;

	num_arg = va_arg(args, unsigned int);
	number = num_arg;

	if (number == 0)
	{
		buffer_overflow(buffer, len, ret);
		buffer[(*len)++] = '0';
	}
	else
	{
		while (t_beg <= number)
			t_beg *= 10;
		tens = t_beg / 10;

		while (tens >= 1)
		{
			digit = number / tens;

			buffer_overflow(buffer, len, ret);
			buffer[(*len)++] = (digit + '0');

			number = (number - (tens * digit));
			tens /= 10;
		}
	}
}
