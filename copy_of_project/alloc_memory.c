/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:18:38 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/24 15:18:34 by alerusso         ###   ########.fr       */
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
	storage((void *)*pipex, 0);
	if (!*pipex)
		return (ER_MALLOC);
	(*pipex)->fds = (int *)ft_calloc(5, sizeof(int));
	if (!(*pipex)->fds)
		return (ER_MALLOC);
	return (0);
}

int	alloc_cmd(t_pipex *pipex, int max_cmd)
{
	if ((!pipex))
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
	return (0);
}
