/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:43:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/22 15:24:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

static void	reset_memory2(t_pipex *pipex);

void	reset_memory(void)
{
	t_pipex	*pipex;

	pipex = (t_pipex *)storage(NULL, 1);
	if (pipex == NULL)
		return ;
	if (pipex->fds)
	{
		free(pipex->fds);
		pipex->fds = NULL;
	}
	if (pipex->commands)
	{
		free_matrix(pipex->commands);
		pipex->commands = NULL;
	}
	if (pipex->path)
	{
		free_matrix(pipex->path);
		pipex->path = NULL;
	}
	reset_memory2(pipex);
	free(pipex);
	storage(NULL, 0);
}

static void	reset_memory2(t_pipex *pipex)
{
	if (pipex->options)
	{
		free_three_d_matrix(pipex->options);
		pipex->options = NULL;
	}
}
