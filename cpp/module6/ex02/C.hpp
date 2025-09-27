/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:21:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/27 17:21:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP
# include "lib/lib.hpp"
# include "Base.hpp"

class C : public Base
{
public:
//	canonic form:
	C();
	~C();
	C(const C &other);
	C &operator=(const C &other);
};

#endif
