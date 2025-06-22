#include "../h.h"

long	elapsed_time(t_time start)
{
	struct timeval	tv;
	long			diff;

	gettimeofday(&tv, NULL);
	diff = (tv.tv_sec - start.tv_sec) * 1000000
		 + (tv.tv_usec - start.tv_usec);
	return (diff);
}
