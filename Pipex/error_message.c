/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:41:43 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/21 15:07:03 by alerusso         ###   ########.fr       */
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
	if (error == ER_BAD_ARGC)
	{
		return (l_printf("Insert entry description of program"));
	}
	else
		return (l_printf("Generic error\n"));
}
