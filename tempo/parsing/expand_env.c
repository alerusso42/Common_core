/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:55:30 by ftersill          #+#    #+#             */
/*   Updated: 2025/05/06 21:06:14 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	insert_var_env(char *search, t_token *token, int *i, char *temp)
{
	char	*dup;
	int		k;
	int		j;
	
	k = 0;
	j = 0;
	dup = ft_strdup(token->content);
	free(token->content);
	token->content = (char*)ft_calloc(ft_strlen(dup) + ft_strlen(temp) + \
		ft_strlen(search) + 1, sizeof(char));
	if (!token->content)
		return /* MALLOC ERROR */;
	while (j < (*i))
		token->content[k++] = dup[j++];
	if (dup[j] == '$' && dup[j] != '\0')
	{
		j = 0;
		while (j < (int)ft_strlen(search))
			token->content[k++] = search[j++];
	}
	j = (*i) + ft_strlen(temp) + 1;
	while (dup[j] != '\0')
		token->content[k++] = dup[j++];
	free(dup);
}

// CHIEDERE AL FHURER ALERUSSO SE LA GESTIONE DEI DELLARI SINGOLI DEVE ESSERE GESTITA

// tok = token, norminette is a piece of shit
void	expand_var(t_token *tok, int *i ,t_data *gen, char *search)
{
	char	*temp;

	temp = NULL;
	if (tok->content[(*i)] == '\"')
	{
		(*i)++;
		while (tok->content[(*i)] && tok->content[(*i)] != '\"')
		{
			if (tok->content[(*i)] && tok->content[(*i)] == '$' && \
			tok->content[(*i) + 1] != '\"' && tok->content[(*i) + 1] != '\'' \
			&& tok->content[(*i) + 1] != ' ')
			{
				temp = what_to_search(tok, i);
				search = get_env(gen->env, temp);
				if (search)
					insert_var_env(search, tok, i, temp);
				else
					skip_env_var(tok, i, temp); // caso dello spazio da gestire
			}
			else
				(*i)++;
		}
		(*i)++;
	}
	free(temp);
}

void	expand_var_alone(t_token *tok, int *i ,t_data *gen, char *search)
{
	char	*temp;

	temp = NULL;
	if (tok->content[(*i)] == '$' && tok->content[(*i) + 1] && \
	tok->content[(*i) + 1] != '\"' && tok->content[(*i) + 1] != '\'' // da levare questo controllo anche nelle altre funzioni per questo caso = echo $"HOE"
	&& tok->content[(*i) + 1] != ' ')
	{
		temp = what_to_search(tok, i);
		search = get_env(gen->env, temp);
		if (search)
			insert_var_env(search, tok, i, temp);
		else
			skip_env_var(tok, i, temp);
	}
	else
		(*i)++;
}

// gestisci il caso delle espansioni infinite se non ri ricordi chiedi a vale greg o ale
void	expand_env(t_token *token, t_data *gen)
{
	int		id;
	int		i;
	char	*search;

	search = NULL;
	id = -1;
	i = 0;
	while (token[++id].content != NULL)
	{
		i = 0;
		while (token[id].content[i] != '\0')
		{
			if (token[id].content[i] == '\'')
				skip_single_quotes(token[id].content, &i);
			else if (token[id].content[i] == '\"')
				expand_var(&token[id], &i, gen, search);
			else if (token[id].content[i] == '$')
				expand_var_alone(&token[id], &i, gen, search);
			else
				i++;
		}
	}
}

//	funzione chiamata all`interno della funzione remove_quotes_token()
//	nel file remove_quotes.c
//	--serve per espandere le variabili di ambiente all`interno della struttura
void	expanding_variables(t_token *token, t_data *gen)
{
	expand_exit_code(token, gen);
	expand_env(token, gen);
	// expand_wildcards(token, gen);

}
