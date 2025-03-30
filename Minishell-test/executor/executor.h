/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:43:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/30 15:09:27 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
# define BUILTIN_NUM 7
# include "../Ssj_libft/libft.h"
# include <sys/wait.h>

typedef int (*t_builtin)(char **, t_exec *);

typedef struct s_token
{
	char			*content;
	int				id;
	int				prior;
	unsigned int	type:4;
}t_token;

typedef struct s_exec
{
	int				*pid_list;
	char			***commands;
	char			**env;
	char			**path;
	char			**files_to_trash;
	void			**builtins;
	int				pipe_fds[2];
	int				last_in;
	int				last_out;
	int				cmd_num;
	unsigned int	which_cmd:3;
	int				last_cmd_done;
	int				stdin_fd;
	int				stdout_fd;
	int				exit_status;
}				t_exec;

typedef struct s_debug_data
{
	char	***matrix;
	char	*temp;
	char	*filename1;
	char	*filename2;
	t_token	*tokens;
	int		fd_to_close;
}t_debug_data;

enum e_types
{
	COMMAND,
	ARGUMENT,
	FILES,
	RED_OUT,
	RED_IN,
	RED_O_APPEND,
	HERE_DOC,
	PIPE,
	AND,
	OR,
	WILDCARD,
};

enum e_builtin
{
	B_ECHO = 1,
	B_CD = 2,
	B_PWD = 3,
	B_EXPORT = 4,
	B_UNSET = 5,
	B_ENV = 6,
	B_EXIT = 7,
};

enum e_permissions
{
	INFILE = O_RDONLY,
	INFILE_DOC = O_RDWR | O_CREAT | O_TRUNC,
	OUTFILE_TRUNC = O_RDWR | O_CREAT | O_TRUNC,
	OUTFILE_APPEND = O_RDWR | O_CREAT | O_APPEND,
};

enum e_storage
{
	STORE,
	RECEIVE,
	_FREE,	
};

enum e_exec_errors
{
	NONE,
	E_ARGS,
	E_MALLOC,
	E_OPEN,
	E_FORK,
};

enum e_sub_strlen
{
	INCL,
	EXCL,
};

enum e_bools
{
	_YES = 1,
	_NO = 0,
};

//SECTION - Main function

int	execute(t_token *tokens, void *data, int debug);

//SECTION Memory management

t_exec	*storage(t_exec *update, int mode);
int		alloc_memory(t_exec **exec, int cmd_num);
void	free_memory(void);
void	*free_debug_data(t_debug_data *data);

//SECTION - General

void	*_free_matrix(char **matrix);
void	*_free_three_d_matrix(char ***matrix);
int		_sub_strlen(char *s, char *charset, int mode);
int		count_commands(t_token *tokens);
int		_ft_realloc(void **content, size_t nmemb, size_t size);
int		is_red_sign(int sign);
int		is_exec_sep(int sign);
int		is_red_input_sign(int sign);
int		is_red_output_sign(int sign);
int		is_a_builtin_cmd(char *cmd);

//SECTION Preparing data: env path, files, commands' path

int		get_commands_data(t_exec *exec, t_token *token);
int		get_paths_data(t_exec *exec, t_token *token);
int		get_file_data(t_exec *exec, t_token *token);

//SECTION Error prints

int		error(int error_type);
int		bash_message(int message, char *file);
int		_fd_printf(int fd, const char *str, ...);

//SECTION - Builtin

int		ft_echo(char **);
int		ft_cd(char **, t_exec *);
int		ft_pwd(char **, t_exec *);
int		ft_export(char **, t_exec *);
int		ft_unset(char **, t_exec *);
int		ft_env(t_exec *);
int		ft_exit(t_exec *);

#endif
