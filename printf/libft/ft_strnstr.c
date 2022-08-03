/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:13:46 by atoullel          #+#    #+#             */
/*   Updated: 2021/07/07 15:32:01 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (!(str && needle))
		return (NULL);
	if (!(*needle))
		return ((char *)str);
	while (str[x] && (x + ft_strlen(needle)) <= len)
	{
		y = 0;
		while (str[y + x] == needle[y] && str[y + x])
			y++;
		if (needle[y] == '\0')
			return ((char *)(str + x));
		x++;
	}
	return (NULL);
}
