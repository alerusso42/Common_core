#SECTION -	settings

NAME = libft.a
OBJ_DIR = obj_dir
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = 
CC = cc

#SECTION - paths

PATH_BFS =			algorythm/bfs
PATH_CHECKS =		checks
PATH_DAFT_PREP =	daft/program/prep_src
PATH_DAFT_PROG =	daft/program/daft_src
PATH_DATA_MATR2 =	data/matrix_2
PATH_DATA_LIST =	data/list
PATH_FILES =		files
PATH_MATH =			math
PATH_MEM =			mem
PATH_PRINTF =		printf
PATH_STRING =		string

#SECTION - filepaths

SRC_ALGORYTHM =	$(addprefix $(PATH_BFS)/, $(shell ls $(PATH_BFS) | grep \\.c))
SRC_CHECKS =	$(addprefix $(PATH_CHECKS)/, $(shell ls $(PATH_CHECKS) | grep \\.c))
SRC_DAFT =		$(addprefix $(PATH_DAFT_PREP)/, $(shell ls $(PATH_DAFT_PREP) | grep \\.c)) 	\
				$(addprefix $(PATH_DAFT_PROG)/, $(shell ls $(PATH_DAFT_PROG) | grep \\.c))
SRC_DATA =		$(addprefix $(PATH_DATA_MATR2)/, $(shell ls $(PATH_DATA_MATR2) | grep \\.c)) \
				$(addprefix $(PATH_DATA_LIST)/, $(shell ls $(PATH_DATA_LIST) | grep \\.c))
SRC_FILES =		$(addprefix $(PATH_FILES)/, $(shell ls $(PATH_FILES) | grep \\.c))
SRC_MATH =		$(addprefix $(PATH_MATH)/, $(shell ls $(PATH_MATH) | grep \\.c))
SRC_MEM =		$(addprefix $(PATH_MEM)/, $(shell ls $(PATH_MEM) | grep \\.c))
SRC_PRINTF =	$(addprefix $(PATH_PRINTF)/, $(shell ls $(PATH_PRINTF) | grep \\.c))
SRC_STRING =	$(addprefix $(PATH_STRING)/, $(shell ls $(PATH_STRING) | grep \\.c))

#SECTION - modules

ALL =				$(SRC_ALGORYTHM) $(SRC_CHECKS) $(SRC_DAFT) $(SRC_DATA) $(SRC_FILES) $(SRC_MATH) $(SRC_MEM) $(SRC_PRINTF) $(SRC_STRING)
MODULE_ALGORYTHM = 	$(SRC_ALGORYTHM) $(SRC_DATA) $(SRC_MEM)
MODULE_CHECKS = 	$(SRC_CHECKS)
MODULE_DAFT = 		$(SRC_DAFT) $(SRC_CHECKS) $(SRC_FILES) $(SRC_MATH) $(SRC_MEM) $(SRC_PRINTF) $(SRC_STRING)
MODULE_FILES = 		$(SRC_DAFT) $(SRC_CHECKS) $(SRC_FILES) $(SRC_MATH) $(SRC_MEM) $(SRC_PRINTF) $(SRC_STRING)
MODULE_MATH = 		$(SRC_MATH)
MODULE_MEM = 		$(SRC_MEM) $(SRC_STRING)
MODULE_PRINTF = 	$(SRC_PRINTF) $(SRC_STRING)
MODULE_STRING = 	$(SRC_STRING) $(SRC_CHECKS) $(SRC_DATA) $(SRC_MEM) $(SRC_PRINTF)

#SECTION - object declaration

OBJ_ALL = $(addprefix $(OBJ_DIR)/, $(ALL:.c=.o))
OBJ_ALGORYTHM = $(addprefix $(OBJ_DIR)/, $(MODULE_ALGORYTHM:.c=.o))
OBJ_CHECKS = $(addprefix $(OBJ_DIR)/, $(MODULE_CHECKS:.c=.o))
OBJ_DAFT = $(addprefix $(OBJ_DIR)/, $(MODULE_DAFT:.c=.o))
OBJ_DATA = $(addprefix $(OBJ_DIR)/, $(MODULE_DATA:.c=.o))
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(MODULE_FILES:.c=.o))
OBJ_MATH = $(addprefix $(OBJ_DIR)/, $(MODULE_MATH:.c=.o))
OBJ_MEM = $(addprefix $(OBJ_DIR)/, $(MODULE_MEM:.c=.o))
OBJ_PRINTF = $(addprefix $(OBJ_DIR)/, $(MODULE_PRINTF:.c=.o))
OBJ_STRING = $(addprefix $(OBJ_DIR)/, $(MODULE_STRING:.c=.o))

#SECTION -	commands

$(NAME): test $(OBJ_ALL)
	ar rcs $(NAME) $(CFLAGS) $(OBJ_ALL) $(LFLAGS)

test: 
#	echo $(OBJ_ALL)
	clear
	@echo $(OBJ_ALL)

all: $(NAME)

algorythm: $(OBJ_ALGORYTHM)
	ar rcs $(NAME) $(CFLAGS) $(OBJ_ALGORYTHM) $(LFLAGS)	

checks: $(OBJ_CHECKS)
	ar rcs $(NAME) $(CFLAGS) $(OBJ_CHECKS) $(LFLAGS)	

daft: $(OBJ_DAFT)
	ar rcs $(NAME) $(CFLAGS) $(OBJ_DAFT) $(LFLAGS)

data: $(OBJ_DATA)
	ar rcs $(NAME) $(CFLAGS) $(OBJ_DATA) $(LFLAGS)

files: $(OBJ_FILES)
	ar rcs $(NAME) $(CFLAGS) $(OBJ_FILES) $(LFLAGS)

math: $(OBJ_MATH)
	ar rcs $(NAME) $(CFLAGS) $(OBJ_MATH) $(LFLAGS)

mem: $(OBJ_MEM)
	ar rcs $(NAME) $(CFLAGS) $(OBJ_MEM) $(LFLAGS)

printf: $(OBJ_PRINTF)
	ar rcs $(NAME) $(CFLAGS) $(OBJ_PRINTF) $(LFLAGS)

string: $(OBJ_STRING)
	ar rcs $(NAME) $(CFLAGS) $(OBJ_STRING) $(LFLAGS)

help:
	@echo "\033[33mList of all modules:\n"\
			"all,\n"\
			"algorythm,\n"\
			"checks,\n"\
			"daft,\n"\
			"data,\n"\
			"files,\n"\
			"math,\n"\
			"mem,\n"\
			"printf,\n"\
			"string,\n\033[0m"

$(OBJ_DIR) : 
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.txt *.out
	rm -rf $(OBJ_DIR)/*

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: help
