/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoullel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 16:48:53 by atoullel          #+#    #+#             */
/*   Updated: 2021/07/09 17:25:05 by atoullel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*n_elem;

	if (!lst || !f || !del)
		return (NULL);
	n_lst = ft_lstnew(f(lst->content));
	if (n_lst == NULL)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		n_elem = ft_lstnew(f(lst->content));
		if (n_elem == NULL)
		{
			ft_lstclear(&n_lst, del);
			break ;
		}
		ft_lstadd_back(&n_lst, n_elem);
		lst = lst->next;
	}
	return (n_lst);
}
