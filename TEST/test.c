#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	*make_coffee(void *name)
{
	printf("\n%s is making coffee...\n", (char *)name);
	sleep(3);
	printf("Coffee ready!\n");
	return (NULL);
}

int	main()
{
	pthread_t	barista[500];

	for (int i = 0; i < 500; i++)
	{
		if (pthread_create(barista + i, NULL, make_coffee, (void *)"ROCKY") > 0)
			return (printf("FAIL!\n"));
	}
	for (int i = 0; i < 500; i++)
	{
		pthread_join(*(barista + i), NULL);
	}
	
}