/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <atoullel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:49:21 by atoullel          #+#    #+#             */
/*   Updated: 2021/12/21 19:11:01 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_printhex(char c, unsigned int x)
{
	char	*tmp;
	int		printed;

	printed = 0;
	tmp = ft_itoh(x);
	if (c == 'X')
		printed = ft_putstr_len(ft_str_toupper(tmp));
	else
		printed = ft_putstr_len(tmp);
	free(tmp);
	return (printed);
}
