#include "main.h"

/**
 * printf_running - handles the format passed by
 * @format: format passed
 * @args: va_list to deal with
 * @buffer: buffer to store data before printing
 * Return: total_length of printed characters, -1 if fail
 */

int printf_running(const char *format, va_list args, char *buffer)
{
	int lens = 0, *len = &lens, returned_length = 0, *ret = &returned_length, i;
	void (*f)(va_list, int *, int *, char *);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer_overflow(buffer, len, ret);
			buffer[lens++] = format[i];
		}
		else
		{
			if (format[i + 1] == '\0')
			{
				buffer_overflow(buffer, len, ret);
				_write_buffer(buffer, len);
				return (-1);
			}
			i++;
			f = get_type(format[i]);
			if (f == NULL)
			{
				buffer_overflow(buffer, len, ret);
				buffer[lens++] = '%';
				buffer[lens++] = format[i];
			}
			else
			{
				f(args, len, ret, buffer);
			}
		}
	}
	(*ret) += (*len);
	_write_buffer(buffer, len);
	return (returned_length);
}

/**
 * _printf - our own printf function
 * @format: the last prameter
 * Return: total_length of printed characters, -1 if fail
 */

int _printf(const char *format, ...)
{
	char *buffer;
	va_list args;
	int returned_length;

	if (format == NULL)
		return (-1);

	buffer = create_buffer();

	if (buffer == NULL)
		return (-1);

	va_start(args, format);

	(returned_length) = (printf_running(format, args, buffer));

	va_end(args);
	free(buffer);

	return (returned_length);
}
