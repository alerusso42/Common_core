/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:06:05 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/21 15:26:20 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

int	main(int argc, char *argv[], char **env)
{
	int			err_type;
	t_settings	settings;

	switches(&settings);
	variables(&settings);
	err_type = parsing(argc, argv, &settings);
	if (err_type != 0)
		return (error(err_type));
	(void)env;
	reset_memory();
	return (0);
}
