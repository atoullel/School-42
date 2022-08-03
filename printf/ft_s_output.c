/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <atoullel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:00:08 by atoullel          #+#    #+#             */
/*   Updated: 2021/12/21 15:13:22 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_s_output(char *s)
{
	if (!s)
		return (ft_putstr_len("(null)"));
	else
		return (ft_putstr_len(s));
}
