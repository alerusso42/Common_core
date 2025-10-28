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

enum e_failures
{
	F_CORRECT,
	F_ALREADY_SIGN,
	F_BAD_BUREAUCRAT,
	F_GRADE_LOW,
};

class Form
{
private:
	enum e_form
	{
		LOWEST_GRADE = 150,
	};
	bool			sign;
	const int		grade_exec;
	const int		grade_sign;
	const std::string	 name;

	void			GradeTooHighException(void);
	void			GradeTooLowException(void);
	void			check_grade(int grade);
	std::string	 	rand_name(void);
public:
//	canonic form:
	Form();
	Form(int exec, int sign);
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);

	bool				getSign(void) const;
	int					getGradeExec(void) const;
	int					getGradeSign(void) const;
	const std::string	&getName(void);
	int					beSigned(Bureaucrat &Bureaucrat);
};

std::ostream	&operator<<(std::ostream &stream, Form &form);

#endif
