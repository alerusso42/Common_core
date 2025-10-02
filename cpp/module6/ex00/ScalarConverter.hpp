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
# include "cfloat"

# define SPECIAL "OK", "inff", "-inff", "+inff", "nanf", "inf", \
"-inf", "+inf", "nan", ""

enum	e_types
{
	T_CHAR,
	T_INT,
	T_FLOAT,
	T_DOUBLE,
	T_OVERFLOW,
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
	S_HALF = S_TOTAL / 2,
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
	static void		convert(std::string literal);
};

//SECTION ScalarConverter.cpp

int		special_cases(std::string s);
int		find_type(std::string s, int special_case);

//SECTION overflow.cpp

bool	float_out_of_range(double n);
int		overflow_check(std::string s);

//SECTION utils.cpp

bool	ft_strchr(std::string s, std::string charset);
int		ft_isdigit(char c);
std::string	 put_dot(int type, bool f);
bool	decimal_not_zero(std::string s);

//SECTION convert.cpp

void	convert_char(double n, int special_case, int type);
void	convert_int(double n, int special_case, int type);
void	convert_float(double n, int special_case, int type);
void	convert_double(double n, int special_case, int type);
void	convert_special(int special_case);

#endif
