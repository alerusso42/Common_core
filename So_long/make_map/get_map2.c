/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:18:22 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/17 18:15:13 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_MAP2_H
# define GET_MAP2_H
# define MIN_INT_VALUE -2147483648
# define MAX_INT_VALUE 2147483647
# include "types.h"
# include "switches.h"
# include "variables.h"
# include "general_ft.h"
# include "atoi.h"
# include "error_message.h"
# include "alloc_t_input.h"
# include "alloc_t_solution.h"
# include "alloc_t_random.h"
# include "random_numbers.h"
# include "print_stuff.h"
# include "edit_map.h"
# include "check_map.h"
# include "save_map.h"
# include "get_next_line_bonus.h"
# include <unistd.h>
# include <fcntl.h>

t_bool	read_map(t_input *input, t_solution *solution)
{
	int		fd;
	char	*line;
	int		x;
	int		y;

	y = input->game_size_h - 1;
	fd = open(input->filename, O_RDONLY, 0666);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		x = 0;
		while ((line[x]) && (line[x] != '\n'))
		{
			solution->position[x][y].value = line[x];
			++x;
		}
		y--;
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 0);
}

#endif