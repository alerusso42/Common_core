#include "philo_bonus.h"

static bool	check(t_philo *philo)
{
	long	time;

	time = getcorrecttime();
	if ((time - philo->last_dinner_time) >= philo->table->t_death / 1000)
		return (true);
	return (false);
}

void	write_status(int action, t_philo *philo)
{
	long	time;

	if (philo->full)
		return ;
	time = (getcorrecttime() - philo->table->start_program);
	sem_wait(philo->table->write_sem);
	if (check(philo))
	{
		printf("%-6ld %-2d has died\n", time, philo->id);
		sem_post(philo->table->write_sem);
		clear(philo->table);
		exit(69);
	}
	if (action == FORK)
		printf("%-6ld %-2d has taken a fork\n", time, philo->id);
	else if (action == THINKING)
		printf("%-6ld %-2d is thinking\n", time, philo->id);
	else if (action == EATING)
		printf("%-6ld %-2d is eating\n", time, philo->id);
	else if (action == SLEEPING)
		printf("%-6ld %-2d is sleeping\n", time, philo->id);
	sem_post(philo->table->write_sem);
}

static long	ft_number_long(const char *c, int x, int sign)
{
	long	num;

	num = 0;
	while ((c[x] >= 48) && (c[x] <= 57))
	{
		num = num * 10 + (c[x] - '0');
		x++;
	}
	if (sign == 1)
		return (num * -1);
	return (num);
}

long	ft_atol(const char *nptr)
{
	int	x;
	int	sign;

	x = 0;
	sign = 0;
	while ((nptr[x] == 32) || ((nptr[x] >= 9) && (nptr[x] <= 13)))
		x++;
	if (nptr[x] == 43)
		x++;
	else if (nptr[x] == 45)
	{
		sign = 1;
		x++;
	}
	else if ((nptr[x] < 48) || (nptr[x] > 57))
		return (0);
	return (ft_number_long(nptr, x, sign));
}

long	getcorrecttime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long)((tv.tv_sec * 1e3) + (tv.tv_usec / 1e3)));
}

int	ft_wait(long pause)
{
	struct timeval	start;
	struct timeval	curr;
	long long int	rem;
	long long int	elapsed;

	gettimeofday(&start, NULL);
	elapsed = 0;
	while (elapsed < pause)
	{
		gettimeofday(&curr, NULL);
		elapsed = ((curr.tv_sec - start.tv_sec) * 1e6) \
		+ (curr.tv_usec - start.tv_usec);
		rem = pause - elapsed;
		if (rem > 1000)
			usleep(rem / 2);
	}
	return (0);
}