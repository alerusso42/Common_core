/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_function_list.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:02:19 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/22 15:36:55 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Z_FUNCTION_LIST_H
# define Z_FUNCTION_LIST_H
# include "Libft/all.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>

# if __has_include("z_header.h")
#  include "z_header.h"
# else
#  include "z_header_bonus.h"
# endif

int		switch_to_bonus(t_settings *settings);
void	*storage(void *ptr, int mode);
int		error(int error);
void	reset_memory(void);
int		switches(t_settings *settings);
int		variables(t_settings *settings);
//		ALLOC_MAIN_STRUCT

int	alloc_main_struct(t_pipex **pipex);
int	alloc_cmd(t_pipex *pipex, int max_cmd);

//		PARSING

int	parsing(char *argv[], char *env[], t_pipex *pipex, t_settings *set);
int	get_options(t_pipex *pipex);
int	get_commands_bonus(char *argv[], t_pipex *pipex, t_settings *set);
//		EXECUTE

int	execute_pipe(t_pipex *pipex, t_settings *settings);
#endif