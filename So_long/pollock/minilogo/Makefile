NAME = minilogo.a
LIBFT = printf/libftprintf.a
CP = cp
SRC = 	init_turtle.c init_minilibx.c rotate_turtle.c set_pen.c \
		move_turtle.c move_turtle2.c
OBJ = $(SRC:.c=.o)
COMP = cc -Wall -Werror -Wextra
LIBFT_RELATIVE_PATH = printf/

all: $(NAME)
	

$(NAME) : $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(LIBFT) : 
	$(MAKE) -C $(LIBFT_RELATIVE_PATH)

%.o: %.c
	$(COMP) -c $< -o $@

clean: 
	rm -f $(OBJ) *.out
	$(MAKE) clean -C $(LIBFT_RELATIVE_PATH)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_RELATIVE_PATH)

re: fclean all

main: re
	$(COMP) -g main.c $(NAME) -o hello_world.out
	rm -f $(OBJ)
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
