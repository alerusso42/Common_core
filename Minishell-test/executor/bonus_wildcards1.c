/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_wildcards1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:24:37 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/16 14:11:53 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	find_directory(char **dir_path, char **old_str);
static int	dir_size(int *size, char *dir_path);
char		*fill_occurrences(t_wildcard *wdata);

int	convert_wildcard(char *old_str, char **new_str)
{
	t_wildcard	wdata;

	wdata = (t_wildcard){0};
	wdata.old_str = old_str;
	*new_str = NULL;
	if (!ft_strchr(old_str, '*'))
		return (_fd_printf(2, "I see no * in |%s|, sir\n", old_str));
	if (find_directory(&wdata.dir_path, &old_str) == E_MALLOC)
		return (E_MALLOC);
	wdata.search = old_str;
	dir_size(&wdata.dir_size, wdata.dir_path);
	if (wdata.dir_size == 0)
		*new_str = ft_strdup(wdata.old_str);
	else
		*new_str = fill_occurrences(&wdata);
	free(wdata.dir_path);
	if (!*new_str)
		return (E_MALLOC);
	return (0);
}

static int	find_directory(char **dir_path, char **old_str)
{
	int	i;

	i = 0;
	while ((*old_str)[i])
		++i;
	i -= (i != 0);
	while (i != 0 && (*old_str)[i] != '/')
		--i;
	if (i == 0 && (*old_str)[i] != '/')
	{
		*dir_path = ft_strdup("./");
		if (!*dir_path)
			return (E_MALLOC);
		return (0);
	}
	*dir_path = ft_calloc(i + 2, sizeof(char));
	if (!*dir_path)
		return (E_MALLOC);
	ft_strlcpy(*dir_path, *old_str, i + 2);
	*old_str += i + 1;
	return (0);
}

static int	dir_size(int *size, char *dir_path)
{
	DIR				*dir;
	struct dirent	*file;

	*size = 0;
	dir = opendir(dir_path);
	if (!dir)
		return (E_WILDCARD_NOTFOUND);
	file = readdir(dir);
	while (file)
	{
		++(*size);
		file = readdir(dir);
	}
	closedir(dir);
	return (0);
}

/*
cc bonus_wildcards1.c bonus_wildcards2.c general3.c general.c general4.c \
printf_fd.c environment.c debug_resources/libft.a -g -Wall -Wextra -Werror
*/
int	main()
{
	char	*test1 = "*";
	char	*test2 = "bu*pwd*.c";
	char	*test3 = "/bin/*";
	char	*result;

	if (convert_wildcard(test1, &result))
		return (printf("ERROR!!!"));
	printf("\nRESULT FOR %s:\n|%s|\n", test1, result);
	free(result);
	if (convert_wildcard(test2, &result))
		return (printf("ERROR!!!"));
	printf("\nRESULT FOR %s:\n|%s|\n", test2, result);
	free(result);
	if (convert_wildcard(test3, &result))
		return (printf("ERROR!!!"));
	printf("\nRESULT FOR %s:\n|%s|\n", test3, result);
	free(result);
	printf("\n\nYou didn't crash!\n");
}
