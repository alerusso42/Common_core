/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:37:40 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/26 19:14:13 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	get_paths_data(t_exec *exec, t_token *token)
{
	char	*path;
	int		cmd_index;

	path = getenv("PATH");
	if (!path)
		return (0);
	exec->path = ft_split(path, ':');
	cmd_index = 0;
	while (exec->commands[cmd_index])
	{
		token->which_cmd = is_a_builtin_cmd(exec->commands[cmd_index][0]);
		if (token->which_cmd == _NO)
		{
			if (get_one() == E_MALLOC)
				return (E_MALLOC);
		}
		++cmd_index;
	}
	
	return (0);
}
