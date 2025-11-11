/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:51:51 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/11 12:27:05 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP
# include "lib/lib.hpp"

class Pair
{
private:
	int32_t	*_first;
	int32_t	*_second;
	int32_t	_size;
	int32_t	_capacity;

	void	realloc();
	void	alloc();
public:
//SECTION - canon form
	Pair(int32_t size);
	Pair(Pair &other);
	~Pair();
	Pair	operator=(Pair &other);

	void	add(int32_t p1, int32_t p2);
	int32_t	find(int32_t pos) const;
};

#endif