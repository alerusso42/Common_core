/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:56:23 by ftersill          #+#    #+#             */
/*   Updated: 2025/04/02 21:59:22 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include "parsing/parsing.h"
# include "executor/executor.h"

enum e_permission
{
	INFILE = O_CREAT | O_APPEND,
};

typedef struct s_data
{
	char	*input;
	int		exit_code;
	char	**env;
	
} t_data;

//signals
//void	signals(int signal, siginfo_t *info, void *s);
int		which_signal_received(void);

#endif