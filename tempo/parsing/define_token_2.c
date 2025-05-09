/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_token_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:04:29 by ftersill          #+#    #+#             */
/*   Updated: 2025/05/07 10:35:47 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_redirection_2(t_token *tok, int *id)
{
	tok->type = RED_IN;
	if (tok->content && !ft_strncmp((tok + 1)->content, "(", ft_strlen(tok->content)))
	{
		(tok + 1)->type = PARENTHESIS;
		(*id) += 2;	
		return (1);
	}
	return (0);
}

int	is_redirection(t_token *tok, t_data *gen, int *id)
{
	(void)gen;
	if (!ft_strncmp(tok->content, ">", ft_strlen(tok->content)))
		tok->type = RED_OUT;
	else if (!ft_strncmp(tok->content, "<", ft_strlen(tok->content)))
	{
		if (is_redirection_2(tok, id) == 1)
			return (0);
	}
	else if (!ft_strncmp(tok->content, "<<", ft_strlen(tok->content)))
		tok->type = HERE_DOC;
	else if (!ft_strncmp(tok->content, ">>", ft_strlen(tok->content)))
		tok->type = RED_O_APPEND;
	if (!ft_strncmp((tok + 1)->content, "(", ft_strlen(tok->content)))
		return (1);
	if (!ft_strncmp((tok + 1)->content, ")", ft_strlen(tok->content)))
		(*id)++;
	else
	{
		(tok + 1)->type = FILES;
		(*id) += 2;
	}
	return (0);
}
