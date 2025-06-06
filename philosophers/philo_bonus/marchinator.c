#include "philo_bonus.h"

void    marchinator(t_table *table)
{
    pid_t   philo;
    int     i;

    i = 0;
    while (i < table->n_philo)
    {
        philo = fork();
        if (philo == -1)
            return (clear(table), exit(1));
        if (philo == 0)
        {
            ft_wait()
            child()
        }
        ++i;
    }

}