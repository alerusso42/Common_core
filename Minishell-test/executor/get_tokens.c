/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:03:58 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/25 15:22:59 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	merge_one(t_token *token, int debug, int i, bool update_type);
static void	sort_id(t_token *token);

/*REVIEW - merge_tokens

//		Before launching execution for a command, we have to
		change a bit the token taken from parsing part:

		1)	We need a new type, RED_SUBSHELL, for <().
		This:	cat <(ls)
				Command		token		type			prior
				//cat		cat			command (0)		0
				//<			<			RED_IN	(4)		0
				//ls		ls			command (0)		1
		Becomes:
				Command		token		type			prior
				//cat		cat			command (0)		0
				//<			<			RED_SUBSHELL(10)0
				//ls		ls			command (0)		1
		
		2)	We need to shift all files in the same token of the
			redirector sign:
		This:	cat < file
				Command		token		type			prior
				//cat		cat			command (0)		0
				//<			<			RED_IN	(4)		0
				//file		file		files 	(2)		0
		Becomes:
				Command		token		type			prior
				//cat		cat			command (0)		0
				//<			file		RED_IN (4)

		In order to do this two changes:
		1)	We loop for all tokens;
		2)	If the token is <, and the next token has a different priority
			(so there is <(...)), mark the token as a RED_SUBSHELL;
		3)	Else, if is a regular redirector sign (<, <<, >, >>), merge it with
			its file;
		4)	We restart the loop, to merge '(' and ')';
		5)	Lastly, sort the id of every token.
*/
void	merge_tokens(t_token *token, int debug)
{
	int	i;

	i = 0;
	while (token[i].content)
	{
		if (token[i].type == RED_IN && token[i].prior != token[i + 1].prior)
		{
			token[i].type = RED_SUBSHELL;
			token[i].prior += 1;
		}
		else if (is_red_sign(token[i].type))
		{
			merge_one(token, debug, i, 0);
		}
		i++;
	}
	i = 0;
	while (token[i].content)
	{
		if (token[i].content[0] == '(' || token[i].content[0] == ')')
			merge_one(token, debug, i, 1);
		else
			++i;
	}
	sort_id(token);
}

/*
void	p_tok(t_token *token)
{
	int i = 0;
	while (token[i].content)
	{
		_fd_printf(1, "\n^^\n%d:", i);
		_fd_printf(1, "\ncont:\t%s", token[i].content);
		_fd_printf(1, "\ntype:\t%d", token[i].type);
		_fd_printf(1, "\nid:\t%d", token[i].id);
		_fd_printf(1, "\nprior:\t%d", token[i].prior);
		++i;
	}
}
*/

/*REVIEW - merge_one

//		1)	If we are not in debug mode, free the current content ('>');
		2)	We update ONLY the content;
		3)	For every other token after current token,
			we drag them one position behind.
*/
static void	merge_one(t_token *token, int debug, int i, bool update_type)
{
	int	j;

	if (!debug)
		free(token[i].content);
	token[i].content = NULL;
	token[i].content = token[i + 1].content;
	if (update_type)
	{
		token[i].type = token[i + 1].type;
		token[i].prior = token[i + 1].prior;
	}
	i++;
	j = i;
	while (token[i].content && token[++j].content)
		token[i++] = token[j];
	token[i] = token[j];
}

/*REVIEW - merge_one

//		Every token is indexed with its position in the token array.
		This index is its ID.
*/
static void	sort_id(t_token *token)
{
	int	i;
	int	j;
	int	cmd_num;
	int	current_layer;

	i = 0;
	cmd_num = 0;
	while (token[i].content)
	{
		j = i;
		current_layer = token[j].prior;
		while (token[j].content && current_layer <= token[j].prior)
		{
			token[j].cmd_num = cmd_num;
			token[j].id = j;
			++j;
		}
		++cmd_num;
		while (token[i].content && \
			 current_layer == token[i].prior && !is_exec_sep(token[i].type))
			++i;
	}
	token[i].cmd_num = cmd_num;
	token[i].prior = -1;
	token[i].id = -1;
}
