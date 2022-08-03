/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:05:11 by atoullel          #+#    #+#             */
/*   Updated: 2021/07/02 17:26:35 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		l;
	int		x;
	char	*str;

	if (!src)
		return (NULL);
	x = 0;
	l = ft_strlen(src);
	str = (char *) malloc(sizeof(char) * (l + 1));
	if (str == NULL)
		return (NULL);
	while (src[x])
	{
		str[x] = src[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}
