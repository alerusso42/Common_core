/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:21:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/27 17:21:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP
# include "lib/lib.hpp"
# include "Base.hpp"

class B : public Base
{
public:
//	canonic form:
	B();
	~B();
	B(const B &other);
	B &operator=(const B &other);
};

#endif
