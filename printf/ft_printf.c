/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <atoullel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:50:24 by atoullel          #+#    #+#             */
/*   Updated: 2021/12/21 12:50:24 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

static size_t	flags(char c, va_list ap)
{
	int	printed;

	printed = 0;
	if (c == 'c')
		printed = ft_putchar_len(va_arg(ap, int));
	else if (c == 's')
		printed = ft_s_output(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		printed = ft_putnbr_len(va_arg(ap, int));
	else if (c == 'u')
		printed = ft_putunnbr_len(va_arg(ap, unsigned int));
	else if (c == 'p')
		printed = ft_putpointer(va_arg(ap, void *));
	else if (c == 'X')
		printed = ft_printhex(c, va_arg(ap, unsigned int));
	else if (c == 'x')
		printed = ft_printhex(c, va_arg(ap, unsigned int));
	else if (c == '%')
		printed = ft_putchar_len(c);
	else
		printed = ft_putchar_len(c);
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		total_printed;

	i = 0;
	total_printed = 0;
	va_start(ap, format);
	if (!format)
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
			total_printed += flags(format[++i], ap);
		else
			total_printed += ft_putchar_len(format[i]);
		i++;
	}
	va_end(ap);
	return (total_printed);
}
