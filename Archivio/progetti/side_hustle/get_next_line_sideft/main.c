/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:41:41 by alerusso          #+#    #+#             */
/*   Updated: 2024/12/20 18:01:12 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line_bonus.h"
# include "../gioco.h"

int		find_number_line(int fd, char *filename, int num_search, ...);
int		move_cursor(int fd, char *filename, int line_num);
char	*get_n_line(int fd, int n);
int		write_fucking_line(int fd, char *filename, int line_num, int position, char *string);
int		reset_fd(int fd, char *name);
char	*find_line(int flag, int fd, int num_search, va_list list);
void	initiate_file(int fd, char *num);
int		write_short_line(int fd, char *filename, int line_num, int position, char *string);

// Deprecata (da me stesso).
char	*line_fgm(int flag, int fd, int num_search, ...)
{
	char	*string;
	char	*search;
	int		counter;
	va_list	list;

	va_start(list, num_search);
	counter = 1;
	string = get_next_line(fd, 0);
	if (!string)
	{
		va_end(list);
		return (NULL);
	}
	search = va_arg(list, char *);
	while ((search) && (string) && (num_search--))
	{
		while (strstr(string, search) == NULL)
		{
			free(string);
			string = get_next_line(fd, 0);
			if (!string)
				break ;
			++counter;
		}
		search = va_arg(list, char *);
	}
	va_end(list);
	if (!string)
		return (NULL);
	free(string);
	if (flag == FIND)
		return (ft_itoa(counter));
	if (flag == GET)
		return (get_n_line(fd, counter));
	if (flag == MOVE)
		return (get_n_line(fd, counter - 1));
	return ("Metti le flag ammodo, mongoloide");
}


/*
Find_number_line riceve:
1) fd;
2) il nome del file come stringa;
3) il numero di confronti da fare;
4) un numero variadico di stringhe: le parole chiave che vuoi cercare nel file.
	
	le stringhe verranno cercate in ordine. Se, durante la ricerca, il cursore
	arriva alla fine del testo senza aver trovato tutte le linee, la funzione
	restituisce -1 (stessa cosa per errori di malloc).

Ritorno:
		Il numero della linea dove si trova la corrispondenza;
		-1, se la ricerca fallisce oppure in caso di errori di malloc.
		-2, se gli argomenti presi sono invalidi.
*/
int		find_number_line(int fd, char *filename, int num_search, ...)
{
	int		line_num;
	char	*string;
	va_list	ptr;

	if ((fd == -1) || (!filename))
		return (-2);
	va_start(ptr, num_search);
	reset_fd(fd, filename);
	string = find_line(FIND, fd, num_search, ptr);
	if (!string)
	{
		va_end(ptr);
		return (-1);
	}
	line_num = atoi(string);
	free(string);
	va_end(ptr);
	reset_fd(fd, filename);
	return (line_num);
}

/*
Hold_space riceve:
1) Il numero di spazi da inserire;
2) fd.
	
	Al termine, hold_space inserisce un carattere di nuova linea \n.

	Hold space non torna niente.
*/
void hold_space(int counter, int fd)
{
	while (counter--)
		write(fd, " ", 1);
	write(fd, "\n", 1);
}

/*
initiate_file riceve:
1) fd;
2) il nome del giocatore.
	
	initiate_file inizializza il file del giocatore.

	initiate_file non torna niente.
*/
void	initiate_file(int fd, char *name)
{
	int	counter;
	int	temp;
	
	counter = MIDWORDS_LEN * 10;
	temp = MIDWORDS_LEN * 10;
	write(fd, "[PLAYER_", 8);
	write(fd, name, strlen(name));
	free(name);
	write(fd, "]", 1);
	write(fd, "\n\n", 2);
	write(fd, "Name = ", 7);
	hold_space(counter, fd);
	write(fd, "Age = ", 7);
	hold_space(counter, fd);
	write(fd, "Class = ", 8);
	hold_space(counter, fd);
	write(fd, "Species = ", 11);
	hold_space(counter, fd);
	write(fd, "Friends = ", 10);
	hold_space(counter, fd);
	write(fd, "_ENDPLAYER_1]\n", 14);
	write(fd, "EOF\n", 4);
}

/*
write_short_line riceve:
1) fd;
2) il nome del file;
3) il numero della linea;
4) la posizione, nella linea, nel quale inserire la stringa;
5) la stringa da inserire.
	
	Scrive una stringa all'interno del file, ad una data linea (line_num),
	ad una certa posizione orizzontale (position).
	Esempio:
	write_fucking_line(3, "file. txt", 2, 2, "Rossi"); //Scrive alla linea 2, posizione 2.
1. [NPC_list]
2. Nome = Mario______, Rossi______, 

Ritorno:
		Il numero della linea dove si trova la corrispondenza;
		-1, se la ricerca fallisce oppure in caso di errori di malloc.

	Write_short_line scrive massimo 5 caratteri.
*/
int		write_short_line(int fd, char *filename, int line_num, int position, char *string)
{
	char	buffer[1];
	int		counter;
	char	*temp;

	if ((fd == -1) || (!string) || (position < 0) || (line_num < 0))
		return (-1);
	reset_fd(fd, filename);
	if (line_num != 1)
	{
		temp = get_n_line(fd, line_num - 1);
		if (!temp)
			return (-1);
		
		free(temp);
	}
	if (read(fd, buffer, 1) <= 0)
		return (-1);
	while ((buffer[0] != ' ') && (buffer[0] != '\n') && (buffer[0] != '\0'))
	{
		if (read(fd, buffer, 1) <= 0)
			return (-1);
	}
	if ((buffer[0] == '\n') || (buffer[0] == '\0'))
		return (-1);
	while ((position--))
	{
		if (read(fd, buffer, 1) <= 0)
			return (-1);
		while ((buffer[0] != ' ') && (buffer[0] != '\n') && (buffer[0] != '\0'))
		{
			if (read(fd, buffer, 1) <= 0)
				return (-1);
		}
		if ((buffer[0] == '\n') || (buffer[0] == '\0'))
			return (-1);
	}
	counter = 0;
	while (counter != SHORTWORDS_LEN)
	{
		if (*string)
		{
			write(fd, string, 1);
			string++;
		}
		else
			write(fd, "_", 1);
		++counter;
	}
	write (fd, ", ", 1);
	while ((buffer[0] == '\n') || (buffer[0] == '\0'))
	{
		if (read(fd, buffer, 1) <= 0)
			return (-1);
	}
	return (line_num);
}

