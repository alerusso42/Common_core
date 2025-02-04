/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_define_list_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:30:07 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/04 16:56:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_DEFINE_LIST_BONUS_H
# define PUSH_DEFINE_LIST_BONUS_H

//	ERRORS
# define ER_HIDDEN_ERROR -1
# define ER_MALLOC_ERROR 1
# define ER_BAD_ARGC 2
# define ER_REPEATED_NUM 3
# define ER_BAD_CHAR 4
# define ER_STACK_CORRUPTION 5
# define ER_SIZE_OVERFLOW 6
# define ER_ATOI 7
//	STORAGE STACKS COMMANDS
# define GET_A 1
# define GET_B 2
# define FILL_A 3
# define FILL_B 4
//	VARIABLES COMMANDS
# define CORRECTION 0
# define PRINT_MODIFICATIONS 1
# define PRINT_FINAL_RESULT 2
# define PLAY 3
//	SWITCH BOOLEANS
# define OFF 0
# define ON 1
# define NO 0
# define YES 1
# define PRINT 1
# define DONT_PRINT 0
//	COMMANDS
# define RA 1
# define RRA 2
# define SA 3
# define SB 4
# define SS 5
# define PA 6
# define PB 7
# define RB 8
# define RR 9
# define RRB 10
# define RRR 11
# define DELETE 12
//	MALLOC_CHUNKS
# define ENVISIONED_MOVES_NUM 8192
//	WHICH_ALGORYTHM
# define RADIX_SORT 0
# define INSERTION_SORT 1

#endif