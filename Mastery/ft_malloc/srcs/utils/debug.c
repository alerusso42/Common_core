/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:11:25 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/12 12:54:08 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

void	print_zone(t_memzone *zone)
{
	t_area	*area;
	int		i;

	if (DEBUG_FLAG == false)
		return ;
	DEBUG("$Mprint zone %p area list:\n$Z", zone);
	i = 0;
	area = ((void *)zone) + sizeof(t_memzone);
	while (area)
	{
		ft_printf("$C$$%d$Z = ", i);
		print_area(area);
		i += 1;
		area = bytelst_next(area);
	}
}

void	print_area(t_area *area)
{
	if (DEBUG_FLAG == false)
		return ;
	ft_printf("{$Yprev$Z = %d}{$Gnext$Z = %d}{$Binfo$Z = %d}\
	$U$Baddr$Z: $Z%p\n", area->prev, area->next, area->info, area);
}
