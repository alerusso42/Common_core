/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:40:30 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/12 19:46:52 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#define UN_BOTTO 100

void		ft_lstdelone(t_list *lst, void (*del)(void *));

/*
static void	del(void *data)
{
	if (data)
	{
		free(data);
		data = NULL;
	}
}

int	main(void)
{
	char	*data;
	t_list	*node;
	t_list	*node_pointer;
	t_list	*new_pointer;
	size_t	size_of_list;
	size_t	counter;

	size_of_list = 20;
	counter = 0;
	data = (char *)malloc(UN_BOTTO);
	if (!data)
		return (2);
	ft_strlcpy(data, (const char *)"MEGA_RAYQUAZA E GABIBBO", UN_BOTTO);
	if (counter < size_of_list)
		node = ft_lstnew((void *)data);
	else
		node = NULL;
	if (!node)
	{
		free(data);
		data = NULL;
		return (2);
	}
	node_pointer = node;
	++counter;
	while ((counter < size_of_list) && (node_pointer))
	{
		new_pointer = ft_lstnew((void *)data);
		if (new_pointer)
		{
			ft_lstadd_front(&node_pointer, new_pointer);
		}
		else
		{
			break ;
		}
		node_pointer = new_pointer;
		++counter;
	}
	node_pointer->next = NULL;
	printf("Contenuto: %s", (char *)node->content);
	printf("\nNext: %p", node->next);
	printf("\nSIZE: %d", ft_lstsize(node));
	ft_strlcpy(node_pointer->content, (char *)"Sono l'ultimo!", UN_BOTTO);
	printf("\nLAST: %s\n", (char *)ft_lstlast(node)->content);
	while ((node->next))
	{
		node_pointer = node;
		node = node->next;
		ft_lstdelone(node_pointer, *del);
	}
	ft_lstdelone(node, *del);
	free(data);
	data = NULL;
	return (0);
}
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		del(lst->type);
		FREE(lst);
	}
}
