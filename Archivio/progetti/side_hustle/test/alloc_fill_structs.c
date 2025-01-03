#include "stdio.h"
#include "libft.h"
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

void	*get_data(t_typelist *node, char *data_name, int fd, char *filename)
{
	if ((fd == -1) || (!node) || (!node->content) || (!node->type) \
	|| (!data_name) || (!filename))
		return (printf("Error: parsing in get_data\n"), NULL);
	if (find_number_line(fd, filename, 2, data_name, node->content) < 0)
		return (printf("Error: data for %s not found\n", \
		(char *)node->content), NULL);
	
	

}