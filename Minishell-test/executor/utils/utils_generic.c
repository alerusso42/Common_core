/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_generic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:04:20 by alerusso          #+#    #+#             */
/*   Updated: 2025/04/30 17:02:39 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

int	bigger(int n1, int n2)
{
	return (n1 * (n1 >= n2) + n2 * (n1 < n2));
}

/*REVIEW - set_exit_status

//	Set exit status. Returns it.
*/
int	set_exit_status(t_exec *exec, int exit_status)
{
	*exec->exit_status = exit_status;
	return (exit_status);
}
