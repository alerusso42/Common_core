/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:57:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/28 18:21:34 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_TPP
# define ITER_TPP

#include "iter.hpp"

template	<typename A, typename F>
void		iter(A *addr, u_int32_t length, F fun)
{
	if (!addr)
		return ;
	for (u_int32_t i = 0; i < length ; i++)
		fun(addr[i]);
}

template	<typename A, typename F>
void		iter(const A *addr, u_int32_t length, F const fun)
{
	if (!addr)
		return ;
	for (u_int32_t i = 0; i < length ; i++)
		fun(addr[i]);
}

#endif