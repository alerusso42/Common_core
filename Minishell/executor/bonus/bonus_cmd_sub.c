#include "../executor.h"

int		parse_prompt(char *s, int *i, char *t_quote);
int		find_something(char *s, char searched, int *i, char *t_quote);
int		get_last_parenthesis(char *s, int dollar_i, int *last_p_i);
void	replace_line(char **s, int start, int end, t_data *gen);
void	stop_program(t_data *gen, int error_type);
char	*get_cmd_output(char *sub_cmd, t_data *gen);

int	command_substitution(char **prompt, t_data *gen)
{
	int		i;
	int		dollar_i;
	int		last_p_i;
	char	t_quote;

	i = 0;
	t_quote = 0;
	while ("Loop: expand all valid $() in prompt")
	{
		dollar_i = parse_prompt(*prompt, &i, &t_quote);
		if (!(*prompt)[i])
			return (0);
		else if (dollar_i == -1)
			continue ;
		else if (dollar_i == -2)
			return (1);
		_cut_string(*prompt, dollar_i, dollar_i + 1);
		if (get_last_parenthesis(*prompt, dollar_i, &last_p_i) == 1)
			return (ft_printf("UNCLOSED PARENTHESIS IN CMD SUB (fix this msg)\n"), 1);
		replace_line(prompt, dollar_i, last_p_i, gen);
	}
}

int	parse_prompt(char *s, int *i, char *t_quote)
{
	int		dollar_i;
	int		frst_p_i;

	dollar_i = find_something(s, '$', i, t_quote);
	if (dollar_i == -1)
		return (-1);
	++(*i);
	frst_p_i = find_something(s, '(', i, t_quote);
	if (frst_p_i == -1)
	{
		//ft_printf("%d: KO!\t|%s|\n", dollar_i, s + dollar_i);
		return (-1);
	}
	else if (frst_p_i == -2)
	{
		return (ft_printf("$\"() and $''() are INVALID (fix this msg)\n"), -2);
	}
	//ft_printf("%d: OK!\t|%s|\n", dollar_i, s + dollar_i);
	return (dollar_i);
}

int	find_something(char *s, char searched, int *i, char *t_quote)
{
	char	invalid_quotes;

	invalid_quotes = 0;
	while (s[*i])
	{
		if (*t_quote == s[*i])
			*t_quote = 0;
		else if ((!*t_quote) && (s[*i] == '\'' || s[*i] == '\"'))
			*t_quote = s[*i];
		else if (!*t_quote && s[*i] == searched)
			break ;
		else if (searched != '$')
			return (-1);
		if (searched != '$' && *t_quote)
			invalid_quotes = 1;
		++(*i);
	}
	if (!s[*i])
		return (-1);
	else if (invalid_quotes)
		return (-2);
	return (*i);
}

int	get_last_parenthesis(char *s, int dollar_i, int *last_p_i)
{
	int		layer;
	int		i;
	char	t_quote;

	i = dollar_i;
	t_quote = 0;
	layer = 1;
	while (s[i])
	{
		if (t_quote == s[i])
			t_quote = 0;
		else if ((!t_quote) && (s[i] == '\'' || s[i] == '\"'))
			t_quote = s[i];
		else if (!t_quote && s[i] == '(')
			layer += 1;
		else if (!t_quote && s[i] == ')')
			layer -= 1;
		if (layer == 0)
			break ;
		++i;
	}
	if (!s[i])
		return (1);
	*last_p_i = i;
	return (0);
}

void	replace_line(char **s, int start, int end, t_data *gen)
{
	char	*line;

	(*s)[end] = 0;
	line = get_cmd_output(*s + start, gen);
	(*s)[end] = ' ';
	_cut_string(*s, start, end);
	if (line)
	{
		*s = _cat_string(*s, line, start, 3);
		if (!*s)
			stop_program(gen, E_MALLOC);
	}
}

void	stop_program(t_data *gen, int error_type)
{
	t_exec	exec;

	exec = (t_exec){0};
	exec.main_struct_pointer = gen;
	error(error_type, &exec);
}

int		get_subcmd_stdout_name(t_data *gen);
int		get_files(int backup_fds[2], int redir_fds[2], char *cmd, t_data *gen);
int		close_files(int backup_fds[2], int redir_fds[2], char del, t_data *gen);
void	run_sub_cmd(t_data *gen, int backup_fds[2], int redir_fds[2]);
void	read_output(t_data *gen, char **s, int result_fd);

