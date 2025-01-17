/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:06:05 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/17 10:03:39 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "switches.h"
#include "variables.h"
#include "error_message.h"
#include "change_mod.h"
#include "reset_memory.h"
#include "alloc_t_input.h"
#include "alloc_t_solution.h"
#include "alloc_t_random.h"
#include "print_stuff.h"
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
	if (argc == 1)
		return (error(ERROR_BAD_ARGC));
	if (change_mod(argv, argc) == 1)
		return (1);
	return (0);
}
