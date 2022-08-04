/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:12:39 by atoullel          #+#    #+#             */
/*   Updated: 2021/07/07 17:27:52 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			x;
	unsigned char	*str1;
	unsigned char	*str2;

	x = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!(s1 && s2))
		return (0);
	if (n == 0)
		return (0);
	while (str1[x] == str2[x] && str1[x] && str2[x] && (x + 1) < n)
		x++;
	return (str1[x] - str2[x]);
}
