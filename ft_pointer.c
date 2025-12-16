/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halakhal <halakhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:55:39 by halakhal          #+#    #+#             */
/*   Updated: 2025/12/10 18:55:42 by halakhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer_function(unsigned long long nb)
{
	int	ret;

	if (nb >= 16)
	{
		ret = ft_pointer_function(nb / 16);
		if (ret == -1)
			return (-1);
		ret = ft_pointer_function(nb % 16);
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

int	ft_pointer(void *ptr)
{
	int					len;
	unsigned long long	nb;
	unsigned long long	temp;

	nb = (unsigned long long)ptr;
	temp = nb;
	len = 0;
	if (write(1, "0x", 2) == -1)
		return (-1);
	if (ft_pointer_function(nb) == -1)
		return (-1);
	if (temp == 0)
		len++;
	while (temp > 0)
	{
		temp /= 16;
		len++;
	}
	return (len + 2);
}
