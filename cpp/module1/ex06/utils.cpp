/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:40:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/01 22:55:48 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	alpha_hash(string s)
{
	int	hash;
	int	i;

	hash = 0;
	i = 0;
	while (s[i] && s[i + 1] && i < 12)
	{
		hash += ((int)s[i] ^ MASK) << 5;
		i += 1;
	}
	hash += i;
	while (hash < 0)
		hash += 1000;
	while (hash >= 1000)
		hash -= 1000;
	return (hash / 10);
}

//returns 1 on error	
int	filter_check(string s, int filter)
{
	switch (alpha_hash(s))
	{
		case (LV_DEBUG)	:
			return (LV_DEBUG < filter);
		case (LV_INFO)	:
			return (LV_INFO < filter);
		case (LV_WARNING) :
			return (LV_INFO < filter);
		case (LV_ERROR)	:
			return (LV_INFO < filter);
		default	:
			return (1);
	}
}
