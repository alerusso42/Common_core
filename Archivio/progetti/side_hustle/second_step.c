/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:29:56 by negambar          #+#    #+#             */
/*   Updated: 2024/12/19 11:06:15 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gioco.h"

void and_so_the_story_starts(all *this, int a);

int	check_for_class(char *s)
{
	int	fd1 = open("classes.txt", O_RDONLY);
	// reset_fd(fd1, "classes.txt");
	char *str = get_next_line(fd1, 0);
	while (str && (strncmp(str, s, strlen(s)) != 0 && strncmp(str, s, strlen(s)) != 32))
	{
		free(str);
		str = get_next_line(fd1, 0);
	}
	if (!str)
		return (0);
	free(str);
	return (1);
}

int	second_step(all *this, int fd)
{
	int c;
	char *str = (char *)calloc(1, sizeof(char) * 100);

	printf("alright, let's get to it\n");
	usleep(500);
	system("clear");
	printf("alright, so...\nwhat class do you want?\n");
	while ((c = getchar()) != '\n' && c != EOF); // Clear the input buffer
	// fgets(str, 100, stdin);
	scanf("%99s", str);
	if (check_for_class(str))
	{
		this->p->class = str;
		size_t len = strlen(this->p->class);
		if (len > 0 && this->p->class[len - 1] == '\n')
			this->p->class[len - 1] = '\0';
		size_t size = strlen(this->p->class) + 1;
		this->p->class = realloc(this->p->class, size);
		reset_fd(fd, "player_info.txt");
		char *lns = find_line(FIND, fd, "Class = ", NULL);
		int n = atoi(lns);
		free(lns);
		reset_fd(fd, "player_info.txt");
		normalise_text(this->p->class);
		write_fucking_line(fd, n, 1, this->p->class);
		printf("\nnice choice!");
		return (and_so_the_story_starts(this, 0), 1);
	}
	char *printf = "why not try a different one?\n";
	write(1, printf, strlen(printf));
	sleep(1);
	free(str);
	return (second_step(this, fd), 0);
}

static void choice_2(all *this)
{
	printf("Ah, how do you remember to be called like?\n");
	char *new_name;
	new_name = calloc(sizeof(char), 100);
	scanf("%99s", new_name);
	this->p->name->first_name = realloc(this->p->name->first_name, strlen(new_name) + 1);
	normalise_text(new_name);
	new_name = strtrim(new_name, "\n ");
	strcpy(this->p->name->first_name, new_name);
	printf("I see, I see.");
}

void and_so_the_story_starts(all *this, int tryingsmt)
{
	char *name = "???";
	if (tryingsmt == 0)
		printf("%s: Finally you're awake!\n", name);
	usleep(500);
	printf("[choice]\n1)Where am I?\n2)Who am I?\n3){do nothing}\n");
	size_t choice = 0;
	scanf("%zu", &choice);
	if (choice == 1)
	{
		if (tryingsmt == 0 || tryingsmt == 2)
			printf("%s: Well, I have no idea either to be honest! *laughs*\n", name);
		and_so_the_story_starts(this, 2);
	}
	if (choice == 2)
	{
		printf("%s: I cannot be the one telling you this,\n \
 I heard them call you %s.\n", name, this->p->name->first_name);
		usleep(400);
		printf("???: Does it sound right to you, friend?\n\n[choice]\n\
1)I'm not a friend of yours\n2)Not really...\n3)Right, I'm %s...\n", this->p->name->first_name);
		choice = 0;
		scanf("%zu", &choice);
		if (choice == 1)
			printf("I'm sorry to offend you, and truly hope you'll forgive this error.\n");
		if (choice == 2)
			choice_2(this);
		if (choice == 3)
			return;
	}
	if (choice == 3)
	{
		if (tryingsmt == 0 || tryingsmt == 2)
			printf("%s: not that talkative, are we huh?\n", name);
		else
			and_so_the_story_starts(this, 1);
	}
}
