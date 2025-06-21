/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:46:54 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/21 00:04:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//	cd Libft, make all, cp libft.a ../
//	comp: cc -Wall -Wextra -Werror -g main.c srcs/*.c libft.a
int	main()
{
	t_data	data;

	data = (t_data){0};
	set_entries(&data);
	alloc_memory(&data);
	parsing(&data);
	frontend(&data);
	rewrite_file(&data, data.filename, data.entry[ID].filename);
	free_memory(&data);
	return (0);
}
