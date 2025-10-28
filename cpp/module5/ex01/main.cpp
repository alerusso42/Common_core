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

//SECTION -	decrementing bureaucrat
int TEST1main()
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

//SECTION -	bad form
int TEST2main()
{
	try
	{
		Form f1(0, 12);
	}
	catch(const Error& e)
	{
		e.print();
	}
	return (0);
}

//SECTION -	form too strong
int TEST3main()
{
	Bureaucrat	b(124);
	Form 		f1(42, 42);

	try
	{
		f1.beSigned(b);
	}
	catch(const Error& e)
	{
		e.print();
	}
	return (0);
}

//SECTION -	bureaucrat not strong enough
int main()
{
	Bureaucrat	b(124);
	Form 		f1(42, 42);

	Bureaucrat	b1(43, "GOKU SUPER SAIYAN 104");
	b.signForm(f1);
	b1.signForm(f1);
	return (0);
}
