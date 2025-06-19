#ifndef FILESYSTEM_H
# define FILESYSTEM_H

# include <sys/time.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

# define FILE 0L
# define FOLDER 1L

enum	e_bool
{
	FALSE,
	TRUE,
};

enum	e_message
{
	HELP,
	ER_INPUT,
};


typedef struct s_FSNode
{
	char 			*name;
	int 			type;
	int 			size;
	struct s_FSNode *father;
	struct s_FSNode *children;
}FSNode;

#endif