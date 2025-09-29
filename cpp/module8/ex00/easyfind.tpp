/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 22:30:42 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/29 22:30:42 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP
# include "lib/lib.hpp"
# include "vector"
# include "map"
# include "list"
# include "algorithm"

template	<typename T>
void		print(const T &val)
{
	std::cout << val << "\n";
}

template	<typename T>
int			easyfind(const T &arr, int n)
{
	typename	T::const_iterator	i;

	i = find(arr.begin(), arr.end(), n);
	if (i == arr.end())
		throw (Error(EX_NOT_FOUND));
	return (*i);
}

#endif