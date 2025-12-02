
#include "ft_printf.h"

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar(nb % 10 + '0');
}

int	ft_digit(int nb)
{
	int	i;

	i = 0;
	ft_putnbr(nb);
	if (nb <= 0)
		i++;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void	ft_doubledigits(unsigned int nb)
{
	if (nb > 9)
		ft_doubledigits(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int	ft_unint(unsigned int nb)
{
	unsigned int	len;

	len = 0;
	ft_doubledigits((unsigned int )nb);
	if (nb == 0)
		len++;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
