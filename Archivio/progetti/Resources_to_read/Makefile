NAME = readfile.a
CP = cp
SRC = 	get_next_line_bonus.c get_next_line_utils_bonus.c ft_itoa.c ft_calloc.c \
		ft_memset.c ft_strnstr.c ft_memcmp.c ft_strlen.c ft_strdup.c
OBJ = $(SRC:.c=.o)
COMP = cc -Wall -Werror -Wextra -g

gdb: 
	$(COMP) libft.a main.c $(SRC)
	clear
	gdb ./a.out

run:
	$(COMP) libft.a main.c $(SRC)
	clear
	./a.out

val:
	$(COMP) libft.a main.c $(SRC)
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out

.PHONY: all clean fclean re main gdb val run
