#include "main.h"

/**
 * get_type - holds the specifier and returns with the correct type
 * @c: type to check
 * Return: pointer to function if matches, NULL if no matches
 */

void (*get_type(char c))(va_list, int *, int *, char *)
{
	int i;
	v_type types[] = {
		{"c", c_func},
		{"s", s_func},
		{"%", percent_func},
		{"d", d_func},
		{"i", d_func},
		{"b", b_func},
		{"u", u_func},
		{"o", o_func},
		{"x", h_func},
		{"X", H_func},
		{"S", S_func},
		{"r", r_func},
		{"R", R_func},
		{"p", p_func},
		{NULL, NULL}
	};

	for (i = 0; types[i].specifier != NULL; i++)
	{
		if (c == *types[i].specifier)
		{
			return (types[i].f);
		}
	}
	return (NULL);
}

/**
 * create_buffer - creates a buffer for printing
 * Return: pointer to buffer
 */

char *create_buffer(void)
{
	char *buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);

	if (buffer == NULL)
		return (NULL);

	return (buffer);
}

/**
 * buffer_overflow - checks if buffer is full
 * @buffer: pointer to buffer
 * @len: pointer to length of the buffer
 * @ret: pointer to total length printed
 */

void buffer_overflow(char *buffer, int *len, int *ret)
{
	if (*len > BUFFER_SIZE - 4)
	{
		_write_buffer(buffer, len);
		(*ret) += (*len);
		(*len) = 0;
	}
}
