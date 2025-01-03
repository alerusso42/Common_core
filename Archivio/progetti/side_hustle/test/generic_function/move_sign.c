/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 09:20:35 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/03 17:51:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Muove caratteri, presi singolarmente, dalla stringa
	2 alla stringa 1.
*/
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
	(*name) = ft_strtrim_one(temp, *sign);
	free(temp);
	if (!(*name))
		return (1);
	temp = (char *)ft_calloc(count_sign + 1, sizeof(char));
	if (!temp)
		return (1);
	temp[count_sign] = 0;
	while (count_sign--)
		temp[count_sign] = *sign;
	(*type) = ft_strjoin_custom((*type), temp);
	if (++sign)
		if (move_sign(type, name, sign) == 1)
			return (1);
	return (0);
}