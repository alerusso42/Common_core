/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   average.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:33:30 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/10 12:10:33 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "average.h"

// int	main(void)
// {
// 	struct timeval	time;
// 	int				nums[SIZE];
// 	int				i;

// 	i = 0;
// 	while (i != SIZE)
// 	{
// 		gettimeofday(&time, 0);
// 		nums[i] = time.tv_usec % SIZE;
// 		printf("%d:\t%d\n", i, nums[i]);
// 		++i;
// 	}
// 	printf("\nAV:\t%f\n", average(nums, SIZE));
// }

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
		if (arr[i] > 0 && arr[i] <= 100)
			av += arr[i];
		++i;
	}
	return (av / (float)size);
}
