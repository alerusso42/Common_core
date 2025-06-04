/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:58:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/04 21:03:26 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	parse_args(t_data *data, char *argv[]);
void	error(t_data *data, int err_type);

/*
$INIT_HASH "$file" "$hash_file" $i "$delim" "${entries[$file]:0:999}"
 "$HASH_SIZE"
*/
int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 7)
		return (1);
	chdir("../");
	data = (t_data){0};
	parse_args(&data, argv);
	alloc_memory(&data);
	free_memory(&data);
	return (0);
}
