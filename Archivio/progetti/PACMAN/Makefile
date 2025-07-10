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

COMP = cc -Wall -Wextra -Werror -g

# Include paths
CFLAGS += \
  -I$(HOME)/libs/SDL_image/include/ \
  -I$(HOME)/libs/SDL_mixer/include/ \
  -I$(HOME)/libs/SDL/include

#LDFLAGS = $(shell pkg-config --libs --cflags sdl3 sdl3-mixer sdl3-image)

# Library paths and linking
LDFLAGS = 	-L$(HOME)/.local/bin/sdl -lSDL3 -lSDL3 \
  			-L$(HOME)/.local/bin/sdl -lSDL3 -lSDL3_mixer \
  			-L$(HOME)/.local/bin/sdl -lSDL3 -lSDL3_image -lm  \
			

all: $(NAME)

$(NAME): $(OBJ) $(O_DIR) $(HEADER)
	@echo $(OBJ)
	@$(COMP) $(OBJ) $(LIB) -o $(NAME) $(CFLAGS) $(LDFLAGS)

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