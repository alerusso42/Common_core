/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 09:12:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/17 11:20:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
# define ENTRY_NUM 4
# define PHONE_SIZE 8
# define FIELD_SIZE 10

typedef	std::string	string;

typedef class Contact
{
	private:
		string	*entry_list[ENTRY_NUM + 1];
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string	darkest_secret;
	public:
		Contact();
		~Contact();

		bool			empty() const;
		string			**get_list();
		const string	get_dark(void) const;
		void			add(void);
		bool			add_info(string *dest, string msg, bool numeric);
		void			reset_contact(void);
}	Contact;

# define INvalid_input_MSG "\033[1;31mBad value\n\033[0m"
# define EMPTY_CONTACTS_MSG "\033[1;32mNo contacts registered.\n\033[0m"
# define INVALID_SEARCH_MSG "\033[1;32mOut of range search.\n\033[0m"
# define MISSING_NUMBER_MSG "\033[1;32mContact does not exist.\n\033[0m"
# define ATOI_BAD_VALUE_MSG "\033[1;31mValue must be integer\n\033[0m"
