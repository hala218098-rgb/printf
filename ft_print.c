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
		result = ft_putchar('%');
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		finished;
	int		i;

	i = 0;
	finished = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			finished += ft_format(args, format[i + 1]);
			i++;
		}
		else
		{
			finished += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (finished);
}
#include <stdio.h>

int	main(void)
{
	int				length;
	int				len;
	unsigned long	p;
	void			*xp;

	length = 0;
	len = 0;
	p = 0;
	xp = (void *)p;
	length = ft_printf("%c %d %i  %s %x %X %% %u %p\n", 'a', -1, -22, "hanieh",
			5000, 1000, 5, xp);
	ft_printf("%d\n", length);
	len = printf("%c %d %i  %s %x %X %% %u %p\n", 'a', -1, -22, "HANIEH", 1000,
			1000, 5, xp);
	printf("%d\n", len);
}