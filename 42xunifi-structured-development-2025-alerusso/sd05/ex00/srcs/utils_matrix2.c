/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrix2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:55:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/21 04:33:36 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static bool	valid_char(char *s, char c);

void	offset_matrix(t_data *data, int entry)
{
	char	c;
	int		i;
	int		j;

	if (data->entry[entry].type == 's')
		c = 'a';
	else
		c = '0';
	i = 0;
	j = 0;
	while (i != ALPHABET_SIZE)
	{
		if (!data->entries[entry][j] || \
			 (valid_char(data->entries[entry][j], c) == true && \
			 unsensitive_check(data->entries[entry][j][0], c + i) == false))
		{
			++i;
		}
		else if (data->entries[entry][j])
		{
			if (data->entry[entry].offsets[i] == -1  && \
				 valid_char(data->entries[entry][j], c) == true)
				data->entry[entry].offsets[i] = j;
			++j;
		}
	}
}

static bool	valid_char(char *s, char c)
{
	if (c == 'a')
		return ((bool)ft_isalpha(s[0]));
	else
		return ((bool)ft_isdigit(s[0]));
}

static void	copy_entries(t_data *data, int entry, int n_elem, char *line)
{
	int	i;
	int	j;
	int	k;

	j = move_str(data->entries[entry][n_elem], SEPARATOR, data->entry[entry].first_entry);
	sub_strcpy(line, data->entries[entry][n_elem] + j, SEPARATOR_S, EXCLUDE);
	k = ft_strlen(line);
	line[k++] = SEPARATOR;
	i = 0;
	while (i != TOTAL_ENTRIES)
	{
		if (i != data->entry[entry].first_entry)
		{
			j = move_str(data->entries[entry][n_elem], SEPARATOR, i);
			sub_strcpy(line + k, data->entries[entry][n_elem] + j, SEPARATOR_S, EXCLUDE);
			k = ft_strlen(line);
			line[k++] = SEPARATOR;
		}
		++i;
	}
	line[k - 1] = '\n';
}

void	prioritize_main_entry(t_data *data, int entry)
{
	char	*line;
	int		i;

	i = 0;
	while (data->entries[entry][i])
	{
		line = ft_calloc(ft_strlen(data->entries[entry][i]) + 2, sizeof(char));
		if (!line)
			error(data, ER_MALLOC);
		copy_entries(data, entry, i, line);
		free(data->entries[entry][i]);
		data->entries[entry][i] = line;
		++i;
	}
}

int	cmp_to_matrix(char s[MAX_READ + 1], char *entries[TOTAL_ENTRIES])
{
	int	i;

	i = 0;
	while (i != TOTAL_ENTRIES)
	{
		if (!sub_strcmp(s, entries[i], ""))
			return (i);
		++i;
	}
	return (-1);
}
