/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:30:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/30 17:06:14 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
# define PMERGEME_TPP
# include "PmergeMe.hpp"

template <typename T>
static void	merge(T &big, T &little, int32_t pos);
template <typename T>
static void	insert(T &big, T &little, int32_t pos);

template <typename T>
void	sort(T &big)
{
	T			little;
	int32_t		size_half;
	Jacobsthal	sequence;

	if (big.size() <= 1)
		return ;
	size_half = big.size() / 2;
	for (int32_t i = 0; i < size_half; i++)
		merge(big, little, i + (big[i] > big[i + 1]));
	sort(big);
	for (int32_t i = 0; i < size_half; i = sequence.next())
	{
		u_int32_t j = sequence.prev();
		while (i >= sequence.prev() && i >= 0)
		{		
			while (little[0] > big[j] && j < big.size())
				j++;
			insert(big, little, j);
			i--;
		}
	}
}

template <typename T>
static void	merge(T &big, T &little, int32_t pos)
{
	little.push_back(*(big.begin() + pos));
	big.erase(big.begin() + pos);
}

template <typename T>
static void	insert(T &big, T &little, int32_t pos)
{
	big.insert(big.begin() + pos, *little.begin());
	little.erase(little.begin());
}

#endif