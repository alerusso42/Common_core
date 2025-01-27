/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_function_list.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:42:52 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/27 12:16:26 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_FUNCTION_LIST_H
# define PUSH_FUNCTION_LIST_H

//	UTILITIES
int		error(int error_type);
int		l_printf(const char *str, ...);
//	MEMORY
int		alloc_data(t_stack **a, t_stack **b, int size);
void	free_memory(t_stack **a, t_stack **b);
//	PARSING
int		get_data(int argc, char *argv[], t_stack **a, t_stack **b);

#endif