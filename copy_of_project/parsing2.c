/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:25:11 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/22 15:35:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

int	get_options(t_pipex *pipex)
{
	int	index;

	index = 0;
	while (pipex->commands[index])
	{
		pipex->options[index] = ft_split(pipex->commands[index], ' ');
		if (pipex->options[index] == NULL)
			return (ER_MALLOC);
		++index;
	}
	return (0);
}

int	get_commands_bonus(char *argv[], t_pipex *pipex, t_settings *set)
{
	(void)argv;
	(void)pipex;
	(void)set;
	return (9);	
}