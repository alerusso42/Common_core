/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:46:20 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/19 16:25:53 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"
#define UN_BOTTO 100

static char	*alloc_string(char *allocated_string, int num, int *index);

/*
int	main(int argc, char *argv[])
{
	int		num;
	char	*str;
	
	if (argc < 2)
	{
		printf("ARGV[1] = num");
		return (0);
	}
	num = atoi(argv[1]);
	str = (char *)malloc(UN_BOTTO);
	if (!str)
		return (2);
	printf("\nItoa di %d: %s\n", num, ft_itoa(num, str));
	free(str);
	return (0);
}*/

char	*ft_itoa(int num)
{
	int		temp_num;
	int		index;
	char	*str;

	index = 0;
	temp_num = num;
	while ((temp_num > 9) || (temp_num < -9))
	{
		index++;
		temp_num /= 10;
	}
	str = NULL;
	str = alloc_string(str, num, &index);
	if (!str)
		return (NULL);
	str[index + 1] = '\0';
	while (num != 0)
	{
		if (num < 0)
			str[index--] = (((num % 10) * -1) + 48);
		else
			str[index--] = ((num % 10) + 48);
		num /= 10;
	}
	return (str);
}

static char	*alloc_string(char *allocated_string, int num, int *index)
{
	if (num < 0)
		*index += 1;
	allocated_string = (char *)ft_calloc((*index) + 2, sizeof(char));
	if (!allocated_string)
		return (NULL);
	if (num < 0)
	{
		allocated_string[0] = '-';
	}
	if (num == 0)
	{
		allocated_string[(*index)] = '0';
	}
	return (allocated_string);
}

t_str	*str_itoa(t_str *this, int32_t value)
{
	FREE(this->buff);
	this->buff = ft_itoa((int)value);
	if (!this->buff)
		this->err = E_ALLOC;
	return (this);
}
