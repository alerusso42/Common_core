/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bfs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:58:05 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/20 15:25:00 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_BFS_H
# define GAME_BFS_H

#include "libft.h"

typedef struct s_position
{
	unsigned char	value;
	char		    *distance;
}               t_position;

typedef struct s_bfs
{
	int			n;
	int			mark;
	int			en_x;
	int			en_y;
	int			p_x;
	int			p_y;
	int			x;
	int			y;
	int			map_x;
	int			map_y;
	t_position	**position;
	int			distance;
}				t_bfs;

t_typelist	*store_list(t_typelist *list, int mode);
void	    del_free(void *ptr);
int	        draw_path(t_bfs *bfs);
void		bfs(t_bfs *bfs);
//int	    get_best_path(t_map *map, int enemy_num);
//void		clean_bfs(t_map *map, int enemy_num);

#endif