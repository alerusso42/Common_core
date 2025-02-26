/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:18:38 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/26 15:43:26 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

int	alloc_main_struct(t_pipex **pipex)
{
	*pipex = (t_pipex *)ft_calloc(1, sizeof(t_pipex));
	if (!*pipex)
		return (ER_MALLOC);
	storage((void *)*pipex, 0);
	return (0);
}

/*
	max_cmd is argc.
	We'll never had more commands than argc.
*/
int	alloc_cmd(t_pipex *pipex, int max_cmd)
{
	if ((!pipex))
		return (ER_MALLOC);
	pipex->fds = (int *)ft_calloc(max_cmd * 2, sizeof(int));
	if (!pipex->fds)
		return (ER_MALLOC);
	if (!pipex->commands)
	{
		pipex->commands = (char **)ft_calloc(max_cmd, sizeof(char *));
	}
	if (!pipex->commands)
		return (ER_MALLOC);
	pipex->options = (char ***)ft_calloc(max_cmd, sizeof(char **));
	if (!pipex->options)
		return (ER_MALLOC);
	pipex->pid_list = (int *)ft_calloc(max_cmd, sizeof(int));
	if (!pipex->pid_list)
		return (ER_MALLOC);
	pipex->cmd_num = max_cmd - 3;
	return (0);
}
