/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:44:37 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/05 15:22:26 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	is_flag(char *s, char *print_slash_n, int *j, char *stop_check);

int	ft_echo(char **args, t_exec *exec)
{
	int		i;
	int		j;
	char	print_slash_n;
	char	stop_check;

	(void)exec;
	i = 1;
	print_slash_n = 1;
	stop_check = 0;
	exec->exit_status = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (stop_check == 0)
				is_flag(&args[i][j], &print_slash_n, &j, &stop_check);
			else
				write(1, &args[i][j], 1);
			++j;
		}
		++i;
	}
	return (write(1, "\n", (int)print_slash_n));
}

static void	is_flag(char *s, char *print_slash_n, int *j, char *stop_check)
{
	if ((*j == 0 || s[-1] == ' ') && \
	s[0] == '-' && s[1] == 'n' && (s[2] == ' ' || s[2] == '\0'))
	{
		*j += 2;
		*print_slash_n = 0;
	}
	else
	{
		write(1, s, 1);
		*stop_check = 1;
	}
	if (s[0] && s[1] && !s[2])
		*j -= 1;
}

/*
int	main()
{
	char	*args1[] = {"/bin/echo", "Assurdo", "Impossibile", "Tremendo", \
	NULL};
	char	*args2[] = {"/bin/echo", "-n", " Impossibile", " Tremendo", NULL};
	char	*args3[] = {"/bin/echo", " -n", "Impossibile", " -n", NULL};
	char	*args4[] = {"/bin/echo", "-n- n- n- n- n- n- n", "Impossibile", \
	"Tremendo", NULL};
	char	*args5[] = {"/bin/echo", "-n -n -n -n -n -na", "Impossibile", \
	"Tremendo", NULL};
	char	*args6[] = {"/bin/echo", "    -n -n -n -n -n -na", "Impossibile",\
	 "Tremendo", NULL};
	char	*args7[] = {NULL};
	char	*args8[] = {"/bin/echo", "|", "",\
		"   |", NULL};
	
	write(1, "TEst 1: normal print with SLASH N\n\n", 35);
	ft_echo(args1, NULL);
	write(1, "\n", 1);
	write(1, "TEst 2: Print with NO SLASH N\n\n", 31);
	ft_echo(args2, NULL);
	write(1, "\n", 1);
	write(1, "TEst 3: Print with NO SLASH N\n\n", 31);
	ft_echo(args3, NULL);
	write(1, "\n", 1);
	write(1, "TEst 4: Print with NO SLASH N\n\n", 31);
	ft_echo(args4, NULL);
	write(1, "\n", 1);
	write(1, "TEst 5: Print with NO SLASH N\n\n", 31);
	ft_echo(args5, NULL);
	write(1, "\n", 1);
	write(1, "TEst 6: Print with NO SLASH N\n\n", 31);
	ft_echo(args6, NULL);
	write(1, "\n", 1);
	write(1, "TEst 7: Print with NO SLASH N\n\n", 31);
	ft_echo(args7, NULL);
	write(1, "\n", 1);
	write(1, "TEst 8: Test gay\n\n", 18);
	ft_echo(args8, NULL);
	write(1, "\n", 1);
}*/
