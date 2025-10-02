/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:09:18 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 14:35:07 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.hpp"

/*
	@param: 	two strings (haystack, needle); max len.
	@returns:	the iterator of the first occurence of little in big.
				if no occurence are found, returns big.end() iterator.
*/
iterator	ft_strnstr(std::string &big, std::string &little, size_t len)
{
	int	i;

	if (little.empty())
		return (big.end());
	i = 0;
	while (big[i] && len--)
	{
		if (big.compare(i, little.length(), little) == 0)
			return (big.begin() + i);
		i++;
	}
	return (big.end());
}
