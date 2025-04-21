#include "mfile_gnl.h"

int	readfd(t_manage_fds	*data, int count)
{
	char			*buff;

	buff = data->buffer[data->curr_fd.n];
	return (SDL_RWread(data->curr_fd.p, buff, sizeof(char), count));
}
