/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:29:25 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/27 12:40:25 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "test.h"

void *malloc_file(size_t size, const char *file)
{
	void	*p;
	int		fd;

	if (size == 0)
		return (NULL);
	fd = open(file, O_RDWR);
	if (fd < 0)
		return (NULL);
	p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	close(fd);
	if (!p || p == (void *)(-1))
		return (NULL);
	VALGRIND_MALLOCLIKE_BLOCK(p, size, 0, 0);
	return (p);
}

void *malloc_virtualfile(size_t size, const char *file)
{
	void	*p;
	int		fd;

	if (size == 0)
		return (NULL);
	fd = open(file, O_RDWR);
	if (fd < 0)
		return (NULL);
	p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	close(fd);
	if (!p || p == (void *)(-1))
		return (NULL);
	VALGRIND_MALLOCLIKE_BLOCK(p, size, 0, 0);
	return (p);
}

void *malloc_tempfile(size_t size)
{
	void	*p;
	int		fd;

	if (size == 0)
		return (NULL);
	fd = open(".temp", O_RDWR | O_CREAT, 0666);
	if (fd < 0)
		return (NULL);
	write(fd, "ciao", 4);
	p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	close(fd);
	unlink(".temp");
	if (!p || p == (void *)(-1))
		return (NULL);
	return (p);
}

void *malloc_anonymous(size_t size)
{
	void	*p;

	if (size == 0)
		return (NULL);
	p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	if (!p || p == (void *)(-1))
		return (NULL);
	return (p);
}
#include "../../all.h"

void *malloc(size_t size)
{
	void		*p;
	t_alloc		*data;

	data = malloc_global_data(false);
	if (!data)
		return (NULL);
	if (size > ALLOC_MAX_SIZE)
		return (PRINT("$Rsize too large$Z\n"), NULL);
	size += sizeof(t_info);
	PRINT("$Goffset$Z: %d; $Gnext addr$Z: %p", data->offset, data->ptr_curr);
	p = mmap(data->ptr_curr, size, PROT_RDWR, MAP_APF, -1, data->offset);
	PRINT("$G;real addr$Z: %p\n", p);
	VALGRIND_MALLOCLIKE_BLOCK(p, size, 0, 0);
	if (p == (void *)-1)
		return (PRINT("$RAllocation failure!$Z\n"), NULL);
	print_extreme(data, p, false);
	data->offset = (size_t)round_page(size, data->pagesize);
	*(t_info *)p = (t_info){data->offset, p - data->ptr_curr};
	data->ptr_curr = p + data->offset;
	data->bytes_alloc += data->offset;
	return (p + sizeof(t_info));
}

void	print_extreme(void *p, t_alloc *dt, bool print)
{
	if (print)
	{
		ft_printf("ptr_max: %p; ptr_min: %p\n", dt->ptr_max, dt->ptr_min);
	}
	if (!p)
		return ;
	if (p < dt->ptr_min)
		dt->ptr_min = p;
	else if (p > dt->ptr_max)
		dt->ptr_max = p;
}
