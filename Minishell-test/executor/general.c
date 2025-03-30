/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:32:40 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/27 21:28:11 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/*
	Always return NULL
*/
void	*_free_matrix(char **matrix)
{
	int	index;

	index = 0;
	if (!matrix)
		return (NULL);
	while (matrix[index])
	{
		if (matrix[index])
			free(matrix[index]);
		matrix[index] = NULL;
		++index;
	}
	if (matrix)
		free(matrix);
	return (NULL);
}

/*
	Always return NULL
*/
void	*_free_three_d_matrix(char ***matrix)
{
	int	index_one;
	int	index_two;

	index_one = 0;
	if (!matrix)
		return (NULL);
	while (matrix[index_one])
	{
		index_two = 0;
		while (matrix[index_one][index_two])
		{
			free(matrix[index_one][index_two]);
			matrix[index_one][index_two] = NULL;
			++index_two;
		}
		free(matrix[index_one]);
		matrix[index_one] = NULL;
		++index_one;
	}
	free(matrix);
	return (NULL);
}

/*
	Count until the char is in the charset.
	TWO MODES:

	INCL: Count until the char is INCLUDED in the charset.
	EXCL: Count until the char is NOT INCLUDED in the charset.
*/
int	_sub_strlen(char *s, char *charset, int mode)
{
	int	i;

	i = 0;
	if (mode == INCL)
	{
		while (((s[i] != '\0')) && \
		(ft_strchr(charset, s[i])))
		{
			++i;
		}
	}
	else if (mode == EXCL)
	{
		while (((s[i] != '\0')) && \
		!(ft_strchr(charset, s[i])))
		{
			++i;
		}
	}
	return (i);
}

int	count_commands(t_token *tokens)
{
	int	cmd_num;

	cmd_num = 0;
	while (tokens->content != NULL)
	{
		cmd_num += (tokens->type == COMMAND);
		++tokens;
	}
	return (cmd_num);
}

int	_ft_realloc(void **content, size_t nmemb, size_t size)
{
	void	*re_content;

	re_content = ft_calloc(nmemb, sizeof(void *));
	if (!(re_content))
		return (1);
	ft_memcpy(re_content, *content, nmemb * size);
	free(*content);
	*content = re_content;
	return (0);
}
