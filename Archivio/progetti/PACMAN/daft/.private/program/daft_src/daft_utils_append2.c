/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_utils_append2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:31:20 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/23 19:47:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "daft_prog.h"

static void	str_handler(t_daft_data *dt, int i, char **line, char *mem);
static void	mtr_h_handler(t_daft_data *dt, int i, char **line, char **mem);
static void	mtr_v_handler(t_daft_data *dt, int i, char **line, char **mem);
static void	mtr_3d_handler(t_daft_data *dt, int i, char **line, char ***mem);

void	_daft_append_f(t_daft_data *dt, int i, char **line, t_daft_mem *mem)
{
	switch (_daft_find_data_type(dt->data_list[i]))
	{
		case (STRING) :
		{
			fd_printf(dt->temp_files[1], "%s", mem->key);
			str_handler(dt, i, line, (char *)mem->ptr);
			break ;
		}
		case (TWO_D_MATRIX) :
		{
			fd_printf(dt->temp_files[1], "%s", mem->key);
			mtr_h_handler(dt, i, line, (char **)mem->ptr);
			break ;
		}
		case (TWO_D_MATRIX_VERTICAL) :
		{
			fd_printf(dt->temp_files[1], "%s\n", mem->key);
			mtr_v_handler(dt, i, line, (char **)mem->ptr);
			break ;
		}
		case (THREE_D_MATRIX) :
		{
			fd_printf(dt->temp_files[1], "%s\n", mem->key);
			mtr_3d_handler(dt, i, line, (char ***)mem->ptr);
		}
	}
	_daft_free_mem(dt, dt->mem.add);
}

static void	str_handler(t_daft_data *dt, int i, char **line, char *mem)
{
	if (**line == '#')
		(void)fd_printf(dt->temp_files[1], "%s\n", *line);
	if (**line == '#' || !ft_strchr(*line, *dt->data_list[i]->key_value_sep))
	{
		FREE(*line);
		*line = gnl();
		return ;
	}
	fd_printf(dt->temp_files[1], "%s\n", mem);
	FREE(*line);
	*line = gnl();
}

static void	mtr_h_handler(t_daft_data *dt, int i, char **line, char **mem)
{
	int		j;

	if (**line == '#')
		(void)fd_printf(dt->temp_files[1], "%s\n", *line);
	if (**line == '#' || !ft_strchr(*line, *dt->data_list[i]->key_value_sep))
	{
		FREE(*line);
		*line = gnl();
		return ;
	}
	j = 0;
	while (mem[j])
	{
		fd_printf(dt->temp_files[1], "%s", mem[j]);
		++j;
		if (mem[j] && mem[j][0])
			fd_printf(dt->temp_files[1], "%c", *dt->data_list[i]->values_sep);
	}
	fd_printf(dt->temp_files[1], "\n");
	FREE(*line);
	*line = gnl();
}

static void	mtr_v_handler(t_daft_data *dt, int i, char **line, char **mem)
{
	int	j;
	int	len;

	FREE(*line);
	*line = gnl();
	j = 0;
	while (mem[j] && mem[j][0] && !ft_strchr(*line, *dt->data_list[i]->field_sep))
	{
		len = sub_strlen(*line, dt->data_list[i]->key_value_sep, EXCLUDE);
		if ((*line)[len])
			(*line)[len + 1] = 0;
		if (**line && **line != '#')
			fd_printf(dt->temp_files[1], *line);
		str_handler(dt, i, line, mem[j]);
		++j;
	}
}

static void	mtr_3d_handler(t_daft_data *dt, int i, char **line, char ***mem)
{
	int	j;
	int	len;

	FREE(*line);
	*line = gnl();
	j = 0;
	while (mem[j] && !ft_strchr(*line, *dt->data_list[i]->field_sep))
	{
		len = sub_strlen(*line, dt->data_list[i]->key_value_sep, EXCLUDE);
		if ((*line)[len])
			(*line)[len + 1] = 0;
		if (**line && **line != '#')
			fd_printf(dt->temp_files[1], *line);
		mtr_h_handler(dt, i, line, mem[j]);
		++j;
	}
}
