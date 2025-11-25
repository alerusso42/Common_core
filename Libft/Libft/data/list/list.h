/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:34:47 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/25 22:39:10 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "../../libft.h"

typedef struct s_list
{
	void	*content;
	void	*next;
}				t_list;

typedef struct s_list2
{
	void	*content1;
	void	*content2;
	void	*next;
}				t_list2;

#endif