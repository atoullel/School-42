/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <atoullel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:50:44 by atoullel          #+#    #+#             */
/*   Updated: 2021/12/21 12:50:44 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_putpointer(void *p)
{
	int			printed;
	char		*p_start;
	char		*tmp;

	tmp = NULL;
	p_start = "0x";
	printed = 0;
	if (!p)
		printed = ft_putstr_len(PTR_NULL);
	else
	{
		tmp = ft_itoh((uintptr_t)p);
		printed = ft_putstr_len(p_start);
		printed += ft_putstr_len(tmp);
		free(tmp);
	}
	return (printed);
}
