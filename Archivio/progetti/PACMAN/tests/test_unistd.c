#include "../includes/lib.h"

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
#define POKEDEX "../../../../getnextline/updated_pokedex.txt"
#define close CLOSE
#define free FREE
int	main2(void)
{
	SDL_RWops		*fd;
	unsigned char	*str;
	int				size;
	int				i;

	fd = OPEN(POKEDEX, "r");
	if (!fd)
		return (1);
	size = SDL_RWsize(fd);
	if (size <= 0)
		return (9);
	str = SDL_calloc(size + 1, sizeof(char));
	if (!str)
		return (2);
	if (READ(fd, str, sizeof(char), size) != size)
		return (FREE(str), CLOSE(fd), 7);
	CLOSE(fd);
	str[size] = 0;
	fd = OPEN("Outputt.txt", "w");
	if (!fd)
		return (9);
	WRITE(fd, str, sizeof(char), size);
	close(fd);
	free(str);
}

int	main(void)
{
	SDL_RWops		**fd;
	int				i;

	i = 0;
	fd = SDL_calloc(22, sizeof(SDL_RWops *));
	while (i != 20)
	{
		fd[i] = OPEN(POKEDEX, "r");
		printf("%d: %d\n", i, fd[i]->type);
		++i;
	}
	i = 0;
	while (i != 20)
		CLOSE(fd[i++]);
	FREE(fd);
	SDL_Quit();
}
