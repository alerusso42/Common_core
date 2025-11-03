/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 21:30:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/03 22:09:06 by alerusso         ###   ########.fr       */
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
static int32_t	binary_search(T &big, T &little, int32_t pos);

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
	for (int32_t i = sequence.next(); i < (int32_t)little.size(); i = sequence.next())
	{
		for (; i >= sequence.prev(); i--)
			insert(big, little, i, binary_search(big, little, i));
	}
	for (int32_t i = little.size() - 1; little.empty() == false; i--)
		insert(big, little, i, binary_search(big, little, i));
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
static int32_t	binary_search(T &big, T &little, int32_t pos)
{
	for (u_int32_t i = 0; true; i++)
		if (little[pos] <= big[i] || i == big.size() - 1)
			return (i);
}

#endif