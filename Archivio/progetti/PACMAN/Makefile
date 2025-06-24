O_DIR = build/obj

ROOT = .

SRC = 	includes/*.h	\
		srcs/*.c		\
		srcs/SDL/*.c	\
		srcs/utils/*.c	\

SRC_OBJ := $(patsubst $(ROOT)/srcs/%.c, $(O_DIR)%.o, $(SRC))

OBJ = $(SRC_OBJ)

NAME = pacman
LIB = daft/daft.a

COMP = cc
CFLAGS = -Wall -Wextra -Werror -g $(shell sdl2-config --cflags)
LDFLAGS = $(shell sdl2-config --libs)

all: $(NAME)

$(NAME): $(OBJ) $(O_DIR)
	@echo $(OBJ)
	@$(COMP) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) $(LDFLAGS)

$(O_DIR):
	mkdir -p $(O_DIR)

$(O_DIR)%.o: $(ROOT)/srcs/%.c | $(O_DIR)
	$(COMP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(O_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
