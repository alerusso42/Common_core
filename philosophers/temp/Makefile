NAME = philo
OBJ_DIR = obj_dir
DEBUG_FILE = g.gdb
SUPPRESSION_FILE = s.supp
SRC = 	main.c \
		error_message.c \
		manage_data/init_thread.c \
		manage_data/memory.c \
		manage_data/parsing.c \
		utils/debug.c \
		utils/ft_atoi.c \
		utils/ft_calloc.c \
		utils/printf_light.c \
		utils/printf_fd.c \
		utils/time.c \
		routine/eat.c \
		routine/death.c \
		routine/print.c  \
		routine/routine.c \

OBJ    = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))
COMP = cc -g -Wall -Wextra -Werror -fPIE
LFLAGS = -lpthread


$(NAME) : $(OBJ) $(OBJ_DIR)
	$(COMP) $(OBJ) -o $(NAME) $(LFLAGS)
	@echo "\n$(NAME) done!!"

all: $(NAME)


$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(COMP) -c $< -o $@

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

clean: 
	@rm -f $(OBJ) $(ALL) $(NAME) $(NAME_BONUS) *.out *.gdb  *.supp *.txt
	@rm -rf $(OBJ_DIR) $(BONUS_DIR) $(OBJ_BONUS_DIR)

clear: 
	clear

fclean: clean
	@rm -f $(NAME)

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

.PHONY: all clean fclean re bonus debug supp
