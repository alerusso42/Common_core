/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:29:46 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/21 18:29:46 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "lib/lib.hpp"
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	string	target;
public:
//	canonic form:
	RobotomyRequestForm(const string &s);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	int	execute(const Bureaucrat &executor) const;
};

#endif
