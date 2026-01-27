/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:11:25 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/27 12:40:25 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

void	print_zone(t_memzone *zone)
{
	t_area	*area;
	int		i;

	if (DEBUG_FLAG == false)
		return ;
	DEBUG("$Mprint zone %p:\n$Z", zone);
	ft_printf("$Z{$Ysize$Z = %d}{$Glc$Z = %d}{$Bbf = %d$Z}\n", \
	zone->size, zone->longest_chunk, zone->blocks_freed);
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

void	print_list(t_list *lst)
{
	int	EYE = 0;

	while (lst)
	{
		ft_printf("%p - ", lst);
		lst = lst->next;
		++EYE;
	}
	ft_printf("\b\b\b   \n$GSIZE$Z: %d\n", EYE);
}

//prints an error and returns NULL
void	*error_malloc(char *s)
{
	err_printf("$RMalloc$Z:$R %s$Z\n", s);
	return (NULL);
}

//prints an error, returns NULL, turn down malloc system
void	*fatal_malloc(char *s)
{
	t_alloc	*data;

	data = malloc_global_data();
	err_printf("Malloc, fatal: %s\n", s);
	malloc_munmap_data();
	data->error = true;
	return (NULL);
}
