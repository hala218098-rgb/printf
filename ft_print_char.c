#include "ft_printf.h"

int ft_print_char(char c)
{
    write(1, &c, 1);
    return (1);
}
static int ft_strlen(const char *s)
{
    int i = 0;

    if (!s)
        return (0);
    while (s[i])
        i++;
    return (i);
}

int ft_print_str(char *s)
{
    int len;

    if (!s)
    {
        write(1, "(null)", 6);
        return (6);
    }
    len = ft_strlen(s);
    write(1, s, len);
    return (len);
}
