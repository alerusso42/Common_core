/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:48:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/05 14:40:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "../Libft/all.h"
# define SEED 42

typedef struct s_hash
{
	int	key;
	int	pos;
}	t_hash;

typedef struct s_data
{
	t_fd	data_fd;
	t_fd	hash_fd;
	char	separator[3];
	t_hash	*hash_table;
	char	*flags;
	char	*data_file;
	char	*hash_file;
	int		*collision;
	int		file_num;
	int		file_size;
	int		hash_size;
}	t_data;

enum e_error
{
	ER_OK,
	ER_OPEN,
	ER_ATOI,
	ER_MALLOC,
};

//SECTION -	collision

void	collision_update(t_data *data, int old_key, int lowest_key, int *i);
int		collision_check(t_data *data, int hash_pos);

//SECTION -	fill_hash_table

void	fill_hash_table(t_data *data);

//SECTION -	hash

int		ft_hash(t_data *data, char *key);

//SECTION -	memory

void	alloc_memory(t_data *data);
void	free_memory(t_data *data);
void	error(t_data *data, int err_type);

//SECTION -	parse_args

void	parse_args(t_data *data, char *argv[]);

//SECTION -	print

void	print_filedata(t_data *data);
void	print_hash_table(t_data *data);

//SECTION -	utils

void	make_float(t_data *data, char *str, double *result);
int		num_size(int n);
int		count_char(char *str, char c);
int		ft_abs(int n);
void	find_lowest_key(t_data *data, int *lowest_key, int *struct_i);

#endif