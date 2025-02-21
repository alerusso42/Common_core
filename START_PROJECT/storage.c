/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:27:34 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/21 15:31:42 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	mode == 0---->	GIVE ptr
	mode == 1---->	TAKE ptr
*/
void	*storage(void *ptr, int mode)
{
	static void	*stock;

	if (mode == 0)
		stock = ptr;
	else if (mode == 1)
		return (stock);
	return (NULL);
}
