/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 14:53:59 by atoullel          #+#    #+#             */
/*   Updated: 2021/07/02 16:29:00 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
		int c, size_t n)
{
	size_t	x;

	x = 0;
	if (n == 0)
		return (NULL);
	while (x < n)
	{
		*(unsigned char *)(dst + x) = *(unsigned char *)(src + x);
		if (*(unsigned char *)(src + x) == (unsigned char)c)
			return (dst + ++x);
		x++;
	}
	return (NULL);
}
