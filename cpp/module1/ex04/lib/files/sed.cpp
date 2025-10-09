/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 22:18:04 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/07 10:12:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	test for sed:
	.	...	.	..		.
	assurdo	assurdo	ass	assurdoa	assurd	assurdoaassurdoassurdo
*/

#include "../lib.hpp"
# define USAGE_SED "This program mimics sed. You must give 3 parameters:\n\
the filename;\n std::string to replace;\n replacement string\n"

static int	get_files(std::string &filename, std::fstream &old_fd, std::fstream &new_fd);
static void	line_replace(std::string &line, std::string &to_replace, std::string &replacer);
static int	sed_parsing(std::string &filename, std::string &to_replace, std::string &replacer);
static int	replace(std::fstream &old_fd, std::fstream &new_fd, std::string &old_s, std::string &new_s);

/*
	sed creates a new file, named filename.replace, in which every occurence of
	to_replace std::string are replaced with replacer string.

	returns 1 on error, 0 on correct execution.
*/
int	sed(std::string filename, std::string to_replace, std::string replacer)
{
	std::fstream	old_fd;
	std::fstream	new_fd;
	int		exit_code;

	if (sed_parsing(filename, to_replace, replacer) == 1)
		return (1);
	if (get_files(filename, old_fd, new_fd) == 1)
		return (1);
	exit_code = replace(old_fd, new_fd, to_replace, replacer);
	old_fd.close();
	new_fd.close();
	if (exit_code != 0)
		std::cerr << "replace failed." << std::endl;
	return (exit_code);
}

//	replacer can be empty.
static int	sed_parsing(std::string &filename, std::string &to_replace, std::string &replacer)
{
	if (!valid_input(filename) || !valid_input(to_replace))
		return (1);
	if (replacer.size() >= 1000)
		return (1);
	if (check_str(replacer, std::isprint, true, 0) == 1)
		return (1);
	return (0);
}

/*
std::ios::in → lettura

std::ios::out → scrittura

std::ios::app → append

std::ios::trunc → tronca a zero

std::ios::binary → modalità binaria
*/
static int	get_files(std::string &filename, std::fstream &old_fd, std::fstream &new_fd)
{
	std::string	 new_file;

	old_fd.open(filename.c_str(), std::ios::in);
	if (old_fd.fail())
		return (std::cerr << "cannot open " << filename << std::endl, 1);
	new_file = filename;
	new_file.append(".replace");
	new_fd.open(new_file.c_str(), std::ios::out | std::ios::trunc);
	if (new_fd.fail())
	{
		old_fd.close();
		return (std::cerr << "cannot open " << new_file << std::endl, 1);
	}
	return (0);
}

/*
	first, a std::string is read until \n.
	then, that std::string is first modified by line_replace, 
	then written on .replace file.
	
	this is done until eof.
*/
static int	replace(std::fstream &old_fd, std::fstream &new_fd, std::string &old_s, std::string &new_s)
{
	std::string	 line;
	bool	no_differencies;

	no_differencies = (old_s.compare(new_s) == 0);
	while (std::getline(old_fd, line))
	{
		if (no_differencies == false)
			line_replace(line, old_s, new_s);
		new_fd.write(line.c_str(), line.size());
		new_fd.write("\n", 1);
	}
	return (0);
}

/*
	erase it, insert it, find it.
	Until the end.
*/
static void	line_replace(std::string &line, std::string &to_replace, std::string &replacer)
{
	size_t	i;

	i = line.find(to_replace, 0);
	while (i != line.npos)
	{
		line.erase(i, to_replace.length());
		line.insert(i, replacer);
		i = line.find(to_replace, i);
	}
}
