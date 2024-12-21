NAME = manage_file_ft.a
LIBFT = Libft/libft.a
CP = cp
SRC = 	get_next_line_bonus.c \
		get_next_line_utils_bonus.c \
		ft_itoa.c \
		ft_memset.c \
		ft_memcmp.c \
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

main: re
	$(COMP) -g main.c $(NAME) -o hello_world.out
	rm -f $(OBJ) $(OBJ_BONUS)
	$(MAKE) clean -C $(LIBFT_RELATIVE_PATH)

gdb: 
	cc -g main.c $(SRC) $(LIBFT)
	clear
	gdb ./a.out

run:
	cc -g main.c $(SRC) $(LIBFT)
	clear
	./a.out

valgrind:
	cc -g main.c $(SRC) $(LIBFT)
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
