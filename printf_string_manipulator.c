#include "main.h"

/**
 * S_func - handle string specifier but converts non-printable to a hexa
 * @args: pointer to the next argument
 * @len: pointer to buffer current length
 * @ret: pointer to total printed length
 * @buffer: buffer to store data before printing
 */

void S_func(va_list args, int *len, int *ret, char *buffer)
{
	char *str, hex[2], hex_c[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	int i, j, k = 0, digit;

	str = va_arg(args, char *);

	if (str == NULL)
	{
		str = "(null)";
	}
	for (i = 0; i <  _strlen(str); i++)
	{
		hex[0] = '0';
		hex[1] = '0';

		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			buffer_overflow(buffer, len, ret);
			buffer[(*len)++] = 92;
			buffer[(*len)++] = 'x';

			digit = str[i];
			while (digit > 0)
			{
				(digit % 16) < 10 ? (hex[k++] = ((digit % 16) + '0')) :
					(hex[k++] = hex_c[(digit % 16) - 10]);
				digit /= 16;
			}
			for (j = 1; j >= 0; j--)
			{
				buffer_overflow(buffer, len, ret);
				buffer[(*len)++] = hex[j];
			}
		}
		else
		{
			buffer_overflow(buffer, len, ret);
			buffer[(*len)++] = str[i];
		}
		k = 0;
	}
}

/**
 * r_func - handle  reverse string specifier
 * @args: pointer to the next argument
 * @len: pointer to buffer current length
 * @ret: pointer to total printed length
 * @buffer: buffer to store data before printing
 */

void r_func(va_list args, int *len, int *ret, char *buffer)
{
	char *str;
	int i;

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	else
	{
		for (i = _strlen(str) - 1; i >= 0; i--)
		{
			buffer_overflow(buffer, len, ret);
			buffer[(*len)++] = str[i];
		}
	}

}

/**
 * R_func - handle  rot13 specifier
 * @args: pointer to the next argument
 * @len: pointer to buffer current length
 * @ret: pointer to total printed length
 * @buffer: buffer to store data before printing
 */

void R_func(va_list args, int *len, int *ret, char *buffer)
{
	char *str;

	char a[53] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
		     'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
		     'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
		     'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
		     'W', 'X', 'Y', 'Z'};
	char b[53] = {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
		     'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
		     'l', 'm', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
		     'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
		     'J', 'K', 'L', 'M'};
	int i, j;

	str = va_arg(args, char *);

	for (j = 0; str[j] != '\0'; j++)
	{
		i = 0;
		while (a[i] != '\0' && str[j] != a[i])
			i++;

		if (str[j] == a[i])
		{
			buffer_overflow(buffer, len, ret);
			buffer[(*len)++] = b[i];
		}
		else
		{
			buffer_overflow(buffer, len, ret);
			buffer[(*len)++] = str[j];
		}
	}
}
