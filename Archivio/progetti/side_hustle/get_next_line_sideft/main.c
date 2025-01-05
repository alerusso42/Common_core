/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:41:41 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/05 15:21:29 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line_bonus.h"
# include <string.h>
# include <stdlib.h>
# include "../gioco.h"

int		find_number_line(int fd, char *filename, int num_search, ...);
int		move_cursor(int fd, char *filename, int line_num);
char	*get_n_line(int fd, int n);
int		write_fucking_line(int fd, char *filename, int line_num, int position, char *string);
int		reset_fd(int fd, char *name);
char	*find_line(int flag, int fd, int num_search, va_list list);
void	initiate_file(int fd, char *num);
int		write_short_line(int fd, char *filename, int line_num, int position, char *string);

static size_t	ft_strlen(const char *string)
{
	int	counter;

	counter = 0;
	while (string[counter])
		++counter;
	return (counter);
}

static char	*ft_strdup(const char *str)
{
	int		n;
	char	*camillo;

	if (!str)
		return (NULL);
	n = 0;
	while (str[n] != '\0')
		++n;
	camillo = NULL;
	n += 1;
	camillo = (char *)calloc(n, sizeof(char));
	if (camillo == NULL)
		return (0);
	n = 0;
	while (str[n] != '\0')
	{
		camillo[n] = str[n];
		++n;
	}
	return (camillo);
}

static int	ft_realloc(void **content, size_t nmemb, size_t size)
{
	void	*re_content;

	re_content = calloc(nmemb, size);
	if (!(re_content))
		return (1);
	memcpy(re_content, *content, nmemb - size);
	free(*content);
	*content = re_content;
	return (0);
}

static int	cut_string(char **string, size_t start, size_t end)
{
	unsigned int	temp;
	unsigned int	string_len;

	if (!(string) || !(*string) || (start > end) || (start == strlen(*string)))
		return (1);
	end++;
	string_len = strlen(*string);
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
	end = strlen(*string);
	if (ft_realloc((void **)string, end + 1, sizeof(char)))
		return (1);
	return (0);
}

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
	
	counter = MIDWORDS_LEN * 10;
	write(fd, "[PLAYER_", 8);
	write(fd, name, strlen(name));
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
	set_maximum_word_len contiene il numero massimo di
	caratteri che write_line può scrivere (che è anche
	il minimo numero di caratteri, vedi "write_line").
	Il valore è definito da un int statico.

	Riceve come argomento un int.

	Se è positivo o zero, modifica l'attuale limite
	di caratteri di write_line, e lo restituisce.
	
	Altrimenti, ritorna il limite attuale senza fare
	altro.
*/
int	set_maximum_word_len(int new_len)
{
	static int	maximum_word_len = MIDWORDS_LEN;

	if (new_len < 0)
		return (maximum_word_len);
	maximum_word_len = new_len;
	return (maximum_word_len); 
}

void	free_matrix(char **matrix)
{
	int	index;

	index = 0;
	if (!matrix)
		return ;
	while (matrix[index])
	{
		if (matrix[index])
			free(matrix[index]);
		matrix[index] = NULL;
		++index;
	}
	if (matrix)
		free(matrix);
}

/*	read_line riceve:
1) fd;
2) il nome del file;
3) il numero della linea.
	
	Legge le stringhe all'interno del file, salvandole in una  
	matrice, ad una data linea (line_num).
	Esempio:
	read_all_line(3, "file.txt", 2); //Legge la linea 2.
1. [NPC_list]
2. Nome = Mario______, Rossi______,  // Legge e torna "Mario", "Rossi".

Ritorno:
		La matrice richiesta, senza , e _ finali;
		NULL, se la ricerca fallisce oppure in caso di errori di malloc.
*/
char	**read_all_line(int fd, char *filename, int line_num)
{
	int		counter;
	char	*temp;
	char	**matrix;
	int		position;

	if ((fd == -1) || (line_num < 0))
		return (NULL);
	reset_fd(fd, filename);
	if (line_num != 1)
	{
		move_cursor(fd, filename, line_num);
	}
	temp = get_next_line(fd, 0);
	if (!temp)
		return (NULL);
	matrix = ft_split(temp, ',');// Splitta la linea ottenuta con ft_split
	free(temp);
	if ((!matrix) || !(*matrix))
		return (NULL);
	counter = 0;
	if (!matrix[1])// Verifica che la posizione richiesta esista.
	{
		return (free_matrix(matrix), NULL);
	}
	while ((matrix[0][counter] != '=') || (matrix[0][counter + 1] != ' '))
		++counter;
	++counter;
	cut_string(&(matrix[0]), 0, counter);
	if (!matrix[0])
		return (free_matrix(matrix), NULL);
	position = 0;
	while (matrix[position]) // sistema tutte le stringhe.
	{
		counter = 0;
		while (matrix[position][counter])// Elimina ',' e '_' di troppo.
			++counter;
		if (counter == 0)
			return (free_matrix(matrix), NULL);
		counter -= 1;
		while (matrix[position][counter] == '_')
			--counter;
		++counter;
		cut_string(&(matrix[position]), counter, ft_strlen(matrix[position]));
		if (matrix[position][0] == ' ')
			cut_string(&(matrix[position]), 0, 0);
		if (matrix[position][0] == '\n')
		{
			free(matrix[position]);
			matrix[position] = NULL;
		}
		++position;
	}
	return (matrix);
}

