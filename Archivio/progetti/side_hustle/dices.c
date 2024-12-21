/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dices.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:21:37 by negambar          #+#    #+#             */
/*   Updated: 2024/12/18 16:38:58 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gioco.h"
#include <sys/time.h>

void dices(int faces)
{
	struct timeval tv;
    gettimeofday(&tv, NULL);
    srand(tv.tv_usec);
	int random = rand() % faces + 1;
	if (random == 1)
	{
		printf("che culo eh?");
	}
	if (random == 20)
		printf("CHE CULO");
	printf("%d", random);
}

int main()
{
	dices(20);
}