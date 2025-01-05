NAME = manage_file_ft.a
LIBFT = Libft/libft.a
CP = cp
SRC = 	get_next_line_bonus.c \
		get_next_line_utils_bonus.c \
		get_next_line_utils_bonus2.c \
		ft_itoa.c \
		ft_memset.c \
		ft_memcmp.c \
		ft_split.c \
		main.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
COMP = cc -Wall -Werror -Wextra
LIBFT_RELATIVE_PATH = Libft/

all: $(NAME) clean
	

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(COMP) -c $< -o $@

clean: 
	rm -f $(OBJ) $(OBJ_BONUS) *.out

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_RELATIVE_PATH)

re: fclean all

main:
	$(COMP) -g $(SRC)
	rm -f $(OBJ)

gdb: 
	cc -g main.c $(SRC) $(LIBFT)
	clear
	gdb ./a.out

run:
	cc -g main.c $(SRC) $(LIBFT)
	clear
	./a.out

vgdb:
	$(COMP) -g $(SRC)
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --vgdb=yes --vgdb-error=0 -s ./a.out

valgrind:
	$(COMP) -g $(SRC)
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out

val: re clean
	$(COMP) main.c $(NAME)
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out

val_noflags: re clean
	cc main.c $(NAME)
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out

.PHONY: all clean fclean re main gdb run valgrind val val_noflags
