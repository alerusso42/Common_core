/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:11:25 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/12 19:46:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

void	print_zone(t_memzone *zone)
{
	t_area	*area;
	int		i;

	return ;
	if (DEBUG_FLAG == false)
		return ;
	DEBUG("$Mprint zone %p:\n$Z", zone);
	ft_printf("$C$$%d: $Z{$Ysize$Z = %d}{$Glc$Z = %d}{$Bsl$Z = %d}\n", \
	zone->index, zone->size, zone->longest_chunk, zone->free_space);
	ft_printf("$Marea list:\n$Z", zone);
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
