/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:50:39 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 16:50:40 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T, typename C>
MutantStack<T, C>::MutantStack()
{

}

template <typename T, typename C>
MutantStack<T, C>::MutantStack(const MutantStack& other)
{
	(void)other;
}

template <typename T, typename C>
MutantStack<T, C>::~MutantStack()
{
}

template <typename T, typename C>
const MutantStack<T, C>& MutantStack<T, C>::operator=(const MutantStack& other)
{
	if (this == &other)
		return *this;
	return *this;
}

template <typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::begin()
{
	return (this->c.begin());
}

template <typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::end()
{
	return (this->c.end());
}
