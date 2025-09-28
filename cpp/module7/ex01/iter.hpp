/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:52:28 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/28 15:52:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include "lib/lib.hpp"

# define ARR_LENGTH 10

template	<typename A, typename F>
void		iter(A *addr, u_int32_t length, F fun);

template	<typename A, typename F>
void		iter(const A *addr, u_int32_t length, F const fun);

# include "iter.tpp"

#endif