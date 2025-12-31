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
#include "../../libft.h"

void	print_extreme(long long *p, bool print);

void *malloc(size_t size)
{
	void		*p;
	static long	min;
	static int	offset;

	min = sysconf(_SC_PAGESIZE);
	p = mmap(NULL, size, PROT_READ | PROT_WRITE, \
		MAP_PRIVATE | MAP_ANONYMOUS, 0, offset);
	VALGRIND_MALLOCLIKE_BLOCK(p, size, 0, 0);
	if (p == (void *)-1)
		return (NULL);
	print_extreme(p, false);
	offset = size + (min - size % min);
	return (p);
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
