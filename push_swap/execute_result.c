/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:40:27 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/27 12:25:03 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("push_swap.h")
# include "push_swap.h"
#else
# include "push_swap_bonus.h"
#endif

static int	get_command(char *input)
{
	if (ft_strncmp(input, "sa", 2) == 0)
		sa();
	else if (ft_strncmp(input, "sb", 2) == 0)
		sb();
	else if (ft_strncmp(input, "ss", 2) == 0)
		ss();
	else if (ft_strncmp(input, "pa", 2) == 0)
		pa();
	else if (ft_strncmp(input, "pb", 2) == 0)
		pb();
	else if (ft_strncmp(input, "ra", 2) == 0)
		ra();
	else if (ft_strncmp(input, "rb", 2) == 0)
		rb();
	else if (ft_strncmp(input, "rra", 3) == 0)
		rra();
	else if (ft_strncmp(input, "rrb", 3) == 0)
		rrb();
	else if (ft_strncmp(input, "rrr", 3) == 0)
		rrr();
	else if (ft_strncmp(input, "rr", 2) == 0)
		rr();
	else
		return (1);
	return (0);
}

/*
	1)	If exists, open tester.txt;
	2)	Gnl loop. 
*/
int	execute_result(void)
{
	char	*line;
	int		fd;
	int		n;

	fd = open("tester.txt", O_RDONLY);
	if (fd < 3)
		return (1);
	line = get_next_line(fd);
	if (!line)
		return (ER_MALLOC_ERROR);
	n = 0;
	while (line)
	{
		if (get_command(line) == 1)
			l_printf("\nINVALID!\n");
		free(line);
		line = get_next_line(fd);
		n++;
	}
	return (0);
}

static int	write_command(char output, int fd)
{
	if (output == SA)
		write(fd, "sa\n", 3);
	else if (output == SB)
		write(fd, "sb\n", 3);
	else if (output == SS)
		write(fd, "ss\n", 3);
	else if (output == PA)
		write(fd, "pa\n", 3);
	else if (output == PB)
		write(fd, "pb\n", 3);
	else if (output == RA)
		write(fd, "ra\n", 3);
	else if (output == RB)
		write(fd, "rb\n", 3);
	else if (output == RRA)
		write(fd, "rra\n", 4);
	else if (output == RRB)
		write(fd, "rrb\n", 4);
	else if (output == RRR)
		write(fd, "rrr\n", 4);
	else if (output == RR)
		write(fd, "rr\n", 3);
	else
		return (1);
	return (0);
}

/*
	1)	Open "tester.txt";
	2)	Writes all commands on it.
*/
void	save_result(t_stack *a)
{
	int		fd;
	int		n;

	fd = open("tester.txt", O_RDWR | O_CREAT | O_TRUNC, 777);
	if (fd < 3)
		return ;
	n = 0;
	while (a->command_list_length--)
	{
		write_command(a->command_list[n], fd);
		++n;
	}
}
