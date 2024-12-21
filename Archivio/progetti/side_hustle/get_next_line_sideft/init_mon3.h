/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mon3.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:34:39 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/20 17:48:57 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_MON3_H
# define INIT_MON3_H
# include "general_ft.h"
# include "general_ft2.h"
# include "get_next_line_bonus.h"
# include <malloc.h>
# include <unistd.h>
# include <fcntl.h>

int		find_1num(int i, int which_n, char *pokedex_copy);
float	find_1flt(int i, int which_n, char *pokedex_copy);
int		*find_nums_int(int i, int *nums, char *pokedex_copy);
t_ob	*find_nums_uchar(int i, t_ob *nums, char *pokedex_copy);
char	*find_1str(int i, int which_s, char *string, char *pokedex_copy);
char	**find_strs(int i, char **strings, char *src);

int	find_1num(int i, int which_n, char *pokedex_copy)
{
	int	num;

	num = 0;
	if (i == -1)
		return (0);
	while (pokedex_copy[i] != '\n')
	{
		if ((pokedex_copy[i] >= '0') && (pokedex_copy[i] <= '9')
			&& (which_n == 1))
		{
			num = atoi(&pokedex_copy[i]);
			return (num);
		}
		else if ((pokedex_copy[i] >= '0') && (pokedex_copy[i] <= '9')
			&& (which_n != 1))
		{
			--which_n;
		}
		while ((pokedex_copy[i] >= '0') && (pokedex_copy[i] <= '9'))
			++i;
		if (pokedex_copy[i] != '\n')
			++i;
	}
	return (0);
}

int	*find_nums_int(int i, int *nums, char *pokedex_copy)
{
	int	nums_index;

	nums_index = 0;
	nums[0] = 0;
	if (i == -1)
		return (nums);
	while (pokedex_copy[i] != '\n')
	{
		if ((pokedex_copy[i] >= '0') && (pokedex_copy[i] <= '9'))
		{
			nums[nums_index] = atoi(&pokedex_copy[i]);
			++nums_index;
		}
		while ((pokedex_copy[i] >= '0') && (pokedex_copy[i] <= '9'))
			++i;
		if (pokedex_copy[i] != '\n')
			++i;
	}
	return (nums);
}

t_ob	*find_nums_uchar(int i, t_ob *nums, char *pokedex_copy)
{
	int	nums_index;

	nums_index = 0;
	nums[0] = 0;
	if (i == -1)
		return (nums);
	while (pokedex_copy[i] != '\n')
	{
		if ((pokedex_copy[i] >= '0') && (pokedex_copy[i] <= '9'))
		{
			nums[nums_index] = atoi(&pokedex_copy[i]);
			++nums_index;
		}
		while ((pokedex_copy[i] >= '0') && (pokedex_copy[i] <= '9'))
			++i;
		if (pokedex_copy[i] != '\n')
			++i;
	}
	return (nums);
}

char	*find_1str(int i, int which_s, char *string, char *pokedex_copy)
{
	if (i == -1)
		return (NULL);
	while (pokedex_copy[i] != '\n')
	{
		if ((((pokedex_copy[i] >= 'a') && (pokedex_copy[i] <= 'z'))
				|| ((pokedex_copy[i] >= 'A') && (pokedex_copy[i] <= 'Z')))
			&& (which_s == 1))
		{
			sub_strcpy(&string, &pokedex_copy[i]);
			return (string);
		}
		else if ((((pokedex_copy[i] >= 'a') && (pokedex_copy[i] <= 'z'))
				|| ((pokedex_copy[i] >= 'A') && (pokedex_copy[i] <= 'Z')))
			&& (which_s != 1))
			--which_s;
		while (((pokedex_copy[i] >= 'a') && (pokedex_copy[i] <= 'z'))
			|| ((pokedex_copy[i] >= 'A') && (pokedex_copy[i] <= 'Z'))
			|| ((pokedex_copy[i] >= '0') && (pokedex_copy[i] <= '9'))
			|| (pokedex_copy[i] == '_'))
			++i;
		if (pokedex_copy[i] != '\n')
			++i;
	}
	return (NULL);
}

char	**find_strs(int i, char **strings, char *src)
{
	int	position;
	int	previous_position;

	if (i == -1)
	{
		strings = NULL;
		return (strings);
	}
	position = 0;
	previous_position = 0;
	if (strings[position])
		strings[position][0] = '0';
	while (strings[previous_position] != NULL)
	{
		strings[position] = find_1str(i, position + 1, strings[position], src);
		++position;
		previous_position = position - 1;
	}
	return (strings);
}

#endif