char	*get_cmd_output(char *sub_cmd, t_data *gen)
{
	int		backup_fds[2];
	int		redir_fds[2];
	char	*line;
	int		result_fd;

	if (get_subcmd_stdout_name(gen) == 1)
		stop_program(gen, E_MALLOC);
	if (get_files(backup_fds, redir_fds, sub_cmd, gen) == 1)
		stop_program(gen, E_OPEN);
	run_sub_cmd(gen, backup_fds, redir_fds);
	dup2(backup_fds[0], STDIN_FILENO);
	dup2(backup_fds[1], STDOUT_FILENO);
	line = NULL;
	result_fd = open(gen->subcmd_stdout, O_RDWR | O_CREAT, 0777);
	close_files(backup_fds, redir_fds, _YES, gen);
	if (result_fd == -1)
		stop_program(gen, E_OPEN);
	read_output(gen, &line, result_fd);
	close(result_fd);
	return (line);
}

int	get_subcmd_stdout_name(t_data *gen)
{
	char	*shell_level;

	free(gen->subcmd_stdout);
	shell_level = get_env(gen->env, "SHLVL");
	if (!shell_level)
	{
		gen->subcmd_stdout = ft_strdup(".subcmd_stdout");
		return (gen->subcmd_stdout == NULL);
	}
	gen->subcmd_stdout = ft_strjoin(".subcmd_stdout", shell_level);
	return (gen->subcmd_stdout == NULL);
}

int	get_files(int backup_fds[2], int redir_fds[2], char *cmd, t_data *gen)
{
	backup_fds[0] = dup(STDIN_FILENO);
	backup_fds[1] = dup(STDOUT_FILENO);
	redir_fds[0] = open(".subcmd_stdin", O_RDWR | O_CREAT, 0777);
	redir_fds[1] = open(gen->subcmd_stdout, O_RDWR | O_CREAT, 0777);
	if (!redir_fds[0] || !redir_fds[1])
		return (close_files(backup_fds, redir_fds, _YES, gen));
	write(redir_fds[0], cmd, ft_strlen(cmd));
	close(redir_fds[0]);
	redir_fds[0] = open(".subcmd_stdin", O_RDWR | O_CREAT, 0777);
	if (!redir_fds[0])
		return (close_files(backup_fds, redir_fds, _YES, gen));
	unlink(".subcmd_stdin");
	dup_and_reset(&redir_fds[0], STDIN_FILENO);
	dup_and_reset(&redir_fds[1], STDOUT_FILENO);
	return (0);
}

int		close_files(int backup_fds[2], int redir_fds[2], char del, t_data *gen)
{
	if (del)
	{
		unlink(".subcmd_stdin");
		unlink(gen->subcmd_stdout);
	}
	close_and_reset(&backup_fds[0]);
	close_and_reset(&backup_fds[1]);
	close_and_reset(&redir_fds[0]);
	close_and_reset(&backup_fds[1]);
	return (1);
}

void	run_sub_cmd(t_data *gen, int backup_fds[2], int redir_fds[2])
{
	pid_t	pid;
	char	**empty_matrix;

	pid = fork();
	if (pid < 0)
	{
		close_files(backup_fds, redir_fds, _YES, gen);
		stop_program(gen, E_FORK);
	}
	else if (pid == 0)
	{
		empty_matrix = (char **)ft_calloc(2, sizeof(char *));
		close_files(backup_fds, redir_fds, _NO, gen);
		if (!empty_matrix)
			stop_program(gen, E_MALLOC);
		empty_matrix[0] = ft_strdup("");
		if (!empty_matrix[0])
			return (_free_matrix(empty_matrix), stop_program(gen, E_MALLOC));
		execve(gen->minishell_path, empty_matrix, gen->env);
		empty_matrix = _free_matrix(empty_matrix);
		stop_program(gen, E_FORK);
	}
	waitpid(pid, NULL, 0);
}

void	read_output(t_data *gen, char **s, int result_fd)
{
	char	*line;
	int		prompt_len;

	prompt_len = ft_strlen(PROMPT);
	line = get_next_line_bonus(result_fd);
	while (line)
	{
		if (line[0] == '\n' || !ft_strncmp(line, PROMPT, prompt_len))
		{
			free(line);
			line = get_next_line_bonus(result_fd);
			continue ;
		}
		line[ft_strlen(line) - 1] = ' ';
		if (!*s)
		{
			*s = ft_strdup(line);
			free(line);
		}
		else
			*s = _ft_strjoin_free(*s, line);
		if (!*s)
			return (close(result_fd), stop_program(gen, E_MALLOC));
		line = get_next_line_bonus(result_fd);
	}
}
