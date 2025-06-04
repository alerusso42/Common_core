/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:58:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/04 16:29:55 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	parse_args(t_data *data, char *argv[]);
void	error(t_data *data, int err_type);



void	parse_args(t_data *data, char *argv[])
{
	long long int	atoi_check;

	data->data_fd = openfd(argv[1], "r");
	if (!data->data_fd.n)
		error(data, ER_OPEN);
	data->hash_fd = openfd(argv[2], "rw");
	if (!data->data_fd.n)
		error(data, ER_OPEN);
	atoi_check = ft_atoi(argv[3]);
	if (atoi_check > INT_MAX || atoi_check < INT_MIN)
		error(data, ER_ATOI);
	data->file_num = (int)atoi_check;
	data->separator = argv[4][0];
	if (!data->separator)
		error(data, ER_ATOI);
	atoi_check = ft_atoi(argv[5]);
	if (atoi_check > INT_MAX || atoi_check < INT_MIN)
		error(data, ER_ATOI);
	data->hash_size = (int)atoi_check;
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 6)
		return (1);
	data = (t_data){0};
	parse_args(&data, argv);	
}