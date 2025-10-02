/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:56:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 14:35:07 by alerusso         ###   ########.fr       */
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

typedef AForm	*(Intern::*forms_list)(std::string const &);

class Intern
{
private:
	std::string	 	*types_allowed;
	forms_list	*forms;
	void		types_get(void);
	int			type_num;
public:
	Intern();
	~Intern();
	Intern(const Intern &other);
	Intern	&operator=(const Intern &other);

	AForm	*makeForm(std::string type, std::string target);
	AForm	*makePresidentialPardon(std::string const &);
	AForm	*makeRobotomyRequest(std::string const &);
	AForm	*makeShrubberyCreation(std::string const &);
	AForm	*makeNothing(std::string const &);
};

#endif