#include "header.h"

/*
	Questa funzione salva il nome dell'oggetto che 
	andremo a cercare.
	
	Se flag == 0 salviamo un nuovo nome in una statica.
	Se flag == 1, recuperiamo il valore della statica.
*/
char	*set_object_name(char *object_name, int flag)
{
	static char	*save;

	if (flag == 0)
	{
		save = object_name;
		return (NULL);
	}
	if (flag == 1)
	{
		return (save);
	}
}

void	*get_struct_data(char *search_struct, char *temp)
{
	int	fd;
	int	line_num;

	fd = open("test.c", O_RDONLY);
	if (fd == -1)
		return (NULL);
	search_struct = ft_strtrim(search_struct, "*");
	if (search_struct == NULL)
		return (NULL);
	if (add_s_(search_struct, &temp) == 1)
		return (free(search_struct), NULL);
	line_num = find_number_line(fd, "test.c", 1, temp);
	free(temp);
	close(fd);
	if (line_num > 0)
	{
		/*In caso sia una struttura, ricorsivamente si chiama finche non si
		  riempie tutta.
		  Infine, torna la struttura castandola a void.*/
	}
	else
		return (free(search_struct), printf("Errore: struct non trovata/tipo invalido.\n"), NULL);
}

void	*analyze_data(char *temp, char *type, char *data_name, int fd, char *filename)
{
	if ((ft_strncmp(temp, "char", 10) == 0) || (ft_strncmp(temp, "unsigned char", 17) == 0))
		return (get_char(type, data_name, fd, filename));
	if ((ft_strncmp(temp, "char*", 10) == 0) || (ft_strncmp(temp, "unsigned char*", 17) == 0))
		return (get_char_1ptr(type, data_name, fd, filename));
	if ((ft_strncmp(temp, "char**", 10) == 0) || (ft_strncmp(temp, "unsigned char**", 17) == 0))
		return (get_char_2ptr(type, data_name, fd, filename));
	if ((ft_strncmp(temp, "int", 10) == 0) || (ft_strncmp(temp, "unsigned int", 17) == 0))
		return (get_int(type, data_name, fd, filename));
	if ((ft_strncmp(temp, "int*", 10) == 0) || (ft_strncmp(temp, "unsigned int*", 17) == 0))
		return (get_int_1ptr(type, data_name, fd, filename));
	if (ft_strncmp(temp, "bool", 10) == 0)
		return (get_bool(type, data_name, fd, filename));
	if (ft_strncmp(temp, "float", 10) == 0)
		return (get_float(type, data_name, fd, filename));
	if (ft_strncmp(temp, "float*", 10) == 0)
		return (get_float_1ptr(type, data_name, fd, filename));
	if (ft_strncmp(temp, "void*", 10) == 0)
		return (get_ptr(type, data_name, fd, filename));
	return (NULL);
}

/*
	ottiene i dati per un certo oggetto di una data struct.
	le informazioni sono contenute in una lista.
*/
void	*get_data(t_typelist *node, char *data_name, int fd, char *filename)
{
	int			fd_2;
	int			line_num;
	char		*search_struct;
	char		*temp;

	if ((fd == -1) || (!node) || (!node->content) || (!node->type) \
	|| (!data_name) || (!filename))
		return (printf("Error: parsing in get_data\n"), NULL);
	if (find_number_line(fd, filename, 2, data_name, node->content) < 0)
		return (printf("Error: data for %s not found\n", \
		(char *)node->content), NULL);
	search_struct = (node->type);
	temp = ft_strdup(node->type);
	if ((!temp) || (format_search(&temp) == 1))
		return (free(temp), 1);
	line_num = find_number_line(fd, "available_types.txt", 2, "[LIST]", temp);
	free(temp);
	if (line_num == -1)
	{
		return (get_struct_data(search_struct, temp));
	}
	else
		return (analyze_data(temp, (char *)node->type, data_name, fd, filename));
}