/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_data.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:11:37 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/05 21:11:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_DATA
# define FT_PRINTF_DATA
# include "ft_printf.h"
# include "ansicode.h"
# define MAX_NUMBER_SIZE 21
# define MAX_ANSI_ARG 4
# define MAX_ANSI_SIZE (4 + MAX_ANSI_ARG) // ESC[9999A
# define FT_PRINTF_DEBUG false
# if FT_PRINTF_DEBUG
#  define PRINTF_DEBUG(str, ...)	ft_printf(str, ##__VA_ARGS__)
# else
#  define PRINTF_DEBUG(str, ...)	(void)0
#endif

typedef struct s_ft_printf	t_ft_printf;

void	print_str(t_ft_printf *data, char *s);
void	print_str_len(t_ft_printf *data, char *s, int len);
void	print_char(t_ft_printf *data, char c);
void	print_int(t_ft_printf *data, int64_t n);
void	print_uint(t_ft_printf *data, uint64_t n);

int		ansi_fill(t_ft_printf *data, uint32_t flags, uint8_t type, char *res);

//int fd, const char *str, t_str *buff, va_list *ptr
typedef struct s_ft_printf
{
	t_str		*buff;
	va_list		*args;
	const char	*s;
	int			fd;
	int			len;
}	t_ft_printf;

#endif