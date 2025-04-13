#include "test.h"

//SECTION - RWFromFile
/*
Available mode strings:

"r":	Open a file for reading. The file must exist.
"w":	Create an empty file for writing. If a file with
		the same name already exists its content is 
		erased and the file is treated as a new empty file.
"a":	Append to a file. Writing operations append data 
		at the end of the file. The file is created if it does not exist.
"r+":	Open a file for update both reading and writing. The file must exist.
"w+":	Ceate an empty file for both reading and writing. 
		If a file with the same name already exists its content is erased 
		and the file is treated as a new empty file.
"a+":	Open a file for reading and appending. 
		All writing operations are performed at the end of the file, 
		protecting the previous content to be overwritten. 
		You can reposition (fseek, rewind) the internal pointer to anywhere
		in the file for reading, but writing operations will move it back
		to the end of file. The file is created if it does not exist.
"b":	In order to open a file as a binary file, 
		a "b" character has to be included in the mode string. 
		This additional "b" character can either be appended 
		at the end of the string 
		(thus making the following compound modes: 
		"rb", "wb", "ab", "r+b", "w+b", "a+b")
		or be inserted between the letter and the "+" sign 
		for the mixed modes ("rb+", "wb+", "ab+"). 
		Additional characters may follow the sequence, 
		although they should have no effect. 
		For example, "t" is sometimes appended 
		to make explicit the file is a text file.
*/
#define POKEDEX "/workspaces/Common_core/getnextline/updated_pokedex.txt"
int	main(void)
{
	SDL_RWops		*fd;
	unsigned char	*str;
	int				size;
	int				i;

	fd = SDL_RWFromFile(POKEDEX, "a+");
	if (!fd)
		return (1);
	size = 100;
	str = SDL_malloc(size);
	if (!str)
		return (2);
	i = 0;
	while (i++ != size)
		str[i] = SDL_ReadU8(fd);
	SDL_RWclose(fd);
	str[i] = 0;
	i = 0;
	while (str[i])
		SDL_RWwrite();
}