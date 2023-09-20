#include "main.h"

/**
 * c_func - handle character specifier
 * @args: pointer to the next argument
 * @len: pointer to buffer current length
 * @ret: pointer to total printed length
 * @buffer: buffer to store data before printing
 */

void c_func(va_list args, int *len, int *ret, char *buffer)
{
	char c = va_arg(args, int);

	buffer_overflow(buffer, len, ret);
	buffer[(*len)++] = c; /*after test check fo ++*/
}

/**
 * s_func - handle string specifier
 * @args: pointer to the next argument
 * @len: pointer to buffer current length
 * @ret: pointer to total printed length
 * @buffer: buffer to store data before printing
 */

void s_func(va_list args, int *len, int *ret, char *buffer)
{
	char *str;
	int i;

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; i < _strlen(str); i++)
	{
		buffer_overflow(buffer, len, ret);
		buffer[(*len)++] = str[i]; /*after test check fo ++*/
	}
}

/**
 * percent_func - handle character %
 * @args: pointer to the next argument
 * @len: pointer to buffer current length
 * @ret: pointer to total printed length
 * @buffer: buffer to store data before printing
 */

void percent_func(va_list args, int *len, int *ret, char *buffer)
{
	(void) args;

	buffer_overflow(buffer, len, ret);
	buffer[(*len)++] = '%'; /*after test check fo ++*/
}
