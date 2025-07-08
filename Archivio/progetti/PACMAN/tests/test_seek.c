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
#define POKEDEX "pokedex.txt"
#define close SDL_RWclose
#define free FREE
#define OFFSET 0
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (42);
	int				offset = atoi(argv[1]);
	IO_STRUCT		*fd;
	unsigned char	*str;
	int				size;

	fd = SDL_RWFromFile(POKEDEX, "r");
	if (!fd)
		return (1);
	size = 10;
	str = SDL_calloc(size + 1, sizeof(char));
	if (!str)
		return (2);
	SEEK(fd, offset, 0);
	if (READ(fd, str, sizeof(char), size) != (size_t)size)
		return (FREE(str), SDL_RWclose(fd), 7);
	SDL_RWclose(fd);
	str[size] = 0;
	fd = SDL_RWFromFile("Outputt.txt", "w");
	if (!fd)
		return (9);
	WRITE(fd, str, sizeof(char), size);
	close(fd);
	free(str);
	return (0);
}

// int	main(void)
// {
// 	IO_STRUCT		**fd;
// 	int				i;

// 	i = 0;
// 	fd = SDL_calloc(22, sizeof(IO_STRUCT *));
// 	while (i != 20)
// 	{
// 		fd[i] = SDL_RWFromFile(POKEDEX, "r");
// 		printf("%d: %d\n", i, fd[i]->type);
// 		++i;
// 	}
// 	i = 0;
// 	while (i != 20)
// 		SDL_RWclose(fd[i++]);
// 	FREE(fd);
// 	SDL_Quit();
// }
