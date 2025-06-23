/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:46:54 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/23 14:17:51 by alerusso         ###   ########.fr       */
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
	l_printf(COL_GREEN"\nPlease wait..\n"COL_R);
	parsing(&data);
	frontend(&data);
	rewrite_file(&data, data.filename, data.entry[0].filename);
	free_memory(&data);
	return (0);
}
