/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_wildcards2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:11:14 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/14 20:08:48 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	search_len(int *start_len, char *start, int *end_len, char *end);
static int	fill_matrix(char *dir_path, char **matrix, char *to_save);

int	dir_check(char *to_save, char *dir_path, \
	char *start_with, char *end_with)
{
	DIR				*dir;
	struct dirent	*file;
	int				i;
	int				start_len;
	int				end_len;

	dir = opendir(dir_path);
	if (!dir)
		return (E_OPEN);
	i = 0;
	search_len(&start_len, start_with, &end_len, end_with);
	file = readdir(dir);
	while (file)
	{
		if ((!start_with || !ft_strncmp(start_with, file->d_name, start_len))\
		 && (!end_with || !_reverse_strncmp(end_with, file->d_name, end_len)))
			to_save[i++] = _YES;
		else
			to_save[i++] = _NO;
		file = readdir(dir);
	}
	return (closedir(dir), 0);
}

static void	search_len(int *start_len, char *start, int *end_len, char *end)
{
	if (start)
		*start_len = ft_strlen(start);
	else
		*start_len = 0;
	if (end)
		*end_len = ft_strlen(end);
	else
		*end_len = 0;
}

char	*fill_occurrences(char *to_save, char *dir_path, \
	char *old_str)
{
	char	**matrix;
	char	*new_str;
	int		matrix_len;

	matrix_len = 0;
	while (to_save[matrix_len] != _STOP)
		++matrix_len;
	if (!matrix_len)
		return (ft_strdup(old_str));
	matrix = ft_calloc(matrix_len + 1, sizeof(char *));
	if (!matrix)
		return (NULL);
	if (fill_matrix(dir_path, matrix, to_save))
		return (_free_matrix(matrix), NULL);
	new_str = _reverse_split(matrix, ' ');
	if (!new_str)
		return (_free_matrix(matrix), NULL);
	return (_free_matrix(matrix), new_str);
}

static int	fill_matrix(char *dir_path, char **matrix, char *to_save)
{
	DIR				*dir;
	int				i;
	struct dirent	*file;

	dir = opendir(dir_path);
	if (!dir)
		return (E_OPEN);
	i = 0;
	file = readdir(dir);
	while (file)
	{
		if (to_save[i])
		{
			matrix[i] = ft_strdup(file->d_name);
			if (!matrix[i])
				return (E_MALLOC);
			++i;
		}
		file = readdir(dir);
	}
	closedir(dir);
	return (0);
}
