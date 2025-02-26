/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:25:11 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/26 15:07:51 by alerusso         ###   ########.fr       */
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

/*
	List of stuff to do:

	1)	get the filenames, and consider here_doc if BONUS is ON;
	2)	get the path from the environment matrix env;
	3)	get the commands: it means modifying argv and check if is a valid path.
		If even ONE command does not exist, everything is aborted;
	4)	get the options of every command.
*/
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

/*
	ft_strlen has a + 1 because of \0.
*/
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

/*
	1)	Find the PATH if exists;
	2)	Split it with :;
*/
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

/*
	This is more complicated.

	1)	Starting from index 2 (argv[0] = pipex, argv[1] = infile), or from
		index 3 if there is the here_doc file;
	WHILE LOOP:

		2)	if the current path ha not a '/', add it. else, strdup it;
		3)	If we strjoin a path (ex: /usr/bin/) and add the command (ex: grep)
			we get /usr/bin/grep, the final program path;
		4)	If check one finds that the program in the path exists, it 
			reset the pipex->path matrix, increase the command index, and
			the current command we are actually saving.
			If index, after the increase, happens to be equal to the
			start value of index (2 + here_doc_bool), stop.
*/
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
			if (++i == pipex->cmd_num + 2 + pipex->here_doc_bool)
				return (0);
			pipex->commands++;
		}
		pipex->path++;
	}
	return (ER_CMD_NOTFOUND);
}

/*
	1)	We calculate the strlen of the command until we find a SPACE:
		because we have to consider the options (ex: wc -l);
	2)	We save a temp copy of the command, until we found \0 or SPACE;
	3)	We access the file. If it exists, we return 0, else 1.

	If a malloc fails here, we go on. 
	Get_commands will fail anyway soon, and will abort the execution.
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
