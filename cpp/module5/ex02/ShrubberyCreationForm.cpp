/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:29:46 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/21 18:29:46 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const string &s) : AForm(145, 137)
{
	this->target = s;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : \
AForm(other.getGradeSign(), other.getGradeExec())
{
	this->target = other.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	this->target = other.target;
	return (*this);
}

int	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	fstream	stream;
	string	filename;

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
	filename.append(this->target).append("_shrubbery");
	stream.open(filename.c_str(), std::ios::app);
	if (stream.fail())
		return (0);
	stream << "\nTree made with love by " << executor.getName();
	stream << "\n" TREE << std::endl;
	stream.close();
	std::cout << "WOW! " << executor.getName() << " Made an amazing tree!";
	std::cout << std::endl;
	return (0);
}