/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:28:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/18 16:28:32 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : grade_exec(LOWEST_GRADE), grade_sign(LOWEST_GRADE), \
name(rand_name())
{
	this->sign = false;
}

Form::Form(int exec, int sign) : grade_exec(exec), grade_sign(sign), \
name(rand_name())
{
	this->sign = false;
	if (exec < 0 || sign < 0)
	{
		std::cerr << "\033[31mBad form: grade too high."; 
		std:: cerr << "\nCatch this, or die." << std::endl;
		this->GradeTooHighException();
	}
	else if (exec > LOWEST_GRADE || sign > LOWEST_GRADE)
	{
		std::cerr << "\033[31mBad form: grade too low."; 
		std:: cerr << "\nCatch this, or die." << std::endl;
		this->GradeTooLowException();
	}
}

Form::~Form()
{}

Form::Form(const Form &other) : grade_exec(LOWEST_GRADE), grade_sign(LOWEST_GRADE), \
name(rand_name())
{
	this->sign = other.sign;
	(void)other;
}

Form &Form::operator=(const Form &other)
{
	this->sign = other.sign;
	return *this;
}

string	Form::rand_name()
{
	string	name;

	for (int i = 0; i < 7; i++)
		name.append() = ((char)(std::rand() % 255));
	return (name);
}

void	Form::check_grade(int grade)
{
	if (grade > LOWEST_GRADE)
		this->GradeTooLowException();
	else if (grade <= 0)
		this->GradeTooHighException();
}

void	Form::GradeTooHighException(void)
{
	throw (Error(EX_GRADE_HIGH));
}

void	Form::GradeTooLowException(void)
{
	throw (Error(EX_GRADE_LOW));
}

const string	&Form::getName(void)
{
	return (this->name);
}

int	Form::beSigned(Bureaucrat &Bureaucrat)
{
	if (this->sign)
		return (F_ALREADY_SIGN);
	if (Bureaucrat.getGrade() > Bureaucrat.getLowestGrade())
		return (F_BAD_BUREAUCRAT);
	if (Bureaucrat.getGrade() > this->grade_sign)
		this->GradeTooLowException();
	this->sign = true;
	return (0);
	
}
