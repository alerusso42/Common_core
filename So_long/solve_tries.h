/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tries.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:14:52 by alerusso          #+#    #+#             */
/*   Updated: 2024/10/30 10:14:52 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_TRIES_H
# define SOLVE_TRIES_H
# include <stdlib.h>
# include "types.h"
# include "solve_game.h"
# include "solve_tries2.h"

int		cycle(t_solution **solution, t_random **random, int *c);
int		cycle2(t_solution **solution, t_random **random, int *end_cycle);
t_bool	fill_point(t_solution **solution, t_random **random, int x, int y);
int		inspect_blacklist(t_solution *solution, int x, int y);
int		take_random(t_solution *solution, t_random **random, int x, int y);
void	insertnum_temp(t_solution **solution, int x, int y, t_onebyte num);

/*STEP:
	1) 	Calcolo delle caselle da riempire (linea ).
	2)	"Finchè tutte le linee non sono riempite,
		continua a riempirle". (linea ).
	3)	"Fai un ciclo (da in basso a sinistra
		a in alto a destra). Se durante
		l'esecuzione noti che esiste una casella
		in tutta la scacchiera con zero valori
		legali, termina il tentativo."
	4)	"Se (*random)->variable_2_randomizer,
		cioè la variabile che aumenta o decrementa
		il ricorso a numeri casuali, è impostata
		a zero, impedendo quindi in toto la
		generazione di numeri casuali,
		appena vedi che non ci sono valori
		sicuri chiudi il tentativo e smetti
		di provare a risolvere."
	5)	Al termine, informa solve_game2 che
		tutto è andato a buon fine e la
		scacchiera è completamente piena.
*/
int	cycle(t_solution **solution, t_random **random, int *c)
{
	int	end_cycle;
	int	error;

	end_cycle = 0;
	error = 0;
	place_to_fill(*solution, &end_cycle);
	while ((end_cycle != 0) && (++(*c) >= 0))
	{
		error = cycle2(solution, random, &end_cycle);
		if (error == NO)
			return (NO);
		if (error == NO_RANDOM)
			return (NO_RANDOM);
		if (((*solution)->g_u_score >= 2)
			&& ((*random)->variable_2_randomizer == 0))
			return (NO_RANDOM);
	}
	return (YES);
}

/*	STEP:
	1)	"Per ogni casella (sali prima le x fino in fondo,
		poi aumenta gradualmente le y), se non c'è
		stato ancora messo nulla (linea ), e
		la quantità di valori legali nella casella è
		pari o minore alla casella vuota presente
		nella scacchiera col minimo numero di valori
		legali (linea ), inserisci un valore (linea )."
		Questo step è fondamentale: il programma
		fa il confronto con i valori legali per capire
		quali sono le caselle in tutta la scacchiera
		le cui probabilità di indovinare il valore
		sono più alte(più valori legali ci sono,
		più è difficile indovinare).
		Quindi se nota che una casella ha il
		100% di probabilità di avere un dato valore,
		darà precedenza a quella; se non esistono,
		darà precedenza a quelle con 2 valori legali
		(50% di probabilità), poi a quelle con 3
		(33%) e così via.
		Nota a margine: il problema dell'aumento di
		game_size è che la probabilità di vittoria
		diminuisce esponenzialmente, perchè si
		parla di prodotto di percentuali.
	2)	Se hai riempito una casella, diminuisci
		il parametro che registra il numero di
		caselle rimanenti (linea ).
*/
int	cycle2(t_solution **solution, t_random **random, int *end_cycle)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y != (*solution)->game_size)
	{
		while (++x != (*solution)->game_size)
		{
			if (((*solution)->position[x][y].u_score <= (*solution)->g_u_score)
				&& ((*solution)->position[x][y].value == 0))
			{
				if (fill_point(solution, random, x, y) != 0)
				{
					if ((*random)->variable_2_randomizer == 0)
						return (NO_RANDOM);
					else
						return (NO);
				}
				(*end_cycle) -= 1;
			}
		}
		x = -1;
	}
	return (YES);
}

/*	STEP:
	1)	"Se la probabilità che la casella sia
		giusta sono pari a zero, torna
		errore e chiudi il tentativo"
		(linea );
	2) "Se la probabilità è 100%, sfoglia la
		black_list e cerca il valore valido"
		(linea );
	3)	"In caso contrario, torna un numero
		casuale nell'intervallo dei valori
		legali".
		(linea ).
	4)	"Setaccia tutta la scacchiera, e trova
		la casella con il minor numero di
		valori legali".
		(linea ).
*/
t_bool	fill_point(t_solution **solution, t_random **random, int x, int y)
{
	t_onebyte	value;

	value = 0;
	if ((*solution)->position[x][y].u_score == 0)
		return (1);
	if (((*solution)->position[x][y].u_score == 1)
	&& ((*random)->variable_2_randomizer != 3))
	{
		value = inspect_blacklist(*solution, x, y);
		insertnum_temp(solution, x, y, value);
	}
	else
	{
		if ((*random)->variable_2_randomizer != 0)
		{
			value = take_random(*solution, random, x, y);
			if (value == 105)
				return (2);
			insertnum_temp(solution, x, y, value);
		}
	}
	update_uncertainscore(solution);
	return (0);
}

/*	Se sia la black_list_sure che la black_list_temp
	non hanno valori registrati, torna il primo
	valore consentito.
*/
int	inspect_blacklist(t_solution *solution, int x, int y)
{
	t_onebyte	index;
	t_onebyte	gs;
	t_onebyte	value;

	index = 0;
	gs = solution->game_size;
	value = 0;
	while (++index != gs + 1)
	{
		if ((solution->position[x][y].black_list[index + (gs + 1)] == 0)
			&& (solution->position[x][y].black_list[index] == 0))
		{
			value = index;
		}
	}
	return (value);
}

/* 	Il controllo su random_num == 103 serve perchè
	la lista di valori casuali finisce col carattere
	terminatore 103.
*/
int	take_random(t_solution *solution, t_random **random, int x, int y)
{
	t_onebyte	gs;
	t_onebyte	random_num;

	gs = solution->game_size + 1;
	random_num = 0;
	while ((random_num == solution->position[x][y].black_list[random_num + gs])
		|| (random_num == solution->position[x][y].black_list[random_num])
		|| (random_num == 0)
		|| (random_num == 103))
	{
		random_num = (*random)->values[(*random)->seed];
		++(*random)->seed;
	}
	return (random_num);
}

#endif
