NAME = getmap.a
LIBFT = Libft/libft.a
LIBFTPRINTF = printf/libftprintf.a
CP = cp
SRC = 	alloc_input.c alloc_solution.c alloc_random.c \
		bfs.c \
		change_mod.c check_map.c check_map2.c check_map3.c \
		edit_map.c edit_map2.c error_message.c ft_light_printf.c \
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
	cp $(LIBFT) $(LIBFTPRINTF)
	cp $(LIBFTPRINTF) $(NAME)
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

folder_clean: 
	rm -f $(OBJ) $(OBJ_BONUS) $(NAME)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_RELATIVE_PATH)
	$(MAKE) fclean -C $(PRINTF_RELATIVE_PATH)

re: fclean all

main: 
	$(COMP) -g main.c $(SRC) $(LIBFTPRINTF) -o a.out
	rm -f $(OBJ) $(OBJ_BONUS)
	clear

gdb: main
	gdb --args ./a.out $(ARGS)

run: main
	./a.out $(ARGS)

val: main
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out $(ARGS)

val_noflags: re clean
	cc main.c $(NAME)
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out

test_g_low: main
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out gen 4 9

test_read: main
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out map.ber

.PHONY: all clean fclean re main gdb run valgrind val val_noflags
