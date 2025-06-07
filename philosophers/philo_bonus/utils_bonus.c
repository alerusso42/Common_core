#include "philo_bonus.h"

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

/*
	VERSION 2.0 (idea taken from Oceano)

	1)	We record the initial time;
	2)	We set the elapsed time (time from start) to
		zero. we'll loop until it is not bigger than
		the requested pause;
	LOOP:
		3)	We get data about the current time;
		4)	We update elapsed: current - start time;
		5)	We update rem (remaining time):
			requested pause - elapsed time;
		6)	If more than 1 MILLISECOND is left,
			ft_wait half the remaining time.

	This approach allows to sleep the most of the time,
	and to check strictly the last MICROSECONDS using
	gettimeofday.

	Here's an example, for a 10000 microseconds pause,
	Considering gettimeofday errors:

	1 STEP: elapsed is 2 microseconds, therefore
			rem = 9998 (10000 - 2);
			we sleep for rem / 2 = 4999 (9998 / 2);

	TOTAL SLEPT: 4999

	2 STEP: elapsed is 5000 microseconds, therefore
			rem = 5000 (10000 - 5000);
			we sleep for rem / 2 = 2500 (5000 / 2);

	TOTAL SLEPT: 7500

	3 STEP: elapsed is 7501 microseconds, therefore
			rem = 2499 (10000 - 7501);
			we sleep for rem / 2 = 1249 (2500 / 2);

	TOTAL SLEPT: 8750

	4 STEP: elapsed is 8750 microseconds, therefore
			rem = 1250 (10000 - 8750);
			we sleep for rem / 2 = 625 (1250 / 2);

	TOTAL SLEPT: 9375

	5 STEP: elapsed is 9377 microseconds, therefore
			rem = 623 (10000 - 9377);
			WE DONT SLEEP: rem is less than 1000

	TOTAL SLEPT: 9377

	6 STEP and so on: we rely only on gettimeofday errors.

	TOTAL SLEPT: 9378
	TOTAL SLEPT: 9378
	TOTAL SLEPT: 9380
	TOTAL SLEPT: 9381
	...
	TOTAL SLEPT: 10001

	//
	Notice: if usleep performs an error bigger than 1000,
			our current parameter, we'll have delays.
*/
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
		elapsed = ((curr.tv_sec - start.tv_sec) * SECONDS) \
		+ (curr.tv_usec - start.tv_usec);
		rem = pause - elapsed;
		if (rem > 1000)
			usleep(rem / 2);
	}
	return (0);
}