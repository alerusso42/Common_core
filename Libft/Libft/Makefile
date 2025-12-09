NAME = libft.a
OBJ_DIR = obj_dir

SRC_ALGORYTHM =	$(shell ls algorythm/bfs | grep .c) 
SRC_CHECKS =	$(shell ls checks | grep .c)
SRC_DAFT =	$(shell ls daft/program/daft_src | grep .c) $(shell ls daft/program/prep_src | grep .c)
SRC_DATA =	$(shell ls data/list | grep .c) $(shell ls data/matrix_2 | grep .c)
SRC_FILES =	$(shell ls files | grep .c)
SRC_MATH =	$(shell ls math | grep .c)
SRC_MEM =	$(shell ls mem | grep .c)
SRC_PRINTF =	$(shell ls printf | grep .c)
SRC_STRING =	$(shell ls string | grep .c)

ALL =				$(SRC_ALGORYTHM) $(SRC_CHECKS) $(SRC_DAFT) $(SRC_DATA) $(SRC_FILES) $(SRC_MATH) $(SRC_MEM) $(SRC_PRINTF) $(SRC_STRING)
MODULE_ALGORYTHM = 	$(SRC_ALGORYTHM) $(SRC_DATA) $(SRC_MEM)
MODULE_CHECKS = 	$(SRC_CHECKS)
MODULE_DAFT = 		$(SRC_DAFT) $(SRC_CHECKS) $(SRC_FILES) $(SRC_MATH) $(SRC_MEM) $(SRC_PRINTF) $(SRC_STRING)
MODULE_FILES = 		$(SRC_DAFT) $(SRC_CHECKS) $(SRC_FILES) $(SRC_MATH) $(SRC_MEM) $(SRC_PRINTF) $(SRC_STRING)
MODULE_MATH = 		$(SRC_MATH)
MODULE_MEM = 		$(SRC_MEM) $(SRC_STRING)
MODULE_PRINTF = 	$(SRC_PRINTF) $(SRC_STRING)
MODULE_STRING = 	$(SRC_STRING) $(SRC_CHECKS) $(SRC_DATA) $(SRC_MEM) $(SRC_PRINTF)

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

CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = 
CC = cc

$(NAME): $(OBJ_ALL)
	ar rcs $(NAME) $(CFLAGS) $(OBJ_ALL) $(LFLAGS)

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
	echo -e "\033[33mList of all modules:\n"\
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

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.txt *.out
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: help
