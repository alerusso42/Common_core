O_DIR = obj/

ROOT = ../..

LIBFT_SRC = 	$(wildcard $(ROOT)/Libft/ft_*.c) \
				$(wildcard $(ROOT)/Libft/other_*.c) \
				$(ROOT)/Libft/mfile_a_gnl.c \
	  			$(ROOT)/Libft/mfile_rw_support.c \
	  			$(ROOT)/Libft/mfile_store_fds_user.c \
	  			$(ROOT)/Libft/mfile_store_fds_utils.c


LIBFT_OBJ := $(patsubst $(ROOT)/Libft/%.c, $(O_DIR)%.o, $(LIBFT_SRC))

OBJ = $(LIBFT_OBJ)

NAME = test.out

COMP = cc
CFLAGS = -Wall -Wextra -Werror -g $(shell sdl2-config --cflags)
LDFLAGS = $(shell sdl2-config --libs)

all: $(NAME)

$(NAME): $(OBJ) $(O_DIR)
	@echo $(OBJ)
	@$(COMP) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

$(O_DIR):
	mkdir -p $(O_DIR)

$(O_DIR)%.o: $(ROOT)/Libft/%.c | $(O_DIR)
	$(COMP) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(O_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
