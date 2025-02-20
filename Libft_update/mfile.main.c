/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfile.main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:40:49 by alerusso          #+#    #+#             */
/*   Updated: 2025/02/18 11:40:51 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* int	main()
{
	char	*string;
	int		fd;
	int		counter;
	int		line_num;

	counter = 5;
	fd = open("updated_pokedex.txt", O_RDWR);
	if (fd == -1)
		return (1);
	while (counter--)
	{
		string = get_next_line(fd, 0);
		//printf("%s", string);
		if (string)
		{
			free(string);
		}
		else
			break ;
	}
	reset_fd(fd, "updated_pokedex.txt");
	string = find_line(FIND, 3, "CHARMANDER", "Weight", NULL);
	printf("%s\n", string);
	line_num = atoi(string);
	free(string);
	string = get_next_line(fd, 0);
	printf("%s\n", string);
	//printf("%s", string);
	free(string);
	write_fucking_line(fd, line_num, 1, "777");
	fd = open("dati_personaggio.txt", O_RDWR);
	if (fd == -1)
	{
		fd = open("dati_personaggio.txt", O_RDWR | O_CREAT);
		if (fd == -1)
			return (1);
		initiate_file(fd, ft_itoa(1));
	}
	reset_fd(fd, "dati_personaggio.txt");
	string = find_line(FIND, fd, "PLAYER_1", "Name", NULL);
	line_num = atoi(string);
	free(string);
	reset_fd(fd, "dati_personaggio.txt");
	write_fucking_line(fd, line_num++, 1, "Marco");
	reset_fd(fd, "dati_personaggio.txt");
	write_fucking_line(fd, line_num++, 1, "27");
	reset_fd(fd, "dati_personaggio.txt");
	write_fucking_line(fd, line_num++, 1, "Bard");
	reset_fd(fd, "dati_personaggio.txt");
	write_fucking_line(fd, line_num, 1, "Gino");
	reset_fd(fd, "dati_personaggio.txt");
	write_fucking_line(fd, line_num, 2, "Beppe");
	reset_fd(fd, "dati_personaggio.txt");
	write_fucking_line(fd, line_num, 1, "Marco");
	return (0);
}
 */

/*
int main()
{
	char	*filename = "enemies.txt";
	int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (1);
	initiate_file(fd, "Rayquaza");
	int line_num = find_number_line(fd, "enemies.txt", 1, "Name = ");
	write_fucking_line(fd, filename, line_num++, 1, "Ale");//name
	write_fucking_line(fd, filename, line_num++, 1, "33");//age
	write_fucking_line(fd, filename, line_num++, 1, "10");//honor
	write_fucking_line(fd, filename, line_num++, 1, "10");//respect
	write_fucking_line(fd, filename, line_num++, 1, "spazzino");//job
	write_fucking_line(fd, filename, line_num++, 1, "Human");//race
	write_fucking_line(fd, filename, line_num++, 1, "Class");//class
	write_fucking_line(fd, filename, line_num++, 1, "N-N");//alignment
	write_fucking_line(fd, filename, line_num++, 1, "10");//strength
	write_fucking_line(fd, filename, line_num++, 1, "10");//dexterity
	close(fd);
	return (0);
}
*/
/*
int	main()
{
	int fd = open("available_types.txt", O_RDONLY);
	int line_num = find_number_line(fd, "available_types.txt", 2, "[LIST]", "unsigned int");
	if (line_num == -1)
		printf("Male");
	else
		printf("\n%d", find_number_line(fd, "available_types.txt", 2, "[LIST]", "unsigned int"));
}
*/

/*
int	main()
{
	char	*line;
	void	*save;
	char	**all_line;
	int		position;
	char	*filename = "default_values.txt";

	int	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	int	line_num = find_number_line(fd, filename, 2, "[LIST]", "char**");
	if (line_num == -1)
		return (1);
	position = 7;
	line = read_line(fd, filename, line_num, position);
	if (line == NULL)
		printf("sad\n");
	else
		printf("\n Linea %d, dato numero %d: %s\n", line_num, position, line);
	free(line);
		position = 2;
	line = read_line(fd, filename, line_num, position);
	if (line == NULL)
		printf("sad\n");
	else
		printf("\n Linea %d, dato numero %d: %s\n", line_num, position, line);
	free(line);
		position = 330;
	line = read_line(fd, filename, line_num, position);
	if (line == NULL)
		printf("sad\n");
	else
		printf("\n Linea %d, dato numero %d: %s\n", line_num, position, line);
	free(line);
	all_line = read_all_line(fd, filename, line_num);
	if (!all_line)
		return (1);
	save = (void *)all_line;
	position = 0;
	while (*all_line)
	{
		if (all_line == NULL)
			printf("sad\n");
		else
			printf("\n Linea %d, dato numero %d: %s\n", line_num, position, *all_line);
		position++;
		free(*all_line);
		++all_line;
	}
	printf("\n Linea %d, dato numero %d: %s\n", line_num, position, *all_line);
	free(save);
	return (0);
}
*/