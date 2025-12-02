#include "ft_printf.h"

static int  ft_hex_len(unsigned int n)
{
    int len;

    if (n == 0)
        return (1);
    len = 0;
    while (n != 0)
    {
        n /= 16;
        len++;
    }
    return (len);
}

static void ft_put_hex(unsigned int n, char format)
{
    char *base;

    if (format == 'x')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";
    if (n >= 16)
        ft_put_hex(n / 16, format);
    write(1, &base[n % 16], 1);
}

int ft_print_hex(unsigned int n, char format)
{
    if (n == 0)
    {
        write(1, "0", 1);
        return (1);
    }
    ft_put_hex(n, format);
    return (ft_hex_len(n));
}
