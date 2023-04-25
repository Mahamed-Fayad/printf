#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
* _printf - Printf function
* @f: format.
* Return: Printed chars.
*/
int _printf(const char *f, ...)
{
int i, printed = 0, printed_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];
if (f == NULL)
return (-1);
va_start(list, f);
for (i = 0; format && f[i] != '\0'; i++)
{
if (f[i] != '%')
{
buffer[buff_ind++] = f[i];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
/* write(1, &f[i], 1);*/
printed_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = get_flags(f, &i);
width = get_width(f, &i, list);
precision = get_precision(f, &i, list);
size = get_size(f, &i);
++i;
printed = handle_print(f, &i, list, buffer,
flags, width, precision, size);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
print_buffer(buffer, &buff_ind);
va_end(list);
return (printed_chars);
}
/**
* print_buffer - Prints the contents of the buffer if it exist
* @buffer: Array of chars
* @buff_ind: Index at which to add next char, represents the length.
*/
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);
*buff_ind = 0;
}
