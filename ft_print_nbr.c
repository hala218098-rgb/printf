#include "ft_printf.h"
static int  ft_count_digits(long n)
{
    int count;

    count = 0;
    if (n <= 0)
        count++;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return (count);
}
int ft_print_nbr(int n)
{
    long    nb;
    char    c;

    nb = n;
    if (nb < 0)
    {
        write(1, "-", 1);
        nb = -nb;
    }
    if (nb >= 10)
        ft_print_nbr((int)(nb / 10));
    c = '0' + (nb % 10);
    write(1, &c, 1);
    return (ft_count_digits(n));
}

int main(void)
{
    ft_print_nbr(89);
    write(1, "\n", 1);
}