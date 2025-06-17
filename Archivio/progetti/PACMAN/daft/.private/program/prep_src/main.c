/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:58:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/17 10:00:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	error(t_data *data, int err_type);

/*
$INIT_HASH "$file" "$hash_file" $i "$delim" "${entries[$file]:0:999}"
 "$HASH_SIZE"
*/
int	main(int argc, char *argv[])
{
	t_data	data;

	chdir("../../");
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
