/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:08:08 by ftersill          #+#    #+#             */
/*   Updated: 2025/03/26 12:00:46 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "debug.h"
# include "executor.h"
# include "debug_resources/all.h"

int	testing(int test_num, int fd);
int	alloc_memory_for_test(char *test, char ****matrix, t_token **exec);
int	read_tokens(char ***matrix, t_token *exec, int line_num);
int	start_test_session(t_token *exec);

int	main(int argc, char **argv)
{
	int		fd;
	char	*filename;
	int		i;

	if (argc != 2 || argv[1][0] == '\0')
		return (fd_printf(2, "\nInsert a file num.\n"));
	filename = ft_strjoin("debug_resources/input_samples/", argv[1]);
	if (!filename)
		return (fd_printf(2, "\nMalloc failed\n"));
	fd = open(filename, O_RDWR, 0666);
	if (fd == -1)
		return (fd_printf(2, "Failed to open file |%s|", filename),\
		 free(filename), 1);
	give_filedata(fd, filename);
	i = 0;
	while ("LOOP: while there are tests to do")
	{
		if (testing(i, fd) != 0)
			break ;
		l_printf("\n\033[1;33mStop.\033[0m\n");
		++i;
	}
	del_filedata();
	free(filename);
}

int	testing(int test_num, int fd)
{
	char	***matrix;
	char	*test;
	char	*temp;
	int		num;
	t_token	*exec;

	temp = ft_itoa(test_num);
	if (!temp)
		return (1);
	test = ft_strjoin("[Test", temp);
	free(temp);
	if (!test)
		return (1);
	num = num_line(1, test);
	free(test);
	test = get_n_line(fd, num);
	if (!test)
		return (2);
	if (alloc_memory_for_test(test, &matrix, &exec) != 0)
		return (free_three_d_matrix(matrix), free(test), free(exec), 3);
	if (read_tokens(matrix, exec, num + 1) != 0)
		return (free_three_d_matrix(matrix), free(test), free(exec), 4);
	if (start_test_session(exec) != 0)
		return (free_three_d_matrix(matrix), free(test), free(exec), 5);
	return (free_three_d_matrix(matrix), free(test), free(exec), 0);
}

int	alloc_memory_for_test(char *test, char ****matrix, t_token **exec)
{
	int	tokens;

	*exec = NULL;
	*matrix = NULL;
	while (!ft_strchr("\n,", *test))
		++test;
	while (!ft_strchr("\n0123456789", *test))
		++test;
	if (ft_strchr("\n", *test))
		return (3);
	tokens = ft_atoi(test);
	if (tokens <= 0)
		return (4);
	*matrix = (char ***)ft_calloc(tokens + 1, sizeof(char **));
	if (!(*matrix))
		return (1);
	*exec = (t_token *)ft_calloc(tokens + 1, sizeof(t_token));
	if (!(*exec))
		return (1);
	return (0);
}

int	read_tokens(char ***matrix, t_token *exec, int line_num)
{
	int		token_num;

	token_num = 0;
	while ("LOOP: I loop until I have found all tokens!")
	{
		matrix[token_num] = read_all_line(line_num + token_num);
		if (!matrix[token_num])
			break ;
		exec[token_num].content = matrix[token_num][0];
		exec[token_num].id = ft_atoi(matrix[token_num][1]);
		exec[token_num].type = ft_atoi(matrix[token_num][2]);
		exec[token_num].prior = ft_atoi(matrix[token_num][3]);
		++token_num;
	}
	if (matrix[0] == NULL)
		return (1);
	return (0);
}

int	start_test_session(t_token *exec)
{
	t_token	*head;

	head = exec;
	l_printf("\n[START]\n++++++++++++++++++++\n");
	while (exec->content)
	{
		l_printf("\n+------------------+\nToken %d:\n", exec->id);
		l_printf("Content:\t|%s|\n", exec->content);
		l_printf("Id:\t\t|%d|\n", exec->id);
		l_printf("Type:\t\t|%d|\n", exec->type);
		l_printf("Priority:\t|%d|\n", exec->prior);
		++exec;
	}
	l_printf("\n+------------------+\n[END]\n++++++++++++++++++++\n");
	l_printf("\nTest for: ");
	exec = head;
	while (exec->content)
	{
		l_printf("%s ", exec->content);
		++exec;
	}
	exec = head;
	return (l_printf("\n\033[1;32mExecution:\033[0m\n"), execute(exec));
}
