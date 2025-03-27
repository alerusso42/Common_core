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

static int	add_one(t_sdl *sdl, char *image_name, int fd);

int add_pics(t_sdl *sdl)
{
    DIR *d;
    struct dirent *dir;
    int fd;

	sdl->img_flags = IMG_Init(VALID_FILES);
	if ((sdl->img_flags & VALID_FILES) != VALID_FILES)
		return (8);
	d = opendir("textures/");
	if (!d)
		return (1);
	fd = open("IMAGE_LIST.txt", O_CREAT | O_RDWR, 0666);
    if (fd < 0)
		return (closedir(d), 1);
    while ((dir = readdir(d)) != NULL) 
	{
        if (check_extension_file(dir->d_name, ".xpm") == 0) 
		{
            if (add_one(sdl, dir->d_name, fd) != 0)
				return (closedir(d), close(fd), 1);
        }
    }
    return (closedir(d), close(fd), 0);
}

static int	add_one(t_sdl *sdl, char *image_name, int fd)
{
	int		which_pic;
	char	*image_path;

	which_pic = find_number_line(fd, "IMAGE_LIST.txt", 1, image_name);
	if (which_pic < 0)
		return (7);
	image_path = ft_strjoin("/textures/", image_name);
	if (!image_path)
		return (1);
	sdl->img[which_pic].surface = IMG_Load(image_path);
	free(image_path);
	if (sdl->img[which_pic].surface == NULL)
		return (9);
	sdl->img[which_pic].texture = SDL_CreateTextureFromSurface\
	(sdl->render, sdl->img[which_pic].surface);
	if (sdl->img[which_pic].texture == NULL)
		return (9);
	return (0);
}
