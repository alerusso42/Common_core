/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 01:24:06 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/21 04:42:27 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	search_in_file(t_data *data, const char *s, int entry, int offset);

void	search(t_data *data, const char *s, int entry)
{
	int		char_type;
	int		offset;

	if (!s || !*s)
		return ;
	char_type = 0;
	if (*s >= 'a' && *s <= 'z')
		char_type = 'a';
	else if (*s >= 'A' && *s <= 'Z')
		char_type = 'A';
	else if (*s >= '0' && *s <= '9')
		char_type = '0';
	else
		char_type = 0;
	if (!char_type)
		offset = 0;
	else if (data->entry[entry].offsets[*s - char_type] == -1)
		offset = -1;
	else
		offset = data->entry[entry].offsets[*s - char_type];
	if (offset == -1 || search_in_file(data, s, entry, offset) == false)
		l_printf(COL_YELLOW"%s"COL_R" not found.\n", s);
}

static int	search_in_file(t_data *data, const char *s, int entry, int offset)
{
	int		fd;
	int		len;
	int		found_something;
	char	first;
	char	*line;

	if (!offset)
		first = 0;
	else
		first = *s;
	found_something = false;
	fd = open(data->entry[entry].filename, O_RDONLY);
	if (fd < 0)
		error(data, ER_OPEN);
	len = ft_strlen(s);
	line = get_n_line(fd, offset + 1);
	while (line && (!first || unsensitive_check(*line, first) == true))
	{
		if (!unsensitive_strncmp(s, line, len))
			found_something = l_printf("%s", line);	
		free(line);
		line = get_next_line(fd, false);
	}
	get_next_line(fd, RESET);
	return (free(line), close(fd), found_something);
}
