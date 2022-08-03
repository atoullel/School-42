/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:07:30 by atoullel          #+#    #+#             */
/*   Updated: 2021/07/03 17:47:19 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	y;
	size_t	x;
	size_t	z;

	if (!(dest && src))
		return (0);
	x = ft_strlen(dest);
	y = 0;
	z = x;
	while ((src[y] != '\0') && (z + y + 1 < size))
	{
		dest[x] = src[y];
		x++;
		y++;
	}
	dest[x] = '\0';
	if (size >= z)
		return (z + ft_strlen(src));
	else
		return (size + ft_strlen(src));
}
