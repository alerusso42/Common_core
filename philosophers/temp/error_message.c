/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:41:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/31 09:13:57 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header/header.h"

static int	other_messages(int error);
static int	other_messages2(int error);
static int	other_messages3(int error);

int	error(t_data *data, int error)
{
	reset_memory(data);
	return (other_messages(error));
}

static int	other_messages(int error)
{
	return (other_messages2(error));
}

static int	other_messages2(int error)
{
	if (error == ER_BAD_ARGC)
	{
		return (fd_printf(2, "Error\nYour program must take the following\
 arguments:\n\
number_of_philosophers time_to_die time_to_eat time_to_sleep\n\
[number_of_times_each_philosopher_must_eat]\n\n\
1) number_of_philosophers: The number of philosophers and forks.\
\n\
2) time_to_die (ms): If a philosopher hasn't eaten within \
time_to_die\n\
ms since their last meal or the start, they die.\n\
3) time_to_eat (ms): Time it takes a philosopher to eat,\
requiring\ntwo forks.\n\
4) time_to_sleep (ms): Time a philosopher spends sleeping.\n\
5) number_of_times_each_philosopher_must_eat (optional): If all\n\
philosophers have eaten at least this many times, the \
simulation\n\
stops. If not specified, it stops when a philosopher dies.\n\n"));
	}
	return (other_messages3(error));
}

static int	other_messages3(int error)
{
	if (error == ER_PARSING)
	{
		return (fd_printf(2, "Error\nCommand not found. Please try another\
			combination."));
	}
	else
		return (fd_printf(2, "Generic error\n"));
}
