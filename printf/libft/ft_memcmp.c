/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:54:56 by atoullel          #+#    #+#             */
/*   Updated: 2021/07/07 16:48:54 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *src1, const void *src2, size_t n)
{
	size_t			x;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *) src1;
	s2 = (unsigned char *) src2;
	x = 0;
	if (n == 0 || !(src1 && src2))
		return (0);
	while (s1[x] == s2[x] && (x + 1) < n)
		x++;
	if (s1[x] == s2[x])
		return (0);
	return (s1[x] - s2[x]);
}
