#include "philo_bonus.h"

void    marchinator(t_table *table)
{
	pid_t   philo;
	int     i;
	int     status;

	i = 0;
	while (i < table->n_philo)
	{
		philo = fork();
		if (philo == -1)
			return (clear(table), exit(1));
		if (philo == 0)
		{
			routine(&table->philo[i]);
		}
		++i;
		ft_wait(10);
	}
	while ((waitpid(-1, &status, WUNTRACED) != -1) && i)
	{
		if (status == 69)
		{
			kill(0);
			break ;
		}
		--i;
	}
}

void	routine(t_philo *philo)
{
	while (1)
	{
		eat_and_sleep();
		think();
	}
}
