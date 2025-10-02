/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:40:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 14:35:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	alpha_hash(std::string s)
{
	int	hash;
	int	i;

	hash = 0;
	i = 0;
	while (s[i] && i < 12)
	{
		hash += (int)s[i];
		++i;
	}
	if (hash >= 1000)
		return (99);
	return (hash / 10);
}
