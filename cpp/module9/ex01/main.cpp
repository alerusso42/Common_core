/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:25:40 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/05 18:25:40 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

/*REVIEW - RPN
	//SECTION - what this program does
	RPN stands for Reverse polish notation.
	It is used to solve arythmetical expressions.

	//SECTION - How does rpn works
	The expression is iterated from begin to end.
	When found a number: it is stored in a buffer.
	When found an operator: 
		1)	the last and last -1 are removed from buffer;
		2)	computation: last - 1 OPERATOR last;
		3)	result is stored at the end of the buffer.
	Example: 8 5 * 2 +
	0)	Buffer:	empty
	1)	Buffer:	8
	2)	Buffer:	8,5
	3)	Buffer:	40
	4)	Buffer:	40,2
	5)	Buffer:	42
	Lastly, Last element of buffer is returned.

	//SECTION - Resolution
	The algorythm is the same as explained before.
	As the buffer, a std::stack is used: it allows to
	access at the last element of the buffer with ease,
	and to remove elements (pop) with easy syntax.
*/
int main(int argc, char *argv[]) 
{
	if (argc != 2)
		return (print_error("Bad argc"), 1);
	else if (valid_input(argv[1]) == false)
		return (2);
	try
	{
		std::cout << rpn(argv[1]) << std::endl;
	}
	catch(const Error& e)
	{
		e.print();
	}
	return (0);
}
