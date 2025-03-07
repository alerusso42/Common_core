/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dont_switch_to_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:31:42 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/04 16:43:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

void	switch_to_bonus(t_settings *settings, t_stack *a)
{
	settings->switch_5_bonus = OFF;
	(void)a;
}
