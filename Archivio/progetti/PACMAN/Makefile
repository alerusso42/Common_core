O_DIR = build/obj

ROOT = .

SRC = 	srcs/*.c		\
		srcs/engine/*.c	\
		srcs/SDL/*.c	\
		srcs/IA/*.c	\
		srcs/map/*.c	\
		srcs/utils/*.c	\
		srcs/debug/*.c	\

HEADER = includes/*.h

SRC_OBJ := $(patsubst $(ROOT)/srcs/%.c, $(O_DIR)%.o, $(SRC))

OBJ = $(SRC_OBJ)

NAME = pacman
LIB = daft/daft.a

IMG_CFLAGS  = $(shell pkg-config --cflags SDL2_image)
IMG_LIBS    = $(shell pkg-config --libs SDL2_image)

COMP = cc
CFLAGS = -Wall -Wextra -Werror -g $(shell sdl2-config --cflags) $(IMG_CFLAGS)
LDFLAGS = $(shell sdl2-config --libs) $(IMG_LIBS)
SDL = -lSDL2_mixer 

all: $(NAME)

$(NAME): $(OBJ) $(O_DIR) $(HEADER)
	@echo $(OBJ)
	@$(COMP) $(CFLAGS) $(OBJ) $(LIB) -o $(NAME) $(SDL) $(LDFLAGS)

$(O_DIR):
	mkdir -p $(O_DIR)

$(O_DIR)%.o: $(ROOT)/srcs/%.c | $(O_DIR)
	$(COMP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(O_DIR)

fclean: clean
	rm -f $(NAME)
	printf 1
	$(MAKE) fclean -C daft/.private/program

daft: 
	printf 2
	$(MAKE) -C daft/.private/program

re: fclean daft all
.PHONY: daft