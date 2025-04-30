/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:00:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/30 17:02:24 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	write_here_doc(char *line, t_exec *exec, int fd)
{
	int		i;
	int		end;
	char	*env_str;
	char	temp;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '$')
		{
			end = i + 1;
			while (line[end] && line[end] != ' ' && line[end] != '$')
				++end;
			temp = line[end];
			line[end] = 0;
			env_str = ft_getenv(*exec->env, line + i + 1, NULL);
			if (env_str)
				ft_putstr_fd(env_str, fd);
			if (!temp)
				break ;
			line[end] = temp;
			i = end - 1;
		}
		else
			write(fd, &line[i], 1);
	}
}