NAME = so_long
NAME_BONUS = so_long_bonus
LIBFT = Libft/libft.a
MINILIBX = minilibx-linux/minilibx.a
OBJ_DIR = obj_dir
OBJ_BONUS_DIR = obj_bonus_dir
BONUS_DIR = bonus_dir
ALL = all.a
CP = cp
SRC = 	alloc_input.c alloc_solution.c alloc_random.c alloc_mlx.c \
		bfs.c \
		change_mod.c change_mod2.c check_map.c check_map2.c check_map3.c \
		edit_map.c edit_map2.c error_message.c ft_light_printf.c \
		general_ft.c general_ft2.c get_map.c get_map2.c \
		get_next_line_bonus.c get_next_line_utils_bonus.c \
		print_stuff.c random_numbers.c reset_memory.c \
		save_map.c \
		add_pic.c check_pic.c reset_pic.c \
		print_mlx.c \
		mlx_key_setting.c \
		get_positions.c \
		move_player.c which_pacman.c \
		reset_game.c \
		switches.c variables.c main.c \

HEADER = 	get_next_line_bonus.h types.h z_error_list.h z_flags.h \
			z_event_list.h z_function_list.h

SRC_BONUS = $(SRC:.c=_bonus.c)
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BONUS_OBJ = $(addprefix $(OBJ_BONUS_DIR)/, $(SRC_BONUS:.c=.o))
#COMP = cc -g -Iminilibx -Lminilibx -lmlx -lX11 -lXext -lm -Lprintf -L$(MINILIBX_RELATIVE_PATH) -LLibft
COMP = -g -Wall -Wextra -Werror -ILibft -Iprintf
LIBX = -Lminilibx-linux -lX11 -lmlx -lXext -lft -lm -Lprintf -LLibft
LIBFT_RELATIVE_PATH = Libft/
PRINTF_RELATIVE_PATH = printf/
MINILIBX_RELATIVE_PATH = minilibx-linux/

all: $(NAME)
	
$(NAME) : $(LIBFT) $(MINILIBX) $(OBJ) $(OBJ_DIR) $(HEADER) $(OBJ_DIR)/dont_switch_to_bonus.o
	cp $(LIBFT) $(MINILIBX)
	touch $(ALL)
	cp $(MINILIBX) $(ALL) 
	cc $(COMP) $(OBJ) $(OBJ_DIR)/dont_switch_to_bonus.o $(ALL) $(LIBX) -o $(NAME)
	@echo "\nall done!!"

#cp $(MINILIBX) $(NAME)
#ar rcs $(NAME) $(OBJ)
#$(MAKE) -C $(MINILIBX_RELATIVE_PATH)

$(LIBFT) : 
	$(MAKE) -C $(LIBFT_RELATIVE_PATH)

$(MINILIBX) : 
	$(MAKE) -C $(MINILIBX_RELATIVE_PATH)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	cc $(COMP) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c | $(OBJ_BONUS_DIR)
	cc $(COMP) -c $< -o $@

$(HEADER):
	@echo "Missing header!"

$(OBJ_DIR)/dont_switch_to_bonus.o: $(OBJ_DIR) $(SRC)
	cc $(COMP) -c dont_switch_to_bonus.c -o $(OBJ_DIR)/dont_switch_to_bonus.o

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

$(OBJ_BONUS_DIR) : 
	mkdir -p $(OBJ_BONUS_DIR)

$(BONUS_DIR) : 
	mkdir -p $(BONUS_DIR)

copy_lib: $(BONUS_DIR)
	cp -r $(MINILIBX_RELATIVE_PATH) $(BONUS_DIR)
	cp -r $(LIBFT_RELATIVE_PATH) $(BONUS_DIR)

$(SRC_BONUS) : 
	@echo "I am creating the bonus files! P-e-f-forza"
	@for file in $(SRC); do \
		cp $$file $(BONUS_DIR)/$${file%.c}_bonus.c; \
	done
	@for file in $(HEADER); do \
		cp $$file $(BONUS_DIR)/$$file; \
	done
	cp switch_to_bonus.c $(BONUS_DIR)
	touch src_ok.txt

bonus: $(LIBFT) $(MINILIBX) $(BONUS_DIR) copy_lib $(OBJ_BONUS_DIR) $(SRC_BONUS) $(BONUS_OBJ) $(HEADER)
	cp $(LIBFT) $(MINILIBX)
	touch $(ALL)
	cp $(MINILIBX) $(ALL) 
	cc $(COMP) $(BONUS_OBJ) $(OBJ_BONUS_DIR)/switch_to_bonus.o $(ALL) $(LIBX) -o $(NAME_BONUS)
	@echo "\nall done!!"


clean: 
	rm -f $(OBJ) $(ALL) $(NAME) $(NAME_BONUS) *.out
	rm -rf $(OBJ_DIR) $(BONUS_DIR) $(OBJ_BONUS_DIR)
	$(MAKE) clean -C $(LIBFT_RELATIVE_PATH)
	$(MAKE) clean -C $(MINILIBX_RELATIVE_PATH)
	rm -f $(MINILIBX)

folder_clean: 
	rm -f $(OBJ) $(NAME)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_RELATIVE_PATH)

re: fclean all

gdb: all
	clear
	gdb --args ./$(NAME) $(ARGS)

run: all
	clear
	./$(NAME) $(ARGS)

val: all
	clear
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME) $(ARGS)

bonus_gdb: bonus
	clear
	gdb --args ./$(NAME_BONUS) $(ARGS)

bonus_run: bonus
	clear
	./$(NAME_BONUS) $(ARGS)

bonus_val: bonus
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(NAME_BONUS) $(ARGS)


norminette_exclude: 
	norminette | grep -v minilibx-linux


.PHONY: all clean fclean re main gdb run valgrind val val_noflags copy_lib norminette_exclude
.SILENT: