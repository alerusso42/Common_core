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

int main2() 
{
	Intern someRandomIntern;
	AForm *rrf;

	std::srand(random_gen());
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	Bureaucrat	b("Mega Rayquaza", 25);
	b.signForm(*rrf);
	rrf->execute(b);
	delete rrf;
	return (0);
}

int	main()
{
	Intern someRandomIntern;
	AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (!rrf) { std::cerr << "Form not created\n"; return 1; }
	delete rrf;
	return (0);
}