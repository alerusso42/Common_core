#define CHUNK 32
#define TRUE 1
#include <unistd.h>
#include <stdio.h>
#include <malloc.h>
#include <fcntl.h>

int	read_pokedex(char **pokedex_copy, int pokedex, int capacity);
int	end_char(char **pokedex_copy, char *temp, int size);
int	erase_pokedex(char **pokedex);

int	main()
{
	char	*pokedex_copy;
	int		pokedex;

	pokedex = open("updated_pokedex.txt", O_RDONLY);
	pokedex_copy = (char *)malloc(CHUNK);
	if (pokedex_copy == NULL)
	{
		free(pokedex_copy);
		return (1);
	}
	read_pokedex(&pokedex_copy, pokedex, CHUNK);
	printf("\n%s\n", pokedex_copy);
	free(pokedex_copy);
	close(pokedex);
	return (0);
}

int	read_pokedex(char **pokedex_copy, int pokedex, int capacity)
{
	static int	size;
	int			bytes_read;
	int			save_position;
	char		*temp;

	size = 0;
	save_position = size;
	bytes_read = 1;
	while (1)
	{
		bytes_read = read(pokedex, (*pokedex_copy) + size, CHUNK);
		if (bytes_read < 0)
			return (2);
		if (bytes_read == 0)
			break ;
		size += bytes_read;
		if (size + CHUNK > capacity)
		{
			capacity += 2;
			temp = (char *)realloc((*pokedex_copy), capacity);
			if (!temp)
				return (1);
			(*pokedex_copy) = temp;
		}
	}
	return (end_char(pokedex_copy, temp, size));
}

int	end_char(char **pokedex_copy, char *temp, int size)
{
	temp = (char *)realloc((*pokedex_copy), size + 1);
	if (!temp)
	{
		erase_pokedex(pokedex_copy);
		return (1);
	}
	(*pokedex_copy) = temp;
	(*pokedex_copy)[size] = '\0';
	return (0);
}

int	erase_pokedex(char **pokedex)
{
	free((*pokedex));
	free(pokedex);
	return (1);
}