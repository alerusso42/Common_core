/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Jacobsthal.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:59:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/30 16:55:38 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JACOBSTHAL_HPP
# define JACOBSTHAL_HPP
# include "lib/lib.hpp"

class Jacobsthal
{
private:
	int32_t	_a;
	int32_t	_b;
	int32_t	_c;

	enum e_jacobsthal
	{
		NUMBER_A = 1,	
		NUMBER_B = 1,	
		NUMBER_C = 1,	
	};
public:
	//canonic form
	Jacobsthal();
	~Jacobsthal();
	Jacobsthal(const Jacobsthal &other);
	Jacobsthal	operator=(const Jacobsthal &other);

	int32_t	next();
	int32_t	prev() const;
};

#endif