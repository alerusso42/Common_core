/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:20:15 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/14 17:44:52 by alerusso         ###   ########.fr       */
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
		err = wait(pause);
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
	if (get_current_time(&philo->time, &philo->current_time) != 0)
		return (ER_GETTIMEOFDAY);
	if (philo->current_time - philo->last_meal_time > philo->time_to_die * MSECONDS)
		state = DEAD;
	if (pthread_mutex_lock(philo->write_mutex) != 0)
		return (ER_MUTEX_LOCK);
	if (state == THINK)
		l_printf("%d %d is thinking\n", philo->current_time, philo->id);
	else if (state == EAT)
		l_printf("%d %d is eating\n", philo->current_time, philo->id);
	else if (state == SLEEP)
		l_printf("%d %d is sleeping\n", philo->current_time, philo->id);
	else if (state == FORK)
		l_printf("%d %d has taken a fork\n", philo->current_time, philo->id);
	else if (state == DEAD)
	{
		l_printf("%d %d ", philo->current_time, philo->id);
		p_color(RED, "died\n");
		philo->state = DEAD;
	}
	if (pthread_mutex_unlock(philo->write_mutex) != 0)
		return (ER_MUTEX_LOCK);
	return (0);
}