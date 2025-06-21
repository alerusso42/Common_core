/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frontend.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 23:47:54 by alerusso          #+#    #+#             */
/*   Updated: 2025/06/21 02:10:43 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	explain_usage(void);
static void	loop(t_data *data, char	user_input[MAX_READ + 1]);

void	frontend(t_data *data)
{
	char	user_input[MAX_READ + 1];

	user_input[0] = 0;
	l_printf("Skip explaination ?[y][n]\n");
	if (read(STDIN_FILENO, user_input, 1) != 1)
		error(data, ER_STDIN);
	if (user_input[0] == 'n')
		explain_usage();
	loop(data, user_input);
}

static void	explain_usage(void)
{
	l_printf(COL_MAGENTA"\"exit\""COL_R);
	l_printf(COL_YELLOW"\t\t\t\tExit program;\n"COL_R);
	l_printf(COL_MAGENTA"\"cmd\""COL_R);
	l_printf(COL_YELLOW"\t\t\t\tShow commands;\n"COL_R);
	l_printf(COL_MAGENTA"\"[SEARCH_ENTRIES]\""COL_R);
	l_printf(COL_YELLOW"\t\tSearch for entries defined in struct.h;\n"COL_R);
	l_printf(COL_MAGENTA"\"return\""COL_R);
	l_printf(COL_YELLOW"\t\t\tReturns to main menu;\n"COL_R);
	l_printf(COL_MAGENTA"\"ID/AUTHOR/BOOK name/subname\""COL_R);
	l_printf(COL_YELLOW"\t{ONLY IN SEARCH MODE}: print entry;\n"COL_R);
}

static void	loop(t_data *data, char	user_input[MAX_READ + 1])
{
	int		i;
	bool	run;
	bool	main_menu;
	char	*names[TOTAL_ENTRIES] = {NAMES};

	main_menu = true;
	i = -1;
	run = true;
	while (run)
	{
		print_entries(names, i);
		if (read(STDIN_FILENO, user_input, MAX_READ) < 0)
			error(data, ER_STDIN);
		user_input[sub_strlen(user_input, "\n", EXCLUDE)] = 0;
		if (main_menu == true)
			i = cmp_to_matrix(user_input, names);
		if (main_menu == true && i != -1)
			main_menu = false;
		else if (!sub_strcmp(user_input, "exit", ""))
			run = false;
		else if (!sub_strcmp(user_input, "return", ""))
		{
			i = -1;
			main_menu = true;
		}
		else if (main_menu == false)
			search(data, user_input, i);
	}
}
