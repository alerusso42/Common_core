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
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("giorgio")
{
	this->grade = this->LOWEST_GRADE;
}

Bureaucrat::Bureaucrat(string name) : name(name)
{
	this->grade = this->LOWEST_GRADE;
}

Bureaucrat::Bureaucrat(int grade) : name("giorgio")
{
	this->grade = grade;
	check_grade();
}

Bureaucrat::Bureaucrat(int grade, string name) : name(name)
{
	this->grade = grade;
	check_grade();
}

Bureaucrat::Bureaucrat(string name, int grade) : name(name)
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

std::ostream&	operator<<(std::ostream& fd, const Bureaucrat &b)
{
	fd << b->name << ", bureaucrat grade " << b->grade << std::endl;
	return (fd);
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

const string	Bureaucrat::getName(void) const
{
	return (this->name);
}

int	Bureaucrat::getGrade(void)
{
	return (this->grade);
}

int	Bureaucrat::getLowestGrade(void)
{
	return (this->LOWEST_GRADE);
}

void	Bureaucrat::check_grade()
{
	if (this->grade > LOWEST_GRADE)
		this->GradeTooLowException();
	else if (this->grade <= 0)
		this->GradeTooHighException();
}

int	Bureaucrat::signForm(Form &form)
{
	int	exit_code = 0;

	try
	{
		exit_code = form.beSigned(*this);
	}
	catch(const Error& e)
	{
		e.print();
		return (form.F_GRADE_LOW);
	}
	if (exit_code == form.F_CORRECT)
		std::cout << this->name << " signed " << form.getName() << std::endl;
	else
		this->print_form_error(form, exit_code);
	return (exit_code);
	
}

void	Bureaucrat::print_form_error(Form &form, int error)
{
	std::cout << this->name << " couldn’t sign ";
	std::cout << form.getName() << "because ";
	switch (error)
	{
		case (form.F_ALREADY_SIGN) :
		{
			std::cout << "is already sign";
			break ;
		}
		case (form.F_BAD_BUREAUCRAT) :
		{
			std::cout << "bureaucrat is invalid";
			break ;
		}
	}
	std::cout << std::endl;
}

void	Bureaucrat::GradeTooHighException(void)
{
	throw (Error(EX_GRADE_HIGH));
}

void	Bureaucrat::GradeTooLowException(void)
{
	throw (Error(EX_GRADE_LOW));
}
