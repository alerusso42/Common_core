NAME = minishell

SRC = main.c signals.c

OBJ_DIR = obj_main

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

FLAGS = -g -Wall -Werror -Wextra -lreadline -lhistory -lncurses -ISsj_libft

LIBFT = Ssj_libft/libft.a

PARSING_SRC = start_lexing.c fill_struct.c utils.c struct_alloc.c remove_quotes.c \
	define_token.c define_token_2.c expand_env.c expand_env_2.c utils_2.c \
	parenthesis.c \

PARSING_DIR = 		parsing
PARSING_OBJ_DIR = 	$(PARSING_DIR)/obj_parsing

EXEC_OBJ = $(addprefix $(PARSING_OBJ_DIR)/, $(PARSING_SRC:.c=.o))

EXEC_DIR =		executor
EXEC_OBJ_DIR = 	$(EXEC_DIR)/obj_executor
BONUS_DIR = 	$(EXEC_DIR)/bonus
BUILT_DIR = 	$(EXEC_DIR)/builtins
DEBUG_DIR =		$(EXEC_DIR)/debug_tools
ENV_DIR =		$(EXEC_DIR)/env_management
EXEC_DIR = 		$(EXEC_DIR)/execution_main
MEM_DIR = 		$(EXEC_DIR)/memory_management
PREP_DIR = 		$(EXEC_DIR)/execution_prep
UTILS_DIR = 	$(EXEC_DIR)/utils

#NOTE - To understand execution part, reading  
#		execute.c from execution_main/ should be enough.

#SECTION - Bonus files
BONUS_FILES = 			bonus_parenthesis.c bonus_wildcards1.c bonus_wildcards2.c
BONUS = 				$(addprefix $(BONUS_DIR)/, $(BONUS_FILES))

#SECTION - Builtin files
BUILTINS_FILES = 		builtin_cd.c builtin_echo.c builtin_env.c \
						builtin_exit.c builtin_export.c builtin_pwd.c \
						builtin_unset.c
BUILTINS = 				$(addprefix $(BUILT_DIR)/, $(BUILTINS_FILES))

#SECTION - env2 fts are meant to be used in parsing part
ENV_FILES = 			environment.c environment2.c
ENV = 					$(addprefix $(ENV_DIR)/, $(ENV_FILES))

#SECTION - execution main file, and errors printings
EXECUTION_MAIN_FILES = 	error_message.c execute.c
EXECUTION_MAIN = 		$(addprefix $(EXEC_DIR)/, $(EXECUTION_MAIN_FILES))

#SECTION - Modify tokens, open here docs, prepare commands, get commands paths
EXECUTION_PREP_FILES = 	get_commands_data.c get_file_data.c \
						get_paths_data.c get_tokens.c
EXECUTION_PREP =		$(addprefix $(PREP_DIR)/, $(EXECUTION_PREP_FILES))

#SECTION - allocate, get memory from main program, free
MEMORY_FILES = 			memory.c
MEMORY = 				$(addprefix $(MEM_DIR)/, $(MEMORY_FILES))

#SECTION - General utilities to abstract part of program
UTILS_FILES = 			printf_fd.c utils_count.c utils_debug.c utils_fds.c \
						utils_generic.c utils_matrix.c  \
						utils_parenthesis2.c utils_parenthesis.c  \
						utils_string2.c utils_string.c utils_tokencheck.c
UTILS = 				$(addprefix $(UTILS_DIR)/, $(UTILS_FILES))

#SECTION - Putting all together:
EXEC_SRC = $(BONUS) $(BUILTINS) $(ENV) $(EXECUTION_MAIN) $(MEMORY) $(EXECUTION_PREP) $(UTILS)
SRC_DEBUG = $(DEBUG_DIR)/debug.c

EXEC_OBJ = $(addprefix $(EXEC_OBJ_DIR)/, $(EXEC_SRC:.c=.o))
OBJ_DEBUG = $(addprefix $(EXEC_OBJ_DIR)/, $(SRC_DEBUG:.c=.o))

FLAGS = -Wall -Werror -Wextra -lreadline -lhistory -g

LIBFT = ../Ssj_libft/libft.a
DEBUG_LIBFT = executor/$(DEBUG_DIR)/debug_resources/libft.a

$(OBJ_DIR): 
	mkdir -p $(OBJ_DIR)
	mkdir -p $(EXEC_OBJ_DIR)
	mkdir -p $(EXEC_OBJ_DIR)/$(BONUS_DIR)
	mkdir -p $(EXEC_OBJ_DIR)/$(BUILT_DIR)
	mkdir -p $(EXEC_OBJ_DIR)/$(DEBUG_DIR)
	mkdir -p $(EXEC_OBJ_DIR)/$(ENV_DIR)
	mkdir -p $(EXEC_OBJ_DIR)/$(EXEC_DIR)
	mkdir -p $(EXEC_OBJ_DIR)/$(MEM_DIR)
	mkdir -p $(EXEC_OBJ_DIR)/$(PREP_DIR)
	mkdir -p $(EXEC_OBJ_DIR)/$(UTILS_DIR)

all : $(NAME)

$(OBJ_DIR)/%.o: %.c
	cc -g -Wall -Werror -Wextra -c $< -o $@

$(PARSING_OBJ)/%.o: %.c
	cc -g -Wall -Werror -Wextra -c $< -o $@

$(EXEC_OBJ)/%.o: %.c
	cc -g -Wall -Werror -Wextra -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ) $(EXEC_OBJ) $(PARSING_OBJ)
	make bonus -C Ssj_libft
	cc $(OBJ) $(EXECUTOR) $(PARSING) $(LIBFT) $(FLAGS) -o $(NAME)

clean:
	@echo Cleaning...
	make clean -C Ssj_libft
	make clean -C parsing
	make clean -C executor
	rm -rf $(OBJ_DIR) $(PAR)

fclean: clean
	@echo I SAID I AM CLEANING OK!!
	make fclean -C Ssj_libft
	make fclean -C parsing
	make fclean -C executor
	rm -f minishell

re : fclean all

libft:
	@echo Compiling Ssj_Libft...
	make bonus -C Ssj_libft

.PHONY: parsing executor clean fclean re

# .SILENT:
