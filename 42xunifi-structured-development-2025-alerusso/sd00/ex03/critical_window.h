/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_window.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:33:27 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/12 09:18:31 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRITICAL_WINDOW_H
# define CRITICAL_WINDOW_H

# include <sys/time.h>
# include <sys/wait.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

# define SIZE 7

int		count_critical_windows(const int *readings, int size);
int		random(int size);

#endif