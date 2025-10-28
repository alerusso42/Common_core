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

int main() 
{
	Intern someRandomIntern;
	AForm *rrf;

	std::srand(random_gen());
	rrf = someRandomIntern.makeForm("residential pardon", "Bender");
	if (!rrf)
		return (print_error("Form does not exist."), 1);
	Bureaucrat	b("Mega Rayquaza", 1);
	b.signForm(*rrf);
	rrf->execute(b);
	delete rrf;
	return (0);
}

int	main2()
{
	Intern 		someRandomIntern;
	Bureaucrat	er_gabibbo(120, "ER GABIBBO");
	AForm* 		rrf;

	std::srand(random_gen());
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (!rrf)
		return (std::cerr << "\033[31mForm does not exist.\033[0m" << std::endl, 1);
	er_gabibbo.signForm(*rrf);
	er_gabibbo.executeForm(*rrf);
	delete rrf;
	return (0);
}