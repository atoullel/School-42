/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:01:33 by atoullel          #+#    #+#             */
/*   Updated: 2021/06/14 16:36:24 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t length)
{
	unsigned char	*dest;
	size_t			x;
	unsigned char	a;

	dest = (unsigned char *) s;
	x = 0;
	a = c;
	while (x < length)
	{
		dest[x] = a;
		x++;
	}
	return (s);
}
