#include "main.h"

/**
 * _memcpy - copies n bytes from memory area src to memory area dest
 * @dest: pointer to memory destination
 * @src: pointer to memory source
 * @n: number of bytes
 * @buffer_len: current bytes taken by buffer
 * Return: pointer to memory destination
 */

char *_memcpy(char *dest, char *src, unsigned int n, unsigned int buffer_len)
{
	if (n > 0)
	{
		unsigned int i;

		for (i = 0; i < n; i++)
			dest[i + buffer_len] = src[i];
	}

	return (dest);
}

/**
 * _strlen - counts the length of string
 * @s: string passed
 * Return: lengnth
 */

int _strlen(char *s)
{
	int len = 0;

	for (len = 0; s[len] != '\0'; len++)
		;

	return (len);
}

/**
 * _write_buffer - prints buffer
 * @buffer: buffer passed
 * @len: number of bytes to be printed
 */

void _write_buffer(char *buffer, int *len)
{
	write(1, buffer, *len);
}
