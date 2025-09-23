/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:27:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/09/23 18:58:35 by alerusso         ###   ########.fr       */
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
void	daft_free(void *mem);
void	*daft_get(const char *search);
void	*daft_edit(const char *search, int size, int mtr_number);
void	*daft_append(char *key, int size, int mtr_number);

//SECTION - enum

typedef enum e_daft_db
{
	ENEMIES,
	MEDIA_LIST,
	POKEDEX,
}	t_daft_db;

//SECTION - Global variables
#define DAFT_PWD "/home/alerusso/Common_core/Archivio/progetti/PACMAN/daft"

#endif
