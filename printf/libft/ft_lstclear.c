/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:47:50 by atoullel          #+#    #+#             */
/*   Updated: 2021/07/09 17:23:38 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*next;

	if (lst && *lst && del)
	{
		tmp = *lst;
		next = tmp->next;
		while (tmp)
		{
			ft_lstdelone(tmp, del);
			if (!next)
				break ;
			tmp = next;
			next = next->next;
		}
		*lst = NULL;
	}
}
