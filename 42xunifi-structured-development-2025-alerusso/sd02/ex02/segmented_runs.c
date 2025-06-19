/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segmented_runs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:33:30 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/18 18:04:22 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "segmented_runs.h"

static int	check_segment(const int *arr, int size, int *i);

/*
int	random(int size)
{
	struct timeval	time;

	usleep(1000);
	gettimeofday(&time, 0);
	return (time.tv_usec % size);
}

int	main(void)
{
	int				nums[SIZE];
	int				i;

	i = 0;
	while (i != SIZE)
	{
		if (i % (SIZE / 25) == 0)
			nums[i] = -1;
		else
			nums[i] = random(SIZE);
		printf("%d:\t%d\n", i, nums[i]);
		++i;
	}
	printf("\nSegments:\t%d\n", count_segments(nums, SIZE));
}*/

int	count_segments(const int *arr, int size)
{
	int		i;
	int		count;

	if (!arr)
		return (0);
	i = 0;
	count = 0;
	while (i != size)
	{
		while (arr[i] == -1)
			++i;
		count += check_segment(arr, size, &i);
	}
	return (count);
}

static int	check_segment(const int *arr, int size, int *i)
{
	int	previous;
	int	current;
	int	count;

	count = 0;
	previous = INT_MIN;
	current = arr[*i];
	while (*i != size && arr[*i] != -1 && current > previous)
	{
		++count;
		previous = current;
		(*i)++;
		current = arr[*i];
	}
	while (*i != size && arr[*i] != -1)
		(*i)++;
	return (count >= 3);
}
