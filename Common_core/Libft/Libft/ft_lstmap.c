/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:41:03 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 01:01:58 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <malloc.h>
#include "libft.h"
#define UN_BOTTO 100

t_list		*ft_lstnew(void *content);
static char	*ft_strcpy(char *dst, char *src);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);

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

	size_of_list = 293562;
	counter = 0;
	data = (char *)malloc(UN_BOTTO);
	if (!data)
		return (2);
	data = ft_strcpy(data, "MEGA_RAYQUAZA E GABIBBO");
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
	ft_strcpy(node_pointer->content, "Sono l'ultimo!");
	printf("\nLAST: %s\n", (char *)ft_lstlast(node)->content);
	while ((node->next))
	{
		if (node->content)
		{
			free(node->content);
			node->content = NULL;
		}
		node_pointer = node;
		node = node->next;
		if (node_pointer)
		{
			free(node_pointer);
			node_pointer = NULL;
		}
	}
	if (node->content)
	{
		free(node->content);
		node->content = NULL;
	}
	if (node)
	{
		free(node);
		node = NULL;
	}
	free(data);
	data = NULL;
	return (0);
}