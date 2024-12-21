/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:04:13 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/17 11:12:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// [flags][width](NO_FLAGS?)[precision + length][SPECIFIER, if not ERROR]
// in caso di errore, continui a stampare finche non trovi % oppure \0.
// NON devi passare all'argomento dopo, poiche l'originale non lo fa.
// Per fare questo, salviamo la posizione iniziale variabile temporanea t.
// Ci sono 2 esiti possibili:
// 1) In caso di errore di malloc/struttura illegale, si torna ERROR.
// 2) In ogni altro caso, si torna le informazioni sulla struttura.
// Per il debug: print_struct(*data)
int	validate_struct(const char *str, t_printdata **data, size_t *index)
{
	size_t	save_index;

	save_index = (*index)++;
	if (reset_printdata(data) == ERROR)
		return (0);
	while ((str[*index]) && (is_flags(str[*index], (*data))))
		++(*index);
	if (is_width(str, index, (*data), save_index) == ERROR)
		return (ERROR);
	if (is_flags(str[*index], (*data)))
		return (ERROR);
	if ((str[*index]) && (str[*index] == '.'))
	{
		if (precision(str, index, (*data), save_index) == ERROR)
			return (ERROR);
	}
	if (is_specifier(str[*index]) == ERROR)
	{
		*index = save_index;
		return (ERROR);
	}
	if (str[*index] == 'p')
		(*data)->print_address = 1;
	override_rules((*data));
	return (0);
}

int	reset_printdata(t_printdata **data)
{
	if (!(*data))
	{
		(*data) = (t_printdata *)ft_calloc(1, sizeof(t_printdata));
		if (!(*data))
			return (ERROR);
	}
	(*data)->precision_length = 0;
	(*data)->is_alt_form = 0;
	(*data)->is_expsign_flag = 0;
	(*data)->is_minus_flag = 0;
	(*data)->is_precision = 0;
	(*data)->is_space_flag = 0;
	(*data)->is_width = 0;
	(*data)->is_width_zero = 0;
	(*data)->is_zero_flag = 0;
	(*data)->width_value = 0;
	(*data)->print_address = 0;
	return (0);
}

int	is_flags(char c, t_printdata *data)
{
	if (c == '-')
		data->is_minus_flag = 1;
	else if (c == '0')
		data->is_zero_flag = 1;
	else if (c == '#')
		data->is_alt_form = 1;
	else if (c == ' ')
		data->is_space_flag = 1;
	else if (c == '+')
		data->is_expsign_flag = 1;
	else
		return (FALSE);
	return (TRUE);
}

int	is_width(const char *str, size_t *i, t_printdata *data, size_t s_i)
{
	if (!(str[*i]) || !((str[*i] >= '0') && (str[*i] <= '9')))
		return (FALSE);
	data->width_value = ft_atoi(&(str[*i]));
	if (data->width_value == 0)
	{
		while (str[*i] == '0')
		{
			++(*i);
		}
		return (0);
	}
	if (data->width_value < 0)
	{
		*i = s_i;
		return (ERROR);
	}
	while ((str[*i] >= '0') && (str[*i] <= '9'))
		++(*i);
	data->is_width = 1;
	if (data->is_zero_flag == 1)
		data->is_width_zero = 1;
	return (0);
}

// Copy of flags_manage. Changes:
// 1) if after the . there is a specifiers, set the precision to zero;
// 2) if precision is negative, return ERROR.
int	precision(const char *str, size_t *i, t_printdata *data, size_t s_i)
{
	(*i) += 1;
	if (!(str[*i]) || (!((str[*i] >= '0') && (str[*i] <= '9')) && \
	(is_specifier(str[*i]) == 1)))
		return (ERROR);
	data->is_precision = 1;
	data->precision_length = 0;
	if (is_specifier(str[*i]) == 0)
		return (0);
	data->precision_length = ft_atoi(&(str[*i]));
	if (data->precision_length == 0)
	{
		while (str[*i] == '0')
		{
			++(*i);
		}
		return (0);
	}
	if (data->precision_length < 0)
	{
		*i = s_i;
		return (ERROR);
	}
	while ((str[*i] >= '0') && (str[*i] <= '9'))
		++(*i);
	return (0);
}
