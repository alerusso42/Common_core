/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:48:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/04 16:26:29 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "Libft/all.h"

void	alloc_memory(t_data *data);
void	free_memory(t_data *data);
void	error(t_data *data, int err_type);

typedef struct s_hash_list
{
	int	key;
	int	pos;
}	t_hash_list;

typedef struct s_data
{
	t_fd		data_fd;
	t_fd		hash_fd;
	char	*data_file;
	char	*hash_file;
	int		file_num;
	int		hash_size;
	char	separator;
}	t_data;

enum e_error
{
	ER_OK,
	ER_OPEN,
	ER_ATOI,
};

#endif