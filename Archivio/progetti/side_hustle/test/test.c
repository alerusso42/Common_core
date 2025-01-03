#include "stdio.h"
#include "libft.h"
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"
#define DEBUG_PRINT 0

int	obtain_list(char *structure_name, t_typelist **list);

typedef struct	s_person
{
	char			*name;
	char			*surname;
	unsigned int	age:7;
}				person;

typedef struct	s_tempp_stats
{
	unsigned char	buff_stats[6];
	unsigned int	cur_hitpoints;
	unsigned int	initiative_score:7;
	bool			death_saves[3];
}				tempp_stats;

typedef struct	s_sheeet
{
	tempp_stats		*rayquaza;
	float			***example;
	unsigned int	strength:7;
	unsigned int	dexterity:7;
	unsigned int	constitution:7;
	unsigned int	intelligence:7;
	unsigned int	wisdom:7;
	unsigned int	charisma:7;
	unsigned int	proficiency:7;
	unsigned int	ispiration:7;
	unsigned int	speed:6;
	unsigned int	armour_class:7;
	unsigned int	initiative:6;
	unsigned int	max_hitpoints;
	unsigned char	*skills;
	unsigned int	attack_bonus:8;
	unsigned char	**weapon;
	unsigned char	**spell_list;//stringhe
}	sheeet;

typedef struct	s_car
{
	char			*name;
	unsigned int	max_speed:10;
	unsigned int	is_used:1;
	unsigned int	how_much_luis_inside:4;
	unsigned int	displacement:15;
}				car;

typedef union	u_all
{
	person	*person;
	car		*car;
}				u_all;

void	print_struct(t_typelist *list, char *where, int pos)
{
	int	counter;

	if (DEBUG_PRINT != 1)
		return ;
	counter = 1;
	if (pos == 0)
		printf("\n%s:\n", where);
	else
		printf("\n%s in position %d:\n", where, pos);
	if (!(list) || !(list->next))
		printf("\nl'è voto, grullo\n");
	while ((list) && (list->next))
	{
		printf("type n_%d: %s\n", counter, (char *)list->type);
		printf("type n_%d: %s\n\n", counter, (char *)list->content);
		list = list->next;
		++counter;
	}
	printf("\nNEXT!\n");
}

void	del(void *node)
{
	node = NULL;
	(void)node;
}

int	add_s_(char *string, char **new_string)
{
	size_t	len;

	if ((!string) || (!new_string))
		return (1);
	len = ft_strlen(string);
	*new_string = (char *)calloc(len + 3, sizeof(char));
	(*new_string)[0] = 's';
	(*new_string)[1] = '_';
	strcpy((*new_string) + 2, string);
	(*new_string)[len + 2] = 0;
	return (0);
}

char	*ft_strtrim_one(char const *s1, char const set)
{
	size_t	len;
	size_t	start;

	start = 0;
	len = ft_strlen((char *)s1);
	if (s1 == NULL)
		return (NULL);
	while (s1[start] && (set == s1[start]))
	{
		start++;
	}
	if (start == len)
	{
		return (ft_strdup(""));
	}
	while (len > 0 && (set == s1[len - 1]))
	{
		len--;
	}
	return (ft_substr(s1, start, len - start));
}

int	cut_string(char **string, size_t start, size_t end)
{
	unsigned int	temp;
	unsigned int	string_len;

	end++;
	if (!(string) || !(*string) || (start > end))
		return (1);
	string_len = ft_strlen(*string);
	temp = start;
	while ((start != end) && ((*string)[start] != 0))
		(*string)[start++] = 0;
	end = start;
	start = temp;
	temp = 0;
	while (end != string_len)
	{
		(*string)[start + temp] = (*string)[end + temp];
		--string_len;
		++temp;
	}
	if (temp != 0)
		(*string)[temp] = 0;
	end = ft_strlen(*string);
	if (alloc_ft((void **)string, (void *)*string, end, REALLOC) == 0)
		return (1);
	return (0);
}

int	move_square_brackets(char **type, char **name)
{
	int		start;
	int		end;
	char	*square_string;

	start = 0;
	while (((*name)[start]) && ((*name)[start] != '['))
		++start;
	if ((*name)[start] == 0)
		return (2);
	end = start;
	while (((*name)[end]) && ((*name)[end] != ']'))
		++end;
	square_string = ft_substr((*name), start, (end - start) + 1);
	if (!square_string)
		return (1);
	(*type) = ft_strjoin_custom((*type), square_string);
	if (!(*type))
		return (1);
	if (cut_string(name, start, end) == 1)
		return (1);
	if (move_square_brackets(type, name) == 1)
		return (1);
	return (0);
}

int	move_sign(char **type, char **name)
{
	unsigned int		count_sign;
	char				*temp;

	if ((!type) || (!name) || (!(*type)) || (!(*name)))
		return (1);
	temp = (*name);
	count_sign = 0;
	while (*(*name) == '*')
		if ((*(*name)++) == '*')
			count_sign++;
	(*name) = ft_strtrim_one(temp, '*');
	free(temp);
	if (!(*name))
		return (1);
	temp = (char *)ft_calloc(count_sign + 1, sizeof(char));
	if (!temp)
		return (1);
	temp[count_sign] = 0;
	while (count_sign--)
		temp[count_sign] = '*';
	(*type) = ft_strjoin_custom((*type), temp);
	if (!(*type) || (move_square_brackets(type, name) == 1))
		return (1);
	return (0);
}

