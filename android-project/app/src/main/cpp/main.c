/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:18:45 by alerusso          #+#    #+#             */
/*   Updated: 2025/08/08 21:33:12 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../jni/include/SDL.h"

int	main()
{
	SDL_Window	*win;

	SDL_init(SDL_INIT_VIDEO);
	win = SDL_CreateWindow("FOLLE", 0, 0, 300, 300, SDL_WINDOW_FULLSCREEN);
	SDL_Delay(5000);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}
