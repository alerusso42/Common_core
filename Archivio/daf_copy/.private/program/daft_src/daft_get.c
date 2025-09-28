/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 08:44:50 by codespace         #+#    #+#             */
/*   Updated: 2025/09/18 23:28:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	*get_mem(t_daft_data *dt, t_daft_list *f, const char *s, t_fd fd);
static char	*check_key(const char *search, char field_sep[], t_fd *fd);
static void	*select_data_file(t_daft_data *data, t_daft_list *file, char *key);

/*
//REVIEW -	daft_get
//
	Takes a string as parameter. Gives back memory, or NULL.
	Fds are open and closed, without fd leaks.

	Memory returned depends on flags in SETTINGS.md.

	1)	*nn**:	Returns a regular string (char *);
	2)	*yn**:	Returns a 2D matrix(char **);
	3)	*ny**:	Returns a 2D matrix(char **);
	4)	*yy**:	Returns a 3D matrix(char **);

	Example:
	...
	APPLE|
	Colors=Red,Yellow,Green
	Id=2
	...
	FLAGS GIVEN		|	SEARCH CONTENT	|	RETURNS
------------------------------------------------------------
	1)	|nn=,		|	Colors			|	"Red,Yellow,Green"
	2)	|yn=,		|	APPLE			|	{"Red,Yellow,Green", "2"}
	3)	|ny=,		|	Colors			|	{"Red", "Yellow", "Green"}
	4)	|yy=,		|	APPLE			|	{"Red", "Yellow", "Green"}, {"2"}
*/
void	*daft_get(const char *search)
{
	t_daft_data	*data;
	t_fd		fd;
	void		*mem;

	if (!search)
		return (NULL);
	data = _daft_get_memory(NULL, false);
	if (!data)
		return (0);
	_daft_free_old_mem(data);
	fd = openfd(data->data_list[data->current_file]->filename, "r");
	if (!fd.n)
		return (NULL);
	mem = get_mem(data, data->data_list[data->current_file], search, fd);
	closefd(fd);
	return (mem);
}

//	Gets hash from string
static void	*get_mem(t_daft_data *dt, t_daft_list *f, const char *s, t_fd fd)
{
	int			hash_result;
	int			offset;
	t_daft_node	*current;
	char		*key;

	hash_result = _daft_hash(f, s);
	if (!f->node[hash_result])
		return (NULL);
	key = NULL;
	current = f->node[hash_result];
	while (!key && current)
	{
		offset = current->offset;
		SEEK(fd.p, offset, 0);
		key = check_key(s, f->field_sep, &fd);
		current = current->next;
	}
	if (!key)
		return (NULL);
	return (select_data_file(dt, f, key));
}

//	Check if key is right (for collisions).
static char	*check_key(const char *search, char field_sep[], t_fd *fd)
{
	char	*key;

	key = gnl();
	if (!key)
		return (NULL);
	if (!ft_strncmp(search, key, sub_strlen(key, field_sep, EXCLUDE)))
		return (key);
	FREE(key);
	reset_fd(*fd);
	return (NULL);
}

static void	*select_data_file(t_daft_data *data, t_daft_list *file, char *key)
{
	if (file->multiple_lines == false && file->split_values == false)
	{
		data->mem.type = STRING;
		return (_daft_get_string(data, file, key));
	}
	else if (file->multiple_lines == true && file->split_values == false)
	{
		data->mem.type = TWO_D_MATRIX;
		return (FREE(key), _daft_get_vertical_matr(data, file));
	}
	else if (file->multiple_lines == false && file->split_values == true)
	{
		data->mem.type = TWO_D_MATRIX;
		return (_daft_get_horiz_matr(data, file, key));
	}
	else if (file->multiple_lines == true && file->split_values == true)
	{
		data->mem.type = THREE_D_MATRIX;
		return (FREE(key), _daft_get_three_d_matr(data, file));
	}
	data->mem.type = NO_MEM;
	return (NULL);
}
