#include "../executor.h"

int		parse_prompt(char *s, int *i, char *t_quote);
int		find_something(char *s, char searched, int *i, char *t_quote);
int		get_last_parenthesis(char *s, int dollar_i, int *last_p_i);
void	replace_line(char **s, int start, int end, t_data *gen);
void	stop_program(t_data *gen, int error_type);

int	command_substitution(char **prompt, t_data *gen)
{
	int		i;
	int		dollar_i;
	int		last_p_i;
	char	t_quote;

	i = 0;
	t_quote = 0;
	while ("Loop: expand all valid $() in prompt")
	{
		dollar_i = parse_prompt(*prompt, &i, &t_quote);
		if (!(*prompt)[i])
			return (0);
		else if (dollar_i == -1)
			continue ;
		else if (dollar_i == -2)
			return (1);
		_cut_string(*prompt, dollar_i, dollar_i + 1);
		if (get_last_parenthesis(*prompt, dollar_i, &last_p_i) == 1)
			return (ft_printf("UNCLOSED PARENTHESIS IN CMD SUB (fix this msg)\n"), 1);
		replace_line(prompt, dollar_i, last_p_i, gen);
	}
	(void)gen;
}

int	parse_prompt(char *s, int *i, char *t_quote)
{
	int		dollar_i;
	int		frst_p_i;

	dollar_i = find_something(s, '$', i, t_quote);
	if (dollar_i == -1)
		return (-1);
	++(*i);
	frst_p_i = find_something(s, '(', i, t_quote);
	if (frst_p_i == -1)
	{
		ft_printf("%d: KO!\t|%s|\n", dollar_i, s + dollar_i);
		return (-1);
	}
	else if (frst_p_i == -2)
	{
		return (ft_printf("$\"() and $''() are INVALID (fix this msg)\n"), -2);
	}
	ft_printf("%d: OK!\t|%s|\n", dollar_i, s + dollar_i);
	return (dollar_i);
}

int	find_something(char *s, char searched, int *i, char *t_quote)
{
	char	invalid_quotes;

	invalid_quotes = 0;
	while (s[*i])
	{
		if (*t_quote == s[*i])
			*t_quote = 0;
		else if ((!*t_quote) && (s[*i] == '\'' || s[*i] == '\"'))
			*t_quote = s[*i];
		else if (!*t_quote && s[*i] == searched)
			break ;
		else if (searched != '$')
			return (-1);
		if (searched != '$' && *t_quote)
			invalid_quotes = 1;
		++(*i);
	}
	if (!s[*i])
		return (-1);
	else if (invalid_quotes)
		return (-2);
	return (*i);
}

int	get_last_parenthesis(char *s, int dollar_i, int *last_p_i)
{
	int		layer;
	int		i;
	char	t_quote;

	i = dollar_i;
	t_quote = 0;
	layer = 1;
	while (s[i])
	{
		if (t_quote == s[i])
			t_quote = 0;
		else if ((!t_quote) && (s[i] == '\'' || s[i] == '\"'))
			t_quote = s[i];
		else if (!t_quote && s[i] == '(')
			layer += 1;
		else if (!t_quote && s[i] == ')')
			layer -= 1;
		if (layer == 0)
			break ;
		++i;
	}
	if (!s[i])
		return (1);
	*last_p_i = i;
	return (0);
}

void	replace_line(char **s, int start, int end, t_data *gen)
{
	char	*sub_prompt;

	(*s)[end] = 0;
	sub_prompt = ft_strdup(*s + start);
	if (!sub_prompt)
		stop_program(gen, E_MALLOC);
	(*s)[end] = ' ';
	_cut_string(*s, start, end);
	free(sub_prompt);
}

void	stop_program(t_data *gen, int error_type)
{
	t_exec	exec;

	exec = (t_exec){0};
	exec.main_struct_pointer = gen;
	error(error_type, &exec);
}
