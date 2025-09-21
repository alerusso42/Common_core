/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:56:13 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/21 22:44:44 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

typedef AForm	*(Intern::*forms_list)(string const &);

Intern::Intern()
{
	this->type_num = 0;
	this->types_get();
	this->forms = new forms_list[this->type_num];
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
	this->types_allowed = new string[this->type_num];
	this->forms = new forms_list[this->type_num];
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
	this->types_allowed = new string[this->type_num];
	this->forms = new forms_list[this->type_num];
	for (int i = 0; i < this->type_num; i++)
	{
		this->types_allowed[i] = other.types_allowed[i];
		this->forms[i] = other.forms[i];
	}
	return (*this);
}

AForm	*Intern::makeForm(string type, string target)
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
	string	types[] = {FORM_NAMES};
	int		i;

	while (types[i].empty())
		++i;
	this->type_num = i + 1;
	this->types_allowed = new string[this->type_num];
	i = 0;
	while (types[i].empty())
	{
		this->types_allowed[i] = types[i];
		++i;
	}
}

AForm	*Intern::makePresidentialPardon(string const &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeRobotomyRequest(string const &target)
{
	AForm	*ptr;

	std::cout << "entro..." << std::endl;
	ptr = new RobotomyRequestForm(target);
	return (ptr);
}

AForm	*Intern::makeShrubberyCreation(string const &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeNothing(string const &target)
{
	(void)target;
	return (NULL);
}
