/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 09:58:28 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/05 12:23:08 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <malloc.h>
#include <semaphore.h>
#include <fcntl.h>
#define PHILO 5
#define SEM_NAME "NAME"
#define TIME_EAT 3
#define TIME_SLEEP 3
#define FORKS PHILO

/*
int	main()
{
	pid_t	pid[PHILO];
	int		i = 0;
	sem_t	*sem;

	sem_unlink(SEM_NAME);
	sem = sem_open(SEM_NAME, O_CREAT, 0666, FORKS);
	if (!sem)
		return (printf("gay\n"));
	while (i != PHILO)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			return (printf("ERROE\n"));
		else if (!pid[i])
		{
			while (1)
			{
				sem_wait(sem);
				sem_wait(sem);
				printf("%d\tsem locked\n", i);
				if (i % 2)
					sleep(TIME_EAT);
				else
					sleep(TIME_SLEEP);
				sem_post(sem);
				sem_post(sem);
				printf("%d\tsem unlocked\n", i);
				usleep(5);
			}
		}
		++i;
	}
	sem_close(sem);
	while (wait(NULL))
		;
	sem_unlink(SEM_NAME);
}
*/


// int main()
// {
// 	pid_t	pid[CHILD];
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	str = malloc(sizeof(char) * 4);
// 	str[0] = 's';
// 	str[1] = 'o';
// 	str[2] = 's';
// 	str[3] = '\0';
// 	while (i != CHILD)
// 	{
// 		pid[i] = fork();
// 		if (pid[i] == -1)
// 			return (printf("ERROE\n"));
// 		else if (!pid[i])
// 		{
// 			while (1)
// 			{
// 				printf("philo %i %s\n", i, str);
// 				sleep(1);
// 				if (i % 2)
// 				{
// 					free(str);
// 					exit(42);
// 				}
// 			}
// 		}
// 		++i;
// 	}
// 	i = 0;
// 	// while (i != CHILD)
// 	// {
//  	// 	// sleep(2);
//  	// 	// kill(pid[i], SIGSTOP);
//  	// 	// write(1, "freeze\n", 7);
//  	// 	sleep(2);
//  	// 	// write(1, "jk\n", 3);
//  	// 	kill(0, SIGKILL);
// 	// 	// kill(0, SIGUSR1);
// 	// 	printf("philo %d HAS BEEN SLAYED, HAHAH\n", i);
// 	// 	++i;
// 	// }
// 	int	status;
// 	while (wait(&status))
// 	{
// 		status %= 255;
// 		printf("status: %d\n", status);
// 		if (status == 42)
// 			break ;
// 	}
// 	kill(0, SIGKILL);
// 	free(str);
// 	printf("MUHAHAHA\n");
// }

// int main(void)
// {
// 	pid_t	pid;

// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		while (1)
// 		{
// 			printf("MAMMA MIA SONO GAY\n");
// 			sleep(1);
// 		}
// 	}
// 	else
// 	{
// 		sleep(5);
// 		kill(pid, SIGSTOP);
// 		write(1, "freeze\n", 7);
// 		sleep(5);
// 		write(1, "jk\n", 3);
// 		kill(-1, SIGKILL);
// 	}
// 	sleep(20);
// 	kill(pid, SIGKILL);
// 	printf("QUANDO VAI ALL'INFERNO DI CHE TI HA MANDATO ALERUSSO\n");
// }
