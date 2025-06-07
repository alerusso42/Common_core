/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daft.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:27:31 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/04 15:44:55 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DAFT_H
# define DAFT_H

//SECTION - functions prototypes

int 	daft_init(void);
void	daft_quit(void);
void	daft_swap(int enum_id);
void	*daft_get(char *search);

//SECTION - enum
/*
	WARNING: 	don't modify this directly!
				modify SETTINGS.md instead!
*/
typedef enum e_daft_db
{
	HASH_DATA_POKEDEX_POKEDEX,
	HASH_HASH_DATA_POKEDEX_POKEDEX,
	HASH_PROGRAM_LIBFT__VSCODE_SETTINGS,
	POKEDEX_POKEDEX,
	PROGRAM_LIBFT__VSCODE_SETTINGS,
}	t_daft_db;
#endif
