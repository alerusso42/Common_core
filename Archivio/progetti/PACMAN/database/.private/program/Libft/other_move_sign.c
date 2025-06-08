/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_move_sign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:15:50 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/31 14:45:45 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other.h"

int	move_sign(char **type, char **name, char *sign)
{
	unsigned int		count_sign;
	char				*temp;

	if ((!type) || (!name) || (!(*type)) || (!(*name)) || (!sign) || !(*sign))
		return (1);
	temp = (*name);
	count_sign = 0;
	while (*(*name) == *sign)
		if ((*(*name)++) == *sign)
			count_sign++;
	trim_only_right(&temp, sign);
	SDL_free(temp);
	if (!(*name))
		return (1);
	temp = (char *)ft_calloc(count_sign + 1, sizeof(char));
	if (!temp)
		return (1);
	temp[count_sign] = 0;
	while (count_sign--)
		temp[count_sign] = *sign;
	(*type) = ft_strjoin_free((*type), temp);
	if (++sign)
		if (move_sign(type, name, sign) == 1)
			return (1);
	return (0);
}
