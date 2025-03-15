#EXPLAINATION
#
#MAKE: generates $(NAME)
#1)	Creates objects inside another folder;
#2)	Then it works as a normal make.
#
#MAKE bonus: generates $(NAME_BONUS)
#1)	Creates a folder for a copy of all Libft, .c and .h sources;
#2)	It copy every source inside the folder, if $(BONUS_MARK) does
#	not exist, and then creates $(BONUS_MARK);
#3)	Then, it calls /bin/bash, to start a new makefile session to make
#	the objects. This is super important, because makefile perform
#	ls -Rl only at the start of the session, therefore it could not
#	see the newborn files;
#4)	In the new makefile session its behaviour mimic $(MAKE), but for
#	the bonus files.

NAME = philo
NAME_BONUS = philo_bonus
LIBFT = Libft/libft.a
OBJ_DIR = obj_dir
OBJ_BONUS_DIR = obj_bonus_dir
BONUS_DIR = bonus_dir
BONUS_MARK = $(BONUS_DIR)/.bonus_done
DEBUG_FILE = g.gdb
SUPPRESSION_FILE = s.supp
SRC = 	alloc_memory.c reset_memory.c storage.c \
		error_message.c \
		general_ft.c \
		print_stuff.c  \
		parsing.c \
		switches.c variables.c main.c \
		item_time.c \
		init_thread.c \
		execute_eat.c execute_death.c execute_routine.c

HEADER = z_function_list.h z_data.h z_header.h 

HEADER_BONUS = 	z_function_list_bonus.h z_data_bonus.h \
				z_header_bonus.h 


#COMP = cc -g -Iminilibx -Lminilibx -lmlx -lX11 -lXext -lm -Lprintf -Lminilibx-linux/ -LLibft
# I file bonus vengono generati rinominando i file sorgente con il suffisso _bonus
SRC_BONUS = $(SRC:.c=_bonus.c)
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BONUS_OBJ = $(addprefix $(OBJ_BONUS_DIR)/, $(SRC_BONUS:.c=.o))

COMP = cc -g -Wall -Wextra -Werror -ILibft -fPIE
LFLAGS = -lpthread
LIBFT_RELATIVE_PATH = Libft/


$(NAME) : $(LIBFT) $(OBJ) $(OBJ_DIR) $(OBJ_DIR)/dont_switch_to_bonus.o $(HEADER)
	$(COMP) $(OBJ) $(OBJ_DIR)/dont_switch_to_bonus.o $(LIBFT) -o $(NAME) $(LFLAGS)
	@echo "\n$(NAME) done!!"

all: $(NAME) bonus


$(LIBFT) : 
	$(MAKE) -C $(LIBFT_RELATIVE_PATH)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(COMP) -c $< -o $@

# Regola per compilare gli oggetti bonus (escluso switch_to_bonus)
$(OBJ_BONUS_DIR)/%_bonus.o: $(BONUS_DIR)/%_bonus.c | $(OBJ_BONUS_DIR) $(BONUS_MARK)
	$(COMP) -c $< -o $@

# Regola separata per switch_to_bonus.o: per evitare relink
$(OBJ_BONUS_DIR)/switch_to_bonus.o: $(BONUS_DIR)/switch_to_bonus.c | $(OBJ_BONUS_DIR) $(BONUS_MARK)
	$(COMP) -c $< -o $@

# Regola separata per dont_switch_to_bonus.o: per evitare relink
$(OBJ_DIR)/dont_switch_to_bonus.o: dont_switch_to_bonus.c | $(OBJ_DIR)
	$(COMP) -c $< -o $@


$(HEADER):
	@echo "Missing header!"

$(BONUS_HEADER):
	@echo "Missing bonus header!"

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

$(OBJ_BONUS_DIR) : 
	mkdir -p $(OBJ_BONUS_DIR)

$(BONUS_DIR) : 
	mkdir -p $(BONUS_DIR)

copy_lib: $(BONUS_DIR)
	@cp -r $(LIBFT_RELATIVE_PATH) $(BONUS_DIR)

# Genera i file bonus solo se non sono già presenti (cioe se BONUS_MARK non esiste)
gen_bonus: $(BONUS_DIR) $(HEADER_BONUS)
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

$(NAME_BONUS): $(OBJ_BONUS_DIR)/switch_to_bonus.o $(BONUS_OBJ) $(BONUS_HEADER)
	$(COMP) $(BONUS_OBJ) $(OBJ_BONUS_DIR)/switch_to_bonus.o $(LIBFT) -o $(NAME_BONUS) $(LFLAGS)
	@echo "\n$(NAME_BONUS) done!!"

bonus: gen_bonus $(LIBFT) copy_lib $(OBJ_BONUS_DIR)
	/bin/bash -c "make BONUS"

BONUS: $(NAME_BONUS)


clean: 
	@rm -f $(OBJ) $(ALL) $(NAME) $(NAME_BONUS) *.out *.gdb  *.supp *.txt
	@rm -rf $(OBJ_DIR) $(BONUS_DIR) $(OBJ_BONUS_DIR)
	$(MAKE) clean -C $(LIBFT_RELATIVE_PATH)

clear: 
	clear

fclean: clean
	@rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_RELATIVE_PATH)

re: fclean $(NAME)
	

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

supp: 
	@if [ ! -f $(SUPPRESSION_FILE) ]; then \
		touch $(SUPPRESSION_FILE); \
		echo "# IGNORE OTHER EXECUTABLES' LEAKS\
		\n{\
		\n\tMALLOC FAILURE OF /usr/bin/*\
		\n\tMemcheck:Leak\
		\n\tfun:malloc\
		\n\t...\
		\n\tobj:/usr/bin/*\
		\n}\
		\n{\
		\n\tCALLOC FAILURE of /usr/bin/*\
		\n\tMemcheck:Leak\
		\n\tfun:calloc\
		\n\t...\
		\n\tobj:/usr/bin/*\
		\n}\
		\n{\
		\n\tREALLOC FAILURE of /usr/bin/*\
		\n\tMemcheck:Leak\
		\n\tfun:realloc\
		\n\t...\
		\n\tobj:/usr/bin/*\
		\n}" > $(SUPPRESSION_FILE); \
		echo "$(SUPPRESSION_FILE) created."; \
	else \
		echo "Suppression file already generated."; \
	fi

.PHONY: all clean fclean re bonus debug supp BONUS
