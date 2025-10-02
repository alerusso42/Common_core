/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:05:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/16 15:05:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("giorgio")
{
	this->grade = this->LOWEST_GRADE;
}

Bureaucrat::Bureaucrat(std::string name) : name(name)
{
	this->grade = this->LOWEST_GRADE;
}

Bureaucrat::Bureaucrat(int grade) : name("giorgio")
{
	this->grade = grade;
	check_grade();
}

Bureaucrat::Bureaucrat(int grade, std::string name) : name(name)
{
	this->grade = grade;
	check_grade();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	this->grade = grade;
	check_grade();
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{ 
	this->grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other) 
	{
		this->grade = other.grade;
	}
	return *this;
}

void	Bureaucrat::increment(void)
{
	this->grade--;
	check_grade();
}

void	Bureaucrat::decrement(void)
{
	this->grade++;
	check_grade();
}

void	Bureaucrat::check_grade()
{
	if (this->grade > LOWEST_GRADE)
		this->GradeTooLowException();
	else if (this->grade <= 0)
		this->GradeTooHighException();
}

const std::string	 Bureaucrat::getName(void) const
{
	return (this->name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

int	Bureaucrat::getLowestGrade(void) const
{
	return (this->LOWEST_GRADE);
}

std::ostream&	operator<<(std::ostream& fd, const Bureaucrat &b)
{
	fd << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (fd);
}

void	Bureaucrat::GradeTooHighException(void)
{
	throw (Error(EX_GRADE_HIGH));
}

void	Bureaucrat::GradeTooLowException(void)
{
	throw (Error(EX_GRADE_LOW));
}
