/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:16:49 by atoullel          #+#    #+#             */
/*   Updated: 2021/07/03 13:12:42 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	x;

	if (!s)
		return (NULL);
	x = ft_strlen(s);
	while (s[x] != c && x > 0)
		x--;
	if (s[x] == c)
		return ((char *)s + x);
	return (NULL);
}
