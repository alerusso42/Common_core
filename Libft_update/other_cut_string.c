/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_cut_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:09:57 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/20 16:36:14 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other.h"

int	cut_string(char **string, size_t start, size_t end)
{
	unsigned int	temp;
	unsigned int	string_len;

	end++;
	if (!(string) || !(*string) || (start > end))
		return (1);
	string_len = 0;
	while ((*string)[string_len])
		++string_len;
	temp = start;
	while ((start != end) && ((*string)[start] != 0))
		(*string)[start++] = 0;
	end = start;
	start = temp;
	temp = 0;
	while (end != string_len)
	{
		(*string)[start + temp] = (*string)[end + temp];
		--string_len;
		++temp;
	}
	return (0);
}