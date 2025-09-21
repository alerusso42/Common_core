/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_utils_edit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 09:23:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/21 10:00:53 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "daft_prog.h"


/*
struct s_daft_list
{
	t_fd		filedata;
	t_daft_node	**node;
	char		*filename;
	int			size;
	char		field_sep[2];
	char		key_value_sep[2];
	char		values_sep[2];
	t_bool		multiple_lines:1;
	t_bool		split_values:1;		
};
*/

//	edits hash file. To call only if a file changes.
int	_daft_edit_hash_file(t_daft_list *list, int f_num)
{
	char	*fnames[2];
	char	flags[5];

	fnames[0] = list->filename;
	fnames[1] = _daft_get_hash_filename(list->filename);
	if (!fnames[1])
		return (_daft_log(DAFT_LOG_MALLOC));
	flags[0] = *list->field_sep;
	flags[1] = (list->multiple_lines) ? 'y': 'n';
	flags[2] = (list->split_values) ? 'y': 'n';
	flags[3] = *list->key_value_sep;
	flags[4] = *list->values_sep;
	return (_daft_prep_prog(fnames, flags, f_num, list->size));
}
