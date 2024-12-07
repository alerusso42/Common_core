/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free_pkmn_memory.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:27:35 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/22 10:15:49 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_FREE_PKMN_MEMORY_H
# define MALLOC_FREE_PKMN_MEMORY_H
# include <unistd.h>
# include "structs_info.h"

void	free_all_init(struct s_pkmn **pkmn);
int		free_matrix_strings(char ***strings);

void	free_all_init(struct s_pkmn **pkmn)
{
	if (((*pkmn)->name) != NULL)
		free((*pkmn)->name);
	free_matrix_strings(&(*pkmn)->types_print);
	free_matrix_strings(&(*pkmn)->abilities_print);
	free_matrix_strings(&(*pkmn)->hid_abilities_print);
	free_matrix_strings(&(*pkmn)->move_lup);
	if (((*pkmn)->move_level) != NULL)
		free((*pkmn)->move_level);
	free_matrix_strings(&(*pkmn)->move_tutor);
	free_matrix_strings(&(*pkmn)->move_egg);
	if (((*pkmn)->evs_given_val) != NULL)
		free((*pkmn)->evs_given_val);
	free_matrix_strings(&(*pkmn)->evs_given_type);
	free_matrix_strings(&(*pkmn)->egg_groups);
	if (((*pkmn)->gender_ratio) != NULL)
		free((*pkmn)->gender_ratio);
	if (((*pkmn)->growth_rate) != NULL)
		free((*pkmn)->growth_rate);
	free_matrix_strings(&(*pkmn)->evolutions);
	if (((*pkmn)->evo_level) != NULL)
		free((*pkmn)->evo_level);
	if (((*pkmn)->color) != NULL)
		free((*pkmn)->color);
	if (((*pkmn)->shape) != NULL)
		free((*pkmn)->shape);
	if (((*pkmn)->pokedex_entry) != NULL)
		free((*pkmn)->pokedex_entry);
}

int	free_matrix_strings(char ***strings)
{
	int	position;

	position = 0;
	if ((*strings) == NULL)
		return (1);
	while ((*strings)[position] != NULL)
	{
		free((*strings)[position]);
		++position;
	}
	free(*strings);
	return (0);
}

#endif