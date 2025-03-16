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

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    DIR *d = opendir("textures/");
    struct dirent *dir;
    int fd = open("list.txt", O_CREAT | O_RDWR, 0666);

    if (!d || fd < 0) return 1;

    while ((dir = readdir(d)) != NULL) {
        if (strstr(dir->d_name, ".xpm")) {
            fprintf(fp, "Textures/%s\n", dir->d_name);
        }
    }
    closedir(d);
    fclose(fp);
    return 0;
}