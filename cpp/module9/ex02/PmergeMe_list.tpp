/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe_list.tpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:30:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/07 01:59:57 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_LIST_TPP
# define PMERGEME_LIST_TPP
# include "PmergeMe.hpp"

template <typename T>
static void	merge(std::list<T> &big, std::list<T> &little, typename std::list<T>::iterator it);
template <typename T>
static void	insert(std::list<T> &big, std::list<T> &little, typename std::list<T>::iterator it);

template <typename T>
void	sort_list(std::list<T> &big)
{
	typename std::list<T>::iterator	temp;
	typename std::list<T>::iterator	next;
	std::list<T>					little;
	int32_t							size_half;

	if (big.size() <= 1)
		return ;
	size_half = big.size() / 2;
	temp = big.begin();
	for (int32_t i = 0; i < size_half; i++)
	{
		next = temp;
		next++;
		if (*temp > *next)
		{
			merge(big, little, temp);
			temp = next;
		}
		else
			merge(big, little, next);
	}
	sort_list(big);
	for (int32_t i = 0; i < size_half; i++)
	{
		temp = big.begin();
		u_int32_t j = 0;
		while (*little.begin() > *temp && j < big.size())
		{
			temp++;
			j++;
		}
		insert(big, little, temp);
	}
}

template <typename T>
static void	merge(std::list<T> &big, std::list<T> &little, typename std::list<T>::iterator it)
{
	little.push_back(*it);
	big.erase(it);
}

template <typename T>
static void	insert(std::list<T> &big, std::list<T> &little, typename std::list<T>::iterator it)
{
	big.insert(it, *little.begin());
	little.erase(little.begin());
}

#endif