int	trim_only_right(char **line, char *trimset)
{
	char			*trimmered_line;
	unsigned int	index;

	index = 0;
	while (ft_strchr(trimset, (*line)[index]) == NULL)
	{
		index++;
	}
	trimmered_line = ft_substr((*line), 0, index);
	if (!trimmered_line)
		return (1);
	free((*line));
	(*line) = trimmered_line;
	return (0);
}

int	add_sign_right(char **string, char sign)
{
	size_t	len;
	char	*new_string;

	if ((!string) || (!*string))
		return (1);
	len = ft_strlen(*string);
	new_string = (char *)calloc(len + 2, sizeof(char));
	if (!new_string)
		return (1);
	new_string[len] = sign;
	new_string[len + 1] = 0;
	strcpy(new_string, *string);
	free(*string);
	*string = new_string;
	return (0);
}

int	format_search(char **search_struct)
{
	unsigned int	start;
	unsigned int	end;

	start = 0;
	if (ft_strchr(*search_struct, '[') == NULL)
		return (0);
	while ("Loop: erase all [] :-)")
	{
		if ((*search_struct)[start] == 0)
			break ;
		if ((*search_struct)[start] == '[')
		{
			end = start;
			while ((*search_struct)[end] != ']')
				++end;
			if (cut_string(search_struct, start, end) == 1)
				return (1);
			if (add_sign_right(search_struct, '*') == 1)
				return (1);
			start = 0;
		}
		start++;
	}
	return (0);
}

int	available_types(char **type, char **name, int fd, t_typelist **list)
{
	int			line_num;
	int			fd_2;
	char		*search_struct;
	t_typelist	*new;
	char		*temp;

	search_struct = (*type);
	temp = ft_strdup(*type);
	if ((!temp) || (format_search(&temp) == 1))
		return (1);
	line_num = find_number_line(fd, "available_types.txt", 2, "[LIST]", temp);
	free(temp);
	if (line_num == -1)
	{
		fd_2 = open("test.c", O_RDONLY);
		if (fd_2 == -1)
			return (1);
		search_struct = ft_strtrim(search_struct, "*");
		if (search_struct == NULL)
			return (1);
		if (add_s_(search_struct, &temp) == 1)
			return (free(search_struct), 1);
		line_num = find_number_line(fd_2, "test.c", 1, temp);
		free(temp);
		close(fd_2);
		if (line_num > 0)
		{
			new = ft_lstnew(NULL, NULL);
			if (!new)
				return (free(search_struct), 1);
			ft_lstadd_back(list, new);
			temp = ft_strdup("s_");
			(*list)->type = (void *)ft_strjoin_custom(temp, *type);
			(*list)->content = (void *)(*name);
			(*type) = NULL;
			(*name) = NULL;
			if (obtain_list(search_struct, list) == 1)
				return (free(search_struct), 1);
			free(search_struct);
		}
		else
			return (free(search_struct), printf("Errore: struct non trovata/tipo invalido.\n"), 1);
	}
	return (0);
}

int	attach_to_list(char **type, char **name, t_typelist **list)
{
	t_typelist	*new;
	int			fd;

	fd = open("available_types.txt", O_RDONLY);
	if (*list == NULL)
		return (1);
	if (fd == -1)
		return (1);
	if (available_types(type, name, fd, list) == 1)
	{
		free(*type);
		free(*name);
		*type = NULL;
		*name = NULL;
		return (close(fd), 0);
	}
	if ((!(name) || !(*name)) && (!(type) || !(*type)))
		return (close(fd), 0);
	new = ft_lstnew(NULL, NULL);
	ft_lstadd_back(list, new);
	if (name)
		(*list)->content = (void *)(*name);
	if (type)
		(*list)->type = (void *)(*type);
	*list = (*list)->next;
	if (name)
		(*name) = NULL;
	(*type) = NULL;
	close(fd);
	return (0);
}//	0x55555555cd70

int	parse_struct_file(char *line, t_typelist **list)
{
	char	**matrix;
	char	*type;
	char	*name;
	int		index;

	matrix = ft_split(line, '\t');
	if (!matrix)
		return (1);
	index = 2;
	while ("Free mistakenly made string resulting from ft_split")
	{
		if (!(matrix[0]) || !(matrix[1]) || (!(matrix[index])))
			break ;
		free(matrix[index]);
		matrix[index] = NULL;
		index++;
	}
	type = matrix[0];
	if (!(matrix[1]))
		return (free(matrix), free(type), printf("Error n_6"), 1);
	name = matrix[1];
	free(matrix);
	trim_only_right(&name, ":;\n");
	move_sign(&type, &name);
	attach_to_list(&type, &name, list);
	return (0);
}

