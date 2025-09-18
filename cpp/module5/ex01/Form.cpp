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

#include "Form.hpp"

Form::Form() : grade_exec(LOWEST_GRADE), grade_sign(LOWEST_GRADE)
{}

Form::Form(int exec, int sign) : grade_exec(exec), grade_sign(sign)
{}

Form::~Form()
{}

Form::Form(const Form &other) : grade_exec(LOWEST_GRADE), grade_sign(LOWEST_GRADE)
{
	(void)other;
}

Form &Form::operator=(const Form &other)
{
	(void)other;
	return *this;
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
