/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:56:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/21 22:45:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define  INTERN_HPP

# include "AForm.hpp"
# include "header.hpp"

class	PresidentialPardonForm;
class	RobotomyRequestForm;
class	ShrubberyCreationForm;
class	Intern;

typedef AForm	*(Intern::*forms_list)(string const &);

class Intern
{
private:
	string		*types_allowed;
	forms_list	*forms;
	void		types_get(void);
	int			type_num;
public:
	Intern();
	~Intern();
	Intern(const Intern &other);
	Intern	&operator=(const Intern &other);

	AForm	*makeForm(string type, string target);
	AForm	*makePresidentialPardon(string const &);
	AForm	*makeRobotomyRequest(string const &);
	AForm	*makeShrubberyCreation(string const &);
	AForm	*makeNothing(string const &);
};

#endif