/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:34:46 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/25 14:22:22 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

int			change_files(t_pipex *pipex, int *pipe_fds, int i, int prev);
static void	close_all(t_pipex *pipex, int *pipe_fds, int prev);

int	execute_pipe(t_pipex *pipex, t_settings *settings)
{
	pid_t	pid;
	int		i;
	int		pipe_fds[2];
	int		prev;

	(void)settings;
	i = 0;
	prev = 0;
	while (pipex->commands[i])
	{
		if (pipe(pipe_fds) == -1)
			return (error(ER_PIPE_FAILED));
		pid = fork();
		if (pid == -1)
			return (error(ER_FORK_FAILED));
		else if (pid == 0)
		{
			if (change_files(pipex, pipe_fds, i, prev) != 0)
				return (error(ER_DUP_FAILED));
			execve(pipex->options[i][0], pipex->options[i], pipex->options[i]);
			return (error(ER_EXECVE_FAILED));
		}
		if (wait(NULL) == -1)
			return (error(ER_WAIT_FAILED));
		if (prev != 0)
			close(prev);
		prev = pipe_fds[0];
		close(pipe_fds[1]);
		++i;
	}
	return (close(pipe_fds[0]), 0);
}

/*	CONDITION		|||	COMMAND_ORDER	|||	INFILE		|||	OUTFILE	

	i == 0 ---------->	First cmd			infile			pipe[1]

	cmd[i + 1] != NULL	Not last cmd		prev. pipe[0]	pipe[1]

	cmd[i + 1] == NULL	Last cmd			prev. pipe[0]	outfile

----------------------------------------------------------------------
	EXAMPLE:

	INFILE	------->	pipex->fds[0] = 3;
	OUTFILE	------->	pipex->fds[1] = 4;
	
	FILE TEMP 1	--->  	pipe[0] = 5;		pipe[1] = 6;
	FILE TEMP 2	--->  	pipe[0] = 7;		pipe[1] = 8;	
	FILE TEMP 3	--->  	pipe[0] = 9;		pipe[1] = 10;

	For three commands:

	CMD_1	--------->	READ: 3(infile);		WRITE: 6(temp1, pipe[1]);
	CMD_2	--------->	READ: 5(temp1, pipe[0]);WRITE: 8(temp2, pipe[1]);
	CMD_3	--------->	READ: 7(temp1, pipe[0]);WRITE: 4(outfile);
	
----------------------------------------------------------------------
We open the pipes to store temp data.
Notice that last call to pipe could be avoided.
IMPROVE THIS BEFORE CORRECTION.
*/
int	change_files(t_pipex *pipex, int *pipe_fds, int i, int prev)
{
	int	err;

	err = 0;
	if (i == 0)
	{
		if (set_input_file(pipex->fds[0]) != 0)
			err = ER_DUP_FAILED;
		if (set_output_file(pipe_fds[1]) != 0)
			err = ER_DUP_FAILED;
	}
	else if (pipex->commands[i + 1] != NULL)
	{
		if (set_input_file(prev) != 0)
			err = ER_DUP_FAILED;
		if (set_output_file(pipe_fds[1]) != 0)
			err = ER_DUP_FAILED;
	}
	else
	{
		if (set_input_file(prev) != 0)
			err = ER_DUP_FAILED;
		if (set_output_file(pipex->fds[1]) != 0)
			err = ER_DUP_FAILED;
	}
	return (close_all(pipex, pipe_fds, prev), err);
}

static void	close_all(t_pipex *pipex, int *pipe_fds, int prev)
{
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	pipe_fds[0] = -1;
	pipe_fds[1] = -1;
	close(pipex->fds[0]);
	close(pipex->fds[1]);
	if (prev != 0)
		close(prev);
	else
		close(0);
}

/*
static void	close_one(int *fd)
{
	if (*fd != -1)
		close(*fd);
	*fd = -1;
}*/
