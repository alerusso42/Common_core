/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 07:28:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/13 15:47:32 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif

static int	add_one(t_sdl *sdl, char *image_name);

int add_pics(t_sdl *sdl) 
{
    DIR *d;
    struct dirent *dir;
    int fd;
	int	i;

	d = opendir("textures/");
	if (!d)
		return (1);
	fd = open("list.txt", O_CREAT | O_RDWR, 0666);
    if (fd < 0)
		return (closedir(d), 1);
	i = 0;
    while ((dir = readdir(d)) != NULL) 
	{
        if (check_extension_file(dir->d_name, ".xpm") == 0) 
		{
            if (add_one(sdl, dir->d_name) != 0)
				return (closedir(d), close(fd), 1);
        }
		++i;
    }
    closedir(d);
    close(fd);
    return 0;
}

static int	add_one(t_sdl *sdl, char *image_name)
{
	sdl->img_flags = IMG_Init(VALID_FILES);
	if ((sdl->img_flags & VALID_FILES) != VALID_FILES)
		return (8);
	sdl->img[i].surface = IMG_Load("Pac_open_right.xpm");
	if (sdl->img[i].surface == NULL)
		return (9);
	sdl->img[i].texture = SDL_CreateTextureFromSurface\
	(sdl->render, sdl->img[i].surface);
	if (sdl->img[0].texture == NULL)
		return (9);
	return (0);
}