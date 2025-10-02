/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:28:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/18 16:28:32 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : grade_sign(LOWEST_GRADE), grade_exec(LOWEST_GRADE), \
name(rand_name())
{
	this->sign = false;
}

AForm::AForm(int sign, int exec) : grade_sign(sign), grade_exec(exec), \
name(rand_name())
{
	this->sign = false;
	if (exec <= 0 || sign <= 0)
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

AForm::~AForm()
{}

AForm::AForm(const AForm &other) : grade_sign(LOWEST_GRADE), grade_exec(LOWEST_GRADE), \
name(rand_name())
{
	this->sign = other.sign;
	(void)other;
}

AForm &AForm::operator=(const AForm &other)
{
	this->sign = other.sign;
	return *this;
}

std::string	 AForm::rand_name()
{
	std::string	 name;
	std::string	 temp;

	name.append("FORM_");
	for (int i = 0; i < 3; i++)
	{
		temp = (char)((std::rand() % 255) % 26 + 'a');
		name.append(temp);
	}
	for (int i = 0; i < 3; i++)
	{
		temp = (char)((std::rand() % 255) % 10 + '0');
		name.append(temp);
	}
	return (name);
}

void	AForm::check_grade(int grade)
{
	if (grade > LOWEST_GRADE)
		this->GradeTooLowException();
	else if (grade <= 0)
		this->GradeTooHighException();
}

void	AForm::GradeTooHighException(void) const
{
	throw (Error(EX_GRADE_HIGH));
}

void	AForm::GradeTooLowException(void) const
{
	throw (Error(EX_GRADE_LOW));
}

const std::string	 &AForm::getName(void) const
{
	return (this->name);
}

int	AForm::getGradeExec(void) const
{
	return (this->grade_exec);
}

int	AForm::getGradeSign(void) const
{
	return (this->grade_sign);
}

int	AForm::beSigned(Bureaucrat &Bureaucrat)
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

void	AForm::beExec(const Bureaucrat &Bureaucrat) const
{
	if (Bureaucrat.getGrade() > this->grade_exec)
		this->GradeTooLowException();
	if (this->sign == false)
		throw Error(EX_NOT_SIGN);
}
