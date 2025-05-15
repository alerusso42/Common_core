/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:13:21 by ftersill          #+#    #+#             */
/*   Updated: 2025/05/14 12:43:10 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	token_struct_init(t_token *token, t_data *gen)
{
	int	i;

	i = 0;
	(void)token, (void)gen;
	while (i < gen->token_num)
	{
		token[i].id = i;
		token[i].type = 1;
		token[i].space_on_right = false;
		token[i].prior = 0;
		token[i].cmd_num = 0;
		i++;
	}
}

void	printf_struct(t_token *token, t_data *gen)
{
	int	i;

	i = 0;
	while (i <= gen->token_num)
	{
		printf("|%s| = | %d |\n", token[i].content, token[i].type);
		i++;
	}
}

// fa il free del contenuto dei token
void	free_token(t_token *token, t_data *gen)
{
	int	i;

	i = 0;
	while (i <= gen->token_num)
	{
		free(token[i].content);
		i++;
	}
}

// funzione che fa free sullo struct
void	free_struct(t_token *token)
{
	free(token);
}

// fa il free di tutto
void	free_all(t_token *token, t_data *gen)
{
	free_token(token, gen);
	free_struct(token);
}
