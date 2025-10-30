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

# define FORM_NAMES "presidential pardon", "robotomy request", \
					"shrubbery creation", ""

class Bureaucrat;

enum e_failures
{
	F_CORRECT,
	F_ALREADY_SIGN,
	F_BAD_BUREAUCRAT,
	F_GRADE_LOW,
	F_BAD_FORM,
};

class Form
{
private:
	enum e_form
	{
		LOWEST_GRADE = 150,
	};
	bool			sign;
	const int		grade_sign;
	const int		grade_exec;
	const std::string	 name;
	void			GradeTooHighException(void) const;
	void			GradeTooLowException(void) const;
	void			check_grade(int grade);
	std::string	 		rand_name(void);
public:
//	canonic form:
	Form();
	Form(int sign, int exec);
	virtual	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);

	const std::string	&getName(void) const;
	int					getSign(void) const;
	int					getGradeExec(void) const;
	int					getGradeSign(void) const;

	int					beSigned(Bureaucrat &Bureaucrat);
	void				beExec(const Bureaucrat &Bureaucrat) const;
	virtual int			execute(Bureaucrat const &executor) const = 0;
};

std::ostream	&operator<<(std::ostream &stream, Form &form);

#endif