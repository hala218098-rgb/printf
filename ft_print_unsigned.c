#include "ft_printf.h"
static int ft_udigit_count(unsigned int n)
{
    int count;

    count = 0;
    if (n == 0)
        return (1);
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return (count);
}
int ft_print_unsigned(unsigned int n)
{
    char c;

    if (n >= 10)
        ft_print_unsigned(n / 10);
    c = '0' + (n % 10);
    write(1, &c, 1);
    return (ft_udigit_count(n));
}