/*	read_line riceve:
1) fd;
2) il nome del file;
3) il numero della linea;
4) la posizione, nella linea, nel quale inserire la stringa.
	
	Legge una stringa all'interno del file, ad una data linea (line_num),
	ad una certa posizione orizzontale (position).
	Esempio:
	read_line(3, "file.txt", 2, 2); //Legge alla linea 2, posizione 2.
1. [NPC_list]
2. Nome = Mario______, Rossi______,  // Legge e torna "Rossi".

Ritorno:
		La stringa richiesta, senza , e _ finali;
		NULL, se la ricerca fallisce oppure in caso di errori di malloc.
*/
char	*read_line(int fd, char *filename, int line_num, int position)
{
	int		counter;
	char	*temp;
	char	**matrix;

	if ((fd == -1) || (position < 0) || (line_num < 0))
		return (NULL);
	reset_fd(fd, filename);
	if (line_num != 1)
	{
		move_cursor(fd, filename, line_num);
	}
	temp = get_next_line(fd, 0);
	if (!temp)
		return (NULL);
	matrix = ft_split(temp, ',');// Splitta la linea ottenuta con ft_split
	free(temp);
	if ((!matrix) || !(*matrix))
		return (NULL);
	counter = 0;
	while (counter != position)// Verifica che la posizione richiesta esista.
	{
		if (!(matrix[counter]))
			return (free_matrix(matrix), NULL);
		if (counter == 0)
		{
			counter++;
			if (!(matrix[counter]))
				return (free_matrix(matrix), NULL);
			if (counter == position)
				break ;
		}
		++counter;
	}
	if (position == 0)// Se position è zero, torna quello che c'è prima di '='
	{
		while ((matrix[0][counter] != '=') || (matrix[0][counter + 1] != ' '))
			++counter;
		++counter;
		cut_string(matrix, counter, strlen(matrix[0]));
		temp = ft_strdup(matrix[0]);
		return (free_matrix(matrix), temp);
	}
	if (position == 1)//Se position è uno, elimina quello che c'è prima di "= "
	{
		while ((matrix[0][counter] != '=') || (matrix[0][counter + 1] != ' '))
			++counter;
		++counter;
		cut_string(&(matrix[0]), 0, counter);
		temp = ft_strdup(matrix[0]);
		return (free_matrix(matrix), temp);
	}
	counter = 0;
	position--;
	while (matrix[position][counter])// Elimina ',' e '_' di troppo.
		++counter;
	if (counter == 0)
		return (free_matrix(matrix), NULL);
	--counter;
	while (matrix[position][counter] == '_')
		--counter;
	++counter;
	cut_string(&(matrix[position]), counter, ft_strlen(matrix[position]));
	temp = ft_strdup(matrix[position]);
	if (temp[0] == ' ')
		cut_string(&temp, 0, 0);
	return (free_matrix(matrix), temp);
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

	Write_line ha un limite massimo di caratteri (10).
	Può essere cambiato in fase di esecuzione, con la
	funzione "set_maximum_word_len".
*/
int		write_line(int fd, char *filename, int line_num, int position, char *string)
{
	int		counter;
	char	*temp;
	int		maximum_word_len;

	if ((fd == -1) || (!string) || (position < 0) || (line_num < 0))
		return (-1);
	reset_fd(fd, filename);
	if (line_num != 1)
	{
		while ("move the cursor to the start of the line")
		{
			if (line_num == 1)
				break ;
			temp = get_next_line(fd, 1);
			if (!temp)
				return (-1);
			if (*temp == '\n')
				--line_num;
			free(temp);
		}
	}
	temp = get_next_line(fd, 1);
	if (!temp)
		return (-1);
	while ((temp[0] != ' ') && (temp[0] != '\n') && (temp[0] != '\0'))
	{
		free(temp);
		temp = get_next_line(fd, 1);
	if (!temp)
		return (-1);
	}
	if ((temp[0] == '\n') || (temp[0] == '\0'))
		return (free(temp), -1);
	while ((position--))
	{
		free(temp);
		temp = get_next_line(fd, 1);
		if (!temp)
			return (-1);
		while ((temp[0] != ' ') && (temp[0] != '\n') && (temp[0] != '\0'))
		{
			free(temp);
			temp = get_next_line(fd, 1);
			if (!temp)
				return (-1);
		}
		if ((temp[0] == '\n') || (temp[0] == '\0'))
			return (free(temp), -1);
	}
	counter = 0;
	maximum_word_len = set_maximum_word_len(-1);
	while (counter != maximum_word_len)
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
	while ((temp[0] == '\n') || (temp[0] == '\0'))
	{
		free(temp);
		temp = get_next_line(fd, 1);
		if (!temp)
			return (-1);
	}
	free(temp);
	return (0);
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
	int		counter;
	char	*temp;

	if ((fd == -1) || (!string) || (position < 0) || (line_num < 0))
		return (-1);
	reset_fd(fd, filename);
	if (line_num != 1)
	{
		while ("move the cursor to the start of the line")
		{
			if (line_num == 1)
				break ;
			temp = get_next_line(fd, 1);
			if (!temp)
				return (-1);
			if (*temp == '\n')
				--line_num;
			free(temp);
		}
	}
	temp = get_next_line(fd, 1);
	if (!temp)
		return (-1);
	while ((temp[0] != ' ') && (temp[0] != '\n') && (temp[0] != '\0'))
	{
		free(temp);
		temp = get_next_line(fd, 1);
	if (!temp)
		return (-1);
	}
	if ((temp[0] == '\n') || (temp[0] == '\0'))
		return (free(temp), -1);
	while ((position--))
	{
		free(temp);
		temp = get_next_line(fd, 1);
		if (!temp)
			return (-1);
		while ((temp[0] != ' ') && (temp[0] != '\n') && (temp[0] != '\0'))
		{
			free(temp);
			temp = get_next_line(fd, 1);
			if (!temp)
				return (-1);
		}
		if ((temp[0] == '\n') || (temp[0] == '\0'))
			return (free(temp), -1);
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
	while ((temp[0] == '\n') || (temp[0] == '\0'))
	{
		free(temp);
		temp = get_next_line(fd, 1);
		if (!temp)
			return (-1);
	}
	free(temp);
	return (0);
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
	int		counter;
	char	*temp;

	if ((fd == -1) || (!string) || (position < 0) || (line_num < 0))
		return (-1);
	reset_fd(fd, filename);
	if (line_num != 1)
	{
		while ("move the cursor to the start of the line")
		{
			if (line_num == 1)
				break ;
			temp = get_next_line(fd, 1);
			if (!temp)
				return (-1);
			if (*temp == '\n')
				--line_num;
			free(temp);
		}
	}
	temp = get_next_line(fd, 1);
	if (!temp)
		return (-1);
	while ((temp[0] != ' ') && (temp[0] != '\n') && (temp[0] != '\0'))
	{
		free(temp);
		temp = get_next_line(fd, 1);
	if (!temp)
		return (-1);
	}
	if ((temp[0] == '\n') || (temp[0] == '\0'))
		return (free(temp), -1);
	while ((position--))
	{
		free(temp);
		temp = get_next_line(fd, 1);
		if (!temp)
			return (-1);
		while ((temp[0] != ' ') && (temp[0] != '\n') && (temp[0] != '\0'))
		{
			free(temp);
			temp = get_next_line(fd, 1);
			if (!temp)
				return (-1);
		}
		if ((temp[0] == '\n') || (temp[0] == '\0'))
			return (free(temp), -1);
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
	while ((temp[0] == '\n') || (temp[0] == '\0'))
	{
		free(temp);
		temp = get_next_line(fd, 1);
		if (!temp)
			return (-1);
	}
	free(temp);
	return (0);
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
	char	*search;

	if ((fd == -1) || (!filename) || (line_num < 1))
		return (-1);
	reset_fd(fd, filename);
	if (line_num == 1)
		return (0);
	search = get_n_line(fd, line_num - 1);
	if (!search)
		return (1);
	free(search);
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

/*
	Richiama get_next_line n volte.
	
	Torna NULL se non trova la linea o se fallisce.
	Altrimenti, torna la linea richiesta.
*/
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

/*
	reset_fd reimposta read all'inizio del file, e contemporaneamente
	resetta il buffer di get_next_line.
*/
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
