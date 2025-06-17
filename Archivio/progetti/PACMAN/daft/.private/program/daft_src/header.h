/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 21:56:13 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/17 15:10:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "../../../daft.h"
# include "../Libft/all.h"

# define SEED 42

typedef struct s_daft_data	t_daft_data;
typedef struct s_daft_conf	t_daft_conf;
typedef struct s_daft_mem	t_daft_mem;
typedef struct s_daft_list	t_daft_list;
typedef struct s_daft_node	t_daft_node;
typedef unsigned int		t_bool;

struct s_daft_conf
{
	char	*default_flags;
	t_bool	debug_log;
};

struct s_daft_mem
{
	void	*ptr;
	char	type;
};

struct s_daft_data
{
	t_daft_conf	conf;
	t_daft_mem	mem;
	t_fd		log_file;
	t_daft_list	**data_list;
	char		**files_names;
	int			files_num;
	int			current_file;
	int			last_error;
};

struct s_daft_list
{
	t_fd		filedata;
	t_daft_node	**node;
	char		*filename;
	int			size;
	char		field_sep[2];
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
	DAFT_LOG_FILESETT,
	DAFT_LOG_ALLOCSIZE,
	DAFT_LOG_MISSFLAGS,
};

enum e_daft_mem
{
	NO_MEM,
	STRING,
	TWO_D_MATRIX,
	THREE_D_MATRIX,
};

int			_daft_save_config(t_daft_data *data);
int			_daft_save_fnames(t_daft_data *data);
int			_daft_get_data(t_daft_list *file, char *filename);
int			_daft_get_data2(t_daft_list *file);
int			_daft_log(int log);
int			_daft_start_list(t_daft_node **list, int offset);
int			_daft_add_node_back(t_daft_node	*list, int offset);
t_daft_data	*_daft_get_memory(t_daft_data *new_data, bool update);
int			_daft_resize_matr(char ***old_matr, int *size);
char		*_cat_string(char *src, char *catstr, size_t start, int which_free);
int			_daft_hash(t_daft_list *file, char *key);
void		_daft_free_old_mem(t_daft_data *data);

void	*_daft_get_string(t_daft_data *data, t_daft_list *file);
void	*_daft_get_vertical_matr(t_daft_data *data, t_daft_list *file);
void	*_daft_get_horizontal_matr(t_daft_data *data, t_daft_list *file);
void	*_daft_get_three_d_matr(t_daft_data *data, t_daft_list *file);

#endif