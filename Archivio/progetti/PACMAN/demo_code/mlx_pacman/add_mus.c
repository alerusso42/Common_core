/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_mus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:27:21 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/13 11:54:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#if __has_include("so_long.h")
# include "so_long.h"
#else
# include "so_long_bonus.h"
#endif

static int	add_one(t_sdl *sdl, char *music_name, int fd);

int add_pics(t_sdl *sdl)
{
    DIR *d;
    struct dirent *dir;
    int fd;

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0)
		return (10);
	d = opendir(PATH_MUSIC);
	if (!d)
		return (1);
	fd = open(LIST_MUSIC, O_CREAT | O_RDWR, 0666);
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

static int	add_one(t_sdl *sdl, char *music_name, int fd)
{
	int		which_mus;
	char	*music_path;

	which_mus = find_number_line(fd, LIST_MUSIC, 1, music_name);
	if (which_mus < 0)
		return (7);
	music_path = ft_strjoin(PATH_MUSIC, music_name);
	if (!music_path)
		return (1);
	if (check_extension_file(music_name, ".wav"))
	{
		sdl->mix.sound[which_mus] = Mix_LoadWAV(music_path);
		if (sdl->mix.sound[which_mus] == NULL)	
			return (printf("\nError in finding file %s\n", which_mus));
	}
	return (0);
}

int	load_wav(t_sdl *sdl, int num, ...);

int	get_sounds(t_sdl *sdl)
{
	int	error;

	sdl->mix.music = Mix_LoadMUS(S_MUSIC);
	if (sdl->mix.music == NULL)	
		return (11);
	error = load_wav(sdl, 7, S_BEGIN, S_CHOMP, S_DEATH, S_EATFRUIT, \
		S_EATGHOST, S_EXTRAPAC, S_INTERMISSION);
	return (0);
}

int	load_wav(t_sdl *sdl, int num, ...)
{
	va_list	ptr;
	char	*s;
	int		i;

	i = 0;
	va_start(ptr, num);
	while (i < num)
	{
		s = (char *)va_arg(ptr, char *);
		sdl->mix.sound[i] = Mix_LoadWAV(s);
		if (sdl->mix.sound[i] == NULL)	
			return (printf("\nError in finding file %s\n", s));
		++i;
	}
	va_end(ptr);
}