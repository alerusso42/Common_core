/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:43:50 by codespace         #+#    #+#             */
/*   Updated: 2025/06/16 19:20:53 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	collision_adder(t_data *data, int hash_pos);
static void	collision_reset(t_data *data, int i);

/**
 * @brief   Add a hash_file index in the collision array
 *
 * 		if get_lowest_key() has failed in updating the key,
 * 		two variables have the same key: therefore there is a collision.
 *		if there is a collision:
 *		collision_adder is called, and 
 * 		
 * 
 *  
 *
 * @param[in]  data   		struct
 * @param[in]  old_key  	key of previous call of get_lowest_key()
 * @param[in]  lowest_key 	key of current call of get_lowest_key()
 * @param[in]  i 			pointer of hash_file write cursor
 * @return     none
 *
 * @note               [Any extra notes—e.g. side effects, thread-safety, performance caveats]
 *
 * @warning            [Optional: if misuse can lead to undefined behavior]
 *
 * @par Example
 * @code
 *   int x = 2, y = 3;
 *   int sum = add_simple(x, y);
 *    sum is now 5 */

void	collision_update(t_data *data, int old_key, int lowest_key, int *i)
{
	if (old_key == lowest_key)
		collision_adder(data, lowest_key);
	else
	{
		collision_reset(data, *i);
		++(*i);
	}
}

static void	collision_adder(t_data *data, int hash_pos)
{
	int	i;

	i = 0;
	while (data->collision[i])
		++i;
	data->collision[i] = hash_pos;
    ft_putstr_fd(" ", data->hash_fd.p);
}

static void	collision_reset(t_data *data, int struct_i)
{
	int		i;
	char	*temp;

	i = 0;
	while (data->collision[i])
	{
		data->collision[i] = 0;
		++i;
	}
	ft_putstr_fd("\n", data->hash_fd.p);
	temp = ft_itoa(struct_i);
	if (!temp)
		error(data, ER_MALLOC);
	ft_putstr_fd(temp, data->hash_fd.p);
	ft_putstr_fd(" :\t", data->hash_fd.p);
	free(temp);
}

int	collision_check(t_data *data, int hash_pos)
{
	int	i;

	i = 0;
	while (data->collision[i])
	{
		if (data->collision[i] == hash_pos)
			return (1);
		++i;
	}
	return (0);
}
