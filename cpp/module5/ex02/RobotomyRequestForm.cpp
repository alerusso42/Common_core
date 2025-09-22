/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:29:46 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/21 18:29:46 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const string &s) : AForm(72, 45)
{
	this->target = s;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : \
AForm(other.getGradeSign(), other.getGradeExec())
{
	this->target = other.target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	this->target = other.target;
	return (*this);
}

int	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	try
	{
		this->beExec(executor);
	}
	catch(const Error& e)
	{
		e.print();
		std::cout << executor.getName() << " cannot exec " << this->getName();
		std::cout << std::endl;
		return (1);
	}
	std::cout << "Drill sound\n";
	if (std::rand() % 2)
		std::cout << this->target << " has been robotomized successfully.";
	else
		std::cout << "\033[33m robotomization failed...\033[0m";
	std::cout << std::endl;
	return (0);
}
