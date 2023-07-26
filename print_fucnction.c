#include "main.h"

/**
 * print_char - Prints a single character
 * @args: The list of arguments
 * Return: Number of characters printed (always 1)
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    write(1, &c, 1);
    return (1);
}

/**
 * print_string - Prints a string
 * @args: The list of arguments
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int length = 0;

    if (str == NULL)
        str = "(null)";

    while (str[length] != '\0')
        length++;

    write(1, str, length);
    return (length);
}

/**
 * print_percent - Prints a percent sign
 * @args: The list of arguments
 * Return: Always returns 1 (number of characters printed)
 */
int print_percent(va_list args)
{
    char percent = '%';
    write(1, &percent, 1);
    return (1);
}

/**
 * print_int - Prints an integer
 * @args: The list of arguments
 * Return: Number of characters printed
 */
int print_int(va_list args)
{
    long int n = va_arg(args, long int);
    int i = BUFF_SIZE - 2;
    int is_negative = 0;
    unsigned long int num;

    n = convert_size_number(n, size);

    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }

    char buffer[BUFF_SIZE];
    buffer[BUFF_SIZE - 1] = '\0';

    num = (unsigned long int)(n < 0 ? -n : n);

    while (num > 0)
    {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
    }

    if (n < 0)
    {
        buffer[i--] = '-';
        is_negative = 1;
    }

    write_number(is_negative, i + 1, buffer);
    return (BUFF_SIZE - i - 2 + is_negative);
}

/**
 * print_binary - Prints a binary representation of an unsigned integer
 * @args: The list of arguments
 * Return: Number of characters printed
 */
int print_binary(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    unsigned int m = 2147483648; /* (2 ^ 31) */
    unsigned int a[32];
    int count = 0, i;

    for (i = 0; i < 32; i++)
    {
        a[i] = (n & m) ? 1 : 0;
        m >>= 1;
    }

    for (i = 0; i < 32; i++)
    {
        if (a[i] || i == 31)
        {
            char z = '0' + a[i];
            write(1, &z, 1);
            count++;
        }
    }

    return (count);
}
