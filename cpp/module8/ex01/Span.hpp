/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:15:21 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/30 10:15:21 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include "lib/lib.hpp"
# include "limits.h"
# include "vector"
# include "list"
# include "algorithm"

class Span
{
private:
	u_int32_t			_size;
	u_int32_t			_capacity;
	std::vector<int>	_data;
	enum e_Span
	{
		SPAN_MAXSIZE = (u_int32_t)1e8,
	};
public:
//	canonic form:
	Span();
	Span(u_int32_t capacity);
	~Span();
	Span(const Span &other);
	Span &operator=(const Span &other);

	void	addNumber(void);
	void	addNumber(int number);
	void	print(void) const;
	int		shortestSpan(void);
	int		longestSpan(void);
	void	generate(void);
};

#endif
