/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:06:05 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/11 18:30:35 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "switches.h"
#include "variables.h"
#include "error_message.h"
#include "reset_memory.h"
#include "alloc_t_input.h"
#include "alloc_t_solution.h"
#include "alloc_t_random.h"
#include "is_possibletowin.h"
#include "is_possibletowin2.h"
#include "solve_game.h"
#include "solve_logic.h"
#include "solve_logic2.h"
#include "solve_tries.h"
#include "solve_tries2.h"
#include "print_stuff.h"
#include "change_mod.h"
#include "automatic_input.h"
#include "automatic_input2.h"
#include "ft_printf.h"
#include <malloc.h>
#include <stdarg.h>

int	ft_settings(t_input **input, t_solution **solution);
int	ft_start(t_input **input, t_solution **solution, t_random *random);

// Per capire il codice, inizia dal file "types.h", poi torna qui.
/* Il programma fa le seguenti operazioni, in ordine:
   1) Recupera la grandezza della scacchiera (game_size), data da
	  il numero degli argomenti escluso il nome del programma diviso
	  4 (linea 52);
   2) Controlla se l'utente ha digitato "play" o "gen".
	  Vedi il file change_mod.h per più info;
   3) Controlla argc: se supera 50 o non è divisibile per 4, dà
	  errore;
   4) Registra l'input dell'utente in una struttura, denominata 
      struct s_input, rinominata con typedef in t_input (linea 56).
	  Se non c'è abbastanza memoria, take_user_input si libera;
   5) Prepara i dati necessari e risolve il gioco (linea 61).
      Vedi ft_settings per più dettagli.
*/
int	main(int argc, char *argv[])
{
	t_input		*input;
	t_solution	*solution;
	int			error_value;
	t_onebyte	game_size;

	if (argc == 1)
		return (error(ERROR_BAD_ARGC));
	game_size = (argc - 1) / 4;
	if ((ft_strcmp(argv[1], "gen") == 0) || (ft_strcmp(argv[1], "play") == 0))
		change_mod(argv, argc);
	if ((ft_strcmp(argv[1], "gen") == 0) || (ft_strcmp(argv[1], "play") == 0))
		return (42);
	if ((((argc - 1) % 4) != 0) || (((argc - 1) / 4) > 9) || (argc == 1))
		return (error(ERROR_BAD_ARGC));
	input = NULL;
	if (alloc_user_input(&input, game_size) != 0)
		return (error(ERROR_FULL_MEMORY));
	if (copy_user_input(argv, &input) == ERROR_INVALID_INPUT)
	{
		full_reset(1, input);
		return (ERROR_INVALID_INPUT);
	}
	solution = NULL;
	error_value = ft_settings(&input, &solution);
	return (error(error_value));
}

/* In ft_settings, il programma:
   1) Alloca spazio sufficiente per i dati della scacchiera,
      immagazzinati in struct s_solution (t_solution).
	  Linea 84.
	  Per più dettagli, apri types.h;
   2) Inizializza i valori in t_solution (linea 83).
   3) Alloca spazio per la struttura necessaria a contenere i valori
      casuali. Se fallisce, all'interno della funzione t_random viene
	  liberato. Linea .
   4) Setta delle impostazioni di sistema modificabili nei file
      switches.h e variables.h;
   5) Genera valori pseudocasuali. Vedi random_numbers.h;
   6) Se è impostata la possibilità in switches.h, la funzione
      is_possibletowin fa ulteriori accertamenti sull'input
	  dell'utente, per verificare se è possibile vincere;
   7) Il programma poi dà avvio alla fase di risoluzione vera e
      propria.
*/
int	ft_settings(t_input **input, t_solution **solution)
{
	t_random	*random;

	if (alloc_sol(input, solution) != 0)
	{
		full_reset(2, input, solution);
		return (3);
	}
	fill_solution(solution, (*input)->game_size);
	if (alloc_randomlist(&random) != 0)
	{
		full_reset(2, input, solution);
		return (3);
	}
	switches(input, solution, &random);
	variables(input, solution, &random);
	fill_random(&random, *input);
	if ((*input)->switch_1_showuserinput == ON)
		print_solution(*input, *solution, 0, 0);
	if (is_possibletowin(*input) != 0)
	{
		full_reset(3, input, solution, &random);
		return (4);
	}
	ft_printf("\n\n");
	return (ft_start(input, solution, random));
}

/* 1) A partire da alcune regole logiche, cerca di trarre
	  quante più informazioni possibili sulle caselle.
	  Vedi file solve_logic.h.
	  Linea .
   2) Il gioco viene risolto. Forse (attualmente fa massimo 6x6).
	  Se hai molto tempo libero, anche il 7x7.
      Linea .
      per info sull'algoritmo di gioco, apri il file solve_game.h;
   3) Se tutto va come previsto, stampa la soluzione (vedi il file
      print_stuff.h), altrimenti restituisce l'errore 5
	  "ERROR_NO_SOLUTIONS". Per info sugli errori, apri il file
	  error_message.h.
*/
int	ft_start(t_input **input, t_solution **solution, t_random *random)
{
	ft_logic_rules(*input, solution);
	solve_game(input, solution, random);
	if ((*solution)->switch_3_showblacklist == ON)
		print_blacklist((*input)->game_size, *solution, -1);
	if (((*solution)->is_correct == YES) && ((*input)->game_size <= 9))
		print_solution(*input, *solution, 0, 0);
	full_reset(3, input, solution, &random);
	if ((*solution)->is_correct == YES)
		return (0);
	else
		return (5);
}
