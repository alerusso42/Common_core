/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:54:27 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/31 09:03:50 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../header/header.h"

int	someone_else_died(t_philo *philo)
{
	if (philo->state == DEAD)
		return (false);
	get_current_time(&philo->time, &philo->current_time);
	if (*philo->someone_died == true)
	{
		philo->state = DEAD;
		return (true);
	}
	if (philo->current_time - philo->last_meal_time >= \
		philo->time_to_die * MSECONDS)
	{
		*philo->someone_died = true;
		philo->state = DEAD;
	}
	return (false);
}
