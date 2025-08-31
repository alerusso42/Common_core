/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/31 14:49:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

/*

	source: https://www.cs.uic.edu/~jbell/CourseNotes/CPlus/FileIO.html

					ios_base	(flag, robe interne classe)
						|
						|
						ios		(gestione buffer)
						|
						|
					iostream	(input, output)
						|
						|
				_____________________
				|					|
			istream				ostream
				|					|
				|					|
(INPUT FILE) ifstream			ofstream (OUTPUT FILE)
				|					|
				|					|
				-------fstream-------
				(input + output file)
				
1	
ofstream O_WRONLY

This data type represents the output file stream 
and is used to create files and to write 
information to files.

2	
ifstream O_RDONLY

This data type represents the input file stream 
and is used to read information from files.

3	
fstream O_RDWR

This data type represents the file stream generally, 
and has the capabilities of both ofstream and 
ifstream which means it can create files, 
write information to files, and read information 
from files.
std::ios::in → lettura

std::ios::out → scrittura

std::ios::app → append

std::ios::trunc → tronca a zero

std::ios::binary → modalità binaria
*/
# include <fstream>

int	main(int argc, char *argv[])
{
	std::fstream	old_fd;
	std::fstream	new_fd;
	string			new_file;

	if (argc != 4)
		return (std::cout << USAGE, 1);
	return (sed(argv[1], argv[2], argv[3]));
}

static int	sed_parsing(string filename, string to_replace, string replacer);
static int	replace(fstream old_fd, fstream new_fd, string old_s, string new_s);

int	sed_parsing(string filename, string to_replace, string replacer)
{
	if (!valid_input(filename) || !valid_input(to_replace))
		return (false);
	if (replacer.size() >= 1000)
		return (false);
	if (check_str(replacer, std::isprint, true) == false)
		return (false);
	return (true);
}

int	sed(string filename, string to_replace, string replacer)
{
	std::fstream	old_fd;
	std::fstream	new_fd;
	string			new_file;
	int				exit_code;

	if (sed_parsing(filename, to_replace, replacer) == false)
		return (1);
	old_fd.open(filename, std::ios::in);
	if (old_fd.fail())
		return (std::cerr << "cannot open " << filename << std::endl, 2);
	new_file = filename;
	new_file.append(".replace");
	new_fd.open(new_file, std::ios::out);
	if (new_fd.fail())
	{
		old_fd.close();
		return (std::cerr << "cannot open " << new_file << std::endl, 2);
	}
	exit_code = replace(old_fd, new_fd, to_replace, replacer);
	old_fd.close();
	new_fd.close();
	if (exit_code != 0)
		std::cerr << "replace failed." << std::endl;
	return (exit_code);
}

static int	replace(fstream old_fd, fstream new_fd, string old_s, string new_s)
{
	string	line;
	int		i;

	while (old_fd.tellg() < old_fd.eof() && !old_fd.fail() && new_fd.fail())
	{
		old_fd.getline(line, line.max_size());
		if (valid_input(line) == false)
			return (1);
		line_replace(line, old_s, new_s);
		new_fd.write(line.c_str(), line.size());
	}
}