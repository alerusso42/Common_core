/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 21:35:57 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/23 21:35:57 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include "lib/lib.hpp"
# include "limits.h"

# define SPECIAL "-inff", "+inff", "nanf", "-inf", "+inf", "nan", ""

class ScalarConverter
{
public:
//	canonic form:
	ScalarConverter();
	virtual ~ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);

	virtual	void	make_abstract(void)	const = 0;
	static void		convert(string literal);
};

bool	special_cases(string s);

#endif
