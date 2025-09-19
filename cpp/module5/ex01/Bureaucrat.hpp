/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 15:05:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/16 15:05:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <fstream>
# include <string>
# include <stdexcept>
# include <cstdlib>
# include "lib/lib.hpp"
# include "Form.hpp"

typedef std::string	string;

class Form;

class Bureaucrat
{
private:
	enum e_bureaucrat
	{
		LOWEST_GRADE = 150,
	};
	const string	name;
	int				grade;
	void			print_form_error(Form &form, int error);
public:
//	canonic form:
	Bureaucrat();
	Bureaucrat(string name);
	Bureaucrat(int grade);
	Bureaucrat(string name, int grade);
	Bureaucrat(int grade, string name);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);

	const string	getName(void) const;
	int				getGrade(void) const;
	int				getLowestGrade(void) const;
	void			increment(void);
	void			decrement(void);
	void			check_grade(void);
	int				signForm(Form &form);
	void			GradeTooHighException(void);
	void			GradeTooLowException(void);
};

std::ostream&	operator<<(std::ostream& fd, const Bureaucrat &b);

#endif
