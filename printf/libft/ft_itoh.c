/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <atoullel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:32:48 by atoullel          #+#    #+#             */
/*   Updated: 2021/12/21 12:32:48 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*output_zero(char *result)
{
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

char	*ft_itoh(uintptr_t nb)
{
	uintptr_t	quotient;
	uintptr_t	temp;
	char		*result;
	int			x;

	x = 0;
	quotient = nb;
	temp = 0;
	result = (char *)malloc(sizeof(char) * 100);
	if (!result)
		return (NULL);
	if (nb == 0)
		return (output_zero(result));
	while (quotient != 0)
	{
		temp = quotient % 16;
		if (temp >= 10)
			result[x++] = temp + 87;
		else
			result[x++] = temp + 48;
		quotient = quotient / 16;
	}
	result[x] = '\0';
	return (ft_str_reverse(result));
}
