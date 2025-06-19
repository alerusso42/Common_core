/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:33:30 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/12 09:19:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "critical_window.h"

int		bigger_than_150(const int *arr, int size, int i);
float	average(const int *arr, int size);
int		three_days_bigger_70(const int *arr, int size, int i);

// int	random(int size)
// {
// 	struct timeval	time;

// 	usleep(1000);
// 	gettimeofday(&time, 0);
// 	return (time.tv_usec % size);
// }

// int	main(void)
// {
// 	int	nums[SIZE];
// 	int	i;

// 	i = 0;
// 	while (i != SIZE)
// 	{
// 		nums[i] = random(SIZE * 20);
// 		printf("%d:\t%d\n", i, nums[i]);
// 		++i;
// 	}
// 	printf("\nSegments:\t%d\n", count_critical_windows(nums, SIZE));
// }

int	count_critical_windows(const int *readings, int size)
{
	int		i;
	int		critical;

	if (!readings)
		return (0);
	i = -1;
	critical = 0;
	while (++i + 5 <= size)
	{
		if (!three_days_bigger_70(readings, size, i))
			continue ;
		if (bigger_than_150(readings, size, i))
			continue ;
		if (average(readings + i, 5) < (float)90)
			continue ;
		++critical;
	}
	return (critical);
}

int	three_days_bigger_70(const int *arr, int size, int i)
{
	int	bigger_seventy;
	int	count;

	bigger_seventy = 0;
	count = 0;
	while (i != size && count != 5)
	{
		if (arr[i] >= 70)
			bigger_seventy += 1;
		i++;
		count++;
	}
	return (bigger_seventy > 2);
}

int	bigger_than_150(const int *arr, int size, int i)
{
	int	bigger_seventy;
	int	count;

	bigger_seventy = 0;
	count = 0;
	while (i != size && count != 5)
	{
		if (arr[i] > 150)
			break ;
		i++;
		count++;
	}
	return (count != 5);
}

float	average(const int *arr, int size)
{
	float	av;
	int		i;

	av = 0;
	if (size <= 0 || !arr)
		return (av);
	i = 0;
	while (i != (float)size)
	{
		av += arr[i];
		++i;
	}
	return (av / (float)size);
}
