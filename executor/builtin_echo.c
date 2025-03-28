/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:44:37 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/27 19:46:13 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	echo(char **args);

int	main()
{
	char	*args1[] = {"/bin/echo", "Assurdo", "Impossibile", "Tremendo", NULL};
	char	*args2[] = {"/bin/echo", "-n", " Impossibile", " Tremendo", NULL};
	char	*args3[] = {"/bin/echo", " -n", "Impossibile", " -n", NULL};
	char	*args4[] = {"/bin/echo", "-n- n- n- n- n- n- n", "Impossibile", "Tremendo", NULL};
	char	*args5[] = {"/bin/echo", "-n -n -n -n -n -na", "Impossibile", "Tremendo", NULL};
	char	*args6[] = {"/bin/echo", "    -n -n -n -n -n -na", "Impossibile", "Tremendo", NULL};
	char	*args7[] = {NULL};
	
	echo(args1);
	echo(args2);
	echo(args3);
	echo(args4);
	echo(args5);
	echo(args6);
	echo(args7);
}

int	is_flag(char *s)
{
	int	response;

	if (s[0] == '-' && s[1] == 'n' && (s[2] == ' ' || s[2] == '\0'))
		response = 1;
	else
		response = 0;
	s += 2;
	return (response);
}

void	echo(char **args)
{
	int	i;
	int	j;
	int	stop;

	i = 1;
	stop = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (stop == 1)
			{
				stop = is_flag(&args[i][j]);
				j += stop;
			}
			else
				write(1, &args[i][j], 1);
			++j;
		}
		++i;
	}
}