static int	manage_error(int error_num, int fd, char **search_struct_name)
{
	if (*search_struct_name)
		free(*search_struct_name);
	(*search_struct_name) = NULL;
	close(fd);
	printf("Errore numero %d", error_num);
	return (1);
}

int	first_node(t_typelist **list)
{
	t_typelist	*new;
	void		*content;
	void		*type;

	new = ft_lstnew(NULL, NULL);
	if (!new)
		return (1);
	content = (void *)ft_strdup("START");
	if (!content)
		return (1);
	type = (void *)ft_strdup("START");
	if (!type)
		return (1);
	(*list)->content = content;
	(*list)->type = type;
	ft_lstadd_back(list, new);
	(*list) = (*list)->next;
	return (0);
}

int	obtain_list(char *structure_name, t_typelist **list)
{
	char		*search_struct_name;
	int			line_num;
	char		*line;
	int			fd;
	t_typelist	*save;

	if (!(*list))
		(*list) = ft_lstnew(NULL, NULL);
	if (!(*list))
		return (1);
	save = *list;
	if (!(((*list)->type) && (ft_strncmp("s_", (*list)->type, 2) == 0)))
		if (first_node(list) == 1)
			return (1);
	print_struct(save, "INIZIO", 0);
	if (((char *)(*list)->type) && (ft_strncmp((char *)(*list)->type, "s_", 2) == 0))
		(*list) = (*list)->next;
	(*list)->next = NULL;
	fd = open("test.c", O_RDONLY);
	if (!fd)
		return (free(*list), printf("Errore n_1!"), 1);
	search_struct_name = NULL;
	if (add_s_(structure_name, &search_struct_name) == 1)
		return (manage_error(2, fd, &search_struct_name));
	line_num = find_number_line(fd, "test.c", 1, search_struct_name);
	if (line_num <= 0)
		return (manage_error(3, fd, &search_struct_name));
	free(search_struct_name);
	search_struct_name = NULL;
	line_num += 1;	// Il cursore si sposta alla prima linea buona di codice
	if (move_cursor(fd, "test.c", line_num) == -1)
		return (manage_error(4, fd, &search_struct_name));
	line = get_next_line(fd, 0);
	if (!line)
		return (manage_error(5, fd, &search_struct_name));
	if (ft_strncmp("{\n", line, 2) == 0)
	{
		free(line);// Se c'e una graffa\n va alla prossima linea di codice
		line = get_next_line(fd, 0);
		if (!line)
			return (manage_error(6, fd, &search_struct_name));
	}
	int	counter = 0;
	while (!ft_strchr(line, '}'))
	{

		++counter;
		if (parse_struct_file(line, list) == 1)
			return (free(line), manage_error(7, fd, &search_struct_name));
		free(line);
		line = get_next_line(fd, 0);// legge la linea x della struct
		if (!line)
			return (manage_error(8, fd, &search_struct_name));
		print_struct(save, "LOOP", counter);
	}
	if (*line != '}')
	{
		if (parse_struct_file(line, list) == 1)
			return (manage_error(9, fd, &search_struct_name));
		free(line);
		line = get_next_line(fd, 0);// legge la linea x della struct
		if (!line)
			return (manage_error(10, fd, &search_struct_name));
		print_struct(save, "LAST_STEP", 0);
	}
	(void)counter;
	free(line);
	close(fd);
	char	*temp;
	char	*temp_2;

	temp = (ft_strdup("END_OF_SUBLIST"));
	temp_2 = (ft_strdup("END_OF_SUBLIST"));
	if (!(temp) || !(temp_2))
		return (1);
	if (((char *)(save)->type) && (ft_strncmp((char *)(save)->type, "s_", 2) == 0))
		return (attach_to_list(&temp, &temp_2, list));
	*list = save;
	free(temp);
	free(temp_2);
	return (0);
}

/*
void	*fill_struct(char *structure_name)
{
	union u_all	*s;
	int			fd;
	void		*pointer;
	t_typelist	*list;

	obtain_list(structure_name, &list);
	s = (union u_all *)calloc(1, sizeof(all));
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

void	fill_list(t_typelist **list, char **matrix)
{
	t_typelist	*first_position;
	t_typelist	*new_node;

	(*list) = ft_lstnew(NULL, NULL);
	if (*list == NULL)
		return ;
	first_position = (*list);
	while ((list) && (matrix) && (*matrix))
	{
		(*list)->content = (void *)(*matrix);
		++matrix;
		new_node = ft_lstnew(NULL, NULL);
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
*/

/*
int	main()
{
	printf("\n-------SECOND_TEST-------\n");

	t_typelist	*list;
	t_typelist	*temp;
	int			counter;

	list = NULL;
	obtain_list("sheeet", &list);
	counter = 1;
	while ((list) && (list->next))
	{
		printf("type n_%d: %s\n", counter, (char *)list->type);
		printf("name n_%d: %s\n\n", counter, (char *)list->content);
		free(list->content);
		free(list->type);
		temp = list;
		list = list->next;
		free(temp);
		++counter;
	}
	if (list)
		free(list);
	return (0);
}//	0x55555555cd70
*/