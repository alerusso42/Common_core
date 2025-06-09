#include "philo_bonus.h"

void	wait_everyone(t_table *table);

void	routine(t_philo *philo)
{
	philo->last_dinner_time = philo->table->start_program;
	while (1)
	{
		if (eat_and_sleep(philo) == FULL)
			exit(0);
		think(philo);
	}
}

void    marchinator(t_table *table)
{
	int     i;
	int     status;

	i = 0;
	table->start_program = getcorrecttime();
	while (i < table->n_philo)
	{
		table->pid_array[i] = fork();
		if (table->pid_array[i] == -1)
			return (clear(table), exit(1));
		if (table->pid_array[i] == 0)
		{
			routine(&table->philo[i]);
		}
		++i;
		ft_wait(10);
	}
	wait_everyone(table);
}

void	wait_everyone(t_table *table)
{
	int	status;
	int	i;

	status = 0;
	i = 0;
	while (table->pid_array[i] && (waitpid(-1, &status, WUNTRACED) != -1))
	{
		if (status / 256 == 69)
		{
			kill(0, SIGKILL);
			printf("HAHAHA SONO INVINCIBILE");
			break ;
		}
		table->pid_array[i] = 0;
		++i;
	}
}

void	kill_everyone(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_philo)
	{
		if (table->pid_array[i])
			kill(table->pid_array[i], SIGKILL);
		++i;
	}
}

#include "philo_bonus.h"

void	open_sem(t_table *table)
{
	table->fork_sem = sem_open(SEM_NAME, O_CREAT, 0666, table->n_philo);
    if (table->fork_sem == SEM_FAILED)
		return (clear(table), exit(1));
	sem_unlink(SEM_NAME);
	table->write_sem = sem_open(SEM_NAME, O_CREAT, 0666, 1);
    if (table->write_sem == SEM_FAILED)
		return (clear(table), exit(1));
	sem_unlink(SEM_NAME);
}

void	init_table(t_table *table)
{
	int	    i;
	t_philo	*philo;

	i = 0;
	table->philo = malloc(table->n_philo * (sizeof(t_philo)));
	if (table->philo == NULL)
		return (printf("MALLOC HAS...FAILED?!"), exit(1));
	table->pid_array = malloc(table->n_philo * (sizeof(pid_t)) + 1);
	if (table->pid_array == NULL)
		return (printf("MALLOC HAS...FAILED?!"), exit(1));
    while (i != table->n_philo)
	{
		philo = table->philo + i;
		philo->id = i + 1;
		philo->meal_counter = 0;
		philo->last_dinner_time = 0;
		philo->full = false;
		philo->table = table;
		i++;
	}
	open_sem(table);
}

void	clear(t_table *table)
{
	if (table->fork_sem)
		sem_close(table->fork_sem);
	if (table->write_sem)
		sem_close(table->write_sem);
	free(table->philo);
	free(table->pid_array);
}

