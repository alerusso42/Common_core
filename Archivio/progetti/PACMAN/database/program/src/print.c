/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:56:36 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/05 01:51:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_filedata(t_data *data)
{
	char	*filename;
	char	*file_size;
	char	*enum_num;

	switch_filedata(data->hash_fd);
	get_filedata(NULL, &filename);
	file_size = ft_itoa(data->hash_size);
	if (!file_size)
		error(data, ER_MALLOC);
	enum_num = ft_itoa(data->file_num);
	if (!enum_num)
		return (SDL_free(file_size), error(data, ER_MALLOC));
	ft_putstr_fd("///", data->hash_fd.p);
	ft_putstr_fd(enum_num, data->hash_fd.p);
	ft_putstr_fd("///", data->hash_fd.p);
	ft_putstr_fd(filename, data->hash_fd.p);
	ft_putstr_fd("///", data->hash_fd.p);
	ft_putstr_fd(file_size, data->hash_fd.p);
	ft_putstr_fd("///", data->hash_fd.p);
	ft_putendl_fd(data->flags, data->hash_fd.p);
	SDL_free(enum_num);
	SDL_free(file_size);
	switch_filedata(data->data_fd);
}

int		collision_update(t_data *data, int lowest_key, int curr, int last);
int		collision_check(t_data *data, int lowest_key, int curr, int last);
void	collision_clear(t_data *data);

void	print_hash_table(t_data *data)
{
	char	*pos_string;
	int		struct_i;
	int		lowest_key;
	int		i;

	struct_i = 0;
	lowest_key = -1;
	i = 0;
	find_lowest_key(data, &lowest_key, &struct_i);
	while (lowest_key)
	{
		if (++i == struct_i)
			ft_putstr_fd(",", data->hash_fd.p);
		while (i != lowest_key)
		{
			ft_putendl_fd("", data->hash_fd.p);
			++i;
		}
		pos_string = ft_itoa(data->hash_table[struct_i].pos);
		if (!pos_string)
			error(data, ER_MALLOC);
		ft_putendl_fd(pos_string, data->hash_fd.p);
		SDL_free(pos_string);
		find_lowest_key(data, &lowest_key, &struct_i);
	}
}
