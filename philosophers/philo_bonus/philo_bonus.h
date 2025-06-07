#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <stdarg.h>
# include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <malloc.h>
#include <semaphore.h>
#include <fcntl.h>

#define SEM_NAME "sem"

enum	e_action
{
	SLEEPING,
	EATING,
	THINKING,
	FORK
};

typedef struct s_table	t_table;

typedef struct s_philo
{
	int					id;
	long				last_dinner_time;
	long				meal_counter;
	bool				full;
	t_table				*table;
}						t_philo;

typedef struct s_table
{
	t_philo				*philo;
    sem_t				*fork_sem;
	sem_t				*write_sem;
	long				n_philo;
	long				t_death;
	long				t_eat;
	long				t_sleep;
	long				max_dinner;
	long				start_program;
	// bool				end_program;
}						t_table;

int		parsing(char **argv);
long	ft_atol(const char *nptr);
void	init_table(t_table *table);
void	clear(t_table *table);
long	getcorrecttime(void);
int		ft_wait(long pause);
void	write_status(int action, t_philo *philo);

#endif