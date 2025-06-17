/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:01:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/17 12:50:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../daft/daft.h"
#include <stdio.h>
#include "lib.h"

/*
cc $(sdl2-config --cflags) -Wall -Wextra -Werror -g daft_test.c ../daft/daft.a $(sdl2-config --libs)
*/
int	main()
{
	int	times;
	daft_init();
	times = 10;
	while (times--)
	{
		char	*line = daft_get("BULBASAUR");
		if (line)
			printf("%s\n", line);
		SDL_free(line);
	}
	daft_quit();
}
