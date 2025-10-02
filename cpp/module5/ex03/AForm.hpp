/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:28:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/18 16:28:32 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
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
};

class AForm
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
protected:
	int				getGradeExec(void) const;
	int				getGradeSign(void) const;
public:
//	canonic form:
	AForm();
	AForm(int sign, int exec);
	virtual	~AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);

	const std::string	 &getName(void) const;
	int				beSigned(Bureaucrat &Bureaucrat);
	void			beExec(const Bureaucrat &Bureaucrat) const;
	virtual int		execute(Bureaucrat const &executor) const = 0;
};

#endif