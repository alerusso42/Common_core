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

typedef std::string	 	 string;

class Bureaucrat
{
private:
	enum e_bureaucrat
	{
		LOWEST_GRADE = 150,
	};
	const std::string	 name;
	int				grade;
public:
//	canonic form:
	Bureaucrat();
	Bureaucrat(std::string name);
	Bureaucrat(int grade);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(int grade, std::string name);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);

	const std::string	 getName(void) const;
	int				getGrade(void) const;
	int				getLowestGrade(void) const;
	void			increment(void);
	void			decrement(void);
	void			check_grade(void);
	void			GradeTooHighException(void);
	void			GradeTooLowException(void);
};

std::ostream&	operator<<(std::ostream& fd, const Bureaucrat &b);

#endif