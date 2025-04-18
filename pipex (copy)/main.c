/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:06:05 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/25 10:35:19 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

int	main(int argc, char *argv[], char **env)
{
	t_pipex		*pipex;
	t_settings	settings;
	int			err;

	switches(&settings);
	variables(&settings);
	if ((settings.switch_1_bonus == OFF) && (argc != 5))
		return (error(ER_BAD_ARGC));
	if ((settings.switch_1_bonus == ON) && ((argc < 5) || (argc > 1000)))
		return (error(ER_BAD_ARGC));	
	alloc_main_struct(&pipex);
	err = alloc_cmd(pipex, argc);
	if (err != 0)
		return (error(err));
	err = parsing(argv, env, pipex, &settings);
	if (err != 0)
		return (error(err));
	err = dup_fds(pipex, &settings);
	if (err != 0)
		return (error(err));
	err = execute_pipe(pipex, &settings);
	if (err != 0)
		return (error(err));
	reset_memory();
	return (0);
}
