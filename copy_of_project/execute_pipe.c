/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:34:46 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/24 13:12:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

int	execute_pipe(t_pipex *pipex, t_settings *settings)
{
	pid_t	pid;
	int		i;

	(void)settings;
	i = 0;
	while (pipex->commands[i])
	{
		pid = fork();
		if (pid == -1)
			return (error(ER_FORK_FAILED));
		else if (pid == 0)
		{
			execve(pipex->options[i][0], pipex->options[i], pipex->options[i]);
			return (error(ER_EXECVE_FAILED));
		}
		wait(NULL);
		++i;
	}
	return (0);
}