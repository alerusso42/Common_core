/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:58:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/26 20:53:06 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	error(t_data *data, int err_type);

/*
$INIT_HASH "$file" "$hash_file" $i "$delim" "${entries[$file]:0:999}"
 "$HASH_SIZE"
 chdir("../../");
*/
int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 7)
		return (1);
	data = (t_data){0};
	parse_args(&data, argv);
	alloc_memory(&data);
	switch_filedata(data.data_fd);
	fill_hash_table(&data);
	print_filedata(&data);
	print_hash_table(&data);
	free_memory(&data);
	return (0);
}
