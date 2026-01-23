/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:52:32 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/23 23:21:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/malloc_internal.h"

static size_t	show_zone(t_list *zones, char *name, int *index, uint32_t flags);
static size_t	show_area(t_area *area, int *index, uint32_t flags);
static void		mem_dump(t_area *area, uint32_t flags);

void	show_alloc_mem()
{
	show_alloc_mem_ex(0);
}

/*
-	show_alloc_mem_ex is equal to show_alloc_mem, 
	except the ex version prints the memory bytes.

-	only the following bases are accepted:
	base 2 		(bit representation)
	base 16 	(hex representation)
	base 256 	(byte representation)
	
-	you can pass 1 to see all of them
*/
void	show_alloc_mem_ex(uint32_t flags)
{
	t_alloc	*data;
	size_t	total;
	int		index;

	data = _global_data(false);
	total = 0;
	index = 0;
	total += show_zone(data->zone_tiny, "TINY", &index, flags);
	total += show_zone(data->zone_small, "SMALL", &index, flags);
	total += show_zone(data->zone_large, "LARGE", &index, flags);
	ft_printf("$BTotal : %u bytes\n", total);
}

static size_t	show_zone(t_list *zones, char *name, int *index, uint32_t flags)
{
	size_t	size;
	t_area	*area;

	size = 0;
	while (zones)
	{
		ft_printf("$B%s$Z : %p, BF %d\n", name, zones->content, ((t_memzone *)zones->content)->blocks_freed);
		area = ((void *)(zones->content)) + sizeof(t_memzone);
		size += show_area(area, index, flags);
		zones = zones->next;
	}
	return (size);
}

static size_t	show_area(t_area *area, int *index, uint32_t flags)
{
	t_area		*usr_ptr_start;
	t_area		*usr_ptr_end;
	size_t		size;
	size_t		total_size;

	total_size = 0;
	while (area)
	{
		usr_ptr_start = ((void *)area) + sizeof(t_area);
		usr_ptr_end = ((void *)area) + area->next;
		size = (size_t)area->next - sizeof(t_area);
		total_size += size * (area->info == 0);
		ft_printf("\033[%dm$$$C%d\033[0m = ", 31 + area->info, *index);
		ft_printf("%p - %p : %u bytes ", usr_ptr_start, usr_ptr_end, size);
		mem_dump(area, flags);
		ft_printf("\n");
		area = bytelst_next(area);
		(*index)++;
	}
	return (total_size);
}

static void	mem_dump(t_area *area, uint32_t flags)
{
	if (flags & MALL_SHOW_SILENT_FREED && area->info & MEM_FREED)
		return ;
	flags &= MALL_SHOW_PRINT_BYTE - 1;
	switch (flags)
	{
		case 2:
			return (mem_dump_bit(area));
		case 16:
			return (mem_dump_hex(area));
		case 256:
			return (mem_dump_byte(area));
		case 1:
			ft_printf("?%p%p?\n?%p%p?\n?%p%p?\n", \
			mem_dump_bit, area, mem_dump_hex, area, mem_dump_byte, area);
		default :
			return ;
	}
}

// void	show_alloc_mem(void *ptr)
// {
	
// }

/*
# include "../../includes/malloc_internal.h"

static size_t	print_zones_lst(t_list *zones, char *name, int *index);
static size_t	print_zone_(t_memzone *zone, int *index);
static size_t	print_area_(t_area *area, int *index);

void	show_alloc_mem()
{
	t_alloc	*data;
	size_t	total;
	int		index;

	data = _global_data(false);
	total = 0;
	index = 0;
	total += print_zones_lst(data->zone_tiny, "TINY", &index);
	total += print_zones_lst(data->zone_small, "SMALL", &index);
	total += print_zones_lst(data->zone_large, "LARGE", &index);
	ft_printf("$BTotal : %u bytes\n", total);
}

static size_t	print_zones_lst(t_list *zones, char *name, int *index)
{
	size_t		total_size;
	t_memzone	*zone;

	total_size = 0;
	while (zones)
	{
		zone = zones->content;
		ft_printf("$B%s$Z : %p , lc %d\n", name, zone, zone->longest_chunk);
		total_size += print_zone_(zone, index);
		zones = zones->next;
	}
	return (total_size);
}

static size_t	print_zone_(t_memzone *zone, int *index)
{
	size_t	total_size;
	t_area	*area;

	area = ((void *)zone) + sizeof(t_memzone);
	total_size = 0;
	while (area)
	{
		total_size += print_area_(area, index);
		area = bytelst_next(area);
		(*index)++;
	}
	return (total_size);
}

static size_t	print_area_(t_area *area, int *index)
{
	size_t		size;
	t_area		*usr_ptr_start;
	t_area		*usr_ptr_end;

	usr_ptr_start = ((void *)area) + sizeof(t_area);
	usr_ptr_end = ((void *)area) + area->next;
	size = (size_t)area->next - sizeof(t_area);
	ft_printf("\033[%dm$$$C%d\033[0m = ", 31 + area->info, *index);
	ft_printf("%p - %p : %u bytes\n", usr_ptr_start, usr_ptr_end, size);
	if (area->info |= MEM_FREED)
		return (0);
	return (size);
}
*/
