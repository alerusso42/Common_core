/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:25:11 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/26 11:52:52 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

int	get_options(t_pipex *pipex)
{
	int	index;

	index = 0;
	while (pipex->commands[index])
	{
		pipex->options[index] = ft_split(pipex->commands[index], ' ');
		if (pipex->options[index] == NULL)
			return (ER_MALLOC);
		++index;
	}
	return (0);
}

int	get_second_filename(char *argv[], t_pipex *pipex)
{
	int	i;
	int	len;

	i = 0;
	while (argv[i] != NULL)
		++i;
	--i;
	len = ft_strlen(argv[i]) + 1;
	pipex->outfile = (char *)ft_calloc(len, sizeof(char));
	if (!pipex->outfile)
		return (ER_MALLOC);
	ft_strlcpy(pipex->outfile, argv[i], len);
	return (0);
}

int	get_here_doc_file(char *argv[], t_pipex *pipex)
{
	char	*line;
	int		fd;
	int		limiter_len;

	limiter_len = ft_strlen(argv[2]);
	fd = open("here_doc", OUTFILE, 0666);
	if (fd < 0)
		return (ER_OPEN_FAILED);
	pipex->here_doc_bool = YES;
	pipex->infile = ft_strdup("here_doc");
	if (!pipex->infile)
		return (ER_MALLOC);
	l_printf("\nInsert the input file contents, line per line.\n");
	l_printf("Press enter to submit. Insert the limiter to stop.\n\n");
	line = gnl(0);
	while ((line) && (ft_strncmp(line, argv[2], limiter_len) != 0))
	{
		ft_putendl_fd(line, fd);
		free(line);
		line = gnl(0);
	}
	if (!line)
		return (ER_MALLOC);
	free(line);
	return (close(fd));
}
