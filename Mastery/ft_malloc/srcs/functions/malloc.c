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
	p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
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
	p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
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
