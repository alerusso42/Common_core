NAME = so_long
NAME_BONUS = so_long_bonus
LIBFT = Libft/libft.a
MINILIBX = minilibx-linux/minilibx.a
OBJ_DIR = obj_dir
OBJ_BONUS_DIR = obj_bonus_dir
BONUS_DIR = bonus_dir
BONUS_MARK = $(BONUS_DIR)/.bonus_done
ALL = all.a
CP = cp

SRC = 	alloc_memory.c reset_memory.c \
		error_message.c \
		general_ft.c \
		print_stuff.c  \
		switches.c variables.c main.c \

HEADER = 	

HEADER_BONUS = 	

# I file bonus vengono generati rinominando i file sorgente con il suffisso _bonus
SRC_BONUS = $(SRC:.c=_bonus.c)
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BONUS_OBJ = $(addprefix $(OBJ_BONUS_DIR)/, $(SRC:.c=_bonus.o))

COMP = -g -Wall -Wextra -Werror -ILibft -Iprintf
LIBFT_RELATIVE_PATH = Libft/

all: $(NAME)
	
$(NAME) : $(LIBFT) $(OBJ) $(OBJ_DIR) $(HEADER)
	touch $(ALL)
	cp $(LIBFT) $(ALL)
	cc $(COMP) $(OBJ) $(OBJ_DIR)/dont_switch_to_bonus.o $(ALL) $(LIBX) -o $(NAME)
	@echo "\nall done!!"

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
gen_bonus: $(BONUS_DIR) $(HEADER) copy_lib
	@if [ ! -f $(BONUS_MARK) ]; then \
		echo "Generating bonus files..."; \
		for file in $(SRC); do \
			cp $$file $(BONUS_DIR)/$${file%.c}_bonus.c; \
		done; \
		for file in $(HEADER_BONUS); do \
			cp $$file $(BONUS_DIR)/$${file}; \
		done; \
		cp switch_to_bonus.c $(BONUS_DIR); \
		touch $(BONUS_MARK); \
	else \
		echo "Bonus files already generated."; \
	fi


bonus: $(LIBFT) $(OBJ_BONUS_DIR) $(BONUS_OBJ) $(HEADER) $(OBJ_BONUS_DIR)/switch_to_bonus.o
	@if [ -f $(BONUS_MARK) ]; then \
		touch $(ALL)\
		cp $(LIBFT) $(ALL)\
		cc $(COMP) $(BONUS_OBJ) $(OBJ_BONUS_DIR)/switch_to_bonus.o $(ALL) $(LIBX) -o $(NAME_BONUS)\
		@echo "\nall done!!"\
	else \
		echo "You MUST launch the command gen_bonus."; \
	fi

clean: 
	rm -f $(OBJ) $(ALL) $(NAME) $(NAME_BONUS) *.out *.gdb
	rm -rf $(OBJ_DIR) $(BONUS_DIR) $(OBJ_BONUS_DIR)
	$(MAKE) clean -C $(LIBFT_RELATIVE_PATH)

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

.PHONY: all clean fclean re main gdb run val copy_lib gen_bonus
.SILENT:
