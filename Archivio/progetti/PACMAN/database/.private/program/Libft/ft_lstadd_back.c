/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:40:12 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/17 21:21:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define UN_BOTTO 100

void	ft_lstadd_back(t_typelist **lst, t_typelist *new)
{
	t_typelist	*pointer;

	if ((lst) && (*lst))
	{
		pointer = ft_lstlast(*lst);
		pointer->next = new;
	}
	else
		*lst = new;
}
