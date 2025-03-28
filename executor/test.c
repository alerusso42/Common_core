#include "debug.h"

/*
int	main()
{
	static int	fds[30];
	int			i;

	i = 0;
	while (i != 8)
	{
		fds[i] = open("execute.c", O_RDONLY);
		if (fds[i] == -1)
			return (printf("gay"));
		i++;
	}
	i = 0;
	while (fds[i])
		printf("\nfd %d", fds[i++]);
	return (printf("\nEtero"));
}
*/

/*
int	main()
{
	char	*s = calloc(15, 1);
	strcpy(s, "Test");
	char	**ptr;
	pid_t	pid;

	ptr = &s;
	pid = fork();
	if (pid < 0)
		return (1);
	else if (pid == 0)
	{
		printf("Ptr for string %s:\t%p. Address: %p\n", s, s, &s);
		printf("ptr for string %s:\t%p. Address: %p\n", *ptr, *ptr, ptr);
	}
}*/
