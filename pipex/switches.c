/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switches.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:59:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/26 14:40:02 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

static void	update_var(t_settings *settings);
static void	others(t_settings *settings);

/*
	Useful to understand whether we are in bonus or not.

	In pipex bonus we'll compile switch_to_bonus.c;
	else we compile dont_switch_to_bonus.c
*/
int	switches(t_settings *settings)
{
	*settings = (t_settings){0};
	settings->switch_1_bonus = switch_to_bonus(settings);
	others(settings);
	update_var(settings);
	return (0);
}

static void	update_var(t_settings *settings)
{
	(void)settings;
}

static void	others(t_settings *settings)
{
	(void)settings;
}
