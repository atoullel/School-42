/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:03:21 by atoullel          #+#    #+#             */
/*   Updated: 2021/07/03 12:24:51 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	x;

	x = 0;
	if (!s)
		return (NULL);
	while (s[x] != c && s[x])
		x++;
	if (s[x] == c)
		return ((char *)s + x);
	return (NULL);
}
