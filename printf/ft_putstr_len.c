/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <atoullel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:50:47 by atoullel          #+#    #+#             */
/*   Updated: 2021/12/21 12:50:47 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_putstr_len(char *s)
{
	if (!s)
		return (0);
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}
