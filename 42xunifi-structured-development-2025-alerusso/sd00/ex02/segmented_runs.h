/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segmented_runs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:33:27 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/12 09:19:56 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEGMENTED_RUNS_H
# define SEGMENTED_RUNS_H

# include <sys/time.h>
# include <sys/wait.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

# define SIZE 100

int	count_segments(const int *arr, int size);
int	random(int size);

#endif