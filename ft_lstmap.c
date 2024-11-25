/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:41:03 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 14:57:20 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <malloc.h>
#include "libft.h"
#define UN_BOTTO 100

t_list		*free_newlist(t_list **lst, void (*del)(void *));
static void ft_lstiter_custom(t_list *lst, void *(*f)(void *));

/*
int	main(void)
{
	char	*data;
	t_list	*node;
	t_list	*lstmap_node;
	t_list	*node_pointer;
	t_list	*new_node;
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
		new_node = ft_lstnew((void *)data);
		if (new_node)
		{
			ft_lstadd_front(&node_pointer, new_node);
		}
		else
		{
			break ;
		}
		node_pointer = new_node;
		++counter;
	}
	node_pointer->next = NULL;
	printf("Contenuto: %s", (char *)node->content);
	printf("\nNext: %p", node->next);
	printf("\nSIZE: %d", ft_lstsize(node));
	ft_strlcpy(node_pointer->content, (char *)"Sono l'ultimo!", UN_BOTTO);
	printf("\nLAST: %s\n", (char *)ft_lstlast(node)->content);
	ft_lstiter(node, *f);
	node_pointer = node;
	while (node_pointer->next)
	{
		printf("\nLSTITER(To_upper): %s\n", (char *)node_pointer->content);
		node_pointer = node_pointer->next;
	}
	printf("\nLSTITER(To_upper): %s\n", (char *)node_pointer->content);
	lstmap_node = ft_lstmap(node, *f);
	node_pointer = lstmap_node;
	while (node_pointer->next)
	{
		printf("\nLSTITER(To_upper): %s\n", (char *)node_pointer->content);
		node_pointer = node_pointer->next;
	}
	printf("\nLSTITER(To_upper): %s\n", (char *)node_pointer->content);
	while ((node->next))
	{
		node_pointer = node;
		node = node->next;
		ft_lstdelone(node_pointer, *del);
	}
	ft_lstdelone(node, *del);
	while ((lstmap_node->next))
	{
		node_pointer = lstmap_node;
		lstmap_node = lstmap_node->next;
		ft_lstdelone(node_pointer, *del);
	}
	ft_lstdelone(lstmap_node, *del);
	free(data);
	data = NULL;
	return (0);
}*/

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	
	ft_lstiter_custom(lst, *f);
	new_lst = (t_list *)malloc(sizeof(t_list));
	if (!new_lst)
		return (free_newlist(&new_lst, *del));
	new_lst = ft_lstnew((void *)lst->content);
	new_node = new_lst->next;
	lst = lst->next;
	while (lst)
	{
		new_node = ft_lstnew((void *)lst->content);
		if (new_node)
			ft_lstadd_back(&new_lst, new_node);
		else
			break ;
		lst = lst->next;
	}
	if (!new_node)
		return (free_newlist(&new_lst, *del));
	new_node->next = NULL;
	ft_lstiter_custom(new_lst, *f);
	return (new_lst);
}

t_list	*free_newlist(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, *del);
	(*lst) = NULL;
	return (NULL);
}

static void ft_lstiter_custom(t_list *lst, void *(*f)(void *))
{
	while (lst->next)
	{
		if (lst->content)
			lst->content = f(lst->content);
		lst = lst->next;
	}
	if (lst->content)
		lst->content = f(lst->content);
}
