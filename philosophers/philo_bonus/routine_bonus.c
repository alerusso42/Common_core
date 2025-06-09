#include "philo_bonus.h"

void	*death_guardian(void *philo);

void	routine(t_philo *philo)
{
	philo->last_dinner_time = philo->table->start_program;
	pthread_create(philo->table->guardian, NULL, death_guardian, (void *)philo);
	while (1)
	{
		ft_wait(100);
		if (eat_and_sleep(philo) == FULL)
			exit(0);
		think(philo);
	}
}

void    marchinator(t_table *table)
{
	pid_t   philo;
	int     i;
	int     status;

	i = 0;
	table->start_program = getcorrecttime();
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
		if (status / 256 == 69)
		{
			kill(0, SIGKILL);
			printf("HAHAHA SONO INVINCIBILE");
			break ;
		}
		--i;
	}
}

static bool	check(t_philo *philo, long time_eat)
{
	long	time;

	time = getcorrecttime();
	if ((time - time_eat) >= philo->table->t_death)
		return (true);
	return (false);
}

void	*death_guardian(void *data)
{
	t_philo	*philo;
	long	time;

	philo = (t_philo *)data;
	while (1)
	{
		ft_wait(100);
		time = get_long(&philo->table->mutex, &philo->last_dinner_time);
		if (check(philo, time))
		{
			sem_wait(philo->table->write_sem);
			printf("%-6ld %-2d died\n", time, philo->id);
			//sem_post(philo->table->write_sem);
			clear(philo->table);
			exit(69);
		}
	}
	return (NULL);
}
