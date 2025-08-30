/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/30 12:34:17 by alerusso         ###   ########.fr       */
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
	std::fstream	fd;

	if (argc != 4)
		return (std::cout << USAGE, 1);
	if (!valid_input(argv[1]) || !valid_input(argv[2]) || !valid_input(argv[3]))
		return (std::cout << USAGE, 1);
	fd.open(argv[1], std::ios::in);
	if (fd.fail())
		return (std::cout << "cannot open " << argv[1] << std::endl, 2);
	fd.close();
}