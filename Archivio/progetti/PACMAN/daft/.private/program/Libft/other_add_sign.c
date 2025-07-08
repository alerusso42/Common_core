/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_add_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:05:18 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/08 15:42:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other.h"

int	add_sign_left(char **string, char sign)
{
	size_t	len;
	char	*new_string;

	if ((!string) || (!*string))
		return (1);
	len = ft_strlen(*string);
	new_string = (char *)ft_calloc(len + 2, sizeof(char));
	if (!new_string)
		return (1);
	new_string[0] = sign;
	ft_strlcpy(new_string + 1, *string, ft_strlen(*string));
	FREE(*string);
	*string = new_string;
	return (0);
}

int	add_sign_right(char **string, char sign)
{
	size_t	len;
	char	*new_string;

	if ((!string) || (!*string))
		return (1);
	len = ft_strlen(*string);
	new_string = (char *)ft_calloc(len + 3, sizeof(char));
	if (!new_string)
		return (1);
	new_string[len + 1] = 0;
	ft_strlcpy(new_string, *string, ft_strlen(*string));
	new_string[len] = sign;
	FREE(*string);
	*string = new_string;
	return (0);
}
