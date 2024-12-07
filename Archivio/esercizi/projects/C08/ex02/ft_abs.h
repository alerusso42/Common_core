/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/10/18 16:46:36 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

# if (value > 0)
#  define ABS(value) (value)
# elif (value < 0)
#  define ABS(value) (-value)
# endif

// Problema: come risolvere con le restrizioni imposte da norminette?
// Online lo fanno con i ternari, ma sono proibiti. Che devo fa??
#endif