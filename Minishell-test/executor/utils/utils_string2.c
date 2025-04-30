/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:25:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/30 17:02:32 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

int	_reverse_strncmp(char *s1, char *s2, int len)
{
	int	i;
	int	j;
	int	diff;

	i = 0;
	j = 0;
	diff = 0;
	while (s1[i])
		++i;
	while (s2[j])
		++j;
	while (!diff && len && i != 0 && j != 0)
	{
		diff = s1[i--] != s2[j--];
		len--;
	}
	return (len + diff);
}

/*REVIEW - double_cmp
	A strncmp with double comparison.
	It is possible to set a number of chars to ignore for second string.
*/
int	double_cmp(char *s1, char *s2, int s1_len, int ignore_n_char)
{
	if (ft_strncmp(s1, s2, ft_strlen(s2) - ignore_n_char))
		return (1);
	if (ft_strncmp(s1, s2, s1_len))
		return (1);
	return (0);
}
