/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_entries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:19:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/21 01:32:09 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	set_entries(t_data *data)
{
	char	*names[TOTAL_ENTRIES + 1] = {NAMES};
	char	*files[TOTAL_ENTRIES + 1] = {FILES};
	char	*types = TYPES;
	int		i;
	int		j;

	data->filename = D_NAME;
	i = 0;
	while (names[i] && files[i] && types[i] && i < TOTAL_ENTRIES)
	{
		data->entry[i].first_entry = i;
		data->entry[i].name = names[i];
		data->entry[i].filename = files[i];
		data->entry[i].type = types[i];
		j = 0;
		while (j != ALPHABET_SIZE)
			data->entry[i].offsets[j++] = -1;
		++i;
	}
	if (i != TOTAL_ENTRIES)
		error(data, ER_MISSING_NAME_HEADER);
}
