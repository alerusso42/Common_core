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

IMG_CFLAGS  = $(shell pkg-config --cflags SDL3_image)
IMG_LIBS    = $(shell pkg-config --libs SDL3_image)

COMP = cc -Wall -Wextra -Werror -g
SDL3_PATH      := /home/alerusso/libs/SDL
SDL_IMAGE_PATH := /home/alerusso/libs/SDL_image/install
SDL_MIXER_PATH := /home/alerusso/libs/SDL_mixer/install
# Include paths
CFLAGS += \
  -I$(SDL3_PATH)/include \
  -I$(SDL_IMAGE_PATH)/include \
  -I$(SDL_MIXER_PATH)/include \
  -I$(HOME)/libs/SDL/install/include \
  -I$(HOME)/libs/SDL_mixer/install/include \
  -I$(HOME)/libs/SDL_image/install/include

# Library paths and linking
LDFLAGS += \
  -L$(HOME)/libs/SDL/install/lib -lSDL3 \
  -L$(HOME)/libs/SDL_mixer/install/lib -lSDL3_mixer \
  -L$(HOME)/libs/SDL_image/install/lib -lSDL3_image

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