/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_utils_get2Dmatr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:11:28 by codespace         #+#    #+#             */
/*   Updated: 2025/06/17 16:18:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*trim_first_line(void);

void	*_daft_get_vertical_matr(t_daft_data *data, t_daft_list *file)
{
	int		size;
	char	**matr;
	char	*line;
	int		i;

	size = 0;
	matr = ft_calloc(size, sizeof(char *));
	if (!matr)
		return (NULL);
	i = 0;
	line = trim_first_line();
	while (line && ft_strchr(line, file->field_sep[0]))
	{
		if (size == i)
			if (_daft_resize_matr(&matr, &size) != 0)
				return (SDL_free(line), NULL);
		matr[i] = ft_strdup(line + sub_strlen(line, file->field_sep, EXCLUDE));
		SDL_free(line);
		if (!matr[i++])
			return (free_matrix(matr));
		line = gnl();
	}
	SDL_free(line);
	data->mem.ptr = matr;
	return (matr);
}

void	*_daft_get_horizontal_matr(t_daft_data *data, t_daft_list *file)
{
	int		size;
	char	**matr;
	char	*line;
	int		i;
	int		j;

	size = 0;
	matr = ft_calloc(size, sizeof(char *));
	if (!matr)
		return (NULL);
	i = 0;
	line = gnl();
	j = 0;
	while (line && line[j])
	{
		if (size == i)
			if (_daft_resize_matr(&matr, &size) != 0)
				return (SDL_free(line), NULL);
		matr[i] = ft_substr(line, j, end_item(line + j, file->field_sep, EXCLUDE));
		
	}
	SDL_free(line);
	data->mem.ptr = matr;
}

static char	*trim_first_line(void)
{
	char	*line;

	line = gnl();
	SDL_free(line);
	return (gnl());
}
