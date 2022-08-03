/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:59:16 by atoullel          #+#    #+#             */
/*   Updated: 2021/06/14 16:35:59 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (n == 0 || !(dst && src))
		return (dst);
	if (src < dst)
	{
		while (n--)
			*(char *)(dst + n) = *(char *)(src + n);
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
