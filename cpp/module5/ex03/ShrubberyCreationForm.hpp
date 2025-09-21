/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:29:46 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/21 18:29:46 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "lib/lib.hpp"
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	string	target;
public:
//	canonic form:
	ShrubberyCreationForm(const string &s);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	void	execute(const Bureaucrat &executor) const;
};

# define TREE "\
                                                           \n\
                                                           \n\
                          /||\\                            \n\
                         / || \\                           \n\
                        /  ||  \\                          \n\
                       /   ||   \\                         \n\
                      /    ||    \\                        \n\
                     /     ||     \\                       \n\
                    /      ||      \\                      \n\
                   /       ||       \\                     \n\
                  /        ||        \\                    \n\
                 /         ||         \\                   \n\
                /          ||          \\                  \n\
               /           ||           \\                 \n\
              /            ||            \\                \n\
             /             ||             \\               \n\
            /              ||              \\              \n\
           /               ||               \\             \n\
          /                ||                \\            \n\
         /                 ||                 \\           \n\
        /__________________||_________________ \\          \n\
                           ||                              \n\
                           ||                              \n\
                           ||                              \n\
                           ||                              \n\
                           ||                               "

#endif
