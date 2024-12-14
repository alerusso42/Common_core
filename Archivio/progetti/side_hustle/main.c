#include "gioco.h"

void reset(all *this, char *s);

static void initall(all *this)
{
	this->p = (player *)calloc(sizeof(player), 1);
	this->p->job = (classes *)calloc(sizeof(classes), 1);

	this->p->name = (names *)calloc(sizeof(names), 1);
	this->p->name->last_name = malloc(sizeof(char) * 100);
	this->p->name->m_nicknames = malloc(sizeof(char) * 100);
}

static void freeall(all *this)
{
	free(this->p->job);
	free(this->p->name->first_name);
	free(this->p->name->last_name);
	free(this->p->name->m_nicknames);
	free(this->p->name);
	free(this->p);
	free(this);
}

static void set_basics(all *this, int fd)
{
	char full[101];
    if (lseek(fd, 0, SEEK_END) == 0)
    {
        initiate_file(fd, strdup("1"));
        lseek(fd, 0, SEEK_SET);
	}
    printf("Narrator: Welcome, uh.. what's your name again? ");
    this->p->name->first_name = calloc(100, sizeof(char));
    fgets(this->p->name->first_name, 100, stdin);
    size_t len = strlen(this->p->name->first_name);
    if (len > 0 && this->p->name->first_name[len - 1] == '\n')
        this->p->name->first_name[len - 1] = '\0';
    size_t size = strlen(this->p->name->first_name) + 1;
    this->p->name->first_name = realloc(this->p->name->first_name, size);
	reset_fd(fd, "player_info.txt");
    char *line_num_str = find_line(FIND, fd, "Name = ", NULL);
    int line_num = atoi(line_num_str);
    free(line_num_str);
	reset_fd(fd, "player_info.txt");
    write_fucking_line(fd, line_num, 1, this->p->name->first_name);
    printf("\nright, %s, finally you're here\n", this->p->name->first_name);
    printf("I'm sorry to ask, dear friend, but how old are you exactly? ");
    scanf("%zu", &this->p->age);
    snprintf(full, sizeof(full), "%zu", this->p->age);
	reset_fd(fd, "player_info.txt");
    line_num_str = find_line(FIND, fd, "Age = ", NULL);
    line_num = atoi(line_num_str);
    free(line_num_str);
    reset_fd(fd, "player_info.txt");
    write_fucking_line(fd, line_num, 1, full);
    if (this->p->age <= 17)
    {
        printf("I'm sorry little one, you aren't who I thought you were.\
Come back when you're older.\n\n\n\n\n");
        reset(this, NULL);
        return;
    }
	write(1, "very well, then, shall we start?", 33);
	sleep(3);
	system("clear");
    close(fd);
	// second_step();
}

void reset(all *this, char *s)
{
	int fd = open("player_info.txt", O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("Failed to reset file");
		if (s)
			free(s);
		freeall(this);
		return;
	}
	set_basics(this, fd);
}

int main(int ac, char **av)
{
	all		*this;
	int		fd = open("player_info.txt", O_RDWR);
	char	*s = gnl(fd);

	this = (all *)calloc(sizeof(all), 1);
	initall(this);
	names *name = this->p->name;
	if (!s)
		set_basics(this, fd);
	else if (s && ac == 1)
	{
		char *mynameis;
		name->first_name = get_that_line(fd, "Name = ", s);
		// printf("\ns:%s", s);
		if (!name->first_name)
			return (free(s), freeall(this), 1);
		mynameis = name->first_name;
		name->first_name = strtrim(mynameis, "\n");
		free(mynameis);
		if (!name->first_name)
			return (free(s), freeall(this), 1);
		printf("Ah, yes,%s, welcome back!\n", name->first_name);
	}
	else if (strcmp(av[1], "reset") == 0)
		return(reset(this, s), 1);
	else if (strcmp(av[1], "debug") == 0)
		fd = open("player_info.txt", O_TRUNC);
	close(fd);
	freeall(this);
	return (0);
}
