/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 21:55:16 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/08 15:31:13 by codespace        ###   ########.fr       */
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
typedef struct s_map_val	t_map_val;

typedef struct s_map_find_data
{
    size_t	    i;
    t_list      *list;
    char        *key;
    void        *value;
}	t_map_find_data;

# define map_error(code, data)	_map_error(ptr, code, data, __FUNCTION__)

size_t	map_default_hash(const char *key);
bool	map_find(t_map *ptr, const char *key, t_map_find_data *val);
int		_map_error(t_map *ptr, int code, void *data, const char *caller);

#endif