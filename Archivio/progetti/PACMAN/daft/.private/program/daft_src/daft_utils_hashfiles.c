/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_utils_hashfiles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:06:24 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/16 19:47:05 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*get_hash_filename(char *filename);
static int	preparations(t_daft_list *file);
static int	alloc_list(t_daft_list *file, int alloc_size);

int	_daft_get_data(t_daft_list *file, char *filename)
{
	char	*hash_filename;

	hash_filename = get_hash_filename(filename);
	if (!hash_filename)
		return (_daft_log(DAFT_LOG_MALLOC));
	file->filedata = openfd(hash_filename, "r");
	if (!file->filedata.n)
		return (_daft_log(DAFT_LOG_OPEN));
	file->filename = filename;
	if (preparations(file) != 0)
		return (closefd(file->filedata), 1);
	if (_daft_get_data2(file) != 0)
		return (closefd(file->filedata), 1);
	return (closefd(file->filedata), 0);
}

static char	*get_hash_filename(char *filename)
{
	int		i;

	i = 0;
	while (filename[i] && ft_strncmp(filename + i, "/daft/.private/", 15))
	{
		++i;
	}
	if (!filename[i])
		return (NULL);
	i += 15;
	return (_cat_string(filename, "hash_", i, 0));
}

static int	preparations(t_daft_list *file)
{
	char		*line;
	int			i;
	long long	alloc_size;

	line = gnl();
	if (!line)
		return (_daft_log(DAFT_LOG_FILESETT));
	alloc_size = ft_atoi(line);
	if (alloc_size == LLONG_MAX || alloc_size <= 0)
		return (SDL_free(line), _daft_log(DAFT_LOG_ALLOCSIZE));
	i = sub_strlen(line, " ", EXCLUDE);
	if (!line[i])
		return (SDL_free(line), _daft_log(DAFT_LOG_MISSFLAGS));
	i += 1;
	if (ft_strlen(line + 1) != 5)
		return (SDL_free(line), _daft_log(DAFT_LOG_MISSFLAGS));
	file->field_sep = line[i];
	file->multiple_lines = (line[i + 1] == 'y');
	file->split_values = (line[i + 2] == 'y');
	file->key_value_sep = line[i + 3];
	file->values_sep = line[i + 4];
	SDL_free(line);
	return (alloc_list(file, alloc_size));
}

static int	alloc_list(t_daft_list *file, int alloc_size)
{
	file->node = ft_calloc(alloc_size + 1, sizeof(t_daft_node));
	if (!file->node)
		return (_daft_log(DAFT_LOG_MALLOC));
	return (0);
}
