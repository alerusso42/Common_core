/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:17:53 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/22 15:20:05 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Z_DATA_H
# define Z_DATA_H
# if __has_include("z_header.h")
#  include "z_header.h"
# else
#  include "z_header_bonus.h"
# endif

enum e_error
{
	ER_BAD_ARGC = 1,
	ER_MALLOC = 2,
	ER_PARSING = 3,
	ER_NOPATH = 4,
	ER_CMD_NOTFOUND = 5,
	ER_FORK_FAILED = 6,
	ER_EXECVE_FAILED = 7,
};

typedef struct s_pipex
{
	char	**commands;
	char	**path;
	int		*fds;
	char	*temp;
	char	***options;
}				t_pipex;

typedef struct s_settings
{
	unsigned char	switch_1_bonus:1;
}				t_settings;

#endif