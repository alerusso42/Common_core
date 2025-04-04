/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switches.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:05:53 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/07 09:13:08 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

static void	apply_switches(t_settings *settings, t_stack *a);

void	switches(t_settings *settings, t_stack *a)
{
	settings->switch_1_showbinary = ON;
	settings->switch_2_indexation = ON;
	settings->switch_3_doctorstrange = OFF;
	settings->switch_4_choose_beststart_in_insertion = ON;
	settings->switch_5_save_result = ON;
	apply_switches(settings, a);
}

static void	apply_switches(t_settings *settings, t_stack *a)
{
	if (settings->switch_1_showbinary == ON)
		a->switch_1_showbinary = ON;
	if (settings->switch_2_indexation == ON)
		a->switch_2_indexation = ON;
	if (settings->switch_4_choose_beststart_in_insertion == ON)
		a->switch_4_choose_beststart_in_insertion = ON;
	switch_to_bonus(settings, a);
}
