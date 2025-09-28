/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:34:28 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/28 10:34:53 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <android/log.h>

#define LOG_TAG "DAFT"

void	logg(char *s)
{
	static int	c;

	if (s)
		__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "Log %d:\t%s\n", c, s);
	else
		__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "Log %d\n", c);
	++c;
}
