#include "stdio.h"
#include "libft.h"
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

typedef struct	s_typelist
{
	void	*content;
	void	*type;
	void	*next;
}				t_typelist;

typedef struct 	s_person
{
	char			*name;
	char			*surname;
	unsigned int	age:7;
}				person;

typedef struct 	s_car
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

int	add_s_(char *string, char **new_string)
{
	size_t	len;

	if ((!string) || (!new_string))
		return (1);
	len = strlen(*string);
	*new_string = calloc(len + 3, sizeof(char));
	if (!(*new_string));
	{
		return (1);
	}
	(*new_string)[0] = 's';
	(*new_string)[1] = '_';
	strcpy((*new_string) + 2, string);
	(*new_string)[len + 1] = 0;
	return (0);
}

int	obtain_list(char *structure_name, t_typelist **list)
{
	char		*search_struct_name;
	int			line_num;
	char		*line;
	char		**matrix;
	int			fd;

	fd = open("test.c", O_RDONLY);
	if (!fd)
		return (printf("Errore n_1!"), NULL);
	add_s_(structure_name, &search_struct_name);
	line_num = find_number_line(fd, "test.c", 1, search_struct_name);
	if (line_num <= 0)
		return (printf("Errore n_2!"), NULL);
	line_num += 1;	// Il cursore si sposta alla prima linea buona di codice
	move_cursor(fd, "test.c", line_num);
	line = get_next_line(fd, 0);
	if (strncmp("{", line, 1) == 0)
	{
		free(line);// Se c'e una graffa\n va alla prossima linea di codice
		line = get_next_line(fd, 0);
	}
	while (!strchr(line, '}'))
	{
		free(line);
		line = get_next_line(fd, 0);// legge la linea x della struct
		
	}
}

void	*fill_struct(char *structure_name)
{
	union s_all	*s;
	int			fd;
	void		*pointer;
	t_typelist	*list;

	obtain_list(structure_name, &list);
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

	ale = (person *)fill_struct("person");
	fiat = (car *)fill_struct("car");
	peugeot = (car *)fill_struct("peugeot");
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