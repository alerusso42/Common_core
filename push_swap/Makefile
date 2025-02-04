NAME = push_swap
NAME_BONUS = push_swap_bonus
LIBFT = Libft/libft.a
OBJ_DIR = obj_dir
OBJ_BONUS_DIR = obj_bonus_dir
BONUS_DIR = bonus_dir
ALL = all.a
CP = cp
SRC = 	ft_light_printf.c \
		get_next_line.c get_next_line_utils.c \
		alloc_random.c random_numbers.c random_test.c \
		general.c general2.c \
		alloc_memory.c free_memory.c \
		parsing_checkdata.c parsing_filldata.c \
		print_stuff.c \
		command_push.c command_rotate.c command_reverse_rotate.c command_swap.c \
		command_counter.c \
		alg_tool_insertion1.c alg_tool_insertion2.c alg_tool_insertion3.c \
		alg_tool_insertion4.c alg_tool_insertion5.c alg_tool_insertion6.c \
		optimize_1doctor_strange.c optimize_2best_start.c optimize_3indexation.c \
		execute_play.c execute_checker.c execute_algorythm.c execute_read_terminal.c \
		error.c switches.c variables.c main.c \

HEADER = 	push_define_list.h push_ext_libraries.h push_function_list.h \
			push_structs.h push_swap.h get_next_line.h

BONUS_HEADER = 	push_define_list_bonus.h push_ext_libraries_bonus.h push_function_list_bonus.h \
				push_structs_bonus.h push_swap_bonus.h get_next_line_bonus.h

SRC_BONUS = $(SRC:.c=_bonus.c)
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BONUS_OBJ = $(addprefix $(OBJ_BONUS_DIR)/, $(SRC_BONUS:.c=.o))
#COMP = cc -g -Iminilibx -Lminilibx -lmlx -lX11 -lXext -lm -Lprintf -L$(MINILIBX_RELATIVE_PATH) -LLibft
COMP = -g -Wall -Wextra -Werror -ILibft
LIBFT_RELATIVE_PATH = Libft/

all: $(NAME)
	
$(NAME) : $(LIBFT) $(OBJ) $(OBJ_DIR) $(HEADER) $(OBJ_DIR)/dont_switch_to_bonus.o
	touch $(ALL)
	cp $(LIBFT) $(ALL)
	cc $(COMP) $(OBJ) $(OBJ_DIR)/dont_switch_to_bonus.o $(ALL) -o $(NAME)
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

$(BONUS_HEADER) : 
	@echo "Missing header!"

$(OBJ_DIR)/dont_switch_to_bonus.o: $(OBJ_DIR) $(SRC)
	cc $(COMP) -c dont_switch_to_bonus.c -o $(OBJ_DIR)/dont_switch_to_bonus.o

$(OBJ_BONUS_DIR)/switch_to_bonus.o: $(OBJ_BONUS_DIR) $(SRC_BONUS)
	cc $(COMP) -c $(BONUS_DIR)/switch_to_bonus.c -o $(OBJ_BONUS_DIR)/switch_to_bonus.o

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

$(OBJ_BONUS_DIR) : 
	mkdir -p $(OBJ_BONUS_DIR)

$(BONUS_DIR) : 
	mkdir -p $(BONUS_DIR)

copy_lib: $(BONUS_DIR)
	cp -r $(LIBFT_RELATIVE_PATH) $(BONUS_DIR)

$(SRC_BONUS) : 
	@echo "I am creating the bonus files! P-e-r-forza"
	@for file in $(SRC); do \
		cp $$file $(BONUS_DIR)/$${file%.c}_bonus.c; \
	done
	@for file in $(BONUS_HEADER); do \
		cp $$file $(BONUS_DIR)/$${file%.h}.h; \
	done
	cp switch_to_bonus.c $(BONUS_DIR)


bonus: $(LIBFT) $(BONUS_DIR) copy_lib $(OBJ_BONUS_DIR) $(SRC_BONUS) $(BONUS_OBJ) $(OBJ_BONUS_DIR)/switch_to_bonus.o $(BONUS_HEADER)
	touch $(ALL)
	cp $(LIBFT) $(ALL)
	cc $(COMP) $(BONUS_OBJ) $(OBJ_BONUS_DIR)/switch_to_bonus.o $(ALL) -o $(NAME_BONUS)
	@echo "\nall done!!"


clean: 
	rm -f $(OBJ) $(ALL) $(NAME) $(NAME_BONUS) *.out
	rm -rf $(OBJ_DIR) $(BONUS_DIR) $(OBJ_BONUS_DIR)
	$(MAKE) clean -C $(LIBFT_RELATIVE_PATH)
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

clear : 
	clear


.PHONY: all clean fclean re main gdb run copy_lib clear copy_files
.SILENT: