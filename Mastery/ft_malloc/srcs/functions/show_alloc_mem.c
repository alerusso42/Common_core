/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:52:32 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/12 20:13:13 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

static size_t	print_one(t_list *zones, char *name);

void	show_alloc_mem()
{
	t_alloc	*data;
	size_t	total;

	data = _global_data(false);
	total = 0;
	total += print_one(data->zone_tiny, "TINY");
	total += print_one(data->zone_small, "SMALL");
	total += print_one(data->zone_large, "LARGE");
	ft_printf("$BTotal : %u bytes\n", total);
}

static size_t	print_one(t_list *zones, char *name)
{
	t_area		*area;
	t_area		*usr_ptr_start;
	t_area		*usr_ptr_end;
	size_t		size;
	size_t		total_size;

	total_size = 0;
	while (zones)
	{
		ft_printf("$B%s$Z : %p\n", name, zones->content);
		area = ((void *)(zones->content)) + sizeof(t_memzone);
		while (area)
		{
			usr_ptr_start = ((void *)area) + sizeof(t_area);
			usr_ptr_end = ((void *)area) + area->next;
			size = (size_t)area->next - sizeof(t_area);
			total_size += size;
			ft_printf("%p - %p : %u bytes\n", usr_ptr_start, usr_ptr_end, size);
			area = bytelst_next(area);
		}
		zones = zones->next;
	}
	return (total_size);
}
