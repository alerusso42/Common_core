/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_entries.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 08:48:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/23 13:29:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	valid_entry(char *line)
{
	int		count_entries;
	int		i;

	if (!line)
		return (false);
	count_entries = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == SEPARATOR)
			count_entries++;
		++i;
	}
	if (count_entries != TOTAL_ENTRIES - 1)
		return (false);
	return (true);
}

static void	trim_left(char *line, int *i);

void	trim_spaces(char *line)
{
	int		i;
	bool	inside_entry;

	if (!line)
		return ;
	i = 0;
	inside_entry = false;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == SEPARATOR)
		{
			trim_left(line, &i);
			inside_entry = false;
		}
		else if (line[i] == TO_TRIM && inside_entry == false)
		{
			cut_string(line, i, i);
			--i;
		}
		else if (line[i] != TO_TRIM)
			inside_entry = true;
		++i;
	}
	trim_left(line, &i);
	if (line[i] == '\n')
		line[i + 1] = 0;
}

static void	trim_left(char *line, int *i)
{
	int	j;

	if (*i == 0)
		return ;
	(*i)--;
	j = (*i);
	while (j && line[j] != SEPARATOR && line[j] == TO_TRIM)
	{
		j--;
	}
	if (*i != j)
		cut_string(line, j + 1, *i);
	(*i)++;
}
