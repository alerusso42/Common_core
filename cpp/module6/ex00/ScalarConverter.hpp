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

# define SPECIAL "OK", "inff", "-inff", "+inff", "nanf", "inf", \
"-inf", "+inf", "nan", ""

enum	e_types
{
	T_CHAR,
	T_INT,
	T_FLOAT,
	T_DOUBLE,
	T_TOTAL,
};

enum e_special
{
	S_INFF = 1,
	S_INFF_MINUS,
	S_INFF_PLUS,
	S_NANF,
	S_INF,
	S_INF_MINUS,
	S_INF_PLUS,
	S_NAN,
	S_TOTAL,
};

class ScalarConverter
{
private:
	//	canonic form:
	ScalarConverter();
	virtual ~ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
public:
	static void		convert(string literal);
};

int		special_cases(string s);
int		find_type(string s, int special_case);

void	convert_char(double n, int special_case, int type);
void	convert_int(double n, int special_case, int type);
void	convert_float(double n, int special_case, int type);
void	convert_double(double n, int special_case, int type);
double	convert_special(int special_case);

#endif
