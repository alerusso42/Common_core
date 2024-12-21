#include <stdio.h>
#include <unistd.h>
#include "get_next_line_sideft/get_next_line_bonus.h"
#include "struct.h"
#define ERROR 1
/*
int	fill_enemy_struct(random_encounter **enemy, int fd);

int	fill_enemy_struct(random_encounter **enemy, int fd)
{
	
}*/

int	initiate_enemy(int fd, char *name)
{
	int		counter;
	int		short_counter;
	int		long_counter;
	int		line_num;
	int		temp;

	(void)temp;
	if (fd == -1)
		return (ERROR);
	counter = MIDWORDS_LEN * 10;
	short_counter = MIDWORDS_LEN;
	long_counter = MIDWORDS_LEN * 60;
	reset_fd(fd, "enemies.txt");
	line_num = find_number_line(fd, "enemies.txt", 1, name);
	move_cursor(fd, "enemies.txt", line_num);
	write(fd, "   \n", 4);
	write(fd, name, strlen(name));
	write(fd, "\n\n", 2);
	write(fd, "name = ", 7);
	hold_space(counter, fd);
	write(fd, "age = ", 6);
	hold_space(short_counter, fd);
	write(fd, "honor = ", 8);
	hold_space(short_counter, fd);
	write(fd, "respect = ", 10);
	hold_space(short_counter, fd);
	write(fd, "job = ", 6);
	hold_space(counter, fd);
	write(fd, "race = ", 7);
	hold_space(counter, fd);
	write(fd, "class = ", 8);
	hold_space(counter, fd);
	write(fd, "alignment = ", 12);
	hold_space(short_counter, fd);
	write(fd, "_SHEET_\n", 8);
	write(fd, "strength = ", 11);
	hold_space(short_counter, fd);
	write(fd, "dexterity = ", 12);
	hold_space(short_counter, fd);
	write(fd, "constitution = ", 15);
	hold_space(short_counter, fd);
	write(fd, "intelligence = ", 15);
	hold_space(short_counter, fd);
	write(fd, "wisdom = ", 9);
	hold_space(short_counter, fd);
	write(fd, "charisma = ", 11);
	hold_space(short_counter, fd);
	write(fd, "proficiency = ", 14);
	hold_space(short_counter, fd);
	write(fd, "ispiration = ", 13);
	hold_space(short_counter, fd);
	write(fd, "speed = ", 8);
	hold_space(short_counter, fd);
	write(fd, "armour_class = ", 15);
	hold_space(short_counter, fd);
	write(fd, "initiative = ", 13);
	hold_space(short_counter, fd);
	write(fd, "max_hitpoints = ", 16);
	hold_space(short_counter, fd);
	write(fd, "current_hitpoints = ", 20);
	hold_space(short_counter, fd);
	write(fd, "attack_bonus = ", 15);
	hold_space(short_counter, fd);
	write(fd, "weapons = ", 10);
	hold_space(counter, fd);
	write(fd, "spell_list = ", 13);
	hold_space(long_counter, fd);
	write(fd, "_END_ENEMY]\n", 12);
	write(fd, "EOF\n", 4);
	line_num = find_number_line(fd, "enemies.txt", 2, name, "name = ");
	write_fucking_line(fd, "enemies.txt",  line_num++, 1, name);//name
	write_short_line(fd, "enemies.txt", line_num++, 1, "33");//age
	write_short_line(fd, "enemies.txt", line_num++, 1, "10");//honor
	write_short_line(fd, "enemies.txt", line_num++, 1, "10");//respect
	write_fucking_line(fd, "enemies.txt" , line_num++, 1, "spazzino");//job
	write_fucking_line(fd, "enemies.txt", line_num++, 1, "Human");//race
	write_fucking_line(fd, "enemies.txt", line_num++, 1, "Class");//class
	write_short_line(fd, "enemies.txt", line_num++, 1, "N-N");//alignment
	line_num++;
	write_short_line(fd, "enemies.txt", line_num++, 1, "10");//strength
	write_short_line(fd, "enemies.txt", line_num++, 1, "10");//dexterity
	write_short_line(fd, "enemies.txt", line_num++, 1, "10");//constitution
	write_short_line(fd, "enemies.txt", line_num++, 1, "10");//intelligence
	write_short_line(fd, "enemies.txt", line_num++, 1, "10");//wisdom
	write_short_line(fd, "enemies.txt", line_num++, 1, "10");//charisma
	write_short_line(fd, "enemies.txt", line_num++, 1, "10");//proficiency
	write_short_line(fd, "enemies.txt", line_num++, 1, "10");//ispiration
	write_short_line(fd, "enemies.txt", line_num++, 1, "12");//speed
	write_short_line(fd, "enemies.txt", line_num++, 1, "10");//armour_class
	write_short_line(fd, "enemies.txt", line_num++, 1, "5");//initiative
	write_short_line(fd, "enemies.txt", line_num++, 1, "15");//max_hitpoints
	write_short_line(fd, "enemies.txt", line_num++, 1, "15");//current_hitpoints
	write_short_line(fd, "enemies.txt", line_num++, 1, "15");//attack_bonus
	temp = line_num;
	write_fucking_line(fd, "enemies.txt", line_num, 1, "sword");//weapons
	line_num = temp;
	write_fucking_line(fd, "enemies.txt", line_num++, 2, "bow");//weapons
	temp = line_num;
	write_fucking_line(fd, "enemies.txt", line_num++, 1, "fireball");//spells
	line_num = temp;
	write_fucking_line(fd, "enemies.txt", line_num++, 2, "Fly");//spells
	write_fucking_line(fd, "enemies.txt", line_num++, 1, "END_ENEMY]\n");
	line_num++;
	write_fucking_line(fd, "enemies.txt", line_num++, 1, "EOF\n");
	return (0);
}

