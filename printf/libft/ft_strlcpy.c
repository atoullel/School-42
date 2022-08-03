/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:09:27 by atoullel          #+#    #+#             */
/*   Updated: 2021/07/03 17:48:39 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	x;

	if (!(dst || src))
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	x = 0;
	while ((src[x] != '\0') && (x + 1 < dstsize))
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
	return (ft_strlen(src));
}
