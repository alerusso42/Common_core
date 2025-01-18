NAME = getmap.a
LIBFT = Libft/libft.a
LIBFTPRINTF = printf/libftprintf.a
CP = cp
SRC = 	alloc_input.c alloc_solution.c alloc_random.c \
		change_mod.c check_map.c check_map2.c check_map3.c \
		edit_map.c edit_map2.c error_message.c ft_printf.c \
		general_ft.c general_ft2.c get_map.c get_map2.c \
		get_next_line_bonus.c get_next_line_utils_bonus.c \
		print_stuff.c random_numbers.c reset_memory.c \
		save_map.c \
		switches.c variables.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
COMP = cc -Wall -Werror -Wextra -g
LIBFT_RELATIVE_PATH = Libft/
PRINTF_RELATIVE_PATH = printf/

all: $(NAME)
	

$(NAME) : $(LIBFT) $(PRINTF) $(OBJ)
	cp $(LIBFT) $(PRINTF)
	cp $(PRINTF) $(NAME)
	ar rcs $(NAME) $(OBJ)

$(LIBFT) : 
	$(MAKE) -C $(LIBFT_RELATIVE_PATH)

$(PRINTF) : 
	$(MAKE) -C $(PRINTF_RELATIVE_PATH)

%.o: %.c
	$(COMP) -c $< -o $@

clean: 
	rm -f $(OBJ) $(OBJ_BONUS)
	$(MAKE) clean -C $(LIBFT_RELATIVE_PATH)
	$(MAKE) clean -C $(PRINTF_RELATIVE_PATH)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_RELATIVE_PATH)
	$(MAKE) fclean -C $(PRINTF_RELATIVE_PATH)

re: fclean all

main: re
	$(COMP) -g main.c $(NAME) -o a.out
	rm -f $(OBJ) $(OBJ_BONUS)
	$(MAKE) fclean -C $(LIBFT_RELATIVE_PATH)
	$(MAKE) fclean -C $(PRINTF_RELATIVE_PATH)

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
