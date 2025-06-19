/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password_validation.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 11:33:27 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/18 18:16:55 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PASSWORD_VALIDATION_H
# define PASSWORD_VALIDATION_H

# include <sys/time.h>
# include <sys/wait.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

enum	e_bool
{
	TRUE,
	FALSE,
};

typedef struct PwStatus
{
	char	*password;
	char	stat;
}	PwStatus;

# define SIZE 7

PwStatus validate_password(const char *new_pw, const char *curr_pw);

#endif