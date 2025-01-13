/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_possibletowin2.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 00:31:41 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/10 15:42:25 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_POSSIBLETOWIN2_H
# define IS_POSSIBLETOWIN2_H
# include "types.h"

int		check_angles(t_input *input, int lim);
int		check_one(t_input *input);
int		checkrow_one(t_input *input);
void	angles_error(t_input *input, int *error_found, int lim, int condition);
void	ones_error(int record_one, int condition);

/*Controllo sugli angoli.*/
int	check_angles(t_input *input, int lim)
{
	int	error_found;

	lim = input->game_size - 1;
	error_found = 0;
	if (input->coldown.x[0] == 1)
	{
		if (input->coldown.x[0] != input->rowleft.y[0])
			angles_error(input, &error_found, lim, 1);
	}
	if (input->colup.x[0] == 1)
	{
		if (input->colup.x[0] != input->rowleft.y[lim])
			angles_error(input, &error_found, lim, 2);
	}
	if (input->colup.x[lim] == 1)
	{
		if (input->colup.x[lim] != input->rowright.y[lim])
			angles_error(input, &error_found, lim, 3);
	}
	if (input->coldown.x[lim] == 1)
	{
		if (input->coldown.x[lim] != input->rowright.y[0])
			angles_error(input, &error_found, lim, 4);
	}
	return (error_found);
}

// Controllo sugli uno.
int	check_one(t_input *input)
{
	int	error_value;
	int	i;
	int	record_one;

	error_value = 0;
	i = -1;
	record_one = -1;
	while (++i != input->game_size)
		if (input->colup.x[i] == 1)
			++record_one;
	if (record_one >= 1)
		error_value += record_one;
	if (record_one >= 1)
		ones_error(record_one, 1);
	i = -1;
	record_one = -1;
	while (++i != input->game_size)
		if (input->coldown.x[i] == 1)
			++record_one;
	if (record_one >= 1)
		error_value += record_one;
	if (record_one >= 1)
		ones_error(record_one, 2);
	error_value += checkrow_one(input);
	return (error_value);
}

int	checkrow_one(t_input *input)
{
	int	error_value;
	int	i;
	int	record_one;

	error_value = 0;
	i = -1;
	record_one = -1;
	while (++i != input->game_size)
		if (input->rowleft.y[i] == 1)
			++record_one;
	if (record_one >= 1)
		error_value += record_one;
	if (record_one >= 1)
		ones_error(record_one, 3);
	i = -1;
	record_one = -1;
	while (++i != input->game_size)
		if (input->rowright.y[i] == 1)
			++record_one;
	if (record_one >= 1)
		error_value += record_one;
	if (record_one >= 1)
		ones_error(record_one, 1);
	return (error_value);
}

void	angles_error(t_input *input, int *error_found, int lim, int condition)
{
	ft_printf("\nERRORE 3: ");
	if (condition == 1)
	{
		ft_printf("input->coldown.x[0] e input->rowleft.y[0]\n");
		ft_printf("AKA %d,%d, ", input->coldown.x[0], input->rowleft.y[0]);
	}
	if (condition == 2)
	{
		ft_printf("input->colup.x[0] e input->rowleft.y[%d]\n", lim);
		ft_printf("AKA %d,%d, ", input->colup.x[0], input->rowleft.y[lim]);
	}
	if (condition == 3)
	{
		ft_printf("input->colup.x[%d] e input->rowright.y[%d]\n", lim, lim);
		ft_printf("AKA %d,%d, ", input->colup.x[lim], input->rowright.y[lim]);
	}
	if (condition == 4)
	{
		ft_printf("input->coldown.x[%d] e input->rowleft.y[0]\n", lim);
		ft_printf("AKA %d,%d, ", input->coldown.x[lim], input->rowright.y[0]);
	}
	ft_printf("non sono compatibili: \nse agli angoli uno dei due valori è ");
	ft_printf("il minimo(1), ");
	ft_printf("il valore nella parte opposta deve identico.\n-----------");
	++(*error_found);
}

void	ones_error(int record_one, int condition)
{
	record_one += 1;
	ft_printf("\nERRORE 6: ");
	if (condition == 1)
		ft_printf("In colup coesistono %d numeri di valore 1.", record_one);
	if (condition == 2)
		ft_printf("In coldown coesistono %d numeri di valore 1.", record_one);
	if (condition == 3)
		ft_printf("In rowleft coesistono %d numeri di valore 1.", record_one);
	if (condition == 4)
		ft_printf("In rowright coesistono %d numeri di valore 1.", record_one);
}

#endif