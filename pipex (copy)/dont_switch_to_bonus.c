/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dont_switch_to_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:18:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/21 15:03:30 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

/*
	Turn off every switch and variable related to bonus.
*/
int	switch_to_bonus(t_settings *settings)
{
	settings->switch_1_bonus = NO;
	return (NO);
}
