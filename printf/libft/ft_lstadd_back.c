/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:44:29 by atoullel          #+#    #+#             */
/*   Updated: 2021/07/09 17:22:36 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last_elem;

	if (!alst || !new)
		return ;
	if (!(*alst))
		*alst = new;
	else
	{
		last_elem = ft_lstlast(*alst);
		last_elem->next = new;
	}
}
