/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:28:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/18 16:28:32 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "lib/lib.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	enum e_form
	{
		LOWEST_GRADE = 150,
	};
	const string	name;
	bool			sign;
	const int		grade_exec;
	const int		grade_sign;
	void			GradeTooHighException(void);
	void			GradeTooLowException(void);
	void			check_grade(int grade);
public:
//	canonic form:
	Form();
	Form(int exec, int sign);
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);

	enum e_failures
	{
		F_CORRECT,
		F_ALREADY_SIGN,
		F_BAD_BUREAUCRAT,
		F_GRADE_LOW,
	};
	const string	&getName(void);
	int				beSigned(Bureaucrat &Bureaucrat);
};

#endif
