/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halakhal <halakhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:40:30 by halakhal          #+#    #+#             */
/*   Updated: 2025/12/17 16:46:41 by halakhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char format)
{
	int	result;

	result = 0;
	if (format == 'c')
		result = ft_putchar(va_arg(args, int));
	else if (format == '%')
		result = ft_putchar('%');
	else if (format == 's')
		result = ft_str(va_arg(args, char *));
	else if (format == 'i' || format == 'd')
		result = ft_digit(va_arg(args, int));
	else if (format == 'u')
		result = ft_unint(va_arg(args, unsigned int));
	else if (format == 'p')
		result = ft_pointer(va_arg(args, void *));
	else if (format == 'x')
		result = ft_hexa_x(va_arg(args, unsigned int));
	else if (format == 'X')
		result = ft_hexa_bx(va_arg(args, unsigned int));
	else
		result = ft_putchar(format);
	if (result == -1)
		return (-1);
	return (result);
}

static int	ft_process(const char *format, va_list args)
{
	int	i;
	int	finished;
	int	tmp;

	i = 0;
	finished = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			tmp = ft_format(args, format[i + 1]);
		else
			tmp = ft_putchar(format[i]);
		if (tmp == -1)
			return (-1);
		finished += tmp;
		if (format[i] == '%' && format[i + 1])
			i++;
		i++;
	}
	return (finished);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		finished;

	if (!format)
		return (-1);
	va_start(args, format);
	finished = ft_process(format, args);
	va_end(args);
	return (finished);
}
