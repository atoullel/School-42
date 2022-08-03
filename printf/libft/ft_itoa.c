/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:40:41 by atoullel          #+#    #+#             */
/*   Updated: 2021/06/14 16:25:31 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	length(long nbr, size_t *len, int *magnitude)
{
	*len = 1;
	*magnitude = 1;
	if (nbr < 0)
	{
		*len = 2;
		nbr = -nbr;
	}
	while (nbr / *magnitude > 9)
	{
		*magnitude *= 10;
		*len += 1;
	}
}

char	*ft_itoa(int n)
{
	size_t	len;
	int		magnitude;
	size_t	i;
	char	*str;
	long	nbr;

	i = 0;
	nbr = n;
	length(nbr, &len, &magnitude);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	if (nbr < 0)
	{
		str[i++] = '-';
		nbr = -nbr;
	}
	while (magnitude >= 1)
	{
		str[i++] = ((nbr / magnitude) % 10) + 48;
		magnitude /= 10;
	}
	str[i] = '\0';
	return (str);
}
