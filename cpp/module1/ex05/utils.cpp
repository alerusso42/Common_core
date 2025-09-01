/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:40:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/01 21:43:30 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	alpha_hash(string s)
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
