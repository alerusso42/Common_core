NAME = philo
OBJ_DIR = obj_dir
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
		routine/monitor.c \
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

$(OBJ_DIR):
	mkdir -p $(sort $(dir $(OBJ)))

clean: 
	@rm -f $(OBJ) $(ALL) $(NAME) $(NAME_BONUS) *.out *.gdb  *.supp *.txt *.sh
	@rm -rf $(OBJ_DIR) $(BONUS_DIR) $(OBJ_BONUS_DIR)

clear: 
	clear

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

debug: 
	$(shell cd debug && make debug)

.PHONY: all clean fclean re bonus debug supp
