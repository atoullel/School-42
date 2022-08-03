/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <atoullel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:50:40 by atoullel          #+#    #+#             */
/*   Updated: 2021/12/21 12:50:40 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_putnbr_len(int n)
{
	unsigned int	nb;
	int				printed;

	printed = 0;
	if (n < 0)
	{
		nb = -n;
		printed = ft_putchar_len('-');
	}
	else
		nb = n;
	if (nb >= 10)
		printed += ft_putnbr_len((nb / 10));
	printed += ft_putchar_len(('0' + (nb % 10)));
	return (printed);
}
