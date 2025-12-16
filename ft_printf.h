/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halakhal <halakhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:55:49 by halakhal          #+#    #+#             */
/*   Updated: 2025/12/16 20:55:30 by halakhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_putchar(int c);
int		ft_pointer_function(unsigned long long nb);
int		ft_doubledigits(unsigned int nb);
int		ft_putnbr(int nb);
int		ft_digit(int nb);
int		ft_unint(unsigned int nb);
int		ft_hexa_x(unsigned int nb);
int		ft_hexagonal_l(unsigned int nb);
int		ft_hexagonal_u(unsigned int nb);
int		ft_hexa_bx(unsigned int nb);
int		ft_pointer(void *ptr);
int		ft_str(char *str);
int		ft_printf(const char *format, ...);
#endif
