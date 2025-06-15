/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 21:56:13 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/16 00:27:30 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "../../../daft.h"
# include "../Libft/all.h"

typedef struct s_daft_data	t_daft_data;
typedef struct s_daft_conf	t_daft_conf;
typedef struct s_daft_list	t_daft_list;
typedef struct s_daft_node	t_daft_node;
typedef unsigned int		t_bool;

struct s_daft_data
{
	t_daft_conf	conf;
	t_fd		log_file;
	t_daft_list	**data_list;
	char		**files_names;
	int			files_num;
	int			current_file;
	int			last_error;
};

struct s_daft_conf
{
	char	*default_flags;
	t_bool	debug_log;
};

struct s_daft_list
{
	t_fd		filedata;
	t_daft_node	**node;
	int			size;
	char		field_sep;
	char		key_value_sep;
	char		values_sep;
	t_bool		multiple_lines:1;
	t_bool		split_values:1;		
};

struct s_daft_node
{
	int			offset;
	t_daft_node	*next;
};

enum e_daft_logs
{
	DAFT_MESSAGES,
	DAFT_ERRORS,
	DAFT_LOG_OPEN,
	DAFT_LOG_ATOI,
	DAFT_LOG_MALLOC,
	DAFT_LOG_SETT,
};

int			_daft_log(t_daft_data *data, int log);
t_daft_data	*_daft_get_memory(t_daft_data *new_data, bool update);


#endif