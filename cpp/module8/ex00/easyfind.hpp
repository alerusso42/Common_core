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

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include "lib/lib.hpp"
# include "vector"
# include "map"
# include "list"
# include "algorithm"

template	<typename T>
void		print(const T &val);

template	<typename T>
int			easyfind(const T &arr, int n);

# include "easyfind.tpp"

#endif