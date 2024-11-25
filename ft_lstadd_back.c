/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:40:12 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 14:11:17 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <malloc.h>
#include "libft.h"
#define UN_BOTTO 100

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pointer;

	pointer = (*lst);
	while (pointer->next)
	{
		pointer = pointer->next;
	}
	pointer->next = new;
}
