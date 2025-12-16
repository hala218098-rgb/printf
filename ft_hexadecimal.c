/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halakhal <halakhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:55:35 by halakhal          #+#    #+#             */
/*   Updated: 2025/12/10 18:55:36 by halakhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int	ft_hexagonal_l(unsigned int nb)
{
	int	ret;

	if (nb >= 16)
	{
		ret = ft_hexagonal_l(nb / 16);
		if (ret == -1)
			return (-1);
		ret = ft_hexagonal_l(nb % 16);
		if (ret == -1)
			return (-1);
	}
	else
	{
		if (nb < 10)
			ret = ft_putchar(nb % 10 + '0');
		else
			ret = ft_putchar(nb - 10 + 'a');
		if (ret == -1)
			return (-1);
	}
	return (1);
}

int	ft_hexa_x(unsigned int nb)
{
	unsigned int	len;
	unsigned int	temp;

	len = 0;
	temp = nb;
	if (ft_hexagonal_l((unsigned int)nb) == -1)
		return (-1);
	if (temp == 0)
		len++;
	while (temp > 0)
	{
		temp /= 16;
		len++;
	}
	return (len);
}

int	ft_hexagonal_u(unsigned int nb)
{
	int	ret;

	if (nb >= 16)
	{
		ret = ft_hexagonal_u(nb / 16);
		if (ret == -1)
			return (-1);
		ret = ft_hexagonal_u(nb % 16);
		if (ret == -1)
			return (-1);
	}
	else
	{
		if (nb < 10)
			ret = ft_putchar(nb % 10 + '0');
		else
			ret = ft_putchar(nb - 10 + 'A');
		if (ret == -1)
			return (-1);
	}
	return (1);
}

int	ft_hexa_bx(unsigned int nb)
{
	unsigned int	len;
	unsigned int	temp;

	len = 0;
	temp = nb;
	if (ft_hexagonal_u((unsigned int)nb) == -1)
		return (-1);
	if (temp == 0)
		len++;
	while (temp > 0)
	{
		temp /= 16;
		len++;
	}
	return (len);
}
