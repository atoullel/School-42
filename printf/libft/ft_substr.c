/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:42:13 by atoullel          #+#    #+#             */
/*   Updated: 2021/07/03 17:49:16 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	y;
	char	*substr;

	y = 0;
	if (!(s))
		return (NULL);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	if (ft_strlen(s) > start)
	{
		while (s[start] && y < len)
			substr[y++] = s[start++];
	}
	substr[y] = '\0';
	return (substr);
}
