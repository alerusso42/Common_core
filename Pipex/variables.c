/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:59:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/21 15:05:32 by alerusso         ###   ########.fr       */
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
	Variables to make the program more flexible.
*/
int	variables(t_settings *settings)
{
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
