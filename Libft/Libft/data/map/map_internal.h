/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 21:55:16 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/08 01:53:27 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_INTERNAL_H
# define MAP_INTERNAL_H

# include "map.h"

# define MAP_NPOS (size_t)-1
# if MAP_LOG_BOOL true
#  define MAP_SWITCH_LOG(s, ...) err_printf(s, ##__VA_ARGS__);break 
#  define MAP_LOG(s, ...) err_printf(s, ##__VA_ARGS__)
# else
#  define MAP_SWITCH_LOG(s, ...) (void)0;break 
#  define MAP_LOG(s, ...) (void)0
# endif

typedef struct s_map		t_map;
typedef struct s_map_values	t_map_values;
typedef struct s_map_node	t_map_node;

# define map_error(code, data)	_map_error(ptr, code, data, __FUNCTION__)

size_t	map_default_hash(const char *key);
bool	map_find(t_map *ptr, const char *key);
void	map_end_function(t_map *ptr);
int		_map_error(t_map *ptr, int code, void *data, const char *caller);

#endif