/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:20:15 by alerusso          #+#    #+#             */
/*   Updated: 2025/05/30 16:44:35 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

int	time_delay_test(void)
{
	struct timeval	time_one;
	struct timeval	time_two;
	long long int	diff;
	long long int	pause;
	int				err;

	pause = 1 * MSECONDS;
	err = 0;
	while (pause != 300 * MSECONDS)
	{
		err = gettimeofday(&time_one, NULL);
		err = ft_wait(pause);
		if (err != 0)
			return (err);
		err = gettimeofday(&time_two, NULL);
		diff = ((time_two.tv_sec - time_one.tv_sec) * 1000000);
		diff += (time_two.tv_usec - time_one.tv_usec);
		diff -= pause;
		l_printf("\nDiff for a %d pause:\t%d\n", pause, diff);
		if (diff > 100)
			return (p_color(RED, "\n\n\n\n\nWARNING!!!!!\n\n\n\n"));
		pause += 1 * MSECONDS;
	}
	p_color(GREEN, "\n\nDELAY TEST OK!\n\n");
	return (err);
}

int	p_color(int color, char *s)
{
	return (l_printf("\033[%dm%s\033[0m", color, s));
}

int	p_state(t_philo *philo, int state)
{
	if (philo->state == DEAD)
		return (DEAD);
	pthread_mutex_lock(philo->write_mutex);
	get_current_time(&philo->time, &philo->current_time);
	if (someone_else_died(philo) == true)
	{
		return (pthread_mutex_unlock(philo->write_mutex));
	}
	get_current_time(&philo->time, &philo->current_time);
	if (philo->state == DEAD)
		l_printf(M_DEAD, philo->current_time / MS, philo->id);
	else if (state == THINK)
		l_printf(M_THINK, philo->current_time / MS, philo->id);
	else if (state == EAT)
		l_printf(M_EAT, philo->current_time / MS, philo->id);
	else if (state == SLEEP)
		l_printf(M_SLEEP, philo->current_time / MS, philo->id);
	else if (state == FORK)
		l_printf(M_FORK, philo->current_time / MS, philo->id);
	pthread_mutex_unlock(philo->write_mutex);
	return (0);
}
