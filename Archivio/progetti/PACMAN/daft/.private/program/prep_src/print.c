/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 21:56:36 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/26 20:51:26 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*itoa_malloc_guard(t_data *data, int struct_i);

void	print_filedata(t_data *data)
{
	char	*file_size;

	switch_filedata(data->hash_fd);
	file_size = ft_itoa(data->hash_size);
	if (!file_size)
		error(data, ER_MALLOC);
	ft_putstr_fd(file_size, data->hash_fd.p);
	ft_putstr_fd(" ", data->hash_fd.p);
	ft_putstr_fd(data->flags, data->hash_fd.p);
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
	while (lowest_key != -1)
	{
		i = lowest_key;
		collision_update(data, old_key, lowest_key, &i);
		old_key = lowest_key;
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
