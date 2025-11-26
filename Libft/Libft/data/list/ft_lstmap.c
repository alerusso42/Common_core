/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:41:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/26 17:04:51 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	if (!lst)
		return (NULL);
	new_lst = lst_new(lst->content);
	if (!new_lst)
		return (NULL);
	while (lst)
	{
		lst_back(&new_lst, lst_new(lst->content));
		lst = lst->next;
		if (del)
			del(lst);
	}
	lst_iter(new_lst, (void (*)(void *))(void *)*f);
	return (new_lst);
}
