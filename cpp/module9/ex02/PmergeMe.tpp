/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:30:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/12/16 09:23:25 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
# define PMERGEME_TPP
# include "PmergeMe.hpp"

template <typename T>
static void	merge(T &big, T &little, int32_t pos);
template <typename T>
static void	insert(T &big, T &little, int32_t pos_lit, int32_t pos_big);
template <typename T>
static int32_t	binary_search(T &big, T &little, int32_t pos, Pair &pairs);
template <typename T>
static void		create_pairs(T &big, T &little, Pair &pairs);

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
	create_pairs(big, pairs);
	for (int32_t i = 0; i < size_half; i += 1)
		merge(big, little, i + (big[i] > big[i + 1]));
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
static void	merge(T &big, T &little, int32_t pos)
{
	little.push_back(*(big.begin() + pos));
	big.erase(big.begin() + pos);
}

template <typename T>
static void	insert(T &big, T &little, int32_t pos_lit, int32_t pos_big)
{
	big.insert(big.begin() + pos_big, *(little.begin() + pos_lit));
	little.erase(little.begin() + pos_lit);
}

template <typename T>
static int32_t	binary_search(T &big, T &little, int32_t pos_lit, Pair &pairs)
{
	int32_t	pos_big = 0;

	for (; big[pos_big] != pairs.find(pos_lit); pos_big++)
		if (little[pos_lit] <= big[pos_big] || pos_big == (int32_t)big.size() - 1)
			break ;
	pairs.rm(pos_lit);
	return (pos_big);
}

template <typename T>
static void		create_pairs(T &big, Pair &pairs)
{
	size_t	lit_i;

	lit_i = 0;
	for (size_t big_i = 0; big_i + 1 < big.size(); big_i += 2)
	{
		pairs.add(lit_i, big[big_i + (big[big_i] > big[big_i + 1])]);
		lit_i += 1;
	}
}

#endif