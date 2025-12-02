#include "ft_printf.h"

void	ft_pointer_function(unsigned long long nb)
{
	if (nb >= 16)
	{
		ft_pointer_function(nb / 16);
		ft_pointer_function(nb % 16);
	}
	else
	{
		if (nb < 10)
			ft_putchar(nb % 10 + '0');
		else
			ft_putchar(nb - 10 + 'a');
	}
}

int	ft_pointer(void *ptr)
{
	int					len;
	unsigned long long	nb;

	nb = (unsigned long long)ptr;
	len = 0;
	write(1, "0x", 2);
	ft_pointer_function(nb);
	if (nb == 0)
	{
		len++;
	}
	while (nb > 0)
	{
		nb /= 16;
		len++;
	}
	return (len + 2);
}