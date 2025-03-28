/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bash_messages.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:51:40 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/26 10:06:37 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	bash_message(int message, char *file)
{
	if (message == E_OPEN)
	{
		_fd_printf(2, "bash: %s: No such file or directory\n", file);
		return (1);
	}
	return (0);
}
