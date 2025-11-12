/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:40:12 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/12 19:46:38 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#define UN_BOTTO 100

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pointer;

	if ((lst) && (*lst))
	{
		pointer = ft_lstlast(*lst);
		pointer->next = new;
	}
	else
		*lst = new;
}
