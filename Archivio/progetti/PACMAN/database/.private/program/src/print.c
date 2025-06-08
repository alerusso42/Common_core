/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:56:36 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/05 14:32:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*itoa_malloc_guard(t_data *data, int struct_i);

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

void	print_hash_table(t_data *data)
{
	char	*pos_string;
	int		struct_i;
	int		lowest_key;
	int		old_key;
	int		i;

	struct_i = 0;
	old_key = -1;
	lowest_key = -1;
	i = 1;
	find_lowest_key(data, &lowest_key, &struct_i);
	while (lowest_key)
	{
		collision_update(data, old_key, lowest_key, &i);
		old_key = lowest_key;
		while (i != lowest_key)
		{
			ft_putendl_fd("", data->hash_fd.p);
			++i;
		}
		pos_string = itoa_malloc_guard(data, struct_i);
		ft_putstr_fd(pos_string, data->hash_fd.p);
		SDL_free(pos_string);
		find_lowest_key(data, &lowest_key, &struct_i);
	}
}

static char	*itoa_malloc_guard(t_data *data, int struct_i)
{
	char	*str;

	str = ft_itoa(data->hash_table[struct_i].pos);
	if (!str)
		error(data, ER_MALLOC);
	return (str);
}
