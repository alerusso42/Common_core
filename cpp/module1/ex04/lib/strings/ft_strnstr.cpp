/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:09:18 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/31 22:49:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.hpp"

/*
	@param: 	two strings (haystack, needle); max len.
	@returns:	the iterator of the first occurence of little in big.
				if no occurence are found, returns big.end() iterator.
*/
iterator	ft_strnstr(string &big, string &little, size_t len)
{
	int	i;

	if (little.empty())
		return (big.end());
	i = 0;
	while (big[i] && len--)
	{
		if (little.compare(&big[i]))
			return (big.begin() + i);
		i++;
	}
	return (big.end());
}
