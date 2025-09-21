/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:29:46 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/21 18:29:46 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

/*
	SIGN	25;	EXEC	5	
*/
int main() 
{
	Bureaucrat	b("Mega Rayquaza", 150);
	AForm	*f1 = new PresidentialPardonForm("Gabibbo");

	std::srand(random_gen());
	b.signForm(*f1);
	f1->execute(b);
	delete f1;
	return 0;
}

/*
	SIGN	72;	EXEC	45	
*/
int TEST2main() 
{
	Bureaucrat	b("Mega Rayquaza", 1);
	AForm	*f1 = new RobotomyRequestForm("Ezio Greggio");

	std::srand(random_gen());
	b.signForm(*f1);
	f1->execute(b);
	delete f1;
	return 0;
}

/*
	SIGN	145;	EXEC	137	
*/
int TEST3main() 
{
	Bureaucrat	b("Mega Rayquaza", 1);
	AForm	*f1 = new ShrubberyCreationForm("Gerry Scotti");

	std::srand(random_gen());
	b.signForm(*f1);
	f1->execute(b);
	delete f1;
	return 0;
}
