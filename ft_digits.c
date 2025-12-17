/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halakhal <halakhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:55:30 by halakhal          #+#    #+#             */
/*   Updated: 2025/12/17 15:40:16 by halakhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	ret;

	if (nb == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (11);
	}
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		nb *= -1;
	}
	if (nb > 9)
	{
		ret = ft_putnbr(nb / 10);
		if (ret == -1)
			return (-1);
	}
	if (ft_putchar(nb % 10 + '0') == -1)
		return (-1);
	return (1);
}

int	ft_digit(int nb)
{
	int	i;
	int	temp;

	i = 0;
	temp = nb;
	if (ft_putnbr(nb) == -1)
		return (-1);
	if (temp <= 0)
		i++;
	while (temp)
	{
		temp /= 10;
		i++;
	}
	return (i);
}

int	ft_doubledigits(unsigned int nb)
{
	int	ret;

	if (nb > 9)
	{
		ret = ft_doubledigits(nb / 10);
		if (ret == -1)
			return (-1);
	}
	if (ft_putchar(nb % 10 + '0') == -1)
		return (-1);
	return (1);
}

int	ft_unint(unsigned int nb)
{
	unsigned int	len;
	unsigned int	temp;

	len = 0;
	temp = nb;
	if (ft_doubledigits((unsigned int)nb) == -1)
		return (-1);
	if (temp == 0)
		len++;
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	return (len);
}
