/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 21:55:16 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/08 22:06:45 by codespace        ###   ########.fr       */
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
    t_list      *node;
    t_list      *head;
    char        *key;
    void        *value;
}	t_map_find_val;

# define map_error(code, data)	_map_error(ptr, code, data, __FUNCTION__)

size_t	map_default_hash(const char *key);
int		_map_error(t_map *ptr, int code, void *data, const char *caller);
bool	_map_find(t_map *ptr, const char *key, t_map_find_val *val);
int 	_map_add(t_map *ptr, char *key, void *val, t_map_find_val *data);
int 	_map_replace(t_map *ptr, char *key, void *val, t_map_find_val *data);
void 	*_map_get(t_map *ptr, char *key, t_map_find_val *data);
void 	_map_del(t_map *ptr, char *key, t_map_find_val *data);

#endif