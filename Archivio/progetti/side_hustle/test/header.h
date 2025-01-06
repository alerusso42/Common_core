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

int		obtain_list(char *structure_name, t_typelist **list);
int		get_struct_list(t_typelist ***struct_list, char ***struct_list_names);
int		cut_string(char **string, size_t start, size_t end);
void	del_pointer(void **ptr, int mode);
int		save_struct(char *struct_name, t_typelist *list);
int		format_search(char **search_struct);
int		move_square_brackets(char **type, char **name);
int		add_s_(char *string, char **new_string);

#endif