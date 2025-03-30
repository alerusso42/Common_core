/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:10:30 by alerusso          #+#    #+#             */
/*   Updated: 2025/03/26 19:08:28 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/*REVIEW - 
	is_redirector_sign searches for:	
										{>}
										{<}
										{>>}
										{<<}
*/
int	is_red_sign(int sign)
{
	if (sign == RED_OUT)
		return (_YES);
	else if (sign == RED_IN)
		return (_YES);
	else if (sign == RED_O_APPEND)
		return (_YES);
	else if (sign == HERE_DOC)
		return (_YES);
	return (_NO);
}

/*REVIEW - 
	is_redirector_input_sign searches for:	
										{<}
										{<<}
*/
int	is_red_input_sign(int sign)
{
	if (sign == RED_IN)
		return (_YES);
	else if (sign == HERE_DOC)
		return (_YES);
	return (_NO);
}

/*REVIEW - 
	is_redirector_output_sign searches for:	
										{>}
										{>>}
*/
int	is_red_output_sign(int sign)
{
	if (sign == RED_OUT)
		return (_YES);
	else if (sign == RED_O_APPEND)
		return (_YES);
	return (_NO);
}

/*REVIEW - 
	is_execution_separator searches for:	
											{|}
											{&&}
											{||}
*/
int	is_exec_sep(int sign)
{
	if (sign == PIPE)
		return (_YES);
	else if (sign == AND)
		return (_YES);
	else if (sign == OR)
		return (_YES);
	return (_NO);
}

int	is_a_builtin_cmd(char *cmd)
{
	if (!ft_strncmp(cmd, "echo", 4))
		return (B_ECHO);
	else if (!ft_strncmp(cmd, "cd", 2))
		return (B_CD);
	else if (!ft_strncmp(cmd, "pwd", 3))
		return (B_PWD);
	else if (!ft_strncmp(cmd, "export", 6))
		return (B_EXPORT);
	else if (!ft_strncmp(cmd, "unset", 5))
		return (B_UNSET);
	else if (!ft_strncmp(cmd, "env", 3))
		return (B_ENV);
	else if (!ft_strncmp(cmd, "exit", 4))
		return (B_EXIT);
	return (_NO);
}
