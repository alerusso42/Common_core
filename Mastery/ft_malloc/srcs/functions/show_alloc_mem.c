/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:52:32 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/26 03:53:47 by alerusso         ###   ########.fr       */
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
	if ((flags & MALL_SHOW_FREED) == 0 && area->info & MEM_FREED)
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
