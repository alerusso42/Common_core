/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_wildcards1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:24:37 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/14 20:04:12 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	find_directory(char **dir_path, char **old_str);
static int	get_start_end(char **start_with, char **end_with, char *old_str);
static int	dir_size(char **to_save, char *dir_path);
int			dir_check(char *to_save, char *dir_path, char *start_with, \
	char *end_with);
char		*fill_occurrences(char *to_save, char *dir_path, char *old_str);

int	convert_wildcard(char *old_str, char **new_str)
{
	char	*temp;
	char	*dir_path;
	char	*start_with;
	char	*end_with;
	char	*to_save;

	temp = old_str;
	*new_str = NULL;
	if (!ft_strchr(old_str, '*'))
		return (_fd_printf(2, "I see no * in |%s|, sir\n", old_str));
	if (find_directory(&dir_path, &old_str) == E_MALLOC)
		return (E_MALLOC);
	if (get_start_end(&start_with, &end_with, old_str) == E_MALLOC)
		return (E_MALLOC);
	to_save = NULL;
	if (dir_size(&to_save, dir_path) != 0)
		return (E_MALLOC);
	if (dir_check(to_save, dir_path, start_with, end_with) != 0)
		*new_str = ft_strdup(temp);
	else
		*new_str = fill_occurrences(to_save, dir_path, temp);
	temp = to_save;
	if (!*new_str)
		return (free(start_with), free(end_with), free(temp), E_MALLOC);
	return (free(start_with), free(end_with), free(temp), 0);
}

static int	find_directory(char **dir_path, char **old_str)
{
	int	i;

	i = 0;
	while ((*old_str)[i] && (*old_str)[i] != '/')
		++i;
	if (!(*old_str)[i])
	{
		*dir_path = ft_strdup("./");
		if (!*dir_path)
			return (E_MALLOC);
		return (0);
	}
	*dir_path = ft_calloc(i + 1, sizeof(char));
	if (!*dir_path)
		return (E_MALLOC);
	ft_strlcpy(*dir_path, *old_str, i);
	*old_str += i + 1;
	return (0);
}

static int	get_start_end(char **start_with, char **end_with, \
	char *old_str)
{
	int		half;
	int		old_str_len;

	*start_with = NULL;
	*end_with = NULL;
	old_str_len = ft_strlen(old_str);
	half = _sub_strlen(old_str, "*", EXCL);
	if (half != 0)
		*start_with = (char *)ft_calloc(half + 1, sizeof(char));
	if (half && !*start_with)
		return (E_MALLOC);
	if (old_str_len - half - 1 > 0)
		*end_with = (char *)ft_calloc(old_str_len - half + 1, sizeof(char));
	if (old_str_len - half - 1 > 0 && !*end_with)
		return (free(*start_with), E_MALLOC);
	if (*start_with)
		_sub_strcpy(*start_with, old_str, "*", EXCL);
	if (*end_with)
		_sub_strcpy(*end_with, old_str + half, "*", EXCL);
	return (0);
}

static int	dir_size(char **to_save, char *dir_path)
{
	int				i;
	DIR				*dir;
	struct dirent	*file;

	i = 0;
	dir = opendir(dir_path);
	if (!dir)
		return (E_WILDCARD_NOTFOUND);
	file = readdir(dir);
	while (file)
	{
		++i;
		file = readdir(dir);
	}
	*to_save = ft_calloc(i + 1, sizeof(char));
	if (!*to_save)
		return (closedir(dir), E_MALLOC);
	(*to_save)[i] = _STOP;
	return (closedir(dir), 0);
}

/*
cc -Wall -Wextra -Werror -g \
bonus_wildcards1.c bonus_wildcards2.c \
general.c general3.c general4.c printf_fd.c \
debug_resources/libft.a
*/
int	main()
{
	char	*test1 = "*";
	char	*test2 = "bu*";
	char	*test3 = "*.c";
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
