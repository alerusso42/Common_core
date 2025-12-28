/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:16:24 by codespace         #+#    #+#             */
/*   Updated: 2025/11/27 17:06:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft.h"
#include "../files/mfile.h"

typedef struct s_fd t_fd;

void	ft_putchar_fd(char c, t_fd fd);
void	ft_putendl_fd(char *s, t_fd fd);
void	ft_putnbr_fd(int n, t_fd fd);
void	ft_putstr_fd(char *s, t_fd fd);
int		fd_printf(t_fd fd, const char *str, ...);
int	    ft_printf(int fd, const char *str, ...);

#endif