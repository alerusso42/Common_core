/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:06:55 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/28 12:08:50 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	find_last_file(t_exec *exec, t_token *token);
static int	add_one(t_exec *exec, t_token *token);
static int	get_here_doc_file(int fd, char *limiter);
static int	compare_input(char *line, char *limiter, int limiter_len);

int	get_file_data(t_exec *exec, t_token *token)
{
	find_last_file(exec, token);
	while (token->content)
	{
		if (is_exec_sep(token->type))
			break ;
		else if (is_red_sign(token->type))
			if (add_one(exec, token) != 0)
				return (1);
		++token;
	}
	if (exec->last_in == -1 && token->type != PIPE && token->content)
		dup2(exec->stdin_fd, 0);
	if (exec->last_out == -1 && token->type != PIPE && token->content)
		dup2(exec->stdout_fd, 1);
	if (token->type == PIPE)
	{
		pipe(exec->pipe_fds);
		dup2(exec->pipe_fds[1], 1);
		close(exec->pipe_fds[1]);
		exec->pipe_fds[1] = 0;
	}
	return (0);
}

static void	find_last_file(t_exec *exec, t_token *token)
{
	exec->last_in = -1;
	exec->last_out = -1;
	while (token->content && is_exec_sep(token->type) == _NO)
	{
		if (token->type == RED_IN || token->type == HERE_DOC)
			exec->last_in = token->id;
		else if (token->type == RED_OUT || token->type == RED_O_APPEND)
			exec->last_out = token->id;
		++token;
	}
}

//	RED_IN avrà un ruolo importante nelle parentesi...
//	grep -v .c <(ls | grep -v .h)
static int	add_one(t_exec *exec, t_token *token)
{
	int	fd;

	if (token->type == RED_IN)
		fd = open(token->content, INFILE);
	else if (token->type == HERE_DOC)
		fd = open("here_doc", INFILE_DOC);
	else if (token->type == RED_OUT)
		fd = open(token->content, OUTFILE_TRUNC);
	else
		fd = open(token->content, OUTFILE_APPEND);
	if (fd == -1)
		return (bash_message(E_OPEN, token->content));
	if (token->type == HERE_DOC)
		if (get_here_doc_file(fd, token->content) != 0)
			return (E_MALLOC);
	if ((token->id == exec->last_in && is_red_input_sign(token->type)) || \
		(token->id == exec->last_out && is_red_output_sign(token->type)))
	{
		dup2(fd, is_red_output_sign(token->type));
	}
	else if (token->type == HERE_DOC)
		unlink("here_doc");
	close(fd);
	return (0);
}

static int	get_here_doc_file(int fd, char *limiter)
{
	char	*line;
	int		limiter_len;

	ft_putstr_fd("> ", 2);
	line = get_next_line_bonus(0);
	limiter_len = ft_strlen(limiter);
	while ((line) && (compare_input(line, limiter, limiter_len)) != 2)
	{
		ft_putstr_fd("> ", 2);
		ft_putstr_fd(line, fd);
		free(line);
		line = get_next_line_bonus(0);
	}
	if (!line)
		return (close(fd), E_MALLOC);
	free(line);
	return (0);
}

static int	compare_input(char *line, char *limiter, int limiter_len)
{
	int			double_equality;

	double_equality = 0;
	if (ft_strncmp(line, limiter, ft_strlen(line) - 1) == 0)
		double_equality += 1;
	if (ft_strncmp(line, limiter, limiter_len) == 0)
		double_equality += 1;
	return (double_equality);
}
