/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_to_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:53:33 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/21 15:06:08 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

/*
	Turn on every switch and variable related to bonus.
*/
int	switch_to_bonus(t_settings *settings)
{
	settings->switch_1_bonus = YES;
	return (YES);
}
