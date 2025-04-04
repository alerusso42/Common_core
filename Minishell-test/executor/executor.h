/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:43:01 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/04 16:12:21 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
# include "../Ssj_libft/libft.h"
# include <sys/wait.h>

typedef struct s_exec t_exec;
typedef int (*t_builtin)(char **, t_exec *);
typedef struct s_token
{
	char			*content;
	int				id;
	int				prior;
	unsigned int	type:4;
}t_token;
struct s_exec
{
	t_builtin		*builtins;
	int				*pid_list;
	char			***commands;
	char			***env;
	int				*env_size;
	int				*last_env;
	char			**path;
	char			*which_cmd;
	void			*main_struct_pointer;
	int				*here_doc_fds;
	int				pipe_fds[2];
	int				last_in;
	int				last_out;
	int				cmd_num;
	int				last_cmd_done;
	int				stdin_fd;
	int				stdout_fd;
	int				exit_status;
	int				debug:1;
};

typedef struct s_debug_data
{
	char	***matrix;
	char	*temp;
	char	*filename1;
	char	*filename2;
	char	**env;
	t_token	*tokens;
	int		last_env;
	int		env_size;
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
	BUILT_N = 8,
};

enum e_permissions
{
	INFILE = O_RDONLY,
	INFILE_DOC = O_RDWR | O_CREAT,
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
	E_NOENV,
	E_ENV_PARSING,
	E_CD_ARGS,
	E_CD_PATH,
};

enum e_sub_strlen
{
	INCL,
	EXCL,
};

enum e_environment
{
	ENV_NO_EQ_PLUS = 0,
	ENV_NAME_SIZE = 1,
	ENV_CONT_SIZE = 2,
	ENV_WHICH_VAL = 3,
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
int		alloc_memory(t_exec *exec, int cmd_num);
void	free_memory(void);
void	*free_debug_data(t_debug_data *data);
void	get_main_struct_data(t_exec *exec, void *data, int debug);
void	close_and_reset(int *fd);

//SECTION - General

void	*_free_matrix(char **matrix);
void	*_free_three_d_matrix(char ***matrix);
char	*_ft_strjoin_free(char *s1, char *s2);
int		count_commands(t_token *tokens);
int		_ft_realloc(void **content, int nmemb, int old_nmemb, size_t sizeof_);
int		is_red_sign(int sign);
int		is_exec_sep(int sign);
int		is_red_input_sign(int sign);
int		is_red_output_sign(int sign);
int		is_a_builtin_cmd(char *cmd);
int		_sub_strlen(char *s, char *charset, int mode);
int		_sub_strcpy(char *dest, char *src, char *charset, int mode);
int		double_cmp(char *s1, char *s2, int s1_len, int ignore_n_char);

//SECTION - Environment management

int		cpy_env(char **old_env, char ***new_env, int *env_size, int *last_env);
int		expand_env(char ***env, int *env_size);
char	*ft_getenv(char **env, char *search, int *where);
int		env_pars(char *item, int *no_eq_plus, int *name_size, int *cont_size);
void	print_env(char **env, int print_init);

//SECTION Preparing data: env path, files, commands' path

void	prepare_here_docs(t_exec *exec, t_token *token);
int		get_commands_data(t_exec *exec, t_token *token);
int		get_paths_data(t_exec *exec, t_token *token);
int		get_file_data(t_exec *exec, t_token *token);

//SECTION Error and prints

int		error(int error_type);
int		bash_message(int message, char *file);
int		_fd_printf(int fd, const char *str, ...);

//SECTION - Builtin

int		ft_echo(char **args, t_exec *exec);
int		ft_cd(char **args, t_exec *exec);
int		ft_pwd(char **args, t_exec *exec);
int		ft_export(char **args, t_exec *exec);
int		ft_unset(char **args, t_exec *exec);
int		ft_env(char **args, t_exec *exec);
int		ft_exit(char **args, t_exec *exec);

#endif
