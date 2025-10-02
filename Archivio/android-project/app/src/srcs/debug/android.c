/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   android.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 00:03:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/02 01:23:37 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pacman.h"

#include <android/log.h>

#define LOG_TAG "DAFT"

void	err(const char *s)
{
	static int	c;

	if (s)
		__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "Log %d:\t%s\n", c, s);
	else
		__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "Log %d\n", c);
	++c;
}