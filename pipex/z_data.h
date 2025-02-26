/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:17:53 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/26 13:50:51 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Z_DATA_H
# define Z_DATA_H
# if __has_include("z_header.h")
#  include "z_header.h"
# else
#  include "z_header_bonus.h"
# endif
# include <fcntl.h>

enum e_error
{
	ER_BAD_ARGC = 1,
	ER_MALLOC = 2,
	ER_PARSING = 3,
	ER_NOPATH = 4,
	ER_CMD_NOTFOUND = 5,
	ER_FORK_FAILED = 6,
	ER_EXECVE_FAILED = 7,
	ER_OPEN_FAILED = 8,
	ER_NO_CODED = 9,
	ER_DUP_FAILED = 10,
	ER_WAIT_FAILED = 11,
	ER_PIPE_FAILED = 12,
};

enum e_fileflags
{
	INFILE = O_CREAT | O_RDONLY,
	OUTFILE = O_CREAT | O_TRUNC | O_WRONLY,
};

typedef struct s_pipex
{
	unsigned int	here_doc_bool:1;
	int				cmd_num;
	int				*pid_list;
	char			*infile;
	char			*outfile;
	char			**commands;
	char			**path;
	int				*fds;
	char			*temp;
	char			***options;
}				t_pipex;

typedef struct s_settings
{
	unsigned char	switch_1_bonus:1;
}				t_settings;

#endif