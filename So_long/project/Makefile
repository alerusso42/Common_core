NAME = so_long.a
LIBFT = Libft/libft.a
PRINTF = printf/libftprintf.a
MINILIBX = minilibx-linux/minilibx.a
ALL = all.a
CP = cp
SRC = 	alloc_input.c alloc_solution.c alloc_random.c alloc_mlx.c \
		bfs.c \
		change_mod.c check_map.c check_map2.c check_map3.c \
		edit_map.c edit_map2.c error_message.c ft_light_printf.c \
		general_ft.c general_ft2.c get_map.c get_map2.c \
		get_next_line_bonus.c get_next_line_utils_bonus.c \
		print_stuff.c random_numbers.c reset_memory.c \
		save_map.c \
		switches.c variables.c main.c

OBJ = $(SRC:.c=.o)
#COMP = cc -g -Iminilibx -Lminilibx -lmlx -lX11 -lXext -lm -Lprintf -L$(MINILIBX_RELATIVE_PATH) -LLibft
COMP = -g -Wall -Wextra -Werror -ILibft -Iprintf
LIBX = -Lminilibx-linux -lX11 -lmlx -lXext -lft -lm -Lprintf -LLibft
LIBFT_RELATIVE_PATH = Libft/
PRINTF_RELATIVE_PATH = printf/
MINILIBX_RELATIVE_PATH = minilibx-linux/

all: $(NAME)
	
$(NAME) : $(LIBFT) $(PRINTF) $(MINILIBX) $(OBJ)
	cp $(LIBFT) $(PRINTF)
	$(MAKE) -C $(MINILIBX_RELATIVE_PATH)
	cp $(MINILIBX) $(PRINTF)
	touch $(ALL)
	cp $(PRINTF) $(ALL) 
	cc $(COMP) $(OBJ) $(ALL) $(LIBX)

#cp $(MINILIBX) $(NAME)
#ar rcs $(NAME) $(OBJ)

$(LIBFT) : 
	$(MAKE) -C $(LIBFT_RELATIVE_PATH)

$(PRINTF) : 
	$(MAKE) -C $(PRINTF_RELATIVE_PATH)

$(MINILIBX) : 
	$(MAKE) -C $(MINILIBX_RELATIVE_PATH)

%.o: %.c
	cc $(COMP) -c $< -o $@

clean: 
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_RELATIVE_PATH)
	$(MAKE) clean -C $(PRINTF_RELATIVE_PATH)
	$(MAKE) clean -C $(MINILIBX_RELATIVE_PATH)

folder_clean: 
	rm -f $(OBJ) $(NAME)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_RELATIVE_PATH)
	$(MAKE) fclean -C $(PRINTF_RELATIVE_PATH)
	$(MAKE) fclean -C $(MINILIBX_RELATIVE_PATH)

re: fclean all

main : $(LIBFT) $(PRINTF) $(MINILIBX)
	cp $(LIBFT) $(PRINTF)
	$(MAKE) -C $(MINILIBX_RELATIVE_PATH)
	cp $(MINILIBX) $(PRINTF)
	touch $(ALL)
	cp $(PRINTF) $(ALL) 
	cc $(COMP) $(SRC) $(ALL) $(LIBX)
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_RELATIVE_PATH)
	$(MAKE) clean -C $(PRINTF_RELATIVE_PATH)
	$(MAKE) clean -C $(MINILIBX_RELATIVE_PATH)

gdb: all
	gdb --args ./a.out $(ARGS)

run: all
	clear
	./a.out $(ARGS)

val: all
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out $(ARGS)

test_g_low: main
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out gen 4 9

test_read: main
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out map.ber

.PHONY: all clean fclean re main gdb run valgrind val val_noflags
.SILENT: