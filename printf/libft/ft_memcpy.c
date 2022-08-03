/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:57:12 by atoullel          #+#    #+#             */
/*   Updated: 2021/07/02 16:07:47 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	x;

	x = 0;
	if (n == 0)
		return (dst);
	while (x < n)
	{
		*(unsigned char *)(dst + x) = *(unsigned char *)(src + x);
		x++;
	}
	return (dst);
}
