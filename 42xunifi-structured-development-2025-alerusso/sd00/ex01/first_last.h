/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_last.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:33:27 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/12 09:21:17 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRST_LAST_H
# define FIRST_LAST_H

# include "sys/time.h"
# include "sys/wait.h"
# include "stdio.h"
# include "limits.h"

# define SIZE 100

void	first_last(int arr[], int size, int target, int *first, int *last);
int		random(int size);

#endif