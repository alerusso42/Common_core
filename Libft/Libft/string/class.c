/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:55:45 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/15 19:25:19 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
		
t_str	str_constructor(t_str *str, char *buff)
{
	printf("%s\tconstructor\n", buff);
	*str = (t_str){0};
	if (_str_get_methods(str) != EXIT_SUCCESS)
		return (*str);
	if (dup(str, buff)->err != EXIT_SUCCESS)
		return (*str);
	str->npos = UINT32_MAX;
	str->len = get_len(str);
	str->begin = (uintptr_t)(void *)&str->buff;
	str->half = (uintptr_t)(void *)&str->buff + (str->len / 2);
	str->end = (uintptr_t)(void *)&str->buff + str->len;
	return (*str);
}

void	str_destructor(t_str *str)
{
	printf("%s\tdestructor\n", str->buff);
	_str_get_methods(NULL);
	FREE(str->buff);
}

int	main()
{
	STR(s, "ROCKY1");
	STR(s2, "ROCKY2");
	STR(s3, "ROCKY3");
	s3.m->dup_str(&s3, &s2);
	return (0);
}
