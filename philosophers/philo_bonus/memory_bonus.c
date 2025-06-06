#include "philo_bonus.h"

void	init_table(t_table *table)
{
	int	    i;
	t_philo	*philo;

	i = 0;
	table->end_program = false;
	table->philo = malloc(table->n_philo * (sizeof(t_philo)));
	if (table->philo == NULL)
		return (free(table->fork), printf("MALLOC HAS...FAILED?!"), exit(1));
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
	table->sem = sem_open(SEM_NAME, O_CREAT, 0666, table->n_philo);
    if (table->sem == SEM_FAILED)
		return (clear(table), exit(1));
	sem_unlink(SEM_NAME);
}

void	clear(t_table *table)
{
	if (sem)
		sem_close(table->sem);
	free(table->fork);
	free(table->philo);
}
