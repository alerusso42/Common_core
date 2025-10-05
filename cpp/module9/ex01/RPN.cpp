/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:27:25 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/05 19:28:12 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

static void		parsing(std::string &expr);
static void		operate(std::stack<int32_t>	&stack, int8_t op, int32_t pos);
static void		pop_two(std::stack<int32_t> &stack, int32_t *n1, int32_t *n2);
static int32_t	safe_div(int32_t n1, int32_t n2, int32_t pos);

int32_t	rpn(std::string expr)
{
	std::stack<int32_t>	stack;

	parsing(expr);
	for (typename std::string::iterator i = expr.begin(); i != expr.end(); i++)
	{
		if (std::isdigit(*i))
			stack.push(*i - '0');
		else if (*i != ' ')
			operate(stack, *i, i - expr.begin());
	}
	if (stack.empty() == true)
		throw (Error(EX_EMPTY_STACK));
	else
		return (stack.top());
}

static void	parsing(std::string &expr)
{
	for (typename std::string::iterator i = expr.begin(); i != expr.end(); i++)
	{
		if (std::strchr(RPN_CHARS, *i) == NULL)
			throw (Error(EX_INVALID_CHAR, 0, *i));
	}
}

static void	operate(std::stack<int32_t>	&stack, int8_t op, int32_t pos)
{
	int32_t	n1;
	int32_t	n2;

	pop_two(stack, &n1, &n2);
	switch (op)
	{
		case ('+') :
			return (stack.push(n1 + n2));
		case ('-') :
			return (stack.push(n1 - n2));
		case ('*') :
			return (stack.push(n1 * n2));
		case ('/') :
			return (stack.push(safe_div(n1, n2, pos)));
	}
}

static void	pop_two(std::stack<int32_t> &stack, int32_t *n1, int32_t *n2)
{
	if (stack.empty() == true)
		throw (Error(EX_EMPTY_STACK));
	*n2 = stack.top();
	stack.pop();
	if (stack.empty() == true)
		throw (Error(EX_EMPTY_STACK));
	*n1 = stack.top();
	stack.pop();
}

static int32_t	safe_div(int32_t n1, int32_t n2, int32_t pos)
{
	if (n2 == 0)
		throw (Error(EX_DIVISION, 0, pos));
	return (n1 / n2);
}
