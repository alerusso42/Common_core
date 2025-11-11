/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:30:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/11 16:26:38 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
# define PMERGEME_TPP
# include "PmergeMe.hpp"

template <typename T>
static void	merge(T &big, T &little, int32_t pos, Pair &pairs);
template <typename T>
static void	insert(T &big, T &little, int32_t pos_lit, int32_t pos_big);
template <typename T>
static int32_t	binary_search(T &big, T &little, int32_t pos, Pair &pairs);

template <typename T>
void	sort(T &big)
{
	T			little;
	int32_t		size_half;
	Jacobsthal	sequence;
	Pair		pairs(big.size());

	if (big.size() <= 1)
		return ;
	size_half = big.size() / 2;
	for (int32_t i = 0; i < size_half; i += 1)
		merge(big, little, i + (big[i] > big[i + 1]), pairs);
	sort(big);
	for (int32_t i = sequence.next(); i < (int32_t)little.size(); i = sequence.next())
	{
		for (; i >= sequence.prev(); i--)
			insert(big, little, i, binary_search(big, little, i, pairs));
	}
	for (int32_t i = little.size() - 1; little.empty() == false; i--)
		insert(big, little, i, binary_search(big, little, i, pairs));
}

template <typename T>
static void	merge(T &big, T &little, int32_t pos, Pair &pairs)
{
	little.push_back(*(big.begin() + pos));
	big.erase(big.begin() + pos);
	pairs.add(little.size() - 1, pos * 2);
}

template <typename T>
static void	insert(T &big, T &little, int32_t pos_lit, int32_t pos_big)
{
	big.insert(big.begin() + pos_big, *(little.begin() + pos_lit));
	little.erase(little.begin() + pos_lit);
}

template <typename T>
static int32_t	binary_search(T &big, T &little, int32_t pos, Pair &pairs)
{
	int32_t	i = 0;

	for (; i < pairs.find(pos); i++)
		if (little[pos] <= big[i] || i == (int32_t)big.size() - 1)
			return (i);
	return (i);
}

#endif