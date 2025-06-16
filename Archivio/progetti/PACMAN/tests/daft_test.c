/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:01:17 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/16 19:49:35 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../daft/daft.h"

/*
cc $(sdl2-config --cflags) -Wall -Wextra -Werror -g daft_test.c ../daft/daft.a $(sdl2-config --libs)
*/
int	main()
{
	daft_init();
	daft_quit();
}