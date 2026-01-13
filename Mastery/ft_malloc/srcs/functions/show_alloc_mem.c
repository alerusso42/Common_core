/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:52:32 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/13 17:52:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

static size_t	print_one(t_list *zones, char *name, int *index);

void	show_alloc_mem()
{
	t_alloc	*data;
	size_t	total;
	int		index;

	data = _global_data(false);
	total = 0;
	index = 0;
	total += print_one(data->zone_tiny, "TINY", &index);
	total += print_one(data->zone_small, "SMALL", &index);
	total += print_one(data->zone_large, "LARGE", &index);
	ft_printf("$BTotal : %u bytes\n", total);
}

static size_t	print_one(t_list *zones, char *name, int *index)
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
			ft_printf("\033[%dm$$$C%d\033[0m = ", 31 + area->info, *index);
			ft_printf("%p - %p : %u bytes\n", usr_ptr_start, usr_ptr_end, size);
			area = bytelst_next(area);
			(*index)++;
		}
		zones = zones->next;
	}
	return (total_size);
}
