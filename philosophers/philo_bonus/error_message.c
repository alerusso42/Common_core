/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:41:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/21 15:35:05 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("z_header.h")
# include "z_header.h"
#else
# include "z_header_bonus.h"
#endif

static int	other_messages(int error);
static int	other_messages2(int error);
static int	other_messages3(int error);

int	error(int error)
{
	void	*ptr;

	ptr = storage(NULL, 1);
	reset_memory(ptr);
	return (other_messages(error));
}

static int	other_messages(int error)
{
	return (other_messages2(error));
}

static int	other_messages2(int error)
{
	return (other_messages3(error));
}

static int	other_messages3(int error)
{
	if (error == ER_PARSING)
	{
		return (fd_printf(2, "Error\nCommand not found"));
	}
	if (error == ER_BAD_ARGC)
	{
		return (fd_printf(2, "Insert entry description of program"));
	}
	else
		return (fd_printf(2, "Generic error\n"));
}
