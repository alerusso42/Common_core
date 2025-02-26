/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:43:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/26 10:57:57 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

static void	reset_memory2(t_pipex *pipex);
static void	close_files(int *fds);

void	reset_memory(void)
{
	t_pipex	*pipex;

	pipex = (t_pipex *)storage(NULL, 1);
	if (pipex == NULL)
		return ;
	if (pipex->commands)
	{
		pipex->commands = free_matrix(pipex->commands);
	}
	if (pipex->path)
	{
		pipex->path = free_matrix(pipex->path);
	}
	if (pipex->options)
	{
		pipex->options = free_three_d_matrix(pipex->options);
	}
	reset_memory2(pipex);
	free(pipex);
	storage(NULL, 0);
}

static void	reset_memory2(t_pipex *pipex)
{
	if (pipex->infile)
	{
		if (ft_strncmp(pipex->infile, "here_doc", 8) == 0)
			unlink("here_doc");
		free(pipex->infile);
		pipex->infile = NULL;
	}
	if (pipex->outfile)
	{
		free(pipex->outfile);
		pipex->outfile = NULL;
	}
	if (pipex->fds)
	{
		close_files(pipex->fds);
		free(pipex->fds);
		pipex->fds = NULL;
	}
}

static void	close_files(int *fds)
{
	int	i;

	i = 0;
	while (fds[i])
	{
		if (fds[i] == INT_MAX)
			close(0);
		else if (fds[i] != -1)
			close(fds[i]);
		fds[i] = -1;
		++i;
	}
}
