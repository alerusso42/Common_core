/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:28:42 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/18 09:49:23 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <malloc.h>
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"
// define usati nel programma
# define ERROR 1
# define MISSING 1
# define TRUE 1
# define FALSE 0
# define SPACES 1
# define ZEROS 2
# define PRECISION 3

typedef struct s_printdata
{
	unsigned int	is_minus_flag:1;
	unsigned int	is_alt_form:1;
	unsigned int	is_space_flag:1;
	unsigned int	is_expsign_flag:1;
	unsigned int	is_zero_flag:1;
	unsigned int	is_width:1;
	unsigned int	is_width_zero:1;
	unsigned int	width_value;
	unsigned int	is_precision:1;
	unsigned int	precision_length;
	unsigned int	print_address:1;
	unsigned int	save_index_position;
}					t_printdata;

typedef unsigned long long int	t_address;
typedef unsigned char			t_uchar;

void	print_struct(t_printdata *data);
int		ft_printf(const char *str, ...);
int		validate_struct(const char *str, t_printdata **data, size_t *index);
int		reset_printdata(t_printdata **data);
int		is_flags(char c, t_printdata *data);
int		is_width(const char *str, size_t *i, t_printdata *data, size_t s_i);
int		precision(const char *str, size_t *i, t_printdata *data, size_t s_i);
size_t	go_next(const char *str, size_t *index);
int		type_print(char type, va_list ptr, size_t *counter, t_printdata *data);
void	ft_putnbr(int num);
void	print(const char *str);
void	write_flags(unsigned int size, size_t flag);
size_t	print_char(unsigned char character, t_printdata *data);
size_t	print_string(unsigned char *string, t_printdata *data);
size_t	print_signed_int(int num, t_printdata *data);
size_t	print_lower_hex(unsigned int num, t_printdata *data);
size_t	print_upper_hex(unsigned int num, t_printdata *data);
size_t	print_unsigned_int(unsigned int num, t_printdata *data);
size_t	print_address(void *address, t_printdata *data);
int		is_specifier(char specifier);
void	override_rules(t_printdata *data);
size_t	precision_and_zero(int num, t_printdata *data);

/* 	printf("%[flags][width][.precision][length]specifier", variable);
	
	RULES
	1) specifiers must be at the end
	2) the flags can be at any order
	3) some flags overrides others
	4) width, .precision, lenght and the specifier have fixed order
	
	SUMMARY OF FLAGS AND AESTHETIC COMMAND:
	1) - :Left alignment 	--->Ov. 2
	2) 0 :Zero padding  	--->
	3) . :Precision			--->Ov. 2, makes 5(if true) 4
	4) MR:Minimal width		--->
	5)MR0:Min. width + 0	--->Ov. 4 
	6) # :Alternative form	--->
	7)   :Space				--->
	8) + :Explicit sign		--->Ov. 7
	*/
#endif