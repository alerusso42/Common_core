/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:59:26 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/12 10:52:18 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if __has_include("so_long.h")
# include "so_long.h"
#else
#include "so_long_bonus.h"
#endif

static void	update_var(t_input *input, t_map *map, t_random *random);
static void	others(t_input *input, t_map *map, t_random *random);

// Siccome importiamo anche input,
// impostiamo una switch inutile per
// zittire le flags.
// variable_2_randomizer aumenta o diminuisce il ricorso a numeri casuali.
// randomizer == 0 non vengono mai usati valori casuali;
// randomizer == 1 vengono usati solo una volta, dopo un ciclo senza modifiche;
// randomizer == 2 come 1, ma i numeri casuali cambiano ad ogni tentativo;
// randomizer == 3 si usano solo valori random.
// in genere, il programma è più efficace ed efficiente con randomizer == 1.
t_bool	variables(t_input *input, t_map *map, t_random *random)
{
	input->en_speed = 2;
	ft_strlcpy(input->valid_signs, "$ECP01\0", 7);
	map->variable_1_player_num = 1;
	map->variable_2_printdata = ALL;
	random->variable_1_setseed = 0;
	random->variable_2_randomizer = 1;
	random->variable_3_enemy_num = 3;
	random->variable_4_collectable_num = 10;
	random->variable_5_internal_wall_num = 0;
	random->variable_6_internal_wall_proportion = A_LOT;
	map->variable_6_window_width = 700;
	map->variable_7_window_heigth = 900;
	ft_strlcpy(map->display_name, "PACMAN\0", 7);
	update_var(input, map, random);
	if (map->switch_1_bonus == NO)
	{
		map->variable_3_enemy_num = 0;
		random->variable_3_enemy_num = 0;
	}
	return (0);
}

t_bool	mlx_settings(t_mlx *mlx)
{
	mlx->variable_1_sprite_size = 25;
	return (0);
}

static void	update_var(t_input *input, t_map *map, t_random *random)
{
	random->wden = random->variable_6_internal_wall_proportion;
	if (random->variable_1_setseed != 0)
		random->seed = random->variable_1_setseed;
	map->wall_number = 2 * map->game_size_w + \
	2 * (map->game_size_h - 2);
	map->free_spaces = \
	map->game_size - (map->wall_number + 3);
	if (random->switch_3_choose_map_entities_num == ON)
	{
		map->void_spaces = \
		map->free_spaces - random->variable_3_enemy_num - \
		random->variable_4_collectable_num - \
		random->variable_5_internal_wall_num;
	}
	else
		map->void_spaces = 0;
	if (random->variable_5_internal_wall_num == 0)
		random->variable_5_internal_wall_num = map->void_spaces / random->wden;
	map->variable_3_enemy_num = random->variable_3_enemy_num;
	map->variable_4_collectable_num = \
	random->variable_4_collectable_num;
	map->variable_5_internal_wall_num = \
	random->variable_5_internal_wall_num;
	map->collectable_num = map->variable_4_collectable_num;
	others(input, map, random);
}

static void	others(t_input *input, t_map *map, t_random *random)
{
	if (input->create_map == CREATE)
	{
		map->collectable_num = random->variable_4_collectable_num;
		map->collectable_left = map->collectable_num;
	}
}
