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
#include "AForm.hpp"

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
	this->grade = other.grade;
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
	fd << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
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

void	Bureaucrat::check_grade()
{
	if (this->grade > LOWEST_GRADE)
		this->GradeTooLowException();
	else if (this->grade <= 0)
		this->GradeTooHighException();
}

int	Bureaucrat::signForm(AForm &form)
{
	int	exit_code = 0;

	try
	{
		exit_code = form.beSigned(*this);
	}
	catch(const Error& e)
	{
		e.print();
		exit_code = F_GRADE_LOW;
	}
	if (exit_code == F_CORRECT)
		std::cout << this->name << " signed " << form.getName() << std::endl;
	else
		this->print_form_error(form, exit_code);
	return (exit_code);
}

void	Bureaucrat::executeForm(AForm const & form)
{
	if (!form.execute(*this))
		std::cout << this->name << " executed " << form.getName() << std::endl;
}

void	Bureaucrat::print_form_error(AForm &form, int error)
{
	std::cout << this->name << " couldn’t sign ";
	std::cout << form.getName() << " because ";
	switch (error)
	{
		case (F_ALREADY_SIGN) :
		{
			std::cout << "is already sign";
			break ;
		}
		case (F_BAD_BUREAUCRAT) :
		{
			std::cout << "is invalid";
			break ;
		}
		case (F_GRADE_LOW) :
		{
			std::cout << "is too weak";
			break ;
		}
	}
	std::cout << std::endl;
}

void	Bureaucrat::GradeTooHighException(void)
{
	this->grade = 1;
	throw (Error(EX_GRADE_HIGH));
}

void	Bureaucrat::GradeTooLowException(void)
{
	this->grade = this->LOWEST_GRADE;
	throw (Error(EX_GRADE_LOW));
}
