/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 18:47:09 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/01 17:12:29 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	ft_unset(char **args, t_exec *exec)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (env_parsing(args[i]))
			//FAI LE ROBINE
		else
			//MESSAGGIO DI ERRORE
		++i;
	}
	(void)args, (void)exec;
	return (0);
}
