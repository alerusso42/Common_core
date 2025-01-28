/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_function_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:42:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/28 17:23:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_FUNCTION_LIST_H
# define PUSH_FUNCTION_LIST_H

//	UTILITIES
int		error(int error_type);
int		l_printf(const char *str, ...);
//	MEMORY
int		alloc_data(t_stack **a, t_stack **b, int size);
t_stack	*store_stacks(t_stack *stack, int mode);
void	free_memory(t_stack **a, t_stack **b);
void	free_three_d_matrix(char ***matrix);
//	PARSING
int		parsing(int argc, char *argv[], t_stack **a, t_stack **b);
int		get_data(int argc, t_stack **a, t_stack **b);
int		fill_stacks(t_stack *a, char ***matrix);
//	PRINT
void	print_stacks(t_stack *a, t_stack *b);
//	COMMANDS
void	sa(void);
void	sb(void);
void	ss(void);

#endif