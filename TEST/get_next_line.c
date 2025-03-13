// Assignment name : get_next_line
// Expected files : get_next_line.c (42_EXAM can't take .h for now)
// Allowed functions: read, free, malloc
// --------------------------------------------------------------------------------
// Write a function named get_next_line which prototype should be:
// char *get_next_line(int fd);
// Your function must return a line that has been read from the file descriptor passed as parameter. 
// What we call a "line that has been read" is a succession of 0 to n characters that end with '\n' (ascii code 0x0a) or with End Of File (EOF).
// The line should be returned including the '\n' in case there is one at the end of the line that has 
// been read. When you've reached the EOF, you must store the current buffer in a char * and return it. If the buffer is empty you must return NULL.
// In case of error return NULL. In case of not returning NULL, the pointer should be free-able. 
// Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be used as the buffer size for the read calls in your functions.
// Your function must be memory leak free. When you've reached the EOF, your function should keep 
// 0 memory allocated with malloc, except the line that has been returned.
// Calling your function get_next_line() in a loop will therefore allow you to read the text available
// on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.
// Make sure that your function behaves well when it reads from a file, from the standard output, from a redirection, etc...
// No call to another function will be done on the file descriptor between 2 calls of get_next_line().
// Finally we consider that get_next_line() has an undefined behaviour when reading from a binary file.
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
#include <fcntl.h>
#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
typedef struct t_plus
{
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
	int		fd;
	int		err;
	int		sizeof_left;

} s_plus;

enum e_read_effects
{
	INVALID = -1,
	END_OF_FILE = 0,
	LAST_CHUNK = 1,
	OK = 2,
};

enum e_alloc_system
{
	CALLOC = 1,
	REALLOC = 2,
	FREE = 3,
};

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}
int	to_read(s_plus *plus)
{
	int	len;

	len = read(plus->fd, plus->buffer, BUFFER_SIZE);
	if (len == -1)
		return (INVALID);
	if (len == 0)
		return (END_OF_FILE);
	if (len < BUFFER_SIZE)
		return (LAST_CHUNK);
	else
		return (OK);
}

int		al_sys(char **s1, char **s2, int mode);
char	*case_1(s_plus *plus);
char	*case_2(s_plus *plus);
char	*case_3(s_plus *plus);
int		find_newlines(s_plus *plus);

char	*ft_calloc()

int		al_sys(char **s1, char **s2, int mode)
{
	if (mode == CALLOC)
	{
		*s1 
	}
}

//	If buffer is empty
char	*case_1(s_plus *plus)
{
	int	read_effects;

	while (find_newlines(plus) != 0)
	{
		read_effects = to_read(plus);
		if (read_effects >= INVALID && read_effects < OK)
			break ;
		if (plus->line == NULL && )
	}
	return (plus->line);
}

int	find_newlines(s_plus *plus)
{
	int	index;

	index = 0;
	while (plus->buffer[index] && plus->buffer[index] != '\n')
		++index;
	plus->sizeof_left = index;
	if (plus->buffer[index] == '\n')
		return (0);
	else
		return (1);
}

char	*get_next_line(int fd)
{
	static s_plus	plus = (s_plus){0};

	if (fd == -1 || BUFFER_SIZE <= 0)
		return(NULL);
	plus.fd = fd;
	plus.line = NULL;
	if (plus.buffer[0] == '\0')
		return (case_1(&plus));
	if (find_newlines(plus.buffer[0]) == 0)
		return (case_2(&plus));
	else
		return (case_3(&plus));
}

int	main(void)
{
	int fd = open("get_next_line.c", O_RDONLY);
	char *str;
	str = get_next_line(fd);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
	}
	return(0);
}