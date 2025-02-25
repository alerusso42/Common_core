/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_function_list_bonus.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:42:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/25 16:18:36 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_FUNCTION_LIST_BONUS_H
# define PUSH_FUNCTION_LIST_BONUS_H

//	UTILITIES
int		error(int error_type);
int		l_printf(const char *str, ...);
void	switches(t_settings *settings, t_stack *a);
void	variables(t_settings *settings, t_stack *a, t_stack *b);
void	switch_to_bonus(t_settings *settings, t_stack *a);
//	MEMORY
int		alloc_data(t_stack **a, t_stack **b, int size);
t_stack	*store_stacks(t_stack *stack, int mode);
void	free_memory(t_stack **a, t_stack **b);
void	free_three_d_matrix(char ***matrix);
//	PARSING
int		parsing(int argc, char *argv[], t_stack **a, t_stack **b);
int		get_data(int argc, t_stack **a, t_stack **b);
int		fill_stacks(t_stack *a, char ***matrix);
void	find_biggest(t_stack *a);
//	PRINT
void	print_stacks(void);
void	print_moves(void);
//	COOL_STUFF
int		random_test(char *argv[]);
int		alloc_randomlist(t_random **random, int numbers_len);
int		get_randomlist(t_random *random, int numbers_len);
//	GENERAL
char	*ft_binary(int num, char result[33], int mlen);
int		ft_abs(int num);
void	find_half(t_stack *a, t_stack *b);
void	switch_data(t_data *one, t_data *two);
//	COMMANDS
void	sa(void);
void	sb(void);
void	ss(void);
void	pa(void);
void	pb(void);
void	ra(void);
void	rb(void);
void	rr(void);
void	rra(void);
void	rrb(void);
void	rrr(void);
void	command_counter(unsigned char command);
//	EXECUTE
int		play(void);
int		checker(void);
void	radix_sort(t_stack *a, t_stack *b);
void	insertion_sort(t_stack *a, t_stack *b);
//	ALGORYTHM TOOLS
void	assure_left_stack(t_stack *a, t_stack *b);
void	set_data_to_zero(t_stack *a, t_stack *b);
void	find_smallest_bigger(t_stack *a, t_stack *b);
void	update_cost(t_stack *a, t_stack *b);
void	choose_cheepest(t_stack *a, t_stack *b);
void	push_one(t_stack *a, t_stack *b);
void	final_rotation(t_stack *a);
//	OPTIMIZE
void	doctor_strange(t_stack *a);
void	indexation(t_stack *a);
void	best_start(t_stack *a);
void	move_unsorted_to_b(t_stack *a);
void	choose_medium_area(t_stack *a, int num);
//	BONUS: CHECKER
int		read_terminal(t_stack *a);
void	test(t_stack *a);

#endif