int	add_square_brackets(char **string)
{
	size_t	len;
	char	*save;

	if ((!string) || (!(*string)))
		return (ERROR);
	len = strlen(*string);
	save = *string;
	*string = calloc(len + 3, sizeof(char));
	if (!(*string))
	{
		return (ERROR);
	}
	(*string)[0] = '[';
	strcpy((*string) + 1, save);
	(*string)[len + 1] = ']';
	(*string)[len + 2] = 0;
	return (0);
}

int	gain_enemydata(random_encounter	**enemy, char *name)
{
	int	fd;
	int	line;

	fd = open("enemies.txt", O_RDWR | O_CREAT, 0644);;
	if (fd == -1)
		return (printf("Problem creating file"));
	if (!name)
		return (printf("Empty string as argument!"));
	if (add_square_brackets(&name) == ERROR)
		return (printf("Malloc error add square brackets || NULL string taken"));
	line = find_number_line(fd, "enemies.txt", 2, "[thief_1]", "max_hp = ");
	if (line == -1)
	{
		if (initiate_enemy(fd, name) == ERROR)//todo
		{
			free(name);
			return (printf("Problem reading file!"));
		}/*
		reset_fd(fd, "enemies.txt");
		if (fill_enemy_struct(enemy, fd) == ERROR)
		{
			free(name);
			freeall_enemy_struct();
			return (printf("malloc error in fill struct!"));
		}*/
	}/*
	else
	{
		free(line);
		reset_fd(fd, "enemies.txt");
		if (fill_struct() == ERROR)//todo
		{
			free(name);
			freeall_enemy_struct();
			return (printf("malloc error in fill struct!"));
		}
	}*/
	if (name)
		free(name);
	(void)enemy;
	close(fd);
	return (0);
}

int	main()
{
	random_encounter	*thief;

	thief = NULL;
	if (gain_enemydata(&thief, "Marco_2") != 0)
		return (printf("\nBAD_ENDING :-("));
}