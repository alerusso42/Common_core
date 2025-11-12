/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 20:24:29 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/12 21:32:57 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include "../libft.h"

# define autoclean(T) T __attribute__((cleanup(clean_ ## T)))
# define autoclean_ptr(T) T __attribute__((cleanup(clean_ ## T ## _ptr)))

typedef struct s_str
{
//SECTION - private
	char	*_buffer;
//SECTION - public
}	t_str;

#endif