/*
write_fucking_line riceve:
1) fd;
2) il nome del file;
3) il numero della linea;
4) la posizione, nella linea, nel quale inserire la stringa;
5) la stringa da inserire.
	
	Scrive una stringa all'interno del file, ad una data linea (line_num),
	ad una certa posizione orizzontale (position).
	Esempio:
	write_fucking_line(3, "file.txt", 2, 2, "Rossi"); //Scrive alla linea 2, posizione 2.
1. [NPC_list]
2. Nome = Mario______, Rossi______, 

Ritorno:
		Il numero della linea dove si trova la corrispondenza;
		-1, se la ricerca fallisce oppure in caso di errori di malloc.

	Write_fucking_line scrive massimo 11 caratteri.
*/
int		write_fucking_line(int fd, char *filename, int line_num, int position, char *string)
{
	char	buffer[1];
	int		counter;
	char	*temp;

	if ((fd == -1) || (!string) || (position < 0) || (line_num < 0))
		return (-1);
	reset_fd(fd, filename);
	if (line_num != 1)
	{
		temp = get_n_line(fd, line_num - 1);
		if (!temp)
			return (-1);
		
		free(temp);
	}
	if (read(fd, buffer, 1) <= 0)
		return (-1);
	while ((buffer[0] != ' ') && (buffer[0] != '\n') && (buffer[0] != '\0'))
	{
		if (read(fd, buffer, 1) <= 0)
			return (-1);
	}
	if ((buffer[0] == '\n') || (buffer[0] == '\0'))
		return (-1);
	while ((position--))
	{
		if (read(fd, buffer, 1) <= 0)
			return (-1);
		while ((buffer[0] != ' ') && (buffer[0] != '\n') && (buffer[0] != '\0'))
		{
			if (read(fd, buffer, 1) <= 0)
				return (-1);
		}
		if ((buffer[0] == '\n') || (buffer[0] == '\0'))
			return (-1);
	}
	counter = 0;
	while (counter != MIDWORDS_LEN)
	{
		if (*string)
		{
			write(fd, string, 1);
			string++;
		}
		else
			write(fd, "_", 1);
		++counter;
	}
	write (fd, ", ", 1);
	while ((buffer[0] == '\n') || (buffer[0] == '\0'))
	{
		if (read(fd, buffer, 1) <= 0)
			return (-1);
	}
	return (line_num);
}

/*
	move_cursor muove il cursore all'inizio della riga data come argomento.

	Prende come argomento:
	1) fd;
	2) il nome del file;
	3) il numero della linea.

	Torna -1 se fallisce(file vuoto, malloc error, argomenti non validi).
	Torna 0 se tutto va bene.
*/
int	move_cursor(int fd, char *filename, int line_num)
{
	char	*string;
	char	*search;

	if ((fd == -1) || (!filename) || (line_num < 1))
		return (-1);
	reset_fd(fd, filename);
	string = get_next_line(fd, 0);
	if (!string)
	{
		return (-1);
	}
	free(string);
	reset_fd(fd, filename);
	if (line_num != 1)
	{
		search = get_n_line(fd, line_num - 1);
		if (search)
			free(search);
	}
	return (0);
}

/*
Flags list
Find = 0 ---> finds where a line is located in a file text (in a string format)
Get  = 1 ---> Finds and give back the content of a line
Move = 2 ---> Moves the cursor to the line

Example:
find_line(GET, "[BEHOLDER]", "max_hp = ")

In this way, find_line finds before the line "[BEHOLDER]", then "max_hp".
If it finds both, it return the line of the last content, else return NULL.
*/
char	*find_line(int flag, int fd, int num_search, va_list list)
{
	char	*string;
	char	*search;
	int		counter;

	counter = 1;
	string = get_next_line(fd, 0);
	if (!string)
	{
		return (NULL);
	}
	search = va_arg(list, char *);
	while ((search) && (string) && (num_search--))
	{
		while (strstr(string, search) == NULL)
		{
			free(string);
			string = get_next_line(fd, 0);
			if (!string)
				break ;
			++counter;
		}
		search = va_arg(list, char *);
	}
	if (!string)
		return (NULL);
	free(string);
	if (flag == FIND)
		return (ft_itoa(counter));
	if (flag == GET)
		return (get_n_line(fd, counter));
	if (flag == MOVE)
		return (get_n_line(fd, counter - 1));
	return ("Metti le flag ammodo, mongoloide");
}

char	*get_n_line(int fd, int n)
{
	char	*line;

	line = NULL;
	while (n--)
	{
		if (line)
			free(line);
		line = get_next_line(fd, 0);
		if (!line)
			break ;
	}
	return (line);
}

int	reset_fd(int fd, char *name)
{
	get_next_line(fd, RESET);
	close(fd);
	fd = open(name, O_RDWR);
	return (0);
}

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
	int fd = open(filename, O_RDWR | O_CREAT, 0644);
	if (fd == -1)
		return (1);
	int line_num = find_number_line(fd, "enemies.txt", 1, "name = ");
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
}*/