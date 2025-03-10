/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:20:15 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/10 15:29:01 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

int	time_delay_test(void)
{
	struct timeval	time_one;
	struct timeval	time_two;
	long long int	diff;
	long long int	pause;
	int				err;

	pause = 1 * MSECONDS;
	err = 0;
	while (pause != 300 * MSECONDS)
	{
		err = gettimeofday(&time_one, NULL);
		err = wait(pause);
		if (err != 0)
			return (err);
		err = gettimeofday(&time_two, NULL);
		diff = ((time_two.tv_sec - time_one.tv_sec) * 1000000);
		diff += (time_two.tv_usec - time_one.tv_usec);
		diff -= pause;
		l_printf("\nDiff for a %d pause:\t%d\n", pause, diff);
		if (diff > 100)
			return (p_color(RED, "\n\n\n\n\nWARNING!!!!!\n\n\n\n"));
		pause += 1 * MSECONDS;
	}
	p_color(GREEN, "\n\nDELAY TEST OK!\n\n");
	return (err);
}

int	p_color(int color, char *s)
{
	return (l_printf("\033[%dm%s\033[0m", color, s));
}