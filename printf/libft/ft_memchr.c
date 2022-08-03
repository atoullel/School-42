/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:51:24 by atoullel          #+#    #+#             */
/*   Updated: 2021/07/02 18:04:12 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			x;

	x = 0;
	if (n == 0 || !s)
		return (NULL);
	while (*(unsigned char *)(s + x) != (unsigned char)c && (x + 1) < n)
		x++;
	if (*(unsigned char *)(s + x) == (unsigned char)c)
		return ((void *)(s + x));
	return (NULL);
}
