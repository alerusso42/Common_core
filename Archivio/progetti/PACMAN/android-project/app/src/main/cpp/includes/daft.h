/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:27:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/07/13 14:59:26 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DAFT_H
# define DAFT_H

/*WARNING: 	don't modify this file directly!
			modify SETTINGS.md instead!
*/

//SECTION - functions prototypes

int 	daft_init(void);
void	daft_quit(void);
void	daft_swap(int enum_id);
void	*daft_get(const char *search);

//SECTION - enum

typedef enum e_daft_db
{
	ENEMIES,
	MEDIA_LIST,
}	t_daft_db;

//SECTION - Global variables
#define DAFT_PWD "daft/"

#endif
