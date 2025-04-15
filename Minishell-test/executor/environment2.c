/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:30:06 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/15 17:19:25 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	write_here_doc(char *line, t_exec *exec, int fd)
{
	int		i;
	int		end;
	char	*env_str;
	char	temp;

	i = 0;
	end = -1;
	while (line[i])
	{
		if (line[i] == '$')
		{
			end = i;
			while (line[end] && line[end] != ' ')
				++end;
			temp = line[end];
			line[end] = 0;
			env_str = ft_getenv(*exec->env, line + end, NULL);
			if (env_str)
				ft_putstr_fd(env_str, fd);
			if (temp)
				end++;
			i = end;
		}
		if (i != end)
			++i;
	}
}
