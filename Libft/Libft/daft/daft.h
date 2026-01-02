/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:27:31 by alerusso          #+#    #+#             */
/*   Updated: 2026/01/02 12:46:50 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DAFT_H
# define DAFT_H

# include "../libft.h"

/*WARNING: 	don't modify this file directly!
			modify SETTINGS.md instead!
*/

//SECTION - functions prototypes

int 	daft_init(const char *path, const char *settings_filename);
void	daft_quit(void);
void	daft_swap(int enum_id);
void	daft_free(void *mem);
void	*daft_get(const char *search);
int		daft_load(void);
void	*daft_edit(const char *search, int size, int mtr_number);
void	*daft_append(const char *key, int size, int mtr_number);

//SECTION - enum

typedef enum e_daft_db
{
	ENEMIES,
	MEDIA_LIST,
	POKEDEX,
}	t_daft_db;

#endif
