/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <atoullel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:38:56 by atoullel          #+#    #+#             */
/*   Updated: 2021/12/21 12:38:56 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_reverse(char *str)
{
	size_t	x;
	size_t	y;
	size_t	z;
	char	tmp;

	if (ft_strlen(str) <= 1)
		return (str);
	tmp = ' ';
	x = 0;
	y = ft_strlen(str) - 1;
	z = y / 2;
	while (x <= z)
	{
		tmp = str[x];
		str[x++] = str[y];
		str[y--] = tmp;
	}
	return (str);
}
