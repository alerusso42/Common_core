/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:34:03 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/18 19:32:34 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "../header.h"

# define SEED 42
# define TO_TRIM " "
# define BUFFER_SIZE 1000

typedef struct s_data	t_data;

struct s_data
{
	int		last_error;
};

enum e_errors
{
	ER_MALLOC,
	ER_OPEN,
	ER_PARSING,
};

#endif