/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:35:51 by atoullel          #+#    #+#             */
/*   Updated: 2021/07/03 17:54:10 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		integer;
	size_t	x;
	int		sign;

	if (!str)
		return (0);
	x = 0;
	sign = 1;
	integer = 0;
	while (str[x] == 32 || str[x] == 9 || str[x] == 10 || str[x] == 12
		|| str[x] == 13 || str[x] == 11)
		x++;
	if (str[x] == '-')
		sign = -1;
	if (str[x] == '-' || str[x] == '+')
		x++;
	while (str[x] >= '0' && str[x] <= '9')
	{
		integer = integer * 10 + (str[x] - 48);
		x++;
	}
	return (sign * integer);
}
