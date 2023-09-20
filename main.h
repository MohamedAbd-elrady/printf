#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

/**
 * struct validTypes - struct that holds types
 * @specifier: specifier to ckeck
 * @f: pointer to function
 */

struct validTypes
{
	char *specifier;
	void (*f)(va_list, int *, int *, char *);
};

typedef struct validTypes v_type;

int _printf(const char *format, ...);
int printf_running(const char *format, va_list args, char *buffer);

void (*get_type(char c))(va_list, int *, int *, char *);
char *create_buffer(void);
void buffer_overflow(char *buffer, int *len, int *ret);

char *_memcpy(char *dest, char *src, unsigned int n, unsigned  int buffer_len);
int _strlen(char *s);
void _write_buffer(char *buffer, int *len);

void c_func(va_list args, int *len, int *ret, char *buffer);
void s_func(va_list args, int *len, int *ret, char *buffer);
void percent_func(va_list args, int *len, int *ret, char *buffer);
void d_func(va_list args, int *len, int *ret, char *buffer);
void b_func(va_list args, int *len, int *ret, char *buffer);
void u_func(va_list args, int *len, int *ret, char *buffer);
void o_func(va_list args, int *len, int *ret, char *buffer);
void h_func(va_list args, int *len, int *ret, char *buffer);
void H_func(va_list args, int *len, int *ret, char *buffer);
void S_func(va_list args, int *len, int *ret, char *buffer);
void r_func(va_list args, int *len, int *ret, char *buffer);
void R_func(va_list args, int *len, int *ret, char *buffer);
void p_func(va_list args, int *len, int *ret, char *buffer);

#endif
