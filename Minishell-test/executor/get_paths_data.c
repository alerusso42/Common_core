/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:37:40 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/31 11:28:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	get_one(char **command, char **path);
static int	_add_sign_left(char **string, char sign);

int	get_paths_data(t_exec *exec, t_token *token)
{
	char	*path;
	int		cmd_index;

	path = getenv("PATH");
	if (!path)
		return (0);
	exec->path = ft_split(path, ':');
	if (!exec->path)
		return (E_MALLOC);
	cmd_index = 0;
	while (exec->commands[cmd_index])
	{
		if (exec->which_cmd[cmd_index] == _NO && access(token->content, X_OK))
		{
			if (get_one(exec->commands[cmd_index], exec->path) == E_MALLOC)
				return (E_MALLOC);
		}
		++cmd_index;
	}
	
	return (0);
}

/*
	
*/
static int	get_one(char **command, char **path)
{
	char	*temp;
	int		i;

	i = 0;
	if (_add_sign_left(command, '/') != 0)
		return (E_MALLOC);
	while (path[i])
	{
		temp = ft_strjoin(path[i], *command);
		if (!temp)
			return (E_MALLOC);
		if (access(temp, X_OK) == 0)
		{
			free(*command);
			*command = temp;
			break ;
		}
		free(temp);
		i++;
	}
	
	return (0);
}

//	I have to reallocate the entire fucking string 
//	to put a fucking '/'
//	calm down Ale calm down
//	It's all ok
//	Just string management
//	Nothing to worry about chill
static int	_add_sign_left(char **string, char sign)
{
	size_t	len;
	char	*new_string;

	if ((!string) || (!*string))
		return (1);
	len = ft_strlen(*string);
	new_string = (char *)ft_calloc(len + 2, sizeof(char));
	if (!new_string)
		return (1);
	new_string[0] = sign;
	ft_strlcpy(new_string + 1, *string, len + 1);
	free(*string);
	*string = new_string;
	return (0);
}
