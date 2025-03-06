/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:06:05 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/06 09:13:08 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

/*
	1)	Get program settings;
	2)	Alloc memory (alloc_main_struct + alloc_cmd);
	3)	Parsing;
	4)	Duplicate the fds of infile and outfile;
	5)	Execute the commands (execute_pipe);
	6)	Free memory and close exceed fds.

	Fun stuff: https://www.youtube.com/watch?v=71NAThAf5yw

	//FIXME - 
		1)	se do absolute path (es: "/bin/cat") deve andare bene uguale;
		2)	non devo creare l'infile se non esiste;
		3)	per argomenti vuoti ridurre argc;
		4)	aggiungere X_OK ad access (cartelle);
		5)	here doc deve accettare 5 ARGC, non 4.
*/
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
