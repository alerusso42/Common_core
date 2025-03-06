#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#define TH 9000

//	SHARED RESOURCE
__uint64_t	ledger = 0;
// lock
pthread_mutex_t	ledger_lock = PTHREAD_MUTEX_INITIALIZER;

void	*update_ledger(void *data)
{
	(void)data;
	pthread_mutex_lock(&ledger_lock);
	ledger += 1;
	pthread_mutex_unlock(&ledger_lock);
	return (NULL);
}

int	main()
{
	pthread_t	waiters[TH];

	pthread_mutex_init(&ledger_lock, NULL);
	for (int i = 0; i < TH; ++i)
	{
		if (pthread_create(waiters + i, NULL, update_ledger, NULL) > 0)
			return (printf("\nError!\n"));
	}
	for (int i = 0; i < TH; ++i)
	{
		pthread_join(waiters[i], NULL);
	}
	printf("\n\tCustomers: %lu\n", ledger);
}
