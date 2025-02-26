/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:25:11 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/26 10:36:47 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

static int	get_env_path(char *env[], t_pipex *pipex);
static int	check_one(char **command, t_pipex *pipex);
static int	get_filenames(char *argv[], t_pipex *pipex, t_settings *set);

int	parsing(char *argv[], char *env[], t_pipex *pipex, t_settings *set)
{
	int		err;
	char	**temp_path;
	char	**temp_cmd;

	err = get_filenames(argv, pipex, set);
	if (err != 0)
		return (err);
	err = get_env_path(env, pipex);
	if (err != 0)
		return (err);
	temp_path = pipex->path;
	temp_cmd = pipex->commands;
	err = get_commands(argv, pipex);
	pipex->path = temp_path;
	pipex->commands = temp_cmd;
	if (err != 0)
		return (err);
	err = get_options(pipex);
	if (err != 0)
		return (err);
	return (0);
}

static int	get_filenames(char *argv[], t_pipex *pipex, t_settings *set)
{
	int	len;
	int	err;

	if ((set->switch_1_bonus == ON) && \
	(ft_strncmp(argv[1], "here_doc", 8) == 0))
	{
		err = get_here_doc_file(argv, pipex);
		if (err != 0)
			return (err);
	}
	else
	{
		len = ft_strlen(argv[1]) + 1;
		pipex->infile = (char *)ft_calloc(len, sizeof(char));
		if (!pipex->infile)
			return (ER_MALLOC);
		ft_strlcpy(pipex->infile, argv[1], len);
	}
	if (get_second_filename(argv, pipex) != 0)
		return (ER_MALLOC);
	return (0);
}

int	get_env_path(char *env[], t_pipex *pipex)
{
	int	i;

	i = 0;
	while ((env[i]) && (ft_strncmp(env[i], "PATH=", 5) != 0))
	{
		++i;
	}
	if (!env[i])
		return (ER_NOPATH);
	pipex->path = ft_split(env[i], ':');
	if (!pipex->path)
		return (ER_MALLOC);
	return (0);
}

int	get_commands(char *argv[], t_pipex *pipex)
{
	int		i;
	char	**start_path;

	i = 2 + pipex->here_doc_bool;
	start_path = pipex->path;
	while (*pipex->path)
	{
		if ((*pipex->path)[ft_strlen(*pipex->path) - 1] != '/')
			*pipex->commands = ft_strjoin("/", argv[i]);
		else
			*pipex->commands = ft_strdup(argv[i]);
		pipex->temp = *pipex->commands;
		*pipex->commands = ft_strjoin(*pipex->path, pipex->temp);
		if (!*pipex->commands)
			return (ER_MALLOC);
		if (check_one(pipex->commands, pipex) == 0)
		{
			pipex->path = start_path;
			if (++i == pipex->cmd_num + 2)
				return (0);
			pipex->commands++;
		}
		pipex->path++;
	}
	return (ER_CMD_NOTFOUND);
}

/*
int	check_one(char **command, t_pipex *pipex)
{
	free(pipex->temp);
	pipex->temp = NULL;
	if (access(*command, F_OK) == 0)
		return (0);
	free(*command);
	*command = NULL;
	return (1);
}*/

/*
	We ignore the flags.
*/
int	check_one(char **command, t_pipex *pipex)
{
	int	len;
	int	i;

	free(pipex->temp);
	len = sub_strlen(*command, " ", EXCLUDE);
	pipex->temp = (char *)ft_calloc(len + 2, sizeof(char));
	if (!pipex->temp)
		return (free(*command), 1);
	i = 0;
	while (((*command)[i]) && ((*command)[i] != ' '))
	{
		pipex->temp[i] = (*command)[i];
		++i;
	}
	if (access(pipex->temp, F_OK) == 0)
		return (free(pipex->temp), 0);
	free(*command);
	free(pipex->temp);
	pipex->temp = NULL;
	*command = NULL;
	return (1);
}
