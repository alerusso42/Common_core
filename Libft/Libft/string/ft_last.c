/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:44:16 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/20 21:42:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

t_str	*str_last_chr(t_str *this, char other)
{
    int32_t	i;

    if (str_check(this, NULL))
        return (_str_set_error(this, E_PARAM, "last"));
    i = (int32_t)(this->end - this->begin) - 1;
    while (i > this->i && this->buff[i] != other)
        i--;
    if (i <= 0)
        this->i = this->npos;
    else
        this->i = i;
    return (this);
}

t_str	*str_last_char(t_str *this, const char *other)
{
    int32_t	i;
    int32_t	j;

    if (str_check(this, NULL))
        return (_str_set_error(this, E_PARAM, "last"));
    i = (int32_t)(this->end - this->begin) - 1;
    j = 0;
    while (i > this->i && this->buff[i] != other[j])
    {
        j = -1;
        while (other[++j])
            if (this->buff[i] == other[j])
                break ;
        i--;
    }
    if (i <= 0)
        this->i = this->npos;
    else
        this->i = i;
    return (this);
}

t_str	*str_last_str(t_str *this, t_str *other)
{
    int32_t	i;
	
    if (str_check(this, NULL))
        return (_str_set_error(this, E_PARAM, "last"));
    i = (int32_t)(this->end - this->begin) - 1;
    while (i > this->i && this->buff[i] != *other->buff)
    {
        other->buff--;
        while (++other->buff)
            if (this->buff[i] == *other->buff)
                break ;
        i--;
    }
    other->buff = (char *)other->begin;
    if (i <= 0)
        this->i = this->npos;
    else
        this->i = i;
    return (this);
}
