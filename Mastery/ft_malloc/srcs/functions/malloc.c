/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:29:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/12/29 17:29:25 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/ft_malloc.h"

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

void	print_extreme(long long *p, bool print);

void *malloc(size_t size)
{
	void		*p;
	t_alloc		*data;

	data = _global_data(false);
	if (!data)
		return (NULL);
	if (size > ALLOC_MAX_SIZE)
		return (PRINT("size too large\n"), NULL);
	size += sizeof(t_info);
	PRINT("offset: %d; next addr: %d", data->offset, data->ptr_curr);
	p = mmap((void *)data->ptr_curr, size, PROT_RDWR, MAP_APF, -1, data->offset);
	PRINT(";real addr: %d\n", (long long)p);
	VALGRIND_MALLOCLIKE_BLOCK(p, size, 0, 0);
	if (p == (void *)-1)
		return (PRINT("failure!\n"), NULL);
	print_extreme(p, false);
	data->offset = round_page(size, data->pagesize);
	*(t_info *)data->ptr_curr = (t_info){size, (uintptr_t)p - data->ptr_curr};
	return (p + sizeof(t_info));
}

void	print_extreme(long long *p, bool print)
{
	static long long	*lowest = (long long *)((1UL << 63) - 1);
	static long long	*biggest = (long long *)0;

	if (print)
	{
		ft_printf(1, "Biggest: %d; Lowest: %d\n", biggest, lowest);
	}
	if (!p)
		return ;
	if (p < lowest)
		lowest = p;
	else if (p > biggest)
		biggest = p;
}
