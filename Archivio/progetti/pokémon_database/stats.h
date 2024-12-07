/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:34:39 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/23 12:30:15 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATS_H
# define STATS_H
# include "ft_printf.h"
# include "general_ft.h"
# include "init_mon.h"
# include <malloc.h>

int				search_stat(char *input, struct s_pkmn *pkmn, int mode);
char			*search_name(char *input, struct s_pkmn *pkmn, char name[20]);
struct s_pkmn	*pkmn_list_0_3(char *str, struct s_pkmn *pkmn);

int	search_stat(char *input, struct s_pkmn *pkmn, int mode)
{
	fake_main(&pkmn, input);
	ft_printf("\n\n");
	ft_printf("%d\b ", mode);
	//pkmn_list_0_3(input, pkmn);
	/*if ((mode) == 0)
	{
		if (pkmn->nbr == 0)
			return (1);
		return (0);
	}
	else if (mode == 1)
		return (pkmn->hp);
	else if (mode == 2)
		return (pkmn->atk);
	else if (mode == 3)
		return (pkmn->def);
	else if (mode == 4)
		return (pkmn->spatk);
	else if (mode == 5)
		return (pkmn->spdef);
	else
		return (pkmn->vel);*/
	return (0);
}

char	*search_name(char *input, struct s_pkmn *pkmn, char name[20])
{
	pkmn_list_0_3(input, pkmn);
	ft_memset(name, 20);
	ft_strcpy(name, pkmn->name);
	return (name);
}

struct s_pkmn	*pkmn_list_0_3(char *str, struct s_pkmn *pkmn)
{
	int				size_name;

	if (ft_strcmp(str, "bulbasaur") < 3)
	{
		pkmn->nbr = 1;
		size_name = ft_strlen("Bulbasaur") + 1;
		pkmn->name = (char *)malloc(size_name);
		ft_memset(pkmn->name, size_name);
		ft_strcpy(pkmn->name, "Bulbasaur");
		pkmn->hp = 45;
		pkmn->atk = 49;
		pkmn->def = 49;
		pkmn->spatk = 65;
		pkmn->spdef = 65;
		pkmn->vel = 45;
		return (pkmn);
	}
	else if (ft_strcmp(str, "ivysaur") < 3)
	{
		pkmn->nbr = 2;
		size_name = ft_strlen("Ivysaur") + 1;
		pkmn->name = (char *)malloc(size_name);
		ft_memset(pkmn->name, size_name);
		ft_strcpy(pkmn->name, "Ivysaur");
		pkmn->hp = 60;
		pkmn->atk = 62;
		pkmn->def = 63;
		pkmn->spatk = 80;
		pkmn->spdef = 80;
		pkmn->vel = 60;
		return (pkmn);
	}
	else if (ft_strcmp(str, "venusaur") < 3)
	{
		pkmn->nbr = 3;
		size_name = ft_strlen("Venusaur") + 1;
		pkmn->name = (char *)malloc(size_name);
		ft_memset(pkmn->name, size_name);
		ft_strcpy(pkmn->name, "Venusaur");
		pkmn->hp = 80;
		pkmn->atk = 82;
		pkmn->def = 83;
		pkmn->spatk = 100;
		pkmn->spdef = 100;
		pkmn->vel = 80;
		return (pkmn);
	}
	pkmn->nbr = 0;
	return (pkmn);
}

#endif