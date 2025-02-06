/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:15:32 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/06 07:50:13 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# define ON 1
# define YES 1
# define OFF 0
# define NO 0
# define NO_RANDOM 2
# define CREATE 1
# define READ 0
# define GET 2
# define UPDATE 1

typedef struct s_input		t_input;
typedef struct s_map		t_map;
typedef struct s_position	t_position;
typedef struct s_random		t_random;
typedef struct s_mlx		t_mlx;
typedef struct s_sprite		t_sprite;
typedef struct s_all		t_all;
typedef unsigned char		t_onebyte;
typedef unsigned int		t_bool;

/*
 Il codice ha come armi 3 strutture di dati: t_input, t_map,
 t_random.
 Per la mole delle strutture allocate, ho preferito l'uso di unsigned
 char al posto di int, perchè un int consuma 4 byte e gli unsigned
 char 1 byte.
 Ho usato unsigned char e non signed perchè i valori negativi avrebbero
 dato più fastidio che altro.
 Per chiarire questo intento, nel codice ho sostituito unsigned char
 con t_onebyte: ma sempre di unsigned char si parla.
 Di seguito spiego le 3 strutture usate.
 NOTA: le switch e le variabili sono impostazioni di sistema per
	   alterare il comportamento del sistema.
	   vedi i file switch.h e variables.h.

 t_input contiene i dati inseriti dall'utente in formato t_onebyte.
 Si accede ai valori di t_input con nomestruttura->colonna/riga.x/y[index].
 Ad esempio, input->colup.x[index].
 Ognuno dei 4 array (colup.x, coldown.x, rowleft.y, rowright.x) termina con 0,
 carattere terminatore.
 Contiene inoltre la grandezza della griglia, parametro fondamentale.

 t_position contiene il valore massimo possibile e le caselle della griglia.
 Ogni casella ha al suo interno 4 tipi di dati: 
 is_sure:1 --> booleano che mostra se il valore della casella è certo;
 value ------> il valore numerico della casella;
 u_score ----> Parametro che segna quanti sono i numeri legali
			   che possono essere inseriti nella casella.
			   Si pronuncia "unsure_score";
 black_list -> un array di t_onebyte che contiene la lista di tutti i valori
				 illegali. Inizialmente, ha 3 valori iniziali: 101, 102, 103.
				 	Da 101 a 102 c'è la lista di valori sempre illegali, che
					non vengono resettati tra una iterazione e l'altra.
					Da 102 a 103 c'è la lista di valori che vengono resettati
					tra una iterazione e l'altra.
 				 	A 103 finisce l'array.
 Si accede ai valori di map facendo: nomestruct->position[x][y].value.
 Ad esempio: map->position[x][y].black_list[index].

 t_map contiene t_position.
 Inoltre, contiene:
 g_u_score ---> Parametro che segna, tra tutti gli u_score, qual è
				il più piccolo. Vengono escluse le caselle già
				riempite.
				Questo parametro è fondamentale per orchestrare
				l'ordine con il quale il programma decide di inserire
				i valori nelle caselle, e, in caso, la casella dove
				è meno rischioso mettere un numero casuale;
game_size --->	Una copia di game_size, la grandezza della scacchiera;
is_solved:1 ->	Booleano che indica quando tutti le caselle sono state
				riempite;
is_correct:1 >	Booleano che indica quando una soluzione trovata è
				giusta, e può essere mandata in stampa in 
				print_stuff.h.				

 t_random	contiene una collezione di 256 numeri casuali, che oscillano tra
 1 e la grandezza della griglia; questo array finisce sempre col carattere
 terminatore 103.
 Vengono generati in "random_numers.h", a partire da un seed, ottenuto con
 la somma dell'atoi di input->colup.x[0],   input->colup.x[0]
 						 input->rowleft.y[0], input->rowright.y[0]
 Il seed è contenuto in t_random.
 Si accede ai valori con nomestruct->seed/values[index].
 Ad esempio: random->values[index]
 */

typedef struct s_bfs
{
	int			en_x;
	int			en_y;
	int			p_x;
	int			p_y;
	int			x;
	int			y;
	int			map_x;
	int			map_y;
	t_position	**position;
	int			distance;
}				t_bfs;

struct s_col
{
	t_onebyte	*x;
};
struct s_row
{
	t_onebyte	*y;
};
struct s_input
{
	t_bool				switch_1_bonus:1;
	t_bool				variable_0_shutupcompiler:1;
	t_bool				create_map:1;
	char				valid_signs[7];
	int					game_size;
	int					game_size_w;
	int					game_size_h;
	char				*filename;
	struct s_col		col;
	struct s_row		row;
};
struct s_position
{
	t_onebyte	value;
	int			distance;
	t_onebyte	*pointer;
};
struct s_map
{
	t_bool				switch_1_bonus:1;
	t_bool				switch_2_printonterminal:1;
	int					variable_1_player_num;
	t_onebyte			variable_3_enemy_num;
	int					variable_4_collectable_num;
	int					variable_5_internal_wall_num;
	int					variable_6_window_width;
	int					variable_7_window_heigth;
	char				display_name[7];
	int					game_size;
	int					game_size_w;
	int					game_size_h;
	int					free_spaces;
	int					void_spaces;
	int					wall_number;
	int					collectable_num;
	unsigned char		is_solved:1;
	int					e_x;
	int					e_y;
	int					p_x;
	int					p_y;
	int					p_dir;
	int					p_frame;
	struct s_position	**position;
	struct s_position	**old_pos;
};
struct s_random
{
	t_bool		switch_1_showseed:1;
	t_bool		switch_2_showrandomvalues:1;
	t_bool		switch_3_choose_map_entities_num:1;
	t_onebyte	variable_1_setseed;
	t_onebyte	variable_2_randomizer:2;
	t_onebyte	variable_3_enemy_num;
	int			variable_4_collectable_num;
	int			variable_5_internal_wall_num;
	int			variable_6_internal_wall_proportion;
	int			wden;
	t_onebyte	seed;
	int			*values;
};
struct s_sprite
{
	void	*blue;
	void	*cian_down;
	void	*cian_front;
	void	*cian_left;
	void	*cian_right;
	void	*cian_up;
	void	*close_exit;
	void	*dead;
	void	*dot;
	void	*exit;
	void	*floor;
	void	*orange_down;
	void	*orange_front;
	void	*orange_left;
	void	*orange_right;
	void	*orange_up;
	void	*pac_close_down;
	void	*pac_close_left;
	void	*pac_close_right;
	void	*pac_close_up;
	void	*pac_dead_1;
	void	*pac_dead_2;
	void	*pac_dead_3;
	void	*pac_dead_4;
	void	*pac_half_down;
	void	*pac_half_left;
	void	*pac_half_right;
	void	*pac_half_up;
	void	*pac_open_down;
	void	*pac_open_left;
	void	*pac_open_right;
	void	*pac_open_up;
	void	*purple_down;
	void	*purple_front;
	void	*purple_left;
	void	*purple_right;
	void	*purple_up;
	void	*red_down;
	void	*red_front;
	void	*red_left;
	void	*red_right;
	void	*red_up;
	void	*special_dot;
	void	*wall_down;
	void	*wall_left;
	void	*wall_right;
	void	*wall_total;
	void	*wall_up;
};
struct s_mlx
{
	void		*con;
	void		*window;
	t_sprite	*sprite;
	int			variable_1_sprite_size;
};
struct s_all
{
	t_input		*input;
	t_map		*map;
	t_random	*random;
	t_mlx		*mlx;
};

#endif