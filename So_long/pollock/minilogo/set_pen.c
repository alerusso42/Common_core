/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:39:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/13 17:52:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilogo.h"

void	penup(t_turtle *turtle)
{
	turtle->penup = ON;
}

void	pendown(t_turtle *turtle)
{
	turtle->penup = OFF;
}

void	pensize(int new_pensize, t_turtle *turtle)
{
	if (new_pensize < 0)
		return ;
	turtle->pensize = new_pensize;
}