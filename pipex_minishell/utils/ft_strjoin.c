/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:43:03 by atoullel          #+#    #+#             */
/*   Updated: 2021/07/03 16:54:05 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	x;
	char	*str;

	if (!(s1 && s2))
		return (NULL);
	x = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (x + 1));
	if (str == NULL)
		return (NULL);
	x = 0;
	while (*s1)
		str[x++] = *s1++;
	while (*s2)
		str[x++] = *s2++;
	str[x] = '\0';
	return (str);
}
