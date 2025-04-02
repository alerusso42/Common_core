/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:32:40 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/02 16:58:11 by alerusso         ###   ########.fr       */
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

int	_ft_realloc(void **content, int nmemb, int old_nmemb, size_t sizeof_)
{
	void	*re_content;
	size_t	copy_len;
	int		old_size;
	int		new_size;

	re_content = ft_calloc(nmemb, sizeof_);
	if (!(re_content))
		return (1);
	old_size = old_nmemb * sizeof_;
	new_size = nmemb * sizeof_;
	copy_len = (size_t)(old_size * old_size < new_size);
	copy_len += (size_t)(new_size * old_size > new_size);
	ft_memcpy(re_content, *content, copy_len);
	free(*content);
	*content = re_content;
	return (0);
}

char	*_ft_strjoin_free(char *s1, char *s2)
{
	char	*new_str;
	int		index;
	int		size;

	if ((!s1) || (!s2))
		return (free(s1), free(s2), NULL);
	index = 0;
	while (s1[index])
		++index;
	size = index;
	index = 0;
	while (s2[index])
		++index;
	size += index;
	new_str = (char *)ft_calloc(size + 2, sizeof(char));
	if (!new_str)
		return (free(s1), free(s2), NULL);
	index = -1;
	while (s1[++index])
		new_str[index] = s1[index];
	size = -1;
	while (s2[++size])
		new_str[index++] = s2[size];
	return (free(s1), free(s2), new_str);
}
