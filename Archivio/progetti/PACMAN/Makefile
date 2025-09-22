O_DIR = build/obj

ROOT = .

SRC :=  $(wildcard srcs/*.c) \
        $(wildcard srcs/engine/*.c) \
        $(wildcard srcs/SDL/*.c) \
        $(wildcard srcs/IA/*.c) \
        $(wildcard srcs/map/*.c) \
        $(wildcard srcs/utils/*.c) \
        $(wildcard srcs/debug/*.c)

HEADER = includes/*.h

#SRC_OBJ := $(patsubst $(ROOT)/srcs/%.c, $(O_DIR)%.o, $(SRC))

OBJ := $(patsubst %.c, $(O_DIR)/%.o, $(SRC))

NAME = pacman
#LIB = daft/daft.a
LIB = daft/.private/program/daft_src/*.c daft/.private/program/prep_src/*.c daft/.private/program/Libft/*.c

COMP = cc -Wall -Wextra -Werror -g

# Include paths
CFLAGS += \
  -I$(HOME)/libs/SDL2/SDL_mixer/include/ \
  -I$(HOME)/libs/SDL2/SDL_image/include/ \
  -I$(HOME)/libs/SDL2/SDL/include

#LDFLAGS = $(shell pkg-config --libs --cflags sdl3 sdl3-mixer sdl3-image)

# Library paths and linking
LDFLAGS = 	-L$(HOME)/.local/bin/sdl -lSDL2 -lSDL2 \
  			-L$(HOME)/.local/bin/sdl -lSDL2 -lSDL2_mixer \
			-L$(HOME)/.local/bin/sdl -lSDL2 -lSDL2_image -lm  \

all: $(NAME)

$(NAME): $(OBJ) $(O_DIR) $(HEADER)
	@echo $(OBJ)
	@$(COMP) $(OBJ) $(LIB) -o $(NAME) $(CFLAGS) $(LDFLAGS)

$(O_DIR):
	mkdir -p $(O_DIR)

$(O_DIR)%.o: $(ROOT)/srcs/%.c | $(O_DIR)
	$(COMP) $(CFLAGS) -c $< -o $@

build/obj/%.o: %.c
	@mkdir -p $(dir $@)
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
