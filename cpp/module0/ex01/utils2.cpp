/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:18:57 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/17 10:52:46 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	print_line(int len);
static void	print_one(string s);
static void	print_entries_name(void);

/*
//REVIEW - print_phonebook

For every contact not empty in the phonebook:

1)	print an horizontal line.
	line_size is the lenght of every entry plus the separators '|';
2)	print every field in the contact, separated to the other by a '|';
3)	print a '\n' before next contact;
4)	print an horizontal line to close the table.
*/
void	print_phonebook(PhoneBook *phone)
{
	int	i;
	int	j;

	i = 0;
	print_entries_name();
	while (i != PHONE_SIZE && phone->get_contacts()[i].empty() == false)
	{
		print_line((FIELD_SIZE + 1) * ENTRY_NUM);
		j = 0;
		std::cout << "|";
		print_one(ft_itoa(i));
		while (j < ENTRY_NUM - 1)
		{
			std::cout << "|";
			print_one(*phone->get_contacts()[i].get_list()[j]);
			++j;
		}
		std::cout << "|";
		std::cout << std::endl;
		i++;
	}
	print_line((FIELD_SIZE + 1) * ENTRY_NUM);
}

static void	print_entries_name(void)
{
	const char	*entries[] = {
	"Index",
	"First_name",
	"Last_name",
	"Nickname",
	NULL
};
	int			i;
	string		s;

	i = 0;
	while (entries[i])
	{
		std::cout << "|";
		s.clear();
		s += entries[i];
		print_one(s);
		++i;
	}
	std::cout << "|\n";
}

static void	print_line(int len)
{
	int		i;

	i = 0;
	while (i != len)
	{
		std::cout << "_";
		++i;
	}
	std::cout << std::endl << std::endl;
}

//	If the string surpasses FIELD_SIZE, last character is set to '.'
static void	print_one(string s)
{
	int	spaces;

	spaces = FIELD_SIZE - s.size();
	if (spaces < 0)
	{
		std::cout << s.substr(0, FIELD_SIZE - 1) << ".";
	}
	else
	{
		while (spaces > 0)
		{
			std::cout << " ";
			--spaces;
		}
		std::cout << s;
	}
}

void	print_guide(void)
{
	std::cout << "\033[1;32mWelcome to PhoneBook! Commands:";
	std::cout << "\nEXIT:\tStop program, clear the Phone forever"; 
	std::cout << "\nADD:\tAdd a new contact to the phone. Please fill every";
	std::cout << " field!";
	std::cout << "\nSEARCH:\tPrints all phonebook, then asks for the index of";
	std::cout << " the contact to print. The index is the saving order.";
	std::cout << " If number of contacts surpasses " << PHONE_SIZE << ", ";
	std::cout << "then first contact gets replaced.\nHave fun!\n\033[0m";
}
