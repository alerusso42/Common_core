/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:27:38 by alerusso          #+#    #+#             */
/*   Updated: 2024/11/25 00:35:43 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <malloc.h>
#include "libft.h"
#define UN_BOTTO 100

/*
int main()
{
	char	*data;
	t_list	*node;

	data = (char *)malloc(UN_BOTTO);
	if (!data)
		return (2);
	data = ft_strlcpy(data, "MEGA_RAYQUAZA E GABIBBO", UN_BOTTO);
	node = ft_lstnew((void *)data);
	printf("Contenuto: %s", node->content);
	if (!node)
		return (2);
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
}*/

t_list *ft_lstnew(void *content)
{
	char	*casted_content;
	t_list	*new_node;
	size_t	alloc_size;

	casted_content = (char *)content;
	alloc_size = ft_strlen(casted_content) + 1;
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = (char *)malloc(alloc_size);
	if (new_node->content == NULL)
		return (NULL);
	ft_strlcpy(new_node->content, casted_content, alloc_size + 2);
	new_node->next = NULL;
	return (new_node);
}
