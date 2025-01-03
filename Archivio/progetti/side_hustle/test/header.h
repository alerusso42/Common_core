#ifndef HEADER_H
# define HEADER_H
#include "stdio.h"
#include "libft.h"
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"
#define DEBUG_PRINT 0

int	obtain_list(char *structure_name, t_typelist **list);
int	cut_string(char **string, size_t start, size_t end);

#endif