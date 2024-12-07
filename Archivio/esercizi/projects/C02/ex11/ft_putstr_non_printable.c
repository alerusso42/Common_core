/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/09/16 10:51:36 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putstr_non_printable(char *str);
void	hex(char *str, int i);
//int end_check(char *str, int i);

/*int main(void)
{
    char    argv[22] = "Coucou\ntu vas bien ?";
    
    //argv[2] = 26;
    ft_putstr_non_printable(argv);
    return (0);
}
*/

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == 127) || (str[i] < 32))
		{
			write(1, "\\", 1);
			hex(str, i);
		}
		else
			write(1, &str[i], 1);
		++i;
	}
}
/*
int end_check(char *str, int i)
{
    int is_end;
    int response;

    response = 0;
    is_end = 0;
    while (is_end != 4)
    {
        if (str[i] != '\0')
            response = 1;
    ++is_end;    
    }
    return (response);
}
*/

void	hex(char *str, int i)
{
	int		hex;
	int		temp;
	char	temp_str[20];

	hex = str[i] + 0;
	i = 19;
	temp_str[i] = '0';
	temp_str[18] = '0';
	while (hex != 0)
	{
		temp = hex % 16;
		hex = hex / 16;
		if (temp > 9)
		{
			temp = temp - 10;
			temp = 'a' + temp;
		}
		else
			temp = temp + '0';
		temp_str[i--] = temp;
	}
	if (temp_str[18] == '0')
		write(1, &temp_str[18], 1);
	while (temp_str[++i])
		write(1, &temp_str[i], 1);
}
/*
0 - 31, 127.*/
