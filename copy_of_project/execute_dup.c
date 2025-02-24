/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:39:35 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/24 15:49:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

int	dup_fds(t_pipex *pipex, t_settings *settings)
{
	int	fd_infile;
	int	fd_outfile;

	(void)settings;
	fd_infile = open(pipex->infile, INFILE, 0666);
	if (fd_infile < 0)
		return (ER_OPEN_FAILED);
	pipex->fds[0] = fd_infile;
	fd_outfile = open(pipex->outfile, OUTFILE, 0666);
	if (fd_outfile < 0)
		return (ER_OPEN_FAILED);
	pipex->fds[1] = fd_outfile;
	if (dup2(fd_infile, 0) == -1)
		return (ER_DUP_FAILED);
	pipex->fds[2] = INT_MAX;
	if (dup2(fd_outfile, 1) == -1)
		return (ER_DUP_FAILED);
	pipex->fds[3] = 1;
	return (0);

}