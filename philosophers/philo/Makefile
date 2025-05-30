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
LIBFT = Libft/libft.a
OBJ_DIR = obj_dir
OBJ_BONUS_DIR = obj_bonus_dir
BONUS_DIR = bonus_dir
BONUS_MARK = $(BONUS_DIR)/.bonus_done
DEBUG_FILE = g.gdb
SUPPRESSION_FILE = s.supp
SRC = 	memory.c \
		error_message.c \
		general_ft.c \
		print_stuff.c  \
		parsing.c \
		main.c \
		item_time.c \
		init_thread.c \
		execute_eat.c execute_death.c execute_routine.c

HEADER = z_function_list.h z_data.h z_header.h 


#COMP = cc -g -Iminilibx -Lminilibx -lmlx -lX11 -lXext -lm -Lprintf -Lminilibx-linux/ -LLibft
# I file bonus vengono generati rinominando i file sorgente con il suffisso _bonus
SRC_BONUS = $(SRC:.c=_bonus.c)
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
BONUS_OBJ = $(addprefix $(OBJ_BONUS_DIR)/, $(SRC_BONUS:.c=.o))

COMP = cc -g -Wall -Wextra -Werror -ILibft -fPIE
LFLAGS = -lpthread
LIBFT_RELATIVE_PATH = Libft/


$(NAME) : $(LIBFT) $(OBJ) $(OBJ_DIR) $(HEADER)
	$(COMP) $(OBJ) $(LIBFT) -o $(NAME) $(LFLAGS)
	@echo "\n$(NAME) done!!"

all: $(NAME)


$(LIBFT) : 
	$(MAKE) -C $(LIBFT_RELATIVE_PATH)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(COMP) -c $< -o $@

$(HEADER): 
	@echo "Missing header!"

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

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
