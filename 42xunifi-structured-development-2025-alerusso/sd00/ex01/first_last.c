/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:33:30 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/11 10:06:50 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_last.h"

// int	random(int size)
// {
// 	struct timeval	time;

// 	gettimeofday(&time, 0);
// 	return (time.tv_usec % size);
// }

// int	main(void)
// {
// 	int				nums[SIZE];
// 	int				i;
// 	int				frst_lst[2];
// 	int				target;

// 	i = 0;
// 	target = random(SIZE);
// 	while (i != SIZE)
// 	{
// 		nums[i] = random(SIZE);
// 		printf("%d:\t%d\n", i, nums[i]);
// 		++i;
// 	}
// 	first_last(nums, SIZE, target, &frst_lst[0], &frst_lst[1]);
// 	printf("\nTarget:\t%d\n", target);
// 	printf("\nFirst:\t%d\nLast:\t%d\n", frst_lst[0], frst_lst[1]);
// }

void	first_last(int arr[], int size, int target, int *first, int *last)
{
	int		i;

	if (first)
		*first = -1;
	if (last)
		*last = -1;
	if (!first || !last || size <= 0)
		return ;
	i = 0;
	while (i != size)
	{
		if (arr[i] == target)
		{
			if (*first == -1)
				*first = i;
			*last = i;
		}
		++i;
	}
}
