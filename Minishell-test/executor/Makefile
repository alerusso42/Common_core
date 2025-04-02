NAME = executor

SRC = 	builtin_cd.c builtin_echo.c builtin_env.c builtin_exit.c builtin_export.c \
		builtin_pwd.c builtin_unset.c \
		environment.c \
		error_message.c execute.c general.c general2.c general3.c \
		get_commands_data.c get_paths_data.c get_file_data.c \
		memory.c memory2.c \
		printf_fd.c

SRC_DEBUG = debug.c

OBJ_DIR = obj_executor

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_DEBUG = $(addprefix $(OBJ_DIR)/, $(SRC_DEBUG:.c=.o))

FLAGS = -Wall -Werror -Wextra -lreadline -lhistory -g --no-pie

LIBFT = ../Ssj_libft/libft.a
DEBUG_LIBFT = debug_resources/libft.a

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	cc -Wall -Werror -Wextra -g -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rcs $(NAME).a $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

deb: $(OBJ_DIR) $(OBJ) $(OBJ_DEBUG)
	mkdir -p $(OBJ_DIR)
	cc -D DEBUG=1 $(FLAGS) $(OBJ_DEBUG) $(OBJ) $(DEBUG_LIBFT) -o exe.out

clean:
	rm -rf obj_executor/*.o *.out *.txt
	rm -rf obj_executor

fclean: clean
	rm -rf $(NAME).a

re: fclean all

#frm = file remove
frm: 
	rm -f *.txt

.PHONY: fclean re clean deb all