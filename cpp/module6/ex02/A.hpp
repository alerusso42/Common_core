/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:21:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/27 17:21:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
# define A_HPP
# include "lib/lib.hpp"
# include "Base.hpp"

class A : public Base
{
public:
//	canonic form:
	A();
	~A();
	A(const A &other);
	A &operator=(const A &other);
};

#endif
