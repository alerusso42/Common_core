/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:28:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/18 16:28:32 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

int main()
{
	Bureaucrat	b1(150);
	Bureaucrat	b2(1);

	std::srand(random_gen());
	try
	{
		b2.decrement();
	}
	catch(const Error &e)
	{
		e.print();
	}
	Form f1(90, 30);
	b2.signForm(f1);
	b1.signForm(f1);
	return (0);
}
