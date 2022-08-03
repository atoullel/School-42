/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnbr_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <atoullel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:50:52 by atoullel          #+#    #+#             */
/*   Updated: 2021/12/21 12:50:52 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_putunnbr_len(unsigned int nb)
{
	int	printed;

	printed = 0;
	if (nb >= 10)
		printed += ft_putunnbr_len((nb / 10));
	printed += ft_putchar_len(('0' + (nb % 10)));
	return (printed);
}
