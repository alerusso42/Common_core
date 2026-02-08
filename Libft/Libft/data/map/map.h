/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 21:55:16 by alerusso          #+#    #+#             */
/*   Updated: 2026/02/08 01:42:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../../libft.h"
# include <stdbool.h>

# define MAP_LOG_BOOL true
# define DEFAULT_SEED 42UL

typedef struct s_map			t_map;
typedef struct s_map_values		t_map_values;
typedef struct s_map_node		t_map_node;
typedef struct s_map_private	t_map_private;

/**
 *## struct s_map
 *### description
- stored data like an unsorted map.
- keys are unique. When adding a new key that already exists:
	`map_add`		returns error MAP_EXIST
	`map_replace`	clears old val if exists, then save new val
- hasher function can be set by changing the variable `hasher`
  default is murmurhash
- a delete function can be set by changing the variable `del`
  default values are not freed
  the delete function is called when:
  `map_clear` method is called
  `map_erase` method is called
  a critical error occured (map->fail set)
 *### variables
`hasher`	a ptr to the function that hash the keys {size_t(*)(char*)}
`del`		a ptr to the function that free val data {void(*)(void*)}
`data`		an array of t_map_values (list of element that collides)
`size`		total number of element in the map
`hash_size`	size of the data array
`fail`		bool true if a critical error occured
 *### methods
 * |Action         |Function Prototype                                    |
 * |:--------------|:-----------------------------------------------------|
 * |:--------------|:-----------------------------------------------------|
 * | alloc data    | `int map_init(t_map *ptr, size_t hash_size)`			|
 * | free data     | `void map_free(t_map *ptr)`						    |
 * | clear data    | `void map_clear(t_map *ptr)`						    |
 * | add key if new| `int map_add(t_map *ptr, char *key, void *val)`		|
 * | add key       | `int map_replace(t_map *ptr, char *key, void *val)`	|
 * | get value     | `void *map_get(t_map *ptr, char *key)`				|
 * | delete key    | `void map_del(t_map *ptr, char *key)`				|
 * |:------------..|:-----------------------------------------------------|
 */
typedef struct s_map
{
	t_map_private	_priv;
	size_t(*hasher)(char*);
	void(*del)(void*);
	t_map_values	**data;
	size_t			size;
	size_t			hash_size;
	bool			fail;
}		t_map;

/*
-	accessed from t_map::data by keys
-	stores a list of values whose keys collide
-	nodes in the list are t_map_node (char *key/void *val pair)
-	size is the number of elements in the list
*/
typedef struct s_map_values
{
	t_list	*values;
	size_t	size;
}		t_map_values;

typedef struct s_map_node
{
	char	*key;
	void	*val;
}		t_map_node;

//do not touch these data
typedef struct s_map_private
{
	t_list		*list;
	t_map_node	*node;
	size_t		i;
	size_t		it;
}		t_map_private;

enum e_map_ret_codes
{
	MAP_OK,
	MAP_SECTION_ERROR,
	MAP_EXIST,
	MAP_NOTFOUND,
	MAP_EINVAL,
	MAP_BUG,
	MAP_SECTION_CRITICAL,
	MAP_INIT_EINVAL,
	MAP_NOMEM,
};

int 	map_init(t_map *ptr, size_t hash_size);
void 	map_free(t_map *ptr);
void 	map_clear(t_map *ptr);
int 	map_add(t_map *ptr, char *key, void *val);
int 	map_replace(t_map *ptr, char *key, void *val);
void 	*map_get(t_map *ptr, char *key);
void 	map_del(t_map *ptr, char *key);


#endif