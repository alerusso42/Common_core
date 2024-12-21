#include "stdio.h"
#include "libft.h"
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct 	s_test_1
{
	char			*name;
	char			*surname;
	unsigned int	age:7;
}				person;

typedef struct 	s_test_2
{
	char			*name;
	unsigned int	max_speed:10;
	unsigned int	is_used:1;
	unsigned int	how_much_luis_inside:4;
	unsigned int	displacement:15;
}				car;

typedef union	s_all
{
	person	*person;
	car		*car;
}				all;

void	del(void *node)
{
	node = NULL;
}

void	*fill_struct(char *structure_name, t_list *list)
{
	union s_all	*s;
	int			fd;
	void		*pointer;

	s = (union s_all *)calloc(1, sizeof(all));
	if (!s)
		return (NULL);
	if (strcmp("person", structure_name) == 0)
	{
		s->person = (person *)calloc(1, sizeof(person));
		if (!s->person)
			return (free(s), NULL);
		while (list->content)
		{
			if (strcmp("name", (char *)list->content) == 0)
			{
				s->person->name = (char *)calloc(11, 1);
				strcpy(s->person->name, "Alessandro");
			}
			else if (strcmp("surname", (char *)list->content) == 0)
			{
				s->person->surname = (char *)calloc(6, 1);
				strcpy(s->person->surname, "Russo");
			}
			else if (strcmp("age", (char *)list->content) == 0)
			{
				s->person->age = 24;
			}
			list = list->next;
		}
		pointer = (void *)s->person;
		free(s);
		return (pointer);
	}
	else if (strcmp("car", structure_name) == 0)
	{
		s->car = (car *)calloc(1, sizeof(car));
		if (!s->car)
			return (free(s), NULL);
		while (list->content)
		{
			if (strcmp("name", (char *)list->content) == 0)
			{
				s->car->name = (char *)calloc(5, 1);
				strcpy(s->car->name, "fiat");
			}
			else if (strcmp("max_speed", (char *)list->content) == 0)
			{
				s->car->max_speed = 280;
			}
			else if (strcmp("is_used", (char *)list->content) == 0)
			{
				s->car->is_used = 1;
			}
			else if (strcmp("how_much_luis_inside", (char *)list->content) == 0)
			{
				s->car->how_much_luis_inside = 15;
			}
			else if (strcmp("displacement", (char *)list->content) == 0)
			{
				s->car->displacement = 10000;
			}
			list = list->next;
		}
		pointer = (void *)s->car;
		free(s);
		return (pointer);
	}
	else
	{
		free(s);
		printf("\nStruttura %s inesistente.\n", structure_name);
		return (NULL);
	}
}

void	fill_list(t_list **list, char **matrix)
{
	t_list	*first_position;
	t_list	*new_node;

	(*list) = ft_lstnew(NULL);
	if (*list == NULL)
		return ;
	first_position = (*list);
	while ((list) && (matrix) && (*matrix))
	{
		(*list)->content = (void *)(*matrix);
		++matrix;
		new_node = ft_lstnew(NULL);
		if (!new_node)
		{
			ft_lstclear(&first_position, *del);
			*list = NULL;
			return ;
		}
		ft_lstadd_back(list, new_node);
		(*list) = (*list)->next;
	}
	(*list) = first_position;
}

int	main()
{
	char	*matrix_1[5] = {"name", "surname", "age"};
	char	*matrix_2[7] = {"name", "max_speed", "is_used", "how_much_luis_inside", "displacement"};

	t_list	*first;
	t_list	*second;

	fill_list(&first, matrix_1);
	fill_list(&second, matrix_2);

	person	*ale;
	car		*fiat;
	car		*peugeot;

	ale = (person *)fill_struct("person", first);
	fiat = (car *)fill_struct("car", second);
	peugeot = (car *)fill_struct("peugeot", first);
	printf("ale_data: name = %s, surname = %s, age = %u\n", ale->name, ale->surname, ale->age);
	printf("car_data: name = %s, max_speed = %u, is_used = %u, luis_inside = %u, displacement = %u\n", fiat->name, fiat->max_speed, fiat->is_used, fiat->how_much_luis_inside, fiat->displacement);
	free(ale->name);
	free(ale->surname);
	free(fiat->name);
	free(ale);
	free(fiat);
	ft_lstclear(&first, *del);
	ft_lstclear(&second, *del);
	return (0);
}