/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:56:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/28 13:56:17 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include "lib/lib.hpp"
# include <iostream>
# include <string>

template	<typename T>
void	swap(T &x, T &y);

template	<typename T>
T	&min(T &x, T &y);

template	<typename T>
T	&max(T &x, T &y);

# include "whatever.tpp"

#endif