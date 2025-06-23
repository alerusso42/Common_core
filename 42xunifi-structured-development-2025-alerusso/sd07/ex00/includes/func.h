/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:34:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/21 03:34:30 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H
# include "../header.h"
# include <stdbool.h>

typedef struct s_data	t_data;

//SECTION - Main functions

int		read_file(t_data *data);
int		write_file(t_data *data);
void	trim_spaces(char *line);
void	frontend(t_data *data);
void	search(t_data *data, const char *s, int entry);

//SECTION - Parsing and memory

void	alloc_memory(t_data *data);
void	free_memory(t_data *data);
void	error(t_data *data, int err_type);
void	set_entries(t_data *data);
void	parsing(t_data *data);
bool	unsensitive_check(char c1, char c2);
int		valid_entry(char *line);
int		delete_warning(t_data *data, char *line);
void	prioritize_main_entry(t_data *data, int entry);

//SECTION - Utils

void	print_entries(char *entries[TOTAL_ENTRIES], int print);
int		unsensitive_strncmp(const char *s1, const char *s2, int n);
int		move_str(char *s, char c, int moves);
int		sub_strcmp(const char *s1, const char *s2, char *charset);
void	sort(char **matrix, char type);
void	rewrite_file(t_data *data, char *filedest, char *filesrc);
int		alloc_2d_matrix(char ***matrix, int size);
int		resize_matr(char ***old_matr, int *size);
void	sort_matrix(char **matrix);
int		cmp_to_matrix(char s[MAX_READ + 1], char *entries[TOTAL_ENTRIES]);
void	*free_matrix(char **matrix);
void	print_matrix(t_data *data, char **matrix, char *filename);
void	offset_matrix(t_data *data, int entry);
int		free_all_matrix(t_data *data);

#endif