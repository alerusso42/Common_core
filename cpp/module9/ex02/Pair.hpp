/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:51:51 by alerusso          #+#    #+#             */
/*   Updated: 2025/12/13 10:47:26 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP
# include "lib/lib.hpp"

# include <limits.h>

class Pair
{
private:
	enum e_Pair
	{
		E_OK,
		E_ALLOC,
		E_EMPTY,
		E_OUT_RANGE,
		PAIR_EMPTY = INT_MAX,
	};
	int32_t	*_buffer;
	int32_t	_size;
	int32_t	_capacity;
	int32_t	_error;

	void	_realloc();
	void	_alloc();
	void	_copy(int32_t *new_arr, int32_t *old_arr);
public:
//SECTION - canon form
	Pair(int32_t size);
	Pair(Pair &other);
	~Pair();
	Pair	operator=(Pair &other);

	void	add(int32_t p1, int32_t p2);
	void	rm(int32_t p1);
	int32_t	find(int32_t pos);
	int32_t	error() const;
	int32_t	error(int32_t val);
};

#endif