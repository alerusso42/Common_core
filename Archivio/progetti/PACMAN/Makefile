O_DIR = build/obj

ROOT = .

SRC :=  $(wildcard srcs/*.c) \
        $(wildcard srcs/engine/*.c) \
        $(wildcard srcs/SDL/*.c) \
        $(wildcard srcs/IA/*.c) \
        $(wildcard srcs/map/*.c) \
        $(wildcard srcs/utils/*.c) \
        $(wildcard srcs/debug/*.c) \

HEADER = includes/*.h

#SRC_OBJ := $(patsubst $(ROOT)/srcs/%.c, $(O_DIR)%.o, $(SRC))

OBJ := $(patsubst %.c, $(O_DIR)/%.o, $(SRC))

NAME = pacman
LIB_PATH = Libft
LIB = $(LIB_PATH)/libft.a

#LIB = daft/program/daft_src/*.c daft/program/prep_src/*.c daft/program/Libft/*.c

COMP = cc -Wall -Wextra -Werror -g

CFLAGS += $(shell pkg-config --cflags sdl2 SDL2_mixer SDL2_image)
LDFLAGS = $(shell pkg-config --libs sdl2 SDL2_mixer SDL2_image) -lm

# Include paths
#CFLAGS += \
  -I$(HOME)/libs/SDL2/SDL_mixer/include/ \
  -I$(HOME)/libs/SDL2/SDL_image/include/ \
  -I$(HOME)/libs/SDL2/SDL/include

#LDFLAGS = $(shell pkg-config --libs --cflags sdl3 sdl3-mixer sdl3-image)

# Library paths and linking
#LDFLAGS = 	-L$(HOME)/.local/bin/sdl -lSDL2 -lSDL2 \
  			-L$(HOME)/.local/bin/sdl -lSDL2 -lSDL2_mixer \
			-L$(HOME)/.local/bin/sdl -lSDL2 -lSDL2_image -lm  \

all: $(NAME)

$(NAME): $(OBJ) $(O_DIR) $(HEADER) $(LIB)
	@echo $(OBJ)
	@$(COMP) $(OBJ) $(LIB) -o $(NAME) $(CFLAGS) $(LDFLAGS)

$(O_DIR):
	mkdir -p $(O_DIR)

$(O_DIR)%.o: $(ROOT)/srcs/%.c | $(O_DIR)
	$(COMP) $(CFLAGS) -c $< -o $@

$(LIB):
	$(MAKE) -C $(LIB_PATH)

build/obj/%.o: %.c
	@mkdir -p $(dir $@)
	$(COMP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(O_DIR)
	rm -f *.log

fclean: clean
	rm -f $(NAME)
	printf 1
	$(MAKE) fclean -C $(LIB_PATH)

daft: 
	printf 2
	$(MAKE) -C $(LIB_PATH)

re: fclean daft all
