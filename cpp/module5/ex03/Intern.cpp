/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:56:13 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/28 14:20:08 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

typedef AForm	*(Intern::*forms_list)(std::string const &);

Intern::Intern()
{
	this->type_num = 0;
	this->types_get();
	this->forms = new forms_list[this->type_num + 1];
	this->forms[0] = &Intern::makePresidentialPardon;
	this->forms[1] = &Intern::makeRobotomyRequest;
	this->forms[2] = &Intern::makeShrubberyCreation;
	this->forms[3] = &Intern::makeNothing;
}

Intern::~Intern()
{
	delete [] (this->forms);
	delete [] (this->types_allowed);
}

Intern::Intern(const Intern &other)
{
	this->type_num = other.type_num;
	this->types_allowed = new std::string[this->type_num];
	this->forms = new forms_list[this->type_num + 1];
	for (int i = 0; i < this->type_num; i++)
	{
		this->types_allowed[i] = other.types_allowed[i];
		this->forms[i] = other.forms[i];
	}
}

Intern	&Intern::operator=(const Intern &other)
{
	if (this == &other)
		return (*this);
	this->type_num = other.type_num;
	this->types_allowed = new string[this->type_num + 1];
	this->forms = new forms_list[this->type_num + 1];
	for (int i = 0; i < this->type_num; i++)
	{
		this->types_allowed[i] = other.types_allowed[i];
		this->forms[i] = other.forms[i];
	}
	return (*this);
}

AForm	*Intern::makeForm(std::string type, std::string target)
{
	int	i;

	i = 0;
	while (i < this->type_num)
	{
		if (type.compare(this->types_allowed[i]) == 0)
			return ((this->*forms[i])(target));
		++i;
	}
	return ((this->*forms[i])(target));
}

void	Intern::types_get(void)
{
	if (this->type_num != 0)
		return ;
	std::string	 types[] = {FORM_NAMES};
	int		i;

	i = 0;
	while (!types[i].empty())
		++i;
	this->type_num = i;
	this->types_allowed = new std::string[this->type_num + 1];
	i = 0;
	while (!types[i].empty())
	{
		this->types_allowed[i] = types[i];
		++i;
	}
}

AForm	*Intern::makePresidentialPardon(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeRobotomyRequest(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makeShrubberyCreation(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeNothing(std::string const &target)
{
	(void)target;
	return (NULL);
}
