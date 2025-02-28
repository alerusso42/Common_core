NAME = push_swap
NAME_BONUS = checker
LIBFT = Libft/libft.a
OBJ_DIR = obj_dir
OBJ_BONUS_DIR = obj_bonus_dir
BONUS_DIR = bonus_dir
BONUS_MARK = $(BONUS_DIR)/.bonus_done
DEBUG_FILE = g.gdb
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
		optimize_4medium.c \
		execute_play.c execute_checker.c execute_algorythm.c execute_result.c \
		error.c switches.c variables.c main.c \

HEADER = 	push_define_list.h push_ext_libraries.h push_function_list.h \
			push_structs.h push_swap.h get_next_line.h

BONUS_HEADER = 	push_define_list_bonus.h push_ext_libraries_bonus.h push_function_list_bonus.h \
				push_structs_bonus.h push_swap_bonus.h get_next_line_bonus.h


#COMP = cc -g -Iminilibx -Lminilibx -lmlx -lX11 -lXext -lm -Lprintf -Lminilibx-linux/ -LLibft
# I file bonus vengono generati rinominando i file sorgente con il suffisso _bonus
SRC_BONUS = $(SRC:.c=_bonus.c)
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BONUS_OBJ = $(addprefix $(OBJ_BONUS_DIR)/, $(SRC:.c=_bonus.o))

COMP = -g -Wall -Wextra -Werror -ILibft -Iprintf -fPIE
LIBFT_RELATIVE_PATH = Libft/
PRINTF_RELATIVE_PATH = printf/
MINILIBX_RELATIVE_PATH = minilibx-linux/

$(NAME) : $(LIBFT) $(OBJ) $(OBJ_DIR) $(HEADER)
	touch $(ALL)
	cp $(LIBFT) $(ALL)
	cc $(COMP) $(OBJ) $(OBJ_DIR)/dont_switch_to_bonus.o $(ALL) -o $(NAME)
	@echo "\nall done!!"

all: $(NAME) bonus


$(LIBFT) : 
	$(MAKE) -C $(LIBFT_RELATIVE_PATH)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	cc $(COMP) -c $< -o $@
	cc $(COMP) -c dont_switch_to_bonus.c -o $(OBJ_DIR)/dont_switch_to_bonus.o

# Regola per compilare gli oggetti bonus (escluso switch_to_bonus)
$(OBJ_BONUS_DIR)/%_bonus.o: $(BONUS_DIR)/%_bonus.c | $(OBJ_BONUS_DIR) $(BONUS_MARK)
	cc $(COMP) -c $< -o $@

# Regola separata per switch_to_bonus.o: per evitare relink
$(OBJ_BONUS_DIR)/switch_to_bonus.o: $(BONUS_DIR)/switch_to_bonus.c | $(OBJ_BONUS_DIR) $(BONUS_MARK)
	cc $(COMP) -c $< -o $@

$(HEADER):
	@echo "Missing header!"

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

$(OBJ_BONUS_DIR) : 
	mkdir -p $(OBJ_BONUS_DIR)

$(BONUS_DIR) : 
	mkdir -p $(BONUS_DIR)

copy_lib: $(BONUS_DIR)
	@cp -r $(LIBFT_RELATIVE_PATH) $(BONUS_DIR)

# Genera i file bonus solo se non sono già presenti (cioe se BONUS_MARK non esiste)
gen_bonus: $(BONUS_DIR) $(HEADER)
	@if [ ! -f $(BONUS_MARK) ]; then \
		echo "Generating bonus files..."; \
		for file in $(SRC); do \
			cp $$file $(BONUS_DIR)/$${file%.c}_bonus.c; \
		done; \
		for file in $(BONUS_HEADER); do \
			cp $$file $(BONUS_DIR)/$${file}; \
		done; \
		cp switch_to_bonus.c $(BONUS_DIR); \
		touch $(BONUS_MARK); \
	else \
		echo "Bonus files already generated."; \
	fi


bonus: gen_bonus $(LIBFT) copy_lib $(OBJ_BONUS_DIR)
	/bin/bash -c "make BASH"

BASH: $(BONUS_OBJ) $(BONUS_HEADER) $(OBJ_BONUS_DIR)/switch_to_bonus.o
	cc $(COMP) $(BONUS_OBJ) $(OBJ_BONUS_DIR)/switch_to_bonus.o $(ALL) -o $(NAME_BONUS)
	@echo "\nall done!!"

clean: 
	rm -f $(OBJ) $(ALL) $(NAME) $(NAME_BONUS) *.out *.gdb *.txt
	rm -rf $(OBJ_DIR) $(BONUS_DIR) $(OBJ_BONUS_DIR)
	$(MAKE) clean -C $(LIBFT_RELATIVE_PATH)

folder_clean: 
	rm -f $(OBJ) $(NAME)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_RELATIVE_PATH)

re: fclean all

debug: 
	@if [ ! -f $(DEBUG_FILE) ]; then \
		touch g.gdb; \
		echo "define a\
		\n\tset \$$i = 0\
		\n\twhile (\$$i < a->size)\
		\n\t\tp a->data[a->first + \$$i]\
		\n\t\tset \$$i = \$$i + 1\
		\n\tend\
		\n\tp a->size\
		\nend\
		\n\ndefine b\
		\n\tset \$$i = 0\
		\n\twhile (\$$i < b->size)\
		\n\t\tp b->data[b->first + \$$i]\
		\n\t\tset \$$i = \$$i + 1\
		\n\tend\
		\n\tp b->size\nend" > $(DEBUG_FILE); \
		echo "$(DEBUG_FILE) created."; \
	else \
		echo "Debug file already generated."; \
	fi

.PHONY: all clean fclean re main gdb run val copy_lib gen_bonus debug BASH
