/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   average.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:33:27 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/10 11:56:09 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVERAGE_H
# define AVERAGE_H

# include "sys/time.h"
# include "stdio.h"
# include "limits.h"

# define SIZE 100

float	average(const int *arr, int size);

#endif