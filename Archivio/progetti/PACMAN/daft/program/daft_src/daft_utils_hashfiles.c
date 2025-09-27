/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_utils_hashfiles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:06:24 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/27 23:05:08 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "daft_prog.h"

static int	preparations(t_daft_list *file);
static int	alloc_list(t_daft_list *file, int alloc_size);

//	Used to get data for a file.
//	Inner flags for the file are stored in file, named as the file,
//	but stored in another directory: .private/hash_data.
//	.private/hash_data stores the offset in which data must be searched.
int	_daft_get_data(t_daft_list *file, char *filename)
{
	char	*hash_filename;

	hash_filename = _daft_get_hash_filename(filename);
	if (!hash_filename)
		return (_daft_log(DAFT_LOG_MALLOC));
	file->filedata = openfd(hash_filename, "r");
	FREE(hash_filename);
	if (!file->filedata.n)
		return (_daft_log(DAFT_LOG_OPEN));
	file->filename = filename;
	if (preparations(file) != 0)
		return (closefd(file->filedata), 1);
	if (_daft_get_data2(file) != 0)
		return (closefd(file->filedata), 1);
	return (closefd(file->filedata), 0);
}

//	search in the filename data/, then appends .private/hash_ in the tail.
char	*_daft_get_hash_filename(char *filename)
{
	int		i;

	i = 0;
	while (filename[i] && ft_strncmp(filename + i, "daft/data/", 10))
	{
		++i;
	}
	if (!filename[i])
		return (NULL);
	i += 10;
	return (_cat_string(filename, "hash_data/", i, 0));
}

//	Inner flags and the maximum hash value are saved.
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
		return (FREE(line), _daft_log(DAFT_LOG_ALLOCSIZE));
	i = sub_strlen(line, " ", EXCLUDE);
	if (!line[i])
		return (FREE(line), _daft_log(DAFT_LOG_MISSFLAGS));
	i += 1;
	if (ft_strlen(line + i) != 5)
		return (FREE(line), _daft_log(DAFT_LOG_MISSFLAGS));
	file->field_sep[0] = line[i];
	file->multiple_lines = (line[i + 1] == 'y');
	file->split_values = (line[i + 2] == 'y');
	file->key_value_sep[0] = line[i + 3];
	file->values_sep[0] = line[i + 4];
	FREE(line);
	file->size = (int)alloc_size;
	return (alloc_list(file, alloc_size));
}

//	Allocs the file lists array of hash data.
static int	alloc_list(t_daft_list *file, int alloc_size)
{
	file->node = ft_calloc(alloc_size + 1, sizeof(t_daft_node));
	if (!file->node)
		return (_daft_log(DAFT_LOG_MALLOC));
	return (0);
}
